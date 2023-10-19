class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        int left = 0 , right = nums.size()-1;
        if(nums[left] < nums[right]){
            return nums[left];
        }
        while(left <= right){
            if(nums[left] < nums[right]){
                ans = min(ans , nums[left]);
                break;
            }

            int mid = left + (right - left)/2;
            ans = min(ans , nums[mid]);

            if(nums[mid] >= nums[left])
                left = mid + 1;
            else 
                right = mid -1 ;
            
            
        }

        return ans;
        
    }
};
