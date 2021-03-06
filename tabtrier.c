#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

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

int quickSort(int *tableau, int p, int r) {
    int q;
    if (p < r) {
        q = partitionner(tableau, p, r);
        quickSort(tableau, p, q);
        quickSort(tableau, q+1, r);
    }
    return *tableau;
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



int tabtrier(int tab[], int taille){
  tab = quickSort(tab,0,taille);
  return tab;
}



void trisel(int tai){

	srand(time(NULL));

	int i;

	int tableau[tai];

	for(i=0; i<tai; i++){
		tableau[i]=rand()%100;
	}

  tableau=tabtrier(tableau,tai);

	// afftab(tableau,tai);
  tri_selection(tableau,tai);
// afftab(tableau,tai);
}



void trirap(int tai){

	srand(time(NULL));
  int p=0;
	int i;
  int tableau[tai];

	for(i=0; i<tai; i++){
		tableau[i]=rand()%100;
	}
	//afftab(tableau,r);
	quickSort(tableau, p, tai);
	//afftab(tableau,r);
}




int main(int argv,char**argc){

    int tai;
    double Trap,Tsel,t1,t2;


    printf(" tai\n");


    sscanf(argc[1],"%d", &tai);
    int i;

    printf("%d\n",tai);

    FILE* fichier = NULL;
    fichier = fopen("test.txt", "w");

    for(i=0;i<500 ;i++){

      printf("Tour %d \n", i+1);
      t1=(double)clock()/CLOCKS_PER_SEC;
      trirap(tai);
      t2=(double)clock()/CLOCKS_PER_SEC;
      Trap=Trap + (t2-t1);
      fprintf(fichier,"%f ", Trap/(i+1));

      t1=(double)clock()/CLOCKS_PER_SEC;
      trisel(tai);
      t2=(double)clock()/CLOCKS_PER_SEC;
      Tsel= Tsel + (t2-t1);
      fprintf(fichier,"%f\n", Tsel/(i+1));
    }
    printf("\n Les tris ont pris %f s au total \n",Trap+Tsel);
    printf("\n Le tri rapide a pris %f s et le tri sel a pris %f s \n",Trap/20,Tsel/20);
    return 0;
}
