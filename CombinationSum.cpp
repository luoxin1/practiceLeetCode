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
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		combinationSumDFS(candidates, target, 0, {},res);
		return res;
	}

private:
	void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int> out, vector<vector<int>>& res)
	{
		if (target < 0)
		{
			return;
		}
		else if (target == 0)
		{
			res.push_back(out);
			return;
		}
		for (size_t i=start;i<candidates.size();++i)
		{
			out.push_back(candidates[i]);
			combinationSumDFS(candidates, target - candidates[i], i, out, res);
			out.pop_back();
		}
	}
};

int main()
{
	vector<int> v = { 2,3,6,7 };
	shared_ptr<Solution> pSolution(new Solution());
	vector<vector<int>> ret =pSolution->combinationSum(v,7);
	for (vector<int> k:ret)
	{
		for (int m:k)
		{
			cout << m << ",";
		}
		cout << endl;
	}
	return 0;
}