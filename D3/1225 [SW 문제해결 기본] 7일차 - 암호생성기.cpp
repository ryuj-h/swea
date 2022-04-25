/*
걸린 시간 : 21:53

1. 이런식으로 푸는걸 원하는게 아닌것 같은데

2. 통과는 됐음



*/
#include<iostream>
#include <vector>

using namespace std;

std::vector<int> vec;

bool sol()
{
	for (int i = 1; i < 6; i++)
	{
		int num = *vec.begin();
		//cout << num << endl;
		vec.erase(vec.begin());
		num = num - i;
		if (num <= 0)
		{
			num = 0;
			vec.push_back(num);
			return true;
		}
		vec.push_back(num);
	}
	return false;
}

void print(int test_case)
{
	cout << "#" << test_case << " ";
	for (int i = 0; i < 8; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		vec.clear();
		cin >> T;
		int Sol = -1;
		for (int i = 0; i < 8; i++)
		{
			int n;
			cin >> n;
			vec.push_back(n);
			//arr[i] = n;
		}
		while (true)
		{
			if (sol())
				break;
		}
		print(test_case);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
