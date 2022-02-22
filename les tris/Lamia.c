#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MILLI_S 1000.0

typedef long *array;
array A;
array Tmp;

/*********** Procedure afficher ************/ 
void afficher_tab(long *tab,int n){
	long i;
      for (i = 0; i < n; i++){
      	printf("%ld \t", tab[i]);
	  }
	
}
/*********** Procedure Permuter ************/
void Permuter(long* x,long* y) //permuter deux valeurs
  {
              long z=*x;
              *x=*y;
              *y=z;
  }
  
/**********************    1 . Tri เ bulles :	  *******************************/
/*********** Procedure TriBulle ************/ 
void TriBulle (long* T,long n)
  {long i;
           int changement=1;
           while(changement==1)
      {
                    changement=0;
                  for(i=0;i<n-1;i++)
                                      if (T[i]>T[i+1])
                {
                                                Permuter(&T[i],&T[i+1]);
                                                changement=1;
                }
    }
}

/*********** Procedure TriBulleOpt ************/
void TriBulleOpt (long* T,long n)
 {int i;
             long m=n-1;
             int changement=1;
             while(changement==1)
     {
                      changement=0;
                      for( i=0;i<m;i++)
                                         if (T[i]>T[i+1])
                {
 Permuter(&T[i],&T[i+1]);
                                                changement=1;
                }
                   m--;
    }
 }

/*******************************    2 . Tri Gnome :	  *******************************/
void TriGnome (long* T,long n)
 {  
             long i=0;
             while(i<n-1)
     {
                      if (T[i]<=T[i+1]){
                      	   i++;  
					  }
             
                      else
        {
                                                  Permuter(&T[i],&T[i+1]);
                                             
                                                  if(i!=0)
                             i--;
                  else
                            i++;
        }
    } 
} 
 

/*******************************    3 .  Tri par distribution :	  *******************************/
/*********** Fonction cle ************/ 
long cle(long x,long i) //retourner la cl้ i d’une valeur x
 {long j,r;
             for (j=1; j<=i; j++){
             	 r=x%10;
                        x=x/10;
			 }
                       
             return r ;
 }    
/*********** Procedure TriAux ************/ 
void TriAux (long *T,long n,long i)    //tri d’un tableau par la i่me cl้
 { 
 long j, m,indice,l; 
   long *tab=(long *)malloc((n+1)*sizeof(long));
      long *k=(long *)malloc((n+1)*sizeof(long));
 	 indice=0;
    for(j=0;j<n;j++){
        k[j]=cle(T[j],i);   
	}        
          for(j=0;j<10;j++){
          	
            for(m=0;m<n;m++){
            	if(k[m]==j){ 
            	 
				   tab[indice]=T[m];  
				   indice=indice+1;	   
		     	 }  
			}    
		  }	 
            for(m=0;m<n;m++){
            T[m]=tab[m]; 
		 
			}  
 }
  
/*********** Procedure TriBase ************/ 
 void TriBase(long* T,long n,long k)
{ long i;
          for (i=1; i<=k; i++) {
               TriAux(T, n, i);
                               }
}

/*******************************  4 . Tri rapide :	  *******************************/
void triRapide (long* tab,long p,long r)
 {
            long q;
                      if(p<r)
         {
                               q=partitionner(tab,p,r);
                               triRapide(tab,p,q-1);
                               triRapide(tab,q+1,r);
         }
}
/*********** Fonction partitionner ************/
 int partitionner(long* tab,long d,long f)
{ //mettre chaque ้l้ment เ gauche ou เ droite de pivot
          long eltPivot;
          int i,j,x;
          eltPivot=tab[(d+f)/2];
          i=d;
          j=f+1;
          do
    {
                    do{
                             i++;
                    }while(tab[i]<eltPivot && i<=f);

                    do{
                             j--;
                   }while(tab[j]>eltPivot);

                    if(i<j)
        {
         x=tab[i];
                           tab[i]=tab[j];
                           tab[j]=x;
        }
          }while(j>i);

          tab[d]=tab[j];
          tab[j]=eltPivot;

           return j;
		   
		   }
		   
/**********************   5 . Tri par tas :	  *******************************/ 
/*********** Procedure inserer_dans_tas  ************/
  void inserer_dans_tas(long *arr, long n, long i) {
   
    long largest = i;
    long left = 2 * i + 1;
    long right = 2 * i + 2;
  
    if (left < n && arr[left] < arr[largest])
      largest = left;
  
    if (right < n && arr[right] < arr[largest])
      largest = right;
 
    if (largest != i) {
      Permuter(&arr[i], &arr[largest]);
      inserer_dans_tas(arr, n, largest);
    }
  }  
