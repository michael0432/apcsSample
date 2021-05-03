#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int m;
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    int best = -1, worst = -1;
    for(int i=0; i<n; i++)
    {
        if(v[i] < 60)
        {
            best = v[i];
        }
        else
        {
            worst = v[i];
            break;
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<v[i];
        if(i != n-1) cout<<" ";
    }
    cout << endl;
    if(best != -1) cout << best << endl;
    else cout << "best case" << endl;
    if(worst != -1) cout << worst << endl;
    else cout << "worst case" << endl;
}