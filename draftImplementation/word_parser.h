#ifndef WORD_PARSER_H
#define WORD_PARSER_H
#include <stdint.h>
#include "word.h"
#include <thread>
#include <semaphore>
using namespace std;
class Parser {
public:
	Parser() {
		memset(word.data, NULL, sizeof(word));
    }
	
    ~Parser() {
    }

public:
	
	void readInputWords();
	void workerThread();
	void showWordsArrayInfo();
	void lookupWords();

public:
	vector<Word*> wordsArray;
	Word word;
	int totalFound;
	
};
#endif //WORD_PARSER_H