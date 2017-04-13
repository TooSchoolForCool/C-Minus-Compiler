/*********************************************************************
 * MODULE: token.h
 * PURPOSE: Define TOKEN type here, and related operations.
 * AUTHER: Zeyu Zhang
 * DATE STARTED:  2017-04-13
 *********************************************************************/

#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

// Define token type
typedef enum _TokenType
{
	// Reserved Words
	ELSE, IF, INT, RETURN, VOID, WHILE,

	// Some more complex token type
	ID, NUMBER,

	// Some basic operators
	PLUS, MINUS, TIMES, DIVIDE, LT, LTE, GT, GTE, EQ,
	NEQ, ASSIGN, SEMI, COMMA, LPAREN, RPAREN, LSQUAREBRA,
	RSQUAREBRA, LBRACE, RBRACE
}TokenType;

extern string TokenName[];

class Token
{
public:
	virtual ~Token();
	TokenType getTokenType();
	int getLineNumber();

protected:
	TokenType token_type_;

	// for debugging and reporting errors
	int line_number_;
};

class Number: public Token
{
public:
	Number(TokenType token_type, int token_value, int line_number);
	~Number();
	int getValue();

private:
	int token_value_;
};

class Word: public Token
{
public:
	Word(TokenType token_type, int line_number);
	~Word();
};

class Identifier: public Token
{
public:
	Identifier(TokenType token_type, std::string token_value, int line_number);
	~Identifier();
	std::string getID();

private:
	std::string token_value_;
};

#endif	// TOKEN_H