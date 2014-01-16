#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **tab; int n,i,j,k,occ,colonne=1,colonneSuiv=1;
    printf("Jusqu'a quel rang voulez vous l'affichage ? ");
    scanf("%d",&n);printf("\n");
    tab=malloc(n*sizeof(int));
    tab[0]=malloc(colonne*sizeof(int*));

    // ...
    tab[0][0]=1;printf("\n%d\n",tab[0][0]);
    for (i=0;i<n;i++){
        colonne=colonneSuiv;
        colonneSuiv=0;
        k=0;
        j=-1;  //car occ++ est avant le premier test de la boucle do...while
        do{
            occ=0;
            do  {  //compte le nombre de 1,2,ou 3 successifs
                occ++;
                j++;
            }while(tab[i][j]==tab[i][j+1] && j+1<colonne);
            colonneSuiv+=2;
            if (i+1!=n){ //remplit et affiche la ligne suivante
                if (colonneSuiv==2)tab[i+1]=malloc(colonneSuiv*sizeof(int*));
                else tab[i+1]=realloc(tab[i+1],colonneSuiv*sizeof(int*));
                tab[i+1][k]=occ; printf("%d  ",tab[i+1][k]);
                tab[i+1][k+1]=tab[i][j]; printf("%d  ",tab[i+1][k+1]);
                k+=2;
                }
        }while(j+1<colonne);
        printf("\n");
    }
    // ...

    for(i=0;i<n;i++){ //libere la memoire
        free(tab[i]);
    }
    free(tab);
    return 0;
}
