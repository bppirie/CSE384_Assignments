#include <stdio.h>
#include <string.h>

/* Bradley Pirie
   CSE384
   Homework 6
   Problem 10

   Write code to “de-vowel” an input string. Assume that the user provides input
   containing only the characters a through z (and all lowercase). Your code should
   create an output string that deletes all vowels from the input string, pushing the
   letters together to fill any gaps. For example, given the input “theturtleandthehare” 
   your code should print out “thtrtlndthhr”
*/

int main() {
   char input[80], output[80];
   printf("Enter a string: ");
   scanf("%s",input);
   int i, j;      // i goes through input[] and j goes through output[]
   for (i = j = 0; input[i] != '\0'; i++) {     // Iterate through input[]
      char c = input[i];      // Save current char as c
      if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {   // Make sure c is not a vowel
         output[j] = c;    // If c is not a vowel then copy it to output[]
         j += 1;           // Increment j
      }
   }
   output[j] = '\0';       // After iterating through input[], end output[] with null char
   printf("%s", output);
   return 0;
}