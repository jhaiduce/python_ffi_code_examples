#define PY_SSIZE_T_CLEAN
#include <Python.h>

double square(double input)
{
	return input*input;
}

static PyObject *
square_py (PyObject *self, PyObject *args)
{
    double input;

    if (!PyArg_ParseTuple(args, "d", &input))
        return NULL;

    double output = square(input);

    return PyFloat_FromDouble(output);
}

static PyMethodDef squareMethods[] = {
    {"square",  square_py, METH_VARARGS,
     "Square a number."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef squareModule = {
    PyModuleDef_HEAD_INIT,
    "square",   /* name of module */
    "Square numbers", /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    squareMethods
};

PyMODINIT_FUNC
PyInit_square(void)
{
    return PyModule_Create(&squareModule);
}
