#!/bin/bash

# Nombre del proyecto
PROYECTO="MinijuegosPOO"

# Crear carpetas
mkdir -p $PROYECTO/{src,include,data,historial}

# Archivos .h
touch $PROYECTO/include/Juego.h
touch $PROYECTO/include/Ahorcado.h
touch $PROYECTO/include/Concentrece.h
touch $PROYECTO/include/Jugador.h
touch $PROYECTO/include/ArchivoHistorial.h

# Archivos .cpp
touch $PROYECTO/src/main.cpp
touch $PROYECTO/src/Juego.cpp
touch $PROYECTO/src/Ahorcado.cpp
touch $PROYECTO/src/Concentrece.cpp
touch $PROYECTO/src/Jugador.cpp
touch $PROYECTO/src/ArchivoHistorial.cpp

# Archivos de datos
touch $PROYECTO/data/palabras.txt
touch $PROYECTO/data/parejas.txt

# Historial
touch $PROYECTO/historial/partidas.txt

# Crear archivo de solución .sln
cat <<EOF > $PROYECTO/MinijuegosPOO.sln
Microsoft Visual Studio Solution File, Format Version 12.00
# Visual Studio Version 17
VisualStudioVersion = 17.3.32611.286
MinimumVisualStudioVersion = 10.0.40219.1
Project("{FAE04EC0-301F-11D3-BF4B-00C04F79EFBC}") = "MinijuegosPOO", "MinijuegosPOO.vcxproj", "{12345678-1234-1234-1234-1234567890AB}"
EndProject
Global
	GlobalSection(SolutionConfigurationPlatforms) = preSolution
		Debug|x64 = Debug|x64
		Release|x64 = Release|x64
	EndGlobalSection
	GlobalSection(ProjectConfigurationPlatforms) = postSolution
		{12345678-1234-1234-1234-1234567890AB}.Debug|x64.ActiveCfg = Debug|x64
		{12345678-1234-1234-1234-1234567890AB}.Debug|x64.Build.0 = Debug|x64
		{12345678-1234-1234-1234-1234567890AB}.Release|x64.ActiveCfg = Release|x64
		{12345678-1234-1234-1234-1234567890AB}.Release|x64.Build.0 = Release|x64
	EndGlobalSection
EndGlobal
EOF

# Crear archivo del proyecto .vcxproj
cat <<EOF > $PROYECTO/MinijuegosPOO.vcxproj
<?xml version="1.0" encoding="utf-8"?>
<Project DefaultTargets="Build" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup Label="ProjectConfigurations">
    <ProjectConfiguration Include="Debug|x64">
      <Configuration>Debug</Configuration>
      <Platform>x64</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|x64">
      <Configuration>Release</Configuration>
      <Platform>x64</Platform>
    </ProjectConfiguration>
  </ItemGroup>
  <PropertyGroup Label="Globals">
    <ProjectGuid>{12345678-1234-1234-1234-1234567890AB}</ProjectGuid>
    <RootNamespace>MinijuegosPOO</RootNamespace>
    <WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion>
  </PropertyGroup>
  <Import Project="\$(VCTargetsPath)\Microsoft.Cpp.Default.props" />
  <PropertyGroup Condition="'\$(Configuration)|\$(Platform)'=='Debug|x64'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>true</UseDebugLibraries>
    <PlatformToolset>v143</PlatformToolset>
  </PropertyGroup>
  <PropertyGroup Condition="'\$(Configuration)|\$(Platform)'=='Release|x64'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>false</UseDebugLibraries>
    <PlatformToolset>v143</PlatformToolset>
  </PropertyGroup>
  <Import Project="\$(VCTargetsPath)\Microsoft.Cpp.props" />
  <ItemGroup>
    <ClInclude Include="include\Juego.h" />
    <ClInclude Include="include\Ahorcado.h" />
    <ClInclude Include="include\Concentrece.h" />
    <ClInclude Include="include\Jugador.h" />
    <ClInclude Include="include\ArchivoHistorial.h" />
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="src\main.cpp" />
    <ClCompile Include="src\Juego.cpp" />
    <ClCompile Include="src\Ahorcado.cpp" />
    <ClCompile Include="src\Concentrece.cpp" />
    <ClCompile Include="src\Jugador.cpp" />
    <ClCompile Include="src\ArchivoHistorial.cpp" />
  </ItemGroup>
  <Import Project="\$(VCTargetsPath)\Microsoft.Cpp.targets" />
</Project>
EOF

echo " Proyecto '$PROYECTO' creado con éxito."
