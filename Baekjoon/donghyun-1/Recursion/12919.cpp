// https://www.acmicpc.net/problem/12919
// A와 B 2 (골드 5)
// 2025-06-12

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string temp = "";

void abGame(string s, string t){
    if (s == t) {
        cout << 1 << "\n";
        exit(0);
    }

    if (s.size() >= t.size()) 
        return;
    
    if (t[t.size()-1] == 'A') {
        temp = t;
        
        temp.pop_back();

        abGame(s,temp);
    }

    if (t[0] == 'B') {
        temp = t.substr(1);

        reverse(temp.begin(), temp.end());

        abGame(s,temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    string S, T;
    cin >> S >> T;

    abGame(S, T);
    
    cout << 0 << "\n";
    
    return 0;
}