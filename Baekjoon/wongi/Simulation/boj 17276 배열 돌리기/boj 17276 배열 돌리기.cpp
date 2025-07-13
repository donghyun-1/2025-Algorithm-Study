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
int arrsize;
void rotate(int size,int angle)
{
    vector<vector<int>> arr(size,vector<int>(size));
    vector<vector<int>> temp = arr;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
    int rotateCount = (angle / 45);
    int c = size / 2;

    if (angle == 0 || angle % 360 == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << arr[i][j] << ' ';
            cout << '\n';
        }
        return;
    }

    // 몇 번 돌릴지 결정 (음수면 반시계)
    int rotateCount = angle / 45;
    bool isClockwise = true;
    if (rotateCount < 0) 
    {
        isClockwise = false;
        rotateCount = -rotateCount;
    }

    // 실제 회전
    for (int a = 0; a < rotateCount; a++)
    {  
        temp = arr;
        if (isClockwise) // 시계 방향
        { 
            // 주대각선 -> 가운데 열
            for (int i = 0; i < size; i++)
            {
                temp[i][c] = arr[i][i];
            }
            // 가운데 열 -> 부대각선
            for (int i = 0; i < size; i++)
            {
                temp[i][size - 1 - i] = arr[i][c];
            }
            // 부대각선 -> 가운데 행 (역순)
            for (int i = 0; i < size; i++)
            {
                temp[c][size - 1 - i] = arr[i][size - 1 - i];
            }
            // 가운데 행 -> 주대각선 (역순)
            for (int i = 0; i < size; i++)
            {
                temp[i][i] = arr[c][i];
            }
        }
        else { // 반시계 방향
            // 가운데 열 -> 주대각선
            for (int i = 0; i < size; i++)
            {
                temp[i][i] = arr[i][c];
            }
            // 주대각선 -> 가운데 행
            for (int i = 0; i < size; i++)
            {
                temp[c][i] = arr[i][i];
            }
            // 가운데 행 -> 부대각선 (역순)
            for (int i = 0; i < size; i++)
            {
                temp[i][size - 1 - i] = arr[c][size - 1 - i];
            }
            // 부대각선 -> 가운데 열 (역순)
            for (int i = 0; i < size; i++)
            {
                temp[i][c] = arr[i][size - 1 - i];
            }
        }
        arr = temp;
    }

    // 결과 출력
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << ' ';
        }
            cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int arrsize,angle;
        cin >> arrsize >> angle;
        rotate(arrsize, angle);
    }
}