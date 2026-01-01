#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <math.h>
#include <limits>

enum literalType
{
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

literalType	getType(std::string s);
void		castToTypes(std::string s);
