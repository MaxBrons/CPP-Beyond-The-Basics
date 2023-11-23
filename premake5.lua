-- Beyond-The-Basics
workspace "Beyond-The-Basics"
	architecture "x64"
	startproject "BankAccount"

	configurations
	{
		"Debug",
		"Release"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Projects
include "Core"

group "Dependencies"
include "GameOfLife/vendor/glfw-premake5.lua"
include "GameOfLife/vendor/glad-premake5.lua"
group ""
group "Assignments"
include "Bank-Account/premake5.lua"
include "Decorator-Pattern/premake5.lua"
include "Queue/premake5.lua"
include "GameOfLife/premake5.lua"
group ""
