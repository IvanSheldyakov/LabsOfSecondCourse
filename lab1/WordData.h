#ifndef __WORD_DATA__

#define __WORD_DATA__

#include <string>

class WordData {
	std::string word;
	int count;
	double frequency;

public:
	WordData(std::string word, int count, double frequency);
	int getCount();
	std::string getWord();
	double getFrequency();
};

#endif

