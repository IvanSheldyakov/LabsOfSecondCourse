
#include "WordAnalyzer.h"

int main(int argc, char** argv) {

	WordAnalyzer* analyzer = new WordAnalyzer();

	analyzer->readWordsFrom(argv[1]);
	analyzer->analyze();
	analyzer->writePreparedDataTo(argv[2]);

	delete analyzer;

	return 0;
}