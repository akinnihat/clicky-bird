@echo off
cls

echo Compiling project...
g++ -o ClickyBird.exe -Iinclude src/*.cpp -lraylib -lgdi32 -lwinmm -mwindows

if %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    pause
    exit /b %ERRORLEVEL%
)

echo Build completed successfully!
pause
