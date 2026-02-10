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
#include<cstring>
using namespace std;
/*
 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)
*/

int a[101][101];
int n,r, l;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0, };
int visited[101][101];
//각 연합을 구분하기위함
int answerCnt = 0;
void clear()
{
    memset(visited, 0, sizeof(visited));
}
void change(vector<int>& curAvgSet)
{
    int arrSize = curAvgSet.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] != 0)
            {
                for (int k = 1; k <= arrSize; k++)
                {
                    if (visited[i][j] == k)
                    {
                        a[i][j] = curAvgSet[k-1];
                    }
                }
            }
        }
        
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l >>r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
     
    while (true)
    {
        int flag = false;//연합을 나누었는지?
        vector<int> groupNumArr;//각그룹의 평균 값을 담을 벡터
        int idx = 1;//몇번째 연합인지 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    queue<pair<int,int>> q;
                    vector<pair<int, int>> groupPos;//연합에 들어가는 나라 위치정보
                    bool tempVisit[101][101] = {false};//일단 조건을 확인하기전에 임시로 방문처리할 배열
                                                        //방문했을때 그 범위 조건에 안맞을수도 있음
                    tempVisit[i][j] = true;
         
                    q.push({ i,j });
                    groupPos.push_back({ i,j });
                    int sum = 0;//연합들의 합
                    int cnt = 0;//한 연합에 들어가는 국가수
                  
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();
                        sum += a[cur.first][cur.second];
                        cnt++;
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            if (nx < 0 || ny < 0 || nx >= n || ny >=n) continue;
                            if (tempVisit[ny][nx])continue;
                            int checkNum = abs(a[ny][nx] - a[cur.first][cur.second]);//조건에 따라 맞는지 확인하는 수
                            if (checkNum >= l && checkNum <= r)
                            {
                                tempVisit[ny][nx] = true;
                      
                                q.push({ ny,nx });
                                groupPos.push_back({ ny,nx });
                            }
                           
                        }
                    }
                    //한 칸에 대해 bfs끝나는 시점
                    //즉 day1 에 연합 하나가 끝나는 시점임
                    if (cnt >= 2)//연합하나가 생성이 되면
                    {
                        int avg = sum / cnt;
                        groupNumArr.push_back(avg);
                        for (int x = 0; x < groupPos.size(); x++)
                        {
                            visited[groupPos[x].first][groupPos[x].second] = idx;
                        }//visited배열에 각 연합의 번호 찍기 + 방문처리
                        flag = true;
                        idx++;
                    }
                }

            }
        }

        if (flag)
        {
            change(groupNumArr);
            answerCnt++;
        }
        else
        {
            break;
        }
        clear();
    }


    cout << answerCnt;
}