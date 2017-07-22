#ifndef __WORD_COUNT_H__
#define __WORD_COUNT_H__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
Programme to open and read a file, run through the text and count the frequency of the words, and then to print the words with the number of times they show up.

Leore Golan

15-02-2017
*/

typedef enum
{
	CANNOT_OPEN_FILE,
	CANNOT_CLOSE_FILE,
	MEMORY_ERROR,
	OK,
} err_code;

typedef struct
{
	char word[40];
	int frequency;
} wordCount_t;

/* find the frequency of each word in a text file */
err_code wordCount(char* sourceFile, char* destinationFile);


 #endif /* __WORD_COUNT_H__ */
