




#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CCrypteur.h"

using namespace std;




int main()
{

	char cfichier[] = "e:\\Cours_Annee_5\\TEST2.bmp";
	char cfichier2[] = "e:\\Cours_Annee_5\\turbine.bmp";
	//char data[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	CCrypteur LeCrypteur(cfichier);
	CCrypteur Image2(cfichier2);
	if (LeCrypteur.valide = false)
	{
		
		return -1;
	}
	if (Image2.valide = false)
	{

		return -1;
	}

	//LeCrypteur.EcrireMessage(data);
	//LeCrypteur.LireMessage();
	//LeCrypteur.CreerBMP(cfichier2);
	LeCrypteur.EncoderImage(&Image2);
return 0;
}