size_t getInsertedIndex(const int* X, const int* Y, size_t xLen, size_t start, size_t end)
{
	size_t mid = start + (end - start) / 2;

	if (Y[mid] == -1)
		return mid;

	if (Y[mid] == X[mid])
		return getInsertedIndex(X, Y, xLen, mid + 1, end);
	else
		return getInsertedIndex(X, Y, xLen, start, mid - 1);
}
