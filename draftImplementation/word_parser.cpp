#include <thread>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include "word_parser.h"

// Worker thread: consume words passed from the main thread and insert them
// in the 'word list' (s_wordsArray), while removing duplicates. Terminate when
// the word 'end' is encountered.
void Parser::workerThread(){
	bool endEncountered = false;
	bool found = false;
	
	while (!endEncountered)
	{
	if (word.data[0]) // Do we have a new word?
	{
		Word *w = new Word(); // Copy the word
		strcpy_s(w->data, strlen(word.data) + 1, word.data);
		word.data[0] = 0; // Inform the producer that we consumed the word
		
		endEncountered = std::strcmp( word.data, "end" ) == 0;
		
		if (!endEncountered)
		{
		// Do not insert duplicate words
		for ( auto p : wordsArray )
		{
			if (!std::strcmp( p->data, w->data ))
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

// Read input words from STDIN and pass them to the worker thread for
// inclusion in the word list.
// Terminate when the word 'end' has been entered.
//
void Parser::readInputWords(){
	bool endEncountered = false;
  
	std::thread worker(&Parser::workerThread, Parser());
	
	char * linebuf = new char[32];
	try
	{
		while (!endEncountered)
		{
			if (fgets(linebuf, strlen(linebuf), stdin) == nullptr) // EOF?
				return;

			endEncountered = std::strcmp(linebuf, "end") == 0;
			// Pass the word to the worker thread
			strcpy_s(word.data, strlen(linebuf) + 1, linebuf);
			
			//while (word.data[0]); // Wait for the worker thread to consume it
		}
	}
	catch (const std::exception&)
	{
		worker.join(); // Wait for the worker to terminate
		throw;
	}
}
void Parser::lookupWords(){
	bool found;
	char * linebuf = new char[32];
	
	for(;;)
	{
		std::printf( "\nEnter a word for lookup:" );
		if (scanf_s( "%s", linebuf, sizeof(linebuf)) == EOF)
			return;
		
		// Initialize the word to search for
		Word * w = new Word();
		strcpy_s( w->data, sizeof(linebuf), linebuf);
		
		// Search for the word
		unsigned i;
		for ( i = 0; i < wordsArray.size(); ++i )
		{
			if (std::strcmp( wordsArray[i]->data, w->data ) == 0)
			{
			found = true;
			break;
			}
		}
		
		if (found)
		{
			std::printf( "SUCCESS: '%s' was present %d times in the initial word list\n",
						wordsArray[i]->data, wordsArray[i]->count );
			totalFound++;
		}
		else
			std::printf( "'%s' was NOT found in the initial word list\n", w->data );
	}
}
void Parser::wordsParsing(){
	try
	{
		readInputWords();
		// Sort the words alphabetically
		std::sort( wordsArray.begin(), wordsArray.end() );
		
		// Print the word list
		std::printf( "\n=== Word list:\n" );
		for ( auto p : wordsArray )
			std::printf( "%s %d\n", p->data, p->count );
		
		lookupWords();
		
		printf( "\n=== Total words found: %d\n", totalFound );
	}
	catch (std::exception & e)
	{
		std::printf( "error %s\n", e.what() );
	}
}