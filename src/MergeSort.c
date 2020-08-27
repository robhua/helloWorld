/*
 ============================================================================
 Name        : HelloWorld.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"

// Set values for a integer array from initializer list
int *arr;
int size;
int *sortedArray;

// Merge the elements of 2 sorted array
void mergeTwoSortedArray(int arr1[], int n1, int arr2[], int n2, int result[]) {
	int i = 0, j = 0, k = 0;

	while (i < n1 && j < n2) {
		if (arr1[i] < arr2[j]) {
			result[k++] = arr1[i++];
		} else if (arr1[i] == arr2[j]) {
			result[k++] = arr1[i++];
			result[k++] = arr2[j++];
		} else {
			result[k++] = arr2[j++];
		}
	}

	while (i < n1)
		result[k++] = arr1[i++];

	while (j < n2)
		result[k++] = arr2[j++];
}

int *copyArray(int *array, int size, int index, int number) {
	int *copyArr = malloc(sizeof(int) * (number));
	int i = 0;
	for (; i < number; i++) {
		copyArr[i] = array[i + index];
	}

	return copyArr;
}
// Implement quick sort algorithm
int *old_mergeSort(int *array, int size) {
	if (size < 2) {
		return copyArray(array, size, 0, size);
	}

	int pilot = size / 2;

	int *leftPilot = copyArray(array, size, 0, pilot);
	leftPilot = old_mergeSort(leftPilot, pilot);

	int *rightPilot = copyArray(array, size, pilot, size - pilot);
	rightPilot = old_mergeSort(rightPilot, size - pilot);

	int *result = malloc(sizeof(int) * size);
	mergeTwoSortedArray(leftPilot, pilot, rightPilot, size - pilot, result);
	return result;

}

/* Merge two sub-array of arr[l..r]
 * First sub-array is arr[l..m]
 * Second sub-array is arr[m+1..r]
 */
void merge (int arr[], int l, int m, int r) {
	int i, j, k;

	// Find sizes of two sub-arrays to be merged
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays and copy data to temp arrays
	int L[n1], R[n2];
	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
	}

	// Merge the temp arrays back into arr[l..r]
	i = 0; // Initial index of first sub-array
	j = 0; // Initial index of second sub-array
	k = l; // Initial index of merged sub-array
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}

	// Copy remaining element of L[], if there are any
	while (i < n1) {
		arr[k++] = L[i++];
	}

	// Copy remaining element of R[], if there are any
	while (j < n2) {
		arr[k++] = R[j++];
	}
}
/*
 * l if left index and r is right index of the
 * sub-array of array to be sorted
 */
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		// Find the midle point,
		// Same as (l+r)/2, but avoids overflow for large r and l
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		// Merge the sorted halves
		merge(arr, l, m, r);
	}
}

void test1() {
	int a = 5;
	a = printf ("%s", "Good") + printf ("%s", "Bye");
	printf ("a = %d", a);
}
void test2() {
	printf ("%x", -1 << 4);
}
void test3() {
	int a= 5;
	a = printf ("welcome");
	printf ("%d", a);
}
int main(void) {
//	readDatas();
//	writeDatas();
//	int arr[] = {12, 11, 13, 5, 6, 7};
//	int arr_size = sizeof(arr)/sizeof (arr[0]);
//
//	printf("# Given array \n");
//	printArray(arr, arr_size);
//
////	sortedArray = mergeSort(arr, size);
//	mergeSort(arr, 0, arr_size - 1);
//
//	printf("# Sorted array \n");
//	printArray(arr, arr_size);
//
//	test1();
//	test2();
	test3();
	return EXIT_SUCCESS;
}
