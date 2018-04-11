#include <string>
#include <stdexcept>
#include "PythonWrapper.hpp"

PyObject* PythonWrapper::import_python_module(const char* moduleName) {	
    PyObject *pModuleName = PyUnicode_FromString(moduleName);
    PyObject *pModule = PyImport_Import(pModuleName);
    Py_DECREF(pModuleName);

	if (pModule == NULL) {
		throw std::runtime_error("Could not load Python module");
	}else{
		printf("Successfully loaded %s module\n", moduleName);
	}	
	return pModule;
}

PyObject* PythonWrapper::load_object(const char* childObjectName, PyObject *parentObject){
	PyObject *callableObject = PyObject_GetAttrString(parentObject, childObjectName);
	if (callableObject && PyCallable_Check(callableObject)) {
		return callableObject;
	}else {
		throw "Could not call attribute from Python object";
	}
}

PyObject* PythonWrapper::call_object(PyObject *callableObject, PyObject *args) {
	PyObject *result = PyObject_CallObject(callableObject, args);
	return result;
}

PyObject* PythonWrapper::call_object(const char* childObjectName, PyObject *parentObject, PyObject *args) {
	PyObject *callableObject = load_object(childObjectName, parentObject);
	PyObject *result = PyObject_CallObject(callableObject, args);
	Py_DECREF(callableObject);
	return result;
}

PyObject* PythonWrapper::instantiate_python_class(const char* className, PyObject *pModule, PyObject *args) {
	call_object(className, pModule, args);
}


PyObject* PythonWrapper::call_method_on_object(const char* methodName, PyObject *pObject, PyObject *args) {
	call_object(methodName, pObject, args);
}

PyObject* PythonWrapper::instantiate_python_class(PyObject *pClass, PyObject *args) {
	call_object(pClass, args);
}


PyObject* PythonWrapper::call_method_on_object(PyObject *pMethod, PyObject *args) {
	call_object(pMethod, args);
}