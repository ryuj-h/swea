/*
소요시간 : 12:35

그냥 노가다문제


*/
#include<iostream>
#include<string>
#include <cstring>

using namespace std;

int map[10];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(map, 0, sizeof(map));
		
		std::string TT;
		cin >> TT;

		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			std::string num;
			cin >> num;
			if (num.compare("ZRO") == 0)
			{
				map[0]++;
			}
			else if (num.compare("ONE") == 0)
			{
				map[1]++;
			}
			else if (num.compare("TWO") == 0)
			{
				map[2]++;
			}
			else if (num.compare("THR") == 0)
			{
				map[3]++;
			}
			else if (num.compare("FOR") == 0)
			{
				map[4]++;
			}
			else if (num.compare("FIV") == 0)
			{
				map[5]++;
			}
			else if (num.compare("SIX") == 0)
			{
				map[6]++;
			}
			else if (num.compare("SVN") == 0)
			{
				map[7]++;
			}
			else if (num.compare("EGT") == 0)
			{
				map[8]++;
			}
			else if (num.compare("NIN") == 0)
			{
				map[9]++;
			}
		}
		cout << TT << endl;
		for(int i = 0; i < 10 ;i++)
		{
			std::string nums;
			switch (i)
			{
			case 0:
				nums = "ZRO";
				break;
			case 1:
				nums = "ONE";
				break;
			case 2:
				nums = "TWO";
				break;
			case 3:
				nums = "THR";
				break;
			case 4:
				nums = "FOR";
				break;
			case 5:
				nums = "FIV";
				break;
			case 6:
				nums = "SIX";
				break;
			case 7:
				nums = "SVN";
				break;
			case 8:
				nums = "EGT";
				break;
			case 9:
				nums = "NIN";
				break;
			default:
				break;
			}

			for (int j = 0; j < map[i]; j++)
			{
				cout << nums << " ";
			}
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
