/*********************************************************************
 * MODULE: util.h
 * PURPOSE: Some utility functions are implemented here
 *			Functions in this file will be used in main.cpp
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-04-13
 *********************************************************************/

#ifndef UTIL_H
#define UTIL_H

#include "token.h"
#include "lexer.h"
#include "globals.h"
#include "error.h"

#include <iostream>
#include <vector>

#include <stdio.h>
#include <getopt.h>
#include <string.h>

void printToken(FILE *out, Token *token);
void freeTokens(std::vector<Token *> &src);
void parseArgs(int argc, char **argv);
void usage();

void LexicalAnalysis(const char *src, const char *dst);

#endif	// UTIL_H
