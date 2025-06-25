// 교재 p.145
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lst) {
    // 배열 내림차순 정렬
    sort(lst.begin(), lst.end(), greater<int>());

    // 중복 제거
    auto newEnd = unique(lst.begin(), lst.end());
    lst.erase(newEnd, lst.end());

    return lst;
}

////////////////////////////////////////////////////////////////////
// test code

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main()
{
    print(solution({4, 2, 2, 1, 3, 4}));
    print(solution({2, 1, 1, 3, 2, 5, 4}));

    return 0;
}