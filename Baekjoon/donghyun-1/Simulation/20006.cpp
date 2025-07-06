// https://www.acmicpc.net/problem/20006
// 랭킹전 대기열 (실버 2)
// 2025-07-02

/* 
    <접근 방법>
    [1] 입력 + 시뮬레이션(들어갈 방 찾기)
    
    match[i][]: i번 째 방에 입장한 플레이어({닉네임, 레벨}) 저장
    room_idx: 활성화 된 제일 마지막 방 index (방이 2개 활성화 되어있으면 room_idx = 1)
    pivot[i]: i번 방의 레벨 기준점 저장

    1-0. 플레이어 레벨, 닉네임 입력
    1-1. 방이 하나도 없으면 0번 방 생성 + pivot 업데이트(맨 처음) + 플레이어 push
    1-2. 활성화된 방 중에 레벨 조건에 맞고 정원 비어 있으면 플레이어 push
    1-3. 레벨 조건 or 정원 꽉 차서 못 들어가면 새로운 방 입장(room_idx 증가시키고 pivot[room_idx] 업데이트)
    반복
    
    [2] 정렬
    pair<string, int> 순으로 저장했기 때문에 각 i번째 방에서 sort 사용해서 닉네임 사전 순 정렬
    
    [3] 출력
    방마다 정원 m만큼 입장했으면 Started! / 아니라면 Waiting! 출력 후 플레이어 출력
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> psi;

int p, m, l;
string n;
vector<vector<psi>> match;
vector<int> pivot;

void simulation() {
    cin >> p >> m;

    match.resize(p);     // 플레이어 수 만큼 방 만들어 두기 (최대 경우)
    pivot.resize(p, -1);

    int room_idx = -1;   // 활성화 된 방

    for (int i = 0; i < p; i++) {
        // 레벨, 닉네임 입력
        cin >> l >> n;

        // 존재하는 방 하나도 없으면(맨 처음)
        if (room_idx == -1) {
            room_idx++;
            match[room_idx].push_back({n, l});
            pivot[room_idx] = l;
            
            continue;
        }

        bool room_flag = false;
        // 들어갈 수 있는 방 하나라도 있는 경우
        for (int i = 0; i <= room_idx; i++) {          
            if ((pivot[i]-10 <= l && l <= pivot[i]+10) && match[i].size() < m) {
                match[i].push_back({n, l});
                room_flag = true;
                break;
            }
        }

        // 레벨 맞는 방 없으면 방 생성
        if (!room_flag) {
            room_idx++;
            match[room_idx].push_back({n, l});
            pivot[room_idx] = l;
        }
    }
}

void print_result() {
    for (int i = 0; i < match.size(); i++) {
        if (match[i].size() == 0) continue;

        if (match[i].size() == m) {
            cout << "Started!\n";
            for (int j = 0; j < match[i].size(); j++) {
                cout << match[i][j].second << " " << match[i][j].first << "\n";
            }
        }
        else {
            cout << "Waiting!\n";
            for (int j = 0; j < match[i].size(); j++) {
                cout << match[i][j].second << " " << match[i][j].first << "\n";
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 + 시뮬레이션
    simulation();

    // 정렬
    for (int i = 0; i < match.size(); i++) {
        if (match[i].size() == 0) continue;

        sort(match[i].begin(), match[i].end());
    }

    // 출력
    print_result();

    return 0;
}