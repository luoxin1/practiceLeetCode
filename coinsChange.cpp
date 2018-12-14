#include <vector>
#include <deque>
#include <iostream>
#include <memory>
#include <algorithm>
#include <limits.h>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int coinsChange(vector<int>& coins, int amount)
	{
		unordered_map<int, int> memo;
		memo[0] = 0;
		return coinsChangeDFS(coins, amount, memo);
	}

private:
	int coinsChangeDFS(vector<int>& coins, int target, unordered_map<int, int>& memo)
	{
		if (target<0)
		{
			return -1;
		}
		if (memo.count(target))
		{
			return memo[target];
		}

		int cur = INT_MAX;
		for (int i=0;i<coins.size();i++)
		{
			int tmp = coinsChangeDFS(coins, target - coins[i], memo);
			if (tmp>=0)
			{
				cur = min(cur, tmp + 1);
			}
		}
		return memo[target] = (cur == INT_MAX )? -1 : cur;
	}
};


int main(int args, char* argv[])
{
	vector<int> coins = { 1,2,5 };
	shared_ptr<Solution> pSolution = make_shared<Solution>();
	int res = pSolution->coinsChange(coins,11);
	cout << "res:" << res<<endl;
	return 0;
}