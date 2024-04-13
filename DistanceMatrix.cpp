#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include "DistanceMatrix.hpp"

using namespace std;

double DistanceMatrix::toRadian(double degree)
{
	return degree * M_PI / 180.0;
}

double DistanceMatrix::toDegree(double radian)
{
	return radian * (180.0 / M_PI);
}

double DistanceMatrix::calculateLength(const vector<double>& vLan, const vector<double>& vLon, int index0, int index1)
{
	double c1 = cos(toRadian(90 - vLan[index0]));
	double c2 = cos(toRadian(90 - vLan[index1]));
	double s1 = sin(toRadian(90 - vLan[index0]));
	double s2 = sin(toRadian(90 - vLan[index1]));
	double c3 = cos(toRadian(vLon[index0] - vLon[index1]));

	double sum = c1 * c2 + s1 * s2 * c3;
	double radian = acos(sum);
	double convDegree = toDegree(radian);
	double length = convDegree * 111.1;
	return length;
}

vector<vector<double>> DistanceMatrix::matrix(const vector<string>& vAbbr, const vector<double>& vLatitude, const vector<double>& vLongitude)
{
	ofstream ost("wynikiDystans.txt");

	for (const auto& elem : vAbbr)
	{
		ost << elem << '\t';
	}
	ost << '\n';

	vector<vector<double>> vAll;
	for (int i = 0; i < 18; i++)
	{
		vector<double> vTeam;
		for (int j = 0; j < 18; j++)
		{
			vTeam.push_back(calculateLength(vLatitude, vLongitude, i, j));
			ost << calculateLength(vLatitude, vLongitude, i, j) << '\t';
		}
		vAll.push_back(vTeam);
		ost << '\n';
	}

	return vAll;
}