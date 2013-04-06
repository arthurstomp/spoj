#include <stdio.h>    
#include <string.h>    
#include<stdlib.h>
#include <math.h>    
#define  MAX 268435455.0000 


typedef struct{  
  double x;  
  double y;  
}ponto ;  

int n;  
double num; 
int *candidate_points;  
ponto *points;

int compareX(const void *a ,const void *b) {  
  ponto *a_aux = (ponto*)a;
  ponto *b_aux = (ponto*)b;
  if (a_aux->x < b_aux->x){ 
    return 1;  
  } else {
    return 0;  
  }
}  

int compareY(const void *a, const void *b) {  
  int *a_aux = (int*)a;
  int *b_aux = (int*)b;
  if(points[(*a_aux)].y < points[(*b_aux)].y){ 
    return 1;  
  } else{
    return 0;  
  }   
}  

double closest_pair(int left, int right) {  
  int i = 0;
  int j = 0;

  double d = MAX;

  if (left == right) { 
    return d;
  }

  if (left + 1 == right) { 
    return  sqrt((points[left].x - points[right].x) * (points[left].x - points[right].x) + (points[left].y - points[right].y) * (points[left].y - points[right].y) );
  }

  int mid = (left + right) / 2;
  double dl = closest_pair(left, mid);
  double dr = closest_pair(mid+1, right);
  if (dl < dr){
    d = dl;
  }else{
    d = dr;
  }	

  /* Elimina o resto dos pontos que não estão em |--d--mid--d--| */
  int k = 0;
  for (i = left; i <= right; i++) {  
    if (fabs(points[mid].x - points[i].x) <= d){
      candidate_points[k] = i;
      k++;
    }
  }  

  qsort(candidate_points, k, sizeof(int), compareY); /* ordena de acordo com a coordenada Y */

  /* dentro do novo espaço, retorna o par mais próximo (só consegui fazer quadrático, mas está funcionando) */
  for (i = 0; i < k; i++) {  
    for (j = i + 1; j < k && points[candidate_points[j]].y-points[candidate_points[i]].y < d ; j++) {  
      double dist = sqrt((points[candidate_points[i]].x - points[candidate_points[j]].x) * (points[candidate_points[i]].x - points[candidate_points[j]].x) +
          (points[candidate_points[i]].y - points[candidate_points[j]].y) * (points[candidate_points[i]].y - points[candidate_points[j]].y) );  
      if (d - dist > 1e-9){
        d = dist;
      }				
    }  
  }

  return d;  
}  


int main() {   

  int i;
  while (scanf("%d", &n) && n) {  
    points = malloc(sizeof(ponto)*n);
    candidate_points = malloc(sizeof(int)*n);
    for (i = 0; i < n; i++){  
      scanf("%lf %lf", &points[i].x, &points[i].y);  
    }
    qsort(points, n,sizeof(ponto), compareX); /* ordena de acordo com a coordenada X */
    num = closest_pair(0, n-1);
    if (num - 10000 > 1e-9) {
      printf("INFINITY\n");  
    } else {
      printf("%.4lf\n", num); 
    }			
    free(points);
    free(candidate_points);
  }  

  return 0;  
}  
