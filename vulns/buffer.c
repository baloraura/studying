#include <stdio.h>

/*Demonstrating buffer overflows*/

int main(int argc, char **argv) {
	char buf[8];         // buffer for eight characters
	gets(buf);           // read from stdio (sensitive function!)
	printf("%s\n", buf); // print out data stored in buf

	return 0;
}
