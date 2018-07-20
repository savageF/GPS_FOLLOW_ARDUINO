#define R 6371
#define TO_RAD (3.1415926536 / 180)
#include <math.h>

// getting distance 
double get_dist(double th1, double ph1, double th2, double ph2)
{
	double dx, dy, dz;
	ph1 -= ph2;
	ph1 *= TO_RAD, th1 *= TO_RAD, th2 *= TO_RAD;

	dz = sin(th1) - sin(th2);
	dx = cos(ph1) * cos(th1) - cos(th2);
	dy = sin(ph1) * cos(th1);
	
	return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}

//getting bearing
double get_bear(double th1, double ph1, double th2, double ph2) {

	double rlat1 = TO_RAD * th1;
	double rlat2 = TO_RAD * th2;
	double rlon1 = TO_RAD * ph1;
	double rlon2 = TO_RAD * ph2;
	
	double y = sin(rlon2-rlon1) * cos(rlat2);
	double x = cos(rlat1) * sin(rlat2) -
		sin(rlat1) * cos(rlat2) * cos(rlon2-rlon1);
	double brng = atan2(y, x) * (180/3.1415926536);

	return brng;

}
