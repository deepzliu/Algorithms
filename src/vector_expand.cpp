#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A constructor" << endl;
	}
};

int main()
{
	vector<A> va;

	cout << "1 capacity: " << va.capacity() << ", size: " << va.size() << endl;
	
	A a;
	int n = 10;
	for(int i = 0; i < n; i++)
	{
		va.push_back(a);
		cout << i << " = capacity: " << va.capacity() << ", size: " << va.size() << endl;
	}

	//va.resize(10);
	//cout << "3 capacity: " << va.capacity() << ", size: " << va.size() << endl;
}
