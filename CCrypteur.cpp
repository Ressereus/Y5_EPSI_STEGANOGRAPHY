
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CCrypteur.h"
using namespace std;


int CCrypteur::EcrireMessage(char* buffer_original)
{
	unsigned int TailleData_original = strlen(buffer_original);
	unsigned int TailleData = TailleData_original + 6; //Ajoute le message (MSG-) et un EOT à la fin
	char* buffer = new char[TailleData];

	sprintf_s(buffer, TailleData, "MSG-%s%c\0", buffer_original, 0x40);

	unsigned int TailleDataX8 = TailleData * 8;

	if (TailleData <= reconst.chargeUtileMSG)
	{
		int i = 0;
		int j = 0;
		int k = 0;
		UnionOctet* OctetBuffer = new UnionOctet[TailleData];
		UnionOctet* OctetDestination = new UnionOctet[TailleData];

		//remplissage des tableaux d'octets
		for (i = 0; i < TailleData; i++)
		{

			OctetBuffer[i].c = buffer[i];
			OctetDestination[i].c = cData[i];
		}
		i = 0;
		for (i = 0; i < TailleDataX8; i++)
		{
			switch (j)
			{
			case 0:
				if ((OctetBuffer[k].Octet.b0 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b0 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b0 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b0 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 1:
				if ((OctetBuffer[k].Octet.b1 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b1 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b1 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b1 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 2:
				if ((OctetBuffer[k].Octet.b2 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b2 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b2 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b2 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 3:
				if ((OctetBuffer[k].Octet.b3 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b3 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b3 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b3 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 4:
				if ((OctetBuffer[k].Octet.b4 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b4 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b4 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b4 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 5:
				if ((OctetBuffer[k].Octet.b5 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b5 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b5 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b5 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 6:
				if ((OctetBuffer[k].Octet.b6 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b6 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b6 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b6 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 7:
				if ((OctetBuffer[k].Octet.b7 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b7 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b7 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b7 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			}
			j++;
			if (j == 8)
			{
				j = 0;
				k++;
			}
		}
		for (i = 0; i < TailleDataX8; i++)
		{
			cData[i] = OctetDestination[i].c;
		}

		char nomfichier[50];
		cout << " données encodées " << endl;

		cout << "donnez un nom de fichier et une destination ( avec le.bmp a la fin) ";
		cin >> nomfichier;
		CreerBMP(nomfichier);
	}
	return 0;
}




int CCrypteur::LireMessage()
{

	char* MessageEncode = new char[reconst.chargeUtileMSG];

	UnionOctet* OctetMessage = new UnionOctet[reconst.chargeUtileMSG];
	UnionOctet* OctetData = new UnionOctet[reconst.restant];

	int i = 0;
	int j = 0;
	int k = 0;

	char entete[4] = "";

	bool flagEOT = false;


	//remplissage du tableaux d'octets
	for (i = 0; i < reconst.restant; i++)
	{
		OctetData[i].c = cData[i];

	}
	i = 0;
	for (i = 0; i < reconst.chargeUtileMSG; i++)
	{
		OctetMessage[i].c = 0x00;

	}
	i = 0;

	//lecture de trois octets "MSG"
	//fin de lecture avec ACII c = 0x04 EOT

	for (i = 0; i < 24; i++)
	{
		switch (j)
		{
		case 0:
			OctetMessage[k].Octet.b0 = OctetData[i].Octet.b0;
			break;
		case 1:
			OctetMessage[k].Octet.b1 = OctetData[i].Octet.b0;
			break;
		case 2:
			OctetMessage[k].Octet.b2 = OctetData[i].Octet.b0;
			break;
		case 3:
			OctetMessage[k].Octet.b3 = OctetData[i].Octet.b0;
			break;
		case 4:
			OctetMessage[k].Octet.b4 = OctetData[i].Octet.b0;
			break;
		case 5:
			OctetMessage[k].Octet.b5 = OctetData[i].Octet.b0;
			break;
		case 6:
			OctetMessage[k].Octet.b6 = OctetData[i].Octet.b0;
			break;
		case 7:
			OctetMessage[k].Octet.b7 = OctetData[i].Octet.b0;
			break;
		}


		j++;
		if (j == 8)
		{
			j = 0;
			entete[k] = OctetMessage->c;
			k++;
		}

	}
	entete[3] = '\0';

	//si un entête "MSG" est détecté !
	if (strcmp(entete, "MSG") == 0)
	{
		printf("il n'y a rien d'encodé sur cette image");
		return -1;
	}
	else
	{
		cout << "décodage en cours.." << endl;
		k = 0;
		i = 0;
		j = 0;
		while (!flagEOT) //Lire tant que l'ont ne voit pas de caractère EOT 0x04 sur la table ascii
		{
			switch (j)
			{
			case 0:
				OctetMessage[k].Octet.b0 = OctetData[i].Octet.b0;
				break;
			case 1:
				OctetMessage[k].Octet.b1 = OctetData[i].Octet.b0;
				break;
			case 2:
				OctetMessage[k].Octet.b2 = OctetData[i].Octet.b0;
				break;
			case 3:
				OctetMessage[k].Octet.b3 = OctetData[i].Octet.b0;
				break;
			case 4:
				OctetMessage[k].Octet.b4 = OctetData[i].Octet.b0;
				break;
			case 5:
				OctetMessage[k].Octet.b5 = OctetData[i].Octet.b0;
				break;
			case 6:
				OctetMessage[k].Octet.b6 = OctetData[i].Octet.b0;
				break;
			case 7:
				OctetMessage[k].Octet.b7 = OctetData[i].Octet.b0;
				break;
			}


			j++;
			if (j == 8)
			{
				j = 0;
				if (OctetMessage[k].c == 0x40)
				{
					flagEOT = true;
					MessageEncode[k] = '\0';
				}
				else
				{
					MessageEncode[k] = OctetMessage[k].c;
				}
				k++;
			}
			i++;
		}

		cout << MessageEncode;



	}
	return 0;
}

CCrypteur::CCrypteur(const char* chemin)
{
	FILE* fichierEntree2;
	fopen_s(&fichierEntree2, chemin, "rb");
	fread(reconst.Entete, 138, 1, fichierEntree2);
	fclose(fichierEntree2);
	fopen_s(&fichierEntree2, chemin, "rb");


	strcpy_s(reconst.leChemin, chemin);

	fread(reconst.cN_M, 2, 1, fichierEntree2);



	if (strcmp((char*)reconst.cN_M, "BM"))
	{
		printf("ce n'est pas un fichier BMP");
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
		if (reconst.bitspPixels != 24)
		{

			printf("ce n'est pas un format 24 bits");

			valide = false;
		}
		else
		{



			this->reconst.compression = *((int*)reconst.cCompression);
			this->reconst.taille = *((int*)reconst.cTaille);
			reconst.restant = this->reconst.largeur * this->reconst.hauteur * 3;
			this->reconst.chargeUtileMSG = (((reconst.restant * 3) / 8) / 8);
			this->reconst.chargeUtileIMG = (this->reconst.chargeUtileMSG / 3) - 54 - 64 - 20;

			cData = new unsigned char[reconst.restant];

			fread(cData, 1, reconst.restant, fichierEntree2);
		}
		fclose(fichierEntree2);

	}
}

int CCrypteur::CreerBMP(char* nom)
{

	int i = 0;
	int ouverture = 0;
	FILE* fichierSortie2;

	ouverture = fopen_s(&fichierSortie2, nom, "w+ b");

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
	fwrite(cData, reconst.restant, 1, fichierSortie2);

	fclose(fichierSortie2);
	return 0;
}

int CCrypteur::EncoderImage(CCrypteur* Image)
{
	if (Image->reconst.tailleDuBMP > reconst.chargeUtileIMG)
	{

		printf("le fichier est trop grand");
		return -1;
	}
	else
	{

		UnionOctet* OctetDestination = new UnionOctet[Image->reconst.tailleDuBMP]; //contiendra les données de la destination : image qui sert de support
		UnionOctet* OctetsEnteteImage = new UnionOctet[138]; //contiendra les données de la nouvelle image
		unsigned int TailleData = Image->reconst.tailleDuBMP;

		int i = 0;
		int j = 0;
		int k = 0;


		unsigned int TailleDataX8 = TailleData * 8;
		unsigned int TailleEnteteX8 = 138 * 8;

		//remplissage de l'entete
		for (i = 0; i < TailleData; i++)
		{
			OctetDestination[i].c = cData[i];		//remplissage des données de RGB de l'image de base 
		}
		for (i = 0; i < 138; i++)
		{
			OctetsEnteteImage[i].c = Image->reconst.Entete[i]; //remplissage des données de l'entête de Image
		}

		i = 0;
		for (i = 0; i < TailleEnteteX8; i++) //doit remplir l'entete
		{
			switch (j)
			{
			case 0:
				if ((OctetsEnteteImage[k].Octet.b0 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b0 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				else if ((OctetsEnteteImage[k].Octet.b0 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b0 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 1:
				if ((OctetsEnteteImage[k].Octet.b1 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b1 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				else if ((OctetsEnteteImage[k].Octet.b1 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b1 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 2:
				if ((OctetsEnteteImage[k].Octet.b2 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b2 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				else if ((OctetsEnteteImage[k].Octet.b2 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b2 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 3:
				if ((OctetsEnteteImage[k].Octet.b3 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b3 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				else if ((OctetsEnteteImage[k].Octet.b3 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b3 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 4:
				if ((OctetsEnteteImage[k].Octet.b4 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b4 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				else if ((OctetsEnteteImage[k].Octet.b4 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b4 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 5:
				if ((OctetsEnteteImage[k].Octet.b5 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b5 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				else if ((OctetsEnteteImage[k].Octet.b5 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b5 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 6:
				if ((OctetsEnteteImage[k].Octet.b6 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b6 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				else if ((OctetsEnteteImage[k].Octet.b6 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b6 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 7:
				if ((OctetsEnteteImage[k].Octet.b7 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b7 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				else if ((OctetsEnteteImage[k].Octet.b7 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetsEnteteImage[k].Octet.b7 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			}
			j++;
			if (j == 8)
			{
				j = 0;
				k++;
			}
		}
		//remplissage des couleurs

		k = 0;
		j = 0;
		int d = 0;
		UnionOctet* OctetBuffer = new UnionOctet[Image->reconst.restant]; //contiendra les données de la nouvelle image

		//remplissage des tableaux d'octets

		for (d; d < Image->reconst.restant; d++)
		{
			OctetBuffer[d].c = Image->cData[d]; //remplissage des Octets de RGB provenant de Image
		}


		for (i; i < TailleDataX8; i++)
		{
			switch (j)
			{
			case 0:
				if ((OctetBuffer[k].Octet.b0 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b0 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b0 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b0 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 1:
				if ((OctetBuffer[k].Octet.b1 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b1 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b1 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b1 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 2:
				if ((OctetBuffer[k].Octet.b2 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b2 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b2 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b2 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 3:
				if ((OctetBuffer[k].Octet.b3 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b3 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b3 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b3 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 4:
				if ((OctetBuffer[k].Octet.b4 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b4 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b4 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b4 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 5:
				if ((OctetBuffer[k].Octet.b5 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b5 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b5 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b5 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 6:
				if ((OctetBuffer[k].Octet.b6 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b6 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b6 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b6 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			case 7:
				if ((OctetBuffer[k].Octet.b7 == 0 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b7 == 0 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 0;
				}
				if ((OctetBuffer[k].Octet.b7 == 1 && OctetDestination[i].Octet.b0 == 0) || (OctetBuffer[k].Octet.b7 == 1 && OctetDestination[i].Octet.b0 == 1))
				{
					OctetDestination[i].Octet.b0 = 1;
				}
				break;
			}
			j++;
			if (j == 8)
			{
				j = 0;
				k++;
			}
		}
		for (i = 0; i < TailleDataX8; i++)// i = 0
		{
			cData[i] = OctetDestination[i].c;
		}

		CreerBMP((char*)"test_image.bmp");
	}
	return 0;
}

int CCrypteur::AfficherImage(CCrypteur Image)
{




	return 0;
}

