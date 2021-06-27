#include<iostream>
#include<stack>
using namespace std;

// 1차 복습 풀이시간 : 8분 30초 내 (강의 풀이 복습 필요)

/*

<54. 올바른 괄호(STL 스택 자료구조 활용)>

괄호가 입력되면 올바른 괄호이면 "YES", 
올바르지 않으면 "NO"를 출력합니다.

(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.

=============================================================================

▶ 입력설명
첫 번째 줄에 괄호 문자열이 입력됩니다. 
문자열의 최대 길이는 30이다.

▶ 출력설명
첫 번째 줄에 YES, NO를 출력한다.

=============================================================================

▶ 입력예제1
(()(()))(()

▶ 출력예제1
NO

▶ 입력예제2
()()(()())

▶ 출력예제2
YES

*/

int main()
{
	// 최초의 풀이 (문자열 활용)

	/*
	char str[31]{ 0 };
	int count = 0;

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		// 왼쪽 괄호 
		if (str[i] == '(')
		{
			count++;
		}
		// 오른쪽 괄호 
		else
		{
			count--;

			if (count < 0)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	(count == 0) ? cout << "YES" << endl : cout << "NO" << endl;
	*/

	// 최초의 풀이 (STL 스택 활용)
	
	stack<char> s;

	char str[31]{ 0 };

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else
		{
			if (s.empty())
			{
				cout << "NO" << endl;
				return 0;
			}

			s.pop();
		}
	}

	(s.empty()) ? cout << "YES" << endl : cout << "NO" << endl;

	//============================================================================//

	// 강의 풀이 (flag를 꼭 써야할까...? return하지 않으면 안되는걸까?)

	/*
	stack<char> s;

	char str[31]{ 0 };
	int flag = 1;

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else
		{
			if (s.empty())
			{
				cout << "NO" << endl;
				flag = 0;
				break;
			}

			s.pop();
		}
	}
	
	if(flag) (s.empty()) ? cout << "YES" << endl : cout << "NO" << endl;
	*/

	return 0;
}