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
