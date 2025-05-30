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
int n = -1;
vector<int> arr;
vector<bool> isUsed;
vector<int> inputArr;
void func(int k)
{
	if (k == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << arr[i] << ' ';// 이제 수열을 완성한것 이므로 출력
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!isUsed[i]&&k==0 || inputArr[i] > arr[k - 1])//오름차순으로 출력
		{
			arr[k] = inputArr[i];//현재 보고 있는 수를 i로 정함
			isUsed[i] = true;//그 수는 사용된 수이므로 true로 변경해줌
			func(k + 1);//다음 순서에 들어갈 수를 정하러 한단계 더 내려감.
			isUsed[i] = false;//이제 a 번째 수를 정한 모든 경우에 대해 다 확인 했으니 
			//i를 사용하지 않은 상태로 변경해줘야함
		}
	}
}
void reset()
{
	arr.clear();
	isUsed.clear();
	inputArr.clear();
	cout << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (n != 0)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			inputArr.push_back(input);
		}
		arr.resize(n + 1);
		isUsed.resize(n + 1);
		inputArr.resize(n + 1);
		func(0);
		reset();
	}
}