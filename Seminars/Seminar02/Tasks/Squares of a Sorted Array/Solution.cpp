class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int l = 0, r = A.size() - 1;
        for (int k = A.size() - 1; k >= 0; k--) {
            if (abs(A[r]) > abs(A[l])) 
              res[k] = A[r] * A[r--];
            else 
              res[k] = A[l] * A[l++];
        }
        return res;
    }
};
