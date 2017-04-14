/*********************************************************************
 * MODULE: token.cpp
 * PURPOSE: Implement functions in token.h
 * AUTHER: Zeyu Zhang
 * DATE STARTED:  2017-04-13
 *********************************************************************/

#include "token.h"

#include <iostream>

using namespace std;

string TokenName[] = {
	// Reserved words
	"ELSE", "IF", "INT", "FLOAT", "RETURN", "VOID", "WHILE",

	// Some more complex token type
	"ID", "INT_NUMBER", "REAL_NUMBER", 

	// Some basic operators
	"PLUS", "MINUS", "TIMES", "DIVIDE", "LT", "LTE", "GT", "GTE", "EQ",
	"NEQ", "ASSIGN", "SEMI", "COMMA", "LPAREN", "RPAREN", "LSQUAREBRA",
	"RSQUAREBRA", "LBRACE", "RBRACE"
};

/**
 * Token
 */
Token::~Token()
{
	// nop
}

TokenType Token::getTokenType()
{
	return token_type_;
}

int Token::getLineNumber()
{
	return line_number_;
}

/**
 * Integer
 */
Integer::Integer(TokenType token_type, string token_string, int line_number)
{
	token_type_ = token_type;
	line_number_ = line_number;

	int tmp = 0;
	for(int i = 0; i < token_string.length(); i++)
	{
		tmp = tmp * 10 + token_string[i] - '0';
	}
	
	token_value_ = tmp;
}

Integer::~Integer()
{
	printf("Free Integer Token:\tline %d\t%-15s\t%d\n", line_number_,
		TokenName[token_type_].c_str(), token_value_);
}

int Integer::getValue()
{
	return token_value_;
}

/**
 * RealNumber
 */
RealNumber::RealNumber(TokenType token_type, std::string token_string, int line_number)
{
	token_type_ = token_type;
	line_number_ = line_number;

	double tmp = 0.0;
	double scaler = 10.0;
	int i = 0;
	
	for(i = 0; i < token_string.length(); i++)
	{
		if(token_string[i] == '.')
			break;
		tmp = tmp * 10 + token_string[i] - '0';
	}
	for(i = i + 1; i < token_string.length(); i++)
	{
		tmp += (token_string[i] - '0') / scaler;
		scaler *= 10;
	}

	token_value_ = tmp;
}

RealNumber::~RealNumber()
{
	printf("Free RealNumber Token:\tline %d\t%-15s\t%lf\n", line_number_,
		TokenName[token_type_].c_str(), token_value_);
}

double RealNumber::getValue()
{
	return token_value_;
}


/**
 * Word
 */
Word::Word(TokenType token_type, string token_string, int line_number)
{
	token_type_ = token_type;
	token_value_ = token_string;
	line_number_ = line_number;
}

Word::~Word()
{
	printf("Free Word Token:\tline %d\t%-15s\t%s\n", line_number_,
		TokenName[token_type_].c_str(), token_value_.c_str());
}

string Word::getValue()
{
	return token_value_;
}

/**
 * Identifier
 */
Identifier::Identifier(TokenType token_type, string token_string, int line_number)
{
	token_type_ = token_type;
	line_number_ = line_number;
	token_value_ = token_string;
}

Identifier::~Identifier()
{
	printf("Free Identifier Token:\tline %d\t%-15s\t%s\n", line_number_,
		TokenName[token_type_].c_str(), token_value_.c_str());
}

string Identifier::getID()
{
	return token_value_;
}