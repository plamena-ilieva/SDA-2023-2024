int upperBound(const int* arr, int len, int searched)
{
	int left = 0;
	int right = len - 1;
  int ans = -1;
  
	while (left <= right)
	{
		int mid = (left + right) / 2;
		
		if (arr[mid] > searched)
			ans = mid;
      right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;

}
