#include <stdio.h>

int main(void) {
	int subway_array[5] = { 30, 40, 50 };
	
	for (int i = 0; i < 5; i++) {
		printf("지하철 %d호차에 %d명이 타고 있습니다.\n", i + 1, subway_array[i]);
	}

	return 0;
}