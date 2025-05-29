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
int L, C;
char arr[15];
int isused[15];
int ja, mo;
vector<char> input;
void func(int k)
{
	if (k == L)
	{
		for (int i = 0; i < L; i++)
		{
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			{
				ja++;
			}
			else
			{
				mo++;
			}
		}
		if (ja >= 1 && mo >= 2)
		{
			for (int i = 0; i < L; i++)
			{
				cout << arr[i];
			}
			cout << "\n";
		}
		ja = 0;
		mo = 0;
		return;
	}
	for (int i = 0; i < C; i++)
	{
		if (!isused[i]&& arr[k - 1] <= input[i])//증가하는 암호. 알파벳 순서
		{
			arr[k] = input[i];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char en;
		cin >> en;
		input.push_back(en);
	}
	sort(input.begin(), input.end());
	func(0);
}