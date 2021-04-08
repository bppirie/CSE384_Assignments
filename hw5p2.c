#include <stdio.h>
#include <string.h>

/* Write a function escape(s,t) that converts characters like newline and tab into
   visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
   function for the other direction as well, converting escape sequences into the real characters.
*/

void escape(char s[], char t[]) {
   int i, j;
   for (i = j = 0; t[i] != '\0'; i++) {
      switch (t[i]) {
         case '\n':
            s[j] = '\\';
            j += 1;
            s[j] = 'n';
            j += 1;
            break;
         case '\t':
            s[j] = '\\';
            j += 1;
            s[j] = 't';
            j += 1;
            break;
         default:
            s[j] = t[i];
            j +=1;
            break;
      }
   }
   s[j] = '\0';
   printf("%s", s);
}


void escape_reverse(char s[], char t[]) {
   int i, j;
   for (i = j = 0; t[i] != '\0'; i++) {
      if (t[i] == '\\') {
         i += 1;
         switch (t[i]) {
            case 'b':
               s[j] = '\b';
               j += 1;
               break;
            case 'n':
               s[j] = '\n';
               j += 1;
               break;
            case 'r':
               s[j] = '\r';
               j += 1;
               break;
            case 't':
               s[j] = '\t';
               j += 1;
               break;
            case 'v':
               s[j] = '\v';
               j += 1;
               break;
         }
      }
      else {
         s[j] = t[i];
         j += 1;
      }
   }
   s[j] = '\0';
   printf("%s", s);
}

int main() {
   char string1[] = "\\tWhat is good\\nmy dude";
   char string2[50];
   printf("%s\n", string1);
   escape_reverse(string2, string1);
}
