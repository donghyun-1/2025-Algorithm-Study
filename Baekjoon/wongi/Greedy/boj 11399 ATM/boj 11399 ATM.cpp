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
	int count;
	cin >> count;
	vector<int> numArr(count);
	for (int i = 0; i < count; i++)
	{
		cin >> numArr[i];
	}
    sort(numArr.begin(), numArr.end());
    int total = 0;
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += numArr[i];
        total += sum;
    }
    cout << total;
}