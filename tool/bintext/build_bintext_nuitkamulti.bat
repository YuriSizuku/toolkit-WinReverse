:: build not stand alone file
nuitka --onefile --full-compat --show-progress "%~dp0\..\..\script\bintext.py" --windows-icon-from-ico="%~dp0\..\..\asset\default.ico" --output-dir="%~dp0\bin\multi" -o "%~dp0\bin\multi\cbintext.exe" --assume-yes-for-downloads