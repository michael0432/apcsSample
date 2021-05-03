#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> people;
    for(int i=1; i<=N; i++)
    {
        people.push_back(i);
    }
    int start_idx = 0;
    for(int i=0; i<K; i++)
    {
        int del_idx = (start_idx + M - 1) % people.size();
        people.erase(people.begin() + del_idx);
        start_idx = del_idx % people.size();
    }
    cout << people[start_idx] << endl;
}
    