#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
//0 0 1 0 1 0 0 1

int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int res=0;
        unordered_map<int,int>m;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k)
                res = max(res, i+1);
            if(m.find(sum-k) != m.end())
                res = max(i - m[sum-k], res);
            else 
                m[sum-k] = i;
        }
       
        return res;
    }

int main() {
    int n; 
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        int curr;
        cin >> curr;
        if (curr == 0) {
            nums[i] = -1;
        }
        else {
            nums[i] = 1;
        }
    }
    
    cout << subarraySum(nums, 0);
    return 0;
}
