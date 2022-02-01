
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CCrypteur.h"
using namespace std;


int CCrypteur::EcrireMessage(char* buffer)
{

	unsigned int TailleData = strlen(buffer);
	if (TailleData <= reconst.chargeUtileMSG)
	{
		FILE* fichierEntree2;
		fopen_s(&fichierEntree2, reconst.leChemin, "r+b");
		int i = 0;
		int k = 0;
		unsigned short int bit[8];


		for (i = 0; i < TailleData; i++)
		{
			if()







			for (k = 0; k < 8; k++)
			{
				cData[i] = cData[i] & 0xFE | bit[k];
			}

		}

	}
	return 0;
}

 CCrypteur::CCrypteur(const char* chemin)
{	
	 FILE* fichierEntree2;
	 fopen_s(&fichierEntree2, chemin, "rb");
	 strcpy(reconst.leChemin, chemin);

	 fread(reconst.cN_M, 2, 1, fichierEntree2);



	if (strcmp((char*)reconst.cN_M, "BM"))
	{
		valide = false;
	}
	else
	{
		valide = true;

		fread(reconst.cPoid, 4, 1, fichierEntree2);
		fread(reconst.cID1, 2, 1, fichierEntree2);
		fread(reconst.cID2, 2, 1, fichierEntree2);
		fread(reconst.cOffset, 4, 1, fichierEntree2);
		fread(reconst.cDIB, 4, 1, fichierEntree2);
		fread(reconst.cLargeur, 4, 1, fichierEntree2);
		fread(reconst.cHauteur, 4, 1, fichierEntree2);
		fread(reconst.cPlanes, 2, 1, fichierEntree2);
		fread(reconst.cBPX, 2, 1, fichierEntree2);
		fread(reconst.cCompression, 4, 1, fichierEntree2);
		fread(reconst.cTaille, 4, 1, fichierEntree2);
		fread(reconst.cXpixelsPM, 4, 1, fichierEntree2);
		fread(reconst.cYpixelsPM, 4, 1, fichierEntree2);
		fread(reconst.cColorsUsed, 4, 1, fichierEntree2);
		fread(reconst.cColorsImportant, 4, 1, fichierEntree2);
		fread(reconst.cMasqueR, 4, 1, fichierEntree2);
		fread(reconst.cMasqueB, 4, 1, fichierEntree2);
		fread(reconst.cMasqueG, 4, 1, fichierEntree2);
		fread(reconst.cMasqueA, 4, 1, fichierEntree2);
		fread(reconst.cRGB, 4, 1, fichierEntree2);
		fread(reconst.cUnused, 64, 1, fichierEntree2);

		this->reconst.tailleDuBMP = *((int*)reconst.cPoid);
		this->reconst.largeur = *((int*)reconst.cLargeur);
		this->reconst.hauteur = *((int*)reconst.cHauteur);
		this->reconst.bitspPixels = *((short int*)reconst.cBPX);
		this->reconst.compression = *((int*)reconst.cCompression);
		this->reconst.taille = *((int*)reconst.cTaille);
		reconst.restant = this->reconst.largeur * this->reconst.hauteur * 3 ;
		this->reconst.chargeUtileMSG = (((reconst.restant * 3) / 8) /8);
		this->reconst.chargeUtileIMG = (this->reconst.chargeUtileMSG / 3)-54-64-20;

		cData = new unsigned char[reconst.restant];

		fread(cData ,1,reconst.restant,fichierEntree2);
	}
}

 int CCrypteur::CreerBMP(char* nom)
 {
	 char chemin[50] = "e:\\Cours_Annee_5\\";

	 int i = 0;
	 strcat_s(chemin, nom);
	 FILE* fichierSortie2;
	 fopen_s(&fichierSortie2, chemin, "wb");

	 fwrite(reconst.cN_M, 2, 1, fichierSortie2);
	 fwrite(reconst.cPoid, 4, 1, fichierSortie2);
	 fwrite(reconst.cID1, 2, 1, fichierSortie2);
	 fwrite(reconst.cID2, 2, 1, fichierSortie2);
	 fwrite(reconst.cOffset, 4, 1, fichierSortie2);
	 fwrite(reconst.cDIB, 4, 1, fichierSortie2);
	 fwrite(reconst.cLargeur, 4, 1, fichierSortie2);
	 fwrite(reconst.cHauteur, 4, 1, fichierSortie2);
	 fwrite(reconst.cPlanes, 2, 1, fichierSortie2);
	 fwrite(reconst.cBPX, 2, 1, fichierSortie2);
	 fwrite(reconst.cCompression, 4, 1, fichierSortie2);
	 fwrite(reconst.cTaille, 4, 1, fichierSortie2);
	 fwrite(reconst.cXpixelsPM, 4, 1, fichierSortie2);
	 fwrite(reconst.cYpixelsPM, 4, 1, fichierSortie2);
	 fwrite(reconst.cColorsUsed, 4, 1, fichierSortie2);
	 fwrite(reconst.cColorsImportant, 4, 1, fichierSortie2);
	 fwrite(reconst.cMasqueR, 4, 1, fichierSortie2);
	 fwrite(reconst.cMasqueB, 4, 1, fichierSortie2);
	 fwrite(reconst.cMasqueG, 4, 1, fichierSortie2);
	 fwrite(reconst.cMasqueA, 4, 1, fichierSortie2);
	 fwrite(reconst.cRGB, 4, 1, fichierSortie2);
	 fwrite(reconst.cUnused, 64, 1, fichierSortie2);

	 fwrite(cData, reconst.restant,1 , fichierSortie2);


	 return fclose(fichierSortie2);
 }