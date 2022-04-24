/*
소요시간 1:01:22

테이블 위에 자성체들이 놓여 있다.

자성체들은 성질에 따라 색이 부여되는데, 푸른 자성체의 경우 N극에 이끌리는 성질을 가지고 있고, 붉은 자성체의 경우 S극에 이끌리는 성질이 있다.

아래와 같은 테이블에서 일정 간격을 두고 강한 자기장을 걸었을 때, 시간이 흐른 뒤에 자성체들이 서로 충돌하여 테이블 위에 남아있는 교착 상태의 개수를 구하라.

아래는 자성체들이 놓여 있는 테이블을 위에서 바라본 모습이다.
 


 
A로 표시된 붉은 자성체의 경우 S극에 이끌리면서 테이블 아래로 떨어지게 된다.

B로 표시된 푸른 자성체의 경우 N극에 이끌리면서 테이블 아래로 떨어지게 된다.

나머지 자성체들은 서로 충돌하며, 교착 상태에 빠져 움직이지 않게 된다.

D로 표시된 자성체들에서 알 수 있듯 한 쪽 방향으로 움직이는 자성체의 개수가 많더라도 반대 방향으로 움직이는 자성체가 하나라도 있으면 교착 상태에 빠져 움직이지 않는다.

D로 표시된 자성체들과 같이 셋 이상의 자성체들이 서로 충돌하여 붙어 있을 경우에도 하나의 교착 상태로 본다.

C와 D는 좌우로 인접하여 있으나 각각 다른 교착 상태로 판단하여 2개의 교착 상태로 본다.

E의 경우와 같이 한 줄에 두 개 이상의 교착 상태가 발생할 수도 있다.

F의 경우 각각 다른 교착상태로 판단하여 2개의 교착상태로 본다.

위의 예시의 경우 테이블 위에 남아있는 교착상태는 7개이므로 7를 반환한다.


[제약 사항]

자성체는 테이블 앞뒤 쪽에 있는 N극 또는 S극에만 반응하며 자성체끼리는 전혀 반응하지 않는다.

테이블의 크기는 100x100으로 주어진다. (예시에서는 설명을 위해 7x7로 주어졌음에 유의)

[입력]

각 테스트 케이스의 첫 번째 줄에는 정사각형 테이블의 한 변의 길이가 주어진다. 그리고 바로 다음 줄에 테스트 케이스가 주어진다.

총 10개의 테스트 케이스가 주어진다.

1은 N극 성질을 가지는 자성체를 2는 S극 성질을 가지는 자성체를 의미하며 테이블의 윗 부분에 N극이 아랫 부분에 S극이 위치한다고 가정한다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 교착 상태의 개수를 출력한다.

*/
#include<iostream>

using namespace std;


int arr[100][100];

void rotate()
{
	static char tmparr[100][100];
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			tmparr[i][j] = arr[100 - 1 - j][i];

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			arr[i][j] = tmparr[i][j];
}

int line(int arr[100])
{
	bool find = false;
	//1 N 2 S
	int i = 0;
	int last = 1;
	int changed = 0;
	while (i < 100 && arr[i] != 1)
		i++;
	for (; i < 100; i++)
	{
		if (arr[i] != last && arr[i] != 0)
		{
			changed++;
			last = arr[i];
		}
	}
	if (changed > 0)
	{
		changed++;

		if (last == 1)
			changed--;

		changed = changed / 2;
	}

	return changed;
}

/*
void rotate()
{
	static int tmparr[100][100];
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			tmparr[i][j] = arr[100 - 1 - j][i];

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			arr[i][j] = tmparr[i][j];
}
*/

int main(int argc, char** argv)
{
	int test_case;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int T;
		cin >> T;

		int Sol = 0;


		for (int y = 0; y < 100; y++)
			for (int x = 0; x < 100; x++)
				cin >> arr[y][x];

		rotate();
		rotate();
		rotate();

		for (int i = 0; i < 100; i++)
		{
			int s = line(arr[i]);
			Sol = Sol + s;
		}

		cout << "#" << test_case << " " << Sol << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
