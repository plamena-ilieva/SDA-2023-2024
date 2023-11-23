class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char &ch: tasks) freq[ch-'A']++;
        priority_queue<int> pq;
        for (int i=0; i<26; i++) {
            if (freq[i] > 0 )
                pq.push(freq[i]);
            }

        int time=0;
        while (!pq.empty()) {
            int cycle = n+1; //length of each cycle
            vector<int> store;

            int temp = 0;
            //while the cycle is not over or there aro no more unque tasks
            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1)
                    store.push_back(pq.top()-1);
                pq.pop();
                temp++;
            }
            for (int &x: store)
                pq.push(x);
            time += (pq.empty() ? temp : n+1);
        }
        return time;
    }
};