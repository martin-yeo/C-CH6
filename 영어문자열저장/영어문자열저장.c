#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	
	for (char c = '0'; c <= 'z'; c++) {
		printf("%c : %d\n", c, c);
	}

	char str[] = "�����ڵ�";
	printf("%s : ũ��(%d)\n", str, sizeof(str));

	strcpy_s(str, sizeof(str), "�ʵ��ڵ�");
	printf("%s : ũ��(%d)\n", str, sizeof(str));

	return 0;
}