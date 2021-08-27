#ifndef WORD_PARSER_H
#define WORD_PARSER_H
#include <stdint.h>
#include "word.h"
class Parser {
public:
	Parser() {
		this.word = new Word();
    }
	
    ~Parser() {
        delete [] data;
    }

private:
	
    void workerThread();
    void readInputWords();
    void lookupWords();
	void wordsParsing();

private:
	std::vector<Word*> wordsArray;
	Word word;
	int count;
	int totalFound;
	
};
#endif //WORD_PARSER_H