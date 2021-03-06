#include<iostream>
using namespace std; 

// 1차 복습 풀이시간 : 5분 (최적화 필요)
// 2차 복습 풀이시간 : 2분 30초 이내 

/*

<02. 자연수의 합>

자연수 A, B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하세요.

=============================================================================

▶ 입력설명
첫 줄에 자연수 A, B가 공백을 사이에 두고 차례대로 입력된다. (1 <= A < B <= 100)

▶ 출력설명
첫 줄에 더하는 수식과 함께 합을 출력합니다. 

=============================================================================

▶ 입력예제
3	7

▶ 출력예제
3+4+6+7=25

*/

// 최초의 풀이 
int main()
{
	int a, b, sum = 0;

	cin >> a >> b;

	// 최초의 풀이 

	/*
	for (int i = a; i <= b; i++)
	{
		cout << i;

		if (i != b) cout << '+';

		sum += i;
	}

	cout << '=' << sum;
	*/

	for (int i = a; i < b; i++)
	{
		cout << i << '+';
		sum += i;
	}

	cout << b << '=' << sum + b << endl;

	return 0;
}
