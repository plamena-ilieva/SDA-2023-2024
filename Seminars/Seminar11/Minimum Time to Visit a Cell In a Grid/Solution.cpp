class Solution {
public:
    int minimumTime(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n,vector<int>(m,1e9));

        if(grid[0][1]>grid[0][0]+1 && grid[1][0]>grid[0][0]+1)
        {
            return -1;
        }

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;

        pq.push({0,{0,0}});

        int nr[] = {-1,0,1,0};
        int nc[] = {0,1,0,-1};

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i=0;i<4;i++)
            {
                int x = r + nr[i];
                int y = c + nc[i];

                if(x>=0 && x<n && y>=0 && y<m)
                {
                    int ntime;

                    if(time + 1 < grid[x][y])
                    {
                        ntime = grid[x][y];

                        if(((time+1)+ntime)%2)
                        {
                            ntime++;
                        }
                    }

                    else
                    {
                        ntime = time+1;
                    }

                    // We will go back and forth with prev. node till time will be
                    // greater or equal
                    if(ntime < res[x][y])
                    {
                        res[x][y]=ntime;
                        pq.push({ntime,{x,y}});
                    }
                }
            }
        }

        if(res[n-1][m-1]==INT_MAX)
        {
            res[n-1][m-1]=-1;
        }
        return res[n-1][m-1];
    }
};