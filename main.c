#include <stdio.h>
#include <string.h>




// STRUCT

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
	int count;
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
		footballPlayers[C].id = C + 1;
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
			footballPlayers[C2].id = C2 + 1;
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
	} while (AFM < 1 || AFM > 3);


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
do{
	printf("________________________________________________\n");
	printf("\n");
printf("Quel poste voulez-vous afficher : ( 1. gardien , 2. defenseur , 3. milieu , 4. attaquant )");
	scanf("%d",&AFP);
	printf("\n");
	printf("________________________________________________\n");
	printf("\n");
}while(AFP < 1 || AFP > 4);



        for(int index = 0 ; index < C ; index++){

            if(strcmp(positons[AFP - 1],footballPlayers[index].poste) == 0){


                 	for (int i = 0; i < C; i++)
		{
		    printf("________________________________________________\n");
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







	}
}

void search(struct informations footballPlayers[], struct count counter[])
{

	int C = counter[0].count;
	int found = 0;
	int SH;
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
	else if (found > 0)
	{

		printf("______________________________________\n");
		printf("Modifiquation est un  done :) \n");
		printf("______________________________________\n");
	}
}

void modifier(struct informations footballPlayers[], struct count counter[])
{

	char positions[4][20] = {"gardien", "defenseur", "milieu", "attaquant"};
	int MDN;
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

	if (found == 0)
	{

		printf("______________________________________\n");
		printf("Player Not Found :( \n");
		printf("______________________________________\n");
	}
}

void supprimer(struct informations footballPlayers[], struct count counter[])
{

	int MDN;
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

		/*
			if(found == 0)
			{

				printf("______________________________________\n");
				printf("Player Not Found :( \n");
				printf("______________________________________\n");

			}

		*/
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
			{4, "yassine bono", 0, "milieu", 3, 10}

		};
	counter[0].count = 4;

menu:

	do
	{

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
		printf("1. enterjfjfjfjjjdjdjd\n");
		printf("________________________________________________\n");
		printf("1. enterjfjfjfjjjdjdjd\n");
		printf("________________________________________________\n");
		printf("1. enterjfjfjfjjjdjdjd\n");
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
	}

	return 0;
}
