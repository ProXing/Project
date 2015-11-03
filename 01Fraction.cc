#include <iostream>
using namespace std;

class Fraction {
private:
	int num, den;
public:
	// constructor
  Fraction(int n, int d) {
		num = n; den = d;
	}
  Fraction(int n) {
		num = n; den = 1;
	}
  Fraction() {
		num = 0; den = 1;
	}
	void print() {
		cout << num << "/" << den << '\n';
	}

};


int main() {
	Fraction a(1,2);  // 1/2
	Fraction b(1,3); // 1/3
	//	Fraction c = a + b;

	Fraction d; // 0/1
	Fraction e(5); // 5/1
#if 0
 	Fraction f();
	/* This is not legal because f is a function that returns Fraction, and therefore
	f.print() makes no sense.
	*/
	f.print();
#endif
	
	a.print();
	b.print();
	//	c.print();
	d.print();
	e.print();
	cout << a << " + " << b << " = " << c << '\n';
}
