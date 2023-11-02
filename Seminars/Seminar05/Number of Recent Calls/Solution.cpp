class RecentCounter {
public:
    queue<int>q;
    RecentCounter() { }

    int ping(int t) {
        int st = t - 3000;
        q.push(t);

        while (!q.empty()) {
            if (q.front() < st)
                q.pop();
            else
                break;
        }

        return q.size();

    }
};