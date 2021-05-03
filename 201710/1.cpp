#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, target, cnt = 0;
    cin >> a >> b >> target;
    if((a && b) == target)
    {
        cnt++;
        cout << "AND" << endl;
    }
    if((a || b) == target)
    {
        cnt++;
        cout << "OR" << endl;
    }
    int mxor = ((a!=0 && b==0) || (a == 0 && b != 0));
    if(mxor == target)
    {
        cnt++;
        cout << "XOR" << endl;
    }
    if(cnt == 0) cout << "IMPOSSIBLE" << endl;
}