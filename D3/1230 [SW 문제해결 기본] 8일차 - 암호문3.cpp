/*
소요시간 : 04:20

똑같은 문제

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


			if (I == 'I')
			{
				int x, y;
				cin >> x >> y;
				for (int ii = 0; ii < y; ii++)
				{
					int num;
					cin >> num;
					plainv.insert(plainv.begin() + x + ii, num);
				}
			}
			else if (I == 'D')
			{
				int x, y;
				cin >> x >> y;
				plainv.erase(plainv.begin() + x, plainv.begin() + x + y);
			}
			else if (I == 'A')
			{
				int y;
				cin >> y;
				for (int ii = 0; ii < y; ii++)
				{
					int num;
					cin >> num;
					plainv.insert(plainv.end(), num);
				}
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
