#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

struct pixel_s
{

	char r;
	char g;
	char b;

};

struct bits_s
{
	
	unsigned short int b0 : 1;// le LSB
	unsigned short int b1 : 1;
	unsigned short int b2 : 1;
	unsigned short int b3 : 1;
	unsigned short int b4 : 1;
	unsigned short int b5 : 1;
	unsigned short int b6 : 1;
	unsigned short int b7 : 1;

	
};

typedef union
{
	bits_s Octet;
	unsigned char c;

}UnionOctet;

struct fichier_s
{
	char leChemin[100];
	unsigned char cN_M[3];
	unsigned char cPoid[5];
	unsigned char cID1[3], cID2[3];
	unsigned char cOffset[5];
	unsigned char cDIB[5];
	unsigned char cLargeur[5] = "";
	unsigned char cHauteur[5] = "";
	unsigned char cPlanes[3];
	unsigned char cBPX[3];
	unsigned char cCompression[5];
	unsigned char cTaille[5];
	unsigned char cXpixelsPM[5];
	unsigned char cYpixelsPM[5];
	unsigned char cColorsUsed[5];
	unsigned char cColorsImportant[5];
	unsigned char cMasqueR[5];
	unsigned char cMasqueG[5];
	unsigned char cMasqueB[5];
	unsigned char cMasqueA[5];
	unsigned char cRGB[5];
	unsigned char cUnused[65];

	unsigned char Entete[139];
	unsigned int restant;
	unsigned int tailleDuBMP;
	unsigned int chargeUtileMSG;
	unsigned int chargeUtileIMG;
	unsigned int taille;
	short int bitspPixels;
	int largeur;
	int hauteur;
	int compression;

};



class CCrypteur
{
public:

	int EcrireMessage(char* buffer);
	int LireMessage();
	int EncoderImage(CCrypteur* Image);
	int AfficherImage(CCrypteur Image);
	int CreerBMP(char* Nom);

	CCrypteur(const char* file);
	bool valide;
	ifstream fichier;
	 fichier_s reconst;
	 unsigned char* cData;
	pixel_s* data;
};

