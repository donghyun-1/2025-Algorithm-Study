// https://www.acmicpc.net/problem/11047
// 동전 0 (실버 4)
// 2025-06-29

/* 
    <접근 방법>

    N의 크기가 최대 10 밖에 되지 않아서 단순 구현으로 접근해보았다.

    1.
    벡터 coin에 N개의 동전 저장

    2.
    최대한 큰 동전 단위를 사용하는 것이 곧, 동전을 최소로 사용하는 것이므로
    K/coin[i]를 통해 최소 개수 temp에 저장 + 최소일 때 idx 구하기

    3.
    ans 변수에 temp 더해주고, K에 사용한 동전 금액만큼 빼주기
    K -= temp * coin[idx]

    4. 
    K == 0 이 될 때까지 반복
*/

#include <iostream>
#include <vector>

using namespace std;

int N, K, ans = 0;
vector<int> coin;

void input() {
    cin >> N >> K;

    coin.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
}

int main()
{
    input();

    while (K != 0) {
        int temp = 100000001;
        int idx = -1;

        for (int i = 0; i < N; i++) {
            if (K / coin[i] == 0) continue;

            if (temp > K/coin[i]) {
                temp = K/coin[i];   // 최소 개수
                idx = i;            // 그 때 idx
            }
        }

        // 사용한 만큼 빼주기
        ans += temp;
        K -= temp * coin[idx];
    }

    cout << ans;

    return 0;
}