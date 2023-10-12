class Solution {
public:

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> bloomTime;

        for(int i = 0; i < plantTime.size(); i++){
            bloomTime.push_back({growTime[i], plantTime[i]});
        }
        sort(bloomTime.rbegin(), bloomTime.rend());

        int maxDayBloom = 0;
        int dayPassed = 0;
        for(pair<int,int>& bloom : bloomTime){
            dayPassed += bloom.second;
            maxDayBloom = max (maxDayBloom, dayPassed + bloom.first);
        }
        return maxDayBloom;

    }
};
