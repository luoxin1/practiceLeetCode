#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int res = 0;
		int i = 0;
		int j = height.size() - 1;
		while (i < j)
		{
			res = max(res, min(height[i], height[j]) * (j - i));
			height[i] < height[j] ? ++i : --j;
		}
		return res;
	}
};

int main(int argc, char* argv[])
{
	std::vector<int> v = { 1,8,6,2,5,4,8,3,7 };
	std::shared_ptr<Solution> pSolution(new Solution());
	std::cout<<pSolution->maxArea(v)<<std::endl;
	return 0;
}
