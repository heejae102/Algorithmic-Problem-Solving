#include<stdio.h>
#include<iostream>
using namespace std; 

// 1차 복습 풀이시간 : 8분 (최적화 필요)

/*

<08. 올바른 괄호(문자열 컨트롤)>

괄호가 입력되면 올바른 괄호이면 "YES", 올바르지 않으면 "NO"를 출력합니다.
(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아닙니다.

=============================================================================

▶ 입력설명
첫 번째 줄에 괄호 문자열이 입력된다. 문자열의 최대 길이는 30입니다. 

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
	// 최초의 풀이 

	/*
	// 괄호 문자열을 입력받음. 문자열의 최대 길이는 30.
	char input[31] = { 0 };
	int leftP = 0, rightP = 0;

	cin >> input;

	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == '(') leftP++;
		else
		{
			(leftP > 0) ? leftP-- : rightP++;
		}
	}

	// 올바른 괄호일 경우 YES, 아닐 경우 NO 출력 
	(leftP == 0) && (rightP == 0) ? printf("YES\n") : printf("NO\n");
	*/

	//============================================================================// 

	// 강의 풀이

	char input[31] = { 0 };
	int matchP = 0;

	cin >> input;

	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == '(') matchP++;
		else
		{
			matchP--;

			// matchP가 음수가 될 경우 
			// ())( 
			// 위와 같이 올바른 괄호 형태가 아니므로 break; 

			if (matchP < 0) break;
		}
	}

	(matchP == 0) ? printf("YES\n") : printf("NO\n");

	return 0;
}