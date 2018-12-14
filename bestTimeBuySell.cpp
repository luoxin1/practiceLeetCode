#include <list>
#include <iostream>
#include <memory>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

class Solution
{
public:
	Solution(int age, string name)
	{
		cout << "age:" << age << " name:" << name<<endl;
	}

	int maxProfit(vector<int> prices)
	{
		int min = INT_MAX;
		int res = 0;
		for (int i=0;i< prices.size();i++)
		{
			if (prices[i]<min)
			{
				min = prices[i];
			}
			if (prices[i]-min>res)
			{
				res = prices[i] - min;
			}
		}
		return res;
	}
};


int main()
{
	//int aa[] = { 7, 1, 5, 3, 6, 4 };
	//int aa[] = { 7, 6, 4, 3, 1 };
	vector<int> aa= { 7, 6, 4, 3, 1 };
	shared_ptr<Solution> pSolution = make_shared<Solution>(12,"luoxin"); 
	//int res = pSolution->maxProfit(aa,sizeof(aa)/sizeof(aa[0]));
	int res = pSolution->maxProfit(aa);
	cout << res << endl;
	return 0;
}