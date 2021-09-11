#include "WordData.h"

WordData::WordData(std::string word, int count, double frequency) {
	this->word = word;
	this->count = count;
	this->frequency = frequency;
}

int WordData::getCount() {
	return count;
}

std::string WordData::getWord() {
	return word;
}

double WordData::getFrequency() {
	return frequency;
}