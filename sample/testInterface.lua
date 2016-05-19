function foo0()
	print("foo0: ")
end

function foo1(p1)
	print("foo1: ", p1)
end

function foo2(p1, p2)
	print("foo2: ", p1, p2)
end

function foo3(p1, p2, p3)
	print("foo3: ", p1, p2, p3)
end

function foo4(p1, p2, p3, p4)
	print("foo4: ", p1, p2, p3, p4)
end

function foo5(p1, p2, p3, p4, p5)
	print("foo5: ", p1, p2, p3, p4, p5)
end

function foo6(p1, p2, p3, p4, p5, p6)
	print("foo6: ", p1, p2, p3, p4, p5, p6)
end

function foo7(p1, p2, p3, p4, p5, p6, p7)
	print("foo7: ", p1, p2, p3, p4, p5, p6, p7)
end

function foo8(p1, p2, p3, p4, p5, p6, p7, p8)
	print("foo8: ", p1, p2, p3, p4, p5, p6, p7, p8)
end

function foo9(p1, p2, p3, p4, p5, p6, p7, p8, p9)
	print("foo9: ", p1, p2, p3, p4, p5, p6, p7, p8, p9)
end

function retFoo0()
	return 0
end

function retFoo1(p1)
	return p1
end

function retFoo2(p1, p2)
	return p1 + p2
end

function retFoo3(p1, p2, p3)
	return p1 + p2 + p3
end

function retFoo4(p1, p2, p3, p4)
	return p1 + p2 + p3 + p4
end

function retFoo5(p1, p2, p3, p4, p5)
	return p1 + p2 + p3 + p4 + p5
end

function retFoo6(p1, p2, p3, p4, p5, p6)
	return p1 + p2 + p3 + p4 + p5 + p6
end

function retFoo7(p1, p2, p3, p4, p5, p6, p7)
	return p1 + p2 + p3 + p4 + p5 + p6 + p7
end

function retFoo8(p1, p2, p3, p4, p5, p6, p7, p8)
	return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8
end

function retFoo9(p1, p2, p3, p4, p5, p6, p7, p8, p9)
	return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9
end

function luaTestObjPointer(pObj)
	pObj:changeName("TestObjPointer Changed")
	return pObj
end

function luaTestObj(obj)
	obj:changeName("TestObj Changed")
	return obj
end

function luaTestObjRef(objRef)
	objRef:changeName("TestObjRef Changed")
	return objRef
end

----------------------------------------------------------
print("run cpp interface")
local cppTest  = Test0()
local cppTest1 = Test1(1)
local cppTest2 = Test2(1,2)
local cppTest3 = Test3(1,2,3)
local cppTest4 = Test4(1,2,3,4)
local cppTest5 = Test5(1,2,3,4,5)
local cppTest6 = Test6(1,2,3,4,5,6)
local cppTest7 = Test7(1,2,3,4,5,6,7)
local cppTest8 = Test8(1,2,3,4,5,6,7,8)
local cppTest9 = Test9(1,2,3,4,5,6,7,8,9)


cppTest:foo0()
cppTest:foo1(1)
cppTest:foo2(1,2)
cppTest:foo3(1,2,3)
cppTest:foo4(1,2,3,4)
cppTest:foo5(1,2,3,4,5)
cppTest:foo6(1,2,3,4,5,6)
cppTest:foo7(1,2,3,4,5,6,7)
cppTest:foo8(1,2,3,4,5,6,7,8)
cppTest:foo9(1,2,3,4,5,6,7,8,9)

print("method retFoo0: ", cppTest:retFoo0())
print("method retFoo1: ", cppTest:retFoo1(1))
print("method retFoo2: ", cppTest:retFoo2(1,2))
print("method retFoo3: ", cppTest:retFoo3(1,2,3))
print("method retFoo4: ", cppTest:retFoo4(1,2,3,4))
print("method retFoo5: ", cppTest:retFoo5(1,2,3,4,5))
print("method retFoo6: ", cppTest:retFoo6(1,2,3,4,5,6))
print("method retFoo7: ", cppTest:retFoo7(1,2,3,4,5,6,7))
print("method retFoo8: ", cppTest:retFoo8(1,2,3,4,5,6,7,8))
print("method retFoo9: ", cppTest:retFoo9(1,2,3,4,5,6,7,8,9))

