void insertionSort(int* v, size_t size) { 
  for (size_t i = 1; i < size; i++) {
    int elem = v[i]; int j = i - 1;

    while (j != -1 && v[j] > elem) { 
      v[j + 1] = v[j];
      j--;
    }

    std::swap(v[j + 1], elem);
  }
}
