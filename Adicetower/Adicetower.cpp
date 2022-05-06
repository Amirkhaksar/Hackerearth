/*Language: cpp
ID: c889471c
QLink:www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/tower-c889471c/
Author: @ellicoder */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Settlement {
	public:
	template < typename T > static T input() {
		T value;
		cin >> value;
		return value;
	}
};

class TestClass
{
    public:
    static void main(vector<string> &args) {
        int t = Settlement::input<int>();
        while (t-- > 0) {
            long n = Settlement::input<long long>();
            long c = 0;
            if (n < 21 || n > 21 && n < 30)
                cout << "-1" << endl;
            else {
                c = n / 14;
                n = n % 14;
                if (n > 1 && n < 13)
                    cout << c << endl;
                else
                    cout << "-1" << endl;
            }
        }
    }
};

int main(int argc, char **argv){
	vector<string> parameter(argv + 1, argv + argc);
	TestClass::main(parameter); 
	return 0;
};