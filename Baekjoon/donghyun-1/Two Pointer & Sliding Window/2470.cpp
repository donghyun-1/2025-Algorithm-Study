// https://www.acmicpc.net/problem/2470
// 두 용액 (골드 5)
// 2025-07-27

/* 
    <접근 방법>
    [1] 
    용액 배열 입력

    [2]
    용액 오름차순 정렬하기
    투 포인터 선택해서 용액 2개 선택
    용액의 합의 절대값이 가장 작은 것 선택

    [3]
    ans[0], [1], [2]에 각 절대값, 용액1값, 용액2값 저장
*/

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
    sort(arr, arr+N);

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