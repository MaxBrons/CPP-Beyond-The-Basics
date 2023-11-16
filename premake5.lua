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

group "Assignments"
include "Bank-Account"
include "Builder-Pattern"
include "Queue"
group ""
