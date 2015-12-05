//Author : Xingyu Li
//Date update : 12/01/2015
#include "Ship.hh"


void Ship::Getnumber()const {
	cout << number << '\n';
}
void Ship::Setnumber(const char* a ) {
	strncpy(number,a,len-1);
	number[len-1]='\0';
}
void Ship::Getshape() const{
	cout << shape << '\n';
}
void Ship::Setshape(const char* a) {
	strncpy(shape,a,len-1);
	shape[len-1]='\0';
}
}
double Ship::GetRadius(double L, double K, double M ){
	return sqrt(L*L+(L/theta+(K-M))*(L/theta+(K-M)));
}
void Ship::SlowDown() const {
	if (depth<30)
		throw "shut down with anchor!'\n";
	AccX=-AccX;
	double t=speed/AccX;
	double DeltaL = speed*t-AccX*AccX*t*0.5;
	cout << DeltaL << '\n';
}
void Ship::Mass(double x, double y) const {
	if (x=this->x,y=this-y)
		throw Crash();

}
 
double Ship::GetAccX(bitmap L1 , bitmap L2,double t) {
	double x= L1.x-L2.x;
	double vx= x/t;
	return  2*(x-vx*t)/t/t;
}
double Ship::GetAccY(bitmap L1 , bitmap L2,double t) {
	double y= L1.y-L2.y;
	double vy= y/t;
	return  2*(y-vy*t)/t/t;

}


};