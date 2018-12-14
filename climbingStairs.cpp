#include <list>
#include <deque>
#include <iostream>
#include <memory>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

class Solution
{
public:
	int climbStairs(int n)
	{
		if (n<=1)
		{
			return 1;
		}

		int oneStep = 1;
		int twoStep = 1;
		int res = 0;

		for (int i=2;i<=n;i++)
		{
			res = oneStep + twoStep;
			twoStep = oneStep;
			oneStep = res;
		}
		return res;
	}
};

int main(int argc, char* args[])
{
	shared_ptr<Solution> pSolution = make_shared<Solution>();
	int res = pSolution->climbStairs(5);
	cout << "res:" << res << endl;
	return 0;
}