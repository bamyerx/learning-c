/*
 * Project 10 from Chapter 22 of King: Modify the inventory2.c program of
 * Section 17.5 by adding the d (dump) and r (restore) operations described in
 * Programming Project 8. Since the part structures aren't stored in an array,
 * the d operation can't save them all by a single call of fwrite. Instead it
 * will need to visit each node in the linked list, writing the part number,
 * part name, and quantity on hand to a file. As it reads parts from a file, the
 * r operation will rebuild the list one node at a time.
 */

#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	struct part *next;
};

struct part *inventory = NULL;    /* points to first part */

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

/*
 * main: Prompts the user to enter an operation code, then calls a function to
 *       perform the requested action. Repeats until the user enters the command
 *       'q'. Prints an error message if the user enters an illegal code.
 */
int main(void)
{
	char code;

	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n')   /* skips to end of line */
			;
		switch (code) {
			case 'i': insert();
					  break;
			case 's': search();
					  break;
			case 'u': update();
					  break;
			case 'p': print();
					  break;
			case 'd': dump();
					  break;
			case 'r': restore();
					  break;
			case 'q': return 0;
			default:  printf("Illegal code\n");
		}
		printf("\n");
	}
}

/*
 * find_part: Looks up a part number in the inventory list. Returns a pointer to
 *            the node containing the part number; if the part number is not 
 *            found, returns NULL.
 */
struct part *find_part(int number)
{
	struct part *p;

	for (p = inventory; p != NULL && number > p->number; p = p->next)
		;
	if (p != NULL && number == p->number)
		return p;
	return NULL;
}

/*
 * insert: Prompts the user for information about a new part and then inserts
 *         the part into the inventory list; the list remains sorted by part
 *         number. Prints an error message and returns prematurely if the part
 *         already exists or space could not be allocated for the part.
 */
void insert(void)
{
	struct part *cur, *prev, *new_node;

	new_node = malloc(sizeof(struct part));
	if (new_node == NULL) {
		printf("Database is full; can't add more parts. \n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &new_node->number);

	for (cur = inventory, prev = NULL;
		 cur != NULL && new_node->number > cur->number;
		 prev = cur, cur = cur->next)
		;
	if (cur != NULL && new_node->number == cur->number) {
		printf("Part already exists.\n");
		free(new_node);
		return;
	}

	printf("Enter part name: ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->on_hand);
	
	new_node->next = cur;
	if (prev == NULL)
		inventory = new_node;
	else
		prev->next = new_node;
}

/*
 * search: Prompts the user to enter a part number, then looks up the part in
 *         the database. If the part exists, prints the name and quantity on
 *         hand; if not, prints an error message.
 */
void search(void)
{
	int number;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Part name: %s\n", p->name);
		printf("Quantity on hand: %d\n", p->on_hand);
	} else
		printf("Part not found.\n");
}

/*
 * update: Prompts the user to enter a part number. Prints an error message if
 *         the part doesn't exist; otherwise, prompts the user to enter change
 *         in quantity on hand and updates the database.
 */
void update(void)
{
	int number, change;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		p->on_hand += change;
	} else
		printf("Part not found.\n");
}

/*
 * print: Prints a list of all parts in the database, showing the part number,
 *        part name, and quantity on hand. Part numbers will appear in ascending
 *        order.
 */
void print(void)
{
	struct part *p;

	printf("Part Number   Part Name                  "
		   "Quantity on Hand\n");
	for (p = inventory; p != NULL; p = p->next)
		printf("%7d       %-25s%11d\n", p->number, p->name, p->on_hand);
}

/*
 * dump: Saves the database in a specified file.
 */
void dump(void)
{
	char filename[MAX_FILENAME];
	FILE *fp;
	struct part *pp;

	printf("Enter name of output file: ");
	scanf("%s", filename);
	if ((fp = fopen(filename, "wb")) != NULL) {
		for (pp = inventory; pp->next != NULL; pp = pp->next) {
			fwrite(&pp->number, sizeof(pp->number), 1, fp);
			fwrite(pp->name, sizeof(pp->name), 1, fp);
			fwrite(&pp->on_hane, sizeof(pp->on_hand), 1, fp);
			pp = pp->next;
		}
		fclose(fp);
	} else
		printf("Dump unsuccessful: can't open %s\n", filename);
}

/*
 * restore: Loads the database from a specified file.
 */
void restore(void)
{
	char filename[MAX_FILENAME];
	FILE *fp;
	struct part *pp, *new_node;

	printf("Enter name of input file: ");
	scanf("%s", filename);
	if ((fp = fopen(filename, "rb")) != NULL) {
		inventory = NULL;
		while (fread(&pp->number, sizeof(pp->number), 1, fp) == 1 &&
			   fread(pp->name, sizeof(pp->name), 1, fp) == 1 &&
			   fread(&pp->on_hand, sizeof(pp->on_hand), 1, fp) == 1) {
			if ((new_node = malloc(sizeof(struct part))) == NULL) {
				fprintf(stderr, "database is full; can't add more parts.\n");
				exit(EXIT_FAILURE);
			}
			new_node->number = pp->number;
			new_node->name = pp->name;
			new_node->on_hand = pp->on_hand;
			new_
		}
		fclose(fp);
	} else
		printf("Restore unsuccessful: can't open %s\n", filename);
}

#include <ctype.h>

/*
 * read_line: Skips leading white-space characters, then reads the remainder of
 *            the input line an dstores it in str. Truncates the line if its
 *            length exceeds n. Returns the number of characters stored.
 */
int read_line(char str[], int n)
{
	int ch, i = 0;

	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}
