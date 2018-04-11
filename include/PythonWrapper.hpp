#ifndef PYTHONWRAPPER_HPP
#define PYTHONWRAPPER_HPP

#include <Python.h>


class PythonWrapper {
public:
	PyObject* import_python_module(const char* moduleName);
	PyObject* load_object(const char* childObjectName, PyObject *parentObject);
	PyObject* call_object(PyObject *callableObject, PyObject *args);
	PyObject* call_object(const char* childObjectName, PyObject *parentObject, PyObject *args);
	PyObject* instantiate_python_class(const char* className, PyObject *pModule, PyObject *args);
	PyObject* call_method_on_object(const char* methodName, PyObject *pObject, PyObject *args);
	PyObject* instantiate_python_class(PyObject *pClass, PyObject *args);
	PyObject* call_method_on_object(PyObject *pMethod, PyObject *args);
};

#endif