
#include "WordAnalyzer.h"
#include <ctype.h>
#include <iostream>



WordAnalyzer::WordAnalyzer() {
	list = {};
	map = {};
	amountOfWords = 0;
}

/*
WordAnalyzer::~WordAnalyzer() {
	while (!list.empty()) {
		WordData data = list.front();
		delete *data;
	}
*/

void WordAnalyzer::findWords(std::string line) {
	std::string word = "";
	for (int i = 0; i < line.size(); i++) {
		if (!isalpha(line[i]) && !isdigit(line[i]) && word.size() > 0) {
			map[word]++;
			word = "";
			amountOfWords++;
		}
		else {
			word.push_back(line[i]);
		}
	}
	if (word.size() > 0) {
		map[word]++;
		amountOfWords++;
	}
}

void WordAnalyzer::readWordsFrom(std::string inputFile) {
	std::ifstream file;
	file.open(inputFile, std::ios::in);
	
	while (!file.eof()) {
		std::string line;
		std::getline(file, line);
		findWords(line);
	}		
	file.close();
}


	
struct Comparator
{
	bool operator ()(WordData &first, WordData &second) {
	
		return (first.getCount() > second.getCount());
	
	}
};

void WordAnalyzer::analyze() {
	for (auto it = map.cbegin(); it != map.cend(); it++) {
		WordData* data = new WordData(it->first, it->second, ((double)it->second * 100 / amountOfWords));
		list.push_back(*data);
	}
	list.sort(Comparator());
}



void WordAnalyzer::writePreparedDataTo(std::string outputFile) {
	std::ofstream file;
	file.open(outputFile, std::ios::out);
	for (auto it = list.begin(); it != list.end(); it++) {
		file << it->getWord() << "," << it->getCount() << "," << it->getFrequency() << "\n";
	}
	file.close();
}




