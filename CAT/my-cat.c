/*****************************************************************/
/* KÄYTTÖJÄRJESTELMÄT JA SYSTEEMIOHJELMOINTI
 * Project 2:			UNIX utilities
 * Nimi ja opiskelijanro:	Miika Pynttäri, 0563090
 * Päivämäärä:			19.4.2021
 * Yhteistyö ja lähteet:	https://gist.github.com/pat36/d991eda0c270ed823a5d83c274c6157c, 
*/
/*****************************************************************/


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{

	FILE* file;
	char chr;
	int q;


	if (argc == 1)
	{
		fprintf(stdout, "No files specified, exiting program...\n\n");
		exit(0);
	}
	
	
	for ( (q = 1); (q < argc); q++ )
	{
	
		/* expanded upon https://gist.github.com/pat36/d991eda0c270ed823a5d83c274c6157c */
	
	
		file = fopen(argv[q], "r");
		if (file == NULL)
		{
			fprintf(stdout, "my-cat: cannot open file\n");
			exit(1);
		}
		
		fprintf(stdout, "\n== DEBUG: before going into loop to get characters ==\n");
		
		while((chr = getc(file)) != EOF)
		{
			printf("%c", chr);
		}
		
		fclose(file);
		
		fprintf(stdout, "\n###################################\n\n");
		
	}

	
	fprintf(stdout, "\n== DEBUG: end of program ==\n\n");
	return 0;
}
