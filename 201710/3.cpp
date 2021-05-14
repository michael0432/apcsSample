#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Node
{
public:
    int val;
    vector<Node*> childs;
    Node(int v)
    {
        val = v;
    }
};

long long int dfs(Node* root, long long int& ans)
{
    long long int res = -1;
    for(int i=0; i<root->childs.size(); i++)
    {
        res = max(res, dfs(root->childs[i], ans));
    }
    res += 1;
    ans += res;
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<Node*> allNode;
    vector<bool> has_parent(n, false);
    Node* root;
    for(int i=1; i<=n; i++)
    {
        Node* n = new Node(i);
        allNode.push_back(n);
    }
    for(int i=0; i<n; i++)
    {
        int k;
        cin >> k;
        for(int j=0; j<k; j++)
        {
            int tmpn;
            cin >> tmpn;
            allNode[i]->childs.push_back(allNode[tmpn-1]);
            has_parent[tmpn-1] = true;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(!has_parent[i])
        {
            root = allNode[i];
            break;
        }
    }
    long long int ans = 0;
    dfs(root, ans);
    cout << root->val << endl <<  ans << endl;
}