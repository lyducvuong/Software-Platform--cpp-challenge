#include <pthread.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include "word_parser.h"
using namespace std;
// Read input words from STDIN and pass them to the worker thread for
// inclusion in the word list.
// Terminate when the word 'end' has been entered.
//
void Parser::readInputWords() {
	bool endEncountered = false;
	pthread_t worker;
	worker = pthread_create(&worker, NULL, &Parser::workerThread_wrapper, this);

	char* linebuf = new char[32];
	try
	{
		while (!endEncountered)
		{
			if (fgets(linebuf, strlen(linebuf), stdin) == nullptr) // EOF?
				return;

			endEncountered = strcmp(linebuf, "end") == 0;
			// Pass the word to the worker thread
			strcpy(word.data, linebuf);

			//while (word.data[0]); // Wait for the worker thread to consume it
		}
	}
	catch (const std::exception&)
	{
		pthread_join(worker, NULL); // Wait for the worker to terminate
		throw;
	}
}

// Worker thread: consume words passed from the main thread and insert them
// in the 'word list' (s_wordsArray), while removing duplicates. Terminate when
// the word 'end' is encountered.
void* Parser::workerThread_wrapper(void *object){
	reinterpret_cast<Parser*>(object)->workerThread();
	return 0;
}
void Parser::workerThread(){
	bool endEncountered = false;
	bool found = false;
	
	while (!endEncountered)
	{
	if (word.data[0]) // Do we have a new word?
	{
		Word *w = new Word(); // Copy the word
		strcpy(w->data, word.data);
		word.data[0] = 0; // Inform the producer that we consumed the word
		
		endEncountered = strcmp( word.data, "end" ) == 0;
		
		if (!endEncountered)
		{
		// Do not insert duplicate words
		for ( auto p : wordsArray )
		{
			if (!strcmp( p->data, w->data ))
			{
			++p->count;
			found = true;
			break;
			}
		}
	
		if (!found)
			wordsArray.push_back( w );
		}
	}
	}
}

void Parser::showWordsArrayInfo() {
	// Sort the words alphabetically
	sort(wordsArray.begin(), wordsArray.end());

	// Print the word list
	printf("\n=== Word list:\n");
	for (auto p : wordsArray)
		printf("%s %d\n", p->data, p->count);
}

void Parser::lookupWords(){
	bool found;
	char * linebuf = new char[32];
	
	for(;;)
	{
		printf( "\nEnter a word for lookup:" );
		if (scanf( "%s", linebuf) == EOF)
			return;
		
		// Initialize the word to search for
		Word * w = new Word();
		strcpy( w->data, linebuf);
		
		// Search for the word
		unsigned i;
		for ( i = 0; i < wordsArray.size(); ++i )
		{
			if (strcmp( wordsArray[i]->data, w->data ) == 0)
			{
				found = true;
				break;
			}
		}
		
		if (found)
		{
			printf( "SUCCESS: '%s' was present %d times in the initial word list\n",
						wordsArray[i]->data, wordsArray[i]->count );
			totalFound++;
		}
		else
			printf( "'%s' was NOT found in the initial word list\n", w->data );
		}
		printf("\n=== Total words found: %d\n", totalFound);

}

int main()
{
	Parser parser = Parser();
	try
	{
		parser.readInputWords();
		parser.showWordsArrayInfo();
		parser.lookupWords();
	}
	catch (exception & e)
	{
		printf( "error %s\n", e.what() );
	}
}
