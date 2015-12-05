//Author : Xingyu Li
//Date update : 12/01/2015
#ifndef Ship_HH_
#define Ship_HH_

#include "Error.hh"
#include "Bitmap.hh" 
#include <cmath>
#include <iostream>


using namespace std;

const double SafeDep=15.0f; //define the safe depth is 15 meter;
double const PI=3.1415926;
double const D2R=PI/180; 
// make mass of ship in order
struct Loc{
	double x;
	double y;
};
class Crash{
private:
	double x, double y;
public:
	Crash(double x,double y): x(x),y(y){
		cout << "The location have a ship here and U cant get to there !\n";
	}
};
class Depth{
private:
	double depth;
public:
	Depth(double dep): depth(dep){
		cout << "The water is too swallow! \n";
	}
};

class Ship :public Error{
private:

	char* shape; //kind of ship;
	char* number;//name of ship;
	double speed;
	double theta;
	double dep;

	enum {len=20};
	vector<Loc> point;
	
public:
	Ship(const char* num,const char* s,double the,int radar,int gps,int sound,double x,double y,double s,double dep) throw(Depth,Crash):Error(radar,gps,sound,x,y){
		if (Depth<SafeDep)
			throw Depth(depth);
		if (x==1&&y==1)
			throw Crash(x,y);
		number = new char [len];
		shape = new char [len];
		strncpy(number,num,len-1);
		number[len-1]='\0';
		strncpy(shape,s,len-1);
		shape[len-1]='\0';
		this->s=s;
		theta=the;

	}
	~Ship(){
		delete [] name;
		delete [] shape;
	}
	
	virtual void Getnumber()const = 0;//show the number of the ship;
	virtual void Setnumber(const char* a) =0; // change the number of the ship
	virtual void Getshape() const = 0; // get the kind of a ship
	virtual void Setshape(const char* a) =0; // set the function of a ship
	virtual double GetRadius(double L, double K, double M) =0; // get the radius of turning;
	virtual void SlowDown() const = 0; //diatance to stop a ship;
	
	virtual double GetAccX(bitmap L1 , bitmap L2,double t) =0; //calculate the ax of a period
	virtual double GetAccY(bitmap L1 , bitmap L2,double t) =0; //calculate the ay of a period
	 //function for a search ship
	Loc Search(double x,double y,bitmap L1, double value) {
		Loc L;
		if (L1.GetXY(x,y)==value){
			L.x=x;
			L.y=y;
			return L;
			else{
				Search(double x,double y+1,bitmap L1, double value);
				Search(double x,double y-1,bitmap L1, double value);
				Search(double x+1,double y,bitmap L1, double value);
				Search(double x-1,double y,bitmap L1, double value);
			return;
		}
		}
	} 
	//function for a drawmapship;
	void Drawmap(double x, double y, bitmap L1, double value) {
		for (double i=0; i < L1.h; i++)
			for (double j=0; j < L1.w; j++){
				if (L1.GetXY(i,j)== value)
					point.pushback(i,j);
				}
		for (vector<Loc>:: iterator i = list.begin(); i!= list.end() ; i++)
			for (vector <Loc>:: iterator j= list.begin()+1; j!=list.end();j++ ){
				L1.line(i.x,i.y,j.x,j.y,value)
			}
		
		}
	};

#endif