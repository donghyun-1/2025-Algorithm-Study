// https://www.acmicpc.net/problem/1644
// 소수의 연속합 (골드 3)
// 2025-05-28

#include <iostream>
#include <vector>

using namespace std;

vector<int> prime;

void check_prime(int n) {
    vector<bool> check(n+1, true);

    for (int i = 2; i * i <= n; i++) {
        if (check[i]) {
            for (int j = i * i; j <= n; j += i) {
                check[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (check[i]) {
            prime.push_back(i);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    // 2 ~ N 소수 구하기
    check_prime(N);

    int start_idx = 0;
    int end_idx = 0;
    int cnt = 0;
    int sum = 0;

    // 투 포인터
    while (1) {
        if (sum > N) {
            sum -= prime[start_idx++];
        }
        else if (end_idx == prime.size()) {
            break;
        }
        else if (sum <= N) {
            sum += prime[end_idx++];
        }
        
        if (sum == N) cnt++;
    }

    cout << cnt;

    return 0;
}