#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int move(queue<int>& bases, int step)
{
    int point = 0;
    for(int i=0; i<step; i++)
    {
        if(i == 0) bases.push(1);
        else bases.push(0);
    }
    for(int i=0; i<step; i++)
    {
        if(bases.front() == 1) point++;
        bases.pop();
    }
    return point;
}

int resetBase(queue<int>& bases)
{
    while(!bases.empty()) bases.pop();
    for(int i=0; i<3; i++) bases.push(0);
}

void printBase(queue<int>& bases)
{
    queue<int> tmp = bases;
    while(!tmp.empty())
    {
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << endl;
}

int calculatePoint(vector<string>& records_sorted, int b)
{
    int points = 0, out = 0, total_out = 0;
    queue<int> bases;
    resetBase(bases);
    for(int i=0; i<records_sorted.size(); i++)
    {
        if(records_sorted[i] == "1B") points += move(bases, 1);
        else if(records_sorted[i] == "2B") points += move(bases, 2);
        else if(records_sorted[i] == "3B") points += move(bases, 3);
        else if(records_sorted[i] == "HR") points += move(bases, 4);
        else
        {
            out++;
            total_out++;
        }
        if(out == 3)
        {
            out = 0;
            resetBase(bases);
        }
        if(total_out == b)
        {
            return points;
        }
    }
    return points;
}

int main()
{
    vector<vector<string>> record(9, vector<string>());
    vector<string> records_sorted;
    int b;
    for(int i=0; i<10; i++)
    {
        if(i == 9) cin >> b;
        else
        {
            int num;
            cin >> num;
            for(int j=0; j<num; j++)
            {
                string r;
                cin >> r;
                record[i].push_back(r);
            }
        }
    }
    for(int j=0; j<5; j++)
    {
        for(int i=0; i<9; i++)
        {
            if(j < record[i].size())
                records_sorted.push_back(record[i][j]);
        }
    }
    cout << calculatePoint(records_sorted, b) << endl;
}