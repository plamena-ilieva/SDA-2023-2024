#include <iostream>

const int MAX_NUM = 1e5;
const int MAX_SIZE = 1e6;

int arr[MAX_SIZE];
int count[MAX_NUM]{};

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        count[arr[i]]++;
    }

    for (int i = 1; i < MAX_NUM; ++i)
    {
        count[i] += count[i - 1];
    }

    int *result = new int[n];
    for (int i = n - 1; i >= 0; --i)
    {
        result[i] = --count[arr[i]];
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << result[i] << " ";
    }

    delete[] result;
    return 0;
}
