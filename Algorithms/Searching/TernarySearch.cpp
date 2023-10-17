int ternarySearch(const int* arr, int len, int x) {
  int left = 0;
  int right = len - 1;
  while (right >= left) {
        int mid1 = left + (right - left) / 3; 
        int mid2 = right - (right - left) / 3;
 
        if (arr[mid1] == x) return mid1; 
        if (arr[mid2] == x) return mid2; 

        if (x < arr[mid1]) 
            right = mid1 - 1;
        else if (x > arr[mid2]) 
            left = mid2 + 1;
        else {
            left = mid1 + 1;
            right = mid2; 
        }
    }
    return -1;
}
