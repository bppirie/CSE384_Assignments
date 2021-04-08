#include <stdio.h>
#include <string.h>

/* Write an alternative version of squeeze(s1,s2) that deletes each character in s1
   that matches any character in the string s2.
*/

void squeeze(char s1[], char s2[]) {
   
   int i, j, k;
   for (i = j = 0; s1[i] != '\0'; i++) {
      int count = 0;
      for (k = 0; s2[k] != '\0'; k++) {
         if (s1[i] == s2[k]) {
            count = 1;
            break;
         }
      }
      if (count == 0) {
         s1[j] = s1[i];
         j += 1;
      }
   }
   s1[j] = '\0';
   printf("%s", s1);
   
}

int main() {
   char string1[] = "Whats good family?";
   char string2[] = "ad";
   squeeze(string1, string2);
}