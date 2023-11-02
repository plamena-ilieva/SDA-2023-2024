class Solution {
public:

    vector<int> maxSlidingWindow(const std::vector<int>& v, size_t k) {
        deque<int> window;
        vector<int> result;

        for (size_t i = 0; i < k; i++) {
            while (!window.empty() && window.back() < v[i]) {
                window.pop_back();
            }
            window.push_back(v[i]);
        }

        result.push_back(window.front());

        for (size_t i = k; i < v.size(); i++) {
            if (window.front() == v[i - k]) {
                window.pop_front();
            }

            while (!window.empty() && window.back() < v[i]) {
                window.pop_back();
            }

            window.push_back(v[i]);
            result.push_back(window.front());
        }

        return result;
    }
};