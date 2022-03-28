#include<stdio.h>
#define STUDENTS 3
#define EXAMS 4 
void minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
void maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
void average(const int grades[][EXAMS], size_t pupils, size_t tests);
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests);


// function main begins program execution
int main(void)
{
    
   // initialize student grades for three students (rows)
   int op;
   int studentGrades[STUDENTS][EXAMS] =  
      { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };

    void (*ptrfunc[4])(const int grades[][EXAMS], size_t pupils, size_t tests) = {printArray, minimum, maximum, average};

    while(scanf("%d", &op)){
        if(op == 4){
            break;
        }
        else{
            ptrfunc[op](studentGrades, STUDENTS, EXAMS);
        }
    }
}

// Find the minimum grade
void minimum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int minimum = grades[0][0];
    for (int i = 0; i < pupils; i++)
    {
        for (int j = 0; j < tests; j++)
        {
            if (grades[i][j] < minimum)
            {
                minimum = grades[i][j];
            }
        }
    }
    printf("%d\n", minimum);
} 

// Find the maximum grade
void maximum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int maximum = grades[0][0];
    for (int i = 0; i < pupils; i++)
    {
        for (int j = 0; j < tests; j++)
        {
            if (grades[i][j] > maximum)
            {
                maximum = grades[i][j];
            }
        }
    }
    printf("%d\n", maximum);
} 

// Determine the average grade for a particular student
void average(const int grades[][EXAMS], size_t pupils, size_t tests)      
{                                                         
    int average = 0;
    for (int i = 0; i < pupils; i++)
    {
        int total = 0;
        for (int j = 0; j < tests; j++)
        {
            total += grades[i][j];
        }
        printf("Student %u average %.2f\n",i,(double)total/tests);
    }
} 

// Print the array
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests)
{
   // output column heads
   printf("%s", "                 [0]  [1]  [2]  [3]");

   // output grades in tabular format
   for (size_t i = 0; i < pupils; ++i) {

      // output label for row
      printf("\nstudentGrades[%u] ", i);

      // output grades for one student
      for (size_t j = 0; j < tests; ++j) {
         printf("%-5d", grades[i][j]);
      } 
   }
   printf("\n");
}