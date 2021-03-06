#define GNUPLOT_PATH "/usr/bin/gnuplot"
#define TRUE 1
#define FALSE 0
#include <stdlib.h> 
#include <stdio.h> /* para printf*/
#include <malloc.h> 
#include <time.h>  /*Tiempo*/

enum {IZQUIERDO, DERECHO};


typedef struct _nodo {
   int dato;
   int FE;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
   struct _nodo *padre;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *AVL;
void Insertar_AVL(AVL *a, int dat);
void Borrar_AVL(AVL *a, int dat);
int Buscar_AVL(AVL a, int dat);
int AVL_empy(AVL r);
int EsHoja(pNodo r);
int Cantidad_nodos(AVL a, int* c);
int Altura_AVL(AVL a, int* altura);
int Altura(AVL a, int dat);
void Recorrido_enOrden(AVL, void (*func)(int*));
void Recorrido_preOrden(AVL, void (*func)(int*));
void Recorrido_postOrden(AVL, void (*func)(int*));
void Equilibrar_AVL(AVL *raiz, pNodo nodo, int, int);
void RSI(AVL *raiz, pNodo nodo);
void RSD(AVL *raiz, pNodo nodo);
void RDI(AVL *raiz, pNodo nodo);
void RDD(AVL *raiz, pNodo nodo);
void Vaciar_AVL(AVL *a);
void auxContador(AVL a, int*);
void auxAltura(AVL a, int, int*);
void Mostrar(int *d);
void mostrar_Array();
void mostrar_Array1();
void mostrar_Array2();
void graficar();
float tiempoCargaAVL;
float tiempoRecorrido;
float tiempoRecorridoLista;
float tiempoCargaLista;
float tiempoOrdenQuick;
float tiempoOrdenBurbuja;
int tamanoL;
int tamanopredefinidolista;


int *lista;
	int *listaBurbuja;
int main()
{
   AVL AVLInt=NULL;
   int altura;
   int nnodos;
   int cargo=0;
   int opcion;
   tamanopredefinidolista=0;
		char palabra[100];
	system("clear");
	url:
	printf("Ingrese  la ruta de su archivo  \n");
	printf("Ejemplo /home/erick/Desktop/Practica2_EDD/prueba1.txt  \n");	
	scanf("%s",palabra); 
	int numero;
	FILE *fp,*fp2;
	fp = fopen ( palabra, "r" ); 
	fp2 = fopen ( palabra, "r" );        
	if (fp==NULL) 
	{
		fputs (" Archivo no cargado,\n verificar el path del archivo.\n",stderr); 
		goto url;		
		//exit (1);
	}
	else
	{
		int contrl=0;
		char caracter[100];
   clock_t start = clock(); 

		while (feof(fp) == 0)
		{
			fgets(caracter,100,fp);
			numero=atoi(caracter);
			Insertar_AVL(&AVLInt, numero);
			tamanopredefinidolista++;
		}
	tiempoCargaAVL=(double)clock() - start / CLOCKS_PER_SEC;

lista=malloc(tamanopredefinidolista*sizeof(int));
listaBurbuja=malloc(tamanopredefinidolista*sizeof(int));
char cara[100];
   clock_t startVector = clock();
int n;
       int contado=0;
		while (feof(fp2) == 0)
		{
			fgets(cara,100,fp2);
			n=atoi(cara);
			lista[contado]=n;
			contado++;
//			printf("\n : %d",n);
		}
	tiempoCargaLista=(double)clock() - startVector / CLOCKS_PER_SEC;
listaBurbuja=lista;


		/*printf("\u2714 Carga exitosa.");*/
		cargo=1;
printf("Cantidad de Nodos %d :",Cantidad_nodos(AVLInt, &nnodos));
		printf("Se carg� correctamente el archivo\n");
		//agregarAlista();
	}
	menu:	
	if(cargo==1)
	{
		printf("**Ingrese el numero de la opcion que desee      ** \n");
		printf("**1.ver tiempos de carga y Equilibrado          ** \n");
		printf("**2.Ver Recorrido AVL           **\n");
		printf("**3.Ver Contendio del  Vector          **\n");
		printf("**4.Mostrar Graficas                  **\n");
		printf("**5.Ordenar Por QuickSort             **\n");
		printf("**6.Ordenar por Burbuja               **\n");
		printf("**0. salir                            **\n");
	
		scanf("%d",&opcion); 
		
	}
	switch(opcion)
	{
		case 0:
			
				goto menu;
			
			
		break;
		case 1:
				 system("clear");
				 printf("\n***AVL\n");
			         printf("\t->Tiempo transcurrido: %f",tiempoCargaAVL,"\n");
				 printf("\n***Vector\n");
				 printf("\t->Tiempo transcurrido: %f",tiempoCargaLista,"\n");
   				 goto menu;
							
		break;
		case 2:
			system("clear");
			clock_t startA = clock(); 
			Recorrido_enOrden(AVLInt, Mostrar);
				tiempoRecorrido=(double)clock() - startA / CLOCKS_PER_SEC;
			 	 printf("\n***Tiempo Recorrido en Orden\n");
				 printf("\t->Tiempo transcurrido: %f",tiempoRecorrido,"\n");
				 
				goto menu;
				break;
		case 3:
			system("clear");
			printf("***Recorrido de arreglo\n\t");
			clock_t startl = clock(); 
			//mostrarInicio();
			mostrar_Array1();
			tiempoRecorridoLista=(double)clock() - startl / CLOCKS_PER_SEC;
			 printf("\n***Tiempo Recorrido en Orden\n");
				 printf("\t->Tiempo transcurrido: %f",tiempoRecorridoLista,"\n");
				
				goto menu;
							
		break;
		case 4:
			graficar();
		break;
		case 5:
			system("clear");			
			clock_t start5 = clock();
			quickSort();
			tiempoOrdenQuick=(double)clock() - start5 / CLOCKS_PER_SEC;
			//system("clear");
			printf("\nResultado\n");
			int cnt;
			mostrar_Array1();
			printf("\nEl tiempo demorado en ordenarpor QuickSort:%f ",tiempoOrdenQuick);
			goto menu;
			
		break;
		case 6:/**ordenar Burbuja*/
			
			clock_t start4 = clock();
			ordenarBurbuja();
			tiempoOrdenQuick=(double)clock() - start4 / CLOCKS_PER_SEC;
			mostrar_Array2();
			printf("\nEl tiempo demorado en ordenar QuickSort:%f ",tiempoOrdenQuick);
			goto menu;
		break;
	}
	
	fclose(fp);   

   return 0;
}
void Vaciar_AVL(AVL *a)
{
   if(*a) {
      Vaciar_AVL(&(*a)->izquierdo);
      Vaciar_AVL(&(*a)->derecho);  
      free(*a);              
      *a = NULL;
   }
}

void Insertar_AVL(AVL *a, int dat)
{

   pNodo padre = NULL;
   pNodo actual = *a;

   while(!AVL_empy(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }

   if(!AVL_empy(actual)) return;
   if(AVL_empy(padre)) {
      *a = (AVL)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
      (*a)->padre = NULL;
      (*a)->FE = 0;
   }
   else if(dat < padre->dato) {
      actual = (AVL)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
      actual->padre = padre;
      actual->FE = 0;
      Equilibrar_AVL(a, padre, IZQUIERDO, TRUE);
   }

   else if(dat > padre->dato) {
      actual = (AVL)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
      actual->padre = padre;
      actual->FE = 0;
      Equilibrar_AVL(a, padre, DERECHO, TRUE);
  }

}

void Equilibrar_AVL(AVL *a, pNodo nodo, int rama, int nuevo)
{
   int salir = FALSE;

   while(nodo && !salir) {
      if(nuevo)
         if(rama == IZQUIERDO) nodo->FE--;
         else                  nodo->FE++;
      else
         if(rama == IZQUIERDO) nodo->FE++;
         else                  nodo->FE--;
      if(nodo->FE == 0) salir = TRUE; 
      else if(nodo->FE == -2) { 
         if(nodo->izquierdo->FE == 1) RDD(a, nodo); 
         else RSD(a, nodo);                         
         salir = TRUE;
      }
      else if(nodo->FE == 2) {  
         if(nodo->derecho->FE == -1) RDI(a, nodo); 
         else RSI(a, nodo);                        
         salir = TRUE;
      }
      if(nodo->padre)
         if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
      nodo = nodo->padre;
   }
}

void RDD(AVL *raiz, AVL nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->izquierdo;
   pNodo R = Q->derecho;
   pNodo B = R->izquierdo;
   pNodo C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else *raiz = R;

   Q->derecho = B;
   P->izquierdo = C;
   R->izquierdo = Q;
   R->derecho = P;

   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = Q;
   if(C) C->padre = P;

   switch(R->FE) {
      case -1: Q->FE = 0; P->FE = 1; break;
      case 0:  Q->FE = 0; P->FE = 0; break;
      case 1:  Q->FE = -1; P->FE = 0; break;
   }
   R->FE = 0;
}


void RDI(AVL *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->derecho;
   pNodo R = Q->izquierdo;
   pNodo B = R->izquierdo;
   pNodo C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else *a = R;

   P->derecho = B;
   Q->izquierdo = C;
   R->izquierdo = P;
   R->derecho = Q;

   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = P;
   if(C) C->padre = Q;

   switch(R->FE) {
      case -1: P->FE = 0; Q->FE = 1; break;
      case 0:  P->FE = 0; Q->FE = 0; break;
      case 1:  P->FE = -1; Q->FE = 0; break;
   }
   R->FE = 0;
}

void RSD(AVL *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->izquierdo;
   pNodo B = Q->derecho;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else *a = Q;


   P->izquierdo = B;
   Q->derecho = P;

   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   P->FE = 0;
   Q->FE = 0;
}

void RSI(AVL *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->derecho;
   pNodo B = Q->izquierdo;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else *a = Q;

   P->derecho = B;
   Q->izquierdo = P;

   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   P->FE = 0;
   Q->FE = 0;
}

void Borrar_AVL(AVL *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;

   actual = *a;
   while(!AVL_empy(actual)) {
      if(dat == actual->dato) { 
         if(EsHoja(actual)) { 
            if(padre) 
               
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            free(actual);
            actual = NULL;
            if((padre->derecho == actual && padre->FE == 1) ||
               (padre->izquierdo == actual && padre->FE == -1)) {
               padre->FE = 0;
               actual = padre;
               padre = actual->padre;
            }
            if(padre)
               if(padre->derecho == actual) Equilibrar_AVL(a, padre, DERECHO, FALSE);
               else                         Equilibrar_AVL(a, padre, IZQUIERDO, FALSE);
            return;
         }
         else { 
            padre = actual;
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { 
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

void Recorrido_enOrden(AVL a, void (*func)(int*))
{
   if(a->izquierdo) Recorrido_enOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) Recorrido_enOrden(a->derecho, func);
}


void Recorrido_preOrden(AVL a, void (*func)(int*))
{
   func(&a->dato);
   if(a->izquierdo) Recorrido_preOrden(a->izquierdo, func);
   if(a->derecho) Recorrido_preOrden(a->derecho, func);
}


void Recorrido_postOrden(AVL a, void (*func)(int*))
{
   if(a->izquierdo) Recorrido_postOrden(a->izquierdo, func);
   if(a->derecho) Recorrido_postOrden(a->derecho, func);
   func(&a->dato);
}

int Buscar_AVL(AVL a, int dat)
{
   pNodo actual = a;
   while(!AVL_empy(actual)) {
      if(dat == actual->dato) return TRUE; 
      else if(dat < actual->dato) actual = actual->izquierdo; 
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE; 
}

int Altura(AVL a, int dat)
{
   int altura = 0;
   pNodo actual = a;

   while(!AVL_empy(actual)) {
      if(dat == actual->dato) return altura;
      else {
         altura++; 
         if(dat < actual->dato) actual = actual->izquierdo;
         else if(dat > actual->dato) actual = actual->derecho;
      }
   }
   return -1; 
}


int Cantidad_nodos(AVL a, int *contador)
{
   *contador = 0;

   auxContador(a, contador);
   return *contador;
}


void auxContador(AVL nodo, int *c)
{
   (*c)++;
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

int Altura_AVL(AVL a, int *altura)
{
   *altura = 0;

   auxAltura(a, 0, altura); 
   return *altura;
}

void auxAltura(pNodo nodo, int a, int *altura)
{
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

int AVL_empy(AVL r)
{
   return r==NULL;
}


int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}


void Mostrar(int *d)
{
   printf("%d, ", *d);
}
void mostrar_Array()
{
	int w,xq;
	for(w=0;w<tamanopredefinidolista;w++)
	{
		xq=lista[w];
	}
}

void mostrar_Array1()
{
	int w,xq;
	for(w=0;w<tamanopredefinidolista;w++)
	{
		printf(", %d",lista[w]);
	}

}
void mostrar_Array2()
{
	int w,xq;
	for(w=0;w<tamanopredefinidolista;w++)
	{
		printf(", %d",listaBurbuja[w]);
	}

}

void graficar()
{
	FILE *gp;
	gp = popen(GNUPLOT_PATH, "w");
	if(gp == NULL)
	{
		fprintf(stderr, "Oops, I can't find %s.", GNUPLOT_PATH);
        }
	fprintf(gp, "set title \"Function A\" \n");

	fprintf(gp, "plot [-512:512] y(x)=a+b*x+c*x*x");
	fflush(gp);

	getchar();
	pclose(gp);
}

