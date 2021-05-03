#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    string x;
    cin >> x;
    int odd_sum = 0, ev_sum = 0;
    bool b = false;
    for(int i=0; i<x.size(); i++)
    {
        if(i % 2 == 0) odd_sum += x[i] - '0';
        else ev_sum += x[i] - '0';
    }
    cout << (odd_sum > ev_sum ? odd_sum - ev_sum : ev_sum -odd_sum) << endl;
}