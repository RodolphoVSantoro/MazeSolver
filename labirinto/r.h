#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define Ke 1000
#define OVERFLOW 2147483647
#define D_OVERFLOW 9007199254740992.0
#define SI sizeof(int)
#define SD sizeof(double)
#define SC sizeof(char)
#define SF sizeof(float)
typedef unsigned long int lint;
#define SL sizeof(lint)

//pilha.h
	//structs
	struct listaInt
	{
		int info;
		struct listaInt* prox;
	};
	typedef struct listaInt ListaInt;

	struct listaFloat
	{
		float info;
		struct listaFloat* prox;
	};
	typedef struct listaFloat ListaFloat;

	struct listaChar
	{
		char info;
		struct listaChar* prox;
	};
	typedef struct listaChar ListaChar;

	struct pilhaF
	{
		ListaFloat* prim;
	};
	typedef struct pilhaF PilhaF;

	struct pilhaI
	{
		ListaInt* prim;
	};
	typedef struct pilhaI PilhaI;

	struct pilhaC
	{
		ListaChar* prim;
	};
	typedef struct pilhaC PilhaC;

	// Cria
	PilhaF* pilhaF_cria(void){
		PilhaF* p = (PilhaF*) malloc(sizeof(PilhaF));
		p->prim = NULL;
		return p;
	}

	PilhaI* pilhaI_cria(void){
		PilhaI* p = (PilhaI*) malloc(sizeof(PilhaI));
		p->prim = NULL;
		return p;
	}

	PilhaC* pilhaC_cria(void){
		PilhaC* p = (PilhaC*) malloc(sizeof(PilhaC));
		p->prim = NULL;
		return p;
	}

	//Push
	void pilhaF_push(PilhaF* p, float v){
		ListaFloat* n = (ListaFloat*) malloc(sizeof(ListaFloat));
		n->info = v;
	 	n->prox = p->prim;
		p->prim = n;
	}

	void pilhaI_push(PilhaI* p, int v){
		ListaInt* n = (ListaInt*) malloc(sizeof(ListaInt));
		n->info = v;
		n->prox = p->prim;
		p->prim = n;
	}
	void pilhaC_push(PilhaC* p, char v){
		ListaChar* n = (ListaChar*) malloc(sizeof(ListaChar));
		n->info = v;
		n->prox = p->prim;
		p->prim = n;
	}

	//pilha_vazia

	int pilhaF_vazia(PilhaF* p){
		if (p->prim == NULL)
			return 1;
		return 0;
	}

	int pilhaI_vazia(PilhaI* p){
		if (p->prim == NULL)
			return 1;
		return 0;
	}

	int pilhaC_vazia(PilhaC* p){
		if (p->prim == NULL)
			return 1;
		return 0;
	}


	//Pop
	float pilhaF_pop(PilhaF* p){
		ListaFloat* t;
		float v;
		if(pilhaF_vazia(p)){
			printf("Pilha vazia\n");
			exit(1);
		}
		t = p->prim;
		v = t->info;
		p->prim = t->prox;
		free(t);
		return v;
	}

	int pilhaI_pop(PilhaI* p){
		ListaInt* t;
		int v;
		if(pilhaI_vazia(p)){
			printf("Pilha vazia\n");
			exit(1);
		}
		t = p->prim;
		v = t->info;
		p->prim = t->prox;
		free(t);
		return v;
	}

	char pilhaC_pop(PilhaC* p){
		ListaChar* t;
		char v;
		if(pilhaC_vazia(p)){
			printf("Pilha vazia\n");
			exit(1);
		}
		t = p->prim;
		v = t->info;
		p->prim = t->prox;
		free(t);
		return v;
	}

	//pilha_libera
	void pilhaF_libera(PilhaF* p){
		ListaFloat* q = p->prim;
		while (q!=NULL){
			ListaFloat* t = q->prox;
			free(q);
			q = t;
		}
		free(p);
	}
	void pilhaI_libera(PilhaI* p){
		ListaInt* q = p->prim;
		while (q!=NULL){
			ListaInt* t = q->prox;
			free(q);
			q = t;
		}
		free(p);
	}
	void pilhaC_libera(PilhaC* p){
		ListaChar* q = p->prim;
		while (q!=NULL){
			ListaChar* t = q->prox;
			free(q);
			q = t;
		}
		free(p);
	}
	//imprimir

	void pilhaF_imprimir(PilhaF* p){
		ListaFloat *lst;
		for(lst=p->prim;lst!=NULL;lst=lst->prox){
			printf("%f\n", lst->info);	
		}
	}
	void pilhaI_imprimir(PilhaI* p){
		ListaInt *lst;
		for(lst=p->prim;lst!=NULL;lst=lst->prox){
			printf("%d\n", lst->info);	
		}
	}
	void pilhaC_imprimir(PilhaC* p){
		ListaChar *lst;
		for(lst=p->prim;lst!=NULL;lst=lst->prox){
			printf("%c\n", lst->info);	
		}
	}
	//pilha_ext
	PilhaF* pilhaF_inverter(PilhaF* p){
		PilhaF* aux = pilhaF_cria();
		while(!(pilhaF_vazia(p))){
			pilhaF_push(aux,pilhaF_pop(p));
		}
		return aux;
	}

	PilhaI* pilhaI_inverter(PilhaI* p){
		PilhaI* aux = pilhaI_cria();
		while(!(pilhaI_vazia(p))){
			pilhaI_push(aux,pilhaI_pop(p));
		}
		return aux;
	}

	PilhaC* pilhaC_inverter(PilhaC* p){
		PilhaC* aux = pilhaC_cria();
		while(!(pilhaC_vazia(p))){
			pilhaC_push(aux,pilhaC_pop(p));
		}
		return aux;
	}
