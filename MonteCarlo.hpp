//DSA2Project4 Elena Lucci
#ifndef MonteCarlo_hpp
#define MonteCarlo_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>

class MonteCarlo{

	private:
		std::ifstream inFile;
		std::ofstream outFile;
		std::string fileName;
		int numBatches;
		int numItems;
		double percentBadBatches;
		double percentBadItems;
		int numSampled;
		int numBad;
		int maxNumBadItems;
		int minNumBadItems;
		double avgBadItems;
		int numBadBatchesFound;

	public:
		MonteCarlo();
		void FindNumBad(double percentBadBatches);
		void Execute(std::string file,int i);
		void ReadFile(std::string fileName);
		void WriteFiles();
		void Display(int simNumber);
		std::string GenerateRand();
		void CheckFiles();
		double PercentBadBatchesFound();

};

#endif
