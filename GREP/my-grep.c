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
#define MAX 512



int main(int argc, char* argv[])
{
	char buffer[MAX];
	FILE *file;
	int count = 0;
	int m;
	
	if (argc < 2)
	{
		fprintf(stdout, "my-grep: <searchterm> <file1>, <file2>, ...\n");
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
	
		for (m = 2; m < argc; m++)
		{
			file = fopen(argv[m], "r");
			if (file == NULL)
			{
				fprintf(stdout, "error: cannot open file '%s'\n", argv[m]);
				exit(1);
			}
			
			while (fgets(buffer, MAX, file))
			{
				if (strstr(buffer, argv[1]))
				{
					printf("%s", buffer);
					count++;
				}
			}
		
			fclose(file);
			printf("found %d occurrences\n", count);
			
		}
		
	}
	
	fprintf(stdout, "-- DEBUG: end of program --\n");
	return 0;
}
