#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void trace(int p, vector<int>& friends, vector<bool>& traced)
{
    if(traced[p]) return;
    else
    {
        traced[p] = true;
        trace(friends[p], friends, traced);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> friends(N);
    vector<bool> traced(N, false);
    int groups = 0;
    for(int i=0; i<N; i++)
    {
        cin >> friends[i];
    }
    for(int i=0; i<N; i++)
    {
        if(!traced[i])
        {
            trace(i, friends, traced);
            groups++;
        }
    }
    cout << groups << endl;
}