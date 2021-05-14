#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

int ans = -1;

int dfs(unordered_map<int, vector<int>>& m, int root){
    int res = 0;
    int maxnum = 0, secondnum = 0;
    for(int i=0; i<m[root].size(); i++){
        res = dfs(m, m[root][i]);
        if(res+1 > maxnum){
            secondnum = maxnum;
            maxnum = res + 1;
        }
        else if(res+1 > secondnum){
            secondnum = res + 1;
        }
    }
    ans = max(ans, maxnum+secondnum);
    return maxnum;
}

int main()
{
    int n, a, b;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    while(cin >> n){
        ans = -1;
        unordered_map<int, vector<int>> m;
        vector<int> hasparent(n, 0);
        for(int i=0; i<n-1; i++){
            cin >> a >> b;
            m[a].push_back(b);
            hasparent[b] = 1;
        }
        vector<int> mem(n, -1);
        if(n > 2){
            for(int i=0; i<n; i++){
                if(hasparent[i] == 0){
                    dfs(m, i);
                    break;
                }
            }
            printf("%d\n", ans);
        }
        else printf("1\n");
        
    }
}