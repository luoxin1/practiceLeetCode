#include <vector>
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
	int maxCoins(vector<int>& nums)
	{
		int n = nums.size();
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);
		vector<vector<int>> dp(n+2,vector<int>(n+2,0));
		for (int k=1;k<=n;k++)
		{
			for (int i=1;i<=n-k+1;i++)
			{
				int j = i + k - 1;
				for (int x=i;x<=j;x++)
				{
					int temp = dp[i][x - 1] + nums[i - 1] * nums[x] * nums[j + 1] + dp[x + 1][j];
					if (dp[i][j]<temp)
					{
						dp[i][j] = temp;
					}
				}
			}
		}
		return dp[1][n];
	}
};

int main()
{
	vector<int> v = { 3, 1, 5, 8 };
	shared_ptr<Solution> pSolution = make_shared<Solution>();
	int ret = pSolution->maxCoins(v);
	cout << ret << endl;
	return 0;
}