#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include "DistanceMatrix.hpp"
#include "AllCombinations.hpp"
#include "GroupDistances.hpp"
#include "SortSolution.hpp"
#include "PrintSolution.hpp"

using namespace std;

int main()
{
	int number = 18; 
	int groupSize = 6;
	bool newGeneration = false;

	vector<string> vAbbr = {"POG", "JAG", "LPO", "WAR", "LEG", "WID", "£KS", "RAD", "ZLU", "ŒL¥", "KOR", "RAK", "PIA", "GZA", "RCH", "SMI", "CRA", "PNI"};
	vector<double> vLatitude = {53.44, 53.11, 52.40, 52.23, 52.22, 51.77, 51.76, 51.41, 51.41, 51.14, 50.86, 50.78, 50.31, 50.30, 50.29, 50.30, 50.06, 50.03};
	vector<double> vLongitude = {14.52, 23.15, 16.86, 16.38, 21.04, 19.51, 19.43, 21.17, 16.20, 16.94, 20.63, 19.16, 18.70, 18.77, 18.97, 21.44, 19.92, 20.22};

	AllCombinations c1;
	vector<vector<vector<int>>> vComb = c1.combinationsVector(number, groupSize, newGeneration);

	DistanceMatrix d1;
	vector<vector<double>> vAll = d1.matrix(vAbbr, vLatitude, vLongitude);

	GroupDistances g1;
	vector<vector<variant<int, double, vector<int>, vector<string>>>> vSolutionSum = g1.distances(vComb, vAll, vAbbr);
	vector<vector<variant<int, double, vector<int>, vector<string>>>> vSolutionMax = g1.distances(vComb, vAll, vAbbr);

	SortSolution s1;
	s1.sorted(vSolutionSum, "sum");
	s1.sorted(vSolutionMax, "max");

	PrintSolution p1;
	p1.print(vSolutionSum, "sum");
	p1.print(vSolutionMax, "max");

	return 0;
}