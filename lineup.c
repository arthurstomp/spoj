//SPOJ problem : LINEUP
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* string_to_array(char *si){
  char *aux = malloc(sizeof(char)*strlen(si));
  int nws = n_whitespaces(si);
  strcpy(aux,si);
  char *rest;
  char *token;
  int *a = malloc(sizeof(int)*nws);
  int i = 0;
  while(token = strtok_r(aux," ",&rest)){
    aux = rest;
    a[i] = atoi(token);
    i++;
  }
  free(aux);
  return a;
}

int n_whitespaces(char* s){
  char *aux = malloc(sizeof(char)*strlen(s));
  strcpy(aux,s);
  char *token;
  char *rest;
  int count = 0;
  token = strtok_r(aux," ",&rest);
  aux = rest;
  while(token = strtok_r(aux," ",&rest)){
    aux = rest;
    count++;
  }
  if(count < 0){
    count = 0;
  }
  free(aux);
  return count;
}

int main(){

  //testing n_whitespaces
  //char *s = malloc(sizeof(char)*256);
  //scanf("%[^\n]%*c",s);
  //printf("n_whitespaces = %i",n_whitespaces(s));
  //free(s);

  //testing string to array
  //char *s = "100 0 0 0 0";
  //int *i = string_to_array(s);
  //int j;
  //for(j = 0; j < n_whitespaces(s); j++){
  //  printf("%i ",i[j]);
  //}
  //free(i);
  
  //Real Deal
  int n_tests;
  scanf("%i",&n_tests);
  int i;
  char *p = malloc(sizeof(char)*43);
  for(i = 0; i < n_tests ; i++){
   int j;
   void **players = malloc(sizeof(int*)*11);
   for(j = 0; j < 11 ; j++){
    scanf("%s",p);
    int *p_a = string_to_array(p);
    players[j] = p_a;
   }
  }
  return 0;
}

