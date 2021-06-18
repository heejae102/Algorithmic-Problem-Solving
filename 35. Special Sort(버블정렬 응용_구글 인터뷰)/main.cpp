#include<stdio.h>
#include<iostream>
using namespace std; 

// 1차 복습 풀이시간 : 10분 (강의 풀이는 복습 필요)
// 2차 복습 풀이시간 : 9분 이내 

/*

<35. Special Sort(버블정렬 응용 : 구글 인터뷰)>

N개의 정수가 입력되면 당신은 입력된 값을 정렬해야 한다.
음의 정수는 앞쪽에 양의정수는 뒷쪽에 있어야 한다. 
또한 양의 정수와 음의 정수의 순서에는 변함이 없어야 한다.

=============================================================================

▶ 입력설명
첫 번째 줄에 정수 N(5 <= N <= 100)이 주어지고, 
그 다음 줄부터 음수를 포함한 정수가 주어진다. 
숫자 0은 입력되지 않는다.

▶ 출력설명
정렬된 결과를 출력한다.

=============================================================================

▶ 입력예제
8
1 2 3 -3 -2 5 6 -6

▶ 출력예제
-3 -2 -6 1 2 3 5 6

*/

int main()
{
	// 최초의 풀이 (스와이프 횟수 : 11)
	// 선택정렬을 사용하면 양수의 순서를 바꿔버리므로 버블정렬을 사용해야 함.

	/*
	int n, idx = 0, temp, swipeCount = 0;
	int num[100]{ 0 };

	cin >> n; 

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	// idx를 증가시켜야하기 때문에 i는 반드시 0부터 시작해야 함. 
	for (int i = 0; i < n; i++)
	{
		if (num[i] > 0) continue;

		// j > idx 이기 떄문에 해당 인덱스 순서에 이미 음수가 있는 경우는 조건에 부합하지 x 
		// j, j - 1 둘을 스와이프하기 때문에 j는 idx 보다 커야 함. (idx 자리로 스와이프해야 함.)
		for (int j = i; j > idx; j--)
		{
			temp = num[j];
			num[j] = num[j - 1];
			num[j - 1] = temp;

			swipeCount++;
		}

		idx++;
	}

	for (int i = 0; i < n; i++)
	{
		cout << num[i] << " ";
	}

	cout << endl << swipeCount << endl;
	*/

	//============================================================================//

	// 강의 풀이 (스와이프 횟수 : 11)
	
	int n, temp, swipeCount = 0;
	int num[100]{ 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (num[j] < 0 && num[j - 1] > 0)
			{
				temp = num[j];
				num[j] = num[j - 1];
				num[j - 1] = temp;

				swipeCount++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << num[i] << " ";
	}

	//cout << endl << swipeCount << endl; 

	return 0;
}