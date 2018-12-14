#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> arr,int size)
	{
		sort(v.begin(), v.end());
		cout << size << endl;
		vector<vector<int>> retDatas;
		for (int i=0;i< size-3;i++)
		{
			if (arr[i]<=0)
			{
				if (i>=1 && arr[i]==arr[i-1])
				{
					continue;
				}
				int j = i + 1;
				int k = size - 1;
				while (j<k)
				{
					if (arr[i]+arr[j]+arr[k]==0)
					{
						vector<int> one;
						one.push_back(arr[i]);
						one.push_back(arr[j]);
						one.push_back(arr[k]);
						retDatas.push_back(one);

						j++;
						k--;
						while (j<k && arr[j]==arr[j-1])
						{
							j++;
						}
						while (j<k && arr[k] == arr[k+1])
						{
							k--;
						}
					}
					else
					{
						bool flag = true;
						while (flag)
						{
							while (j<k && arr[j]+arr[k]>(-1)*arr[i])
							{
								k--;
							}
							while (j<k && arr[j]+arr[k]<(-1)*arr[i])
							{
								j++;
							}
							if (j>=k || arr[j]+arr[k]==(-1)*arr[i])
							{

								flag = false;
							}
						}
					}
				}
			}

		}
		return retDatas;
	}
};


int main()
{
	//int S[] = { -4 ,-1,-1, 0, 1, 2};
	vector<int> v = { -1, 0, 1, 2, -1, -4 };
	/*for (int n:v)
	{
		cout << n << ",";
	}
	cout << endl;*/

	shared_ptr<Solution> pSolution(new Solution());
	vector<vector<int>> datas = pSolution->threeSum(v,v.size());
	cout << "datas size:" << datas.size() << endl;
	for (vector<int> vecs : datas)
	{
		for (int vec : vecs)
		{
			cout << vec << ",";
		}
		cout << endl;
	}
	return 0;
}