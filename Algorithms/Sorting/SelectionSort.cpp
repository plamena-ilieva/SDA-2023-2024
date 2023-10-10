void selectionSort(int* arr, size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    size_t minElementIndex = i;
			
    for (size_t j = i + 1; j < size; j++)
      if (arr[j] < arr[minElementIndex])
        minElementIndex = j;

    if (i != minElementIndex)
      std::swap(arr[i],  arr[minElementIndex]);
  }	
}	
