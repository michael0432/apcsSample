#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Rotate(vector<vector<int>>& v)
{
    vector<vector<int>> out(v[0].size(), vector<int>(v.size()));
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            out[v[0].size()-1-j][i] = v[i][j];
        }
    }
    return out;
}

void Flip(vector<vector<int>>& v)
{
    for(int i=0; i<v.size()/2; i++){
        for(int j=0; j<v[0].size(); j++){
            swap(v[v.size()-1-i][j], v[i][j]);
        }
    }
}

int main()
{
    int R,C,M;
    while(cin >> R >> C >> M){
        vector<vector<int>> B(R, vector<int>(C, -1));
        vector<int> operation(M);
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin >> B[i][j];
            }
        }
        for(int i=0; i<M; i++){
            cin >> operation[i];
        }
        for(int i=M-1; i>=0; i--){
            if(operation[i] == 0) B = Rotate(B);
            else if(operation[i] == 1) Flip(B); 
        }
        cout << B.size() << " " << B[0].size() << endl;
        for(int i=0; i<B.size(); i++){
            for(int j=0; j<B[0].size(); j++){
                cout<<B[i][j];
                if(j != B[0].size()-1) cout << " ";
            }
            cout<<endl;
        }
    }
    
}