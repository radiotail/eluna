--new a class
local cppClass = CPPClass("cppClass")
cppClass:print()
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

local refClass = cppClass:createRef(cppClass)
print("createRef: ", refClass, cppClass)
cppClass:print()
refClass:print()
