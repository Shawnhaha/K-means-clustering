#include "kmeans.h"
using namespace std;

void Kmeans::getVector(vector<Point> p){
	points.clear();
	for (int i = 0; i < p.size(); ++i) {
		P pp;
		pp.x = p[i].x;
		pp.y = p[i].y;
		pp.id = p[i].id;
		points.push_back(pp);
	}
}


void Kmeans::kmeans(int Knum, vector<int> Firstid) {
	kNum = Knum;

	firstid.clear();
        firstid = Firstid;

	//assign the beginning k-means
	means.clear();
	for (int i = 0; i < kNum; ++i) {
		Mean m;
		for (int i = 0; i < points.size(); ++i) {
			for (int j = 0; j < kNum; ++j){
				if (points[i].id == firstid[j]) {
					m.x = points[i].x;
					m.y = points[i].y;
					means.push_back(m);
				}
			}
		}
	}

	bool kchanged = true;

	while(kchanged == true) {
		kchanged = false;
		
		//Division
		clusters.clear();

		clusters.resize(kNum);
		
		for (int i = 0; i < points.size(); ++i) {
			int a;
			vector<double> d;
			d.clear();

			for (int j = 0; j < kNum; ++j) {
				d.push_back(sqrt(pow(points[i].x - means[j].x, 2) + pow(points[i].y - means[j].y, 2)));
				if (j == 0) {
					a = j;
				}
				else if (d[j] < d[a]) {
					a = j;
				}
			}
			clusters[a].push_back(points[i]);
		}

		//New centroids
		
		newmeans.clear();
		for (int i = 0; i < clusters.size(); ++i) {
			Mean nm;
			double xsum = 0;
	                double ysum = 0;

			for (int j = 0 ; j < clusters[i].size(); ++j) {
				xsum += clusters[i][j].x;
				ysum += clusters[i][j].y;
			}
		
			nm.x = xsum/clusters[i].size();
			nm.y = ysum/clusters[i].size();
			newmeans.push_back(nm);
		}
		

		for (int i = 0; i < clusters.size(); ++i) {
			if (newmeans[i].x != means[i].x || newmeans[i].y != means[i].y) {
				kchanged = true;
				break;
			}
		}
		
		for (int i = 0; i < clusters.size(); ++i) {
			means[i].x = newmeans[i].x;
			means[i].y = newmeans[i].y;
		}

	}


//The closet points
	cPointid.clear();
	for (int i = 0; i < clusters.size(); ++i) {
		int a;
		vector<double> d;
		d.clear();

		for (int j = 0; j < clusters[i].size(); ++j) {
			d.push_back(sqrt(pow(clusters[i][j].x-means[i].x, 2) + pow(clusters[i][j].y-means[i].y, 2)));
			if (j == 0) {
				a = j;
			}
			else if (d[j] < d[a]) {
				a = j;
			}
		}
		cPointid.push_back(clusters[i][a].id);
	}


//print
	cout << "For k-means clustering:" << endl;
	cout << "For a k value of " << kNum << ", here is the information regarding its clusters:" << endl;
	
	for (int i = 0; i < kNum; ++i) {
		cout << "Cluster " << i+1 << " contains " << clusters[i].size() << " points and the point " << cPointid[i] << " is closest to its centroid." << endl;
	}
	clusters.clear();
}

