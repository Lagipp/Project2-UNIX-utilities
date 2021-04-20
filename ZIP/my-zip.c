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
	
	

	fprintf(stdout, "== DEBUG: end of program\n\n");
}

