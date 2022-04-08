//DSA2Project4 Elena Lucci
#include "MonteCarlo.hpp"

MonteCarlo::MonteCarlo(){

		numBatches = 0;
		numItems = 0;
		percentBadBatches = 0.0;
		percentBadItems = 0.0;
		numSampled = 0;
		fileName = "";
		maxNumBadItems =0;
		minNumBadItems = 10001;
		avgBadItems = 0;
		numBadBatchesFound = 0;

}
//Executes Simulation
void MonteCarlo::Execute(std::string file, int i){
	ReadFile(file);
	WriteFiles();
	CheckFiles();
	Display(i);
	//resets numbers
	maxNumBadItems = 0;
	minNumBadItems = 10001;
	numBadBatchesFound = 0;
}

void MonteCarlo::ReadFile(std::string fileName){

	inFile.open(fileName);
		
	inFile >> numBatches >> numItems >> percentBadBatches >> percentBadItems >> numSampled;
	inFile.close();	
	
	FindNumBad(percentBadBatches);
}

void MonteCarlo::WriteFiles(){
	//creates good files
	for(int i=1;i<(numBatches-numBad)+1;i++){
		std::string s = std::to_string(i);
		fileName = "ds" + s + ".txt";
		outFile.open(fileName);

		for(int j=0;j<numItems;j++){
			outFile << "g" << std::endl;
		}
		outFile.close();
	}

	double total = 0;
	//creates bad files
	for(int i=(numBatches-numBad)+1; i <numBatches+1;i++){
		std::string s = std::to_string(i);
		fileName = "ds" + s + ".txt";
		outFile.open(fileName);

		int numBadCounted = 0;
		for(int j=0; j<numItems;j++){
			
			std::string temp = GenerateRand();

			outFile << temp << std::endl;
			
			if(temp == "b"){
				numBadCounted++;
			}
		
		}
		
		if(numBadCounted > maxNumBadItems){
			maxNumBadItems = numBadCounted;
		}

		if(numBadCounted < minNumBadItems){
			minNumBadItems = numBadCounted;
		}

		total += numBadCounted;

		outFile.close();
	}

	avgBadItems = (total / (numBad*1000))* 1000;

	
		
}

void MonteCarlo::FindNumBad(double percentBadBatches){
	numBad = numBatches * (percentBadBatches/100);
}

std::string MonteCarlo::GenerateRand(){

	int randNum;

	randNum = rand() % 100;

	if((randNum >= 0) && (randNum <= (percentBadItems-1))){
		return "b";
	}
	else{
		return "g";

	}
}

void MonteCarlo::CheckFiles(){

	for(int i=1;i<numBatches+1;i++){
		std::string s = std::to_string(i);
		fileName = "ds" + s + ".txt";

		inFile.open(fileName);
		
		for(int j =0;j<numSampled;j++){
			std::string temp;
			inFile >> temp;
			
			if(temp == "b"){
				numBadBatchesFound++;
				break;
			}

		}
	
		inFile.close();
	}
}

double MonteCarlo::PercentBadBatchesFound(){

	double a = (double) numBadBatchesFound;

	return (a/numBad)*100;
}

void MonteCarlo::Display(int simNumber){
	std::cout<< "Simulation #" << simNumber << std::endl;
	std::cout<< "	Number of batches of items:				" << numBatches << std::endl;
	std::cout<< "	Number of items in each batch:				" << numItems << std::endl;
	std::cout << "	Percentage of batches containing bad items:		" << percentBadBatches << std::endl;
	std::cout << "	Percentage of items that are bad in a bad set:		" << percentBadItems << std::endl;
	std::cout << "	Items sampled from each set:				" << numSampled << std::endl;

	std::cout << std::endl;

	std::cout << "Generating data sets:" << std::endl;
	std::cout << "	Total bad sets = " << numBad << std::endl;
	std::cout << "	Max number of bad items in a bad set = " << maxNumBadItems << std::endl;
	std::cout << "	Min number of bad items	in a bad set = " << minNumBadItems << std::endl;
	std::cout << "	Average number of bad items in a bad set = " << avgBadItems << std::endl;

	std::cout << std::endl;

	std::cout << "Analyzing data Sets:" << std::endl;
	std::cout << "	Base = " << (1-(percentBadItems/100)) << "	Exponent = " << numSampled  <<std::endl;
	std::cout << "	P(failure to detect bad item) = " << pow((1-(percentBadItems/100)), numSampled) << std::endl;
	std::cout << "	P(batch is good) = " << 1 - (pow((1-(percentBadItems/100)), numSampled)) << std::endl;
	std::cout << "	Percentage of bad batches detected = "<< PercentBadBatchesFound() <<std::endl;
	
	std::cout << std::endl;
	
	std::cout << "######################################################" << std::endl;
}
