// https://www.acmicpc.net/problem/14719
// 빗물 (골드 5)
// 2025-06-20

#include <iostream>
#include <vector>

using namespace std;

int H, W;
vector<int> v;

void input() {
    cin >> H >> W;

    v.resize(W);
    
    for (int i = 0; i < W; i++) {
        cin >> v[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    int left = 0;
    int right = W - 1;
    int left_max = v[left];
    int right_max = v[right];
    int ans = 0;

    while (left < right) {
        if (left_max < right_max) {
            left++;
            left_max = max(left_max, v[left]);

            ans += left_max - v[left];
        } 
        else {
            right--;
            right_max = max(right_max, v[right]);

            ans += right_max - v[right];
        }
    }

    cout << ans;

    return 0;
}