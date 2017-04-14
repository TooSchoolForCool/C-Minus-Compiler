/*********************************************************************
 * MODULE: util.cpp
 * PURPOSE: Implement functions defined in util.h
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-04-14
 *********************************************************************/

#include "util.h"

using namespace std;

/**
 * Command Line Arguments define here
 */
#define HELP 				'h'
#define LEX 				'l'
#define OBJ					'o'
#define TRACE_DESTRUCTOR	1001
#define TRACE_TOKEN			1002

char short_opts[] = "hl:o:";
static struct option long_opts[] = {
	{"help", no_argument, NULL, HELP},
	{"TraceDestructor", no_argument, NULL, TRACE_DESTRUCTOR},
	{"TraceToken", no_argument, NULL, TRACE_TOKEN}
};

void printToken(Token *token)
{
	TokenType token_type = token->getTokenType();
	
	Integer *integer_token = (Integer *)token;
	RealNumber *real_number_token = (RealNumber *)token;
	// Word *word_token = (Word *)token;
	Identifier *id_token = (Identifier *)token;

	printf("line %-6d\t%-20s", token->getLineNumber(), TokenName[token_type].c_str());

	switch(token_type)
	{
		case ID:
			printf("%s\n", id_token->getID().c_str());
			break;
		case INT_NUMBER:
			printf("%d\n", integer_token->getValue());
			break;
		case REAL_NUMBER:
			printf("%lf\n", real_number_token->getValue());
			break;
		default:
			printf("%s\n", id_token->getID().c_str());
			break;
	}
}

void printTokens(vector<Token *> &src)
{
	for(vector<Token *>::iterator iter = src.begin();
		iter != src.end(); iter++)
	{
		printToken(*iter);
	}
}

void freeTokens(vector<Token *> &src)
{
	for(vector<Token *>::iterator iter = src.begin();
		iter != src.end(); iter++)
	{
		delete *iter;
	}
}

void parseArgs(int argc, char **argv)
{
	int opt;
	int opt_index;

	while( (opt = getopt_long(argc, argv, short_opts, long_opts, &opt_index)) != EOF )
	{
		switch(opt)
		{
			case HELP:
				usage();
				break;
			case LEX:
				mode = LEX_ANALYSIS;
				strcpy(src_file_path, optarg);
				break;
			case OBJ:
				strcpy(dst_file_path, optarg);
				break;
			case TRACE_DESTRUCTOR:
				TraceDestructor = true;
				break;
			case TRACE_TOKEN:
				TraceToken = true;
				break;
			default:
				char msg[512];
				sprintf(msg, "[util.cpp parseArgs()] no such option '-%s'", argv[opt_index]);
				error(msg);
				break;
		}
	}
}

void usage()
{
	string out = "";

	out += "OVERVIEW: C-MINUS compiler\n\n";
	out += "USAGE: ./cc [options] <inputs>\n\n";
	out += "OPTIONS:\n";

	cout << out << endl;
	exit(0);
}

void LexicalAnalysis()
{
	cout << "lexical analysis" << endl;
}