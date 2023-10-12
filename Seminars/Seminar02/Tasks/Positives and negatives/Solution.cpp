template <typename T>
int partition(T* arr, int len, T pivot) {
	int i = 0, j = len - 1;

	while (true) {
		while (arr[j] > pivot)
			j--;
		while (arr[i] < pivot)
			i++;

		if (i < j)
			std::swap(arr[i], arr[j]);
		else
			return j;
	}
}

void positivesAndNegatives(int* X, size_t len) {
	partition<int>(X, len, 0);
}
