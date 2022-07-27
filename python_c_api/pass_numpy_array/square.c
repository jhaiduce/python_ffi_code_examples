#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <numpy/arrayobject.h>
#include <numpy/ndarraytypes.h>

/* Square each element of an array and store the output 
   in another array of the same size */
void square(double *input, double *output, int len)
{
  for(int i=0; i<len; i++)
    {
      output[i] = input[i]*input[i];
    } 
}

/* Python wrapper for the square function */
static PyObject *
square_np (PyObject *self, PyObject *args)
{
  PyObject *input;
  PyArrayObject *output = NULL;

  /* Parse arguments */
  if (!PyArg_ParseTuple(args, "O", &input))
    return NULL;

  /* Convert input to a contiguous numpy array of type double */
  PyArrayObject * in_arr = (PyArrayObject *) PyArray_FROM_OTF
    (input, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);

  if (in_arr == NULL)
    goto fail;

  /* Get array size */
  int ndim = PyArray_NDIM(in_arr);
  npy_intp * shape = PyArray_DIMS(in_arr);
  int len = (int) PyArray_SIZE(in_arr);

  /* Create output array */
  output = PyArray_SimpleNew(ndim, shape, NPY_DOUBLE);

  /* Get pointers to input and output data */
  double * in_data = (double *) PyArray_DATA(in_arr);
  double * out_data = (double *) PyArray_DATA(output);

  /* Square all elements */
  square(in_data, out_data, size);

  /* Decrement reference count of in_arr since it won't be returned */
  Py_DECREF(in_arr);

  return output;
  
 fail:
  /* Decrement reference counts and return NULL */
  Py_XDECREF(in_arr);
  Py_XDECREF(output);
  return NULL;
}

static PyMethodDef squareMethods[] = {
  {"square",  square_np, METH_VARARGS,
   "Square each element of an array."},
  {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef squareModule = {
  PyModuleDef_HEAD_INIT,
  "square",   /* name of module */
  "Square elements of arrays", /* module documentation, may be NULL */
  -1,       /* size of per-interpreter state of the module,
	       or -1 if the module keeps state in global variables. */
  squareMethods
};

PyMODINIT_FUNC
PyInit_square(void)
{
  import_array();
  return PyModule_Create(&squareModule);
}
