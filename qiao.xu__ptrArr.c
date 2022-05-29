#include<stdio.h>
#include<stdlib.h>

void array1(int** a, int b, int c)
{
		int i, j;

		for (i = 0; i < b; i++)
		{
			for (j = 0; j < c; j++)
				printf("iarray[%d][%d]=%d\n", i, j, *(int*)((int*)(a)+i*c+j));
		}
		
}

void tran(int** a, int b, int c)
{
	int i, j;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d\t", *(int*)((int*)(a)+j * c + i));
			printf("\n");

		}
		
	}
	
}

void printmat(int** a, int b, int c)
{
	int i, j;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d\t", *(int*)((int*)(a)+j * c + i));
			printf("\n");
		}
		
	}
}

void mul(int a[][4], int b[][4], int c[][4])
{
	int i, j, x, y, k;
	const int N = 3;
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			k = a[i][j] * b[j][i];
			c[i][i] = c[i][i] + k;
		}
	}
}

int main(void)
{
	int iarray[2][2] = { {1,2},{3,4} };
	array1((int**)iarray, 2, 2);
	printf("iarray[2][2]=\n");
	tran((int**)iarray, 2, 2);
	

	int A[4][4] = { {1,1,1,1},{1,2,3,4},{1,3,6,10},{1,4,10,20} };
	int B[4][4] = { {4,-6,4,-1},{-6,14,-11,3},{4,-11,10,-3},{-1,3,-3,1} };
	int C[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int D[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };



	printf("Performing Matrix Transpose...\n");
	printf("C=\n");
	tran((int**)C, 4, 4);
	printf("C's transpose=\n");
	printmat((int**)C, 4, 4);
	printf("\n");
	printf("A=\n");
	tran((int**)A, 4, 4);
	printf("B=\n");
	tran((int**)B, 4, 4);
	printf("D=AxB");
	mul(A, B, D);
	tran((int**)A, 4, 4);

	
}