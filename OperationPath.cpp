#include "OperationPath.h"
#include "InputOutput.h"
#include "Functions.h"

ClassFactory<OperationPath> * OperationPath::RegisteredFactory =
	new ClassFactory<OperationPath>(GetCommand());

OperationPath::OperationPath(std::queue<std::wstring> & oArgList) : Operation(oArgList)
{
	// exit if there are not enough arguments to part
	std::vector<std::wstring> sSubArgs = ProcessAndCheckArgs(1, oArgList, L"\\0");

	// verify this parameter has only be specified once
	if (InputOutput::BasePath().size() > 0)
	{
		wprintf(L"%s\n", L"ERROR: Path can only be specified once.");
		exit(-1);
	}

	// store off the argument
	InputOutput::BasePath() = sSubArgs[0];
};