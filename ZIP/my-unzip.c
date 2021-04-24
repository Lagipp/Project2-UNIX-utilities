/*****************************************************************/
/* KÄYTTÖJÄRJESTELMÄT JA SYSTEEMIOHJELMOINTI
 * Project 2:			UNIX utilities
 * Nimi ja opiskelijanro:	Miika Pynttäri, 0563090
 * Päivämäärä:			20.4.2021
 * Yhteistyö ja lähteet:	
 * 
 * - https://www.codeproject.com/Questions/771736/decompress-file-using-rle-cplusplus
 * - https://www.programmingalgorithms.com/algorithm/rle-decompress/c/
 * - https://www.cefns.nau.edu/~pek7/CS200/Project%203.pdf
 *
 *  (all sources were mainly glanced over while trying to emulate their core concepts into this code)
*/
/*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64


int main(int argc, char* argv[])
{
	FILE *file;
	char input[MAX];
	char chr[10];
	int integer;
	int x;
	int t;

	if (argc < 2 || argc > 2)
	{
		fprintf(stdout, "INCORRECT USAGE, try: ./my-unzip <file>\n\n");
		exit(1);
	}
	
	strcpy(input, argv[1]);
	
	file = fopen(argv[1], "r");
	if(file == NULL) {
		fprintf(stdout, "error: cannot open file '%s'\n\n", input);
		exit(1);
	}


	while ((x = fscanf(file, "%d%c", &integer, chr)) != EOF)	/* getting the desired syntax, "int char", e.g. "2a" "3b" */
	{	
		if (x != 2)		/* if the syntax is not correct */
		{
			fprintf(stdout, "ERROR: input doesnt follow the proper syntax... \n\n");
			exit(1);
		}		
		
		for (t = 0; t < integer; t++) 	/* printing the characters of the RLE as many times */
		{					/* as the integer in front of them, e.g. "3e" -> "eee" */
			printf("%s", chr);
		
		}	
	} 	
	fclose(file);
	fprintf(stdout, "\n");

	return 0;
}



