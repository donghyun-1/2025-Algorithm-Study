// https://school.programmers.co.kr/learn/courses/30/lessons/12949
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2[0].size(); j++) {
            for (int k = 0; k < arr2.size(); k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    return answer;
}

////////////////////////////////////////////////////////////////////
// test code

void print(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    print(solution({{1, 4}, {3, 2}, {4, 1}}, {{3, 3}, {3, 3}}));

    /*
        15 15 
        15 15 
        15 15
    */

    print(solution({{2, 3, 2}, {4, 2, 4}, {3, 1, 4}}, {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}}));

    /*
        22 22 11
        36 28 18
        29 20 14
    */

    return 0;
}