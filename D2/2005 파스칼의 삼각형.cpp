/*

소요 15:00

*/
#include<iostream>

using namespace std;

int arr[10][10];

void paskal(int line)
{
	for (int y = 0; y < line; y++)
	{
		for (int x = 0; x <= y; x++)
		{
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int LINE;
	cin >> T;

	arr[0][0] = 1;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}


	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> LINE;
		cout << "#" << test_case <<endl;
		paskal(LINE);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
