#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void titre();
void Menu();
int AjouteUnCompte(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n);
void Operation(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n);
void affichages(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n);
void trieascendent(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n);
void trieDescendant(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n);
void Ascendant(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n,double K);
void rechirche(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n,char CN[10]);
void Fidilisation(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n);


int main()
{
        char Cin[100][10],Nom[100][15],PreN[100][15],CN[10];
        double Mont[100],K;
        int x,n=0;

   do{
        do{
            titre();
            Menu();
    scanf("%d",&x);
    system("cls");
    }while(x<1 || x>6);

    switch(x)
    {
    case 1:
        titre();
        n = AjouteUnCompte(Cin,PreN,Nom,Mont,n);
        system("cls");
        break;
   case 2:
       titre();
        int i,z;
         do{ printf("Tapez le nombre de comptes que vous souhaitez ajouter   :\n");
          scanf("%d",&z);
          system("cls");
         }while(z<0);
        for(i=0;i<z;i++)
        {
            titre();
            printf("ajouter clien N: %d\n",i+1);
        n = AjouteUnCompte(Cin,PreN,Nom,Mont,n);
          system("cls");
            }

       break;
    case 3:
        if(n!=0)
        {titre();
        Operation(Cin,PreN,Nom,Mont,n);
        system("cls");}else{
            titre();
        printf("Pas de compte\n");
        system("pause");
        system("cls");
        }
        break;
    case 4:
        if(n!=0)
    {
        titre();
        printf("1   :trie par ordre ascendant.\n");
        printf("2   :trie par ordre descendant.\n");
        printf("3   :Par Ordre Ascendant (les comptes bancaire ayant un montant superieur a un chiffre introduit).\n");
        printf("4   :Par Ordre Descendant (les comptes bancaire ayant un montant superieur a un chiffre introduit).\n");
        printf("5   :rechirche \n");

        int q;
        do{scanf("%d",&q);
        }while(q<1 || q>5);
        switch(q)
        {
        case 1:
            trieascendent(Cin,PreN,Nom,Mont,n);
            affichages(Cin,PreN,Nom,Mont,n);
            system("cls");
            break;
        case 2:
            trieDescendant(Cin,PreN,Nom,Mont,n);
            affichages(Cin,PreN,Nom,Mont,n);
            system("cls");
            break;
        case 3:
            printf("ecrire le montant  afiche les comptes bancaire ayant un montant superieur");
            scanf("%lf",&K);
            trieascendent(Cin,PreN,Nom,Mont,n);
            Ascendant(Cin,PreN,Nom,Mont,n,K);
            system("cls");
            break;
        case 4:
            printf("ecrire le montant  afiche les comptes bancaire ayant un montant superieur");
            scanf("%lf",&K);
            trieDescendant(Cin,PreN,Nom,Mont,n);
            Ascendant(Cin,PreN,Nom,Mont,n,K);
            system("cls");
            break;
        case 5:
            printf("ecrir un CIN que tu veux rechercher :\n");
            scanf("%s",CN);
            rechirche(Cin,PreN,Nom,Mont,n,CN);
            break;

        }
        system("cls");
    }else{
            titre();
        printf("Pas de compte\n");
        system("pause");
        system("cls");
        }
        break;
   case 5:
       trieascendent(Cin,PreN,Nom,Mont,n);
       Fidilisation(Cin,PreN,Nom,Mont,n);

    }
   }while(x!=6);


    return 0;
}

void titre()
    {
    printf("\t\t\t\t\tGestion Bancaire");
    printf("\n\n\n");
    }

void Menu()
    {
     printf("Menu :\n");
     printf("1  :Introduire un compte bancaire.\n");
     printf("2  :Introduir plusieurs comptes bancaires.\n");
     printf("3  :Operation.\n");
     printf("4  :Affichage.\n");
     printf("5  :Fidilisation.\n");
     printf("6   :Quitter l'application.\n");
    }

