// https://www.acmicpc.net/problem/2304
// 창고 다각형 (실버 2)
// 2025-07-06

/* 
    <접근 방법>
    [1] 
    building[위치] = 높이 입력
    최대 높이, 인덱스 구하기
    
    [2]
    왼쪽부터 최대 높이까지 구간 계산
    높이 비교, 더하기
    
    [3]
    오른쪽부터 최대 높이까지 구간 계산
    높이 비교, 더하기

    [4]
    최대 높이 더하고 출력
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
int maxIdx, maxH = 0;
vector<int> building;

void input() {
    cin >> N;

    building.resize(1001, 0);

    int L, H;
    for (int i = 0; i < N; i++) {
        cin >> L >> H;

        building[L] = H;    // 위치, 높이

        // 최대 높이
        if (H > maxH) {
            maxH = H;
            maxIdx = L;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    int area = 0;

    // 왼쪽 -> 최대 높이
    int left_height = 0;

    for (int i = 0; i < maxIdx; i++) {
        left_height = max(left_height, building[i]);

        area += left_height;
    }

    // 최대 높이 <- 오른쪽
    int right_height = 0;

    for (int i = 1000; i > maxIdx; i--) {
        right_height = max(right_height, building[i]);

        area += right_height;
    }

    // 최대 높이 더하기
    area += maxH;

    cout << area;

    return 0;
}