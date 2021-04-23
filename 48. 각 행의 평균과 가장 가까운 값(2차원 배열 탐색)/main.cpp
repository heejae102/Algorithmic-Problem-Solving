#include<iostream>
#include<cmath>
using namespace std; 

// 1차 복습 풀이시간 : 16분 

/*

<48. 각 행의 평균과 가장 가까운 값(2차원 배열 탐색)>

<그림 1>과 같이 9 × 9 격자판에 쓰여진 81개의 자연수가 주어질 때, 
각 행의 평균을 구하고, 그 평균과 가장 가까운 값을 출력하는 프로그램을 작성하세요. 

평균은 소수점 첫 째 자리에서 반올림합니다. 
평균과 가까운 값이 두 개이면 그 중 큰 값을 출력하세요.

=============================================================================

▶ 입력설명
첫 째 줄부터 아홉 번째 줄까지 한 줄에 아홉 개씩 자연수가 주어진다. 
주어지는 자연수는 100보다 작다.

▶ 출력설명
첫째 줄에 첫 번째 줄부터 각 줄에 각행의 평균과 
그 행에서 평균과 가장 가까운 수를 출력한다.

=============================================================================

▶ 입력예제
3 23 85 34 17 74 25 52 65
10 7 39 42 88 52 14 72 63
87 42 18 78 53 45 18 84 53
34 28 64 85 12 16 75 36 55
21 77 45 35 28 75 90 76 1
25 87 65 15 28 11 37 28 74
65 27 75 41 7 89 78 64 39
47 47 70 45 23 65 3 41 44
87 13 82 38 50 12 48 29 80

▶ 출력예제
42 34
43 42
53 53
45 36
50 45
41 37
54 64
43 44
49 50

*/

int main()
{
	// 최초의 풀이 

	/*
	// 첫 째 줄부터 아홉 번째 줄까지 한 줄에 아홉 개씩 자연수가 주어진다.

	int sum = 0, res = 0;
	int num[9][9]{ 0 }, average[9]{ 0 };

	for (int i = 0; i < 9; i++)
	{
		sum = 0;

		for (int j = 0; j < 9; j++)
		{
			cin >> num[i][j];

			sum += num[i][j];
		}

		// ※ 계산 값이 실수로 반환될 수 있도록 상수를 9.0f 의 실수형으로 작성해주어야 함.
		average[i] = round(sum / 9.0f);
	}

	// 평균은 소수점 첫 째 자리에서 반올림합니다.
	// 평균과 가까운 값이 두 개이면 그 중 큰 값을 출력하세요.

	for (int i = 0; i < 9; i++)
	{
		res = num[i][0];

		for (int j = 1; j < 9; j++)
		{
			if (abs(average[i] - num[i][j]) < abs(average[i] - res))
			{
				res = num[i][j];
			}
			else if (abs(average[i] - num[i][j]) == abs(average[i] - res))
			{
				if (num[i][j] > res) res = num[i][j];
			}
		}

		cout << average[i] << " ";
		cout << res << endl; 
	}
	*/

	// 개선된 풀이 (입력과 동시에 출력되는 형태. 강의 풀이보다 변수 적게 사용.)

	int num[9][9]{ 0 }, sum = 0, res = 0, average;

	for (int i = 0; i < 9; i++)
	{
		sum = 0;

		for (int j = 0; j < 9; j++)
		{
			cin >> num[i][j];

			sum += num[i][j];
		}

		average = (sum / 9.0f) + 0.5f;

		cout << average << " ";

		res = num[i][0];

		for (int j = 1; j < 9; j++)
		{
			if (abs(average - num[i][j]) < abs(average - res))
			{
				res = num[i][j];
			}
			else if (abs(average - num[i][j]) == abs(average - res))
			{
				if (num[i][j] > res) res = num[i][j];
			}
		}

		cout << res << endl; 
	}


	//============================================================================//

	// 강의 풀이 (입력과 동시에 출력되는 형태)

	/*
	int sum, average, min, temp, res; 
	int num[9][9]{ 0 };

	for (int i = 0; i < 9; i++)
	{
		sum = 0;

		for (int j = 0; j < 9; j++)
		{
			cin >> num[i][j];

			sum += num[i][j];
		}

		// 0.5를 더해서 int형으로 캐스팅하면 소수점 첫째자리에서 반올림 
		average = (sum / 9.0f) + 0.5f;

		cout << average << " ";

		min = numeric_limits<int>::max();

		for (int j = 0; j < 9; j++)
		{
			temp = abs(average - num[i][j]);

			if (temp < min)
			{
				min = temp;
				res = num[i][j];
			}
			else if (temp == min) if (num[i][j] > res) res = num[i][j];
		}

		cout << res << endl; 
	}
	*/
	
	return 0;
}