// https://school.programmers.co.kr/learn/courses/30/lessons/68644
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> numSet;
    
    for (int i = 0; i < numbers.size()-1; i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            numSet.insert(numbers[i] + numbers[j]);
        }
    }
    
    answer.assign(numSet.begin(), numSet.end());
    
    return answer;
}

////////////////////////////////////////////////////////////////////
// test code

void print(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main()
{
    print(solution({2, 1, 3, 4, 1}));
    print(solution({5, 0, 2, 7}));

    return 0;
}