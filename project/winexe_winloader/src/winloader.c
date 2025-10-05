#include <windows.h>
#define WINHOOK_IMPLEMENTATION
#include "winhook.h"

#ifndef _DEBUG
//#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")
#endif

int main(int argc, char *argv[])
{
	char exepath[MAX_PATH] = {0};
	char dllpath[MAX_PATH] = {0};
	char* cmdstr = NULL;

	printf("winloader v0.1.1, developed by devseed\n"
		"usage:\n"
		"winloader // if the name is xxx_yyy.exe, start xxx.exe\n"
		"winloader exepath, cmdstr // will be null, dll has the same name as exe\n"
		"winloader exepath dllpath\n"
		"winloader exepath dllpath cmdstr\n\n"
	);

	switch (argc)
	{
	case 1:
	{
		int end = (int)(strstr(argv[0], ".exe") - argv[0]);
		while (end > 0 && argv[0][end] != '_') end--;
		printf("%d\n", end);
		strncpy(exepath, argv[0], end);
		exepath[end] = '\0';
		strcat(exepath, ".exe");
		strcpy(dllpath, exepath);
		strcpy(dllpath + strlen(dllpath) - 4, ".dll");
		break;
	}
	case 2:
	{
		strcpy(exepath, argv[1]);
		strcpy(dllpath, exepath);
		strcpy(dllpath + strlen(dllpath) - 4, ".dll");
		break;
	}
	case 3:
	{
		strcpy(exepath, argv[1]);
		strcpy(dllpath, argv[2]);
		break;
	}
	case 4:
	{
		strcpy(exepath, argv[1]);
		strcpy(dllpath, argv[2]);
		cmdstr = argv[3];
		break;
	}
	default:
		printf("error too many args!\n");
		return -1;
	}
	printf("start exepath=%s, cmdstr=%s, dllpath=%s\n", exepath, cmdstr, dllpath);
	DWORD pid = winhook_startexeinject(exepath, cmdstr, dllpath);
	if (pid)
	{
		printf("start successed, pid=%d\n", (int)pid);
		return 0;
	}
	else
	{
		printf("start failed!\n");
		return -1;
	}
}