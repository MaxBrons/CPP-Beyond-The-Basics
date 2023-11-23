project "GameOfLife-Assembly"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"src",
		"../Core/src",
		"vendor/glfw/include",
		"vendor/glad/include",
		"vendor/glm"
	}

	links
	{
		"Core",
		"GLFW",
		"Glad",
		"opengl32.lib"
		
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	filter "configurations:Debug"
		defines "BTB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BTB_RELEASE"
		runtime "Release"
        	optimize "on"
