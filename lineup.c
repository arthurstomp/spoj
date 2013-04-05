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

void print_array(void *a){
  int i;
  for(i = 0; i < sizeof(a)/sizeof(a[0]); i++){
    if(sizeof(a[0]) == sizeof(int)){
      printf("%i",(*(int*)a)[0]);
    }
    if(sizeof(a[0]) == sizeof(char)){
      printf("%s",(*(int*)a)[0]);
    }
  }
  printf("\n",NULL);
}

int main(){

  //testing n_whitespaces
  //char *s = malloc(sizeof(char)*256);
  //scanf("%[^\n]%*c",s);
  //printf("n_whitespaces = %i",n_whitespaces(s));
  //free(s);

  //testing string to array
  char *s = malloc(sizeof(char)*256);
  scanf("%[^\n]%*c",s);
  int *i = string_to_array(s);
  print_array(i);
  free(s);
  free(i);
  return 0;
}

