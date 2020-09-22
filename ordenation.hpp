#ifndef ORDENATION_HPP_
#define ORDENATION_HPP_
int *growingGenerator(unsigned long n);
int *descendingGenerator(unsigned long n);
int *randomGenerator(unsigned long n);
void bubbleSort(int *v, unsigned long n);
void selectionSort(int *v, unsigned long n);
void insertionSort(int *v, unsigned long n);
void mergeSortRecursive(int *v, unsigned long n, int left, int right);
void mergeSortIterative(int *, unsigned long n);
void mergeSortIntercalate(int *v, int left, int half, int right);
void radixsort(int* v, unsigned long n, int base);
#endif
