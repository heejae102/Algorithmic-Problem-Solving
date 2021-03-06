#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

// 1차 복습 풀이시간 : 13분 (강의 풀이보다 성능이 좋은 새로운 풀이법 추가)
// 2차 복습 풀이시간 : 5분 30초 이내 

/*

<33. 3등의 성적은?(정렬 응용)>

N명의 수학성적이 주어지면 그 중 
3등을 한 수학성적을 출력하는 프로그램을 작성하세요.

만약 학생의 점수가 100점이 3명, 99점이 2명, 98점이 5명, 97점이 3명 
이런식으로 점수가 분포되면 1등은 3명이며, 
2등은 2명이며, 3등은 5명이 되어 98점이 3등을 한 점수가 됩니다.

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 수학성적 점수가 공백을 사이에 두고 입력됩니다. 
수학성적 점수는 100점 만점 기준으로 입력됩니다.

▶ 출력설명
3등을 한 점수를 출력합니다.

=============================================================================

▶ 입력예제
7
80 96 75 82 96 92 100

▶ 출력예제
92

*/

int main()
{
	// 최초의 풀이 (강의 풀이와 동일)

	/*
	int n, idx, temp, res = 1;
	int score[100]{ 0 };

	cin >> n; 

	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}

	// 내림차순 정렬 
	for (int i = 0; i < n - 1; i++)
	{
		idx = i; 

		for (int j = i + 1; j < n; j++)
		{
			if (score[j] > score[idx]) idx = j; 
		}

		temp = score[i];
		score[i] = score[idx];
		score[idx] = temp;
	}

	// 100 96 96 92 82 80 75 
	for (int i = 1; i < n; i++)
	{
		if (score[i - 1] != score[i]) res++;

		if (res >= 3)
		{
			cout << score[i] << endl; 
			break;
		}
	}
	*/

	//============================================================================//

	// 개선된 풀이 (정렬 과정에서 정답 도출)

	/*
	int score[100]{ 0 }, n, idx, temp, count = 1;

	cin >> n; 

	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}

	// 내림차순 정렬 

	for (int i = 0; i < n - 1; i++)
	{
		idx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (score[j] > score[idx]) idx = j;
		}

		temp = score[i];
		score[i] = score[idx];
		score[idx] = temp;

		if (i != 0 && score[i] != score[i - 1])
		{
			if (++count >= 3)
			{
				cout << score[i] << endl;
				break;
			}
		}
	}
	*/

	//============================================================================//

	// 새로운 풀이 (직접 정렬 로직을 구현하지 않는 경우)

	int n, count = 1;

	cin >> n; 

	vector<int> score(n);

	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}

	sort(score.begin(), score.end(), greater<int>());

	for (int i = 1; i < n; i++)
	{
		if (score[i] != score[i - 1])
		{
			if (++count >= 3)
			{
				cout << score[i] << endl;
				break;
			}			
		}
	}

	return 0;
}