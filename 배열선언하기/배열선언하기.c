#include <stdio.h>

int main(void) {
	int subway_array[5] = { 30, 40, 50 };
	
	for (int i = 0; i < 5; i++) {
		printf("����ö %dȣ���� %d���� Ÿ�� �ֽ��ϴ�.\n", i + 1, subway_array[i]);
	}

	return 0;
}