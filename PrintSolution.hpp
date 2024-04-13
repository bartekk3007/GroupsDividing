#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <tuple>
#include <fstream>

using namespace std;

class PrintSolution
{
public:
	void print(const vector<vector<variant<int, double, vector<int>, vector<string>>>>& vSolution, string operation)
	{
		ofstream ost;
		if (operation == "sum")
		{
			ost.open("wynikiSuma.txt");
		}
		else if (operation == "max")
		{
			ost.open("wynikiMax.txt");
		}

		for (int i = 0; i < vSolution.size(); i++)
		{
			for (int j = 2; j < vSolution[0].size() - 2; j += 3)
			{
				for (string abbr : get<vector<string>>(vSolution[i][j]))
				{
					ost << abbr << ' ';
				}
				ost << '\n';
				ost << get<double>(vSolution[i][j + 1]);
				ost << '\n';
			}

			if (operation == "sum")
			{
				ost << get<double>(vSolution[i][vSolution[0].size() - 1]);
				ost << " " << "(" << get<double>(vSolution[i][vSolution[0].size() - 2]) << ")";
			}
			else if (operation == "max")
			{
				ost << get<double>(vSolution[i][vSolution[0].size() - 2]);
				ost << " " << "(" << get<double>(vSolution[i][vSolution[0].size() - 1]) << ")";
			}
			ost << '\n';
			ost << '\n';
		}
		ost.close();
	}
};