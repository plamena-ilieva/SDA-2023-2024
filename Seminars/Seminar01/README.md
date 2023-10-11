```cpp
int factorial(int n) {
        if (n <= 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
```
O(n)
```cpp
int fibonacci(int n) { 
	if (n <= 0) { 
		return  0; 
	} else  if (n == 1) { 
		return  1; 
	} else { 
	return  fibonacci(n - 1) + fibonacci(n - 2); 
	} 
}
```
O(1,6^n)
```cpp
int recursiveSum(int arr[], int n) { 
	if (n == 0) { 
		return  0; 
	} else { 
		return arr[0] + recursiveSum(arr + 1, n - 1); 				} 
}
```
O(n)
```cpp
int recursiveBinarySearch(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return recursiveBinarySearch(arr, target, mid + 1, right);
    } else {
        return recursiveBinarySearch(arr, target, left, mid - 1);
    }
}

```
O(log(n))
```cpp
void towersOfHanoi(int n, char source, char auxiliary, char target) { 
	if (n == 1) { 
		cout << "Move disk 1 from " << source << " to " << target << endl; 
		return; 
	} 
	towersOfHanoi(n - 1, source, target, auxiliary);
	cout << "Move disk " << n << " from " << source << " to " << target << endl; 
	towersOfHanoi(n - 1, auxiliary, source, target); 
}
```
O(2^n)
