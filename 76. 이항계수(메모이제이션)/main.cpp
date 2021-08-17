#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*

<76. 이항계수(메모이제이션)>

이항계수는 N개의 원소를 가지는 집합에서 
R개의 원소를 뽑아 부분집합을 만드는 경우의 수를 의미한다. 
공식은 nCr 로 표현된다.
N과 R이 주어지면 이항계수를 구하는 프로그램을 작성하세요.

nCr = (n-1)C(r-1) + (n-1)Cr

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(1 <= N <= 20)과 R(0 <= R <= 20)이 주어진다. 단 (N >= R)

▶ 출력설명
첫 번째 줄에 이항계수 값을 출력한다.

=============================================================================

▶ 입력예제
5 3

▶ 출력예제
10

*/

/*
int factorial(int n)
{
	if (n == 1) return 1; 
	else return n * factorial(n - 1);
}
*/

int dy[21][21]{ 0 };

int DFS(int n, int r)
{
	// Memoization(메모이제이션) 
	// 이미 계산된 값은(0보다 큰 경우) 중복으로 계산하지 않고 저장된 값을 리턴 
	if (dy[n][r] > 0) return dy[n][r];

	if (n == r || r == 0) return 1; 
	else return  dy[n][r] = DFS(n - 1, r - 1) + DFS(n - 1, r);	// 계산된 값을 dy에 넣고 리턴 
}

int main()
{
	// 강의 풀이 

	int n, r;

	cin >> n >> r;
	cout << DFS(n, r) << endl;

	return 0;
}