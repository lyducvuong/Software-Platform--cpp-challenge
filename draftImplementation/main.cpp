#include <thread>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include "word_parser.h"

int main ()
{
	Parser parser = Parser();
	try
	{
		parser.wordsParsing();
	}
	catch (const std::exception&)
	{
		throw;
		return 0;
	}
	
	
}