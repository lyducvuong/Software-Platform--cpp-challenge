#ifndef WORD_PARSER_H
#define WORD_PARSER_H
#include <stdint.h>
#include "word.h"
#include <thread>
#include <semaphore.h>
using namespace std;
class Parser {
public:
	Parser() {
		memset(word.data,'\0', sizeof(word));
    }
	
    ~Parser() {
    }

public:
	static void* workerThread_wrapper(void* object);
	void readInputWords();
	void workerThread();
	void showWordsArrayInfo();
	void lookupWords();

public:
	vector<Word*> wordsArray;
	Word word;
	int totalFound;
	sem_t sync;
	
};
#endif //WORD_PARSER_H
