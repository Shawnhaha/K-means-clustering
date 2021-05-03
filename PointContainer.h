#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include "Point.h"
using namespace std;
#ifndef _POINTCONTAINER_
#define _POINTCONTAINER_

class PointContainer
{
	public:
		vector<Point> points;
		//map to save the centriods for each k from min to max
		int min_k, max_k;
		vector<vector<int>> centroids;
		PointContainer();
		~PointContainer();
		void read_config_file(string config_file);
		void read_points(string file_name);
};

#endif
