// 교재 p.142
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    // 코드 작성
    sort(arr.begin(), arr.end());

    return arr;
}

////////////////////////////////////////////////////////////////////
// test code

void print(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
}

int main()
{
    print(solution({1, -5, 2, 4, 3}));          // -5 1 2 3 4 
    print(solution({2, 1, 1, 3, 2, 5, 4}));     // 1 1 2 2 3 4 5 
    print(solution({6, 1, 7}));                 // 1 6 7 
    
    return 0;
}