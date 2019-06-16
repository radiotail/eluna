#include <stdio.h>
#include <string.h>
#include "ELuna.h"

struct TestObj
{
	TestObj(const char* name): m_name(name){};
	~TestObj(){};
	void print(){printf("hello world: %s [%p]\n", m_name, this);};
	void changeName(const char* name) {m_name = name;};
	const char* m_name;
};

class Test
{
public:
	Test() { 
		printf(" Test0 Constructor!\n");
	}

	~Test() { printf(" Test0 Destructor!\n");}

	void foo0() {
		printf("foo0: \n");
	}

	void foo1(int p1) {
		printf("foo1: %d\n", p1);
	}

	void foo2(int p1, int p2) {
		printf("foo2: %d %d\n", p1, p2);
	}

	void foo3(int p1, int p2, int p3) {
		printf("foo3: %d %d %d\n", p1, p2, p3);
	}

	void foo4(int p1, int p2, int p3, int p4) {
		printf("foo4: %d %d %d %d\n", p1, p2, p3, p4);
	}

	void foo5(int p1, int p2, int p3, int p4, int p5) {
		printf("foo5: %d %d %d %d %d\n", p1, p2, p3, p4, p5);
	}

	void foo6(int p1, int p2, int p3, int p4, int p5, int p6) {
		printf("foo6: %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6);
	}

	void foo7(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
		printf("foo7: %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7);
	}

	void foo8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
		printf("foo8: %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8);
	}

	void foo9(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
		printf("foo9: %d %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
	}

	int retFoo0() {
		return 0;
	}

	int retFoo1(int p1) {
		return p1;
	}

	int retFoo2(int p1, int p2) {
		return p1 + p2;
	}

	int retFoo3(int p1, int p2, int p3) {
		return p1 + p2 + p3;
	}

	int retFoo4(int p1, int p2, int p3, int p4) {
		return p1 + p2 + p3 + p4;
	}

	int retFoo5(int p1, int p2, int p3, int p4, int p5) {
		return p1 + p2 + p3 + p4 + p5;
	}

	int retFoo6(int p1, int p2, int p3, int p4, int p5, int p6) {
		return p1 + p2 + p3 + p4 + p5 + p6;
	}

	int retFoo7(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
		return p1 + p2 + p3 + p4 + p5 + p6 + p7;
	}

	int retFoo8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
		return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8;
	}

	int retFoo9(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
		return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
	}

	bool testBool(bool p) {
		return p;
	}

	char* testPChar(char* p) {
		return p;
	}

	const char* testPConstChar(const char* p) {
		return p;
	}

	char testChar(char p) {
		return p;
	}

	unsigned char testUChar(unsigned char p) {
		return p;
	}

	short testShort(short p) {
		return p;
	}

	unsigned short testUShort(unsigned short p) {
		return p;
	}

	long testLong(long p) {
		return p;
	}

	unsigned long testULong(unsigned long p) {
		return p;
	}

	unsigned int testUInt(unsigned int p) {
		return p;
	}

	long long testLongLong(long long p) {
		return p;
	}

	unsigned long long testULongLong(unsigned long long p) {
		return p;
	}
	
	float testFloat(float p) {
		return p;
	}

	double testDouble(double p) {
		return p;
	}
	
	ELuna::LuaString testLuaString(ELuna::LuaString p) {
		return p;
	}

	std::string testStdString(std::string p) {
		return p;
	}

	ELuna::LuaTable testLuaTable(ELuna::LuaTable p) {
		p.set(2, "world");
		printf("has key: %d\n", p.has("world"));
		printf("has key: %d\n", p.has(1));
		printf("has key: %d\n", p.has(2));
		printf("has key: %d\n", p.has(100));
		printf("get value: %s\n", p.get<int, const char*>(1));
		printf("get value: %s\n", p.get<int, const char*>(2));

		return p;
	}

	TestObj testObj(TestObj p) {
		p.m_name = "TestObj Change";
		return p;
	}

	TestObj& testObjRef(TestObj& p) {
		p.m_name = "TestObjRef Changed";
		return p;
	}

	void testObjPointer(TestObj* p) {
		p->m_name = "TestObjPointer Changed";
	}

	TestObj* testObjPointer1(TestObj* p) {
		p->m_name = "TestObjPointer Changed";
		p = new TestObj("fuck pointer");  // will memory leak, need delete. c new, c delete
		return p;
	}

	TestObj* testObjPointer2(TestObj* p) {
		p->m_name = "TestObjPointer Changed";
		return p;
	}

	const TestObj* testObjPointer3(TestObj* p) {
		return p;
	}

	const TestObj* testObjPointer4(const TestObj* p) {
		return p;
	}
private:
};

class Test1
{
public:
	Test1(int p1) { 
		printf(" Test1 Constructor! %d\n", p1);
	}

	~Test1() { printf(" Test1 Destructor!\n");}
};

class Test2
{
public:
	Test2(int p1, int p2) { 
		printf(" Test2 Constructor! %d %d\n", p1, p2);
	}

	~Test2() { printf(" Test2 Destructor!\n");}
};

class Test3
{
public:
	Test3(int p1, int p2, int p3) { 
		printf(" Test3 Constructor! %d %d %d\n", p1, p2, p3);
	}

	~Test3() { printf(" Test3 Destructor!\n");}
};

class Test4
{
public:
	Test4(int p1, int p2, int p3, int p4) { 
		printf(" Test4 Constructor! %d %d %d %d\n", p1, p2, p3, p4);
	}

	~Test4() { printf(" Test4 Destructor!\n");}
};

class Test5
{
public:
	Test5(int p1, int p2, int p3, int p4, int p5) { 
		printf(" Test5 Constructor! %d %d %d %d %d\n", p1, p2, p3, p4, p5);
	}

	~Test5() { printf(" Test5 Destructor!\n");}
};

class Test6
{
public:
	Test6(int p1, int p2, int p3, int p4, int p5, int p6) { 
		printf(" Test6 Constructor! %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6);
	}

	~Test6() { printf(" Test6 Destructor!\n");}
};

class Test7
{
public:
	Test7(int p1, int p2, int p3, int p4, int p5, int p6, int p7) { 
		printf(" Test7 Constructor! %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7);
	}

	~Test7() { printf(" Test7 Destructor!\n");}
};

class Test8
{
public:
	Test8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) { 
		printf(" Test8 Constructor! %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8);
	}

	~Test8() { printf(" Test8 Destructor!\n");}
};

class Test9
{
public:
	Test9(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) { 
		printf(" Test9 Constructor! %d %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
	}

	~Test9() { printf(" Test9 Destructor!\n");}
};

void foo0() {
	printf("foo0: \n");
}

void foo1(int p1) {
	printf("foo1: %d\n", p1);
}

void foo2(int p1, int p2) {
	printf("foo2: %d %d\n", p1, p2);
}

void foo3(int p1, int p2, int p3) {
	printf("foo3: %d %d %d\n", p1, p2, p3);
}

void foo4(int p1, int p2, int p3, int p4) {
	printf("foo4: %d %d %d %d\n", p1, p2, p3, p4);
}

void foo5(int p1, int p2, int p3, int p4, int p5) {
	printf("foo5: %d %d %d %d %d\n", p1, p2, p3, p4, p5);
}

void foo6(int p1, int p2, int p3, int p4, int p5, int p6) {
	printf("foo6: %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6);
}

void foo7(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
	printf("foo7: %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7);
}

void foo8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
	printf("foo8: %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8);
}

void foo9(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
	printf("foo9: %d %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
}

int retFoo0() {
	return 0;
}

int retFoo1(int p1) {
	return p1;
}

int retFoo2(int p1, int p2) {
	return p1 + p2;
}

int retFoo3(int p1, int p2, int p3) {
	return p1 + p2 + p3;
}

int retFoo4(int p1, int p2, int p3, int p4) {
	return p1 + p2 + p3 + p4;
}

int retFoo5(int p1, int p2, int p3, int p4, int p5) {
	return p1 + p2 + p3 + p4 + p5;
}

int retFoo6(int p1, int p2, int p3, int p4, int p5, int p6) {
	return p1 + p2 + p3 + p4 + p5 + p6;
}

int retFoo7(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
	return p1 + p2 + p3 + p4 + p5 + p6 + p7;
}

int retFoo8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
	return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8;
}

int retFoo9(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
	return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
}

TestObj retObj(TestObj p) {
	p.m_name = "RetObj Change";
	return p;
}

TestObj& retObjRef(TestObj& p) {
	p.m_name = "RetObjRef Changed";
	return p;
}

TestObj* retObjPointer1(TestObj* p) {
	p->m_name = "RetObjPointer Changed";
	p = new TestObj("fuck pointer");  // will memory leak, need delete. c new, c delete
	return p;
}

TestObj* retObjPointer(TestObj* p) {
	p->m_name = "RetObjPointer Changed";
	return p;
}

void testCPP(lua_State* L) {
	//register a class and it's constructor. indicate all constructor's param type
	ELuna::registerClass<Test>(L, "Test0", ELuna::constructor<Test>);
	ELuna::registerClass<TestObj>(L, "TestObj", ELuna::constructor<TestObj, const char*>);
	//register a method
	ELuna::registerMethod<Test>(L, "foo0", &Test::foo0);
	ELuna::registerMethod<Test>(L, "foo1", &Test::foo1);
	ELuna::registerMethod<Test>(L, "foo2", &Test::foo2);
	ELuna::registerMethod<Test>(L, "foo3", &Test::foo3);
	ELuna::registerMethod<Test>(L, "foo4", &Test::foo4);
	ELuna::registerMethod<Test>(L, "foo5", &Test::foo5);
	ELuna::registerMethod<Test>(L, "foo6", &Test::foo6);
	ELuna::registerMethod<Test>(L, "foo7", &Test::foo7);
	ELuna::registerMethod<Test>(L, "foo8", &Test::foo8);
	ELuna::registerMethod<Test>(L, "foo9", &Test::foo9);

	ELuna::registerMethod<Test>(L, "retFoo0", &Test::retFoo0);
	ELuna::registerMethod<Test>(L, "retFoo1", &Test::retFoo1);
	ELuna::registerMethod<Test>(L, "retFoo2", &Test::retFoo2);
	ELuna::registerMethod<Test>(L, "retFoo3", &Test::retFoo3);
	ELuna::registerMethod<Test>(L, "retFoo4", &Test::retFoo4);
	ELuna::registerMethod<Test>(L, "retFoo5", &Test::retFoo5);
	ELuna::registerMethod<Test>(L, "retFoo6", &Test::retFoo6);
	ELuna::registerMethod<Test>(L, "retFoo7", &Test::retFoo7);
	ELuna::registerMethod<Test>(L, "retFoo8", &Test::retFoo8);
	ELuna::registerMethod<Test>(L, "retFoo9", &Test::retFoo9);

	ELuna::registerMethod<TestObj>(L, "print", &TestObj::print);
	ELuna::registerMethod<TestObj>(L, "changeName", &TestObj::changeName);

	//test read2cpp and push2lua
	ELuna::registerMethod<Test>(L, "testBool", &Test::testBool);
	ELuna::registerMethod<Test>(L, "testChar", &Test::testChar);
	ELuna::registerMethod<Test>(L, "testDouble", &Test::testDouble);
	ELuna::registerMethod<Test>(L, "testFloat", &Test::testFloat);
	ELuna::registerMethod<Test>(L, "testLong", &Test::testLong);
	ELuna::registerMethod<Test>(L, "testLongLong", &Test::testLongLong);
	ELuna::registerMethod<Test>(L, "testLuaString", &Test::testLuaString);
	ELuna::registerMethod<Test>(L, "testStdString", &Test::testStdString);
	ELuna::registerMethod<Test>(L, "testPChar", &Test::testPChar);
	ELuna::registerMethod<Test>(L, "testPConstChar", &Test::testPConstChar);
	ELuna::registerMethod<Test>(L, "testShort", &Test::testShort);
	ELuna::registerMethod<Test>(L, "testUChar", &Test::testUChar);
	ELuna::registerMethod<Test>(L, "testUInt", &Test::testUInt);
	ELuna::registerMethod<Test>(L, "testULong", &Test::testULong);
	ELuna::registerMethod<Test>(L, "testULongLong", &Test::testULongLong);
	ELuna::registerMethod<Test>(L, "testUShort", &Test::testUShort);
	ELuna::registerMethod<Test>(L, "testLuaTable", &Test::testLuaTable);
	ELuna::registerMethod<Test>(L, "testObjPointer", &Test::testObjPointer);
	ELuna::registerMethod<Test>(L, "testObjPointer1", &Test::testObjPointer1);
	ELuna::registerMethod<Test>(L, "testObjPointer2", &Test::testObjPointer2);
	ELuna::registerMethod<Test>(L, "testObjPointer3", &Test::testObjPointer3);
	ELuna::registerMethod<Test>(L, "testObjPointer4", &Test::testObjPointer4);
	ELuna::registerMethod<Test>(L, "testObj", &Test::testObj);
	ELuna::registerMethod<Test>(L, "testObjRef", &Test::testObjRef);

	//register a function
	ELuna::registerFunction(L, "cppFoo0", &foo0);
	ELuna::registerFunction(L, "cppFoo1", &foo1);
	ELuna::registerFunction(L, "cppFoo2", &foo2);
	ELuna::registerFunction(L, "cppFoo3", &foo3);
	ELuna::registerFunction(L, "cppFoo4", &foo4);
	ELuna::registerFunction(L, "cppFoo5", &foo5);
	ELuna::registerFunction(L, "cppFoo6", &foo6);
	ELuna::registerFunction(L, "cppFoo7", &foo7);
	ELuna::registerFunction(L, "cppFoo8", &foo8);
	ELuna::registerFunction(L, "cppFoo9", &foo9);

	ELuna::registerFunction(L, "cppRetFoo0", &retFoo0);
	ELuna::registerFunction(L, "cppRetFoo1", &retFoo1);
	ELuna::registerFunction(L, "cppRetFoo2", &retFoo2);
	ELuna::registerFunction(L, "cppRetFoo3", &retFoo3);
	ELuna::registerFunction(L, "cppRetFoo4", &retFoo4);
	ELuna::registerFunction(L, "cppRetFoo5", &retFoo5);
	ELuna::registerFunction(L, "cppRetFoo6", &retFoo6);
	ELuna::registerFunction(L, "cppRetFoo7", &retFoo7);
	ELuna::registerFunction(L, "cppRetFoo8", &retFoo8);
	ELuna::registerFunction(L, "cppRetFoo9", &retFoo9);
	ELuna::registerFunction(L, "cppRetObj", &retObj);
	ELuna::registerFunction(L, "cppRetObjRef", &retObjRef);
	ELuna::registerFunction(L, "cppRetObjPointer", &retObjPointer);
	ELuna::registerFunction(L, "cppRetObjPointer1", &retObjPointer1);

	//test constructor
	ELuna::registerClass<Test1>(L, "Test1", ELuna::constructor<Test1, int>);
	ELuna::registerClass<Test2>(L, "Test2", ELuna::constructor<Test2, int, int>);
	ELuna::registerClass<Test3>(L, "Test3", ELuna::constructor<Test3, int, int, int>);
	ELuna::registerClass<Test4>(L, "Test4", ELuna::constructor<Test4, int, int, int, int>);
	ELuna::registerClass<Test5>(L, "Test5", ELuna::constructor<Test5, int, int, int, int, int>);
	ELuna::registerClass<Test6>(L, "Test6", ELuna::constructor<Test6, int, int, int, int, int, int>);
	ELuna::registerClass<Test7>(L, "Test7", ELuna::constructor<Test7, int, int, int, int, int, int, int>);
	ELuna::registerClass<Test8>(L, "Test8", ELuna::constructor<Test8, int, int, int, int, int, int, int, int>);
	ELuna::registerClass<Test9>(L, "Test9", ELuna::constructor<Test9, int, int, int, int, int, int, int, int, int>);
}

void testLua(lua_State* L) {
	printf("------------testLua------------\n");
	ELuna::LuaFunction<void> foo0(L, "foo0");
	ELuna::LuaFunction<void> foo1(L, "foo1");
	ELuna::LuaFunction<void> foo2(L, "foo2");
	ELuna::LuaFunction<void> foo3(L, "foo3");
	ELuna::LuaFunction<void> foo4(L, "foo4");
	ELuna::LuaFunction<void> foo5(L, "foo5");
	ELuna::LuaFunction<void> foo6(L, "foo6");
	ELuna::LuaFunction<void> foo7(L, "foo7");
	ELuna::LuaFunction<void> foo8(L, "foo8");
	ELuna::LuaFunction<void> foo9(L, "foo9");

	ELuna::LuaFunction<int> retFoo0(L, "retFoo0");
	ELuna::LuaFunction<int> retFoo1(L, "retFoo1");
	ELuna::LuaFunction<int> retFoo2(L, "retFoo2");
	ELuna::LuaFunction<int> retFoo3(L, "retFoo3");
	ELuna::LuaFunction<int> retFoo4(L, "retFoo4");
	ELuna::LuaFunction<int> retFoo5(L, "retFoo5");
	ELuna::LuaFunction<int> retFoo6(L, "retFoo6");
	ELuna::LuaFunction<int> retFoo7(L, "retFoo7");
	ELuna::LuaFunction<int> retFoo8(L, "retFoo8");
	ELuna::LuaFunction<int> retFoo9(L, "retFoo9");
	ELuna::LuaFunction<TestObj*> luaTestObjPointer(L, "luaTestObjPointer");
	ELuna::LuaFunction<TestObj&> luaTestObjRef(L, "luaTestObjRef");
	ELuna::LuaFunction<TestObj> luaTestObj(L, "luaTestObj");

	foo0();
	foo1(1);
	foo2(1,2);
	foo3(1,2,3);
	foo4(1,2,3,4);
	foo5(1,2,3,4,5);
	foo6(1,2,3,4,5,6);
	foo7(1,2,3,4,5,6,7);
	foo8(1,2,3,4,5,6,7,8);
	foo9(1,2,3,4,5,6,7,8,9);

	printf("retFoo0: %d\n", retFoo0());
	printf("retFoo1: %d\n", retFoo1(1));
	printf("retFoo2: %d\n", retFoo2(1,2));
	printf("retFoo3: %d\n", retFoo3(1,2,3));
	printf("retFoo4: %d\n", retFoo4(1,2,3,4));
	printf("retFoo5: %d\n", retFoo5(1,2,3,4,5));
	printf("retFoo6: %d\n", retFoo6(1,2,3,4,5,6));
	printf("retFoo7: %d\n", retFoo7(1,2,3,4,5,6,7));
	printf("retFoo8: %d\n", retFoo8(1,2,3,4,5,6,7,8));
	printf("retFoo9: %d\n", retFoo9(1,2,3,4,5,6,7,8,9));

	printf("luaTestObjPointer: \n");
	TestObj pObj = TestObj("TestObjPointer");
	TestObj* retPObj = luaTestObjPointer(&pObj);
	pObj.print();
	retPObj->print();

	printf("luaTestObjRef1: \n");
	TestObj objRef1("TestObjRef1");
	TestObj& retObjRef1 = luaTestObjRef(&objRef1);
	objRef1.print();
	retObjRef1.print();
	
	printf("luaTestObjRef2: \n");
	TestObj objRef2("TestObjRef2");
	TestObj& retObjRef2 = luaTestObjRef(objRef2);
	objRef2.print();
	retObjRef2.print();
	
	printf("luaTestObj: \n");
	TestObj obj("TestObj");
	TestObj retObj = luaTestObj(obj);
	obj.print();
	retObj.print();
	printf("pass refrence to luaFunction the same as object!\n");
}


const char *fileName = "../sample/testInterface.lua";
int main()
{
	lua_State *L = ELuna::openLua();

	testCPP(L);

	ELuna::doFile(L, fileName);

	testLua(L);
	ELuna::closeLua(L);

	getchar();

	return 0;
}