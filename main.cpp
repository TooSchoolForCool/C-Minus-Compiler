/*********************************************************************
 * MODULE: main.cpp
 * PURPOSE: main function laid here.
 * AUTHER: Zeyu Zhang
 * DATE STARTED:  2017-04-13
 *********************************************************************/

#include "lexer.h"
#include "utils.h"
#include "globals.h"

#include <iostream>
#include <vector>

#include <stdio.h>

using namespace std;

char src_file_path[1024] = "";
char dst_file_path[1024] = "";

bool TraceDestructor = false;
bool TraceToken = false;

CompilerMode mode = NOP;

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		usage();
		return 0;
	}

	parseArgs(argc, argv);

	switch(mode)
	{
		case NOP:
			cout << "No operation" << endl;
			break;
		case LEX_ANALYSIS:
			LexicalAnalysis(src_file_path, dst_file_path);
			cout << "Lexical Analysis is done" << endl;
			break;
		default:
			char msg[512];
			sprintf(msg, "[main.cpp main()] no such option: %d", mode);
			error(msg);
			break;
	}

	return 0;
}