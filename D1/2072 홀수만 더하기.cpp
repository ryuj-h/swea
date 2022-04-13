
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int answer = 0;
		for (int i = 0; i < 10; i++)
		{
			int number;
			cin >> number;
			if (number % 2)
			{
				answer += number;
			}
		}
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
