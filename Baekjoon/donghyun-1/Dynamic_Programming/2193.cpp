// https://www.acmicpc.net/problem/2193
// 이친수 (실버 3)
// 2025-05-14

#include <iostream>

using namespace std;

int main()
{
    int N;
    long long arr[91];
    cin >> N;

    // 1 1 2 3 5 8
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= N; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[N];

    return 0;
}