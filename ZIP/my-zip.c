/*****************************************************************/
/* KÄYTTÖJÄRJESTELMÄT JA SYSTEEMIOHJELMOINTI
 * Project 2:			UNIX utilities
 * Nimi ja opiskelijanro:	Miika Pynttäri, 0563090
 * Päivämäärä:			20.4.2021
 * Yhteistyö ja lähteet:	
 *  
 * - https://stackoverflow.com/questions/19173442/reading-each-line-of-file-into-array/19174415
 * - https://www.geeksforgeeks.org/run-length-encoding/
 *
*/
/*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64


char* fileToArray(char input[MAX])
{
	/* function to save contents of a file into an array, as the encoding function requires an array */


	/* source used for function: https://stackoverflow.com/questions/19173442/reading-each-line-of-file-into-array/19174415 */
	
	FILE* file = NULL;	
	
	int allocated = 128;
	int maxlength = 100;

	char **words = (char **)malloc(sizeof(char*)*allocated);	/* allocating lines of text */
	if (words == NULL)
	{
		fprintf(stdout, "error: malloc() failed...\n\n");
		exit(1);
	}
	
	file = fopen(input, "r");
	if (file == NULL)
	{
		fprintf(stdout, "error: couldn't open file '%s'\n\n", input);
		exit(1);
	}
	
	int q;
	for (q = 0; 1; q++)
	{
		int w;
		
		if (q >= allocated)		/* if the allocation amount has been crossed */
		{
			int new_size;
			
			new_size = allocated * 2;
			words = (char **)realloc(words, sizeof(char*) * new_size);	/* doubling the allocation size and */
											/* reallocating */
			
			if (words == NULL)
			{
				fprintf(stdout, "error: realloc() failed...\n\n");
				exit(1);
			}
			
			allocated = new_size;		/* saving the new size as double of original */
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
		
		
		/* removing newlines */
		
		for (w = strlen(words[q]) -1; w >= 0 && (words[q][w] == '\n' || words[q][w] == '\r'); w--)
		{
			;
		}
		
		words[q][w+1] = '\0';
		
	}
	fclose(file);
	return *words;		/* returning the array */
}



char* encode(char* source)
{
	/* function to run-length-encode an array */


	/* source used for function: https://www.geeksforgeeks.org/run-length-encoding/ */


	int runlen;		// variable to keep track how many of one character there are in a row 
	char count[MAX];
	int length = strlen(source);		// length of the source string
	int a, b = 0, c;
	
	
	/* the size of the new string is at most twice the size of original */
	/* e.g. original is abc, RLE is 1a1b1c. At most double, more often less */
	
	char* dest = (char*)malloc(sizeof(char) * (length * 2 + 1));
	
	for (a = 0; a < length; a++)		/* moving along the string one-by-one */
	{		
		runlen = 1;
		while (a + 1 < length && source[a] == source[a + 1])		/* counting the number of occurences */
		{								/* of one same character */
			runlen++;
			a++;
		}
		
		sprintf(count, "%d", runlen);		/* storing runlength into the array */
		
		for (c = 0; *(count + c); c++, b++)
		{
			dest[b] = count[c];		/* copying the number in front of the characters */
		}
		dest[b++] = source[a];			/* copying the character to be the second in the array, after the number */
	}

	dest[b] = '\0';
	return dest;
}


int main(int argc, char* argv[])
{
	char input[MAX];
	char output[MAX];
	//FILE *file_in;
	FILE *file_out = NULL;
	int g;
	char *encoding;



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
	
	for (g = 1; g < (argc-1); g++)		/* looping until all files have been compressed */
	{
		strcpy(input, argv[g]);
		
		char *array = fileToArray(input);
		encoding = encode(&array[0]);
		
		fprintf(file_out, "%s", encoding);
		
		/*file_in = fopen(input, "r");
		if (file_in == NULL)
		{
			fprintf(stdout, "error: cannot open file '%s'\n\n", input);
			exit(1);
		}
		fclose(file_in)*/
		
	}
	
	
	fprintf(stdout, "--- Program finished, the output can be found at '%s'\n", output);

	return 0;
}



