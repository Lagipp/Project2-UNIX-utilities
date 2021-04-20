/*****************************************************************/
/* KÄYTTÖJÄRJESTELMÄT JA SYSTEEMIOHJELMOINTI
 * Project 2:			UNIX utilities
 * Nimi ja opiskelijanro:	Miika Pynttäri, 0563090
 * Päivämäärä:			19.4.2021
 * Yhteistyö ja lähteet:	https://www.codeproject.com/Questions/5268549/How-do-I-make-a-programme-in-C-which-mimic-the-gre
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
		fprintf(stdout, "INCORRECT USAGE, try: ./my-grep <searchterm> <file1>, <file2>, ...\n");
		exit(1);
	}
	
	if (argc == 2)
	{
		// searching from stdin
		printf("\n == DEBUG: tää ei viel toimi lol ota joku toinen ==\n");
		return 0;
	}
	
	
	if (argc > 2)
	{
	
	/* expanded from the following source: https://www.codeproject.com/Questions/5268549/How-do-I-make-a-programme-in-C-which-mimic-the-gre */
	
	
		for (m = 2; m < argc; m++)
		{
			count = 0;				/* resetting the value of count */
			
			strcpy(filename, argv[m]);		/* saving the parameters into variables for easier print messages */
			strcpy(searchterm, argv[1]);
			
			file = fopen(argv[m], "r");
			if (file == NULL)
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
					count++;
				}
			}
		
			fclose(file);
			printf("--- Found %d occurrences!\n\n", count);
			
		}
		
	}
	
	fprintf(stdout, "-- DEBUG: end of program --\n");
	return 0;
}
