#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool OK(vector<int>& v, int towersCnt, int k)
{
    vector<bool> covered(v.size(), 0);
    for(int i=0; i<v.size(); ++i)
    {
        if(!covered[i])
        {
            int j = i;
            --towersCnt;
            while(v[j] <= v[i] + k && j < v.size())
            {
                covered[j++] = 1;
            }
            --j;
            int l = j+1;
            while(v[l] <= v[j] + k && l < v.size())
            {
                covered[l++] = 1;
            }
        }
    }
    return towersCnt >= 0;
}

int binarySearch(vector<int>& v, int k)
{
    int left = 0, right = v.size(), result;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(OK(v, mid, k))
        {
            result = mid;
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return result;
}

int main()
{
    int k, n;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
    {
        cin>>v[i];
    }
    int ans = 0;
    sort(v.begin(), v.end());
    cout<<binarySearch(v, k);
}
