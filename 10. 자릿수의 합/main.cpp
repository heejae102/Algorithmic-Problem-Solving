#include<stdio.h>
#include<iostream>
using namespace std; 

// 1차 복습 풀이시간 : 9분 

/*

<10. 자릿수의 합>

N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고,
그 합이 최대인 자연수를 출력하는 프로그램을 작성하세요.

각 자연수의 자릿수의 합을 구하는 함수 int digit_sum(int x)를
꼭 작성해서 프로그래밍 하세요. 

=============================================================================

▶ 입력설명
첫 줄에 자연수의 개수 N(3 <= N <= 100)이 주어지고, 
그 다음 줄에 N개의 자연수가 주어진다. 

각 자연수의 크기는 10,000,000를 넘지 않는다. 

▶ 출력설명
자릿수의 합이 최대인 자연수를 출력한다. 
자릿수의 합이 최대인 자연수가 여러개인 경우, 
그 중 값이 가장 큰 값을 출력합니다.  

=============================================================================

▶ 입력예제
5
125 15232 79 1325 97

▶ 출력예제
97

*/

// 최초의 풀이 
/*
int digit_sum(int x)
{
	int sum = 0;

	for (int i = 1; i <= x; i *= 10)
	{
		sum += (x / i) % 10;
	}

	return sum;
}
*/

// 새로운 풀이
int digit_sum(int x)
{
	int sum = 0;

	while (x > 0)
	{
		sum += x % 10;
		x /= 10;
	}

	return sum;
}

int main()
{
	// 최초의 풀이 

	/*
	// 첫 줄에 자연수의 개수 N(3 <= N <= 100)이 주어지고,
	// 그 다음 줄에 N개의 자연수가 주어진다.

	int n = 0, max = 0, index = 0;
	int num[100] = { 0 };
	int sum[100] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		sum[i] = digit_sum(num[i]);
		
		if (sum[i] > max)
		{
			max = sum[i];
			index = i;
		}
		else if (sum[i] == max) if (num[index] < num[i]) index = i;
	}

	// 자릿수의 합이 최대인 자연수를 출력한다. 
	// 자릿수의 합이 최대인 자연수가 여러개인 경우, 그 중 값이 가장 큰 값을 출력.  

	printf("%d\n", num[index]);
	*/

	//============================================================================// 

	// 강의 풀이 

	int n, num, sum = 0, max = 0, res = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		sum = digit_sum(num);

		if (sum > max)
		{
			max = sum;
			res = num;
		}
		else if (sum == max) if (num > res) res = num;
	}

	printf("%d\n", res);

	return 0;
}