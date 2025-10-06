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
#include <unordered_set>
#include<unordered_map>
using namespace std;
int board[129][129];
int white = 0;
int blue = 0;
int N;
void func(int x, int y, int size)
{
    int first = board[x][y];
    bool isSame = true;
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (board[i][j] != first)
            {
                isSame = false;
            }
        }
        if (!isSame) break;
    }
    if (isSame)
    {
        if (first == 0)
        {
            white++;
        }
        else
        {
            blue++;
        }
        return;
    }
    func(x, y, size / 2);
    func(x, y + size / 2, size / 2);
    func(x + size / 2, y, size / 2);
    func(x + size / 2, y + size / 2, size / 2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    func(0, 0, N);
    cout << white << '\n' << blue;
}