#include<stdio.h>
#include <regex.h>
#include<complex.h>

regex_t letter;
regex_t number;
regex_t placa_antiga;
regex_t placa_nova;
regex_t placa_nova2;

int isletter(char c){
	printf("char %c\n",c);
	regcomp(&letter, "[A-Z]", 0);
	int ret=regexec(&letter,&c,0,NULL,0);
	int is = 1;
	if (ret==REG_NOMATCH)
		is= 0;
	regfree(&letter);
	return is;
}

int isnumber(char c){
	//printf("char %c\n",c);
	//regcomp(&letter, "[A-Z]", 0);
	//int ret=regexec(&letter,&c,0,NULL,0);
	int is = 0;
	if ( (c=='0') || (c=='1') || (c=='2') || (c=='3') || (c=='4') ||
		 (c=='5') || (c=='6') || (c=='7') || (c=='8') || (c=='9') )
		is= 1;
	//regfree(&letter);
	return is;
}


int isPlacaAntiga(char* c){
	if (!regexec(&placa_antiga,c,0,NULL,0))
		return 1;
	else
		return 2;

}

int isPlacaNova(char* c){
	int tipo_placa =1;
	if (!regexec(&placa_nova,c,0,NULL,0))
		tipo_placa=2;
	regcomp(&placa_nova, "[A-Z][A-Z][A-Z][A-Z][A-Z][0-9][0-9]", 0);	
	return tipo_placa;

}
int tipo_placa(char* c){
	if (!regexec(&placa_antiga,c,0,NULL,0)){
		regcomp(&placa_antiga, "[A-Z][A-Z][A-Z][0-9][0-9][0-9][0-9]", 0);				
		return 1;
	}
	else
		if(!regexec(&placa_nova2,c,0,NULL,0)){
			regcomp(&placa_nova, "[A-Z][A-Z][A-Z][A-Z][A-Z][0-9][0-9]", 0);
			if (!regexec(&placa_nova,c,0,NULL,0)){
				regcomp(&placa_nova2, "[^ACMIP][^ACMIP][^ACMIP][^ACMIP][^ACMIP][0-9][0-9]", 0);
				return 2;
			}
		}
}


long potencia(int x, int n){
	int i= 1;
	long result= 1;
	if (n==0)
		return 1;
	for (i;i<=n;i++){
		result= result * x;	
	}
	return result;  
}

int isPlacaValida(char* placa){//,regex_t* l,regex_t* n){
	int i;
	//printf("IsPlacaValida %s\n",placa);
	if (strlen(placa)==7 ){
//		for (i=0;i<3;i++)
//			if (!isletter(placa[i])) 
//				return 0;
		int char3=isnumber(placa[3]);//isletter(placa[3]);
		//printf("IsPlacaValida %s %d\n",placa,char3);	
		int char4=isnumber(placa[4]);//isletter(placa[4]);
		if ( (!char3&&char4) || (!char4&&char3) )
			return 0;
		if (char3&&char4)
			return 1;
		else{
			for (i=4;i>=0;i--)
				if ( (placa[i]=='A' ) || (placa[i]=='C' ) || (placa[i]=='M' ) || (placa[i]=='I' )||  (placa[i]=='P' ) )
					return 0;
				else
					return 2;	
		}
			
//		for (i=5;i<7;i++)
//			if (isletter(placa[i])) 
//				return 0;
	}
	return 1;
}

double placa2num(char* pl,int tipo){
	//printf("placa2num %s %d \n",pl,tipo);
	int i=0,num=0,j=0;	
	long soma=0;
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
			soma += (pl[i]-65-j) * potencia(23,3-i-1);   
		}
		soma= soma * potencia(10,2);
		char* s2;
		s2= malloc(2* sizeof(char));
		strcpy(s2,&pl[5]);
		//printf("soma: %d\n",soma);
		long num=175760000+atoi(s2)+1;
		//printf("s2:%s numeral: %d\n",s2,num);
		return soma + num;
	}

	return -1;
}


int main(){
		char* placa1=malloc(7*sizeof(char));
		char* placa2=malloc(7*sizeof(char));
		int numConfidencia;
		int pl1_tipoplaca;
 		int pl2_tipoplaca;
		long s1toNum=0;
		long s2toNum=0;
//		pow(10,2);
		/* Compile regular expression */
      //  regcomp(&letter, "[A-Z]", 0);
  //      regcomp(&number, "[0-9]", 0);		
	//	regcomp(&placa_antiga, "[A-Z][A-Z][A-Z][0-9][0-9][0-9][0-9]", 0);		
	//	regcomp(&placa_nova, "[A-Z][A-Z][A-Z][A-Z][A-Z][0-9][0-9]", 0);		
	//	regcomp(&placa_nova2, "[^ACMIP][^ACMIP][^ACMIP][^ACMIP][^ACMIP][0-9][0-9]", 0);		
		scanf("%s",placa1);
		scanf("%s",placa2);
		scanf("%d",&numConfidencia);	
		int k=1;	
		while (((placa1[0]!='*')	 && (placa2[0]!='*') ) ){
		//	printf("%s %s\n",placa1,placa2);
		//	pl1_tipoplaca= tipo_placa(placa1);//isPlacaAntiga(placa1);
		//	pl2_tipoplaca= tipo_placa(placa2);
	
		//	printf("%d\n",pl2_tipoplaca);
		//	printf("%d\n",pl1_tipoplaca);
			//printf("%d\n",isPlacaValida(placa1,&letter,&number));
			//printf("%d\n",isPlacaValida(placa2,&letter,&number));
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
					if (s1toNum+numConfidencia<s2toNum)
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
}




