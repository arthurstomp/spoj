// SPOJ : Plagio
// usar o número de semi-tons entre as notas para codifcar os textos.
// Exemplor CEGBb = 322 DF#A = 32

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum 
{C,C1,D,D1,E,F,F1,G,G1,A,A1,B} tiponota;

int* compute_next(int *p, int m){
  int *next = malloc(sizeof(int)*m);
  int i;
  int j;
  next[1] = -1;
  next[2] = 0;
  for(i = 3; i < m; i++){
    j = next[i - 1] + 1;
    while(p[i-1] != p[j-1] && j > 1){
      j = next[j-1] + 1;
        //  printf("\na\n");
    }
    next[i] = j;
  }
  return next;
}

//tiponota note_to_number(char* n){
//  if(strcmp(n,"C") == 0 || strcmp(n,"B#") == 0){ 
//    return C;
//  }else if(strcmp(n,"C#") == 0|| strcmp(n,"Db") == 0){
//    return C1; 
//  }else if(strcmp(n,"D") == 0){
//    return D;
//  }else if(strcmp(n,"D#") == 0 || strcmp(n,"Eb") == 0){
//    return D1;
//  }else if(strcmp(n,"E") == 0 || strcmp(n,"Fb") == 0){
//    return E;
//  }else if(strcmp(n,"F") == 0 || strcmp(n,"E#") == 0){
//    return F;
//  }else if(strcmp(n,"F#") == 0 || strcmp(n,"Gb") == 0){
//    return F1;
//  }else if(strcmp(n,"G") == 0){
//    return G;
//  }else if(strcmp(n,"G#") == 0 || strcmp(n,"Ab") == 0){
//    return G1;
//  }else if(strcmp(n,"A") == 0){
//    return A;
//  }else if(strcmp(n,"A#") == 0 || strcmp(n,"Bb") == 0){
//    return A1;
//  }else if(strcmp(n,"B") == 0 || strcmp(n,"Cb") == 0){
//    return B;
//  }
//}

void imprimelista(int* a,int m){
    int i=0;
    printf("\nlista: ");
    for (i;i<m;i++)
        printf(" %d",a[i]);
    printf("\n");
}


int note_to_number(char* n){
  if(strcmp(n,"C") == 0 || strcmp(n,"B#") == 0){ 
    return 1;
  }else if(strcmp(n,"C#") == 0|| strcmp(n,"Db") == 0){
    return 2; 
  }else if(strcmp(n,"D") == 0){
    return 3;
  }else if(strcmp(n,"D#") == 0 || strcmp(n,"Eb") == 0){
    return 4;
  }else if(strcmp(n,"E") == 0 || strcmp(n,"Fb") == 0){
    return 5;
  }else if(strcmp(n,"F") == 0 || strcmp(n,"E#") == 0){
    return 6;
  }else if(strcmp(n,"F#") == 0 || strcmp(n,"Gb") == 0){
    return 7;
  }else if(strcmp(n,"G") == 0){
    return 8;
  }else if(strcmp(n,"G#") == 0 || strcmp(n,"Ab") == 0){
    return 9;
  }else if(strcmp(n,"A") == 0){
    return 10;
  }else if(strcmp(n,"A#") == 0 || strcmp(n,"Bb") == 0){
    return 11;
  }else if(strcmp(n,"B") == 0 || strcmp(n,"Cb") == 0){
    return 12;
  }
}


