#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int k;
    string s;
    while(cin >> k >> s)
    {
        vector<int> v;
        bool inlower = false;
        if(islower(s[0])) inlower = true;
        int cnt = 0;
        for(int i=0; i<s.size(); i++)
        {
            if((islower(s[i]) && inlower) || (!islower(s[i]) && !inlower)) cnt++;
            else
            {
                v.push_back(cnt);
                cnt = 1;
                inlower = !inlower;
            }
        }
        v.push_back(cnt);
        int res = 0;
        int tmp = 0;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i] == k) tmp += v[i];
            else if(v[i] < k)
            {
                res = max(res, tmp);
                tmp = 0;
            }
            else
            {
                if(tmp == 0) tmp += k;
                else
                {
                    res = max(res, tmp+k);
                    tmp = k;
                }
            }
        }
        res = max(res, tmp);
        cout << res << endl;
    }
    
}