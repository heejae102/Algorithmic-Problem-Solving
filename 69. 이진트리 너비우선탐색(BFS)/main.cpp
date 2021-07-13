#include<iostream>
#include<vector>
using namespace std;

// 1�� ���� Ǯ�̽ð� : 12�� �� (���� �ʿ�)

/*

<69. ����Ʈ�� �ʺ�켱Ž��(BFS)>

���� ������ Ž���ϹǷ� ����Ž�����ε� �Ҹ���. 

�Ʒ� �׸��� ���� ����Ʈ���� �ʺ�켱Ž���� ������. 
���� ���� 6���� �Է¹޾� ó���غ�����.


				1
		2				3
	4		5		6		7


�ʺ�켱 Ž�� : 1 2 3 4 5 6 7

=============================================================================

�� �Է¿���
1 2
1 3
2 4
2 5
3 6
3 7

�� ��¿���
1 2 3 4 5 6 7

*/

int main()
{
	// ���� Ǯ�� 

	int Q[100]{ 0 }, ch[10]{ 0 };
	vector<int> map[10];
	int edge = 6, front = -1, back = -1, a, b, x;

	for (int i = 0; i < edge; i++)
	{
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	Q[++back] = 1;
	ch[1] = 1;

	while (front < back)
	{
		x = Q[++front];
		cout << x << " ";

		for (int i = 0; i < map[x].size(); i++)
		{
			if (ch[map[x][i]] != 0) continue;
			
			ch[map[x][i]] = 1;
			Q[++back] = map[x][i];
		}
	}

	return 0;
}