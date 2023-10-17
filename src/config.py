#-------------------------------------------------------------------------------------------------------------
#   HOME FOLDER
#-------------------------------------------------------------------------------------------------------------
HOME = "C:\\Users\\Administrador\\"
OPEN_CV_HOME = "\\lib\\opencv\\build\\"
#-------------------------------------------------------------------------------------------------------------
#   COMMAND FLAGS FOR CL
#-------------------------------------------------------------------------------------------------------------
COMPILER         =  "cl "
FLAGS            =  "/W3 /EHsc /std:c++17 /GA /MT " 
#-------------------------------------------------------------------------------------------------------------
#   TELL CL TO LINK
#-------------------------------------------------------------------------------------------------------------
LINK            = " /link"
#-------------------------------------------------------------------------------------------------------------
#   MY TEMPLATE ONLY HEADER LIB
#-------------------------------------------------------------------------------------------------------------
TEMPLATE_LIB    = "/I"+ HOME + "Documents\\GitHub\\mycpp\\mycpp\\template_lib "
#-------------------------------------------------------------------------------------------------------------
#   INCLUDE FOLDERS AND SRC FOLDERS
#-------------------------------------------------------------------------------------------------------------
INCLUDE         = ""
SRC             = "Image.cpp demo.cpp opcvwrapper.cpp segmentation.cpp"
#-------------------------------------------------------------------------------------------------------------
#   WINDOWS NECESSARY LIBS
#   Cimg for example requires:
#   " kernel32.lib user32.lib gdi32.lib Shell32.lib"
#-------------------------------------------------------------------------------------------------------------
LIB_WINDOWS     = ""
#-------------------------------------------------------------------------------------------------------------
#  HEADERS AND LIBS
#-------------------------------------------------------------------------------------------------------------
LIB_HEADERS   = "/I"+ HOME + OPEN_CV_HOME + "include\\ "
LIB           = " " + HOME + OPEN_CV_HOME + "x64\\vc16\\lib\\opencv_world480.lib"
#-------------------------------------------------------------------------------------------------------------
#   CMD TO BUILD
#   if you want to build only one file using build.bat just leave as "%%SRC%%"
#   and use build yourfile.cpp
#   otherwise you can add sources above in the SRC variable
#-------------------------------------------------------------------------------------------------------------
BUILD_CMD     = COMPILER + FLAGS + LIB_HEADERS + SRC + LINK + LIB
#-------------------------------------------------------------------------------------------------------------