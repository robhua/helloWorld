#include <stdio.h>
#include <stdlib.h>

//##########################################
void printArray(int [], int );
int* readArray(char []);
void writeArray(int [], int , char []);
//##########################################

/* A utility function to print an array */
void printArray(int arr[], int arr_size) {
	int i;
	for (i = 0; i < arr_size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


// Reading datas to array
int* readArray(char file_name[]) {
	FILE *myFile = fopen(file_name, "r");

	int n;
	fscanf(myFile, "%d\n", &n);
	int *arr = malloc(sizeof(int) * n);

	int i;
	for (i = 0; i < n; i++) {
		fscanf(myFile, "%d", &arr[i]);
	}
	fclose(myFile);

	return arr;
}

//Write data in file
void writeArray(int arr[], int n, char file_name[]) {
	//Open the file in write mode
	FILE *myFile = fopen(file_name, "w");

	//Write size of the array
	fprintf(myFile, "%d\n", n);

	//Write elements of the array
	int i = 0;
	for (; i < n; i++) {
		fprintf(myFile, "%d ", arr[i]);
	}
	fclose(myFile);
}
