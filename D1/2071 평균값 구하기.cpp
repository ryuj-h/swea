
#include <iostream>
#include <cmath>
using namespace std;

/*

10개의 수를 입력 받아, 평균값을 출력하는 프로그램을 작성하라.

(소수점 첫째 자리에서 반올림한 정수를 출력한다.)


[제약 사항]

각 수는 0 이상 10000 이하의 정수이다.


[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 10개의 수가 주어진다.


[출력]

출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.

(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

*/

//int arr[11];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int Sol = 0;
		for (int i = 0; i < 10; i++)
		{
			int num;
			cin >> num;
			Sol += num;
			//arr[i] = num;
		}
		Sol = floor(Sol / 10.f + 0.5);
		

		cout << "#" << test_case << " " << Sol << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
