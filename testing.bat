@echo off
cd build*
cd Desktop*
set PATH=%PATH%;C:\Qt\6.10.2\mingw_64\bin
.\UnitTests.exe
pause