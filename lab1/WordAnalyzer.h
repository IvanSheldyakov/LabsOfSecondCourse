#ifndef __STRING_ANALYZER__

#define __STRING_ANALYZER__

#include <list>
#include <string>
#include <map>
#include <fstream>

#include "WordData.h"


class WordAnalyzer {
	
	std::list<WordData> list;
	std::map<std::string, int> map;

	int amountOfWords;

public:
	WordAnalyzer();
	
	void readWordsFrom(std::string inputFile);
	void writePreparedDataTo(std::string outputFile);
	void analyze();
	

private:
	void findWords(std::string line);
	
		

};


#endif