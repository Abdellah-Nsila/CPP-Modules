#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <cfloat>
#include <cerrno>

enum literalType
{
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

literalType	getType(std::string s);
