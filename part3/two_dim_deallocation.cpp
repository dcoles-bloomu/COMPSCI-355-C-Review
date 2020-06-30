/*
 * Dynamically allocates a 2D array and initializes it as a multiplication
 * table.
 *
 * Point of discussion: deallocating 2D arrays.
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <iomanip>
using namespace std;

int n;
int** a;

void init(); // initialize array with the value i * j in cell (i, j).
void print(); // print contents of the array as a table
void release(); // release dynamically allocated memory (causes memory leak)
void release2(); // release dynamically allocated memory (correct version)

int main() {
    cout << "Enter array size: ";
    cin >> n;
    init();
    print();
    release2();
}

void init() {
    a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = i * j;
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }
}

void release() {
    delete []a; // MEMORY LEAK
}

void release2() {
    for (int i = 0; i < n; i++) {
        delete []a[i]; // delete each row
    }
    delete []a; // delete array of rows
}