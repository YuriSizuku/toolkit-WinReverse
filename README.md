# Toolkit Win Reverse

![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/yurisizuku/toolkit-WinReverse?color=green&label=WinReverse)![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/YuriSizuku/toolkit-WinReverse/build.yml?label=build)  

🍀 Libraries (mostly use single header file) for my reverse projects.  
Scripts for localization are moved to [Toolkit Localization](https://github.com/YuriSizuku/toolkit-Localization).  
`winloader` and `libwinversion` are moved to [Override](https://github.com/YuriSizuku/win-Override)

Projects based on this repo:  

- [Override](https://github.com/YuriSizuku/win-Override)  
- [MemoryModule](https://github.com/YuriSizuku/win-MemoryModule)  
- [MemoryVFS](https://github.com/YuriSizuku/win-MemoryVFS)
- [GalgameReverse](https://github.com/YuriSizuku/GalgameReverse)  

## Components

### cross platform libraries  

- `windllin.py`, staticly inject `dll` to a `exe`  
- `wincoff.py`, method for parsing `coff` object file  

### windows platform libraries

In `project`,  `Makefile` for `gcc` (llvm-mingw or mingw-w64), `tcc` (not support inline) and `sln` for `msvc`.  All of them are compatible for `win xp` and above.  

- `windyn.h`, single header file for windows dynamic binding system api without IAT
- `winhook.h`,  single header file for windows dynamic hook and memory util functions
- `winpe.h`, single header file for windows pe structure, adjusting realoc addrs, or iat
- `winversion.h`, single header file for windows `version.dll` proxy to patch.dll, see [Release](https://github.com/YuriSizuku/toolkit-Override)
