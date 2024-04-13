#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class DistanceMatrix
{
public:
	double toRadian(double degree);
	double toDegree(double radian);
	double calculateLength(const vector<double>& vLan, const vector<double>& vLon, int index0, int index1);
	vector<vector<double>> matrix(const vector<string>& vAbbr, const vector<double>& vLatitude, const vector<double>& vLongitude);
};