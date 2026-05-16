/*
bfs를 사용해서 문제 해결 (주어진 정수에서 최소 개수의 제곱수를 사용한횟수)
n에서 시작해서 완전 제곱수를 하나씩 빼가며 0에 빠르게 도달하면 그것이 사용한 완전 제곱수
뺀 횟수 == 사용한 완전 제곱수의 개수

각 레벨 즉 bfs로 들어갈때 완전 제곱수를 빼주는것임
즉
레벨 1 -> 완전 제곱수를 1번 뺀 결과들
레벨 2 -> 완전 제곱수를 2번 뺀 결과들 
.....
.....
이런 식으로 각각 레벨마다 큐에 제곱수를 n번뺀 결과들이 push가 된다.
따라서 이제 각 레벨안에서 현재 수 보다 작은 제곱수들을 빼면서 다시 큐에 넣는다
이 과정에서 방문한 숫자는 다시 계산할 필요가 없으므로 방문처리를 확인하면서 큐에 넣는 작업을 넣어줌
이러한 과정을 반복하다가 가장 먼저 현재 뺀 숫자가 0이 되면 그 때가 가장 빠르게 제곱수를 사용한 것이므로 정답을 리턴해줌

*/
class Solution {
public:
    int numSquares(int n) {
        int answer = 0;
        queue<int> q;
        bool isVisited[10001] = { false };
        q.push({ n });
        isVisited[n] = true;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int cur = q.front();
                q.pop();
                for (int i = 1; i * i <= cur; i++)
                {
                    int num = cur - i * i;
                    if (!isVisited[num])
                    {
                        q.push(num);
                        isVisited[num] = true;
                    }
                    if (num == 0)
                    {
                        return answer + 1;
                    }
                }
            }
            answer++;
        }
        return answer;
    }
};