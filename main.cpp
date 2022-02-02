




#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CCrypteur.h"

using namespace std;
bool flag = true;
char cfichier[150]	= "";
char cfichier2[150] = "";
CCrypteur* LeCrypteur;
CCrypteur* LeCrypteur2;


void findecodageMsg();
void accueil();
void menu();
void secondfichier();
void encoderMsg();
void decoderMsg();


int main()
{
	accueil();
	
return 0;
}

void accueil()
{

	while (flag)
	{
		LeCrypteur = nullptr;
		LeCrypteur2 = nullptr;
		cout << "-Premier fichier" << endl;
		cout << "Bonjour, veuillez donner le chemin d'un fichier BMP 24bits" << endl;
		cin.clear();
		cin >> cfichier;
			LeCrypteur = new CCrypteur(cfichier);
			if (LeCrypteur->valide != true)
			{
				cout << "Erreur, fichier non compatible" << endl;
				accueil();
			}
			else
			{
				menu();
			}
	}
}

void menu()
{
			char c = ' ';
			cout << "fichier chargé avec succès" << endl;
			cout << "1 - charger un second fichier" << endl;
			cout << "2 - Encoder un message" << endl;
			cout << "3 - Decoder un message" << endl;
			cout << "4 - quitter" << endl;
			cin.clear();
			cin >> c;
			switch (c)
			{
			default:
				cout << "Erreur de saisie" << endl;
				menu();
				break;
			case '1':
				secondfichier();
				break;
			case '2':
				encoderMsg();
				break;
			case '3':
				decoderMsg();
				break;
			case '4':
				cout << "aurevoir" << endl;
					flag = false;
					accueil();
					break;

			}
}

void secondfichier()
{
	cout << "veuillez donner le chemin d'un second fichier BMP 24bits" << endl;
	cin.clear();
	cin >> cfichier;
	LeCrypteur2 = new CCrypteur(cfichier);
	if (LeCrypteur2->valide != true)
	{
		cout << "Erreur, chemin ou fichier non compatible" << endl;
		menu();
	}
	else
	{
		cout << "fichier chargé avec succès" << endl;
	}

}
void encoderMsg()
{
	char c = '\0';
	char* MESSAGE = nullptr;
	cout << "La capacité maximale de votre message est de " << LeCrypteur->reconst.chargeUtileMSG << " octets" << endl;
	if (LeCrypteur->reconst.chargeUtileMSG > 200)
	{
		cout << " Oui c'est beaucoup" << endl;
	}

	cout << "Voulez-vous encoder un message? o/n" << endl;
	cin.clear();
	cin >> c;
	if (c == 'o')
	{
		MESSAGE = new char[LeCrypteur->reconst.chargeUtileMSG - 10];
		cout << "Tapez votre message :" << endl;
		cin.clear();
		cin >> MESSAGE;

		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		LeCrypteur->EcrireMessage(MESSAGE);



	}
	else if (c == 'n')
	{
		menu();
	}
	else
	{
		cout << " Erreur de saisie" << endl;
		encoderMsg();
	}
}
void decoderMsg()
{
	
	cout << "vérification de l'encodage" << endl;
	LeCrypteur->LireMessage();
	cout << endl <<  "-----------------fin-du-message-----------------" << endl << "Tapez m pour retourner au menu" << endl;
	findecodageMsg();
}
void findecodageMsg()
{
	char c = ' ';
	cin.clear();
	cin >> c;
	if (c != 'm')
	{
		cout << "_" << endl;
	}
	else
	{
		menu();
	}
}