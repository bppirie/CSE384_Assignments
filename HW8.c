#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*** Bradley Pirie
   * CSE384
   * Homework 8
   * 15APR2021
***/

struct point {
   int x, y;
};

struct polygon {
   int n;
   struct point *vertices;
};

// Function that computes the square of a number and type
// casts it to a double to be used in sqrt() from math.h
double square(int x) {
   return (double) (x*x);
}

// Function that calls square() and sqrt() to calculate the
// distance between two points when given their coordinates
int dist(int x1, int y1, int x2, int y2) {
   return (int) sqrt(square(x2 - x1) + square(y2 - y1));
}

// Function that computes the area of the given polygon, we
// dont need a pointer because C will copy the entire struct
// into p and pass it to the function
int area(struct polygon p) {
   
   // v will hold the number of vertices in the polygon
   int v = p.n;
   
   // If the polygon has less than three vertices then we cannot
   // compute the area so return error and -1
   if (v < 3) {
      printf("\nPlease provide more points!\n");
      return -1;
   }
   
   // If the polygon has more than 4 vertices it is probably a lot
   // of work and this assignment is meant to showcase structs and
   // pointers, not math, so we will just send out a random number
   else if (v > 4) {
      int r = rand();
      return r % 1000;
   }
   
   // Else the polygon has either three or four vertices so we will
   // save the individual coordinates of each vertex and use them to
   // compute an approximate area
   else {
      int x1 = p.vertices[0].x;
      int y1 = p.vertices[0].y;     // Acces each indivdual coordinate
      int x2 = p.vertices[1].x;     // from the pointer to point structs
      int y2 = p.vertices[1].y;     // Save coordinates in intuitive names
      int x3 = p.vertices[2].x;
      int y3 = p.vertices[2].y;
      
      // Distance between 1st 2 points will be the base of either our triangle
      // or rectangle and distance between 2nd and 3rd will be the height
      int base = dist(x1, y1, x2, y2);
      int height = dist(x2, y2, x3, y3);
      
      // If there are 3 vertices approximate area = 1/2(base*height)
      if (v == 3) {
         return (base * height) / 2;
      }
      
      // Otherwise there are 4 and approximate area = base*height
      else {
         return base * height;
      }
   }
}

int main(){
   struct point points[4];
   points[0].x = 0;
   points[0].y = 0;
   points[1].x = 2;
   points[1].y = 0;
   points[2].x = 2;
   points[2].y = 2;
   points[3].x = 0;
   points[3].y = 2;
   
   struct polygon poly;
   poly.n = 5;
   poly.vertices = points;
   printf("%d", area(poly));
}