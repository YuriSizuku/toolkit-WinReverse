msbuild %~dp0\libwinversion.sln -t:libwinversion:rebuild -p:configuration=release -p:Platform=x86 
msbuild %~dp0\libwinversion.sln -t:libwinversion:rebuild -p:configuration=release -p:Platform=x64