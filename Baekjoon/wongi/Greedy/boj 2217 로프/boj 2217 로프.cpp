#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
여러 개의 로프를 사용할 경우 각 로프는 
자신보다 무거운 물건을 들 수 없으므로
여러 개를 사용할 때는
(각 로프가 버틸 수 있는 무게)*(사용한 로프의 개수)
이 값을 모든 조합에 대해 계산해서 최대값을 찾으면 된다.
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++) 
	{
		cin >> arr[i];
	}

	// 오름차순 정렬 ==> 가장 
	sort(arr.begin(), arr.end());

	int answer = 0;
	// i번째부터 N-1번째까지 로프를 모두 사용한다고 할 때,
	// 들 수 있는 무게는 arr[i] * (N - i)
	for (int i = 0; i < N; i++)
	{
		int weight = arr[i] * (N - i);
		// 최대값 갱신
		answer = max(answer, weight);
	}

	cout << answer << '\n';
}