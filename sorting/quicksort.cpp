/* Quicksort is a fast sorting algorithm, widely applied in practice.
On average, it has O(n log n) complexity. At best, it has O(n log n) 
complexity. At worst, it has O(n^2) complexity. 

The algorithm is as follows:
(1) Choose Pivot Value
	- We take the value of the middle element as a pivot value, but it
	can be any value, which is in range of the sorted values, even if it 
	isn't present in the array.
(2) Partition
	- Rearrange elements in such a way, that all elements which are 
	lesser than the pivot go to the left part of the array and all 
	elements greater than the pivot go to the right part of the array.
	Values equal can stay in any part of the array.
	---> Array may be divided into unequal parts.
(3) Sort Both Parts
	- Apply the quicksort algorithm recursively to the left and right 
	parts. */

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left+right) / 2];

	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j++;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

