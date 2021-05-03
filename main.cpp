#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include "PointContainer.h"
#include "kmeans.h"
using namespace std;

int main(int argc, char* argv[])
{
 string file_name;
 PointContainer point_container;
 cout <<"Please enter the name of the configuration file:";
 cin >> file_name;
 point_container.read_config_file(file_name);
 cout<< "The total number of k values to be tested is " << point_container.max_k - point_container.min_k + 1 << endl; 
 cout<< "The total number of points in this file is " << point_container.points.size() << endl;
 
Kmeans k;
k.getVector(point_container.points);

for(int i = point_container.min_k; i <= point_container.max_k; ++i) {
	k.kmeans(i,point_container.centroids[i-2]);
}


 return 0;
}


