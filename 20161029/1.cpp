#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> triangle(3);
    cin >> triangle[0] >> triangle[1] >> triangle[2];
    sort(triangle.begin(), triangle.end());
    cout << triangle[0] << " " << triangle[1] << " " << triangle[2] << endl;
    if(triangle[0] + triangle[1] <= triangle[2]) cout << "No" << endl;
    else if(triangle[0] * triangle[0] + triangle[1] * triangle[1] < triangle[2] * triangle[2]) cout << "Obtuse" << endl; 
    else if(triangle[0] * triangle[0] + triangle[1] * triangle[1] == triangle[2] * triangle[2]) cout << "Right" << endl;
    else cout << "Acute" << endl;
}