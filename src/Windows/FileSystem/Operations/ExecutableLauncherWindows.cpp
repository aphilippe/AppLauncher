#include "ExecutableLauncherWindows.h"
#include <windows.h>
#include <atlstr.h>

using namespace clt::filesystem;
using namespace clt::filesystem::operations;

ExecutableLauncherWindows::ExecutableLauncherWindows()
{
}


ExecutableLauncherWindows::~ExecutableLauncherWindows()
{
}

void 
ExecutableLauncherWindows::execute(const entities::Path & executable)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	CString pathString(executable.getValue().c_str());

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	CreateProcess(
		NULL,
		pathString.GetBuffer(),
		NULL,
		NULL,
		false,
		0,
		NULL,
		executable.getParent().getValue().c_str(), // TODO: need to put the folder path of the exeto work with some game
		&si,
		&pi);

	// Wait until child process exits.
	WaitForSingleObject(pi.hProcess, INFINITE);

	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}