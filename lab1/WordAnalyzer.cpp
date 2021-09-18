
#include "WordAnalyzer.h"
#include <cctype>
#include <iostream>



WordAnalyzer::WordAnalyzer() {
	map = {};
	amountOfWords = 0;
}


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



struct Comparator {
	bool operator ()(WordData &first, WordData &second) {

		return (first.getCount() > second.getCount());

	}
};

void WordAnalyzer::analyze(std::list<WordData> &list) {
	for (auto it = map.cbegin(); it != map.cend(); it++) {
        WordData wordData(it->first, it->second, ((double)it->second * 100 / amountOfWords));
		list.push_back(wordData);
	}
	list.sort(Comparator());
}



void WordAnalyzer::writePreparedDataTo(std::string outputFile) {
    std::list<WordData> list = {};
	std::ofstream file;
	file.open(outputFile, std::ios::out);
	analyze(list);
	for (auto it = list.begin(); it != list.end(); it++) {
		file << it->getWord() << "," << it->getCount() << "," << it->getFrequency() << "\n";
	}
	file.close();
}




