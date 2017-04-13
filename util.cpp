/*********************************************************************
 * MODULE: util.cpp
 * PURPOSE: Implement functions defined in util.h
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-04-14
 *********************************************************************/

#include "util.h"

using namespace std;

void printToken(Token *token)
{
	TokenType token_type = token->getTokenType();
	
	Integer *integer_token = (Integer *)token;
	RealNumber *real_number_token = (RealNumber *)token;
	// Word *word_token = (Word *)token;
	Identifier *id_token = (Identifier *)token;

	printf("line %d\t%-15s\t", token->getLineNumber(), TokenName[token_type].c_str());

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
			printf("-\n");
			break;
	}
}