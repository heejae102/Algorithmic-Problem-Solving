#include<stdio.h>
#include<iostream>
using namespace std; 

// 1차 복습 풀이시간 : 5분 
// 2차 복습 풀이시간 : 7분 이내 

/*

<17. 선생님 퀴즈>

현수네 반은 학생이 N명 있습니다. 
수업도중 선생님이 잠깐 자리를 비워야 하는데 그 동안 
학생들이 떠들거나 놀지 않도록 각 학생들에게 퀴즈를 냈습니다.

선생님은 각 학생들에게 숫자가 적힌 카드를 줬습니다.
각 학생들은 1부터 자기 카드에 적힌 숫자까지의 합을 구하는 퀴즈입니다.

선생님이 돌아와서 각 학생들의 답이 맞았는지 확인을 하려고 하는데
너무 힘들어서 여러분에게 자동으로 채점을 하는 프로그램을 부탁했습니다. 
여러분이 선생님을 도와주세요.

=============================================================================

▶ 입력설명
첫 줄에 반 학생수인 자연수 N(1 <= N <= 10)이 주어집니다.
각 학생들은 1부터 N까지 번호가 부여되어 있다고 가정합니다.

두 번째 줄부터 1번 학생부터의 카드에 적힌 수와 
학생이 구한 정답이 공백을 사이에 두고 입력된다. 
카드에 적힌 수는 1000을 넘지 않는다.

▶ 출력설명
첫 줄부터 1번 학생이 정답을 맞추면 "YES", 틀리면 "NO"를 출력하세요.

=============================================================================

▶ 입력예제
3
10 55
20 350
100 5050

▶ 출력예제
YES
NO
YES

*/

int main()
{
	// 최초의 풀이 

	// 첫 줄에 반 학생수인 자연수 N(1 <= N <= 10)이 주어집니다.
	// 두 번째 줄부터 1번 학생부터의 카드에 적힌 수와 
	// 학생이 구한 정답이 공백을 사이에 두고 입력된다.

	int n, num, answer, count = 0;
	char res[10]{ 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num >> answer;

		count = 0;

		for (int j = 1; j <= num; j++)
		{
			count += j;
		}

		if (count == answer) res[i] = 1;
	}

	// 첫 줄부터 1번 학생이 정답을 맞추면 "YES", 틀리면 "NO"를 출력하세요.
	for (int i = 0; i < n; i++)
	{
		(res[i] == 1) ? printf("YES\n") : printf("NO\n");
	}
	
	//============================================================================// 

	// 강의 풀이 
	// (모든 입력이 끝나고 출력되는 것이 아니라, 하나씩 입력될 때마다 출력) 

	/*
	int n, num, answer, count = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num >> answer;

		count = 0;

		for (int j = 1; j <= num; j++)
		{
			count += j;
		}

		if (count == answer) printf("YES\n");
		else printf("NO\n");
	}
	*/

	return 0;
}