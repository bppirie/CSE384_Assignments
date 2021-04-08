#include <stdio.h>
#include <string.h>

int main(){
   char s[20] = "one";
   char t[20] = "two";
   int i, j;
   i=j=0;
   while (s[i++] != '\0') {
      ;
   }
   while (t[j] != '\0') {
      s[i++] = t[j++];
   }
   printf("%s\n", s);
}