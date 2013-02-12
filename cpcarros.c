#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int isnumber(char c){
	//printf("char %c\n",c);
	int is = 0;
	if ( (c=='0') || (c=='1') || (c=='2') || (c=='3') || (c=='4') ||
		 (c=='5') || (c=='6') || (c=='7') || (c=='8') || (c=='9') )
		is= 1;
	return is;
}


long long  potencia(int x, int n){
	int i= 1;
	long long result= 1;
	if (n==0)
		return 1;
	for (i;i<=n;i++){
		result= result * x;	
	}
	return result;  
}

int isPlacaValida(char* placa){
	int i;
	if (strlen(placa)==7 ){
		int char3=isnumber(placa[3]);
		int char4=isnumber(placa[4]);
		if ( (!char3&&char4) || (!char4&&char3) )
			return 0;
		if (char3&&char4){
			for (i=2;i>=0;i--)
				if (placa[i]>'A' && placa[i]<'Z')
					return 1;
		}else{
			for (i=4;i>=0;i--)
				if ( (placa[i]=='A' ) || (placa[i]=='C' ) || (placa[i]=='M' ) || (placa[i]=='I' )||  (placa[i]=='P')||(placa[i]<'A') || (placa[i]>'Z') )
					return 0;
				else
					return 2;	
		}
	}
	return 1;
}

long long placa2num(char* pl,int tipo){
	//printf("placa2num %s %d \n",pl,tipo);
	int i=0,num=0,j=0;	
	long long soma=0;
	if (tipo==1){
		for (i=2;i>=0;i--){
			soma += (pl[i]-65) * potencia(26,3-i-1);   
		}
		soma= soma * potencia(10,4);
		char* s2;
		s2= malloc(4* sizeof(char));
		strcpy(s2,&pl[3]);
		//printf("soma: %d\n",soma);
		long num=atoi(s2)+1;
		//printf("s2:%s numeral: %d\n",s2,num);
		return soma + num;
	}
	if (tipo==2){
		//printf("tipo2\n");
		for (i=4;i>=0;i--){
			j=0;			
			if (pl[i]>'A' )
				j++;
			if (pl[i]>'C' )
				j++;
			if (pl[i]>'M' )
				j++;
			if (pl[i]>'I' )
				j++;
			if (pl[i]>'P' )
				j++;
			soma += (pl[i]-65-j) * potencia(21,5-i-1);   
		}
		soma= soma * potencia(10,2);
		char* s2;
		s2= malloc(2* sizeof(char));
		strcpy(s2,&pl[5]);
		//printf("soma %s: %llu\n",pl,soma);
		long long num=175760000+atoi(s2)+1;
		//printf("s2:%s numeral: %d\n",s2,num);
		return soma + num;
	}
}


int main(){
		char* placa1=malloc(7*sizeof(char));
		char* placa2=malloc(7*sizeof(char));
		int numConfidencia;
		int pl1_tipoplaca;
 		int pl2_tipoplaca;
		long s1toNum=0;
		long s2toNum=0;

		scanf("%s",placa1);
		scanf("%s",placa2);
		scanf("%d",&numConfidencia);	
		int k=1;	
		while (((placa1[0]!='*')	 && (placa2[0]!='*') ) ){
			if ((isPlacaValida(placa2))){ //,&letter,&number)) ){
				pl2_tipoplaca=2;
				pl1_tipoplaca=2;
				if (isnumber(placa2[3]))
					pl2_tipoplaca=1;
				if (isnumber(placa1[3]))
					pl1_tipoplaca=1;			
				s1toNum=placa2num(placa1,pl1_tipoplaca);
				s2toNum=placa2num(placa2,pl2_tipoplaca);
			//	printf("soma:%lu %lu\n",s1toNum,s2toNum);
				if (s2toNum>s1toNum)	{	
					if (s1toNum+numConfidencia>=s2toNum)
						printf("Y\n");
					if (s1toNum+numConfidencia<s2toNum || numConfidencia<1 || numConfidencia>1000000000)
						printf("N\n");	
				}else
					printf("N\n");											
			}else
				printf("N\n");						
			scanf("%s",placa1);
			scanf("%s",placa2);
			scanf("%d",&numConfidencia);		
			k++;
		}
	return 0;
}




