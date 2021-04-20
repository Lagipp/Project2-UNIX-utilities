/*****************************************************************/
/* KÄYTTÖJÄRJESTELMÄT JA SYSTEEMIOHJELMOINTI
 * Project 2:			UNIX utilities
 * Nimi ja opiskelijanro:	Miika Pynttäri, 0563090
 * Päivämäärä:			19.4.2021
 * Yhteistyö ja lähteet:	 
*/
/*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128


int main(int argc, char* argv[])
{

	FILE* file;
	char chr;
	int q;
	char filename[MAX];


	if (argc == 1)
	{
		fprintf(stdout, "No files specified, exiting program...\n\n");
		exit(0);
	}
	
	
	for ( (q = 1); (q < argc); q++ )
	{
	
		/* expanded from the source:  https://gist.github.com/pat36/d991eda0c270ed823a5d83c274c6157c */
	
		strcpy(filename, argv[q]);
			
		file = fopen(argv[q], "r");
		if (file == NULL)
		{
			fprintf(stdout, "\nmy-cat: cannot open file '%s'\n", filename);
			exit(1);
		}

		fprintf(stdout, "--- Printing out the contents of file '%s': \n", filename);
		
		
		while((chr = getc(file)) != EOF)		/* going through the file one char at a time */
		{
			printf("%c", chr);			/* printing out the file one character at a time */
		}
		
		fclose(file);
		
		fprintf(stdout, "--- EOF for file '%s'\n", filename);
	}

	return 0;
}
