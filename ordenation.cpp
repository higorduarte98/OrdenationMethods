#include "ordenation.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int* randomGenerator(unsigned long n){
    srand (time(NULL));

    int *v = new int [n];
    
    for(int i = 0; i < n; i++)
        v[i] = rand() % n;

    return v;
}

int* growingGenerator(unsigned long n){
    int *v = new int [n];
    for(unsigned long i = 1; i <= n; i++)
        v[i - 1] = i;
    return v;
}

int* descendingGenerator(unsigned long n){   
    int *v = new int [n];

    for(unsigned long i = n; i > 0; i--)
        v[n - i] = i;

    return v;
}

void bubbleSort(int *v, unsigned long n){
    unsigned long aux, i, j;

    for (i = 0; i < n; i++){
        for(j = 1; j < n - i; j++){
            if(v[j] < v[j-1]){
                aux = v [j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
}

void selectionSort(int *v, unsigned long n){
    unsigned long min, aux, i, j;

    for (i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++)
            if(v[j] < v[min])
                min = j;
            aux = v[min];
            v[min] = v[i];
            v[i] = aux;
    }
}

void insertionSort(int *v, unsigned long n){
    unsigned long aux, j, i;

    for (i = 1; i < n; i++){
        aux = v[i];
        j = i - 1;
        while(j >= 0 && aux < v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}

void mergeSortRecursive(int *v, unsigned long n, int left, int right){
    if (left >= right) return;

    unsigned long half = (left + right) / 2;
    mergeSortRecursive(v, left, half, n);
    mergeSortRecursive(v, half + 1, right, n);
    mergeSortIntercalate(v, left, half, right);
}

void mergeSortIterative(int *v, unsigned long n){
    unsigned long left, right;
    unsigned long b = 1;
    while (b < n){
        left = 0;
        while(left + b < n){
            right = left + 2 * b;
            if (right > n) right = n;
            mergeSortIntercalate(v, left, left+b-1, right-1);
            left = left + 2 * b;
        }
        b *= 2;
    }
}

void mergeSortIntercalate(int *v, int left, int half, int right){
    unsigned long k,i,j;
    unsigned long size_left = half-left+1;
    unsigned long size_right = right - half;
    int *v_left = new int [size_left];
    int *v_right = new int [size_right];

    for(i = 0; i < size_left; i++)
        v_left[i] = v[i+left];
    for(i = 0; i < size_right; i++)
        v_right[i] = v[i+half+1];

    k = left;

    for(i = 0, j = 0, k = left; k <= right; k++){
        if(i == size_left){
            v[k] = v_right[j++];
        }
        else if(j == size_right){
            v[k] = v_left[i++];
        }
        else if(v_left[i] < v_right[j]){
            v[k] = v_left[i++];
        }
        else{
            v[k] = v_right[j++];
        }
    }

    delete v_left;
    delete v_right;
}

void radixsort(int* v, unsigned long n, int base){

	int biggestElement = v[0];
	int count[11];
	unsigned long k=1;
	short digit=0;
	short quotient=0;
	int divider = 1;
	int* vAux = new int[n];
	int position;
	

	for(unsigned long i = 0; i < n; i++)
	{
		if(v[i] > biggestElement)
		{
			biggestElement = v[i];
		}	
	}

	while(biggestElement/divider > 0)
	{
		for (unsigned long j = 0; j < base; j++)
			count[j] = 0;

		for (unsigned long i = 0; i < n; i++)
		{
			quotient = v[i];
			for(int aux = 0; aux < k; aux++)
			{
				digit = quotient % base;
				quotient = quotient / base;
			}
			count[digit+1]++;	
		}

		for(unsigned long j = 1; j < base; j++)
			count[j] += count[j-1];

		for(unsigned long i = 0; i < n; i++)
		{
			quotient = v[i];
			for(unsigned long aux = 0; aux < k; aux++)
			{
				digit = quotient % base;
				quotient = quotient / base;
			}

			position = count[digit];
			count[digit]++;

			vAux[position] = v[i];
		}

		for(unsigned long i = 0; i < n; i++)
		{
			v[i] = v[i];
		}

		divider *= 10;
		k++;
	}

	delete [] vAux;
}