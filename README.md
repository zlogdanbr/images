# Images
This is a project I use to learning OpenCV ( https://opencv.org ) and try to recaptulate knowledge I had while I was in college.

So, I installed OpenCV in my Windows machine and used a custom python script to build this project. 

I went through the OpenCV documentation to create three different sources.

A wrapper- opcvwrapper.cpp
-------------------------------
Provides a wrapper for most Image Processing algorithms provided by OpenCV. 
I cite the original reference page where I got the info.

A demo - demp.cpp
-------------------------------
Provides useful examples of the above wrapper

An image node classification class - segmentation.cpp
-------------------------------------------------------
I provide a segmentation class and an eye recognition algorithm class

## Building files:

It is possible to use Microsoft C++ compiler without VS IDE.  See below, how.


* git clone https://github.com/zlogdanbr/images.git
* Install python 3.10 or above
* Install Visual Studio 2022 and C++ tools
* Install https://chocolatey.org
* Download the contents of https://github.com/zlogdanbr/mycpp/tree/main/build_tool
* And add the folder you downloaded them to your windows path

Once you do that you may edit the config.py file and configure your build. 
They are easy to use and more fun than makefiles. I suspect that you can port than to Linux easily.

* build --s yoursource.cpp 	 (builds the select source ignoring the SRC variable see below )
* build						 (expects you to have set the SRC variable at config.py)
* build --clean				 (removes OBJs and EXEs files)


If you want to build only one source, please change your local config.sys to have 

BUILD_CMD     = COMPILER + FLAGS + TEMPLATE_LIB + "%%SRC%%" + LINK + LIB

this will allow the option to build a single source.

_________________________________________________
**2020, 2021, 2022, 2023 Daniel Vasconcelos Gomes**
**You can use this freely but I don't take responsibility for whatever problems this will likely cause. I use this as a library for my code.**





