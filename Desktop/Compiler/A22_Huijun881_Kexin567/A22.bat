@echo off
:: ---------------------------------------------------------------------
:: COMPILERS COURSE - SCRIPT                                           -
:: SCRIPT A22 - CST8152 - Summer 2024                                  -
:: ---------------------------------------------------------------------

CLS
SET COMPILER=C:\Users\BU1\source\repos\A22\out\build\x64-debug\A22.exe

:: Setting file paths
SET FILE_PATH=C:\Users\BU1\Desktop\Compiler\A22_Huijun881_Kexin567

SET FILE1=%FILE_PATH%\emptyFile
SET FILE2=%FILE_PATH%\Error
SET FILE3=%FILE_PATH%\dataTypes

SET ASSIGNMENT=A22
SET EXTENSION=pr
SET OUTPUT=out
SET ERROR=err

SET PARAM=s
SET PARAM1=a
SET PARAM2=100
SET PARAM3=100

:: Print current directory and file path for debugging
echo Current directory: %CD%
echo Batch file path: %~dp0

:: ---------------------------------------------------------------------
:: Begin of Tests (A12 - S24) ------------------------------------------
:: ---------------------------------------------------------------------

@echo on
:: Print the value of PARAM to confirm it's set correctly
echo PARAM is set to %PARAM%
echo Running %COMPILER% with %PARAM% %FILE2%.%EXTENSION%

::
:: BASIC TESTS  ----------------------------------------------------------
::
:: Basic Tests (A12 - S24) - - - - - - - - - - - - - - - - - - - - - -
echo Running command: %COMPILER% %PARAM% %FILE1%.%EXTENSION% %PARAM1% %PARAM2% %PARAM3%
%COMPILER% %PARAM% %FILE1%.%EXTENSION% %PARAM1% %PARAM2% %PARAM3% > %FILE1%-%ASSIGNMENT%.%OUTPUT% 2> %FILE1%-%ASSIGNMENT%.%ERROR%
echo Command finished for %FILE1%

echo Running command: %COMPILER% %PARAM% %FILE2%.%EXTENSION% %PARAM1% %PARAM2% %PARAM3%
%COMPILER% %PARAM% %FILE2%.%EXTENSION% %PARAM1% %PARAM2% %PARAM3% > %FILE2%-%ASSIGNMENT%.%OUTPUT% 2> %FILE2%-%ASSIGNMENT%.%ERROR%
echo Command finished for %FILE2%

echo Running command: %COMPILER% %PARAM% %FILE3%.%EXTENSION% %PARAM1% %PARAM2% %PARAM3%
%COMPILER% %PARAM% %FILE3%.%EXTENSION% %PARAM1% %PARAM2% %PARAM3% > %FILE3%-%ASSIGNMENT%.%OUTPUT% 2> %FILE3%-%ASSIGNMENT%.%ERROR%
echo Command finished for %FILE3%

::
:: ADVANCED TESTS  -------------------------------------------------------
::
:: Advanced Tests (A12 - S24) - - - - - - - - -- - - - - - - - - - - -

::echo Running command: %COMPILER% %PARAM% %FILE7%.%EXTENSION% f 100 10
::%COMPILER% %PARAM% %FILE7%.%EXTENSION% f 100 10 > %FILE7%-%ASSIGNMENT%-f-100-10.%OUTPUT% 2> %FILE7%-%ASSIGNMENT%-f-100-10.%ERROR%
::echo Command finished for %FILE7% with f 100 10

::echo Running command: %COMPILER% %PARAM% %FILE7%.%EXTENSION% a 100 10
::%COMPILER% %PARAM% %FILE7%.%EXTENSION% a 100 10 > %FILE7%-%ASSIGNMENT%-a-100-10.%OUTPUT% 2> %FILE7%-%ASSIGNMENT%-a-100-10.%ERROR%
::echo Command finished for %FILE7% with a 100 10

::echo Running command: %COMPILER% %PARAM% %FILE7%.%EXTENSION% m 100 10
::%COMPILER% %PARAM% %FILE7%.%EXTENSION% m 100 10 > %FILE7%-%ASSIGNMENT%-m-100-10.%OUTPUT% 2> %FILE7%-%ASSIGNMENT%-m-100-10.%ERROR%
::echo Command finished for %FILE7% with m 100 10

:: SHOW OUTPUTS - - - - - - - - - - - - - - - - - - - - - - - - - - -
DIR %FILE_PATH%\*.OUT
DIR %FILE_PATH%\*.ERR

:: ---------------------------------------------------------------------
:: End of Tests (A12 - S24) --------------------------------------------
:: ---------------------------------------------------------------------
pause
