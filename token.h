/*********************************************************************
 * MODULE: token.h
 * PURPOSE: Define TOKEN type here, and related operations.
 * AUTHER: Zeyu Zhang
 * DATE STARTED:  2017-04-13
 *********************************************************************/

#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

#include <stdio.h>

// Define token type
typedef enum _TokenType
{
	// Reserved Words
	ELSE, IF, INT, FLOAT, RETURN, VOID, WHILE,

	// Some more complex token type
	ID, INT_NUMBER, REAL_NUMBER,

	// Some basic operators
	PLUS, MINUS, TIMES, DIVIDE, LT, LTE, GT, GTE, EQ,
	NEQ, ASSIGN, SEMI, COMMA, LPAREN, RPAREN, LSQUAREBRA,
	RSQUAREBRA, LBRACE, RBRACE
}TokenType;

// extern variable in file token.cpp
extern std::string TokenName[];

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

class Integer: public Token
{
public:
	Integer(TokenType token_type, std::string token_string, int line_number);
	~Integer();
	int getValue();

private:
	int token_value_;
};

class RealNumber: public Token
{
public:
	RealNumber(TokenType token_type, std::string token_string, int line_number);
	~RealNumber();
	double getValue();

private:
	double token_value_;
};

class Word: public Token
{
public:
	Word(TokenType token_type, std::string token_string, int line_number);
	~Word();
	std::string getValue();

private:
	std::string token_value_;
};

class Identifier: public Token
{
public:
	Identifier(TokenType token_type, std::string token_string, int line_number);
	~Identifier();
	std::string getID();

private:
	std::string token_value_;
};

#endif	// TOKEN_H