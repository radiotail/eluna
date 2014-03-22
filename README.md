## ELuna - Extended Luna
ELuna is a simple library to bind C/C++ and Lua, which just depends on Lua library. It is clear and
lightweight. You can include ELuna and Lua in your project to use. My original intention is to do 
some extension for Luna, so its main idea bases on luna. Users don't have to focus on the details of 
binding C++ and Lua, but use some simple API provided by ELuna to bind cpp class, method, function or 
to bind lua function, table.

Before version 1.1, ELuna copied class's all methods to object's table when you create an object, that 
is the same as Luna. It needn't find method from metatable when you call cpp method, but object creation 
is very slow. Obviously, this way may be a good chiose when you call its method many times but create 
object rarely. In order to improve its efficiency, I do some adjustments in later versions. I use a new 
way to bind method which doesn't copy class's all methods to table, but register a method to class's 
metatable. When you call this method, ELuna will find this method from metatable by using "index" metamethod. 
In this way, object creation is very fast while calling method is a little slower than before. Finally, how 
to choose the version depends on your requirement.

After many versions, ELuna has been stable at present. However, maybe there are still some bugs that I didn't 
find. Please contact me when you find any problems. Of course, ELuna also can't support all the features, such
as binding member data and so on. The main reason is that they were either used rarely or implemented easily 
by other ways during my past project. For example, we can register a "get" and "set" method to take the place
of binding the member data. If you really need these features, it is simple to add by yourself.

## SAMPLE
There is a simple sample to show you how to use ELuna. In this sample, I will show you 
how to register a class(using ELuna::registerClass), a method (using ELuna::registerMethod) or 
a function(using ELuna::registerFunction) to lua, and how to register a lua 
function(using ELuna::LuaFunction?) or table(using ELuna::LuaTable?) to cpp.

```
//sample.cpp
#include <stdio.h>
#include <string.h>
#include "ELuna.h"

//define a class
class CPPClass
{
public:
        CPPClass(const char* name): m_name(name){
                printf("%s Constructor!\n", name);
        }
        ~CPPClass(){
                printf("%s Destructor!\n", m_name);
        }

        //define method
        void cppPrint(const char* word) {
                printf("%s: %s\n", m_name, word);
        }

        int cppSum(int a, int b){
                return a + b;
        }
private:
        const char* m_name;
};

//define function
void cppPrint(char* str) {
        printf("cppPrint: %s\n", str);
}

int cppSum(int a, int b){
        return a + b;
}

void testCPP(lua_State* L) {
        //register a class and it's constructor. indicate all constructor's param type
        ELuna::registerClass<CPPClass>(L, "CPPClass", ELuna::constructor<CPPClass, const char* >);
        //register a method
        ELuna::registerMethod<CPPClass>(L, "cppPrint", &CPPClass::cppPrint);
        ELuna::registerMethod<CPPClass>(L, "cppSum", &CPPClass::cppSum);

        //register a function
        ELuna::registerFunction(L, "cppPrint", &cppPrint);
        ELuna::registerFunction(L, "cppSum", &cppSum);
}

void testLua(lua_State* L) {
        //new a LuaFunction object to bind lua function. indicate return value type
        ELuna::LuaFunction<void> luaPrint(L, "luaPrint");
        ELuna::LuaFunction<int> luaSum(L, "luaSum");

        //run Luafunction's () to call lua function
        luaPrint("hello world");
        printf("luaSum: %d\n", luaSum(1,2));

        //register a lua table
        ELuna::LuaTable luaTable(L, "luaTable");
        //set table's key and value
        luaTable.set(2, "world");
        printf("LuaTable: %s %s\n", luaTable.get<char*>(1), luaTable.get<char*>(2));
}

const char *fileName = "sample.lua";

int main()
{
        lua_State *L = ELuna::openLua();

        testCPP(L);

        ELuna::doFile(L, fileName);

        testLua(L);
        ELuna::closeLua(L);

        system("pause");
        return 0;
}
```

```
/////////////////////////////////////////////////////////////////////////
//sample.lua
--new a class
local cppClass = CPPClass("cppClass")
--call cpp method
cppClass:cppPrint("Hello world!")
print("CPPClass's cppSum:", cppClass:cppSum(1,2))

--call cpp function
cppPrint("Hello world!")
print("cppSum:", cppSum(1,2))

--define lua function
function luaPrint(str)
        print("luaPrint:", str)
end

function luaSum(a, b)
        return a + b
end

--define table
luaTable = {"hello"}
```

## ATTENTIONS
Transferring or returning pointer has best efficiency, followed by reference, the worst is transferring object.


