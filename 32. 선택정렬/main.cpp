#include<stdio.h>
#include<iostream>
using namespace std; 

/*

<32. 선택정렬>

N개의 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
정렬하는 방법은 선택정렬입니다.

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(1 <= N <= 100)이 주어집니다.
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 
각 자연수는 정수형 범위 안에 있습니다.

▶ 출력설명
오름차순으로 정렬된 수열을 출력합니다.

=============================================================================

▶ 입력예제
6
13 5 11 7 23 15

▶ 출력예제
5 7 11 13 15 23

*/

int main()
{
	// 최초의 풀이 

	/*
	int n, index, temp, min = numeric_limits<int>::max();
	int num[100]{ 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		min = num[i];
		index = i;

		for (int j = i + 1; j < n; j++)
		{
			if (num[j] < min)
			{
				min = num[j];
				index = j;
			}
		}

		temp = num[i];
		num[i] = num[index];
		num[index] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << num[i] << " ";
	}
	*/

	//============================================================================//

	// 강의 풀이 (조금 더 최적화된 풀이)

	int n, temp, index;
	int num[100]{ 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		index = i;

		for (int j = i + 1; j < n; j++)
		{
			if (num[j] < num[index]) index = j;
		}

		temp = num[i];
		num[i] = num[index];
		num[index] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << num[i] << " ";
	}

	return 0;
}