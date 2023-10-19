#include <iostream>
#include <vector>
#include <valarray>

bool OK(const std::vector<size_t> &v, size_t seconds, size_t sheets) {
    size_t sum = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        sum += seconds/v[i];
    }
    return sum >= sheets;
}

size_t binarySearch(const std::vector<size_t> &v, size_t left, size_t right, long long sheets) {
    size_t ans = right;
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        if (OK(v, mid, sheets)) {
            ans = std::min(ans,mid);
            right = mid - 1;
        } else
            left = mid + 1;
    }
    return ans;
}

size_t binarySearch(const std::vector<size_t> &v, long long sheets) {
    auto slowest = std::max_element(v.begin(), v.end());
    size_t max = sheets/v.size()*(*slowest)+1;
    auto fastest = std::min_element(v.begin(), v.end());
    size_t min = sheets/v.size()*(*fastest);
    return binarySearch(v, min, max, sheets);
}

int main() {
    
    size_t count;
    size_t sheets;
    std::cin >> sheets >> count;
    std::vector<size_t> printers(count);

    for (size_t i = 0; i < count; ++i)
        std::cin >> printers[i];

    std::cout << binarySearch(printers, sheets);

    return 0;
}
