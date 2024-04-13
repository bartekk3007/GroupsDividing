#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <algorithm>

class GroupDistances
{
public:
	double groupSum(const vector<vector<double>>& vAll, const vector<int>& indices)
	{
		double gSum = 0;
		for (int i = 0; i < indices.size(); i++)
		{
			for (int j = i + 1; j < indices.size(); j++)
			{
				int index0 = indices[i];
				int index1 = indices[j];
				gSum += vAll[index0][index1];
			}
		}
		return gSum;
	}

	vector<string> abbreviations(const vector<string>& vAbbr, const vector<int>& indices)
	{
		vector<string> vStr;
		for (int index : indices)
		{
			vStr.push_back(vAbbr[index]);
		}
		return vStr;
	}

	vector<vector<variant<int, double, vector<int>, vector<string>>>> distances(const vector<vector<vector<int>>>& vComb,
		const vector<vector<double>>& vAll, const vector<string>& vAbbr)
	{
		vector<vector<variant<int, double, vector<int>, vector<string>>>> vSolution;
		
		for (int i = 0; i < vComb.size(); i++)
		{
			vector<variant<int, double, vector<int>, vector<string>>> vLine;
			double sum = 0;
			vector<double> vSum;

			vLine.push_back(i);
			for (int j = 1; j < vComb[0].size(); j++)
			{
				vector<int> vGroup;
				for (int k = 0; k < vComb[0][1].size(); k++)
				{
					vGroup.push_back(vComb[i][j][k]);
				}
				vLine.push_back(vGroup);
				vLine.push_back(abbreviations(vAbbr, vGroup));
				sum += groupSum(vAll, vGroup);
				vSum.push_back(groupSum(vAll, vGroup));
				vLine.push_back(groupSum(vAll, vGroup));
			}
			
			vLine.push_back(*max_element(vSum.begin(), vSum.end()));
			vLine.push_back(sum);
			vSolution.push_back(vLine);
		}

		return vSolution;
	}
};