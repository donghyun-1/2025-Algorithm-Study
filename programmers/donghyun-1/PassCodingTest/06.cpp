// https://school.programmers.co.kr/learn/courses/30/lessons/42889
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareP(pair<double, int>& v1, pair<double, int>& v2) {
    // 실패율 같으면
    if (v1.first == v2.first) {
        // 작은 단계 먼저 출력
        return v1.second < v2.second;
    }

    return v1.first > v2.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> temp(N, {0, 0});    // 실패율, 단계
    
    // 초기화
    for (int i = 1; i <= N; i++) {
        temp[i-1].second = i;
    }
    
    // 인원 수 입력
    for (int i = 0; i < stages.size(); i++) {
        int s = stages[i];
        
        if (s == N+1) continue;
        
        temp[s-1].first++;
    }
    
    // 실패율 계산
    int left = stages.size();
    for (int i = 0; i < N; i++) {
        double n = temp[i].first;   // 못 깬 인원
        
        if (left != 0) {
            temp[i].first = n / left;   
        }
        else { // 0으로 나누기 방지
            temp[i].first = 0;
        }

        left -= (int)n;
    }
    
    // 내림차순 정렬
    sort(temp.begin(), temp.end(), compareP);
    
    // 단계만 저장
    for (int i = 0; i < N; i++) {
        answer.push_back(temp[i].second);
    }
    
    return answer;
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
    print(solution(5, {2, 1, 2, 6, 2, 4, 3, 3}));

    // 3 4 2 1 5

    print(solution(4, {4, 4, 4, 4, 4}));

    // 4 1 2 3

    return 0;
}