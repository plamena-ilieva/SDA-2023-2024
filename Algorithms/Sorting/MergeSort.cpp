void merge(int* arr, size_t lenOne, int* arr2, size_t lenTwo) {
	int* resultArray = new int[lenOne + lenTwo];

	int pntOne = 0;
	int pntTwo = 0;
	int resArrayIndex = 0;

	while (pntOne < lenOne && pntTwo < lenTwo) {
		if (arr[pntOne] <= arr2[pntTwo])
			resultArray[resArrayIndex++] = arr[pntOne++];
		else
			resultArray[resArrayIndex++] = arr2[pntTwo++];
	}

	while (pntOne < lenOne)
		resultArray[resArrayIndex++] = arr[pntOne++];

	while (pntTwo < lenTwo)
		resultArray[resArrayIndex++] = arr2[pntTwo++];

	for (int i = 0; i < lenOne + lenTwo; i++)
		arr[i] = resultArray[i];

	delete[] resultArray;
}

void mergeSort(int* arr, size_t size) {
    if(size < 2)
        return;
        
    size_t mid = size / 2;    
    mergeSort(arr, mid);
    mergeSort(arr + mid, size - mid);
    merge(arr, mid, arr + mid, size - mid);
}
