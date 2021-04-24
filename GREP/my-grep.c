/*****************************************************************/
/* KÄYTTÖJÄRJESTELMÄT JA SYSTEEMIOHJELMOINTI
 * Project 2:			UNIX utilities
 * Nimi ja opiskelijanro:	Miika Pynttäri, 0563090
 * Päivämäärä:			20.4.2021
 * Yhteistyö ja lähteet:	
 *
 * - https://stackoverflow.com/questions/17504122/taking-a-string-as-input-and-storing-them-in-a-character-array-in-c/17504265
 * - https://stackoverflow.com/questions/7251307/using-strcpy-with-a-string-array-in-c
 * - https://www.codeproject.com/Questions/5268549/How-do-I-make-a-programme-in-C-which-mimic-the-gre
 *
*/
/*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 512



int main(int argc, char* argv[])
{
	char buffer[MAX];
	FILE *file;
	int count;
	int m;
	char filename[MAX];
	char searchterm[MAX];
	
	
	if (argc < 2)
	{
	/* when only the command is typed? */ 
	
	
		fprintf(stdout, "INCORRECT USAGE, try: ./my-grep <searchterm> <file1>, <file2>, ...\n");
		exit(1);
	}
	
	
	if (argc == 2)
	{
	/* when no files are given, just the searchterm --> take words from user (read from stdin) */
	
	
		/* user input into a char-array found from: 
		   https://stackoverflow.com/questions/17504122/taking-a-string-as-input-and-storing-them-in-a-character-array-in-c/17504265 */
	
	
		char *line = NULL;
		size_t len;
		char array[MAX][MAX];		/* https://stackoverflow.com/questions/7251307/using-strcpy-with-a-string-array-in-c */
						/* for some reason the array needs double brackets, idk why but it works */
						/* (i had some problems but they were solved with the link above) */
		int u;
		
		strcpy(searchterm, argv[1]);
		
		
		fprintf(stdout, "Give some inputs, type 'STOP' to stop\n\n");
		
		count = 0;						/* resetting the value of count */
		
		while(getline(&line, &len, stdin) != -1)
		{
			if (strcmp(line, "STOP\n") == 0)		/* if user types STOP, don't take any more inputs */
			{
				break;
			}
		
			if (strstr(line, searchterm) != NULL)		/* if user typed something containing the searchterm, */
			{					   	/* add it to the array */
				strcpy(array[m], line);
				count++;				/* keeping count how many words were found */
			}
			m++;
		}
		
		free(line);
		
		
		/* PRINTING OUT THE FOUND WORDS */
		
		fprintf(stdout, "\n--- Printing out words with '%s' in them from stdin:\n", searchterm);
		
		for(u = 0; u < m; u++)
		{
			fprintf(stdout, "%s", array[u]);
		}
		
		printf("--- Found %d occurrences!\n\n", count);
		return 0;
	}
	
	
	if (argc > 2)
	{
	
	/* when the searchterm and file(s) have been supplied */
	
	
	/* expanded from the following source: https://www.codeproject.com/Questions/5268549/How-do-I-make-a-programme-in-C-which-mimic-the-gre */
	
	
		for (m = 2; m < argc; m++)		/* looping through until all files are printed */
		{
			count = 0;				/* resetting the value of count */
			
			strcpy(filename, argv[m]);
			strcpy(searchterm, argv[1]);
			
			file = fopen(argv[m], "r");
			if (file == NULL)			/* if the file doesn't exist (or something odd happens for some reason), stop */
			{
				fprintf(stdout, "error: cannot open file '%s'\n", filename);
				exit(1);
			}
			
			
			/* PRINTING OUT THE FOUND WORDS */
			
			fprintf(stdout, "--- Printing out words with '%s' in them from file '%s':\n", searchterm, filename);
			
			while (fgets(buffer, MAX, file))
			{
				if (strstr(buffer, argv[1]))		/* if the searchterm is found within a word, the word gets printed */
				{
					printf("%s", buffer);
					count++;			/* keeping count how many words were found */
				}
			}
		
			fclose(file);
			printf("--- Found %d occurrences!\n\n", count);	/* this line was just for debugging, but */
										/* I kept it in since it's kind of cool */
		}
	}
	return 0;
}
