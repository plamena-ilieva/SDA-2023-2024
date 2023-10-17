int binarySearch(const int* arr, int len, int searched)
{
	int left = 0;
	int right = len - 1;
  int anw = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		
		if (arr[mid] > searched)
			right = mid - 1;
		else {
      ans = mid;
			left = mid + 1;
    }
	}
	return -1;

}
