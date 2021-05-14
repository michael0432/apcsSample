#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

unsigned long long int solve(vector<int>& weight, vector<int>& times, int n)
{
    unsigned long long int res = 0;
    int totaltimes = 0;
    unordered_map<int, int> choosed;
    
    for(int i=0; i<n; i++)
    {
        totaltimes += times[i];
    }
    for(int i=0; i<n; i++)
    {
        unsigned int totalweight = UINT_MAX;
        int choosed_box = -1;
        unsigned int cost;
        for(int j=0; j<n; j++)
        {
            if(choosed.count(j) == 0)
            {
                cost = (totaltimes - times[j]) * weight[j];
                if(cost < totalweight)
                {
                    totalweight = cost;
                    choosed_box = j;
                }
                else if(cost == totalweight)
                {
                    if(weight[choosed_box] < weight[j])
                    {
                        totalweight = cost;
                        choosed_box = j;
                    }
                }
            }
        }
        choosed[choosed_box] = 1;
        res += (totaltimes - times[choosed_box]) * weight[choosed_box];
        totaltimes -= times[choosed_box];
    }
    return res;
}

unsigned long long int solve2(vector<vector<unsigned long long int>>& data, int n)
{
    unsigned long long int totaltimes = 0;
    unsigned long long int res = 0;
    for(int i=0; i<n; i++)
    {
        totaltimes += data[i][1];
    }
    sort(data.begin(), data.end(), [](const vector<unsigned long long int>& v1, const vector<unsigned long long int>& v2)
    {
        return v1[0] * v2[1] < v2[0] * v1[1];
    });
    for(int i=0; i<n; i++)
    {
        res += data[i][0] * (totaltimes - data[i][1]);
        totaltimes -= data[i][1];
    }
    return res;
}

int main()
{
    int n;
    while(cin >> n)
    {
        vector<vector<unsigned long long int>> data(n, vector<unsigned long long int>(2, 0));
        for(int x=0; x<2; x++)
        {
            for(int i=0; i<n; i++)
            {
                cin >> data[i][x];
            }
        }
        cout << solve2(data, n) << endl;
    }
    
}