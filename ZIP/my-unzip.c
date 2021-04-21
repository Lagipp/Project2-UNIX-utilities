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


	while ((x = fscanf(file, "%d%c", &integer, chr)) != EOF)
	{	
		if (x != 2)
		{
			fprintf(stdout, "error: input doesnt follow the proper syntax... \n\n");
			exit(1);
		}		
		
		for (t = 0; t < integer; t++) 
		{
			printf("%s", chr);
		
		}	
	} 	

	fclose(file);

	fprintf(stdout, "\n== DEBUG: end of program\n\n");
	return 0;
}



