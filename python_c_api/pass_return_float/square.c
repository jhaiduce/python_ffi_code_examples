#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *
square (PyObject *self, PyObject *args)
{
    double input;
    int sts;

    if (!PyArg_ParseTuple(args, "d", &input))
        return NULL;

    double output = input*input;

    return PyFloat_FromDouble(output);
}

static PyMethodDef squareMethods[] = {
    {"square",  square, METH_VARARGS,
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
