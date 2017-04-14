/*********************************************************************
 * MODULE: lexer.h
 * PURPOSE: Define Lexer Class here
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-04-13
 *********************************************************************/

#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include "globals.h"
#include "error.h"

#include <iostream>
#include <fstream>
#include <string>

#include <stdio.h>
#include <ctype.h>

typedef enum _LexerState
{
	START,
	IN_LETTER,
	IN_INT,
	IN_FLOAT,
	IN_DIV,
	IN_LT,
	IN_GT,
	IN_EQ,
	IN_NEQ,
	IN_COMMENT,
	IN_COMMENT_END,
	OVER
}LexerState;

class Lexer
{
public:
	Lexer(const char *file_path);
	~Lexer();
	Token *getToken();
	char _getNextChar();
	void _backwardCurPosition();

private:
	
private:
	std::ifstream file_in_;

	std::string cur_line_;
	int cur_position_;
	int cur_line_len_;
	int cur_line_number_;

	bool is_end_of_file_;
};

#endif	// LEXER_H