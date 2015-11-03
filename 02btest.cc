#include <iostream>
using namespace std;
class test {
private:
	int a, b, c;
public:
	test() : a(1), b(2), c(5) {}
	void print() const {
		cout << a << b << c;
		
	}
	void add(test t1, test t2) {
		t1.a = 4;
		t2.b = 5;
	}
	friend ostream& operator <<(ostream& s, const test& t) {
		s << t.a << t.b << t.c;
	}
};

int main() {
	test t1;
	test t2=test ();// NOT AN OBJECT
	//	test t3(4); // ILLEGAL
  const test t3;
	t1.print();
	t3.print();
	t2.print(); // ILLEGAL
	cout << t3;}
	
