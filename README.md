# images
Used to learn OpenCV and image processing recapping

I have installed OpenCV in my Windows machine and used a custom python script to build this project. I went through the OpenCV documentation to create three different classes.

A wrapper- opcvwrapper.cpp
-------------------------------
Provides a wrapper for most Image Processing algorithms provided by OpenCV. I cite the original reference page where I got the info.

A demo - demp.cpp
-------------------------------
Provides useful examples of the above wrapper

An image node classification class - segmentation.cpp
-------------------------------------------------------
I provide a segmentation class and an eye recognition algorithm class

In order to use:

- git clone https://github.com/zlogdanbr/images.git
- Install python 3.10 or above
- Install Visual Studio 2022 and C++ tools
- This is the configuration file that will run the building
   https://github.com/zlogdanbr/images/blob/main/src/config.py
- Make.bat will just call python --project and build what is described in the config.py file.

You can use it at your will, and please remember to mention me if possible.





