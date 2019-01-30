#include<iostream>
#include <vector>
#include <queue>
#include<memory>
using namespace std;

class Solution
{
public:
	bool canFinish(int numCourse, vector<vector<int>>& prerequisites)
	{
		vector<vector<int>> graph(numCourse, vector<int>(0));
		vector<int> in(numCourse, 0);
		for (auto a:prerequisites)
		{
			graph[a[1]].push_back(a[0]);
			++in[a[0]];
		}
		queue<int> q;
		for (int i=0;i<numCourse;++i)
		{
			if (in[i] == 0)
			{
				q.push(i);
			}
		}

		while (!q.empty())
		{
			int t = q.front();
			q.pop();
			for (auto a: graph[t])
			{
				--in[a];
				if (in[a]==0)
				{
					q.push(a);
				}
			}
		}
		for (int i=0;i<numCourse;++i)
		{
			if (in[i]!=0)
			{
				return false;
			}
		}
		return true;
	}
};


int main(int argc, char** argv)
{
	vector<int> v1{1,0};
	vector<vector<int>> v2;
	v2.push_back(v1);
	shared_ptr<Solution> pSolution = make_shared<Solution>();
	cout<<pSolution->canFinish(2,v2)<<endl;
	return 0;
}