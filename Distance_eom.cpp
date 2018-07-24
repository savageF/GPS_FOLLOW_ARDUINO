#include <math.h>
#include "Distance_eom.h"


//get distance between A and B
//use Kilometer

double get_dist(double la1, double lo1, double la2, double lo2)
{
	double dx, dy, dz;
	lo1 -= lo2;
	lo1 *= TO_RAD, la1 *= TO_RAD, la2 *= TO_RAD;

	dz = sin(la1) - sin(la2);
	dx = cos(lo1) * cos(la1) - cos(la2);
	dy = sin(lo1) * cos(la1);
	return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}

//get Angle between A and B
//called bearing
//use Degree

double get_bear(double la1, double lo1, double la2, double lo2) {

	double rlat1 = TO_RAD * la1;
	double rlat2 = TO_RAD * la2;
	double rlon1 = TO_RAD * lo1;
	double rlon2 = TO_RAD * lo2;

	double y = sin(rlon2 - rlon1) * cos(rlat2);
	double x = cos(rlat1) * sin(rlat2) -
		sin(rlat1) * cos(rlat2) * cos(rlon2 - rlon1);
	double brng = atan2(y, x) * (180 / 3.1415926536);

	return brng+360; // Clockwise if u want to change this -> 360 - brng 

}
