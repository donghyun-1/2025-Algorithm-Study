#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = num; // int형 범위를 벗어날 수 있으므로 long long 사용
    int answer = 0;

    while (n != 1) {
        if (answer >= 500) {
            return -1; // 500번 초과 시 -1 반환
        }
        if (n % 2 == 0) {
            n /= 2; // 짝수일 경우 2로 나눔
        }
        else {
            n = n * 3 + 1; // 홀수일 경우 3을 곱하고 1을 더함
        }
        answer++;
    }
    return answer;
}