//
//int functions
	int contDigit(int num)
	{
		int digitos = 0;
		char str[11];
		sprintf_s(str, "%d", num);
		while (str[digitos] != '\0')
		{
			digitos++;
		}
		return digitos;
	}

	int transfer_time(int *alvo, int *valores)
	{
		int *ptr_alvo = alvo, *ptr_v = valores;
		clock_t i = clock();
		while (*ptr_v != 0)
		{
			*ptr_alvo = *ptr_v;
			ptr_alvo++;
			ptr_v++;
		}
		*ptr_alvo = *ptr_v;
		return ((clock() - i) / CLOCKS_PER_SEC);
	}

	void transfer(int *alvo, int *valores)
	{
		int *ptr_alvo = alvo, *ptr_v = valores;
		while (*ptr_v != 0)
		{
			*ptr_alvo = *ptr_v;
			ptr_alvo++;
			ptr_v++;
		}
		*ptr_alvo = *ptr_v;
	}

	void transfer(int alvo, int valor)
	{
		alvo = valor;
	}

	void transfer(int alvo, int *valor)
	{
		alvo = *valor;
	}

	void transfer(int *alvo, int valor)
	{
		*alvo = valor;
	}

	int swap_time(int *alvo, int *valores,int tamanho)
	{
		int *ptr_alvo = alvo, *ptr_v = valores,auxiliar,x=0;
		clock_t i=clock();
		while (x<=tamanho)
		{
			auxiliar = *ptr_alvo;
			*ptr_alvo = *ptr_v;
			*ptr_v = auxiliar;
			ptr_alvo++;
			ptr_v++;
			x++;
		}
		return ((clock()-i)/CLOCKS_PER_SEC);
	}


	void swap(int *alvo, int *valores,int tamanho)
	{
		int *ptr_alvo = alvo, *ptr_v = valores,auxiliar,x=0;
		while (x<=tamanho)
		{
			auxiliar = *ptr_alvo;
			*ptr_alvo = *ptr_v;
			*ptr_v = auxiliar;
			ptr_alvo++;
			ptr_v++;
			x++;
		}
	}
	
	void printv(int v)
	{
		printf("%d", v);
	}

	void printv(int *v)
	{
		printf("%d", *v);
	}

	void unset(int *p)
	{
		free(p);
		p = NULL;
	}

	void print_r(int *array)
	{
		int *ptr_ar = array;
		int cont = 0;
		while (*ptr_ar != 0)
		{
			printf("[%d]=>%d\n", cont, *ptr_ar);
			printf("\n");
			cont++;
			ptr_ar++;
		}
	}
	void arand(int *array, int tamanho)
	{
		int *ptr_ar;
		srand((unsigned)time(NULL));
		ptr_ar = array;
		while (ptr_ar <= &array[tamanho - 1])
		{
			*ptr_ar = rand() + 1;
			ptr_ar++;
		}
	}
	void replace_top(int *pos, int T)
	{
		int *top = pos + (T-1);
		int auxiliar = *top;
		*top = *pos;
		*pos = auxiliar;
		unset(top);
	}
	void scan_r(int *array, int T)
	{
		int *ptr, cont = 1;
		ptr = array;
		while (ptr <= &array[T - 1])
		{
			printf("[%d]: ", cont);
			scanf_s("%d", ptr);
			cont++;
			ptr++;
		}
	}
//

