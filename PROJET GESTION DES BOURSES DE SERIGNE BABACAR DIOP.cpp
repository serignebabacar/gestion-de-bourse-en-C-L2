#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
typedef struct etudiant // DEFINITION DE LA STRUCUTURE ETUDIANT
{
	          char nom[10];
	          char prenom[20];
	          char ine[13];
	          int bourse ;
	          char genre[10];
          }etudiant;
              void couleur(int x,int y)// POUR LES COULEURS EXEMPLE couleur(12,0);corresponrd a rouge ecriture ecran noir
        {
               HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
               SetConsoleTextAttribute(H,y*16+x);
        }
void gotoxy(int x, int y)// FONTION D'EMPLACEMENT SUR ECRAN
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}
        	void copyright() //  POUR VOIR LE PROGRAMMEUR DU PROJET
{
	couleur(0,3);printf("\n\n\t\t\t\t   COPYRIGHT%c\t\t\t\t        ",-87);couleur(3,0);
	printf("\n\nCe programme vous est presente par\n\nSERIGNE BABACAR DIOP ETUDIANT de la LGI : promo 2015\n\n\n");
	printf("PROF: INGENIEUR PAPA DIOP ");
	couleur(5,99);
	printf("\n\tTAPEZ SUR UNE TOUCHE POUR RETOURNER AU MENU PRINCIPAL:");getch();
}
void fin()
        {
            int i ; char salam[50]      ;
    	  strcpy(salam,"MERCI  ") ;
    	 printf("\n\n\t") ;
    	 for(i=0 ; i<strlen(salam) ; i++)
    	    {
    	            couleur(i+2,0);printf("%c",salam[i]) ;
    	    	printf("\t") ;
    	    	Sleep(1000) ;
    	    }}

      	int trouve(char mot[])//FONTION QUI DECTECTE LES ERREURS DE SAISIS
{

    int i,j=0,resultat=0;
    char cherche[]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for(i=0;i<strlen(mot);i++)
    {
        if(strchr(cherche,mot[i]) == NULL)
            {
                resultat=1;
                break;
            }
    }
    return resultat;

}
void saisi(etudiant e[],int taille)// pour la SAISIE DES INFORMATIONS SUR LES ETUDIANTS
{
	int i,j,n,controle,verifi;
	for(i=0;i<taille;i++)
	{

	couleur(5,0);
	system("cls");
	 printf("\n\t\t\t\t  ___________________  \n");
           printf("\t\t\t\t||                   ||\n");
           printf("\t\t\t\t||   ETUDIANT  %d     ||\n",i+1);
           printf("\t\t\t\t||                   ||\n");
           printf("\t\t\t\t||___________________||\n");
couleur(10,1);
		  printf("INE:");
		   printf("\nNOM:");
		    printf("\nPRENOM:");
		    printf("\nGENRE:");
		     printf("\nTYPE DE BOURSE :\n");
		       couleur(9,0);printf("\n\t\t1: DEMI BOURSE ");
		            couleur(4,0);   printf("\t2:BOURSE ENTIERE ");
                   couleur(6,0); printf("\t3:BOURSE D'EXELLENCE:");
		               printf("\n\t\t\t\t\tCHOIX:");
		do{

		         gotoxy(4,6); scanf("%s",e[i].ine);
		if(i>=1)
		{
			for(j=0;j<i;j++)
			{
				if(strcasecmp(e[i].ine,e[j].ine)==0)
				controle=1;
				else controle=0;
			}
		}
		if(controle==1|| strlen(e[i].ine)!=12 || e[i].ine[0]!='N' ){
		 gotoxy(4,6);
		couleur(12,0);}
	}while(controle==1|| strlen(e[i].ine)!=12 || e[i].ine[0]!='N' );
           couleur(10,1);

           	do{

		gotoxy(5,7);scanf("%s",e[i].nom);
		n=trouve(e[i].nom);
		 if(n==1)
		 {

		 couleur(12,0);
		 gotoxy(4,6);
		 }

		}while(n==1);

couleur(10,1);

		do{

		   gotoxy(7,8);  scanf("%s",e[i].prenom);
		    n=trouve(e[i].prenom);
		   	 if(n==1)
		 {
		 	 couleur(12,0);
		 gotoxy(6,8);
		 }
		}while(n==1);

	          couleur(10,1);        do{

	                 gotoxy(8,9); scanf("%s",e[i].genre);
	                   if(((strcasecmp(e[i].genre,"masculin")!=0)&&(strcasecmp(e[i].genre,"m")!=0))&&((strcasecmp(e[i].genre,"feminin")!=0)&&(strcasecmp(e[i].genre,"f")!=0)))
	                   {
	                   	 gotoxy(8,9);	 couleur(12,0);

					   }
	                   } while(((strcasecmp(e[i].genre,"masculin")!=0)&&(strcasecmp(e[i].genre,"m")!=0))&&((strcasecmp(e[i].genre,"feminin")!=0)&&(strcasecmp(e[i].genre,"f")!=0)));


			do{
			couleur(5,0);

		             	fflush(stdin);
	      gotoxy(46,13); verifi=scanf("%d",&controle);
	        if(verifi!=1 || controle <1|| controle >3)
	       {
	       	couleur(12,0);
	        gotoxy(46,13);
		   }
	       }while(verifi!=1 || controle <1|| controle >3);
	       couleur(10,1);
		       switch(controle)
		        {

			        case 1: e[i].bourse=18000;break;
				    case 2: e[i].bourse=36000;break;
					case 3: e[i].bourse=60000;break;
				default:break;
		        }
		controle=0;

}
}
void montant_global(etudiant c[],int max)// CALCUL DU MONTANT GLOBAL ANNUEL
{
	int i;
	float s1=0,s2=0,s=0;
    for(i=0; i<max; i++)
    {
        if((strcasecmp(c[i].genre,"masculin")==0)||(strcasecmp(c[i].genre,"m")==0))
                  s1+=(c[i].bourse*12)+35000;
        else
                  s2+=(c[i].bourse*12)+35000;
    }
    s=s1+s2;
    printf("\nle montant global(annuel) DE L'allocation des  etudes est %.0f\n",s);
}
void pourcentage(etudiant c[],int max)// CALCUL DU POURCENTAGE
{
    int i;
	float s1=0,s2=0,s=0;
    for(i=0; i<max; i++)
    {
        if((strcasecmp(c[i].genre,"masculin")==0)||(strcasecmp(c[i].genre,"m")==0))
                  s1+=(c[i].bourse*12)+35000;
        else
                  s2+=(c[i].bourse*12)+35000;
    }
    s=s1+s2;

           if(s1>s2)
                 printf("\nla part en pourcentage qui revient aux ETUDIANTS  %2.2f  \n est superieure a celle qui revient auX ETUDIANTES %2.2f\n",(s1*100)/s,(s2*100)/s);
     else if(s1<s2)
                 printf("\nla part en pourcentage qui revient aux ETUDIANTS  %2.2f   \n est inferieure  a celle qui revient auX ETUDIANTES %2.2f\n",(s1*100)/s,(s2*100)/s);
       else
                 printf("\nla part en pourcentage qui revient aux ETUDIANTS  %2.2f \n est egale  a celle qui revient auX ETUDIANTES %2.2f\n",(s1*100)/s,(s2*100)/s);
}
void afficher(etudiant e){// AFFCIHER LES ETUDIANTS
    couleur(10,1); printf("\n\nINE:%s\nNOM:%s\nPRENOM:%s\nGENRE:%s\nMONTANTBOURSE:%d\t\t",e.ine,e.nom,e.prenom,e.genre,e.bourse);
}
void tri(etudiant e[],int taille){// TRIER DANS L'ORDRE DECROISSANT

        FILE*fichier=NULL;
		int i,j,n,verifi;
		etudiant tmp;
		printf("\n\t\t 1:AFFICHAGE DIRECTE \t\t2:AFFICHAGE DANS LE FICHIER ");
        couleur(5,0);  printf("\n\t\t\tchoix:");
         do{
			couleur(5,0);

		             	fflush(stdin);
	       verifi=scanf("%d",&n);
	       if(verifi!=1 || n<1|| n>2)
	       {
	       	couleur(12,0);printf("erreur");
	       	couleur(10,0);printf("\n\t\t\t\t\tCHOIX:");
		   }
	       }while(verifi!=1 || n<1|| n>2);
	       couleur(10,1);
		       switch(n)
		        {

			        case 1:
			            for(i=0;i<=taille-2;i++)
		{
				for(j=i+1;j<taille;j++)
				{
					if(e[i].bourse<e[j].bourse)
					{
					tmp=e[i];
					e[i]=e[j];
					e[j]=tmp;
					}
				}
}
				for(i=0;i<taille;i++)
				{
                    couleur(11,0); printf("\n\t\t\t\tETUDIANT [%d] \n\n",i+1);
                    afficher(e[i]);

				}
				      break;
				    case 2:
				        for(i=0;i<=taille-2;i++)
                {
				          for(j=i+1;j<taille;j++)
				   {
					if(e[i].bourse<e[j].bourse)
					   {
					tmp=e[i];
					e[i]=e[j];
					e[j]=tmp;
					   }
				   }
		       }
			     fichier=fopen("tri.txt","w+");
		if(fichier!=NULL)
			{
				for(i=0;i<taille;i++)
				{
					fprintf(fichier,"\n\t\t\t\tETUDIANT [%d] \n\n",i+1);
					fprintf(fichier,"\n\nINE:%s\nNOM:%s\nPRENOM:%s\nGENRE:%s\nMONTANTBOURSE:%d\n",e[i].ine,e[i].nom,e[i].prenom,e[i].genre,e[i].bourse);
				}


	             fclose(fichier);
	             system("tri.txt");
	        }
				 else
				  {
				   printf("fichier non ouvert");
				  }
				  break;
				  default:break;

   }
}
void recherche(etudiant* p,int n){// POUR RECHERCHER UN ETUDIANT PAR SON INE DANS LA BASE DE DONNEE
   int i=0;
   char id[13];
   printf("Donner L'INE de l'etudiant que vous voulez rechercher:");
   couleur(10,1); scanf("%s",&id);
    while(i<n && strcmp(id,p[i].ine)!=0){
        i++;
    }
    if(i<n){
        printf("ETUDIANT[%d]",i+1);
        afficher(p[i]);
    }else{
        printf("L'INE saisi n'est pas dans la BASE DE DONNEE  ");
    }
}
    int main()
        {
        	    int n=0,i,j,verifi,r;
        	    etudiant* e=NULL;
        	     couleur(4,0);

         printf("\n\t\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
           printf("\t\t\t\t°                                  °\n");
           printf("\t\t\t\t°   PROJET GESTION DES BOURSES     °\n");
           printf("\t\t\t\t°                                  °\n");
           printf("\t\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");

                printf("\n\t\t\t        *******  ");
        	    printf("\n\t\t\t       *******       ");
        	    printf("\n\t\t\t      **          ");
        	    printf("\n\t\t\t     **           ");
                printf("\n\t\t\t    **         ");
                 printf("\n\t\t\t************    ");
                printf("\n\t\t\t************    ");
                printf("\n\t\t\t    **             ");
                printf("\n\t\t\t     **           ");
                printf("\n\t\t\t      **          ");
                printf("\n\t\t\t       *******          ");
                printf("\n\t\t\t        *******   ");
                          for(i=0;i<=10;i++)
                 {
                      system("color a");
                      printf("\a");
                      system("color b");
                      printf("\a");
                      system("color c");
                      printf("\a");
                      system("color c");

                 }
    do{
            system("cls");

            couleur(10,1);
     printf("\n||-------------------------------------------------------------------------||\n");
       printf("||-------------------------------------------------------------------------||\n");
       printf("||                                                                         ||\n");
	   printf("||  1:ENREGISTREMENT DES ETUDIANTS                                         ||\n");
       printf("||                                                                         ||\n");
	   printf("||  2:montant global de l'allocation des etudes                            ||\n");
       printf("||                                                                         ||\n");
	   printf("||  3:la part en pourcentage des ETUDIANT comparer a celle des ETUDIANTES  ||\n");
       printf("||                                                                         ||\n");
       printf("||  4:ETUDIANTS boursiers dans  l'ordre decroissant                        ||\n");
       printf("||                                                                         ||\n");
       printf("||  5:COPYRIGHT                                                            ||\n");
       printf("||                                                                         ||\n");
       printf("||  6:RECHERCHE PAR INE                                                    ||\n");
       printf("||                                                                         ||\n");
       printf("||  0:POUR QUITTER                                                         ||\n");
       printf("||                                                                         ||\n");
       printf("||-------------------------------------------------------------------------||\n");
       printf("||-------------------------------------------------------------------------||\n");
      couleur(6,0); printf("\n\t\t\tpatientez!");
      for(int j=0;j<5;j++)
      {
          printf("°");
          Sleep(1000);
      }
      ;printf("\n\t\t\t\t\tchoix:");


        do{
        fflush(stdin);
       verifi = scanf("%d",&r);
       if(verifi != 1||r>6||r<0)
       {
       couleur(12,0);	 printf("erreur \n");
       couleur(10,1); printf("choix:");
	   }

       }while(verifi != 1||r>6||r<0);

        	    switch(r){
		case 1:
		          printf("\nsaisir le nombre d'etudiant ");
  do{
	   	 fflush(stdin);
          verifi=scanf("%d",&n);
       if(verifi!=1 || n==0 )
       {
       	couleur(12,0);printf("\nerreur ! \n");
       	couleur(10,1);printf("saisir un autre nombre ");
	   }

        }while(verifi!=1||  n==0);
        	    e=(etudiant*)malloc(n*sizeof(etudiant));
        	    saisi(e,n);
        	     printf("\n\tTAPEZ SUR UNE TOUCHE POUR RETOURNER AU MENU PRINCIPAL:\n");getch();
        	     break;
        case 2:
        		couleur(5,0);
             	system("cls");
	            montant_global(e,n);

        	    printf("\n\tTAPEZ SUR UNE TOUCHE POUR RETOURNER AU MENU PRINCIPAL:\n");getch();
        	    break;

        case 3:
                couleur(10,0);
	            system("cls");
              	pourcentage(e,n);
				printf("\n\tTAPEZ SUR UNE TOUCHE POUR RETOURNER AU MENU PRINCIPAL:\n");getch();
				break;
        case 4:
                couleur(10,0);
                system("cls");
                tri(e,n);

				 printf("\n\tTAPEZ SUR UNE TOUCHE POUR RETOURNER AU MENU PRINCIPAL:\n");getch();
				  break;
       case 5:
             	couleur(10,0);
	            system("cls");
	           copyright(); getch();
	           break;
	   case 6:
	            couleur(10,0);
                system("cls");
                recherche(e,n);
                printf("\n\tTAPEZ SUR UNE TOUCHE POUR RETOURNER AU MENU PRINCIPAL:\n");getch();
                getch();break;
        default :break;
		   }
		   }while((r<=6) && (r>0));
		   couleur(10,1);fin();
       	return 0;
		}


