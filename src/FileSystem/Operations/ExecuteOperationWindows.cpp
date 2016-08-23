
#ifdef WIN32

#include "ExecuteOperation.h"

#include "FileSystem/Path.h"

#include <windows.h>
#include <atlstr.h>

using file_system::operations::ExecuteOperation;
using file_system::Path;

void ExecuteOperation::execute(const Path& path)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	CString pathString(path.stringValue().c_str());

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
		path.getParent().stringValue().c_str(), // TODO: need to put the folder path of the exe to work with some game
		&si,
		&pi);

	// Wait until child process exits.
	WaitForSingleObject(pi.hProcess, INFINITE);

	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

#endif