// https://www.acmicpc.net/problem/1459
// 걷기 (실버 3)
// 2025-05-23 

#include <iostream>

using namespace std;

struct Point {
    long long x, y;
};

int W;                  // 한 블록 가는데 걸리는 시간 W
int S;                  // 대각선으로 한 블록을 가로지르는 시간 S
long long total_time = 0;

long long crossMove(long long remainder_x, long long remainder_y) {
    while (remainder_x != 0) {
        if (remainder_x >= 2) {
            remainder_x -= 2;
            total_time += 2*S;
        }
        else {
            remainder_x--;
            total_time += W;
        }
    }

    while (remainder_y != 0) {
        if (remainder_y >= 2) {
            remainder_y -= 2;
            total_time += 2*S;
        }
        else {
            remainder_y--;
            total_time += W;
        }
    }

    return total_time;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long X, Y;         // 집 위치

    cin >> X >> Y >> W >> S;

    Point curr = {X, Y};

    // 방법 2번 (대각선)
    if (W + W > S) {
        while (curr.x != 0 && curr.y != 0) {
            curr.x--;
            curr.y--;
            total_time += S;
        }

        long long remainder_x = curr.x - 0;
        long long remainder_y = curr.y - 0;

        if (W > S) {
            total_time = crossMove(remainder_x, remainder_y);
        }
        else {
            total_time += remainder_x * W;
            total_time += remainder_y * W;
        }
    }
    // 방법 1번 (도로)
    else {
        total_time += X * W;
        total_time += Y * W;
    }

    cout << total_time;

    return 0;
}