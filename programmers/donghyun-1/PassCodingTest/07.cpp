// https://school.programmers.co.kr/learn/courses/30/lessons/49994
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int D[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<vector<bool>>> visited(11, vector<vector<bool>>(11, vector<bool>(4, false)));

// 10x10 격자, (5, 5)에서 시작한다고 가정
int solution(string dirs) {
    int answer = 0;
    
    int dir;
    int curr_row = 5;
    int curr_col = 5;
    
    for (int i = 0; i < dirs.size(); i++) {
        if (dirs[i] == 'U') dir = 0;
        else if (dirs[i] == 'R') dir = 1;
        else if (dirs[i] == 'D') dir = 2;
        else if (dirs[i] == 'L') dir = 3;
        
        int nr = curr_row + D[dir][0], nc = curr_col + D[dir][1];
        
        if (nr < 0 || nr > 10 || nc < 0 || nc > 10) continue;
        
        // 새로운 길 방문 처리
        if (!visited[curr_row][curr_col][dir] && !visited[nr][nc][(dir+2)%4]) {
            visited[curr_row][curr_col][dir] = true;
            visited[nr][nc][(dir+2)%4] = true;
            answer++;
        }

        curr_row = nr;
        curr_col = nc;
    }
    
    return answer;
}

////////////////////////////////////////////////////////////////////
// test code

int main()
{
    cout << solution("ULURRDLLU") << "\n";

    // 7

    cout << solution("LULLLLLLU") << "\n";

    // 7

    return 0;
}