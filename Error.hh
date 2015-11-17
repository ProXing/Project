#ifndef Error_HH_
#define Error_HH_


class Error{
private:
	double x,y;
	double Nx,Ny;
	
public:
	Error(double x, double y){
		x=x;
		y=y;
	};
	virtual double RadarX(double x, double y) const =0;
	virtual double Gps(double x, double y) const=0;
	virtual double Sounder(double x, double y) const=0;
	virtual double GetLoc(double x, double y, double Nx, double Ny) const=0;
	virtual double Getdirect(double dest) const=0;
	friend double operator -(const Error& a1,const Error& a2){};
	virtual bool safeDist(Error a) const=0;
	virtual double Correct(Error a) const=0;
};
#endif