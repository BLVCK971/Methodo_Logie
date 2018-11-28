#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int *T;


int partitionner(int *tableau, int p, int r) {
    int pivot = tableau[p], i = p-1, j = r+1;
    int temp;
    while (1) {
        do
            j--;
        while (tableau[j] > pivot);
        do
            i++;
        while (tableau[i] < pivot);
        if (i < j) {
            temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
        }
        else
            return j;
    }
}

void quickSort(int *tableau, int p, int r) {
    int q;
    if (p < r) {
        q = partitionner(tableau, p, r);
        quickSort(tableau, p, q);
        quickSort(tableau, q+1, r);
    }
}

int max(int tab[], int taille)

{
    int i=0, indice_max=0;
    while(i < taille) {
	 if(tab[i] > tab[indice_max])
	 indice_max = i;
	 i++;
   }
    return indice_max;
}

void echanger(int tab[], int x, int y){
    int tmp;

    tmp = tab[x];

    tab[x] = tab[y];

    tab[y] = tmp;}



void tri_selection(int tab[], int taille){
    int indice_max;

    for(; taille > 1 ; taille--) // tant qu'il reste des éléments non triés
    {
        indice_max = max(tab, taille);

        echanger(tab, taille-1, indice_max); // on échange le dernier élément avec le plus grand
    }}



void afftab(int *t, int nom){
    	int i;
    	for(i=0; i< nom-1; i++){
    		printf("%d ",t[i]);

    }	printf("\n");
}




void trisel(int tai){

	int i;

	// afftab(tableau,tai);
  tri_selection(T,tai);
// afftab(tableau,tai);
}



void trirap(int tai){

  int p=0;
	int i;


	//afftab(tableau,r);
	quickSort(T, p, tai);
	//afftab(tableau,r);
}


void main(int argv,char**argc){

    int tai,nbruns;
    double Trap,Tsel,t1,t2,tst1,tst2,tt1,tt2;


    srand(time(NULL));

    //printf(" tai\n");


    sscanf(argc[1],"%d", &tai);
    sscanf(argc[2],"%d", &nbruns);

    int i,j;


    //printf("%d %d %s\n",tai,nbruns,argc[3]);
    //printf("%d\n",tai);

    FILE* fichier = NULL;
    fichier = fopen(argc[3], "w");


    T = (int*)malloc(sizeof(int)*tai);

    for(i=0;i<nbruns;i++){

      for(j=0; j<tai; j++) T[j]=rand()%100;

      t1=(double)clock()/CLOCKS_PER_SEC;
      trirap(tai);
      t2=(double)clock()/CLOCKS_PER_SEC;
      Trap=Trap + (t2-t1);

      for(j=0; j<tai; j++) T[j]=rand()%100;

      t1=(double)clock()/CLOCKS_PER_SEC;
      trisel(tai);
      t2=(double)clock()/CLOCKS_PER_SEC;
      Tsel= Tsel + (t2-t1);
    }

    for(j=0; j<tai; j++) T[j]=rand()%100;
    trirap(tai/2);

    printf("%f %f ",Trap/nbruns,Tsel/nbruns);

    Trap=0;
    Tsel=0;

    for(i=0;i<nbruns;i++){


      t1=(double)clock()/CLOCKS_PER_SEC;
      trirap(tai);
      t2=(double)clock()/CLOCKS_PER_SEC;
      Trap=Trap + (t2-t1);


      t1=(double)clock()/CLOCKS_PER_SEC;
      trisel(tai);
      t2=(double)clock()/CLOCKS_PER_SEC;
      Tsel= Tsel + (t2-t1);

    }
    printf("%f %f ",Trap/nbruns,Tsel/nbruns);

    Trap=0;
    Tsel=0;

    for(i=0;i<nbruns;i++){


      t1=(double)clock()/CLOCKS_PER_SEC;
      trirap(tai);
      t2=(double)clock()/CLOCKS_PER_SEC;
      Trap=Trap + (t2-t1);


      t1=(double)clock()/CLOCKS_PER_SEC;
      trisel(tai);
      t2=(double)clock()/CLOCKS_PER_SEC;
      Tsel= Tsel + (t2-t1);

    }
    printf("%f %f\n",Trap/nbruns,Tsel/nbruns);

    fclose(fichier);
    free(T);



}
