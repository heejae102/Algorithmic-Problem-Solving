#include<iostream>
#include<stack>
using namespace std; 

/*

<53. K진수 출력(스택 자료구조 구현)>

10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요. 
스택 자료구조를 사용하시기 바랍니다.

=============================================================================

▶ 입력설명
첫 번째 줄에 10진수 N(10 <= N <= 1,000)과 K(2, 5, 8, 16)가 주어진다.

▶ 출력설명
첫 K진수를 출력한다.

=============================================================================

▶ 입력예제1
11 2

▶ 출력예제1
1011

▶ 입력예제2
31 16

▶ 출력예제2
1F

*/

/*
int top = -1;
int stack[1000]{ 0 };

void push(int input)
{
	stack[++top] = input;
}

int pop()
{
	if (top >= 0) return stack[top--];
}
*/

int main()
{
	// 스택 직접 구현 

	/*
	char str[20]{ "0123456789ABCDEF" };

	int n, k;

	cin >> n >> k;

	while (n > 0)
	{
		push(n % k);
		n /= k;
	}

	while (top != -1)
	{
		cout << str[pop()];
	}
	*/

	//============================================================================//

	// STL 스택 사용 

	char str[20]{ "0123456789ABCDEF" };

	int n, k;

	cin >> n >> k;

	stack<int> num;

	while (n > 0)
	{
		num.push(n % k);
		n /= k;
	}

	while (!num.empty())
	{
		cout << str[num.top()];
		num.pop();
	}

	return 0;
}