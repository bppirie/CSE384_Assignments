#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Bradley Pirie
   CSE384
   Homework 7
   06APR2021
   
   Consider the following variable declarations. Write code that uses these variables
   to perform a matrix multiplication. The program should prompt the user for the
   sizes of the two matrices to be multiplied (from these, it can calculate the size of
   the result matrix). It should then dynamically allocate memory for the matrices
   and prompt the user for values for all entries in the matrix. Finally, the program
   should perform the matrix multiplication and report the result.
   double **m1,**m2,**mr;
   int m1_rows,m1_cols,m2_rows,m2_cols,mr_rows,mr_cols;
   Example: if the first matrix is 1 ? 3 with values [1 7 4] and the second matrix
   is 3 ? 2 with values [1 3], [1 9] and [6 2] in each row, then the result matrix
   should be 1? 2 with values [32 74].
 */
 
 int main() {
 
   double **m1, **m2, **mr;
   int m1_rows, m1_cols, m2_rows, m2_cols, mr_rows, mr_cols;
   
   // Ask for user input for size of the matrices, use scanf to store response into address of variables
   printf("How many rows in matrix 1? ");
   scanf("%d", &m1_rows);
   printf("How many columns in matrix 1? ");
   scanf("%d", &m1_cols);
   printf("How many rows in matrix 2? ");
   scanf("%d", &m2_rows);
   printf("How many columns in matrix 2? ");
   scanf("%d", &m2_cols);
   
   // Check if the matrices align the right way 
   if (m1_cols != m2_rows) {
      printf("\nThese cannot be multiplied, if matrix 1 has n columns then matrix 2 must have n rows");
      return 1;
   }
   else {      // Otherwise the result matrix will have matrix 1 rows and matrix 2 columns
      mr_rows = m1_rows;
      mr_cols = m2_cols;
   }
   
   // Dynamically allocate memeroy for each matrix using calloc
   m1 = (double **) calloc(m1_rows, sizeof(double *)); // First create a memory location for each row to
   m2 = (double **) calloc(m2_rows, sizeof(double *)); // hold a pointer to the memory for its corresponding
   mr = (double **) calloc(mr_rows, sizeof(double *)); // columns
   
   for (int i = 0; i < m1_rows; i++) {
      *(m1 + i) = (double *) calloc(m1_cols, sizeof(double)); // Next iterate through each row in the memory
   }                                                          // above and set its pointer to a new set of
   for (int i = 0; i < m2_rows; i++) {                        // memory for each column in that row to hold
      *(m2 + i) = (double *) calloc(m2_cols, sizeof(double)); // the double value that corresponds with that
   }                                                          // row and column in the matrix
   for (int i = 0; i < mr_rows; i++) {
      *(mr + i) = (double *) calloc(mr_cols, sizeof(double));
   }
   
   /* Using the memory created above, iterate through each row & column
      and ask the user what value is in the matrix at that location  */
   for (int i = 0; i < m1_rows; i++) {
      for (int j = 0; j < m1_cols; j++) {
         double val;
         printf("Matrix 1 value at row %d, column %d: ", i, j);
         scanf("%lf", &val);
         *(*(m1 + i) + j) = val; // Save response in the memory at corresponding position
      }
   }
   for (int i = 0; i < m2_rows; i++) {
      for (int j = 0; j < m2_cols; j++) {
         double val;
         printf("Matrix 2 value at row %d, column %d: ", i, j);
         scanf("%lf", &val);
         *(*(m2 + i) + j) = val; // Save respons in the memory at corresponding position
      }
   }
   
   // Iterate through each entry in the result matrix and compute its value
   for (int i = 0; i < mr_rows; i++) {
      for (int j = 0; j < mr_cols; j++) {
         double sum = 0;
         int k, l;                                            // Iterate through matrix 1 and 2 and sum
         for (k = l = 0; k < m2_rows; k++, l++) {             // Multiply entry k of row i in matrix 1
            sum += ((*(*(m1 + i) + k)) * (*(*(m2 + l) + j))); // by entry l in column j of matrix 2. Iterate
         }                                                    // through each k in row i and l in column
         *(*(mr + i) + j) = sum;                              // j and sum all values for 1 entry in result matrix
      }
   }
   
   /* Display resulting matrix to user by iterating through
      result matrix and printing each formatted value    */
   for (int i = 0; i < mr_rows; i++) {
      for (int j = 0; j < mr_cols; j++) {
         double val = (*(*(mr + i) + j));
         if (j == 0) {
            printf("\n| %5.2lf", val);    // First of each row goes on newline
         }                                // with | symbol before value. Last
         else if (j == (mr_cols - 1)) {   // of each row has | symbol after value.
            printf(" %5.2lf |", val);     // Every other value is printed in 
         }                                // between with a space and formatting
         else {
            printf(" %5.2lf", val);
         }
      }
   }
   
   return 0;
 }