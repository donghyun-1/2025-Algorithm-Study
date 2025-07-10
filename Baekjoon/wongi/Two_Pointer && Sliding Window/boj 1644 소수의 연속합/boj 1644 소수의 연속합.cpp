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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	vector<int> sosu;
	/*for (int i = 2; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0)
				cnt++;
		}
		if (cnt == 1)
		{
			sosu.push_back(i);
		}
	} -->이렇게 풀어버리니깐 자꾸 시간초과가 뜸.
	*/ 
	vector<bool> isPrime(N + 1, true);
	isPrime[0] = isPrime[1] = false;

	// 에라토스테네스의 체 알고리즘 사용
	/*
	2부터 시작하여 해당 숫자가 소수이면,
	그 소수의 배수들을 모두 지워나갑니다(소수가 아님으로 표시).
	이 과정을 숫자의 제곱근까지 반복하면, 남아있는 숫자들이 모두 소수가 됩니다.
	ex)
	처음에 2부터 N까지 모든 숫자를 소수로 간주(참(true))합니다.
	2부터 시작해서 2의 배수(4, 6, 8, ...)들을 소수가 아니라고 표시합니다.
	다음으로 3의 배수(6, 9, 12, ...)도 소수가 아니라고 표시합니다.
	이 작업을 √N까지 반복합니다.
	최종적으로 참으로 남은 숫자들이 소수입니다.
	* 
	*/
	for (int i = 2; i * i <= N; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= N; j += i)
				isPrime[j] = false;
		}
	}
	for (int i = 2; i <= N; i++) {
		if (isPrime[i])
			sosu.push_back(i);
	}
	//소수 구하기
	int size = sosu.size();
	int startIdx=0;
	int endIdx=0;
	int answer = 0;
	vector<int> sumArr(size+1,0);
	for (int i = 1; i <= size; i++)
	{
		sumArr[i] = sumArr[i - 1] + sosu[i - 1];
	}
	while (startIdx<=endIdx&&endIdx<=size)
	{
		int sum=sumArr[endIdx] - sumArr[startIdx];
		if (sum == N)
		{
			startIdx++;
			answer++;
		}
		else if (sum > N)
		{
			startIdx++;
		}
		else if (sum < N)
		{
			endIdx++;
		}
	}
	cout << answer;


}