int kmp(int *t, int n, int *p, int m){
  int i = 1; int j = 1;
  int *next = compute_next(p,m);
//  imprimelista(next,m);
  int start = -1;
  //printf("n = %i , m = %i\n", n,m);
  int k;
  //for(k = 0; k < n; k++){
  //printf("%i \n",t[k]);
 // }
 // printf("\n",NULL);
 // for(k = 0; k < m; k++){
 //   printf("%i ",p[k]);
 // }
 // printf("\n",NULL);
  while(start == -1  && i < n){
 //   printf("asad\n");
   // printf("p[%d] = %i , t[%d] = %i\n",j,p[j],i,t[i]);
    if(p[j] == t[i]){
      if(m <= 1){
   //     printf("loucura\n");
        start = abs(i-m);
      }
      //printf("p[j] = %i , t[i] = %i\n",p[j],t[i]);
      j = j + 1;
      i = i + 1;
    }else{
         j = next[j]+1;
         while ( p[j]!=t[i] && j>0)
              j = next[j]+1;
        
         if (j>=1){
            j++;
            i++;
         }else{
            i++;
            j=1;
         }
    }
    //printf("%i %i . i = %i j = %i\n",t[i],p[j], i , j);
  //  printf("j:  %i i: %i ",j,i);
    if(j == m){
     //printf("ZZ"); 
      start = 0;
    }
//    printf("here start = %i\n",start);
  }
  //printf("start out = %i\n",start);
  return start;
}

int *notes_to_semitones(char* t, int n){
  int *semitones = malloc(sizeof(int)*n);
  char *aux = malloc(strlen(t));
  strcpy(aux,t);
  //printf("|%s|",aux);
  int i = 0;
  char *rest;
  char *note;
  int a_note;
  int n_note;
  //note = strtok_r(aux," ",&rest);
  aux = rest;
  a_note = note_to_number(note);
  //while(note = strtok_r(aux," ",&rest)){
    //printf("%s",note);
    //n_note = note_to_number(note);
    //aux = rest;
    //semitones[i] = abs(n_note - a_note);
    //i++;
   // a_note = n_note;
  //}
  return semitones;
}

int n_whitespaces(char* s){
  char *aux = malloc(strlen(s)+1);
  strcpy(aux,s);
  char *result = NULL;
  int count = -1;
  result = strtok(aux," ");
  while(result != NULL ){
    result = strtok(NULL," ");
    count++;
  }
  return count;
}




