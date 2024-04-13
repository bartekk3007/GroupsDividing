#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class AllCombinations
{
public:
	int countInst = 0;
	vector<int> incl = {};
	vector<int> excl = {};

	bool inVector(vector<int>& searchVec, int val);
	void simplePrint(vector<int>& data);
	void printIter(vector<vector<int>>& ansVec, int num);
	bool printCombinations(vector<int>& data, int arraySize, int iter, vector<vector<int>>& ansVec, bool& was);
	void combinationUtil(vector<int> arr, vector<int>& data, int start, int end, int index, int r, int smallestIndex, bool goPrint, vector<vector<int>>& ansVec, bool& was);
	void allCombination(vector<int>& arr, int n, int r);
	void combinations(int number, int groupSize);
	vector<vector<vector<int>>> combinationsVector(int number, int groupSize, bool newGeneration);
};
