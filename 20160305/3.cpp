#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void mergeLine(vector<vector<int>>& v)
{
    int index = 0;
    while(index < v.size()-1){
        if(v[index][1] >= v[index+1][0]){
            v[index][1] = max(v[index][1], v[index+1][1]);
            v.erase(v.begin()+index+1);
        }
        else{
            index++;
        }
    }
}


int main()
{
    int N;
    while(cin >> N)
    {
        vector<vector<int>> lines(N, vector<int>(2));
        for(int i=0; i<N; i++)
        {
            cin>>lines[i][0];
            cin>>lines[i][1];
        }
        sort(lines.begin(), lines.end(), [](const vector<int>& l, vector<int>& r)
        {
            return l[0] < r[0];
        });
        mergeLine(lines);
        int res = 0;
        for(int i=0; i<lines.size(); i++){
            res += lines[i][1] - lines[i][0];
        }
        cout << res << endl;
    }
}