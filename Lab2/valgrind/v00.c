#include <stdlib.h>

void f ()
 {
  int *x;
  x =（int *)malloc(10 * sizeof(int));
  x[9] = 0;
  free(x);
 }

int main ()
 {
  f();
  return 0;
 }
