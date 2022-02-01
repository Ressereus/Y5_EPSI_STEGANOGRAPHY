




#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CCrypteur.h"

using namespace std;




int main()
{

	char cfichier[] = "e:\\Cours_Annee_5\\TEST.bmp";
	char cfichier2[] = "TEST2.bmp";
	char data[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	CCrypteur LeCrypteur(cfichier);
	if (LeCrypteur.valide = false)
	{
		printf("ce n'est pas un fichier BMP");
		return -1;
	}
	if (LeCrypteur.reconst.bitspPixels != 24)
	{
		printf("pas 24bits");
		return -2;
	}


	LeCrypteur.EcrireMessage(data);
	//LeCrypteur.CreerBMP(cfichier2);

	return 0;
}