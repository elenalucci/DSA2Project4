//DSA2Project 4 Elena Lucci
#include <iostream>
#include "MonteCarlo.hpp"

int main(){

	MonteCarlo mc;
	mc.Execute("t1.txt",1);
	mc.Execute("t2.txt",2);
	mc.Execute("t3.txt",3);
	mc.Execute("t4.txt",4);

	return 0;
}
