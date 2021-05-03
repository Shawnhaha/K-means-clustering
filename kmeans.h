#ifndef KMEANS_H
#define KMEANS_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include"PointContainer.h"
using namespace std;

class Kmeans {
	public:
		struct P {
			double x,y;
			int id;
		};
		struct Mean {
			double x,y;
		};
		
		int kNum;
		vector<int> firstid; // the beginnig k-means' ids
		vector<int> cPointid; // the closet points' ids
		vector<P> points;
		vector<Mean> means;
		vector<Mean> newmeans;
		vector<vector<P>> clusters;

		void getVector(vector<Point> p);
		void kmeans(int,vector<int>);

};

#endif
