#include "Error.hh"

virtual double RadarX(double x, double y)const {};
virtual double Gps(double x, double y)const {};
virtual double Sounder(double x, double y)const {};
virtual double GetLoc(double x, double y, double Nx, double Ny)const {};
virtual double Getdirect(double dest) const {};
friend double operator -(const Error& a1,const Error& a2){};
virtual bool safeDist(Error a) const {};
virtual double Correct(Error a) const {};
};