#include<iostream>
using namespace std;

// 1�� ���� Ǯ�̽ð� : 10�� �� (���� �ʿ�)

/*

<62. ��������(���� ����)>

N���� ���ڰ� �ԷµǸ� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
�����ϴ� ����� ���������Դϴ�.

=============================================================================

�� �Է¼���
ù ��° �ٿ� �ڿ��� N(1 <= N <= 100)�� �־����ϴ�.
�� ��° �ٿ� N���� �ڿ����� ������ ���̿� �ΰ� �Էµ˴ϴ�. 
�� �ڿ����� ������ ���� �ȿ� �ֽ��ϴ�.

�� ��¼���
������������ ���ĵ� ������ ����մϴ�.

=============================================================================

�� �Է¿���
8
7 6 3 1 5 2 4 8

�� ��¿���
1 2 3 4 5 6 7 8

*/

int arr[101]{ 0 }, temp[101]{ 0 };

/*
void divide(int lt, int rt)
{
	int mid;
	int p1, p2, p3;

	if (lt >= rt) return; 

	mid = (lt + rt) * 0.5f;

	divide(lt, mid);
	divide(mid + 1, rt);

	// �̹� ���ĵǾ� �ִ� �������� ����� ��ġ�� 
	p1 = lt;
	p2 = mid + 1;
	p3 = lt;

	while (p1 <= mid && p2 <= rt)
	{
		(arr[p1] < arr[p2]) ? temp[p3++] = arr[p1++] : temp[p3++] = arr[p2++];
	}

	while (p1 <= mid) temp[p3++] = arr[p1++];
	while (p2 <= rt) temp[p3++] = arr[p2++];

	for (int i = lt; i <= rt; i++)
	{
		arr[i] = temp[i];
	}
}
*/
 
// ���� Ǯ�� ���� 
void divide(int lt, int rt)
{
	if (lt >= rt) return; 

	int mid, p1, p2, p3;

	mid = (lt + rt) * 0.5f;

	divide(lt, mid);
	divide(mid + 1, rt);

	p1 = p3 = lt;
	p2 = mid + 1;

	while (p1 <= mid && p2 <= rt)
	{
		(arr[p1] < arr[p2]) ? temp[p3++] = arr[p1++] : temp[p3++] = arr[p2++];
	}

	while (p1 <= mid) temp[p3++] = arr[p1++];
	while (p2 <= rt) temp[p3++] = arr[p2++];

	for (int i = lt; i <= rt; i++)
	{
		arr[i] = temp[i];
	}
}

int main()
{
	// ���� Ǯ�� 

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	divide(1, n);

	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}