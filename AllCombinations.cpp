#include <iostream>
#include <vector>
#include <fstream>
#include "AllCombinations.hpp"

using namespace std;
ofstream ofile("wynikiKombinacje.txt");

bool AllCombinations::inVector(vector<int>& searchVec, int val)
{
	return find(searchVec.begin(), searchVec.end(), val) != searchVec.end();
}

void AllCombinations::simplePrint(vector<int>& data)
{
	for (int item : data)
	{
		ofile << item - 1 << ' ';
	}
}

void AllCombinations::printIter(vector<vector<int>>& ansVec, int num)
{
	for (int i = 0; i < num; i++)
	{
		simplePrint(ansVec[i]);
		ofile << '\t';
	}
}

bool AllCombinations::printCombinations(vector<int>& data, int arraySize, int iter, vector<vector<int>>& ansVec, bool& was)
{
	if (iter == 0)
	{
		ofile << countInst << '\t';
		ansVec[iter] = data;
		simplePrint(data);
		ofile << '\t';
		return true;
	}
	else if (arraySize)
	{
		if (!was)
		{
			printIter(ansVec, iter);
		}
		ansVec[iter] = data;
		simplePrint(data);
		ofile << '\t';
		return true;
	}
	else
	{
		if (!was)
		{
			printIter(ansVec, iter);
		}
		ansVec[iter] = data;
		simplePrint(data);
		ofile << '\n';
		countInst++;
		clog << countInst << '\n';
		return false;
	}
}

void AllCombinations::combinationUtil(vector<int> arr, vector<int>& data, int start, int end, int index, int r, int smallestIndex, bool goPrint, vector<vector<int>>& ansVec, bool& was)
{
	if (index == r && goPrint)
	{
		bool resWas = printCombinations(data, arr.size(), (end + 1 - arr.size() - r) / r, ansVec, was);
		was = resWas;
		vector<int> addData;
		addData.resize(r);
		combinationUtil(arr, addData, 0, end, 0, r, 0, false, ansVec, was);
	}
	else
	{
		// && (!inVector(incl, data[0]) || !inVector(excl, arr[i - index]))
		for (int i = start; i - index < arr.size() && i <= end && end - i + 1 >= r - index && (start > 0 || i == smallestIndex); i++)
		{
			data[index % r] = arr[i - index];
			vector<int> temp = arr;
			temp.erase(temp.begin() + (i - index));
			combinationUtil(temp, data, i + 1, end, index + 1, r, smallestIndex, true, ansVec, was);
		}
	}
}

void AllCombinations::allCombination(vector<int>& arr, int n, int r)
{
	vector<int> data;
	data.resize(r);
	vector<vector<int>> ansVec;
	for (int i = 0; i < n / r; i++)
	{
		vector<int> prevVec;
		prevVec.resize(r);
		ansVec.push_back(prevVec);
	}
	bool initWas = true;
	combinationUtil(arr, data, 0, n - 1, 0, r, 0, true, ansVec, initWas);
}

vector<int> createVector(int number)
{
	vector<int> v1;
	for (int i = 1; i <= number; i++)
	{
		v1.push_back(i);
	}
	return v1;
}

void AllCombinations::combinations(int number, int groupSize)
{
	vector<int> arr = createVector(number);
	allCombination(arr, number, groupSize);
}

vector<vector<vector<int>>> AllCombinations::combinationsVector(int number, int groupSize, bool newGeneration)
{
	ifstream ist;
	if (newGeneration)
	{
		combinations(number, groupSize);
		ist.open("wynikiKombinacje.txt");
	}
	else
	{
		ist.open("wynikiZapisane.txt");
	}

	int groupNuber = number / groupSize;
	vector<vector<vector<int>>> vAll;

	int ID;
	int digit;
	while (ist >> ID)
	{
		vector<vector<int>> vLine;

		vector<int> vID;
		vID.push_back(ID);
		vLine.push_back(vID);

		for (int i = 0; i < groupNuber; i++)
		{
			vector<int> vGroup;
			for (int j = 0; j < groupSize; j++)
			{
				ist >> digit;
				vGroup.push_back(digit);
			}
			vLine.push_back(vGroup);
		}
		vAll.push_back(vLine);
	}

	ist.close();

	return vAll;
}