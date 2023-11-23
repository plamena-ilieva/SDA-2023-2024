class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int, vector<int>, greater<int>>
        pq(nums.begin(), nums.begin()+k);

        for (int i=k; i<n; i++){
            pq.push(nums[i]);
            pq.pop();
        }
        return pq.top();
    }
};