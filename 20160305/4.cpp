#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

int ans = -1;

int dfs(unordered_map<int, vector<int>>& m, vector<int>& mem, int root){
    mem[root] = 0;
    int res = 0;
    int maxnum = 0, secondnum = 0;
    for(int i=0; i<m[root].size(); i++){
        if(mem[m[root][i]] == -1){
            res = dfs(m, mem, m[root][i]);
            if(res+1 > maxnum){
                secondnum = maxnum;
                maxnum = res + 1;
            }
            else if(res+1 > secondnum){
                secondnum = res + 1;
            }
        }
    }
    ans = max(ans, maxnum+secondnum);
    return maxnum;
}

int main()
{
    int n, a, b;
    while(scanf("%d", &n) != EOF){
        ans = -1;
        unordered_map<int, vector<int>> m;
        for(int i=0; i<n-1; i++){
            scanf("%d %d\n",&a, &b);
            m[a].push_back(b);
            m[b].push_back(a);
        }
        vector<int> mem(n, -1);
        if(n > 2){
            for(int i=0; i<n; i++){
                if(m[i].size() != 1){
                    dfs(m, mem, i);
                    break;
                }
            }
            printf("%d\n", ans);
        }
        else printf("1\n");
        
    }
}