// Knapsack.c
#include <stdio.h>
int main(){
	int bagSize, nItems;
	scanf("%d %d",&bagSize,&nItems);
	int n, value, weight;
	int values[nItems], weights[nItems];
	for(n = 0; n <= nItems - 1; n++){
		scanf("%d %d",&weight,&value);
		values[n] = value;
		weights[n] = weight;
	}
	int knapsack[nItems+1][bagSize+1], i, j;
	for(i = 0; i <= nItems; i++){
		for(j = 0; j <= bagSize; j++){
			if(i == 0){
				knapsack[i][j] = 0;
			}else{
				if(weights[i-1] <= j){
					if(knapsack[i-1][j] >= knapsack[i-1][j - weights[i-1]] + values[i-1]){
						knapsack[i][j] = knapsack[i-1][j];
					}else{
						knapsack[i][j] = knapsack[i-1][j - weights[i-1]] + values[i-1];
					}
				}else{
					knapsack[i][j] = knapsack[i-1][j];
				}
			}
		}
	}
	printf("%d \n",knapsack[nItems][bagSize]);
	return 0;
}