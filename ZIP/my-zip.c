/*****************************************************************/
/* KÄYTTÖJÄRJESTELMÄT JA SYSTEEMIOHJELMOINTI
 * Project 2:			UNIX utilities
 * Nimi ja opiskelijanro:	Miika Pynttäri, 0563090
 * Päivämäärä:			20.4.2021
 * Yhteistyö ja lähteet:	
*/
/*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256


char* fileToArray(char input[MAX])
{
	/* source used for function: https://stackoverflow.com/questions/19173442/reading-each-line-of-file-into-array/19174415 */
	
	FILE* file = NULL;	
	
	int allocated = 128;
	int maxlength = 100;

	char **words = (char **)malloc(sizeof(char*)*allocated);
	if (words == NULL)
	{
		fprintf(stdout, "error: malloc() failed...\n\n");
		exit(1);
	}
	
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stdout, "error: couldn't open file '%s'\n\n", filename);
		exit(1);
	}
	
	int q;
	for (q = 0; ; q++)
	{
		int w;
		
		if (q >= allocated)
		{
			int new_size;
			
			new_size = allocated * 2;
			words = (char **)realloc(words, sizeof(char*) * new_size);
			
			if (words == NULL)
			{
				fprintf(stdout, "error: realloc() failed...\n\n");
				exit(1);
			}
			
			allocated = new_size;
		}
		
		words[q] = malloc(maxlength);
		if (words[q] == NULL)
		{
			fprintf(stdout, "error: malloc() failed...\n\n");
			exit(1);
		}
		
		if (fgets(words[q], maxlength-1, file) == NULL)
		{
			break;
		}
		
		
		for (w = strlen(words[q]) -1; w >= 0 && (words[q][w] == '\n' || words[q][w] == '\r'); w--)
		{
			;
		}
		
		words[q][w+1] = '\0';
		
	}
	fclose(file);
	return *words;
}



char* encode(char* source)
{
	/* source used for function: https://www.geeksforgeeks.org/run-length-encoding/ */


	int runlen;
	char count[MAX];
	int length = strlen(source);
	int a, b, c;
	
	
	char *dest = (char*)malloc(sizeof(char) * (length * 2 + 1));
	
	for (a = 0; a < length; a++)
	{		
		runlen = 1;
		while (a + 1 < length && source[a] == source[a + 1])
		{
			runlen++;
			a++;
		}
		
		sprintf(count, "%d", runlen);
		
		for (c = 0; *(count + c); c++, b++)
		{
			dest[b] = count[c];
		}
		dest[b++] = source[a];
	}

	dest[b] = '\0';
	return dest;
}


int main(int argc, char* argv[])
{
	char input[MAX];
	char output[MAX];
	FILE *file_in;
	FILE *file_out;



	if (argc <= 2)
	{
		fprintf(stdout, "INCORRECT USAGE, try: ./my-zip <file1>, (<file2>, <file3>, ...) <output>\n\n");
		exit(1);
	}

	
	strcpy(output, argv[argc-1]);		/* copying the last argument to be the output-file */
	
	file_out = fopen(output, "w");
	if (file_out == NULL)
	{
		fprintf(stdout, "error: couldn't open file '%s'\n\n", output);
		exit(1);
	}
	
	
	
	

	fprintf(stdout, "== DEBUG: end of program\n\n");
}

