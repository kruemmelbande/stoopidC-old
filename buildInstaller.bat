@echo off
echo Building...
pip install pyinstaller > NUL 
pyinstaller --noconfirm --onefile --windowed --icon "./icon.ico" --add-data "./build/stoopid.exe;." --add-data "./icon.ico;."  "./install.py">NUL
move dist\install.exe install.exe>NUL
del dist /F /Q /S>NUL
del .\build\install /F /Q /S>NUL
rmdir dist>NUL
rmdir .\build\install /S /Q>NUL
del install.spec>NUL
echo Build done!
