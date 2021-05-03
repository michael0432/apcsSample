#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, tmp;
    cin >> N >> M;
    vector<int> res;
    vector<int> ans;
    int sum = 0;
    for(int i=0; i<N; i++)
    {
        int maxnum = -1;
        for(int j=0; j<M; j++)
        {
            cin >> tmp;
            maxnum = max(tmp, maxnum);
        }
        sum += maxnum;
        res.push_back(maxnum);
    }
    cout << sum << endl;
    for(int i=0; i<res.size(); i++)
    {
        if(sum % res[i] == 0)
        {
            ans.push_back(res[i]);
        }
    }
    if(ans.size() == 0) cout << "-1" << endl;
    else
    {
        for(int i=0; i<ans.size(); i++)
        {
            cout << ans[i];
            if(i != ans.size()-1) cout << " ";
        }
        cout << endl;
    }
}