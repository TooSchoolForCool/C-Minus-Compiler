/*********************************************************************
 * MODULE: globals.h
 * PURPOSE: Most of the global variables are declared here.
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-04-14
 *********************************************************************/

#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>

/********************************************************************
 * In file main.cpp
 ********************************************************************/

typedef enum _CompilerMode
{
	LEX_ANALYSIS
}CompilerMode;

// read in source file path
extern std::string src_file_path;

// output target file path
extern std::string dst_file_path;

/**
 * Trace all destructors, check if all alloced memory are released
 * This variable will be used in every class destructor
 */
extern bool TraceDestructor;

/**
 * Trace Token Scanner
 * This variable will be used in `getToken()` in file 'lexer.cpp'
 */
extern bool TraceToken;

#endif	// GLOBALS_H