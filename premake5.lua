-- Beyond_The_Basics
workspace "Beyond_The_Basics"
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
include "BankAccount"
