# SDL3 Template

SDL3 Application Template

## setup

-   1st step: SDL3 For visual studio and Cmake  
    [SDL3 For Windows](https://github.com/libsdl-org/SDL/releases/download/prerelease-3.1.10/SDL3-devel-3.1.10-VC.zip)  
    [CMAKE](https://cmake.org/download/)

-   2nd step: Install CMAKE and Unzip SDL3 it and save wherever you want

This project expects the SDL3 files to be located in C:\SDL3
If you want to use other location, remeber to change the paths on CmakeLists.txt

```cmake
SET(SDL3_PATH C:/SDL3)
SET(SDL3_LIB_PATH C:/SDL3/lib/x64)
SET(SDL3_INCLUDE_PATH C:/SDL3/include)
```

-   3rd step: Build the project

```bash
cmake -S . -B build
cd build
cmake --build .
```

After that, a new folder will be created in the root of our project

<pre><strong>
sdl3-template   
├───bin (New folder)   
├───build   
│   └───...   
├───main.cpp   
├───readme.md   
└───CMakeLists.txt   
</strong></pre>

To run the project execute

```bash
cd ..\bin\
SDLTemplate.exe
```
