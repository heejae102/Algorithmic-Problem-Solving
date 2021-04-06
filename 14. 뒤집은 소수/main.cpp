#include<stdio.h>
#include<iostream>
using namespace std; 

/*

<14. 뒤집은 소수>

N개의 자연수가 입력되면 각 자연수를 뒤집은 후 
그 뒤집은 수가 소수이면 그 수를 출력하는 프로그램을 작성하세요. 

예를 들어 32를 뒤집으면 23이고, 23은 소수이다. 
그러면 23을 출력한다. 
단 910를 뒤집으면 19로 숫자화 해야 한다. 
첫 자리부터의 연속된 0은 무시한다.

뒤집는 함수인 int reverse(int x) 와 
소수인지를 확인하는 함수 bool isPrime(int x)를 반드시
작성하여 프로그래밍 한다.

=============================================================================

▶ 입력설명
첫 줄에 자연수의 개수 N(3 <= N <= 100)이 주어지고, 
그 다음 줄에 N개의 자연수가 주어진다.
각 자연수의 크기는 100,000를 넘지 않는다.

▶ 출력설명
첫 줄에 뒤집은 소수를 출력합니다. 
출력순서는 입력된 순서대로 출력합니다.

=============================================================================

▶ 입력예제 
5
32 55 62 3700 250

▶ 출력예제 
23 73

*/

// 최초의 풀이 

/*
// 뒤집는 함수 
int reverse(int x)
{
	// 각 자연수의 크기는 100, 000를 넘지 않으므로 
	// 크기 6을 수용하는 문자열 정의 

	int res = 0;
	char ch[7] = { 0 };
	sprintf_s(ch, "%d", x);

	for (int i = 0, j = 1; i < strlen(ch); i++, j *= 10)
	{
		res += (ch[i] - '0') * j;
	}

	return res;
}

// 소수인지 확인하는 함수 
bool isPrime(int x)
{
	if(x == 1) return false; 

	for (int i = 2; i < x; i++)
	{
		if (x % i == 0) return false;
	}

	return true;
}
*/

//============================================================================// 

// 강의 풀이 

// 뒤집는 함수 
int reverse(int x)
{
	int res = 0;

	while (x > 0)
	{
		res = (res * 10) + (x % 10);
		x /= 10;
	}

	return res;
}

// 소수인지 확인하는 함수 
bool isPrime(int x)
{
	if (x == 1) return false; 

	// 1과 자기자신을 제외한 약수가 존재하는지 확인 
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0) return false; 
	}

	return true; 
}

int main()
{
	// 최초의 풀이 

	int n, num, res = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		res = reverse(num);

		// 소수는 1을 포함하지 않으므로 1은 제외할 것. 
		if (isPrime(res)) printf("%d ", res);
	}

	return 0;
}