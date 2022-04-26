
/*

소요 시간 : 3:39


풀이 방법:

이전 문제와 동일한 코드에서 명령어만 하나 추가되었다.

std::vector::erase 로 구현




0 ~ 999999 사이의 수를 나열하여 만든 암호문이 있다. 암호문을 급히 수정해야 할 일이 발생했는데,

이 암호문은 특수 제작된 처리기로만 수정이 가능하다. 이 처리기는 다음과 같이 2개의 기능을 제공한다.

1. I(삽입) x, y, s : 앞에서부터 x의 위치 바로 다음에 y개의 숫자를 삽입한다. s는 덧붙일 숫자들이다.[ ex) I 3 2 123152 487651 ]

2. D(삭제) x, y : 앞에서부터 x의 위치 바로 다음부터 y개의 숫자를 삭제한다.[ ex) D 4 4 ]

위의 규칙에 맞게 작성된 명령어를 나열하여 만든 문자열이 주어졌을 때, 암호문을 수정하고, 수정된 결과의 처음 10개 숫자를 출력하는 프로그램을 작성하여라.

[입력]

첫 번째 줄 : 원본 암호문의 길이 N ( 100 ≤ N ≤ 200 의 정수)

두 번째 줄 : 원본 암호문

세 번째 줄 : 명령어의 개수 ( 10 ≤ N ≤ 20 의 정수)

네 번째 줄 : 명령어

위와 같은 네 줄이 한 개의 테스트 케이스이며, 총 10개의 테스트 케이스가 주어진다.

[출력]

#기호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 수정된 암호문의 처음 10개 항을 출력한다.


*/
#include<iostream>
#include<vector>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int N;
		cin >> N;
		std::vector<int> plainv;
		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			plainv.push_back(num);
		}

		int commandN;
		cin >> commandN;

		for (int i = 0; i < commandN; i++)
		{
			char I;
			cin >> I;

			int x, y;
			cin >> x >> y;

			if (I == 'I')
			{
				for (int ii = 0; ii < y; ii++)
				{
					int num;
					cin >> num;
					plainv.insert(plainv.begin() + x + ii, num);
				}
			}
			else if (I == 'D')
			{
				plainv.erase(plainv.begin() + x, plainv.begin() + x + y);
			}
		}

		char I;

		int Sol = -1;

		cout << "#" << test_case << " ";
		for (int i = 0; i < 10; i++)
		{
			cout << plainv[i] << " ";
		}
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
