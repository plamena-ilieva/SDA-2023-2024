int kk = 0;

bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[kk] > v2[kk]; 
    }

class Solution {
public:

    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        kk = k;
        sort(score.begin(), score.end(), cmp);
        return score;
    }
};
