#include<iostream>
#include<stack>
#include<vector>
using namespace std; 

// 1차 복습 풀이시간 : 30분 내 (복습 필요 / 예외처리 오류)

/*

<55. 기차 운행(스택 자료구조 응용)>

A도시에서 출발한 기차는 B도시로 도착한다. 
그런데 도로 중간에 T자형 교차로가 있어 출발한 기차의 도착 순서를 조정할 수 있다.


A도시						B도시

			교차로


교차로에서는 다음과 같은 두 개의 작업을 합니다.

P(push)작업 : A도시에서 오는 기차를 교차로에 넣는다.
O(out)작업 : 교차로에 들어온 가장 최근 기차를 B도시로 보낸다.

만약 2 1 3 기차 번호 순으로 A도시에서 출발하더라도 
B도시에는 T교차로를 이용하여 1 2 3 순으로 도착하게 할 수 있습니다.
그 작업 P, P, O, O, P, O순으로 작업을 하면 B도시에 1, 2, 3 순으로 도착합니다.

1부터 N까지 번호를 가진 기차가 A도시에서 어떤 순으로 출발하든, 
B도시에 번호순으로 도착하도록 하는 교차로 작업을 출력합니다. 

모든 기차는 교차로에 들어가야만 B도시로 갈 수 있습니다. 
번호순서대로 도착이 불가능하면 impossible 이라고 출력합니다.

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(3 <= N <= 30)가 주어진다.
두 번째 줄에 A도시에서 출발하는 기차번호순이 차례대로 입력된다.

▶ 출력설명
교차로 작업을 순서대로 P와 O로 출력한다.

=============================================================================

▶ 입력예제
3
2 1 3

▶ 출력예제
PPOOPO

*/

int main()
{
	// 최초의 풀이 
	// ※ 번호순서대로 도착이 불가능할 경우 impossible만 출력해야 한다. 

	/*
	// 1부터 N까지 번호를 가진 기차가 A도시에서 어떤 순으로 출발하든,
	// B도시에 번호순으로 도착하도록 하는 교차로 작업을 출력합니다.

	// 모든 기차는 교차로에 들어가야만 B도시로 갈 수 있습니다. 
	// 교차로 작업을 순서대로 P와 O로 출력한다.

	int n, temp, idx = 0, pos = 1;

	char str[61]{ 0 };
	stack<int> train;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		train.push(temp);
		str[idx++] = 'P';

		while (temp == pos)
		{
			train.pop();
			pos++;
			str[idx++] = 'O';

			// 스택이 비어있지 않다면(예외검사 필수) 
			// 맨 위에 있는 원소를 temp에 넣어서 비교검사를 이어간다. 
			if(!train.empty()) temp = train.top();
		}
	}

	str[idx] = '\0';

	// 번호순서대로 도착이 불가능하면 impossible 이라고 출력합니다.

	(!train.empty()) ? cout << "impossible" << endl : cout << str << endl;
	*/

	//============================================================================//

	// 개선된 풀이 

	stack<int> train;
	int n, temp, pos = 1, idx = 0;
	char str[61]{ 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		train.push(temp);
		str[idx++] = 'P';

		while (!train.empty() && train.top() == pos)
		{
			train.pop();
			str[idx++] = 'O';
			pos++;
		}
	}

	// 단일문자를 하나씩 입력했기 때문에 문자열로 출력하기 위해서는 
	// 마지막 문자 뒤에 NULL(\0) 값을 추가해주어야 한다. 
	str[idx] = '\0';

	// 번호순대로 도착했다면 스택에 남은 원소가 없어서 empty()에 대해 true를 반환할 것. 
	(train.empty()) ? cout << str << endl : cout << "impossible" << endl;

	//============================================================================//

	// 강의 풀이 (시간 복잡도나 공간 복잡도가 좋지 못함.)

	/*
	vector<char> str; 
	stack<int> train;
	int n, temp, pos = 1;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		train.push(temp);
		str.push_back('P');

		while (1)
		{
			if (train.empty()) break;

			if (pos == train.top())
			{
				train.pop();
				pos++;
				str.push_back('O');
			}
			else break;
		}
	}

	if (!train.empty()) cout << "impossible" << endl;
	else
	{
		for (int i = 0; i < str.size(); i++)
		{
			cout << str[i];
		}
	}
	*/

	return 0;
}