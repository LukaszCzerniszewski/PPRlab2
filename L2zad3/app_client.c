/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "app.h"


void
// testowy_1(char *host,int liczba1, int liczba2)
testowy_1(char *host,char *dana, int size )
{
	CLIENT *clnt;
	wyjscie  *result_1;
	wejscie  obliczenia_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, TESTOWY, PROBNA, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	for(int i =0; i< size; i++)
	{
		obliczenia_1_arg.x1[i]=dana[i];
	}
	

	obliczenia_1_arg.x2 = size;
	
	result_1 = obliczenia_1(&obliczenia_1_arg, clnt);
	
	if (result_1 == (wyjscie *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	
	// for(int i=0; i< size; i++)
	// {
	// 	obliczenia_1_arg.x1 = dana[i];
	// 	result_1 = obliczenia_1(&obliczenia_1_arg, clnt);
	// if (result_1 == (wyjscie *) NULL) {
	// 	clnt_perror (clnt, "call failed");
	// }

	// }

	

	// printf("\nWprowadzone dane:\t%d\t%d\n", liczba1, liczba2);
	// printf("\nUzyskane wyniki:\n");
	// printf("\tsuma:\t\t%d\n\troznica:\t%d\n\tiloczyn:\t%d\n\n",
		// result_1->suma, result_1->roznica, result_1->iloczyn);
	// printf("\tsuma:\t\t%d\n",
	// 	result_1->suma);

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	char *dana;

	// if (argc < 2) {
	// 	printf ("usage: %s server_host\n", argv[0]);
	// 	exit (1);
	// }
	host = argv[1];
	printf("Czesc to ja client 'Proces 1'");
	printf("Podaj dana do przekonwertowania\n");
	scanf("%s",dana);
	printf("\nDana do przekonwertowania = %s\n",dana);
	testowy_1 (host, dana, strlen(dana));


	//testowy_1 (host, atoi(argv[2]), atoi(argv[3]));
	exit (0);
}
