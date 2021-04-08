#include <stdio.h>
#include <string.h>

/* Bradley Pirie
   CSE384
   Homework 6
   Problem 13

   Write a program that looks at all the command line arguments and reports if any
   of the arguments are the same (i.e., they match exactly). The program should
   print out the matching argument and the positions it occupies in the list of
   arguments
*/

int main(int argc, char *argv[]) {     // Save arguments in argv[]
   for (int i = 0; i < argc; i++) {    // Iterate through argv[]
      int flag = 0;     // flag=0 means no repeats found, flag=1 means there is a repeat
      if (argv[i] != "") { // If argv[i] is empty then it has already been tested so skip
         for (int j = i + 1; j < argc; j++) {   // Iterate through agrv[] starting at i
            if (argv[j] != "" && strcmp(argv[i], argv[j]) == 0) { // Check if argv[j] is nonempty and the same as argv[i]
               if (flag == 1) {  // If flag=1 add the additional repeat to output
                  argv[i] = "";  // Set argv[i] to emtpy since it has been tested
                  printf(", %d", j);   // Print the additional repeat
               }
               else { // Then flag=0 so this is the first repeat of this type
                  argv[j] = "";  // Set agrv[i]'s repeat to empty
                  printf("Argument \"%s\" repeats at positions %d, %d", argv[i], i, j); // Print that the argument does have a repeat as well as the first 2 positions
                  flag = 1;      // Set flag=1 to indicate that any other repeat will be an addition to the output printed above
               }
            }
         }
         argv[i] = ""; // After iterating through all elements after argv[i] mark it empty to indicate it has been tested
         if (flag == 1) {  // If flag=1 then argv[i] had a repeat and therfore printed out a line
            printf("\n");  // Print out new line for the next argument
         }
      }
   }
}