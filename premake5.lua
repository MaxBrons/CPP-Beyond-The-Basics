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
include "Bank-Account"
include "Builder-Pattern"
