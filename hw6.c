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
   int flag = 0;
   int j = 0;
   scanf("%s",name);
   char fst = name[0];
   first[0] = fst;
   for (int i = 1; name[i] != '\0'; i++) {
      char c = name[i];
      if (c >= 'A' && c <= 'Z') {
         first[i] = '\0';
         last[j] = c;
         j++;
         flag = 1;
      }
      else if (flag == 0) {
         first[i] = c;
      }
      else {
         last[j] = c;
         j++;
      }
   }
   last[j] = '\0';
   printf("%s\n", first);
   printf("%s", last);

}
