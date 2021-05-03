#include "PointContainer.h"

PointContainer::PointContainer()
{
}

PointContainer::~PointContainer()
{
}

void PointContainer::read_config_file(string config_file)
{
	fstream file;
	file.open(config_file.c_str());
	if(!file.good())
	{
		puts("Config file not found");
		exit(-1);
	}

	string point_fileName;
	getline(file, point_fileName);
	std::size_t pos = point_fileName.find(":");
	point_fileName = point_fileName.substr(pos + 1);
	string line;

	getline(file, line);
	pos = line.find(":");
	min_k = atoi(line.substr(pos + 1).c_str());

	getline(file, line);
	pos = line.find(":");
	max_k = atoi(line.substr(pos + 1).c_str());
	// read initially place the centriods when performing k-means clustering	
	
	for (int i = min_k ; i <= max_k; i++)
	{
		vector<int> c;
		getline(file, line);
		pos = line.find(":");
		line = line.substr(pos + 1);
		stringstream stream(line);
		for (int j = 0 ; j < i; j++)
		{
			int n;
			stream >> n;
			c.push_back(n);
		}
			centroids.push_back(c);
	}

	read_points(point_fileName);
}

void PointContainer::read_points(string file_name)
{
	fstream file;
	file.open(file_name.c_str());
	if (!file.good())
	{
		puts("points file not found");
		exit(-1);
	}
	Point point;
	while (file >> point.id >> point.x >> point.y)
	{
		points.push_back(point);
	}
}
