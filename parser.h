#include <stdlib.h>
#include <string.h>

typedef struct parser_
{
	const char* buffer;
	int pos;
	int line;
} parser;

/** Create a new parser with the given string to parse. **/
parser* create_parser(const char* buffer);

/** Returns 1 if we're at the end of the buffer. **/
int parser_at_end(parser* p);

/** Returns a new string with the next amount chars in the buffer. **/
const char* parser_get_next(parser* p, int amount);

/** Returns the next character in the buffer. **/
char parser_get_char(parser* p);

/** Checks if the given word is ahead in the buffer. 
	Return 1 if it is, 0 otherwise.
**/
int parser_is_next(parser* p, const char* word);

/** Skips the next amount chars in the buffer. Returns the skipped string. **/
const char* parser_skip_amount(parser* p, int amount);

/** Checks if the word is in the buffer, and if so, skips it. Returns 1 if word matched. **/
int parser_skip(parser* p, const char* word);

/** Reads an integer and writes it into the pointer. Returns 1 on success, 0 on failure. **/
int parser_read_integer(parser* p, int* i);