/*********** Procedure supprime_min  ************/   
void supprime_min (long *arr, long n) {  
 
   long i;
    for (i = n - 1; i >= 0; i--) {
      Permuter(&arr[0], &arr[i]);
   
      inserer_dans_tas(arr, i, 0);
    }
    
  }
/*********** Procedure Tri_Tas ************/    
  void Tri_Tas(long *arr, long n) {
  	long i;
    
    for (i = n / 2 - 1; i >= 0; i--)
    {
      inserer_dans_tas(arr, n, i);
	}
	
   supprime_min ( arr, n);
  
  }




int Menu()		
{
	int Choix;
	do
	{
	
		printf("                             ษออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("                             บ                                                      บ\n");
		printf("                             บ                    Menu Principal                    บ\n");
		printf("                             บ                                                      บ\n");
		printf("                             ศออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
		printf("\n                      Veuillez choisir un Algorithme de tri, Tapez :\n");
		printf("\n                               1- Tri a bulles");
		printf("\n                               2- Tri a bulles Optimal");
		printf("\n                               3- Tri gnome");
		printf("\n                               4- Tri par distribution");
		printf("\n                               5- Tri rapide");
		printf("\n                               6- Tri par Tas");
		printf("\n                               7- Quitter\n");
		printf("\n\n\n\nChoix :");
		scanf("%d",&Choix);
	} while (Choix <1 || Choix >7);
	return Choix;
}

 

int main()
 {    	printf("\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>      Ce Projet est realise par:  GUEDOUDJ LAMIA      <<<<<<<<<<<<<<<<<<\n");	
		printf("  \n");
		printf("\n\n\n");
	    LARGE_INTEGER deb, fin, freq;
            int cas; 
            long var;
            long i,j; 	
			int Choix;
            long tab_val[]={ pow(10,3),2*pow(10,3),3*pow(10,3),4*pow(10,3),5*pow(10,3),6*pow(10,3),7* pow(10,3),8*pow(10,3),
			9*pow(10,3),10*pow(10,3) ,20*pow(10,3) ,30*pow(10,3) ,40*pow(10,3) ,50*pow(10,3),100*pow(10,3)}; 
      
       	Choix = Menu();
       		while (Choix!=7)
	{       	printf("\n        Veuillez choisir un cas de tri, Tapez :\n");
		        printf("\n                 1- Meilleur cas");
		        printf("\n                 2- Pire cas");
        	    printf("\n\n\nCas :");
         		scanf("%d",&cas);                            
           for (i=0;i<15;i++)
          {      long *tab=(long *)malloc((tab_val[i]+1)*sizeof(long));

                    switch(cas)
        {
                   case 1:
                             var=1;
                             for (j=0;j<tab_val[i];j++)
                             {tab[j]=var; var++;}
                             break;
                    case 2:
                             var=tab_val[i];
                             for (j=0;j<tab_val[i];j++)
                             {tab[j]=var; var--;}
                             break;
        }
                    QueryPerformanceFrequency(&freq);
                    QueryPerformanceCounter(&deb);
                      
					   switch(Choix)
        {
                    case 1:
                             TriBulle(tab,tab_val[i]);
                             break;
                    case 2:
                    	    TriBulleOpt(tab,tab_val[i]);
                            break;
                    case 3:   
                             TriGnome(tab,tab_val[i]); 
                             break;
                      case 4:
                            TriBase(tab,tab_val[i],5);  
                            break; 
                    case 5:
                    	    triRapide(tab,0,tab_val[i]-1);
                            break;
                    case 6:  
                             Tri_Tas(tab, tab_val[i]); 
                             break; 
        }
           QueryPerformanceCounter(&fin);
          double delta=(MILLI_S * (fin.QuadPart - deb.QuadPart)) / freq.QuadPart;
                    printf("T[%ld]\t=\t%3.2lf ms \n",tab_val[i],delta);    
	}
		printf("\n\n\n\n\n Appuyez sur une touche pour retourner au menu principal  ");	
							getch(); 
	  system("cls"); //efface l'้cran
            	Choix=Menu();  
	}	 return 0;
 }
