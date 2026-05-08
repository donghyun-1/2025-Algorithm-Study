#include <string>
#include <vector>
#include <iostream>
int check[101][101];
using namespace std;
/*
a가 b를 이겼다 
a가 b를 이기고 b가 c를 이겼다면 a는 c보다 순위가 높다
-> 즉 이런 간접 순위도 알아야 한다. 따라서 모든 정점 사이의 관계를 갱신할수 있는 플로이드 워셜 알고리즘 사용

또한 추가로 한 사람에 대해서 n-1(나머지 사람들)명과의 순위를 알수 있다면 
이는 확실하게 몇등인지 알 수가 있음
*/
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<int> arr[101];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                check[i][j] = 0;
            }
            else
            {
                check[i][j] = -1;
            }

        }
    }
    for (int i = 0; i < results.size(); i++)
    {
        int a = results[i][0];
        int b = results[i][1];

        check[a][b] = 1;//a가 b를 이김
    }


    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (check[i][k] == 1 && check[k][j] == 1)
          
                {
                    check[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int checkNum = 0;
        for (int j = 1; j <= n; j++)
        {
            //i와 j사이의 관계를 아는 경우
            if (check[i][j] == 1 || check[j][i] == 1)
            {
                checkNum++;
            }
        }
        if (checkNum == n - 1)
        {
            answer++;
        }
    }
    return answer;
}