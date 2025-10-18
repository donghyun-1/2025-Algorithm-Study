// https://www.acmicpc.net/problem/2467
// 용액 (골드 5)
// 2025-10-15

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 정렬
    // sort(arr, arr+N);

    // 투 포인터
    int left = 0;
    int right = N-1;
    int value = 0;
    int ans[3] = {2000000000, 0 , 0};

    while (left < right) {
        value = arr[left] + arr[right];

        if (ans[0] > abs(value)) {
            ans[0] = abs(value);
            ans[1] = arr[left];
            ans[2] = arr[right];
        }

        if (value < 0) {
            left++;
        }
        else if (value > 0) {
            right--;
        }
        else {
            break;
        }
    }

    cout << ans[1] << " " << ans[2];

    return 0;
}