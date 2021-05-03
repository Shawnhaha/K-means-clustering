#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#ifndef _POINT_
#define _POINT_
class Point
{
	public:
		double x, y;
		int id;
		int cluster_id;
		// compare operator for sorting
		bool operator<(const Point & other ) const;
		// copy constructors
		Point & operator = ( const Point & other);
		// copy constructors
		Point ( const Point & obj);
		// constructor with values
		Point ( int, double, double);
		// default constructor
		Point();
		~Point();

		void set_cluster(int cluster);
		int get_cluster();
};
#endif
			