print("---------------------test read2cpp and push2lua--------------------")
print("testBool: ", cppTest:testBool(true))
print("testPChar: ", cppTest:testPChar("hello world"))
print("testPConstChar: ", cppTest:testPConstChar("hello world"))
print("testChar: ", cppTest:testChar(49))
print("testUChar: ", cppTest:testUChar(49))
print("testShort: ", cppTest:testShort(-1))
print("testUShort: ", cppTest:testUShort(1))
print("testLong: ", cppTest:testLong(-1))
print("testULong: ", cppTest:testULong(1))
print("testUInt: ", cppTest:testUInt(1))
print("testLongLong: ", cppTest:testLongLong(-1))
print("testULongLong: ", cppTest:testULongLong(-1))
print("testFloat: ", cppTest:testFloat(0.33))
print("testDouble: ", cppTest:testDouble(0.33))
print("testLuaString: ", cppTest:testLuaString("hello world"))
print("testStdString: ", cppTest:testStdString("hello world"))

local table = {"hello"}
local retTable = cppTest:testLuaTable(table)
print("method testLuaTable: ", retTable[1], retTable[2])

local pObj = TestObj("TestObjPointer")
cppTest:testObjPointer(pObj)
print("method testObjPointer: ")
pObj:print()

local pObj = TestObj("TestObjPointer1")
local a = cppTest:testObjPointer1(pObj)
print("method testObjPointer1: ", a, pObj)
pObj:print()
a:print()

local pObj = TestObj("TestObjPointer2")
local a = cppTest:testObjPointer2(pObj)
print("method testObjPointer2: ", a, pObj)
pObj:print()
a:print()

local obj = TestObj("TestObj")
local a = cppTest:testObj(obj)
print("method testObj: ", a, obj)
obj:print()
a:print()

local objRef = TestObj("TestObjRef")
local a = cppTest:testObjRef(objRef)
print("method testObjRef: ", a, objRef)
objRef:print()
a:print()

cppFoo0()
cppFoo1(1)
cppFoo2(1,2)
cppFoo3(1,2,3)
cppFoo4(1,2,3,4)
cppFoo5(1,2,3,4,5)
cppFoo6(1,2,3,4,5,6)
cppFoo7(1,2,3,4,5,6,7)
cppFoo8(1,2,3,4,5,6,7,8)
cppFoo9(1,2,3,4,5,6,7,8,9)

print("function retFoo0: ", cppRetFoo0())
print("function retFoo1: ", cppRetFoo1(1))
print("function retFoo2: ", cppRetFoo2(1,2))
print("function retFoo3: ", cppRetFoo3(1,2,3))
print("function retFoo4: ", cppRetFoo4(1,2,3,4))
print("function retFoo5: ", cppRetFoo5(1,2,3,4,5))
print("function retFoo6: ", cppRetFoo6(1,2,3,4,5,6))
print("function retFoo7: ", cppRetFoo7(1,2,3,4,5,6,7))
print("function retFoo8: ", cppRetFoo8(1,2,3,4,5,6,7,8))
print("function retFoo9: ", cppRetFoo9(1,2,3,4,5,6,7,8,9))

local pObj = TestObj("RetObjPointer")
local a = cppRetObjPointer(pObj)
print("function cppRetObjPointer: ", a, pObj)
pObj:print()
a:print()

local pObj = TestObj("RetObjPointer1")
local a = cppRetObjPointer1(pObj)
print("function cppRetObjPointer1: ", a, pObj)
pObj:print()
a:print()

local obj = TestObj("RetObj")
local a = cppRetObj(obj)
print("function cppRetObj: ", a, obj)
obj:print()
a:print()

local objRef = TestObj("RetObjRef")
local a = cppRetObjRef(objRef)
print("function cppRetObjRef: ", a, objRef)
objRef:print()
a:print()










