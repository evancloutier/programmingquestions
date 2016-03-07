/* You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order. */
#include <iostream>

void merge(int a[], int lastA, int b[], int lastB) {
    int index = lastB + lastA + 1;
    while (index >= 0) {
        if (a[lastA] > b[lastB]) {
            a[index] = a[lastA];
            lastA--;
        }
        else {
            a[index] = b[lastB];
            lastB--;
        }
        index--;
    }
}