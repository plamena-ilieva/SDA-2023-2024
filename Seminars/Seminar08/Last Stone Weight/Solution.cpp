class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        int a,b;
        priority_queue<int>pq(stones.begin(), stones.end());

        while(pq.size()!=1)
        {
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            int c=a-b;
            pq.push(c);
        }
        return pq.top();
    }
};