/*********************************************************************
 * MODULE: lexer.cpp
 * PURPOSE: Implement Lexer class here
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-04-13
 *********************************************************************/

#include "lexer.h"
#include "utils.h"

using namespace std;

Lexer::Lexer(const char *file_path)
{
	file_in_.open(file_path, ios::in);

	if( !file_in_.is_open() )
	{
		char msg[512];
		sprintf(msg, "Cannot open file <%s>", file_path);
		error(msg);
	}

	getline(file_in_, cur_line_);
	cur_line_.push_back('\n');

	cur_position_ = 0;
	cur_line_len_ = cur_line_.length();
	cur_line_number_ = 1;

	is_end_of_file_ = false;
}

Lexer::~Lexer()
{
	file_in_.close();
	
	if(TraceDestructor)
	{
		cout << "[TraceDestructor] Lexer destoried, file closed." << endl;
	}
}

Token *Lexer::getToken()
{
	Token *ret = NULL;

	char ch;
	bool save_cur_char;

	LexerState state = START;
	TokenType cur_token_type;
	std::string token_buffer = "";

	while(state != OVER)
	{
		ch = _getNextChar();
		save_cur_char = true;

		switch(state)
		{
			case START:
				if(ch == ' ' || ch == '\t' || ch == '\n')
				{
					state = START;
					save_cur_char = false;
				}
				else if(ch == '_' || isalpha(ch))
				{
					state = IN_LETTER;
				}
				else if( isdigit(ch) )
				{
					state = IN_INT;
				}
				else if(ch == '!')
				{
					state = IN_NEQ;
				}
				else if(ch == '/')
				{
					state = IN_DIV;
					save_cur_char = false;
				}
				else if(ch == '<')
				{
					state = IN_LT;
				}
				else if(ch == '>')
				{
					state = IN_GT;
				}
				else if(ch == '=')
				{
					state = IN_EQ;
				}
				else if(ch == EOF)
				{
					state = OVER;
					return NULL;
				}
				else
				{
					state = OVER;

					if(ch == '+')
					{
						cur_token_type = PLUS;
					}
					else if(ch == '-')
					{
						cur_token_type = MINUS;
					}
					else if(ch == '*')
					{
						cur_token_type = TIMES;
					}
					else if(ch == ';')
					{
						cur_token_type = SEMI;
					}
					else if(ch == ',')
					{
						cur_token_type = COMMA;
					}
					else if(ch == '(')
					{
						cur_token_type = LPAREN;
					}
					else if(ch == ')')
					{
						cur_token_type = RPAREN;
					}
					else if(ch == '[')
					{
						cur_token_type = LSQUAREBRA;
					}
					else if(ch == ']')
					{
						cur_token_type = RSQUAREBRA;
					}
					else if(ch == '{')
					{
						cur_token_type = LBRACE;
					}
					else if(ch == '}')
					{
						cur_token_type = RBRACE;
					}
					else
					{
						char msg[512];
						sprintf(msg, "line %d: Unknown Lexeme <%c>", cur_line_number_, ch);
						error(msg);
					}
				}
				break;	// Break for START state
			case IN_LETTER:
				if(ch == '_' || isalpha(ch) || isdigit(ch))
				{
					state = IN_LETTER;
				}
				else
				{
					_backwardCurPosition();
					save_cur_char = false;
					state = OVER;
					cur_token_type = ID;
				}
				break;
			case IN_INT:
				if( isdigit(ch) )
				{
					state = IN_INT;
				}
				else if(ch == '.')
				{
					state = IN_FLOAT;
				}
				else
				{
					_backwardCurPosition();
					save_cur_char = false;
					state = OVER;
					cur_token_type = INT_NUMBER;
				}
				break;
			case IN_FLOAT:
				if( isdigit(ch) )
				{
					state = IN_FLOAT;
				}
				else
				{
					_backwardCurPosition();
					save_cur_char = false;
					state = OVER;
					cur_token_type = REAL_NUMBER;
				}
				break;
			case IN_NEQ:
				if(ch == '=')
				{
					state = OVER;
					cur_token_type = NEQ;
				}
				else
				{
					char msg[512];
					sprintf(msg, "line %d: Unknown Lexeme <!%c>", cur_line_number_, ch);
					error(msg);
				}
				break;
			case IN_DIV:
				if(ch == '*')
				{
					state = IN_COMMENT;
					save_cur_char = false;
				}
				else
				{
					token_buffer.push_back('/');

					_backwardCurPosition();
					save_cur_char = false;
					state = OVER;
					cur_token_type = DIVIDE;
				}
				break;
			case IN_LT:
				state = OVER;

				if(ch == '=')
				{
					cur_token_type = LTE;					
				}
				else
				{
					_backwardCurPosition();
					save_cur_char = false;
					cur_token_type = LT;
				}
				break;
			case IN_GT:
				state = OVER;

				if(ch == '=')
				{
					cur_token_type = GTE;					
				}
				else
				{
					_backwardCurPosition();
					save_cur_char = false;
					cur_token_type = GT;
				}
				break;
			case IN_EQ:
				state = OVER;

				if(ch == '=')
				{
					cur_token_type = EQ;					
				}
				else
				{
					_backwardCurPosition();
					save_cur_char = false;
					cur_token_type = ASSIGN;
				}
				break;
			case IN_COMMENT:
				save_cur_char = false;
				if(ch == '*')
				{
					state = IN_COMMENT_END;
				}
				else if(ch == EOF)
				{
					state = OVER;
					error("Expecting end of comment <*/>");
				}
				break;
			case IN_COMMENT_END:
				save_cur_char = false;
				if(ch == '/')
				{
					state = START;
				}
				else if(ch == '*')
				{
					state = IN_COMMENT_END;
				}
				else if(ch == EOF)
				{
					state = OVER;
					error("Expecting end of comment </>");
				}
				break;
			default:
				char msg[512];
				sprintf(msg, "Unexpected error in lexer.cpp getToken(): previous state: %d, current char: %c", state, ch);
				error(msg);
				break;
		}	// END of state switch structure

		if(save_cur_char)
			token_buffer.push_back(ch);
	}	// End of while(state != OVER)

	if(cur_token_type == REAL_NUMBER)
	{
		ret = new RealNumber(REAL_NUMBER, token_buffer, cur_line_number_);
	}
	else if(cur_token_type == INT_NUMBER)
	{
		ret = new Integer(INT_NUMBER, token_buffer, cur_line_number_);
	}
	else if(cur_token_type == ID)
	{
		if(token_buffer == "else")
		{
			ret = new Word(ELSE, token_buffer,cur_line_number_);
		}
		else if(token_buffer == "if")
		{
			ret = new Word(IF, token_buffer, cur_line_number_);
		}
		else if(token_buffer == "int")
		{
			ret = new Word(INT, token_buffer, cur_line_number_);
		}
		else if(token_buffer == "float")
		{
			ret = new Word(FLOAT, token_buffer, cur_line_number_);
		}
		else if(token_buffer == "return")
		{
			ret = new Word(RETURN, token_buffer, cur_line_number_);
		}
		else if(token_buffer == "void")
		{
			ret = new Word(VOID, token_buffer, cur_line_number_);
		}
		else if(token_buffer == "while")
		{
			ret = new Word(WHILE, token_buffer, cur_line_number_);
		}
		else
		{
			ret = new Identifier(ID, token_buffer, cur_line_number_);
		}
	}
	else
	{
		ret = new Word(cur_token_type, token_buffer, cur_line_number_);
	}

	if(TraceToken)
	{
		printf("[TraceToken] line %-6d\t%-16s%s\n", cur_line_number_,
			TokenName[cur_token_type].c_str(), token_buffer.c_str());
	}

	return ret;
}

char Lexer::_getNextChar()
{
	// Reach END of current line
	while(cur_position_ >= cur_line_len_)
	{	
		// Reach END of this file
		if( !getline(file_in_, cur_line_) )
		{
			is_end_of_file_ = true;
			return EOF;
		}
		cur_line_.push_back('\n');

		cur_position_ = 0;
		cur_line_len_ = cur_line_.length();
		cur_line_number_++;
	}

	return cur_line_[cur_position_++];
}

void Lexer::_backwardCurPosition()
{
	cur_position_--;
}