/*
다음 100X100의 2차원 배열이 주어질 때, 각 행의 합, 각 열의 합, 각 대각선의 합 중 최댓값을 구하는 프로그램을 작성하여라.

다음과 같은 5X5 배열에서 최댓값은 29이다.



[제약 사항]

총 10개의 테스트 케이스가 주어진다.

배열의 크기는 100X100으로 동일하다.

각 행의 합은 integer 범위를 넘어가지 않는다.

동일한 최댓값이 있을 경우, 하나의 값만 출력한다.
 
[입력]

각 테스트 케이스의 첫 줄에는 테스트 케이스 번호가 주어지고 그 다음 줄부터는 2차원 배열의 각 행 값이 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스의 답을 출력한다.
*/

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	
	int arr[100][100];
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int T;
		int Sol = 0;

		cin >> T;

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				int n;
				cin >> n;
				arr[i][j] = n;
			}
		}

		int maximum = 0;
		int degak1 = 0;
		int degak2 = 0;
		for (int i = 0; i < 100; i++)
		{
			int hang = 0;
			int yul = 0;
			for (int j = 0; j < 100; j++)
			{
				hang = hang + arr[i][j];
				yul = yul + arr[j][i];
				if (maximum < hang)
					maximum = hang;
				if (maximum < yul)
					maximum = yul;
				if (i == j)
				{
					degak1 = degak1 + arr[i][j];
				}
				if (j - 99 == i)
				{
					degak2 = degak2 + arr[i][j];
				}
			}
		}


		cout << "#" << test_case << " " << maximum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
