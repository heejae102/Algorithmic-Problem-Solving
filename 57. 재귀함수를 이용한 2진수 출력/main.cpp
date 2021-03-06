#include<iostream>
#include<stack>
using namespace std;

// 1차 복습 풀이시간 : 3분 30초 내 

/*

<57. 재귀함수 이진수 출력>

10진수 N이 입력되면 2진수로 변환하여 출력하는 프로그램을 작성하세요.
단 재귀함수를 이용해서 출력해야 합니다.

=============================================================================

▶ 입력설명
첫 번째 줄에 10진수 N(1 <= N <= 1,000)이 주어집니다.

▶ 출력설명
첫 번째 줄에 이진수를 출력하세요.

=============================================================================

▶ 입력예제1
11

▶ 출력예제1
1011

*/

/*
stack<int> num;

void recur(int x)
{
	if (x <= 0) return;

	num.push(x % 2);
	recur(x / 2);
}
*/

void recursive(int x)
{
	if (x <= 0) return; 

	recursive(x / 2);
	cout << x % 2;
}

int main()
{
	// 최초의 풀이 
	
	/*
	int n;

	cin >> n;
	recur(n);

	while (!num.empty())
	{
		cout << num.top();
		num.pop();
	}
	*/

	//============================================================================//

	// 강의 풀이 

	int n; 

	cin >> n;

	recursive(n);

	return 0;
}