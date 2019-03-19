# About
Circular variation of classic Pong game in C++ and OpenGL.

# How to build
This project is using Premake 5 to generate projects. It can create Visual Studio 2017 project on Windows and generete Makefiles on Linux.

## Windows
First, you need to run premake in order to generate VS project. To do so simply run the **GenerateVSProject.bat** file.
Then you can open created solution and build project from there.

## Linux
Run `./GenerateMake.sh` - it will call premake to generate Makefiles.  

Then you can run Makefile in root directory and specify configuration type (if don't specify configuration it will take debug by default):  
`make config=release` or `make config=debug`  

After successfull compilation you can run  
`./Run.sh release` or `./Run.sh debug`  
or manually execute accurate file in created bin/ folder.
