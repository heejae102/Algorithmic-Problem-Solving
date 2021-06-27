#include<iostream>
#include<stack>
using namespace std;

// 1�� ���� Ǯ�̽ð� : 8�� 30�� �� (���� Ǯ�� ���� �ʿ�)

/*

<54. �ùٸ� ��ȣ(STL ���� �ڷᱸ�� Ȱ��)>

��ȣ�� �ԷµǸ� �ùٸ� ��ȣ�̸� "YES", 
�ùٸ��� ������ "NO"�� ����մϴ�.

(())() �̰��� ��ȣ�� ���� �ùٸ��� ��ġ�ϴ� ������, (()()))�� �ùٸ� ��ȣ�� �ƴϴ�.

=============================================================================

�� �Է¼���
ù ��° �ٿ� ��ȣ ���ڿ��� �Էµ˴ϴ�. 
���ڿ��� �ִ� ���̴� 30�̴�.

�� ��¼���
ù ��° �ٿ� YES, NO�� ����Ѵ�.

=============================================================================

�� �Է¿���1
(()(()))(()

�� ��¿���1
NO

�� �Է¿���2
()()(()())

�� ��¿���2
YES

*/

int main()
{
	// ������ Ǯ�� (���ڿ� Ȱ��)

	/*
	char str[31]{ 0 };
	int count = 0;

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		// ���� ��ȣ 
		if (str[i] == '(')
		{
			count++;
		}
		// ������ ��ȣ 
		else
		{
			count--;

			if (count < 0)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	(count == 0) ? cout << "YES" << endl : cout << "NO" << endl;
	*/

	// ������ Ǯ�� (STL ���� Ȱ��)
	
	stack<char> s;

	char str[31]{ 0 };

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else
		{
			if (s.empty())
			{
				cout << "NO" << endl;
				return 0;
			}

			s.pop();
		}
	}

	(s.empty()) ? cout << "YES" << endl : cout << "NO" << endl;

	//============================================================================//

	// ���� Ǯ�� (flag�� �� ����ұ�...? return���� ������ �ȵǴ°ɱ�?)

	/*
	stack<char> s;

	char str[31]{ 0 };
	int flag = 1;

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else
		{
			if (s.empty())
			{
				cout << "NO" << endl;
				flag = 0;
				break;
			}

			s.pop();
		}
	}
	
	if(flag) (s.empty()) ? cout << "YES" << endl : cout << "NO" << endl;
	*/

	return 0;
}