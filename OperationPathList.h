#pragma once

#include "Operation.h"

class OperationPathList : public Operation
{
private:

	// statics used by command registration utility
	static std::wstring GetCommand() { return L"PathList"; }
	static ClassFactory<OperationPathList> * RegisteredFactory;

public:

	// constructors
	OperationPathList(std::queue<std::wstring> & oArgList);
};