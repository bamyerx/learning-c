/*
 * Exercise 5-20 from K&R: Expand dcl to handle declarations with function
 * argument types, qualifiers like const, and so on.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

enum { NAME, NUMBER, TYPE_SPECIFIER, TYPE_QUALIFIER, STORAGE_CLASS };
enum { SUCCESS, FAILURE };	/* return codes for parsing functions */

const char *type_specifiers[] = { "void", "char", "short", "int", "long",
	                              "float", "double", "signed", "unsigned" };
const int ntypes = 9;
const char *type_qualifiers[] = { "const", "volatile" };
const int nqualifiers = 2;
const char *storage_classes[] = { "auto", "register", "static", "extern" };
const int nstorage_classes = 4;

int dcl(void);
int dirdcl(void);
void pointer(void);
void type_qualifier_list(void);
int parameter_list(void);
int parameter_declaration(void);
void declaration_specifiers(void);
int is_declaration_specifier(void);
int identifier_list(void);

int gettoken(void);
int tokentype;           /* type of last token */
int getch(void);
void ungetch(int);
char token[MAXTOKEN+1];    /* last token string */
char name[MAXTOKEN+1];     /* identifier name */
char datatype[MAXTOKEN+1]; /* data type = char, int, etc. */
char out[1000];

int main(void)  /* convert declaration to words */
{
	int c;

	while (gettoken() != EOF) {    /* 1st token on line is the datatype */
		name[0] = '\0';
		out[0] = '\0';
		datatype[0] = '\0';
		if (is_declaration_specifier())
			declaration_specifiers();
		if (dcl() == SUCCESS && tokentype == '\n')
			printf("%s: %s %s\n", name, out, datatype);
		else {
			printf("syntax error: unexpected '%c'\n", tokentype);
			while ((c = getch()) != '\n' && c != EOF)
				;
		}
	}

	return 0;
}

/* gettoken: return next token */
int gettoken(void)
{
	int c, i;
	char *p = token;

	/* skip white space */
	while ((c = getch()) == ' ' || c == '\t')
		;
	if (isalpha(c) || c == '_') {
		for (*p++ = c; isalnum(c = getch()) || c == '_'; )
			if (p < token + MAXTOKEN)
				*p++ = c;
		*p = '\0';
		ungetch(c);
		for (i = 0; i < ntypes; i++)
			if (strcmp(token, type_specifiers[i]) == 0)
				return tokentype = TYPE_SPECIFIER;
		for (i = 0; i < nqualifiers; i++)
			if (strcmp(token, type_qualifiers[i]) == 0)
				return tokentype = TYPE_QUALIFIER;
		for (i = 0; i < nstorage_classes; i++)
			if (strcmp(token, storage_classes[i]) == 0)
				return tokentype = STORAGE_CLASS;
		return tokentype = NAME;
	} else if (isdigit(c)) {
		for (*p++ = c; isdigit(c = getch()); )
			if (p < token + MAXTOKEN)
				*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NUMBER;
	} else
		return tokentype = c;
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

/* getch: get a (possibly pushed-back) character */
int getch(void)  
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* dcl: parse a declarator
 *
 * declarator:
 *     pointer? direct-declarator
 */
int dcl(void)
{
	if (tokentype == '*')
		pointer();
	return dirdcl();
}

/* dirdcl: parse a direct declarator
 *
 * direct-declarator:
 *     NAME
 *     ( declarator )
 *     direct-declarator [ NUMBER ]
 *     direct-declarator ( parameter-list? )
 *     direct-declarator ( identifier-list )
 */
int dirdcl(void)
{
	if (tokentype == NAME)
		strcpy(name, token);
	else if (tokentype == '(') {
		gettoken();
		if (dcl() == FAILURE)
			return FAILURE;
		if (tokentype != ')') {
			printf("error: missing )\n");
			return FAILURE;
		}
	} else {
		printf("error: expected identifier or (\n");
		return FAILURE;
	}
	while (gettoken() == '[' || tokentype == '(') {
		if (tokentype == '[') {
			if (gettoken() != NUMBER) {
				printf("error: expected integer\n");
				return FAILURE;
			}
			strcat(out, " array[");
			strcat(out, token);
			strcat(out, "] of");
			if (gettoken() != ']') {
				printf("error: missing ]\n");
				return FAILURE;
			}
		} else if (tokentype == '(') {
			strcat(out, " function returning");
			gettoken();
			if (is_declaration_specifier()) {
				if (parameter_list() == FAILURE)
					return FAILURE;
			} else if (tokentype == NAME) {
				if (identifier_list() == FAILURE)
					return FAILURE;
			} else if (tokentype != ')') {
				printf("error: expected parameter declaration or identifier\n");
				return FAILURE;
			}
			if (tokentype != ')') {
				printf("error: missing )\n");
				return FAILURE;
			}
		}
	}
	return SUCCESS;
}

/* pointer: parse a pointer
 *
 * pointer:
 *     * type-qualifier-list?
 *     * type-qualifier-list? pointer
 */
void pointer(void)
{
	gettoken();
	if (tokentype == TYPE_QUALIFIER)
		type_qualifier_list();
	if (tokentype == '*')
		pointer();
	strcat(out, " pointer to");
}

/* type_qualifier_list: consume type qualifier tokens
 *
 * type-qualifier-list:
 *     TYPE_QUALIFIER
 *     type-qualifier-list TYPE_QUALIFIER
 */
void type_qualifier_list(void)
{
	while (gettoken() == TYPE_QUALIFIER)
		;
}

/* parameter_list: parse a parameter list
 *
 * parameter-list:
 *     parameter-declaration
 *     parameter-list , parameter-declaration
 */
int parameter_list(void)
{
	if (parameter_declaration() == FAILURE)
		return FAILURE;
	while (tokentype == ',') {
		gettoken();
		if (!is_declaration_specifier()) {
			printf("error: expected declaration specifier\n");
			return FAILURE;
		}
		if (parameter_declaration() == FAILURE)
			return FAILURE;
	}
	return SUCCESS;
}

/* parameter_declaration: parse a parameter-declaration
 *
 * parameter-declaration:
 *     declaration-specifiers declarator
 */
int parameter_declaration(void)
{
	declaration_specifiers();
	return dcl();
}

/* declaration_specifiers: consume declaration specifiers
 *
 * declaration-specifiers:
 *     storage-class-specifier declaration-specifiers?
 *     type-specifier declaration-specifiers?
 *     type-qualifier declaration-specifiers?
 */
void declaration_specifiers(void)
{
	do {
		strcat(datatype, " ");
		strcat(datatype, token);
		gettoken();
	} while (is_declaration_specifier());
}

/* is_declaration_specifier: checks if current token is a declaration specifier */
int is_declaration_specifier(void)
{
	return tokentype == STORAGE_CLASS ||
		   tokentype == TYPE_SPECIFIER ||
		   tokentype == TYPE_QUALIFIER;
}

/* identifier_list: parse an identifier list
 *
 * identifier-list:
 *     identifier
 *     identifier-list , identifier
 */
int identifier_list(void)
{
	while (gettoken() == ',') {
		if (gettoken() != NAME) {
			printf("error: expected identifier\n");
			return FAILURE;
		}
	}
	return SUCCESS;
}

