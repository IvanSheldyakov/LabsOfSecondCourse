#include "WordAnalyzer.h"
#include <iostream>
int main(int argc, char** argv) {

    if (argc != 3) {
        std::cout  << "Incorrect amount of arguments" << std::endl;
        return 0;
    }

	WordAnalyzer* analyzer = new WordAnalyzer();

	analyzer->readWordsFrom(argv[1]);
	analyzer->writePreparedDataTo(argv[2]);

	delete analyzer;

	return 0;
}
