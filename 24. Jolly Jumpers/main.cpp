#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std; 

// 1차 복습 풀이시간 : 15분 
// (복습필요 / 배열의 인덱스 값 계산 시 예외처리 필요)
// (입력받으면서 바로 연산할 수 있도록 구현할 것)

// 2차 복습 풀이시간 : 6분 이내 (인덱스 범위 실수 / 최적화 필요)

/*

<24. Jolly Jumpers>

N개의 정수로 이루어진 수열에 대해 서로 인접해 있는 두 수의 차가 
1에서 N-1까지의 값을 모두 가지면 그 수열을 유쾌한 점퍼(jolly jumper)라고 부른다. 

예를 들어 다음과 같은 수열에서 1 4 2 3 앞 뒤에 있는 숫자 차의 절대 값이 
각각 3 ,2, 1이므로 이 수열은 유쾌한 점퍼가 된다. 

어떤 수열이 유쾌한 점퍼인지 판단할 수 있는 프로그램을 작성하라.

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(3 <= N <= 100)이 주어진다.
그 다음 줄에 N개의 정수가 주어진다. 

정수의 크기는 int 형 범위안에 있으며, 
인접한 두 수의 차도 정수형 범위에 있습니다.

▶ 출력설명
유쾌한 점퍼이면 “YES"를 출력하고, 그렇지 않으면 ”NO"를 출력한다.

=============================================================================

▶ 입력예제
5
1 4 2 3 7

▶ 출력예제
YES

*/

int main()
{
	// 최초의 풀이 

	/*
	// 첫 번째 줄에 자연수 N(3 <= N <= 100)이 주어진다.
	// 그 다음 줄에 N개의 정수가 주어진다.

	int n, preNum, curNum, temp;
	int gap[100]{ 0 };

	cin >> n;

	cin >> preNum;

	for (int i = 1; i < n; i++)
	{
		cin >> curNum;

		// temp 값이 gap의 사이즈를 초과하는 경우를 방지하기 위해 
		// 값을 먼저 계산 후 사이즈 범위 내의 값일 경우에만 해당 인덱스 값 +1 
		temp = abs(curNum - preNum);
		if (temp < 100) gap[temp]++;

		preNum = curNum;
	}

	// 유쾌한 점퍼이면 "YES"를 출력하고, 그렇지 않으면 "NO"를 출력한다.
	for (int i = 1; i < n; i++)
	{
		if (gap[i] == 0)
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	*/
	
	//============================================================================//

	// 개선된 풀이 (중복된 수가 입력되는 케이스에 대해서도 정답 출력)

	int n, preNum, curNum, temp;

	cin >> n; 

	vector<int> num(n, 0);

	cin >> preNum;

	for (int i = 1; i < n; i++)
	{
		cin >> curNum;

		temp = abs(curNum - preNum);

		// temp는 절대값이므로 음수일 수는 없고, 0이거나 n보다 큰 경우 100% 오답
		// 중복된 수열차가 존재해도 100% 오답 

		if (temp == 0 || temp >= n || num[temp] != 0)
		{
			cout << "NO" << endl; 
			return 0;
		}

		num[temp] = 1; 
		preNum = curNum;
	}

	cout << "YES" << endl; 

	//============================================================================//

	// 강의 풀이 (시간 복잡도가 더 우수, 중복된 수가 입력될 경우 오답 발생!!)

	/*
	int n, preNum, curNum, temp;

	cin >> n;

	cin >> preNum;

	vector<int> gap(n, 0);

	for (int i = 1; i < n; i++)
	{
		cin >> curNum;

		temp = abs(preNum - curNum);

		// temp(수열의 차)가 인덱스 범위 값이고, 해당 값이 최초로 등장하는 경우는 count
		// 그렇지 않은 경우가 발생 시 문제의 조건을 충족하지 못하므로 바로 NO 출력 
		if (temp < n && gap[temp] == 0) gap[temp] = 1;
		else
		{
			printf("NO\n");
			return 0;
		}

		preNum = curNum;
	}

	// NO가 출력되어 프로그램이 종료되지 않았다면, 조건이 충족되었다는 의미로 YES 출력 
	printf("YES\n");
	*/

	return 0;
}