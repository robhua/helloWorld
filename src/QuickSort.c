#include <stdio.h>
#include <stdlib.h>

/*This function takes last element as pivot,
 * places the pivot at its correction position
 * places all element smaller than pivot to left of pivot and
 * places all element greater to right pivot.
 */
int partition(int arr[], int low, int high) {
	int i = low - 1;
	// TODO Implement quicksort
	return i;
}
/*The main function that implement Quicksort
 * arr[] --> Array to be sorted
 * low --> Starting index
 * high --> Ending index
 */
void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		// Call recursively two halves
		QuickSort(arr, low, pi-1);
		QuickSort(arr, pi-1, high);
	}
}
