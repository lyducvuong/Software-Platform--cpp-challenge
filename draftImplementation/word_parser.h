#ifndef WORD_PARSER_H
#define WORD_PARSER_H
#include <stdint.h>
#include "word.h"
#include <thread>
#include <semaphore>
class Parser {
public:
	Parser() {
    }
	
    ~Parser() {

    }

public:
	
    void workerThread();
    void readInputWords();
    void lookupWords();
	void wordsParsing();

public:
	sem_t mutex;
	std::vector<Word*> wordsArray;
	Word word;
	int totalFound;
	
};
#endif //WORD_PARSER_H