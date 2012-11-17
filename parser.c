#include <stdlib.h>
#include <string.h>

typedef struct parser_
{
	const char* buffer;
	int pos;
	int line;
} parser;

/** Create a new parser with the given string to parse. **/
parser* create_parser(const char* buffer)
{
	parser* rval = malloc(sizeof(parser));
	rval->buffer = buffer;
	rval->pos = 0;
	rval->line = 0;
};

/** Returns 1 if we're at the end of the buffer. **/
int parser_at_end(parser* p)
{
	return p->pos >= strlen(p->buffer);
};

/** Returns a new string with the next amount chars in the buffer. **/
const char* parser_get_next(parser* p, int amount)
{
	if(p->pos + amount > strlen(p->buffer))
	{
		return NULL;
	}

	char* rval = malloc(amount+1);
	strncpy(rval, p->buffer+p->pos, amount);
	return rval;
};

/** Returns the next character in the buffer. **/
char parser_get_char(parser* p)
{
	if(p->pos < strlen(p->buffer))
	{
		return p->buffer[p->pos];
	}
	return 0;
};

/** Checks if the given word is ahead in the buffer. 
	Return 1 if it is, 0 otherwise.
**/
int parser_is_next(parser* p, const char* word)
{
    const char* compare = parser_get_next(p, strlen(word));

	return strcmp(word, compare) == 0;
};

/** Skips the next amount chars in the buffer. Returns the skipped string. **/
const char* parser_skip_amount(parser* p, int amount)
{
	int start = p->pos;
	p->pos += amount;
	if(p->pos > strlen(p->buffer)) p->pos = strlen(p->buffer);

	int length = p->pos - start + 1;
	char* rval = malloc(length);
	strncpy(rval, p->buffer+start, length);
	return rval;
};

/** Checks if the word is in the buffer, and if so, skips it. Returns 1 if word matched. **/
int parser_skip(parser* p, const char* word)
{
	if(parser_is_next(p, word))
	{
		parser_skip_amount(p, strlen(word));
		return 1;
	}
	else return 0;
};
