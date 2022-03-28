#include <stdio.h>

int main() 
{
  int x=9, y=9;
  char a[x][y];

  for (int i=0; i<x; i++)
  {
    for (int j=0; j<y;)
    {
      char c;
      scanf("%c", &c);

      if (c=='_' || c=='x')
      {
        if (c=='_')
        {
            a[i][j]='0';
        }
        else{
            a[i][j]='x';
        }
        j++;
      }
    }
  }

  printf("%c", a[9][-1]);

for (int i=0; i<x; i++)
  {
    for (int j=0; j<y; j++)
    {
      if (a[i][j]!='x')
      {
        if (a[i-1][j-1]=='x')
        {
          a[i][j]=a[i][j]+1;
        //   if(i==8 && j==0) printf("a");
        }
        if (a[i-1][j]=='x')
        {
          a[i][j]=a[i][j]+1;
        //   if(i==8 && j==0) printf("b");
        }
        if (a[i-1][j+1]=='x')
        {
          a[i][j]=a[i][j]+1;
            // if(i==8 && j==0) printf("c"); // 
        }
        if (a[i][j-1]=='x')
        {
          a[i][j]=a[i][j]+1;
            // if(i==8 && j==0) printf("d");
        }
        if (a[i][j+1]=='x')
        {
          a[i][j]=a[i][j]+1;
            // if(i==8 && j==0) printf("e"); // 
        }
        if (a[i+1][j-1]=='x' && j-1 > 0)
        {
          a[i][j]=a[i][j]+1;
            // if(i==8 && j==0) printf("f \"%c\"", a[i+1][-1]); //
        }
        if (a[i+1][j]=='x')
        {
          a[i][j]=a[i][j]+1;
            // if(i==8 && j==0) printf("g");
        }
        if (a[i+1][j+1]=='x')
        {
          a[i][j]=a[i][j]+1;
            // if(i==8 && j==0) printf("h");
        }
      }
    }
  }

  for (int i=0; i<x; i++)
  {
    if (a[i][0]=='0')
    {
        a[i][0]='_';
    }
    if (a[i][0]=='x')
    {
        a[i][0]='x';
    }
    printf("%c", a[i][0]);
    for (int j=1; j<y; j++)
    {
      if (a[i][j]=='0')
      {
          a[i][j]='_';
      }
      if (a[i][0]=='x')
      {
          a[i][0]='x';
      }  
      printf(" %c", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}