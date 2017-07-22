#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "word_count.h"

err_code wordCount(char* sourceFile, char* destinationFile)
{
	FILE* fp, fp_dest;
	char string[100];
	char word[40];
	wordCount_t* freq;
	int i;

	freq = (wordCount_t*) calloc(1024, sizeof(wordCount_t));
	if (NULL == freq)
	{
		return MEMORY_ERROR;
	}

	fp = fopen(sourceFile,"r");
	if(NULL == fp)
	{
		return CANNOT_OPEN_FILE;
	}
	while (fscanf(fp, " %s", word) !=EOF)
	{
		for(i = 0; freq[i].word[0] > 0; ++i)
		{
			if (0 == strcmp(word, freq[i].word))
			{
				++freq[i].frequency;
				break;
			}
		}
		if(0 == freq[i].word[0])
		{
			strcpy(freq[i].word, word);
			++freq[i].frequency;
		}
	}
	fclose(fp);

	fp_dest = *fopen(destinationFile, "w");
	for(i = 0; *freq[i].word != '\0' && i < 1024; ++i)
	{
		fprintf(fp, "%s: %d\n", freq[i].word, freq[i].frequency);
	}

	fclose(fp);
	free(freq);
	freq = NULL;
	return OK;
}
