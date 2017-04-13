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
	"ELSE", "IF", "INT", "RETURN", "VOID", "WHILE",

	// Some more complex token type
	"ID", "NUMBER",

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
 * Number
 */
Number::Number(TokenType token_type, int token_value, int line_number)
{
	token_type_ = token_type;
	token_value_ = token_value;
	line_number_ = line_number;
}

Number::~Number()
{
	// nop
}

int Number::getValue()
{
	return token_value_;
}

/**
 * Word
 */
Word::Word(TokenType token_type, int line_number)
{
	token_type_ = token_type;
	line_number_ = line_number;
}

Word::~Word()
{
	// nop
}

/**
 * Identifier
 */
Identifier::Identifier(TokenType token_type, string token_value, int line_number)
{
	token_type_ = token_type;
	line_number_ = line_number;
	token_value_ = token_value;
}

Identifier::~Identifier()
{
	// nop
}

string Identifier::getID()
{
	return token_value_;
}