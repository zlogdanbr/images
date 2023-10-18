echo off
clear
IF "%~1"=="" GOTO _BUILD
IF "%~1"=="--clean" python build.py --clean ELSE GOTO _SINGLE
GOTO _END
:_BUILD
python build.py --clean
python build.py --project
GOTO _END
:_SINGLE
python build.py %~1
:_END

