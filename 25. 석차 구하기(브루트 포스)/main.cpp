#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

/*

<25. 석차 구하기(브루트 포스)>

N명의 학생의 수학점수가 입력되면 
각 학생의 석차를 입력된 순서대로 출력하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 줄에 N(1<=N<=100)이 입력되고, 
두 번째 줄에 수학점수를 의미하는 N개의 정수가 입력된다. 

같은 점수가 입력될 경우 높은 석차로 동일 처리한다. 
즉 가장 높은 점수가 92점인데 92점이 3명 존재하면 
1등이 3명이고 그 다음 학생은 4등이 된다. 

점수는 100점 만점이다.

▶ 출력설명
첫 줄에 입력된 순서대로 석차를 출력한다.

=============================================================================

▶ 입력예제
5
90 85 92 95 90

▶ 출력예제
3 5 2 1 3

*/

int main()
{
	// 최초의 풀이 

	/*
	int n, count = 0;
	int rank[100]{ 0 };

	cin >> n; 

	vector<int> score(n);
	vector<int> ordered(n);

	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
		ordered[i] = score[i];
	}

	// 벡터 내림차순 정렬
	sort(ordered.begin(), ordered.end(), greater<int>());

	// 같은 점수가 입력될 경우 높은 석차로 동일 처리한다. 
	// 즉 가장 높은 점수가 92점인데 92점이 3명 존재하면
	// 1등이 3명이고 그 다음 학생은 4등이 된다.

	for (int i = 0; i < n; i++)
	{
		count++;

		if (i != 0 && ordered[i - 1] == ordered[i]) continue;

		for (int j = 0; j < n; j++)
		{
			if (ordered[i] == score[j]) rank[j] = count;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", rank[i]);
	}
	*/

	//============================================================================//

	// 강의 풀이 (시간 복잡도는 같지만 공간 복잡도가 더 우수)

	int n; 
	int score[100], rank[100];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
		rank[i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (score[i] < score[j]) rank[i]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", rank[i]);
	}

	return 0;
}