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
vector<int> solution(vector<int> arr, int n) {
    bool isOdd;
    if (arr.size()%2 == 1) isOdd = true;
    else isOdd = false;

    for (int i = 0; i < arr.size(); i++)
    {
        if (isOdd)
        {
            if (i % 2 == 0) arr[i] += n;
        }
        else
        {
            if (i % 2 == 1) arr[i] += n;
        }
    }

    return arr;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}