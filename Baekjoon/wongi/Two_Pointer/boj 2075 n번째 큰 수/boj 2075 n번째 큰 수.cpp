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
//long  board[1501][1501];
struct cmp {
	bool operator()(long a, long b)
	{
		return a > b;
	}
};//오름차순
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<long, vector <long>, cmp> pq;
	int N;
	cin >> N;
	/*for(int i=0;i<N;i++) // => 시간 초과
	{
		for (int j = 0; j < N; j++)
		{
			long long input;
			cin >> input;
			board[i][j] = input;
			pq.push(board[i][j]);
		}
	}*/
	for (int i = 0; i < N * N; i++)
	{
		int input;
		cin >> input;
		pq.push(input);
		//최소 힙 을 유지해준다.
		if (pq.size() > N) {// 가장 작은 값이 TOP에 있음 이거 해주는이유는
			//항상 크기를 n으로 제한해서 메모리 제한 조건을 해결하기위함
			pq.pop();// 따라서 만약에 우선순위 큐의 크기가 n을 넘어가면가장 작은 값인 top을 삭제
		}
	}
	/*for (int i = 0; i < N-1; i++)
	{
		pq.pop();
	}*/
	cout << pq.top() << "\n"; //=> n번째로 큰 수를 출력해줌

}