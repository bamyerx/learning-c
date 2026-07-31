/* Allows the user to view regions of computer memory */

#include <ctype.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

typedef unsigned char BYTE;

int main(void)
{
	uintptr_t addr;
	int i, n;
	BYTE *ptr;

	printf("Address of main function: %p\n", (void *) main);
	printf("Address of addr variable %p\n", (void *) &addr);

	printf("\nEnter a (hex) address: ");
	scanf("%" SCNxPTR, &addr);
	printf("Enter number of bytes to view: ");
	scanf("%d", &n);

	printf("\n");
	printf("     Address                   Bytes              Characters\n");
	printf(" ----------------  -----------------------------  ----------\n");

	ptr = (BYTE *) addr;
	for (; n > 0; n -= 10) {
		printf(" %016" PRIXPTR "  ", (uintptr_t) ptr);
		for (i = 0; i < 10 && i < n; i++)
			printf("%.2X ", *(ptr + i));
		for (; i < 10; i++)
			printf("   ");
		printf(" ");
		for (i = 0; i < 10 && i < n; i++) {
			BYTE ch = *(ptr + i);
			if (!isprint(ch))
				ch = '.';
			printf("%c", ch);
		}
		printf("\n");
		ptr += 10;
	}
	printf("\n");

	return 0;
}
