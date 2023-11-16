project "Core"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src"
	}

	filter "configurations:Debug"
		defines "BTB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BTB_RELEASE"
		runtime "Release"
        	optimize "on"
