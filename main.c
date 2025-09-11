#include <stdio.h>
#include <string.h>




// STRUCT

	int countId = 5;
struct informations
{
	int id;
	char nom_prenom[50];
	int numero_maillot;
	char poste[20];
	int age;
	int buts;
};
struct count
{
	int count ;
};



// AJOUTE UN JOUEUR

void ajoute(struct informations footballPlayers[], struct count counter[])
{
	int AM;
	int P;
	char positions[4][20] = {"gardien", "defenseur", "milieu", "attaquant"};

	do
	{
		printf("\n");
		printf("_\n");
		printf("1. Ajoute Un Joueur  /\\ 2. Ajoute Plusieurs Joueurs :  \n");
		printf("--- ");
		scanf("%d", &AM);
		getchar();
	} while (AM < 1 || AM > 2);

	if (AM == 1)
	{
		int C = counter[0].count;

		printf("________________________________________________\n");
		printf("Nom et Prenom :  ");
		fgets(footballPlayers[C].nom_prenom, 50, stdin);
		footballPlayers[C].nom_prenom[strcspn(footballPlayers[C].nom_prenom, "\n")] = '\0';
		printf("________________________________________________\n");
		printf("Numero De Maillot  :");
		scanf("%d", &footballPlayers[C].numero_maillot);
		getchar();
		do
		{
			printf("________________________________________________\n");
			printf("(1. gardien , 2. defenseur , 3.millieu , 4.attaquant)\n");
			printf("Poste : ");
			scanf("%d", &P);
			getchar();
			strcpy(footballPlayers[C].poste, positions[P - 1]);
			printf("________________________________________________\n");
		} while (P < 1 || P > 4);
		printf("Age : ");
		scanf("%d", &footballPlayers[C].age);
		getchar();
		printf("________________________________________________\n");
		printf("Buts : ");
		scanf("%d", &footballPlayers[C].buts);
		getchar();
		printf("________________________________________________\n");
		footballPlayers[C].id = countId ;
		countId++;
		counter[0].count++;
	}

	if (AM == 2)
	{
		int QTT;

		do
		{
			printf("\n");
			printf("________________________________________________\n");
			printf("1. Enter Quantite :  \n");
			printf("--- ");
			scanf("%d", &QTT);
			getchar();
		} while (QTT < 1);

		for (int n = 0; n < QTT; n++)
		{

			int C2 = counter[0].count;
			printf("________________________________________________\n");
			printf("Nom et Prenom :  ");
			fgets(footballPlayers[C2].nom_prenom, 50, stdin);
			footballPlayers[C2].nom_prenom[strcspn(footballPlayers[C2].nom_prenom, "\n")] = '\0';
			printf("________________________________________________\n");
			printf("Numero De Maillot  : ");
			scanf("%d", &footballPlayers[C2].numero_maillot);
			getchar();
			do
			{
				printf("________________________________________________\n");
				printf("(1. gardien , 2. defenseur , 3.millieu , 4.attaquant)\n");
				printf("Poste : ");
				scanf("%d", &P);
				getchar();
				strcpy(footballPlayers[C2].poste, positions[P - 1]);
				printf("________________________________________________\n");
			} while (P < 1 || P > 4);
			printf("Age : ");
			scanf("%d", &footballPlayers[C2].age);
			getchar();
			printf("________________________________________________\n");
			printf("Buts : ");
			scanf("%d", &footballPlayers[C2].buts);
			getchar();
			printf("________________________________________________\n");
			footballPlayers[C2].id = countId;
			countId++;
			counter[0].count++;
		}
	}
}

// AFFICHE LES JOUJEUR(S)

