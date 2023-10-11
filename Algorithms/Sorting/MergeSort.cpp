void merge(int* arr, size_t lenOne, int* arr2, size_t lenTwo, int* buffer) {
	int pntOne = 0;
	int pntTwo = 0;
	int bufferIndex = 0;

	while (pntOne < lenOne && pntTwo < lenTwo) {
		if (arr[pntOne] <= arr2[pntTwo])
			buffer[bufferIndex++] = arr[pntOne++];
		else
			buffer[bufferIndex++] = arr2[pntTwo++];
	}

	while (pntOne < lenOne)
		buffer[bufferIndex++] = arr[pntOne++];

	while (pntTwo < lenTwo)
		buffer[bufferIndex++] = arr2[pntTwo++];

	for (int i = 0; i < lenOne + lenTwo; i++)
		arr[i] = buffer[i];
}

void mergeSortStep(int* arr, size_t size, int* buffer) {
    if(size < 2)
        return;
        
    size_t mid = size / 2;    
    mergeSortStep(arr, mid, buffer);
    mergeSortStep(arr + mid, size - mid, buffer);
    merge(arr, mid, arr + mid, size - mid, buffer);
}

void mergeSort(int* arr, size_t size)
{
	if (!arr || size == 0)
		return;

	int* pBuffer = new int[size];

	mergeSortStep(pArr, Size, pBuffer);

	delete[]  pBuffer;
}
