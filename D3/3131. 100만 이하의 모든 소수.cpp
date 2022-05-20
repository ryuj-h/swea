/*


1 이상 100만(106) 이하의 모든 소수를 구하는 프로그램을 작성하시오.

참고로, 10 이하의 소수는 2, 3, 5, 7 이다.

[입력]

이 문제의 입력은 없다.

[출력]

1 이상 100만 이하의 소수를 공백을 사이에 두고 한 줄에 모두 출력한다.

1 이상 100만(106) 이하의 모든 소수를 구하는 프로그램을 작성하시오.

참고로, 10 이하의 소수는 2, 3, 5, 7 이다.

[입력]

이 문제의 입력은 없다.

[출력]

1 이상 100만 이하의 소수를 공백을 사이에 두고 한 줄에 모두 출력한다.

에라토스테네스체 사용시 0.04초 걸림

그냥 하니까 0.77초


*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool issosu(uint64_t num)
{
	for (uint64_t ii = 2; ii * ii <= num; ii++)
	{
		if (num % ii == 0)
			return false;
	}
	return true;
}

void Eratos(int n)
{
	if (n <= 1) return;

	bool* PrimeArray = new bool[n + 1];

	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;

	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
	}
	for (uint64_t i = 2; i <= n; i++)
	{
		if(PrimeArray[i])
			printf("%d ", i);
	}

}

int main(int argc, char** argv)
{
	Eratos(1000000);
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
