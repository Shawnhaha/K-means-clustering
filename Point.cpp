#include "Point.h"

bool Point::operator<(const Point & other) const
{
	return id < other.id;
}

Point & Point::operator=(const Point & other)
{
	x = other.x;
	id = other.id;
	y = other.y;
	cluster_id = other.cluster_id;
	return * this;
}

Point::Point(const Point & obj)
{
	x = obj.x;
	y = obj.y;
	cluster_id = obj.cluster_id;
	id = obj.id;
}

Point::Point(int id, double x, double y)
{
	this-> id = id;
	this-> x = x;
	this-> y = y;
	cluster_id = 0;
}

Point::Point()
{
	id = x = y = cluster_id = 0;
}

Point::~Point()
	= default;

void Point::set_cluster(int cluster)
{
	cluster_id = cluster;
}

int Point::get_cluster()
{
	return cluster_id;
}
