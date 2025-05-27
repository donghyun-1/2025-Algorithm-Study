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
using namespace std;
int main()
{
	//while (input.find(checkWord) != string::npos)
	//{
	//	//cout << input.find(checkWord) << "찾음";
	//	int index = input.find(checkWord);
	//	input = input.erase(index, wordSize);
	//	count++;
	//}
	/*
		위에 원래 input을 삭제 하면 안되는게 예외가 있다.
		aabb
		ab
		이러면 맨처음에 ab를 삭제를 하면
		ab가 또 남아버림
		그래서 답이 2로 나와버리는데 이건 오답임
		따라서 원래 문자열을 건드리지말고 index만 옮겨보도록함
	*/

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;
	getline(cin, input);
	string checkWord;
	getline(cin, checkWord);
	int count = 0;
	int wordSize = checkWord.size();
	size_t pos = 0;
	string temp = input;
	while (true) 
	{
		pos = temp.find(checkWord);
		if (pos == string::npos) break;
		count++;
		// 찾은 위치 다음부터 새로운 부분 문자열 생성
		temp = temp.substr(pos + wordSize);
	}
	cout << count;

}