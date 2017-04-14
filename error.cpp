/*********************************************************************
 * MODULE: error.cpp
 * PURPOSE: Implement error reporting functions defined in error.h
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-04-14
 *********************************************************************/

#include "error.h"

using namespace std;

void error(const char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

void error(string msg)
{
	cerr << msg << ": " << strerror(errno) << endl;
	exit(1);
}
