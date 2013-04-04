// SPOJ : Plagio
// usar o número de semi-tons entre as notas para codifcar os textos.
// Exemplor CEGBb = 322 DF#A = 32

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* compute_next(char *p, int m){
  int *next = malloc(sizeof(int)*m);
  int i;
  int j;
  next[0] = -1;
  next[1] = 0;
  for(i = 2; i < m; i++){
    j = next[i - 1] + 1;
    while(p[i-1] != p[j-1] && j > 0){
      j = next[j-1] + 1;
    }
    next[i] = j;
  }
  return next;
}

int kmp(char *t, int n, char *p, int m){
  int i = 0; int j = 0;
  int *next = compute_next(p,m);
  int start = -1;
  while(start == -1  && i < n){
    if(p[j] == t[i]){
      j = j + 1;
      i = i + 1;
    }else{
     j = next[j-1] + 1;
      if(j == 0){
        j = 1;
        i = i + 1;
      }
    }
    if(j == m ){
      start = i - m ;
    }
  }
  if (start == -1){
    return -1;
  }else{
    return start ;
  }
}

//int *notes_to_semitones(char* t, int n){
//  int a = 0 ; int d = 0;
//  while(d < n){
//  }
//}
int main(){
  char *p = "xyxyyxyxyxx";
  //printf("%s\n",p);
  int *next = compute_next(p,strlen(p));
  int i;
  for(i = 0; i < 11 ; i++){
    printf("%i",next[i]);
  }
  printf("\n",NULL);
  char *t = "xyxyyxyxyxx";
  int start = kmp(t,strlen(t),p,strlen(p));
  printf("%i\n",start); 
  return 0;
}
