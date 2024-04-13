#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <algorithm> 

using namespace std;

class SortSolution
{
public:
	struct functorSum
	{
		bool operator() (vector<variant<int, double, vector<int>, vector<string>>> a, 
			vector<variant<int, double, vector<int>, vector<string>>> b)
		{
			return (a[a.size() - 1] < b[b.size() - 1]);
		}
	};

	struct functorMax
	{
		bool operator() (vector<variant<int, double, vector<int>, vector<string>>> a,
			vector<variant<int, double, vector<int>, vector<string>>> b)
		{
			if (a[a.size() - 2] == b[b.size() - 2])
			{
				return (a[a.size() - 1] < b[b.size() - 1]);
			}
			else
			{
				return (a[a.size() - 2] < b[b.size() - 2]);
			}
		}
	};

	void sorted(vector<vector<variant<int, double, vector<int>, vector<string>>>>& vSolution, string operation)
	{
		if (operation == "sum")
		{
			functorSum sumSort;
			sort(vSolution.begin(), vSolution.end(), sumSort);
		}
		else if (operation == "max")
		{
			functorMax maxSort;
			sort(vSolution.begin(), vSolution.end(), maxSort);
		}
	}
};