// https://school.programmers.co.kr/learn/courses/30/lessons/42840
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p1 = {1, 2, 3, 4, 5};                   // 5개 반복
vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};          // 8개 반복
vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};    // 10개 반복

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> correct;
    correct.resize(3, 0);
    
    // 몇 개 맞추는지 카운트
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == p1[i%5]) correct[0]++;
        if (answers[i] == p2[i%8]) correct[1]++;
        if (answers[i] == p3[i%10]) correct[2]++;
    }
    
    // 최댓값 구하기
    int maxA = *max_element(correct.begin(), correct.end());
    
    for (int i = 0; i < 3; i++) {
        if (correct[i] == maxA) 
            answer.push_back(i+1);
    }
    
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
    print(solution({1, 2, 3, 4, 5}));
    print(solution({1, 3, 2, 4, 2}));

    return 0;
}