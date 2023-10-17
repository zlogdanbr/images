echo off
clear
IF "%~1"=="" GOTO _BUILD
IF "%~1"=="--clean" python build.py --clean
GOTO _END
:_BUILD
python build.py --clean
python build.py --project
:_END