void affiche(struct informations footballPlayers[], struct count counter[])
{

	int C = counter[0].count;
	int AFM;
	int AFP;
	char positions[4][20] = {"gardien", "defenseur", "milieu", "attaquant"};
	struct informations copyASC[100];
	struct informations copyPoste[100];
	struct informations copyAge[100];

	for (int y = 0; y < C; y++)
	{
		copyASC[y] = footballPlayers[y];
	}
	for (int d = 0; d < C; d++)
	{
		copyPoste[d] = footballPlayers[d];
	}
	for (int u = 0; u < C; u++)
	{
		copyAge[u] = footballPlayers[u];
	}

	do
	{
		printf("\n");
		printf("_\n");
		printf("1. Affiche Simple /\\ 2. Affiche Par ASD  /\\ 3. Affiche Par Age /\\ 4. Affiche Par Poste : \n");
		printf("--- ");
		scanf("%d", &AFM);
		getchar();
	} while (AFM < 1 || AFM > 4);


	if(AFM == 1){


        	for (int i = 0; i < C; i++)
		{
			printf("ID : %d\n", footballPlayers[i].id);
			printf("Name : %s\n", footballPlayers[i].nom_prenom);
			printf("numero mailot : %d\n", footballPlayers[i].numero_maillot);

			printf("poste : %s\n", footballPlayers[i].poste);
			printf("age : %d\n", footballPlayers[i].age);

			printf("buts : %d\n", footballPlayers[i].buts);
			printf("________________________________________________\n");
		}


	}

	if (AFM == 2)
	{

		for (int q = 0; q < C - 1; q++)
		{
			for (int j = 0; j < C - q - 1; j++)
			{
				if (strcmp(copyASC[j].nom_prenom, copyASC[j + 1].nom_prenom) > 0)
				{
					struct informations temp = copyASC[j];
					copyASC[j] = copyASC[j + 1];
					copyASC[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < C; i++)
		{
			printf("ID : %d\n", copyASC[i].id);
			printf("Name : %s\n", copyASC[i].nom_prenom);
			printf("numero mailot : %d\n", copyASC[i].numero_maillot);

			printf("poste : %s\n", copyASC[i].poste);
			printf("age : %d\n", copyASC[i].age);

			printf("buts : %d\n", copyASC[i].buts);
			printf("________________________________________________\n");
		}
	}

	if (AFM == 3)
	{

		for (int i = 0; i < C; i++)
		{

			for (int l = 0; l < C - i - 1; l++)
			{

				if (copyAge[l].age >= copyAge[l + 1].age)
				{

					struct informations temp = copyAge[l];

					copyAge[l] = copyAge[l + 1];
					copyAge[l + 1] = temp;
				}
			}
		}

		for (int i = 0; i < C; i++)
		{
			printf("ID : %d\n", copyAge[i].id);
			printf("Name : %s\n", copyAge[i].nom_prenom);
			printf("numero mailot : %d\n", copyAge[i].numero_maillot);

			printf("poste : %s\n", copyAge[i].poste);
			printf("age : %d\n", copyAge[i].age);

			printf("buts : %d\n", copyAge[i].buts);
			printf("________________________________________________\n");
		}
	}

	if (AFM == 4)
	{
	    afficheByPoste:
	    int found = 0;
	    int AB;
do{
	printf("________________________________________________\n");
	printf("\n");
printf("Quel poste voulez-vous afficher ( 1. gardien , 2. defenseur , 3. milieu , 4. attaquant ) : ");
	scanf("%d",&AFP);
	printf("\n");
	printf("________________________________________________\n");
	printf("\n");
}while(AFP < 1 || AFP > 4);





        for(int index = 0 ; index < C ; index++){




            if(strcmp(positions[AFP - 1],footballPlayers[index].poste) == 0){


		    printf("________________________________________________\n");
			printf("ID : %d\n", footballPlayers[index].id);
			printf("Name : %s\n", footballPlayers[index].nom_prenom);
			printf("numero mailot : %d\n", footballPlayers[index].numero_maillot);

			printf("poste : %s\n", footballPlayers[index].poste);
			printf("age : %d\n", footballPlayers[index].age);

			printf("buts : %d\n", footballPlayers[index].buts);
			printf("________________________________________________\n");


            found++;

            }


        }




   if(found == 0){


		printf("______________________________________\n");
		printf("Player Not Found :( \n");
		printf("______________________________________\n");

   }


do{

printf("1. affiche d'autre /\\ 2. back : ");
scanf("%d",&AB);
}while(AB < 1 || AB > 2);

if(AB == 1){
    goto afficheByPoste;
}


	}
}

// SEARCH

void search(struct informations footballPlayers[], struct count counter[])
{
    searchAgain:
	int C = counter[0].count;
	int found = 0;
	int SH;
	int AB =0 ;
	do
	{
		printf("\n");
		printf("1. Recherche Pour Name  /\\ 2. Recherche Pour ID : ");
		scanf("%d", &SH);
		getchar();
	} while (SH < 1 || SH > 2);

	if (SH == 1)
	{

		char name[20];

		printf("Enter Nom De joueur : ");
		fgets(name, 20, stdin);
		name[strcspn(name, "\n")] = '\0';

		for (int i = 0; i < C; i++)
		{

			if (strcmp(name, footballPlayers[i].nom_prenom) == 0)
			{

				printf("______________________________________\n");

				printf("ID : %d\n", footballPlayers[i].id);
				printf("Name : %s\n", footballPlayers[i].nom_prenom);
				printf("numero mailot : %d\n", footballPlayers[i].numero_maillot);

				printf("poste : %s\n", footballPlayers[i].poste);
				printf("age : %d\n", footballPlayers[i].age);

				printf("buts : %d\n", footballPlayers[i].buts);
				printf("______________________________________\n");

				found++;
			}
		}
	}

	if (SH == 2)
	{

		char id;

		printf("Enter ID De joueur : ");
		scanf("%d", &id);

		for (int i = 0; i < C; i++)
		{

			if (footballPlayers[i].id == id)
			{

				printf("______________________________________\n");

				printf("ID : %d\n", footballPlayers[i].id);
				printf("Name : %s\n", footballPlayers[i].nom_prenom);
				printf("numero mailot : %d\n", footballPlayers[i].numero_maillot);

				printf("poste : %s\n", footballPlayers[i].poste);
				printf("age : %d\n", footballPlayers[i].age);

				printf("buts : %d\n", footballPlayers[i].buts);
				printf("______________________________________\n");

				found++;
			}
		}
	}

	if (found == 0)
	{

		printf("______________________________________\n");
		printf("Player Not Found :( \n");
		printf("______________________________________\n");
	}

	do{

printf("1. Recherche pour d'autre /\\ 2. back : ");
scanf("%d",&AB);
}while(AB < 1 || AB > 2);

if(AB == 1){
    goto searchAgain;
}

}

//MODIFIER

void modifier(struct informations footballPlayers[], struct count counter[])
{
modifierAgain:
	char positions[4][20] = {"gardien", "defenseur", "milieu", "attaquant"};
	int MDN;
	int AB = 0;
	int found = 0;
	do
	{
		printf("\n");
		printf("1. Modifier Par Name  /\\ 2. Modifier Par ID : ");
		scanf("%d", &MDN);
		getchar();
	} while (MDN < 1 || MDN > 2);

	if (MDN == 2)
	{

		int C = counter[0].count;
		int id;

		int P;
		printf("Enter ID De joueur : ");
		scanf("%d", &id);

		for (int e = 0; e < C; e++)
		{

			if (id == footballPlayers[e].id)
			{

				printf("______________________________________\n");
				printf("PLAYER : %s\n", footballPlayers[e].nom_prenom);
				printf("______________________________________\n");
				do
				{
					printf("________________________________________________\n");
					printf("(1. gardien , 2. defenseur , 3.millieu , 4.attaquant)\n");
					printf("Poste : ");
					scanf("%d", &P);
					getchar();
					strcpy(footballPlayers[e].poste, positions[P - 1]);
					printf("________________________________________________\n");
				} while (P < 1 || P > 4);
				printf("Age : ");
				scanf("%d", &footballPlayers[e].age);
				getchar();
				printf("________________________________________________\n");
				printf("Buts : ");
				scanf("%d", &footballPlayers[e].buts);
				getchar();
				printf("________________________________________________\n");

				found++;
			}
		}
	}

	if (MDN == 1)
	{

		int C = counter[0].count;
		char name[20];
		int found = 0;
		int MN = 0;
		int IDP;
		int P;
		printf("Enter Nom De joueur : ");
		fgets(name, 20, stdin);
		name[strcspn(name, "\n")] = '\0';

		for (int e = 0; e < C; e++)
		{
			if (strcmp(name, footballPlayers[e].nom_prenom) == 0)
			{

				MN++;
				printf("______________________________________\n");
				printf("ID : %d\n", footballPlayers[e].id);
				printf("PLAYER : %s\n", footballPlayers[e].nom_prenom);
				printf("______________________________________\n");
			}
		}

		if (MN < 2)
		{

			for (int r = 0; r < C; r++)
			{
				if (strcmp(name, footballPlayers[r].nom_prenom) == 0)
				{

					do
					{
						printf("________________________________________________\n");
						printf("(1. gardien , 2. defenseur , 3.millieu , 4.attaquant)\n");
						printf("Poste : ");
						scanf("%d", &P);
						getchar();
						strcpy(footballPlayers[r].poste, positions[P - 1]);
						printf("________________________________________________\n");
					} while (P < 1 || P > 4);
					printf("Age : ");
					scanf("%d", &footballPlayers[r].age);
					getchar();
					printf("________________________________________________\n");
					printf("Buts : ");
					scanf("%d", &footballPlayers[r].buts);
					getchar();
					printf("________________________________________________\n");

					found++;
				}
			}
		}

		if (MN > 1)
		{
			printf("lala : %d \n", MN);
			int id;
			int P;
			printf("Enter ID De joueur : ");
			scanf("%d", &id);

			for (int e = 0; e < C; e++)
			{

				if (id == footballPlayers[e].id)
				{

					printf("______________________________________\n");
					printf("PLAYER : %s\n", footballPlayers[e].nom_prenom);
					printf("______________________________________\n");
					do
					{
						printf("________________________________________________\n");
						printf("(1. gardien , 2. defenseur , 3.millieu , 4.attaquant)\n");
						printf("Poste : ");
						scanf("%d", &P);
						getchar();
						strcpy(footballPlayers[e].poste, positions[P - 1]);
						printf("________________________________________________\n");
					} while (P < 1 || P > 4);
					printf("Age : ");
					scanf("%d", &footballPlayers[e].age);
					getchar();
					printf("________________________________________________\n");
					printf("Buts : ");
					scanf("%d", &footballPlayers[e].buts);
					getchar();
					printf("________________________________________________\n");

					found++;
				}
			}
		}
	}



/* if (found == 0)
	{

		printf("______________________________________\n");
		printf("Player Not Found :( \n");
		printf("______________________________________\n");
	}

*/
	do{

printf("1. Modifier d'autre /\\ 2. back : ");
scanf("%d",&AB);
}while(AB < 1 || AB > 2);

if(AB == 1){
    goto modifierAgain ;
}
}

// SUPPRIMMER

void supprimer(struct informations footballPlayers[], struct count counter[])
{
supprimerAgain:
	int MDN;
	int AB = 0 ;
	int found = 0;
	do
	{
		printf("\n");
		printf("1. Supprimer Par Name  /\\ 2. Supprimer Par ID : ");
		scanf("%d", &MDN);
		getchar();
	} while (MDN < 1 || MDN > 2);

	if (MDN == 2)
	{

		int C = counter[0].count;
		int id;
		int P;
		int SR;
		int FN = 0 ;
		printf("Enter ID De joueur : ");
		scanf("%d", &id);

		for (int i = 0; i < C; i++)
		{

			if (id == footballPlayers[i].id)
			{
				printf("__________________________________\n");

				printf("ID : %d\n", footballPlayers[i].id);
				printf("PLAYER : %s\n", footballPlayers[i].nom_prenom);
				printf("______________________________________\n");
				printf("you sure wanna delete this player ' 1. Yes /\\ 2. No' : ");
				scanf("%d", &SR);

				FN++;
			}
		}



		if (FN == 0)
		{

			printf("______________________________________\n");
			printf("Player Not Found :( \n");
			printf("______________________________________\n");
		}

		if (SR == 1)
		{

			for (int e = 0; e < C; e++)
			{

				if (id == footballPlayers[e].id)
				{

					for (int j = e; j < C - 1; j++)
					{

						footballPlayers[j] = footballPlayers[j + 1];
					}

					counter[0].count--;
					// footballPlayers[i]
					found++;
				}
			}
		}
	}

	if (MDN == 1)
	{

		int C = counter[0].count;
		char name[20];
		int found = 0;
		int MN = 0;
		int IDP;
		printf("Enter Nom De joueur : ");
		fgets(name, 20, stdin);
		name[strcspn(name, "\n")] = '\0';

		for (int e = 0; e < C; e++)
		{
			if (strcmp(name, footballPlayers[e].nom_prenom) == 0)
			{

				MN++;
				printf("______________________________________\n");
				printf("ID : %d\n", footballPlayers[e].id);
				printf("PLAYER : %s\n", footballPlayers[e].nom_prenom);
				printf("______________________________________\n");
			}
		}

		if (MN > 1)
		{
			printf("lala : %d \n", MN);

			int id;
			int SR;
			int FN;
			printf("Enter ID De joueur : ");
			scanf("%d", &id);

			for (int i = 0; i < C; i++)
			{

				if (id == footballPlayers[i].id)
				{
					printf("__________________________________\n");
					printf("you sure wanna delete this player ' 1. Yes /\\ 2. No' : ");
					scanf("%d", &SR);
					FN++;
				}
			}

			if (FN == 0)
			{

				printf("______________________________________\n");
				printf("Player Not Found :( \n");
				printf("______________________________________\n");
			}

			if (SR == 1)
			{

				for (int i = 0; i < C; i++)
				{

					if (id == footballPlayers[i].id)
					{
						printf("__________________________________\n");
						printf("you sure wanna delete this player ' 1. Yes /\\ 2. No' : ");
						scanf("%d", &SR);
						FN++;
					}
				}

				for (int e = 0; e < C; e++)
				{

					if (id == footballPlayers[e].id)
					{

						for (int v = e; v < C - 1; v++)
						{

							footballPlayers[v] = footballPlayers[v + 1];
						}
					}
				}
				counter[0].count--;
				found++;
			}
		}

		if (MN < 2)
		{

			int m = counter[0].count;
			printf("%d", m);
			printf("tara kayn");

			for (int r = 0; r < m; r++)
			{
				if (strcmp(name, footballPlayers[r].nom_prenom) == 0)
				{

					for (int g = r; g < m - 1; g++)
					{
						footballPlayers[g] = footballPlayers[g + 1];
					}
				}
			}
			found++;
			counter[0].count--;
		}



	}
	do{

printf("1. Supprimer d'autre /\\ 2. back : ");
scanf("%d",&AB);
}while(AB < 1 || AB > 2);

if(AB == 1){
    goto supprimerAgain;
}
}

// STATISTIQUES

void statistiques(struct informations footballPlayers[], struct count counter[]){

int STT;
int C = counter[0].count;
int AB;
goAgain:

	do
	{
	printf("\n");
		printf("\n");
		printf("      ________________ STATISTIQUES ________________");
		printf("\n");
		printf("________________________________________________\n");
		printf("1. Afficher le nombre total de joueurs dans l’équipe : \n");
		printf("________________________________________________\n");
		printf("2. Afficher l’âge moyen des joueurs : \n");
		printf("________________________________________________\n");
		printf("3. Afficher les joueurs ayant marqué plus de X buts  : \n");
		printf("________________________________________________\n");
		printf("4. Afficher le meilleur buteur (joueur avec le maximum de buts) : \n");
		printf("________________________________________________\n");
		printf("5. Afficher le joueur le plus jeune et le plus âgé : \n");
		printf("________________________________________________\n");
		printf("--- ");
		scanf("%d", &STT);
		getchar();

		printf("\n");
		printf("\n");
	} while (STT < 1 || STT > 5);



	if(STT == 1){
            printf("_______________________________________\n");
        printf("le nombre total de joueurs est un : %d\n",C);
	printf("_______________________________________\n");
	}

	if(STT == 2){
           int total = 0;

    for(int i = 0 ; i < C - 1 ; i++){
        total += footballPlayers[i].age;
    }
          int  moyen = total / C ;
          printf("_______________________________________\n");
        printf("l’âge moyen des joueurs : %d\n",moyen);
        printf("_______________________________________\n");
	}


	if(STT == 3){

        int BT;
        do{
        printf("Enter nomber de buts :  ");
        scanf("%d",&BT);
        }while(BT < 1);


        for(int i = 0 ; i < C ; i++){


            if(footballPlayers[i].buts > BT){


                	printf("ID : %d\n", footballPlayers[i].id);
			printf("Name : %s\n", footballPlayers[i].nom_prenom);
			printf("numero mailot : %d\n", footballPlayers[i].numero_maillot);

			printf("poste : %s\n", footballPlayers[i].poste);
			printf("age : %d\n", footballPlayers[i].age);

			printf("buts : %d\n", footballPlayers[i].buts);
			printf("________________________________________________\n");


            }



        }






	}


	if(STT == 4){

        int maxButs = 0;
        for(int  i =0 ; i < C  ; i++){


            if(footballPlayers[i].buts > maxButs){
                maxButs = footballPlayers[i].buts;
            }


        }



        for(int i = 0 ; i < C ; i++){

            if(footballPlayers[i].buts == maxButs){


                	printf("ID : %d\n", footballPlayers[i].id);
			printf("Name : %s\n", footballPlayers[i].nom_prenom);
			printf("numero mailot : %d\n", footballPlayers[i].numero_maillot);

			printf("poste : %s\n", footballPlayers[i].poste);
			printf("age : %d\n", footballPlayers[i].age);

			printf("buts : %d\n", footballPlayers[i].buts);
			printf("________________________________________________\n");





            }




        }




	}



	if(STT == 5){




     int plusJeune = footballPlayers[0].age;
        for(int  i =0 ; i < C  ; i++){
            if(footballPlayers[i].age < plusJeune){
                plusJeune = footballPlayers[i].age;
            }
        }
         int plusAge = 0;
        for(int  i =0 ; i < C  ; i++){

            if(footballPlayers[i].age > plusAge){
                plusAge = footballPlayers[i].age;
            }
        }



        for(int u = 0 ; u < C ; u++){




            if(footballPlayers[u].age == plusJeune){


                    printf("LE JOUEUR PLUS JEUNE : \n");
                	printf("ID : %d\n", footballPlayers[u].id);
			printf("Name : %s\n", footballPlayers[u].nom_prenom);
			printf("numero mailot : %d\n", footballPlayers[u].numero_maillot);

			printf("poste : %s\n", footballPlayers[u].poste);
			printf("age : %d\n", footballPlayers[u].age);

			printf("buts : %d\n", footballPlayers[u].buts);
			printf("________________________________________________\n");

              printf("\n");
              printf("\n");


            }










	}





	for(int u = 0 ; u < C ; u++){




            if(footballPlayers[u].age == plusAge){


                    printf("LE JOUEUR PLUS AGE : \n");
                	printf("ID : %d\n", footballPlayers[u].id);
			printf("Name : %s\n", footballPlayers[u].nom_prenom);
			printf("numero mailot : %d\n", footballPlayers[u].numero_maillot);

			printf("poste : %s\n", footballPlayers[u].poste);
			printf("age : %d\n", footballPlayers[u].age);

			printf("buts : %d\n", footballPlayers[u].buts);
			printf("________________________________________________\n");

              printf("\n");
              printf("\n");


            }










	}









	}









	        do{

printf("1. d'autre /\\ 2. back : ");
scanf("%d",&AB);
}while(AB < 1 || AB > 2);

if(AB == 1){
    goto goAgain;
}
}



int main()
{

	int choose;
	struct count counter[1];
	struct informations footballPlayers[100] =
		{
			{1, "fakhrddine largou", 7, "milieu", 56, 210},
			{2, "anas talbi", 5, "defenseur", 25, 80},
			{3, "yassine bono", 1, "gardien", 34, 1},
			{4, "yassine bono", 0, "milieu", 98, 10}

		};
	counter[0].count = 4;

menu:

	do
	{
	printf("\n");
		printf("\n");
		printf("      ________________ MENU ________________");
		printf("\n");
		printf("________________________________________________\n");
		printf("1. Ajoute Joueur (s) : \n");
		printf("________________________________________________\n");
		printf("2. Afficher Joueurs : \n");
		printf("________________________________________________\n");
		printf("3. Recherche un joueur : \n");
		printf("________________________________________________\n");
		printf("4. Modifier un Joueur : \n");
		printf("________________________________________________\n");
		printf("5. Supprimer un Joueur : \n");
		printf("________________________________________________\n");
		printf("6. Statistiques : \n");
		printf("________________________________________________\n");
		printf("--- ");
		scanf("%d", &choose);
		getchar();
		printf("\n");
		printf("\n");
	} while (choose < 1 || choose > 8);

	switch (choose)
	{

	case 1:
		ajoute(footballPlayers, counter);
		goto menu;
		break;

	case 2:
		affiche(footballPlayers, counter);
		goto menu;
		break;

	case 3:
		search(footballPlayers, counter);
		goto menu;
		break;

	case 4:

		modifier(footballPlayers, counter);
		goto menu;
		break;

	case 5:
		supprimer(footballPlayers, counter);
		goto menu;
		break;
    case 6:
        statistiques(footballPlayers,counter);
        goto menu;
        break;
	}

	return 0;
}