//int sorting
	void spsort(int *matriz, int T)
	{
		PilhaI *pilha = pilhaI_cria();
		int menorval = OVERFLOW;
		int iMem,t = (T*(SI));
		for (int i = 0; i < T; ++i)
		{
			for (int j = 0; j < T; ++j)
			{
				if (menorval > matriz[j])
				{
					menorval = matriz[j];
					iMem = j;
				}
			}
			matriz[iMem] = OVERFLOW;
			pilhaI_push(pilha, menorval);
			menorval = OVERFLOW;
		}
		pilha = pilhaI_inverter(pilha);
		int *retorno = (int*)malloc(t+SI);
		for (int i = 0; i < T; ++i)
		{
			retorno[i] = pilhaI_pop(pilha);
		}
		retorno[T] = 0;
		transfer(matriz,retorno);
		free(retorno);
	}

	void spsort_it(int *matriz, int T)
	{
		PilhaI *pilha = pilhaI_cria();
		int menorval = OVERFLOW;
		int iMem,t = (T*(SI));
		for (int i = 0; i < T; ++i)
		{
			for (int j = 0; j < T; ++j)
			{
				if (menorval > matriz[j])
				{
					menorval = matriz[j];
					iMem = j;
				}
			}
			matriz[iMem] = OVERFLOW;
			pilhaI_push(pilha, menorval);
			menorval = OVERFLOW;
			printf("%d Numeros Ordenados\n",i+1);
		}
		pilha = pilhaI_inverter(pilha);
		int *retorno = (int*)malloc(t+SI);
		for (int i = 0; i < T; ++i)
		{
			retorno[i] = pilhaI_pop(pilha);
		}
		retorno[T] = 0;
		transfer(matriz,retorno);
		free(retorno);
	}	
	void spsort_percent(int *matriz, int T)
	{
		PilhaI *pilha = pilhaI_cria();
		int menorval = OVERFLOW;
		int iMem,t = (T*(SI));
		long int porcento = -1;
		double cont=0;
		for (int i = 0; i < T; ++i)
		{
			for (int j = 0; j < T; ++j)
			{
				if (menorval > matriz[j])
				{
					menorval = matriz[j];
					iMem = j;
				}
			}
			matriz[iMem] = OVERFLOW;
			pilhaI_push(pilha, menorval);
			menorval = OVERFLOW;
			if(porcento<(cont/T)*100)
			{
				porcento++;
				printf("%d%%\n",porcento);
			}
			cont++;
		}
		pilha = pilhaI_inverter(pilha);
		int *retorno = (int*)malloc(t+SI);
		for (int i = 0; i < T; ++i)
		{
			retorno[i] = pilhaI_pop(pilha);
		}
		retorno[T] = 0;
		transfer(matriz,retorno);
		free(retorno);
	}


	void tsort(int *m, int T)
	{
		int *ptr_m,*ptr_aux = m,*ptr_ord,*m_ord;
	 	ptr_m = m;
	 	m_ord = (int *)calloc((T+1),SI);
		ptr_ord = m_ord;
	 	while(ptr_m <= &m[T-1])
	 	{
	 		ptr_aux = m;
	  		ptr_ord = m_ord;
	  		while(ptr_aux <= &m[T-1])
	  		{
		   		if(*ptr_m > *ptr_aux)
		   		{
		    		ptr_ord++;
		   		}
		  		ptr_aux++;
			  	}
		  	while(*ptr_ord == *ptr_m)
		  	{
		  		ptr_ord++;
		  	}
		  	*ptr_ord = *ptr_m;
		  	ptr_m++;
		}
		transfer(m,m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		free(m_ord);
	}

	void tsort_it(int *m, int T)
	{
		int *ptr_m, *ptr_aux = m, *ptr_ord, *m_ord;
		double cont = 0.0;
	 	ptr_m = m;
	 	m_ord = (int *)calloc((T+1),SI);
		ptr_ord = m_ord;
	 	while(ptr_m <= &m[T-1])
	 	{
	 		ptr_aux = m;
	  		ptr_ord = m_ord;
	  		while(ptr_aux <= &m[T-1])
	  		{
		   		if(*ptr_m > *ptr_aux)
		   		{
		    		ptr_ord++;
		   		}
		  		ptr_aux++;
			  	}
		  	while(*ptr_ord == *ptr_m)
		  	{
		  		ptr_ord++;
		  	}
		  	*ptr_ord = *ptr_m;
		  	ptr_m++;
		  	if (cont < D_OVERFLOW)
			{
				cont++;
				printf("%.0lf/%d numeros ordenados\n",cont,T);
			}
		}
		transfer(m,m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		free(m_ord);
	}

	void tsort_percent(int *m, int T)
	{
		int *ptr_m, *ptr_aux = m, *ptr_ord, *m_ord;
		double cont = 0.0;
	 	ptr_m = m;
	 	m_ord = (int *)calloc((T+1),SI);
		ptr_ord = m_ord;
		long int porcento = -1;
	 	while(ptr_m <= &m[T-1])
	 	{
	 		ptr_aux = m;
	  		ptr_ord = m_ord;
	  		while(ptr_aux <= &m[T-1])
	  		{
		   		if(*ptr_m > *ptr_aux)
		   		{
		    		ptr_ord++;
		   		}
		  		ptr_aux++;
			  	}
		  	while(*ptr_ord == *ptr_m)
		  	{
		  		ptr_ord++;
		  	}
		  	*ptr_ord = *ptr_m;
		  	ptr_m++;
		  	if(porcento<(cont/T)*100)
			{
				porcento++;
				printf("%d%%\n",porcento);
			}
			cont++;
		}
		transfer(m,m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		free(m_ord);
	}

	void trsort(int *m, int T)
	{
		int *ptr_m = m, *ptr_aux = m;
		int *m_ord,t = T;
		m_ord = (int *)calloc((T + 1), SI);
		int *ptr_end_m = &m[T - 1], *ptr_end_ord = &m_ord[T - 1], *ptr_ord = m_ord, *ptr_o = m_ord;
		while (ptr_m <= ptr_end_m)
		{
			ptr_aux = m;
			ptr_ord = m_ord;
			ptr_o = m_ord;
			while (ptr_o <= ptr_end_ord)
			{
				if (ptr_aux <= ptr_end_m)
				{
					if (*ptr_m > *ptr_aux)
						ptr_ord++;
					ptr_aux++;
				}
				if (*ptr_o != 0)
					if (*ptr_m >= *ptr_o)
						ptr_ord++;
				ptr_o++;
			}
			*ptr_ord = *ptr_m;
			replace_top(ptr_m,t);
			ptr_end_m--;
			t--;
			ptr_ord = m_ord;
		}
		transfer(m, m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		unset(ptr_o);
		unset(ptr_end_m);
		unset(ptr_end_ord);
		unset(m_ord);
	}

	void trsort_it(int *m, int T)
	{
		int *ptr_m = m, *ptr_aux = m;
		int *m_ord,t = T;
		m_ord = (int *)calloc((T + 1), SI);
		int *ptr_end_m = &m[T - 1], *ptr_end_ord = &m_ord[T - 1], *ptr_ord = m_ord, *ptr_o = m_ord;
		double cont = 0.0;
		while (ptr_m <= ptr_end_m)
		{
			ptr_aux = m;
			ptr_ord = m_ord;
			ptr_o = m_ord;
			while (ptr_o <= ptr_end_ord)
			{
				if (ptr_aux <= ptr_end_m)
				{
					if (*ptr_m > *ptr_aux)
						ptr_ord++;
					ptr_aux++;
				}
				if (*ptr_o != 0)
					if (*ptr_m >= *ptr_o)
						ptr_ord++;
				ptr_o++;
			}
			*ptr_ord = *ptr_m;
			replace_top(ptr_m,t);
			ptr_end_m--;
			t--;
			ptr_ord = m_ord;
			if (cont < D_OVERFLOW)
			{
				cont++;
				printf("%.0lf/%d numeros ordenados\n",cont,T);
			}
		}
		transfer(m, m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		unset(ptr_o);
		unset(ptr_end_m);
		unset(ptr_end_ord);
		unset(m_ord);
	}

	void trsort_percent(int *m, int T)
	{
		int *ptr_m = m, *ptr_aux = m;
		int *m_ord,t = T;
		m_ord = (int *)calloc((T + 1), SI);
		int *ptr_end_m = &m[T - 1], *ptr_end_ord = &m_ord[T - 1], *ptr_ord = m_ord, *ptr_o = m_ord;
		double cont = 0.0;
		long int porcento = -1;
		while (ptr_m <= ptr_end_m)
		{
			ptr_aux = m;
			ptr_ord = m_ord;
			ptr_o = m_ord;
			while (ptr_o <= ptr_end_ord)
			{
				if (ptr_aux <= ptr_end_m)
				{
					if (*ptr_m > *ptr_aux)
						ptr_ord++;
					ptr_aux++;
				}
				if (*ptr_o != 0)
					if (*ptr_m >= *ptr_o)
						ptr_ord++;
				ptr_o++;
			}
			*ptr_ord = *ptr_m;
			replace_top(ptr_m,t);
			ptr_end_m--;
			t--;
			ptr_ord = m_ord;
			if(porcento<(cont/T)*100)
			{
				porcento++;
				printf("%d%%\n",porcento);
			}
			cont++;
		}
		transfer(m, m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		unset(ptr_o);
		unset(ptr_end_m);
		unset(ptr_end_ord);
		unset(m_ord);
	}
//

//char functions
	int contDigit(char str[])
	{
		int digitos = 0;
		while (str[digitos] != '\0')
		{
			digitos++;
		}
		return digitos;
	}

	int toINT(char str[])
	{
		int digitos = 0, x = 0, num = 0, p, y;

		while (str[digitos] != '\0')
		{
			digitos++;
		}
		digitos--;
		int pos = digitos;

		if (str[0] == '-' || str[0] == '-')
		{
			pos--;
			for (x = 1; x <= digitos; x++)
			{
				p = (str[x] - 48);
				for (y = 1; y <= pos; y++)
				{
					p = p * 10;
				}
				num = num + p;
				pos--;
			}
			num = num * -1;
		}
		else
		{
			for (x = 0; x <= digitos; x++)
			{
				p = (str[x] - 48);
				for (y = 1; y <= pos; y++)
				{
					p = p * 10;
				}
				num = num + p;
				pos--;
			}
		}
		return num;
	}

	void transfer_time(char *alvo, char *valores)
	{
		char *ptr_alvo = alvo, *ptr_v = valores;
		clock_t i = clock();
		while (*ptr_v != 0)
		{
			*ptr_alvo = *ptr_v;
			ptr_alvo++;
			ptr_v++;
		}
		*ptr_alvo = *ptr_v;
		printf("Copiado em %d s", ((clock() - i) / CLOCKS_PER_SEC));
		printf("\n");
	}

	void transfer(char *alvo, char *valores)
	{
		char *ptr_alvo = alvo, *ptr_v = valores;
		while (*ptr_v != 0)
		{
			*ptr_alvo = *ptr_v;
			ptr_alvo++;
			ptr_v++;
		}
		*ptr_alvo = *ptr_v;
		printf("\n");
	}

	void transfer(char alvo, char valor)
	{
		alvo = valor;
	}
	
	void transfer(char alvo, char *valor)
	{
		alvo = *valor;
	}

	void transfer(char *alvo, char valor)
	{
		*alvo = valor;
	}
	
	void swap_time(char *alvo, char *valores,int tamanho)
	{
		char *ptr_alvo = alvo, *ptr_v = valores,auxiliar,x=0;
		clock_t i=clock();
		while (x<=tamanho)
		{
			auxiliar = *ptr_alvo;
			*ptr_alvo = *ptr_v;
			*ptr_v = auxiliar;
			ptr_alvo++;
			ptr_v++;
			x++;
		}
		printf("Trocado em %d segundos\n",((clock()-i)/CLOCKS_PER_SEC));
	}
	
	void swap(char *alvo, char *valores,int tamanho)
	{
		char *ptr_alvo = alvo, *ptr_v = valores,auxiliar,x=0;
		while (x<=tamanho)
		{
			auxiliar = *ptr_alvo;
			*ptr_alvo = *ptr_v;
			*ptr_v = auxiliar;
			ptr_alvo++;
			ptr_v++;
			x++;
		}
	}

	void printv(char v)
	{
		printf("%d", v);
	}

	void printv(char *v)
	{
		printf("%d", *v);
	}

	void unset(char *p)
	{
		free(p);
		p = NULL;
	}

	void print_r(char *array)
	{
		char *ptr_ar = array;
		int cont = 0;
		while (*ptr_ar != 0)
		{
			printf("[%d]=>%d\n", cont, *ptr_ar);
			printf("\n");
			cont++;
			ptr_ar++;
		}
	}

	void replace_top(char *pos, int T)
	{
		char *top = pos + (T-1);
		char auxiliar = *top;
		*top = *pos;
		*pos = auxiliar;
		unset(top);
	}

	void scan_r(char *array, int T)
	{
		char *ptr = array;
		int cont = 1;
		while (ptr <= &array[T - 1])
		{
			printf("[%d]: ", cont);
			scanf_s("%d", ptr);
			cont++;
			ptr++;
		}
	}
//

//double functions
	void transfer_time(double *alvo, double *valores)
	{
		double *ptr_alvo = alvo, *ptr_v = valores;
		clock_t i = clock();
		while (*ptr_v != 0)
		{
			*ptr_alvo = *ptr_v;
			ptr_alvo++;
			ptr_v++;
		}
		*ptr_alvo = *ptr_v;
		printf("Copiado em %d s", ((clock() - i) / CLOCKS_PER_SEC));
		printf("\n");
	}

	void transfer(double *alvo, double *valores)
	{
		double *ptr_alvo = alvo, *ptr_v = valores;
		while (*ptr_v != 0)
		{
			*ptr_alvo = *ptr_v;
			ptr_alvo++;
			ptr_v++;
		}
		*ptr_alvo = *ptr_v;
		printf("\n");
	}

	void transfer(double alvo, double valor)
	{
		alvo = valor;
	}

	void transfer(double alvo, double *valor)
	{
		alvo = *valor;
	}

	void transfer(double *alvo, double valor)
	{
		*alvo = valor;
	}

	void swap_time(double *alvo, double *valores,int tamanho)
	{
		double *ptr_alvo = alvo, *ptr_v = valores,auxiliar,x=0;
		clock_t i=clock();
		while (x<=tamanho)
		{
			auxiliar = *ptr_alvo;
			*ptr_alvo = *ptr_v;
			*ptr_v = auxiliar;
			ptr_alvo++;
			ptr_v++;
			x++;
		}
		printf("Trocado em %d segundos\n",((clock()-i)/CLOCKS_PER_SEC));
	}

	void swap(double *alvo, double *valores,int tamanho)
	{
		double *ptr_alvo = alvo, *ptr_v = valores,auxiliar,x=0;
		while (x<=tamanho)
		{
			auxiliar = *ptr_alvo;
			*ptr_alvo = *ptr_v;
			*ptr_v = auxiliar;
			ptr_alvo++;
			ptr_v++;
			x++;
		}
	}

	void printv(double v)
	{
		printf("%d", v);
	}

	void printv(double *v)
	{
		printf("%d", *v);
	}

	void unset(double *p)
	{
		free(p);
		p = NULL;
	}


	void print_r(double *array)
	{
		double *ptr_ar = array;
		int cont = 0;
		while (*ptr_ar != 0)
		{
			printf("[%d]=>%d\n", cont, *ptr_ar);
			printf("\n");
			cont++;
			ptr_ar++;
		}
	}

	void arand(double *array, int tamanho)
	{
		double *ptr_ar;
		srand((unsigned)time(NULL));
		ptr_ar = array;
		while (ptr_ar <= &array[tamanho - 1])
		{
			*ptr_ar = rand() + 1;
			ptr_ar++;
		}
	}
	
	void replace_top(double *pos, int T)
	{
		double *top;
		top = (pos + (T - 1));
		double auxiliar = *top;
		*top = *pos;
		*pos = auxiliar;
		unset(top);
	}

	void scan_r(double *array, int T)
	{
		double *ptr = array;
		int cont = 1;
		while (ptr <= &array[T - 1])
		{
			printf("[%d]: ", cont);
			scanf_s("%d", ptr);
			cont++;
			ptr++;
		}
	}
//

//double sorting
	void tsort(double *m, int T)
	{
		double *ptr_m, *ptr_aux = m, *ptr_ord, *m_ord;
	 	ptr_m = m;
	 	m_ord = (double *)calloc((T+1),SD);
		ptr_ord = m_ord;
	 	while(ptr_m <= &m[T-1])
	 	{
	 		ptr_aux = m;
	  		ptr_ord = m_ord;
	  		while(ptr_aux <= &m[T-1])
	  		{
		   		if(*ptr_m > *ptr_aux)
		   		{
		    		ptr_ord++;
		   		}
		  		ptr_aux++;
			  	}
		  	while(*ptr_ord == *ptr_m)
		  	{
		  		ptr_ord++;
		  	}
		  	*ptr_ord = *ptr_m;
		  	ptr_m++;
		}
		transfer(m,m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		free(m_ord);
	}

	void tsort_it(double *m, int T)
	{
		double *ptr_m, *ptr_aux = m, *ptr_ord, *m_ord;
		double cont = 0.0;
	 	ptr_m = m;
	 	m_ord = (double *)calloc((T+1),SD);
		ptr_ord = m_ord;
	 	while(ptr_m <= &m[T-1])
	 	{
	 		ptr_aux = m;
	  		ptr_ord = m_ord;
	  		while(ptr_aux <= &m[T-1])
	  		{
		   		if(*ptr_m > *ptr_aux)
		   		{
		    		ptr_ord++;
		   		}
		  		ptr_aux++;
			  	}
		  	while(*ptr_ord == *ptr_m)
		  	{
		  		ptr_ord++;
		  	}
		  	*ptr_ord = *ptr_m;
		  	ptr_m++;
		  	if (cont < D_OVERFLOW)
			{
				cont++;
				printf("%.0lf/%d numeros ordenados\n",cont,T);
			}
		}
		transfer(m,m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		free(m_ord);
	}

	void tsort_percent(double *m, int T)
	{
		double *ptr_m, *ptr_aux = m, *ptr_ord, *m_ord;
		double cont = 0.0;
	 	ptr_m = m;
	 	m_ord = (double *)calloc((T+1),SD);
		ptr_ord = m_ord;
	 	while(ptr_m <= &m[T-1])
	 	{
	 		ptr_aux = m;
	  		ptr_ord = m_ord;
	  		while(ptr_aux <= &m[T-1])
	  		{
		   		if(*ptr_m > *ptr_aux)
		   		{
		    		ptr_ord++;
		   		}
		  		ptr_aux++;
			  	}
		  	while(*ptr_ord == *ptr_m)
		  	{
		  		ptr_ord++;
		  	}
		  	*ptr_ord = *ptr_m;
		  	ptr_m++;
		  	if (cont < D_OVERFLOW)
			{
				cont++;
				printf("%lf /100 dos numeros ordenados\n",(cont/T)*100);
			}
		}
		transfer(m,m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		free(m_ord);
	}

	void trsort(double *m, int T)
	{
		double *ptr_aux = m;
		double *ptr_m = m, *m_ord;
		int t = T;
		m_ord = (double *)calloc((T + 1), SD);
		double *ptr_end_m = &m[T - 1], *ptr_end_ord = &m_ord[T - 1], *ptr_ord = m_ord, *ptr_o = m_ord;
		while (ptr_m <= ptr_end_m)
		{
			ptr_aux = m;
			ptr_ord = m_ord;
			ptr_o = m_ord;
			while (ptr_o <= ptr_end_ord)
			{
				if (ptr_aux <= ptr_end_m)
				{
					if (*ptr_m > *ptr_aux)
						ptr_ord++;
					ptr_aux++;
				}
				if (*ptr_o != 0)
					if (*ptr_m >= *ptr_o)
						ptr_ord++;
				ptr_o++;
			}
			*ptr_ord = *ptr_m;
			replace_top(ptr_m,t);
			ptr_end_m--;
			t--;
			ptr_ord = m_ord;
		}
		transfer(m, m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		unset(ptr_o);
		unset(ptr_end_m);
		unset(ptr_end_ord);
		unset(m_ord);
	}

	void trsort_it(double *m, int T)
	{
		double *ptr_aux = m;
		double *ptr_m = m, *m_ord;
		int t = T;
		m_ord = (double *)calloc((T + 1), SD);
		double *ptr_end_m = &m[T - 1], *ptr_end_ord = &m_ord[T - 1], *ptr_ord = m_ord, *ptr_o = m_ord;
		double cont = 0.0;
		while (ptr_m <= ptr_end_m)
		{
			ptr_aux = m;
			ptr_ord = m_ord;
			ptr_o = m_ord;
			while (ptr_o <= ptr_end_ord)
			{
				if (ptr_aux <= ptr_end_m)
				{
					if (*ptr_m > *ptr_aux)
						ptr_ord++;
					ptr_aux++;
				}
				if (*ptr_o != 0)
					if (*ptr_m >= *ptr_o)
						ptr_ord++;
				ptr_o++;
			}
			*ptr_ord = *ptr_m;
			replace_top(ptr_m,t);
			ptr_end_m--;
			t--;
			ptr_ord = m_ord;
			if (cont < D_OVERFLOW)
			{
				cont++;
				printf("%.0lf/%d numeros ordenados\n",cont,T);
			}
		}
		transfer(m, m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		unset(ptr_o);
		unset(ptr_end_m);
		unset(ptr_end_ord);
		unset(m_ord);
	}


	void trsort_percent(double *m, int T)
	{
		double *ptr_aux = m;
		double *ptr_m = m, *m_ord;
		int t = T;
		m_ord = (double *)calloc((T + 1), SD);
		double *ptr_end_m = &m[T - 1], *ptr_end_ord = &m_ord[T - 1], *ptr_ord = m_ord, *ptr_o = m_ord;
		double cont = 0.0;
		while (ptr_m <= ptr_end_m)
		{
			ptr_aux = m;
			ptr_ord = m_ord;
			ptr_o = m_ord;
			while (ptr_o <= ptr_end_ord)
			{
				if (ptr_aux <= ptr_end_m)
				{
					if (*ptr_m > *ptr_aux)
						ptr_ord++;
					ptr_aux++;
				}
				if (*ptr_o != 0)
					if (*ptr_m >= *ptr_o)
						ptr_ord++;
				ptr_o++;
			}
			*ptr_ord = *ptr_m;
			replace_top(ptr_m,t);
			ptr_end_m--;
			t--;
			ptr_ord = m_ord;
			if (cont < D_OVERFLOW)
			{
				cont++;
				printf("%lf /100 dos numeros ordenados\n",(cont/T)*100);
			}
		}
		transfer(m, m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		unset(ptr_o);
		unset(ptr_end_m);
		unset(ptr_end_ord);
		unset(m_ord);
	}
//

//float functions
	void transfer_time(float *alvo, float *valores)
	{
		float *ptr_alvo = alvo, *ptr_v = valores;
		clock_t i = clock();
		while (*ptr_v != 0)
		{
			*ptr_alvo = *ptr_v;
			ptr_alvo++;
			ptr_v++;
		}
		*ptr_alvo = *ptr_v;
		printf("Copiado em %d s", ((clock() - i) / CLOCKS_PER_SEC));
		printf("\n");
	}

	void transfer(float *alvo, float *valores)
	{
		float *ptr_alvo = alvo, *ptr_v = valores;
		while (*ptr_v != 0)
		{
			*ptr_alvo = *ptr_v;
			ptr_alvo++;
			ptr_v++;
		}
		*ptr_alvo = *ptr_v;
		printf("\n");
	}

	void transfer(float alvo, float valor)
	{
		alvo = valor;
	}
	
	void transfer(float alvo, float *valor)
	{
		alvo = *valor;
	}

	void transfer(float *alvo, float valor)
	{
		*alvo = valor;
	}

	void swap_time(float *alvo, float *valores,int tamanho)
	{
		float *ptr_alvo = alvo, *ptr_v = valores,auxiliar,x=0;
		clock_t i=clock();
		while (x<=tamanho)
		{
			auxiliar = *ptr_alvo;
			*ptr_alvo = *ptr_v;
			*ptr_v = auxiliar;
			ptr_alvo++;
			ptr_v++;
			x++;
		}
		printf("Trocado em %d segundos\n",((clock()-i)/CLOCKS_PER_SEC));
	}

	void swap(float *alvo, float *valores,int tamanho)
	{
		float *ptr_alvo = alvo, *ptr_v = valores,auxiliar,x=0;
		while (x<=tamanho)
		{
			auxiliar = *ptr_alvo;
			*ptr_alvo = *ptr_v;
			*ptr_v = auxiliar;
			ptr_alvo++;
			ptr_v++;
			x++;
		}
	}

	void printv(float v)
	{
		printf("%d", v);
	}

	void printv(float *v)
	{
		printf("%d", *v);
	}

	void unset(float *p)
	{
		free(p);
		p = NULL;
	}

	void print_r(float *array)
	{
		float *ptr_ar = array;
		int cont = 0;
		while (*ptr_ar != 0)
		{
			printf("[%d]=>%d\n", cont, *ptr_ar);
			printf("\n");
			cont++;
			ptr_ar++;
		}
	}

	void arand(float *array, int tamanho)
	{
		float *ptr_ar;
		srand((unsigned)time(NULL));
		ptr_ar = array;
		while (ptr_ar <= &array[tamanho - 1])
		{
			*ptr_ar = rand() + 1;
			ptr_ar++;
		}
	}

	void replace_top(float *pos, int T)
	{
		float *top = pos + (T-1);
		float auxiliar = *top;
		*top = *pos;
		*pos = auxiliar;
		unset(top);
	}

	void scan_r(float *array, int T)
	{
		float *ptr = array;
		int cont = 1;
		while (ptr <= &array[T - 1])
		{
			printf("[%d]: ", cont);
			scanf_s("%d", ptr);
			cont++;
			ptr++;
		}
	}
//

//float sorting
	void tsort(float *m, int T)
	{
		float *ptr_m, *ptr_aux = m, *ptr_ord, *m_ord;
	 	ptr_m = m;
	 	m_ord = (float *)calloc((T+1),SF);
		ptr_ord = m_ord;
	 	while(ptr_m <= &m[T-1])
	 	{
	 		ptr_aux = m;
	  		ptr_ord = m_ord;
	  		while(ptr_aux <= &m[T-1])
	  		{
		   		if(*ptr_m > *ptr_aux)
		   		{
		    		ptr_ord++;
		   		}
		  		ptr_aux++;
			  	}
		  	while(*ptr_ord == *ptr_m)
		  	{
		  		ptr_ord++;
		  	}
		  	*ptr_ord = *ptr_m;
		  	ptr_m++;
		}
		transfer(m,m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		free(m_ord);
	}

	void tsort_it(float *m, int T)
	{
		float *ptr_m, *ptr_aux = m, *ptr_ord, *m_ord;
		double cont = 0.0;
	 	ptr_m = m;
	 	m_ord = (float *)calloc((T+1),SF);
		ptr_ord = m_ord;
	 	while(ptr_m <= &m[T-1])
	 	{
	 		ptr_aux = m;
	  		ptr_ord = m_ord;
	  		while(ptr_aux <= &m[T-1])
	  		{
		   		if(*ptr_m > *ptr_aux)
		   		{
		    		ptr_ord++;
		   		}
		  		ptr_aux++;
			  	}
		  	while(*ptr_ord == *ptr_m)
		  	{
		  		ptr_ord++;
		  	}
		  	*ptr_ord = *ptr_m;
		  	ptr_m++;
		  	if (cont < D_OVERFLOW)
			{
				cont++;
				printf("%.0lf/%d numeros ordenados\n",cont,T);
			}
		}
		transfer(m,m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		free(m_ord);
	}

	void tsort_percent(float *m, int T)
	{
		float *ptr_m, *ptr_aux = m, *ptr_ord, *m_ord;
		double cont = 0.0;
	 	ptr_m = m;
	 	m_ord = (float *)calloc((T+1),SF);
		ptr_ord = m_ord;
	 	while(ptr_m <= &m[T-1])
	 	{
	 		ptr_aux = m;
	  		ptr_ord = m_ord;
	  		while(ptr_aux <= &m[T-1])
	  		{
		   		if(*ptr_m > *ptr_aux)
		   		{
		    		ptr_ord++;
		   		}
		  		ptr_aux++;
			  	}
		  	while(*ptr_ord == *ptr_m)
		  	{
		  		ptr_ord++;
		  	}
		  	*ptr_ord = *ptr_m;
		  	ptr_m++;
		  	if (cont < D_OVERFLOW)
			{
				cont++;
				printf("%lf /100 dos numeros ordenados\n",(cont/T)*100);
			}
		}
		transfer(m,m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		free(m_ord);
	}

	void trsort(float *m, int T)
	{
		float *ptr_aux = m;
		float *ptr_m = m, *m_ord;
		int t = T;
		m_ord = (float *)calloc((T + 1), SF);
		float *ptr_end_m = &m[T - 1], *ptr_end_ord = &m_ord[T - 1], *ptr_ord = m_ord, *ptr_o = m_ord;
		while (ptr_m <= ptr_end_m)
		{
			ptr_aux = m;
			ptr_ord = m_ord;
			ptr_o = m_ord;
			while (ptr_o <= ptr_end_ord)
			{
				if (ptr_aux <= ptr_end_m)
				{
					if (*ptr_m > *ptr_aux)
						ptr_ord++;
					ptr_aux++;
				}
				if (*ptr_o != 0)
					if (*ptr_m >= *ptr_o)
						ptr_ord++;
				ptr_o++;
			}
			*ptr_ord = *ptr_m;
			replace_top(ptr_m,t);
			ptr_end_m--;
			t--;
			ptr_ord = m_ord;
		}
		transfer(m, m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		unset(ptr_o);
		unset(ptr_end_m);
		unset(ptr_end_ord);
		unset(m_ord);
	}

	void trsort_it(float *m, int T)
	{
		float *ptr_aux = m;
		float *ptr_m = m, *m_ord;
		int t = T;
		m_ord = (float *)calloc((T + 1), SF);
		float *ptr_end_m = &m[T - 1], *ptr_end_ord = &m_ord[T - 1], *ptr_ord = m_ord, *ptr_o = m_ord;
		double cont = 0.0;
		while (ptr_m <= ptr_end_m)
		{
			ptr_aux = m;
			ptr_ord = m_ord;
			ptr_o = m_ord;
			while (ptr_o <= ptr_end_ord)
			{
				if (ptr_aux <= ptr_end_m)
				{
					if (*ptr_m > *ptr_aux)
						ptr_ord++;
					ptr_aux++;
				}
				if (*ptr_o != 0)
					if (*ptr_m >= *ptr_o)
						ptr_ord++;
				ptr_o++;
			}
			*ptr_ord = *ptr_m;
			replace_top(ptr_m,t);
			ptr_end_m--;
			t--;
			ptr_ord = m_ord;
			if (cont < D_OVERFLOW)
			{
				cont++;
				printf("%.0lf/%d numeros ordenados\n",cont,T);
			}
		}
		transfer(m, m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		unset(ptr_o);
		unset(ptr_end_m);
		unset(ptr_end_ord);
		unset(m_ord);
	}

	void trsort_percent(float *m, int T)
	{
		float *ptr_aux = m;
		float *ptr_m = m, *m_ord;
		int t = T;
		m_ord = (float *)calloc((T + 1), SF);
		float *ptr_end_m = &m[T - 1], *ptr_end_ord = &m_ord[T - 1], *ptr_ord = m_ord, *ptr_o = m_ord;
		double cont = 0.0;
		while (ptr_m <= ptr_end_m)
		{
			ptr_aux = m;
			ptr_ord = m_ord;
			ptr_o = m_ord;
			while (ptr_o <= ptr_end_ord)
			{
				if (ptr_aux <= ptr_end_m)
				{
					if (*ptr_m > *ptr_aux)
						ptr_ord++;
					ptr_aux++;
				}
				if (*ptr_o != 0)
					if (*ptr_m >= *ptr_o)
						ptr_ord++;
				ptr_o++;
			}
			*ptr_ord = *ptr_m;
			replace_top(ptr_m,t);
			ptr_end_m--;
			t--;
			ptr_ord = m_ord;
			if (cont < D_OVERFLOW)
			{
				cont++;
				printf("%lf /100 dos numeros ordenados\n",(cont/T)*100);
			}
		}
		transfer(m, m_ord);
		unset(ptr_m);
		unset(ptr_aux);
		unset(ptr_ord);
		unset(ptr_o);
		unset(ptr_end_m);
		unset(ptr_end_ord);
		unset(m_ord);
	}
//