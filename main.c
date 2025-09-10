#include <stdio.h>
#include <string.h>



struct  informations{
	int id;
	char nom_prenom[50];
	int numero_maillot;
	char poste[20];
	int age;
	int buts;

};
struct count{
int count;
};


void ajoute(struct informations  footballPlayers[],struct count counter[]){
	int AM;
	int P ;

	char positions[4][20] = {"gardien","defenseur","milieu","attaquant"};

	do{
			printf("\n");
	printf("_\n");
	printf("1. Ajoute Un Joueur  /\\ 2. Ajoute Plusieurs Joueurs :  \n");
	printf("--- ");
	scanf("%d",&AM);
	getchar();
	}while(AM < 1 || AM > 2);



	if(AM == 1){
            int C = counter[0].count;

			printf("________________________________________________\n");
	printf("Nom et Prenom :  ");
	fgets(footballPlayers[C].nom_prenom , 50 , stdin);
	footballPlayers[C].nom_prenom[strcspn(footballPlayers[C].nom_prenom, "\n")] = '\0';
		printf("________________________________________________\n");
	printf("Numero De Maillot  :");
	scanf("%d",&footballPlayers[C].numero_maillot);
	getchar();
	do{
		printf("________________________________________________\n");
	printf("(1. gardien , 2. defenseur , 3.millieu , 4.attaquant)\n");
	printf("Poste : ");
		scanf("%d",&P);
			getchar();
		strcpy(footballPlayers[C].poste,positions[P - 1]);
			printf("________________________________________________\n");
	}while(P < 1 || P > 4);
	printf("Age : ");
	scanf("%d",&footballPlayers[C].age);
		getchar();
		printf("________________________________________________\n");
	printf("Buts : ");
	scanf("%d",&footballPlayers[C].buts);
		getchar();
		printf("________________________________________________\n");
    footballPlayers[C].id = C + 1;
	counter[0].count++;

	}


	if(AM == 2){
    int QTT;

    do{
			printf("\n");
		printf("________________________________________________\n");
	printf("1. Enter Quantite :  \n");
	printf("--- ");
	scanf("%d",&QTT);
	getchar();
	}while(QTT < 1);

	for(int n=0 ; n < QTT ; n++){

            int C2 = counter[0].count;
			printf("________________________________________________\n");
	printf("Nom et Prenom :  ");
	fgets(footballPlayers[C2].nom_prenom , 50 , stdin);
	footballPlayers[C2].nom_prenom[strcspn(footballPlayers[C2].nom_prenom, "\n")] = '\0';
		printf("________________________________________________\n");
	printf("Numero De Maillot  : ");
	scanf("%d",&footballPlayers[C2].numero_maillot);
	getchar();
	do{
		printf("________________________________________________\n");
	printf("(1. gardien , 2. defenseur , 3.millieu , 4.attaquant)\n");
	printf("Poste : ");
		scanf("%d",&P);
			getchar();
		strcpy(footballPlayers[C2].poste,positions[P - 1]);
			printf("________________________________________________\n");
	}while(P < 1 || P > 4);
	printf("Age : ");
	scanf("%d",&footballPlayers[C2].age);
		getchar();
		printf("________________________________________________\n");
	printf("Buts : ");
	scanf("%d",&footballPlayers[C2].buts);
		getchar();
		printf("________________________________________________\n");
    footballPlayers[C2].id = C2 + 1;
	counter[0].count++;
	}

	}




}



int main()
{


	int choose;
	struct count counter[1];
	struct informations footballPlayers[1000] = {
	{ 1 , "fakhrddine largou" , 7,"milieu", 22 ,210},
	{ 2 , "anas talbi" , 5,"defenseur", 25 ,80},
	{ 3 , "yassine bono" , 1,"gardien", 34 ,1}
};
counter[0].count = 3;



menu :

do{
	printf("      ________________ MENU ________________");
	printf("\n");
		printf("________________________________________________\n");
	printf("1. Ajoute Joueur (s) : \n");
		printf("________________________________________________\n");
	printf("2. Afficher Joueurs : \n");
		printf("________________________________________________\n");
	printf("1. \n");
		printf("________________________________________________\n");
	printf("1. enterjfjfjfjjjdjdjd\n");
		printf("________________________________________________\n");
	printf("1. enterjfjfjfjjjdjdjd\n");
		printf("________________________________________________\n");
	printf("1. enterjfjfjfjjjdjdjd\n");
		printf("________________________________________________\n");
	printf("1. enterjfjfjfjjjdjdjd\n");
		printf("________________________________________________\n");
	printf("1. enterjfjfjfjjjdjdjd\n");
		printf("________________________________________________\n");
	printf("--- ");
	scanf("%d",&choose);
    getchar();
}while(choose < 1 || choose > 8);


switch(choose){

	case 1 :

ajoute(footballPlayers,counter);
 goto menu;
	break;

	case 2 :


	int C = counter[0].count;
	for(int i=0 ; i < C ; i++){
		printf("ID : %d\n",footballPlayers[i].id);
		printf("Name : %s\n",footballPlayers[i].nom_prenom);
		printf("numero mailot : %d\n",footballPlayers[i].numero_maillot);

		printf("poste : %s\n",footballPlayers[i].poste);
		printf("age : %d\n",footballPlayers[i].age);

		printf("buts : %d\n",footballPlayers[i].buts);
		printf("________________________________________________\n");
		//printf("%d",footballPlayers[i].count);
	}
	goto menu;
	break;
}

return 0;

}
