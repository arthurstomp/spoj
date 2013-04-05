//  Problema para contar as camadas de uma cebola.
// getting the input
#include<stdio.h>
#include<string.h>


//Working
int extreme_point(int points_x[], int points_y[],int n){
  int i;
  int extreme_point_index;
  int extreme_x = -20000;
  int extreme_y = 20000;
  for(i = 0; i < n; i++){
   if(points_x[i] >= extreme_x){
     if(points_y[i] <= extreme_y){
      extreme_point_index = i;
      extreme_x = points_x[i];
      extreme_y = points_y[i];
     }
   }
  }
  return extreme_point_index;
}

float slope(int x1, int y1, int x2, int y2){
  return (y2-y1)/(x2-x1);
}

int min_slope_point(int x, int y, int points_x[], int points_y[], int n){
  int i;
  int min_slope = 20000.0;
  int min_slope_point_index;
  for(i = 0; i < n; i++){
    if(points_x[i] != x && points_y[i] != y){
      if(slope(x,y,points_x[i],points_y[i]) <= min_slope){
        min_slope = slope(x,y,points_x[i],points_y[i]);
        min_slope_point_index = i;
      }
    }
  }
  return min_slope_point_index;
}

int[] 

int main(){
  int points_x[7] = {0,0,1,3,6,8,8};
  int points_y[7] = {0,8,6,1,6,0,8};
  int extreme_point_index = extreme_point(points_x,points_y,7);
  printf("the extreme point was the %i . x = %i, y = %i\n",extreme_point_index,points_x[extreme_point_index],points_y[extreme_point_index]);
  return 0;
}


//trecho para guardar partes de código

//int n_points = 10;
//while(n_points != 0){
//  scanf("%i",&n_points);
//  printf("numero de pontos %i\n",n_points);
//  //int points_x[n_points];
//  //int points_y[n_points];
//  int i;
//  for(i = 0; i < n_points; i++){
//    char point_string[20]; 
//    scanf("%s",point_string);
//    printf("test\n");
//    printf("inputs = %s\n",point_string);
//    //printf("pontos %s\n",point_string);
//    //points_x[i] = atoi(strtok(point_string," "));
//    //points_y[i] = atoi(strtok(point_string," "));
//    //printf("x do ponto = %s",points_x[i])
//  }
//}

