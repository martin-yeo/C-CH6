#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL_BOTTLES 4

void showStart(void);
void showStage(int);
void showBottles(int, int[], size_t);
int getUserInput(size_t);
void showEnding(int, int);

int main(void) {
	srand(time(NULL));
	int theTreatment = rand() % TOTAL_BOTTLES +1;		// 정답 병 번호
	int nowNoBottle = 0;		// 이번 회차 약병 개수
	int prevNoBottle = 0;		// 이전 회자 약병 개수
	
	// 게임 시작 화면 출력
	showStart();

	for (int i = 0; i < 3; i++) { // 총 3회 약병조합 보여주기
		// 몇번째 회차인지 출력
		showStage(i+1);

		// 몇 개의 약병을 고를 것인가 선택(2개~3개)
		// 이번 개수(nowNoBottle)는 이전 개수(prevNoBottle)와는 달라야 함
		do {
			nowNoBottle = rand() % 2 + 2;
		} while (prevNoBottle == nowNoBottle);
		
		// 약병 고르기 전 초기화
		int bottle[TOTAL_BOTTLES] = { 0, };		// 선택된 약병 배열  0:미선택, 1:선택

		// 몇 번 약병을 고를 것인가 선택
		for (int j = 0; j < nowNoBottle; j++)	{
			int randBottle = rand() % TOTAL_BOTTLES;
			if (bottle[randBottle] == 0) bottle[randBottle] = 1;
			else j--;
		}

		// 고른 약병을 화면에 출력하고, 머리가 나는지 여부를 출력
		showBottles(theTreatment, bottle, TOTAL_BOTTLES);  // 정답병번호

		// 잠깐 멈추기
		//getchar();
	}

	// 사용자에게 효과있는 발모제를 입력받기
	int answer = 0;
	answer = getUserInput(TOTAL_BOTTLES);

	// 게임 종료 화면 출력. 정답이면 1, 아니면 0으로 전달
	showEnding(theTreatment, answer-1 == theTreatment);

	return 0;
}


void showStart(void) { // 게임 시작 화면
	printf("*------ 자라나라 머리카락 게임 v1.0 ------*\n");
	printf(" 3번의 실험 결과를 보고서 정답 병번호 맞히기\n");
	printf("*-----------------------------------------*\n\n");
}

void showStage(int stage) {  // 몇번 회차인지 출력
	printf("<< [%d회차 실험] \n", stage);
}

void showBottles(int magicBottle, int selectedBottles[], size_t no) { // 정답 병번호, 선택된 병 배열, 병개수 받아 결과 출력
	int isIncluded = 0;

	for (int i = 0; i < no; i++)	{
		if (selectedBottles[i] == 1) {
			printf("%d번병 ", i + 1);
			if (magicBottle == i) isIncluded = 1;
		}		
	}
	printf("선택, 머리에 바릅니다!\n");

	if (isIncluded == 1)	{
		printf(">> 성공!! 머리카락이 났습니다!\n\n");
	}
	else {
		printf(">> 실패!! 머리카락이 나지 않았습니다.. ㅠㅠ\n\n");
	}
	
}

int getUserInput(size_t no) {
	int input;

	while (1)
	{
		printf("발모제는 몇 번 병일까요? ");
		int check = scanf_s(" %d", &input);
		
		if (check == 0) {
			printf("숫자를 입력하세요!\n");
			char garbage[256];
			scanf_s("%s", garbage, sizeof(garbage));
		}
		else if (input < 1 || input > no) {
			printf("1 ~ %d 사이의 숫자를 입력하세요!\n", no);
		}
		else break;
	}

	return input;
}

void showEnding(int magicBottle, int code) {  // 정답 병번호, 정답 여부 코드(0:실패, 1:정답) 받아 출력하고, 게임 종료 화면 출력
	
	if (code == 1) printf("\n\n>> 정답입니다!\n\n");
	else printf("\n\n>> 틀렸습니다! 정답은 %d번병입니다.\n\n", magicBottle + 1);

	printf("*------------게--임---종--료--------------*\n\n");
}