int AjouteUnCompte(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n)
    {
        printf("ajoutez un Cin de personne :\t");
        scanf("%s",cin[n]);
        printf("ajoutez un Nom de personne :\t");
        scanf("%s",nom[n]);
        printf("ajoutez un Prenom de personne :\t");
        scanf("%s",Pre[n]);
        printf("ajoutez le Montant  :\t");
        scanf("%lf",&M[n]);
        n++;

        return n;
    }






void Operation(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n)
{   int s,i,f;
    double Mr;

        for(i=0;i<n;i++)
        {
            printf("%d  :%s  %s  %s    :%.2f\n",i+1,Pre[i],nom[i],cin[i],M[i]);
        }
        do{ printf("Choisissez le numéro de la personne :");

        scanf("%d",&f);
        }while(f<1 || f>n);


        printf("1   :Retrait\n2 :Depot\n");
        scanf("%d",&s);

        if(s==1)
        {
            printf("Entrez le montant que vous souhaitez retirer\n");
            scanf("%lf",&Mr);
            if(Mr>M[f-1])
            {
                printf("Desole, le montant sur le compte n'est pas suffisant\n");
                system("pause");
            }else{
            M[f-1]=M[f-1]-Mr;
                }
            }else if(s==2)
            {   printf("Entrez le montant que vous souhaitez depot\n");
            scanf("%lf",&Mr);
                M[f-1]=M[f-1]+Mr;
            }

}



void affichages(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n)
{   int i;



        for(i=0;i<n;i++)
        {
        printf("%d  %s  %s  %s  :%.2f DH  \n",i+1,nom[i],Pre[i],cin[i],M[i]);
        }
        system("pause");
}




void trieascendent(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n)
{   int i,j;
    double T;
    char A[15];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
           if(M[i]<M[j])
           {
             T=M[i];
             M[i]=M[j];
             M[j]=T;

             strcpy(A,Pre[j]);
             strcpy(Pre[j],Pre[i]);
             strcpy(Pre[i],A);

              strcpy(A,nom[j]);
             strcpy(nom[j],nom[i]);
             strcpy(nom[i],A);

              strcpy(A,cin[j]);
             strcpy(cin[j],cin[i]);
             strcpy(cin[i],A);


           }

        }
    }


}

void trieDescendant(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n)
{

    int i,j;
    double T;
    char A[15];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
           if(M[i]>M[j])
           {
             T=M[i];
             M[i]=M[j];
             M[j]=T;

             strcpy(A,Pre[j]);
             strcpy(Pre[j],Pre[i]);
             strcpy(Pre[i],A);

              strcpy(A,nom[j]);
             strcpy(nom[j],nom[i]);
             strcpy(nom[i],A);

              strcpy(A,cin[j]);
             strcpy(cin[j],cin[i]);
             strcpy(cin[i],A);


           }

        }
    }


}

void Ascendant(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n,double K)
{   int i;



        for(i=0;i<n;i++)
        {   if(M[i]>K)
            {

        printf("%d\t%s\t%s\t%s\t:%.2f DH  \n",i+1,nom[i],Pre[i],cin[i],M[i]);
            }
        }
        system("pause");
}


void rechirche(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n,char CN[10])
{   int i,j=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(cin[i],CN)== 0)
        {
         printf("%s\t%s\t%s\t %.2f DH\n", cin[i],nom[i],Pre[i],M[i]);
        j++;
        }
    }
    if(j==0){
                printf("un persone non trouve\n");
           }
   system("pause");

}

void Fidilisation(char cin[100][10],char Pre[100][15],char nom[100][15],double M[100],int n)
{   int i,K=3;
    double j;
    for(i=0;i<K;i++)
    {
        if(M[i]=M[i+1])
        {
            K++;
        }

        j=(M[i]*1,3)/100;
        M[i]=M[i]+j;

    }
    printf("1.3% aux comptes ayant les 3 premiers montants supérieurs\n");
    for(i=0;i<K;i++)
        {
            printf("%d  %s  %s  %s  :%.2f DH   \n",i+1,nom[i],Pre[i],cin[i],M[i]);
        }

}






