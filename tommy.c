include <stdio.h>
#include <stdlib.h>
#include <time.h>

int k(int*a, char*b){
  *b = (int)*b;
  if(*b<*a){
    printf("Too small\n");
    return 1;
  }  
  else if(*b>*a){
    printf("Too big\n");
    return 1;
  }
  else{
    printf("Good\n");
    exit(0);
  }
}

int main(void) {
  int a, i;
  char b;
  char str[4] = {'C', 'D', 'H', 'S'};
  unsigned int seed;
  seed = time(NULL);
  srand(seed);
  i = rand()%4;
  a = str[i]; 
  do{
    scanf("%c", &b);
    if(k(&a, &b))
      continue;
    else if(!k(&a,&b))
      break;
  } while(1);
  return 0;
}