#include<iostream>
#include<limits>
using namespace std; 

// 1차 복습 풀이시간 : 5분
// 2차 복습 풀이시간 : 3분 30초 이내 

/*

<04. 나이 차이>

N(2 <= N <= 100) 명의 나이가 입력됩니다. 
이 N명의 사람 중 가장 나이차이가 많이 나는 경우는 몇 살일까요? 
최대 나이 차이를 출력하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
입력파일은 input.txt로 한다.
첫 줄에 자연수 N(2 <= N <= 100)이 입력되고, 
그 다음 줄에 N개의 나이가 입력된다. 

▶ 출력설명
출력파일은 output.txt로 한다. 
첫 줄에 최대 나이차이를 출력합니다. 

=============================================================================

▶ 입력예제
10
13	15	34	23	45	65	33	11	26	42

▶ 출력예제
54

*/

/*

<자료형의 최대값/최소값 받아오기>

헤더파일 : #include<limits>

numeric_limits<int>::max 
해당 자료형의 최대값 

numeric_limits<int>::min
해당 자료형의 최소값

*/

int main()
{
	// 최초의 풀이 

	/*
	int num, min, max = 0;
	int age[100] = { 0 };

	cin >> num;

	for (int i = 0; i < num; i++)
		cin >> age[i];

	min = age[0];

	for (int i = 0; i < num; i++)
	{
		if (age[i] < min) min = age[i];
		if (age[i] > max) max = age[i];
	}

	cout << max - min << endl;
	*/

	// 강의 풀이 

	int num, input, max = 0, min = numeric_limits<int>::max();

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> input;

		if (input < min) min = input;
		if (input > max) max = input;
	}

	cout << max - min;

	return 0;
}