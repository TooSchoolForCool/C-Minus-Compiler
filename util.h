/*********************************************************************
 * MODULE: util.h
 * PURPOSE: Some utility functions are implemented here
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-04-13
 *********************************************************************/

#ifndef UTIL_H
#define UTIL_H

#include "token.h"

#include <iostream>
#include <vector>

#include <stdio.h>

void printToken(Token *token);
void printTokens(std::vector<Token *> &src);
void freeTokens(std::vector<Token *> &src);

#endif	// UTIL_H
