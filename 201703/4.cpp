#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool TrytoPut(int d, vector<int>& v, int total)
{
    int cover_idx = 0;
    int cover_range = -1;
    int num = 0;
    while(cover_idx < (int)(v.size()))
    {
        cover_range = v[cover_idx] + d;
        num++;
        if(num > total) return false;
        else if(cover_range >= v[v.size()-1]) return true;
        while(cover_idx < v.size() && cover_range >= v[cover_idx]) cover_idx++;
    }
    return true;
}

int main()
{
    int N,K;
    while(cin >> N >> K){
        
        vector<int> v(N, 0);
        for(int i=0; i<N; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int minD = 1, maxD = v[N-1] - v[0], mid = (minD + maxD) / 2;
        int result = maxD;
        // binary search
        if(K == 1)
        {
            cout << maxD << endl;
            continue;
        } 
        while(minD < maxD)
        {
            mid = (minD + maxD) / 2;
            if(TrytoPut(mid, v, K)) maxD = mid;
            else minD = mid + 1;
        }
        cout << maxD << endl;
    }
}