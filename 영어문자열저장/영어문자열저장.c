#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	
	for (char c = '0'; c <= 'z'; c++) {
		printf("%c : %d\n", c, c);
	}

	char str[] = "나도코딩";
	printf("%s : 크기(%d)\n", str, sizeof(str));

	strcpy_s(str, sizeof(str), "너도코딩");
	printf("%s : 크기(%d)\n", str, sizeof(str));

	return 0;
}