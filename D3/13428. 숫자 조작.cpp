
#include<iostream>
#include <string>

using namespace std;

int mmin;
int mmax;
int strs;
/*

9자리 이하의 음이 아닌 정수 N이 있다. 당신은 이 수에서 한 쌍의 숫자를 골라 그 위치를 바꾸는 일을 최대 한 번 하여(안 하거나, 한 번만 하여) 새로운 수 M을 만들 수 있다. 단, 바꾼 결과 M의 맨 앞에 ‘0’이 나타나면 안 된다.

M의 최솟값과 최댓값을 구하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스는 하나의 줄로 이루어진다. 각 줄에는 0 이상 999,999,999 이하의 정수 N이 주어진다. N ≠ 0 이라면 주어지는 수가 0으로 시작하지 않는다.


[출력]
각 테스트 케이스마다, M의 최솟값과 최댓값을 공백 하나를 사이로 두고 출력한다.



*/


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string numstr;
		cin >> numstr;
		strs = numstr.size();
		mmin = mmax = stoi(numstr);


		for (int i = 0; i < strs - 1; i++)
		{
			for (int j = i + 1; j < strs; j++)
			{
				string backup = numstr;
				auto tmp = backup[i];
				backup[i] = backup[j];
				backup[j] = tmp;

				if (backup[0] == '0')
					continue;
				int newnum = stoi(backup);
				mmin = min(mmin, newnum);
				mmax = max(mmax, newnum);
			}
		}
		cout << "#" << test_case << " " << mmin << " "<< mmax << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
