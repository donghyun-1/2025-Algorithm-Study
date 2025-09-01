// https://www.acmicpc.net/problem/2529
// 부등호 (실버 1)
// 2025-08-29

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int k;
char sign[10];
long long max_num = 0;
long long min_num = 9999999999;
string ans_max = "";
string ans_min = "";
string num[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
bool used[10];


void input() {
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> sign[i];
    }
}

void backtracking(int before, vector<string>& temp) {
    if (temp.size() == k+1) {
        string str_temp = "";
        for (int i = 0; i < k+1; i++) {
            str_temp += temp[i];
        }

        if (max_num < stoll(str_temp)) {
            max_num = stoll(str_temp);
            ans_max = str_temp;
        }
        if (min_num > stoll(str_temp)) {
            min_num = stoll(str_temp);
            ans_min = str_temp;
        }
    }

    for (int i = 0; i < 10; i++) {
        int curr = stoi(num[i]);
        if (used[curr]) continue;

        if (temp.size() == 0) {         // 비어 있으면 1개 넣기
            temp.push_back(num[i]);
            used[curr] = true;

            backtracking(curr, temp);
        
            used[curr] = false;
            temp.pop_back();
        }
        else {
            if (sign[temp.size()-1] == '<') {
                if (curr > before) {
                    temp.push_back(num[i]);
                    used[curr] = true;

                    backtracking(curr, temp);
        
                    used[curr] = false;
                    temp.pop_back();
                }
            }
            else if (sign[temp.size()-1] == '>') {
                if (curr < before) {
                    temp.push_back(num[i]);
                    used[curr] = true;
                    
                    backtracking(curr, temp);
                    
                    used[curr] = false;
                    temp.pop_back();
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

    input();

    vector<string> v;
    backtracking(-1, v);

    cout << ans_max << "\n" << ans_min;

    return 0;
}