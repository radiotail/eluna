solution "ELuna"
    location("../build")
	configurations {"Debug", "Release"}

	configuration "Debug"
  	defines { "DEBUG" }
	flags {"Symbols"}

	configuration "Release"
  	defines { "NDEBUG" }
	flags {"Optimize"}

	project "sample"
	kind "ConsoleApp"
	language "C++"
	targetdir "../bin"
	includedirs {"../"}
	includedirs {"../eluna"}
	
    files {"../eluna/ELuna.h", "../sample/sample.cpp"}
	
	links {"lua51"} -- fix it

	project "interface"
	kind "ConsoleApp"
	language "C++"
	targetdir "../bin"
	includedirs {"../"}
	includedirs {"../eluna"}
	
    files {"../eluna/ELuna.h", "../sample/testInterface.cpp"}
	
	links {"lua51"} -- fix it

