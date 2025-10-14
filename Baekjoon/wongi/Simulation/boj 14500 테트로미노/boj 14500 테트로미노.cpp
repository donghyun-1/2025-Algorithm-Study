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
#include<math.h>
using namespace std;
int n, m;
int board[501][501];
int answer = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int longShape[8][2] =
    {
      {0,0},{1,0},{2,0},{3,0},
      {0,0},{0,1},{0,2},{0,3}
    };
    // ㅁ (1가지)
    int recShape[4][2] =
    {
        {0,0},{1,0},{0,1},{1,1}
    };
    // L (8가지)
    int lShape[32][2] =
    {
        {0,0},{1,0},{2,0},{2,1},// ㄴ
        {0,0},{0,1},{0,2},{1,0},// ㄴ 90도
        {0,0},{0,1},{1,1},{2,1},// ㄴ 180도
        {1,0},{1,1},{1,2},{0,2},// ㄴ 270도
        {0,1},{1,1},{2,1},{2,0},  // ㄴ 대칭
        {0,0},{1,0},{1,1},{1,2},  // ㄴ 대칭 90도
        {0,0},{0,1},{1,0},{2,0},  // ㄴ 대칭 180도
        {0,0},{0,1},{0,2},{1,2}   // ㄴ 대칭 270도
    };
    // Z (4가지)
    int zShape[16][2] =
    {
        {0,0},{0,1},{1,1},{1,2},
        {0,1},{1,0},{1,1},{2,0},
        {0,1},{0,2},{1,0},{1,1},
        {0,0},{1,0},{1,1},{2,1}
    };

    // ㅗ (4가지)
    int fShape[16][2] =
    {
        {0,0},{0,1},{0,2},{1,1},// ㅗ
        {0,1},{1,0},{1,1},{2,1},// ㅏ
        {0,1},{1,0},{1,1},{1,2},// ㅜ
        {0,0},{1,0},{2,0},{1,1} // ㅓ
    };
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //ㅡ
            for (int k = 0; k < 8; k += 4)
            {
                int curSum = 0;
                for (int a = 0; a < 4; a++)
                {
                    int nx = i + longShape[k + a][0];
                    int ny = j + longShape[k + a][1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                    curSum += board[nx][ny];
                }
                    answer = max(answer, curSum);
            }

            //ㅁ
            for (int k = 0; k < 4; k += 4)
            {
                int curSum = 0;
                for (int a = 0; a < 4; a++)
                {
                    int nx = i + recShape[k + a][0];
                    int ny = j + recShape[k + a][1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                    curSum += board[nx][ny];
                }
                    answer = max(answer, curSum);
            }

            // L
            for (int k = 0; k < 32; k += 4)
            {
                int curSum = 0;
                for (int a = 0; a < 4; a++)
                {
                    int nx = i + lShape[k + a][0];
                    int ny = j + lShape[k + a][1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                    curSum += board[nx][ny];
                }
                    answer = max(answer, curSum);
            }

            //Z
            for (int k = 0; k < 16; k += 4)
            {
                int curSum = 0;
                for (int a = 0; a < 4; a++)
                {
                    int nx = i + zShape[k + a][0];
                    int ny = j + zShape[k + a][1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                    curSum += board[nx][ny];
                }
                    answer = max(answer, curSum);
            }

            //ㅗ
            for (int k = 0; k < 16; k += 4)
            {
                int curSum = 0;
                for (int a = 0; a < 4; a++)
                {
                    int nx = i + fShape[k + a][0];
                    int ny = j + fShape[k + a][1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                    curSum += board[nx][ny];
                }
                    answer = max(answer, curSum);
            }
        }
    }
    cout << answer;
}