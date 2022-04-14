
/*
달팽이는 1부터 N*N까지의 숫자가 시계방향으로 이루어져 있다.

다음과 같이 정수 N을 입력 받아 N크기의 달팽이를 출력하시오.


[예제]

N이 3일 경우,
 



N이 4일 경우,
 


[제약사항]

달팽이의 크기 N은 1 이상 10 이하의 정수이다. (1 ≤ N ≤ 10)


[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스에는 N이 주어진다.


[출력]

각 줄은 '#t'로 시작하고, 다음 줄부터 빈칸을 사이에 두고 달팽이 숫자를 출력한다.

(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

*/

#include<iostream>

using namespace std;

int arr[11][11];

void print(int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j];// << " ";
			if (j != N - 1)
				cout << " ";
		}
		cout << endl;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		int Endnum = N * N / 4 + N * N % 4;
	
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				arr[i][j] = -1;
		for (int i = 0; i < N; i++)
			for (int j = 0 ;j < N; j++)
				arr[i][j] = 0;
		
		int currnum = 1;
		int currx = 0;
		int curry = 0;
		
		int direction = 3;//0 - 상 1 - 하 2 - 좌 3 - 우

		while (currnum<= N*N)
		{
			arr[curry][currx] = currnum;
			currnum++;
			//print(N);

			switch (direction)
			{
			case 0:
				if (arr[curry - 1][currx] != 0)
				{
					direction = 3;
					currx++;
				}
				else
				{
					curry--;
				}
				break;
			case 1:
				if (arr[curry + 1][currx] != 0)
				{
					direction = 2;
					currx--;
				}
				else
				{
					curry++;
				}

				break;
			case 2:
				if (arr[curry][currx - 1] != 0)
				{
					direction = 0;
					curry--;
				}
				else
				{
					currx--;
				}
				break;
			case 3:
				if (arr[curry][currx + 1] != 0)
				{
					direction = 1;
					curry++;
				}
				else
				{
					currx++;
				}
				break;
			default:
				break;
			}
		}

		cout << "#" << test_case << endl;
		print(N);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
