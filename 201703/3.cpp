#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool isvalid(int i, int j, int N){
    if(i < 0 || j < 0 || i >= N || j >= N) return false;
    else return true;
}

int main()
{
    int N, didx;
    cin >> N >> didx;
    vector<vector<int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    vector<vector<int>> matrix(N, vector<int>(N, 0));
    vector<vector<int>> mem = matrix;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int posi = N/2, posj = N/2, step = 0;
    while(step < N * N)
    {
        mem[posi][posj] = 1;
        cout << matrix[posi][posj];
        int newposi = posi + dir[didx][0], newposj = posj + dir[didx][1];
        if(isvalid(newposi, newposj, N) && mem[newposi][newposj] == 0)
        {
            posi = newposi;
            posj = newposj;
            didx = (didx + 1) % 4;
        }
        else if(isvalid(newposi, newposj, N) && mem[newposi][newposj] == 1)
        {
            int newdidx = (didx == 0 ? 3 : didx - 1);
            posi = posi + dir[newdidx][0];
            posj = posj + dir[newdidx][1];
        }
        step++;
    }
    cout << endl;
}