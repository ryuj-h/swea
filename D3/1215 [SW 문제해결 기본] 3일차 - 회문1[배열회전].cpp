/*
소요시간 :  31:41
푼 방식 배열 회전

*/


#include<iostream>

using namespace std;

char arr[10][10];

bool ishm(char* str, int N)
{
	for (int i = 0; i < N / 2; i++)
	{
		if (str[i] != str[N - i - 1])
			return false;
	}
	return true;
}

void rotate()
{
	static char tmparr[10][10];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			tmparr[i][j] = arr[8 - 1 - j][i];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			arr[i][j] = tmparr[i][j];
}

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int N;
		int Sol = 0;

		cin >> N;
		for (int y = 0; y < 8; y++)
		{
			char buf[11];
			cin >> buf;
			for (int x = 0; x < 8; x++)
			{
				arr[y][x] = buf[x];
			}
		}

		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8 - N +1; x++)
			{
				if (ishm(&arr[y][x],N))
				{
					Sol++;
				}
			}
		}

		rotate();
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8 - N + 1; x++)
			{
				if (ishm(&arr[y][x], N))
				{
					Sol++;
				}
			}
		}

		cout << "#" << test_case << " " << Sol << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
