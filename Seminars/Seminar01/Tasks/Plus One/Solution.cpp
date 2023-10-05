class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = digits[digits.size() - 1] + 1;
        digits[digits.size() - 1] = sum % 10;
        bool one = sum >= 10;

        for (int i = digits.size() - 2; i >= 0 && one; i--) {
            int sum = digits[i] + oneInMind;
            digits[i] = sum % 10;
            one = sum >= 10;
        }
        if (one) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
