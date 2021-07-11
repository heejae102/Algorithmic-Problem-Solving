#include<iostream>
#include<stack>
using namespace std;

// 1차 복습 풀이시간 : 5분 내 

/*

<58. 이진트리 깊이우선탐색(DFS)>

아래 그림과 같은 이진트리를 전위순회, 중위순회와 후위순회를 연습해보세요.


				1
		2				3
	4		5		6		7


=============================================================================

▶ 입력예제
1

▶ 출력예제
전위순회 출력 : 1 2 4 5 3 6 7
중위순회 출력 : 4 2 5 1 6 3 7
후위순회 출력 : 4 5 2 6 7 3 1

*/

void recur(int vertex)
{
	if (vertex > 7) return; 

	// print 함수가 들어가는 위치에 따라 전위/중위/후위순회

	// 전위순회
	recur(vertex * 2);
	//중위순회
	recur(vertex * 2 + 1);
	//후위순회 
	cout << vertex << " ";
}

int main()
{
	// 강의 풀이 

	int n;
	
	cin >> n;

	recur(n);

	return 0;
}