int main(){
  //char *t1 = "D G A B C D G G G C D E F# G C C";
  //char *t2 = "C C# D D# E F F# G G# A A# B";
  //char *t3 = "C Db D Eb E F Gb G Ab A Bb B";
  //char *t4 = "C E G Bb";
  //char *p1 = "G G C D";
  //char *p2 = "C D";
  //char *p3 = "C D";
  //char *p4 = "D F# A";
  //int *t1_aux = notes_to_semitones(t1,n_whitespaces(t1));
  //int *t2_aux = notes_to_semitones(t2,n_whitespaces(t2));
  //int *t3_aux = notes_to_semitones(t3,n_whitespaces(t3));
  //int *t4_aux = notes_to_semitones(t4,n_whitespaces(t4));

  //int *p1_aux = notes_to_semitones(p1,n_whitespaces(p1));
  //int *p2_aux = notes_to_semitones(p2,n_whitespaces(p2));
  //int *p3_aux = notes_to_semitones(p3,n_whitespaces(p3));
  //int *p4_aux = notes_to_semitones(p4,n_whitespaces(p4));

  //printf("test 1 = %i\n",kmp(t1_aux,n_whitespaces(t1),p1_aux,n_whitespaces(p1)));
  //printf("test 2 = %i\n",kmp(t2_aux,n_whitespaces(t2),p2_aux,n_whitespaces(p2)));
  //printf("test 3 = %i\n",kmp(t3_aux,n_whitespaces(t3),p3_aux,n_whitespaces(p3)));
  //printf("test 4 = %i\n",kmp(t4_aux,n_whitespaces(t4),p4_aux,n_whitespaces(p4)));
  
  //char *t = "C Db D Eb E F Gb G Ab A Bb B";
  //char *p = "C D";
  //int *t_aux = notes_to_semitones(t, n_whitespaces(t));
  //printf("number of whitespaces of %s = %i",t,n_whitespaces(t));
  //printf("\n",NULL);
  //int *p_aux = notes_to_semitones(p, n_whitespaces(p));
  //printf("number of whitespaces of %s = %i",p,n_whitespaces(p));
  //printf("\n",NULL);
  //int i;
  //printf("semitones of %s = ",t);
  //for(i = 0; i < n_whitespaces(t); i++){
  //  printf("%i ",t_aux[i]);
  //}
  //printf("\n",NULL);
  //printf("semitones of %s = ",p);
  //for(i = 0; i < n_whitespaces(p); i++){
  //  printf("%i ",p_aux[i]);
  //}
  //printf("\n",NULL);
  //int plagio = kmp(t_aux,sizeof(t_aux)/sizeof(t_aux[0]),p_aux,sizeof(p_aux)/sizeof(p_aux[0]));
  //printf("%i",plagio);

  int nt = 1; int np = 1;
  //char** t=(char**)malloc(200 * sizeof(char*)) ;
  
  //char* t=(char*)malloc(500 * sizeof(char)) ;
  //char* p[10000] ;
  
  //printf("%u %u",p,t);
  
  //printf("%i %i\n",nt,np);

  
  scanf("%i %i \n",&nt,&np);
  //t[0]=0;
		//scanf("%s ",aux );
  while(nt != 0 && np != 0){
  int* t_aux = (int*) malloc(nt*sizeof(int));
  char** t = (char*) malloc(nt*sizeof(char*));
  int* p_aux = (int*) malloc(np*sizeof(int));
   char** p=(char**)malloc( np* sizeof(char*)) ;
//   t[0]=0;
//	printf("entrei\n T:");
	int i=0;
	for (i;i<nt;i++){
		//printf("teste1");
        char* aux = (char*) malloc(2*sizeof(char));
        t[i]=(char*) malloc(2*sizeof(char));
	    scanf("%s ",aux );	
	    t[i]=aux;
	    if (i!=0)
	        if (note_to_number(t[i])>=   note_to_number(t[i-1])){
	    	    t_aux[i]= (note_to_number(t[i]) - note_to_number(t[i-1]) );
	    	}else{
	    	 //   printf("\nahoi\n");
	    		t_aux[i]= ( note_to_number(t[i]) + 12 - note_to_number(t[i-1]) );
	    	}
	    else
	        t_aux[i]=note_to_number(aux);	
//	        free(aux);
	//        printf("i: %d t_aux %d \n",i,t_aux[i]);
	//	printf("nota: %s valor_nota:%d t_aux: %d ",aux,note_to_number(aux),t_aux[i]);
	}
	//printf("\nP: ");
	i=0;
	for (i;i<np;i++){
	        char* aux = (char*) malloc(2*sizeof(char));
	        p[i]=(char*) malloc(2*sizeof(char));
		    scanf("%s ",aux );
			    p[i]=aux;
		if (i!=0)
		     if (note_to_number(p[i])>= note_to_number(p[i-1])){
	    	    p_aux[i]= (note_to_number(p[i]) - note_to_number(p[i-1]) );
	    	}else{
	    	  // printf("\nahoi %d %d \n",note_to_number(p[i]),note_to_number(p[i-1]));
    	    	p_aux[i]= (note_to_number(p[i])+12 - note_to_number(p[i-1]) );	
    	    }
	    else
	        p_aux[i]=note_to_number(aux);	
	//    free(aux);
		//p_aux[i]=note_to_number(aux);	
	//	printf("aux: %s p: %d ",aux,p_aux[i]);
	  //  printf("nota: %s valor_nota:%d p_aux: %d ",aux,note_to_number(aux),t_aux[i]);
	}
	i=1;
	int plagio = kmp(t_aux,nt,p_aux,np);
	if(plagio == -1){
      printf("N\n");
    }else{
      printf("S\n");
    }
	
	//int* p_aux= malloc()
	//for (i;i<=np;i++)
	scanf("%i %i \n",&nt,&np);
	free(t_aux);
	free(p_aux);
	free(p);
	free(t);
//	free(aux);
	
  }
	
  return 0;
}
