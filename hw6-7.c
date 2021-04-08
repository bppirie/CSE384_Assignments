#include <stdio.h>
#include <string.h>

/* Bradley Pirie
   CSE384
   Homework 6
   Problem 7

   Write code to split an input string (variable “name”) into two output strings
   (variables “first” and “last”). Assume that the user provides input containing
   only the characters a through z and A through Z. Assume there are exactly two
   capital letters in the input, one at the beginning of the first name, and one at
   the beginning of the last name. For example, given the input “JoeSmith”, your
   code should split it into “Joe” and “Smith”
*/

int main() {
   char name[50], first[25], last[25];
   printf("What is your name? ");
   scanf("%s",name);
   int flag = 0;        // flag=0 is first name, flag=1 is last name
   int j = 0;           // j will go through last[]
   first[0] = name[0];  // Place first capital letter from first name in first[]
   for (int i = 1; name[i] != '\0'; i++) {   // iterate through input starting with second letter
      char c = name[i]; // Save current letter as c
      if (c >= 'A' && c <= 'Z') { // Check if c is capital, if it is then we have reached the first letter of last name
         first[i] = '\0';     // End first[] with null char
         last[j] = c;         // Place the capital in last[]
         j += 1;              // Increment j
         flag = 1;            // Set flag=1 to know we are in the last name
      }
      else if (flag == 0) {   // If flag is 0 then copy name[] to first[]
         first[i] = c;
      }
      else {                  // If flag is 1 then copy name[] to last[] and increment j
         last[j] = c;
         j += 1;
      }
   }
   last[j] = '\0';            // After iterating through name[], end last[] with null char
   printf("%s\n", first);
   printf("%s", last);
   return 0;
}
