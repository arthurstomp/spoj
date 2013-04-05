                                                                     
                                                                     
                                                                     
                                             
#include <iostream>    
#include <cstdio>    
#include <cstring>    
#include <cmath>    
#include <algorithm>    
using namespace std;  
#define  MAXN  0XFFFFFFF  
  
int n;  
double num; 
int pontosCandidatos[10000];  
 
struct Ponto {  
    double x;  
    double y;  
} p[10000];  

bool comparaX(Ponto a , Ponto b) {  /* Compara o X de dois pontos */
    if (a.x < b.x){ 
		return true;  
	} else {
		return false;  
	}
}  

bool comparaY(int a, int b) {  /* Compara o Y de dois pontos */
    if(p[a].y < p[b].y){ 
		return true;  
	} else{
		return false;  
	}   
}  

double ParMaisProximo(int left, int right) {  
    int i = 0;
	int j = 0;
	
    double d = MAXN;
	
    if (left == right) { /* caso base (só existe 1 ponto) */
		return d;
	}
	
    if (left + 1 == right) { /* só existem dois pontos */
		return sqrt((p[left].x - p[right].x) * (p[left].x - p[right].x) + (p[left].y - p[right].y) * (p[left].y - p[right].y));
	}
	
	/* Dividir p/conquistar */
    int mid = (left + right) / 2;
    double d1 = ParMaisProximo(left, mid);
    double d2 = ParMaisProximo(mid+1, right);
    if (d1 < d2){
		d = d1;
	}else{
		d = d2;
	}	
	
	/* Elimina o resto dos pontos que não estão em |--d--mid--d--| */
	int k = 0;
    for (i = left; i <= right; i++) {  
        if (fabs(p[mid].x - p[i].x) <= d){
            pontosCandidatos[k] = i;
			k++;
		}
    }  
	
    sort(pontosCandidatos, pontosCandidatos + k, comparaY); /* ordena de acordo com a coordenada Y */
  
    /* dentro do novo espaço, retorna o par mais próximo (só consegui fazer quadrático, mas está funcionando) */
    for (i = 0; i < k; i++) {  
        for (j = i + 1; j < k && p[pontosCandidatos[j]].y-p[pontosCandidatos[i]].y < d ; j++) {  
            double dist = sqrt((p[pontosCandidatos[i]].x - p[pontosCandidatos[j]].x) * (p[pontosCandidatos[i]].x - p[pontosCandidatos[j]].x) +
							   (p[pontosCandidatos[i]].y - p[pontosCandidatos[j]].y) * (p[pontosCandidatos[i]].y - p[pontosCandidatos[j]].y));  
            if (d - dist > 1e-9){
				d = dist;
			}				
        }  
    }
	
    return d;  
}  
  
int main() {   
	
    while (scanf("%d", &n) && n) {  
        for (int i = 0; i < n; i++)  
            scanf("%lf %lf", &p[i].x, &p[i].y);  
        sort(p, p + n, comparaX); /* ordena de acordo com a coordenada X */
        num = ParMaisProximo(0, n-1);
        if (num - 10000 > 1e-9) {
			printf("INFINITY\n");  
		} else {
			printf("%.4lf\n", num); 
		}			
    }  
	
    return 0;  
}  
