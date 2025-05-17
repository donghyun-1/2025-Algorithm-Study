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
	int n;
	long long d[1500001];
	long long t[1500001];
	long long p[1500001];
	//근데왜 이거 배열들 전역으로 말고 int main안에 넣으니까 답이 맞을까.....
	//d[i] -->i날에 시작해서 n까지 벌 수 있는 최대 수입 테이블
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}
	for (int i = n; i > 0; i--)
	{
		if (i + t[i] > n + 1)//만약에 i번째부터 시작했는데 퇴사일 까지 안끝날때
		{
			d[i] = d[i + 1];
			/*
			i일부터 t[i]일 걸리는 상담을 시작하면,
			종료일이 i + t[i] - 1이므로, 그 다음 날은 i + t[i]
			퇴사일은 n+1일이기 때문에, i + t[i] > n+1 이면 불가능
			*/
		}
		else//퇴사일 안에 끝날때
		{

			d[i] = max(d[i + 1], p[i] + d[i + t[i]]);
			/*
			 1) 상담을 건너뛰고 다음 날부터 얻는 수익: d[i+1]
			 2) 오늘 상담을 하고, 끝나는 날 다음날부터 얻는 수익: p[i] + d[i + t[i]]
			 둘 중 큰 값을 선택*/
		}
	}
	cout << *max_element(d + 1, d + n + 1);
}