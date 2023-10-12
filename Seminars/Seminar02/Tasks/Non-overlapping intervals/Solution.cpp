class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort by x
        sort(intervals.begin(), intervals.end()); 
    
        vector<int> prev=intervals[0];
        int num = -1;
        for(vector<int>& curr: intervals){
            if (curr[0] < prev[1] && curr[1] <= prev[1]) {
                num++;
                prev=curr;
            }
            else if(curr[0] < prev[1] && curr[1] > prev[1])
                num++;
            else 
                prev = curr;
        }
        return num; 
    }
};
