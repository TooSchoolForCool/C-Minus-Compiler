/*********************************************************************
 * MODULE: error.h
 * PURPOSE: Some error reporting functions are defined here.
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-04-13
 *********************************************************************/

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void error(std::string msg);
void error(const char *msg);