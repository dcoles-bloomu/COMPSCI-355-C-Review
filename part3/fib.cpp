/*
 * Outputs the first 20 Fibonacci numbers.
 *
 * Points of discussion: partial initialization of an array and array
 * arguments passed by reference.
 *
 * Execution snapshot: see end of file.
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <iomanip>
using namespace std;

// fills an array with the first n Fibonacci numbers
void fib_fill(int [], int n);

// outputs contents of an array of size n
void print(const int [], int n);

int main() {
   const int N = 25;
   int a[N] = {0, 1}; // first two terms of Fibonacci sequence
   fib_fill(a, N);
   print(a, N);
   delete[] a;
   return 0;
}

void fib_fill(int a[], int n) {
   for (int k = 2; k < n; k++) {
      a[k] = a[k - 1] + a[k - 2];
   }
}

void print(const int a[], int n) {
   for (int k = 0; k < n; k++) {
      cout << setw(2) << k << ". " << a[k] << endl;
   }
}

/**********
 0. 0
 1. 1
 2. 1
 3. 2
 4. 3
 5. 5
 6. 8
 7. 13
 8. 21
 9. 34
10. 55
11. 89
12. 144
13. 233
14. 377
15. 610
16. 987
17. 1597
18. 2584
19. 4181
20. 6765
21. 10946
22. 17711
23. 28657
24. 46368
**********/