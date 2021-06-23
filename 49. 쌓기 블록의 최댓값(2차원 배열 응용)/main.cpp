#include<iostream>
#include<vector>
using namespace std;

// 1차 복습 풀이시간 : 20분 (복습 필요)
// 2차 복습 풀이시간 : 12분 내 

/*

<49. 쌓기 블록의 최댓값(2차원 배열 응용)>

현수는 블록놀이를 좋아합니다. 
현수에게 정면에서 본 단면과 오른쪽 측면에서 본 단면을 주고, 
최대 블록개수를 사용하여 정면과 오른쪽 측면에서 
본 모습으로 블록을 쌓으라 했습니다.

현수가 블록을 쌓는데 사용해야 할 최대 개수를 출력하는 프로그램을 작성하세요.

   ■
■  ■ 
■  ■ ■

<정면>

      ■
    ■ ■
■ ■ ■ ■

<오른쪽 측면>

2   3 1
2   2 1
1   1 1
1   1 1

<위에서 본 높이(최대개수)>

위에서 봤을 때 각 칸의 블록의 개수입니다. 
정면에서의 높이 정보와 오른쪽 측면에서의 높이 정보가 주어지면 
사용할 수 있는 블록의 쵀대 개수를 출력하세요.

=============================================================================

▶ 입력설명
첫 줄에 블록의 크기 N(3 <= N <= 10)이 주어집니다. 
블록이 크기는 정사각형 N*N입니다.

두 번째 줄에 N개의 정면에서의 높이 정보가 왼쪽 정보부터 주어집니다.
세 번째 줄에 N개의 오른쪽 측면 높이 정보가 앞쪽부터 주어집니다.
블록의 높이는 10 미만입니다.

▶ 출력설명
첫 줄에 블록의 최대 개수를 출력합니다.

=============================================================================

▶ 입력예제
4
2 0 3 1
1 1 2 3

▶ 출력예제
17

*/

int main()
{
	// 최초의 풀이 

	/*
	// 첫 줄에 블록의 크기 N(3 <= N <= 10)이 주어집니다.
	// 블록이 크기는 정사각형 N*N입니다.

	int block[10][10]{ 0 }, front[10]{ 0 }, right[10]{ 0 }, n, res = 0;

	cin >> n;

	// 정면과 우측 정보 입력 

	for (int i = 0; i < n; i++)
	{
		cin >> front[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		cin >> right[i];
	}

	// 최대 블록 개수 검사 (정면 -> 우측)
	// 정면으로 최대 값을 먼저 넣어놓고, 우측의 값을 비교하여 우측의 범위를 벗어나면 
	// 우측의 범위 값에 맞춰서 결과값을 산출 

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			block[j][i] = front[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (block[i][j] > right[i]) block[i][j] = right[i];

			res += block[i][j];
		}
	}

	cout << res << endl; 
	*/

	//============================================================================//

	// 개선된 풀이 (입력과 동시에 계산)

	int n, input, count = 0, arr[10][10]{ 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		for (int j = 0; j < n; j++)
		{
			arr[j][i] = input;
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		cin >> input;

		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > input) arr[i][j] = input; 

			count += arr[i][j];
		}
	}

	cout << count << endl; 

	//============================================================================//

	// 강의 풀이 (변수 하나를 줄이고 입력과 동시에 계산) 

	/*
	int block[10][10]{ 0 }, input[10]{ 0 }, n, res = 0;

	cin >> n;

	// 정면 값 입력 
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			block[j][i] = input[i];
		}
	}

	// 우측면 값 입력 
	for (int i = n - 1; i >= 0; i--)
	{
		cin >> input[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (block[i][j] > input[i]) block[i][j] = input[i];
		
			res += block[i][j];
		}
	}

	cout << res << endl; 
	*/

	return 0;
}