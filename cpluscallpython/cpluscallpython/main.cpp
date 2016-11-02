
#include "Python.h"
#include <iostream>
using namespace std;

//int main()
//
//{
//
//	int nRet = -1;
//
//
//
//	PyObject* pName = NULL;
//
//	PyObject* pModule = NULL;
//
//	PyObject* pDict = NULL;
//
//	PyObject* pFunc = NULL;
//
//	PyObject* pArgs = NULL;
//
//	PyObject* pRet = NULL;
//
//	do
//
//	{
//
//		// ��ʼ��Python
//
//		// ��ʹ��Pythonϵͳǰ������ʹ��Py_Initialize����
//
//		// ���г�ʼ������������Python���ڽ�ģ�鲢���ϵͳ·
//
//		// ����ģ������·���С��������û�з���ֵ�����ϵͳ
//
//		// �Ƿ��ʼ���ɹ���Ҫʹ��Py_IsInitialized��
//
//		Py_Initialize();
//
//
//
//		// ����ʼ���Ƿ�ɹ�
//
//		if (!Py_IsInitialized())
//
//		{
//
//			break;
//
//		}
//
//
//
//		// ��ӵ�ǰ·��
//
//		// ��������ַ�����ΪPython����ֱ�����У�����
//
//		// ��ʾ�ɹ���-1��ʾ�д����ʱ���������Ϊ�ַ���
//
//		// �����﷨����
//
//		PyRun_SimpleString("importsys");
//
//		PyRun_SimpleString("sys.path.append('./pyfile/')");
//
//
//
//		// ������ΪPyPlugin�Ľű�
//
//		pName = PyString_FromString("PyPlugin");
//
//		pModule = PyImport_Import(pName);
//
//		if (!pModule)
//
//		{
//
//			printf("can't findPyPlugin.py\n");
//
//			break;
//
//		}
//
//
//
//		pDict = PyModule_GetDict(pModule);
//
//		if (!pDict)
//
//		{
//
//			break;
//
//		}
//
//
//
//		// �ҳ�������ΪAddMult�ĺ���
//
//		pFunc = PyDict_GetItemString(pDict, "AddMult");
//
//		if (!pFunc || !PyCallable_Check(pFunc))
//
//		{
//
//			printf("can't findfunction [AddMult]\n");
//
//			break;
//
//		}
//
//
//
//		pArgs = Py_BuildValue("ii", 12, 14);
//
//		PyObject* pRet = PyEval_CallObject(pFunc, pArgs);
//
//		int a = 0;
//
//		int b = 0;
//
//		if (pRet && PyArg_ParseTuple(pRet, "ii", &a, &b))
//
//		{
//
//			printf("Function[AddMult] call successful a + b = %d, a * b = %d\n", a, b);
//
//			nRet = 0;
//
//		}
//
//
//
//		if (pArgs)
//
//			Py_DECREF(pArgs);
//
//		if (pFunc)
//
//			Py_DECREF(pFunc);
//
//		// �ҳ�������ΪHelloWorld�ĺ���
//
//		pFunc = PyDict_GetItemString(pDict, "HelloWorld");
//
//		if (!pFunc || !PyCallable_Check(pFunc))
//
//		{
//
//			printf("can't findfunction [HelloWorld]\n");
//
//			break;
//
//		}
//
//		pArgs = Py_BuildValue("(s)", "magictong");
//
//		PyEval_CallObject(pFunc, pArgs);
//
//	} while (0);
//
//
//
//	if (pRet)
//
//		Py_DECREF(pRet);
//
//	if (pArgs)
//
//		Py_DECREF(pArgs);
//
//	if (pFunc)
//
//		Py_DECREF(pFunc);
//
//	if (pDict)
//
//		Py_DECREF(pDict);
//
//	if (pModule)
//
//		Py_DECREF(pModule);
//
//	if (pName)
//
//		Py_DECREF(pName);
//
//	Py_Finalize();
//
//
//
//	return 0;
//
//}
int main()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		return -1;
	}
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("import os");
	PyRun_SimpleString("sys.path.append('./pyfile/')");
	PyRun_SimpleString("print sys.path");

	PyObject *pModule = NULL;
	pModule = PyImport_ImportModule("PyPligin");  //�õ��ļ�hello.py
	if (!pModule)
	{
		printf("not found .py file\n");
	}

	PyObject *pFunc = NULL;
	PyObject *pValue = NULL;

	//pValue = PyObject_CallMethod(pModule, "add", "ii", 10, 20);   //ͨ������õ���ģ��ֱ�ӷ���ģ������ĺ���add(a,b)
	//															  //ע�������"ii"��ʵ���൱��C�е�"%d%d"�Ĺ��ܣ���ο��ĵ�
	//cout << PyLong_AsLong(pValue) << endl;            //���õ���pValueֵת��ΪC�е�long��


	pValue = PyObject_CallMethod(pModule, "update", "");
	cout << PyLong_AsLong(pValue) << endl;


	//pFunc = PyObject_GetAttrString(pModule, "add");  //Ҳ����ʹ�øú����õ���������
	//pValue = PyObject_CallFunction(pFunc, "ii", 1, 2);    //ͨ����������ִ�к���
	//cout << PyLong_AsLong(pValue) << endl;


	printf("success!\n");
	Py_Finalize(); /* ����Python���������ͷ���Դ */

	int i = 0;
	cin >> i;
	return 0;
}