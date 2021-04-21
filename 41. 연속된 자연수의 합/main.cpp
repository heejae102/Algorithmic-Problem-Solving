#include<stdio.h>
#include<iostream>
using namespace std; 

// 1차 복습 풀이시간 : 16분 (복습 필요 / 강의 풀이 암기하기) 

/*

<41. 연속된 자연수의 합>

입력으로 양의 정수 N이 입력되면 2개 이상의 연속된 자연수의 합으로 
정수 N을 표현하는 방법의 가짓수를 출력하는 프로그램을 작성하세요.

만약 N = 15이면
7 + 8 = 15
4 + 5 + 6 = 15
1 + 2 + 3 + 4 + 5 = 15
와 같이 총 3가지의 경우가 존재한다.

=============================================================================

▶ 입력설명
첫 번째 줄에 양의 정수 N(7 <= N < 1000)이 주어진다.

▶ 출력설명
첫줄부터 각각의 경우의 수를 출력한다.
맨 마지막 줄에 총 개수를 출력한다.

=============================================================================

▶ 입력예제
15

▶ 출력예제
7 + 8 = 15
4 + 5 + 6 = 15
1 + 2 + 3 + 4 + 5 = 15
3

*/

int main()
{
	// 최초의 풀이 

	/*
	int n, temp, count, res = 0;

	cin >> n; 

	for (int i = (n * 0.5) + 1; i > 0; i--)
	{
		count = 0;

		for (int j = i; j > 0; j--)
		{
			count += j;

			if (count == n)
			{
				res++;
				temp = j;
				cout << temp << " ";

				while (temp < i)
				{
					cout << "+ " << ++temp << " ";
				}

				cout << "= " << n << endl;
				break;
			}
			else if (count > n) break;
		}
	}

	cout << res << endl; 
	*/

	//============================================================================//

	// 개선된 풀이 (최초의 풀이 살짝 정돈)

	/*
	int n, temp, sum = 0, count = 0;

	cin >> n;

	for (int i = n * 0.5 + 1; i > 0; i--)
	{
		sum = i;

		for (int j = i - 1; j > 0; j--)
		{
			sum += j;

			if (sum == n)
			{
				temp = j;

				while (temp < i) cout << temp++ << " + ";
				
				cout << i << " = " << n << endl;

				count++;
				break;
			}
			if (sum > n) break;
		}
	}

	cout << count << endl; 
	*/

	//============================================================================//


	// 강의 풀이 

	// (1, 2) 연속된 수 2개에서 연속 텀 3을 원래 수에서 빼고(12) 해당 수를 2개로
	// 나누었을 때 나누어 떨어지면 2개로 연달아서 더했을 때 원래의 수(15)가 되는 것.  

	int n, i, count = 1, temp, res = 0;

	cin >> n; 

	temp = n--;

	while (n > 0)
	{
		count++;

		n -= count;

		if (n % count == 0)
		{
			for (i = 1; i < count; i++)
			{
				cout << (n / count) + i << " + ";
			}

			cout << (n / count) + i << " = " << temp << endl;
			res++;
		}
	}

	cout << res << endl; 

	return 0;
}