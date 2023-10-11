size_t partition(int* arr, size_t size) {
	int pivot = arr[size / 2];

	int i = 0;
	int j = size - 1;

	while (true) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i < j)
			std::swap(arr[i], arr[j]);
		else
			return j;
	}
}

void quickSort(int* arr, size_t size) {
    if (size < 2)
        return;
    size_t pivotIndex = partition(arr, size);       

    quickSort(arr, pivotIndex);
    quickSort(arr + pivotIndex + 1, size - pivotIndex - 1);
}
