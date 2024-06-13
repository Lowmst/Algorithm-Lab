#include <iostream>
#include <cstdlib>

const int N = 20;
int queens[N];       
int count = 0;     

void output(int n)
{
	count++;
	std::cout << count;
	for (int i = 1; i <= n; i++)
		std::cout << " (" << i << "," << queens[i] << ")";
	std::cout << "\n";
	for (int row = 1; row <= n; row++)
	{
		for (int col = 1; col <= n; col++)
		{
			if (queens[row] != col)
				std::cout << "x ";
			else
				std::cout << "Q ";
		}
		std::cout << "\n";
	}
}

bool check(int row, int col)
{
	for (int i = 1; i < row; i++)
	{
		if (col == queens[i] || abs(i - row) == abs(queens[i] - col))
			return false;
	}
	return true;
}

//�Ե�`row`�н��з���
void place(int row, int n)
{
	if (row > n) //�ѷ��������У����һ�����
		output(n);
	else
	{
		for (int i = 1; i <= n; i++)   //����ÿһ��
		{
			if (check(row, i))
			{
				queens[row] = i;
				place(row + 1, n);  //������һ��
			}
		}
	}
}

int main(void)
{
	place(1, 8);        //��������״̬����
	return 0;
}