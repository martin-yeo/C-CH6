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
	int theTreatment = rand() % TOTAL_BOTTLES +1;		// ���� �� ��ȣ
	int nowNoBottle = 0;		// �̹� ȸ�� �ິ ����
	int prevNoBottle = 0;		// ���� ȸ�� �ິ ����
	
	// ���� ���� ȭ�� ���
	showStart();

	for (int i = 0; i < 3; i++) { // �� 3ȸ �ິ���� �����ֱ�
		// ���° ȸ������ ���
		showStage(i+1);

		// �� ���� �ິ�� �� ���ΰ� ����(2��~3��)
		// �̹� ����(nowNoBottle)�� ���� ����(prevNoBottle)�ʹ� �޶�� ��
		do {
			nowNoBottle = rand() % 2 + 2;
		} while (prevNoBottle == nowNoBottle);
		
		// �ິ ���� �� �ʱ�ȭ
		int bottle[TOTAL_BOTTLES] = { 0, };		// ���õ� �ິ �迭  0:�̼���, 1:����

		// �� �� �ິ�� �� ���ΰ� ����
		for (int j = 0; j < nowNoBottle; j++)	{
			int randBottle = rand() % TOTAL_BOTTLES;
			if (bottle[randBottle] == 0) bottle[randBottle] = 1;
			else j--;
		}

		// �� �ິ�� ȭ�鿡 ����ϰ�, �Ӹ��� ������ ���θ� ���
		showBottles(theTreatment, bottle, TOTAL_BOTTLES);  // ���亴��ȣ

		// ��� ���߱�
		//getchar();
	}

	// ����ڿ��� ȿ���ִ� �߸����� �Է¹ޱ�
	int answer = 0;
	answer = getUserInput(TOTAL_BOTTLES);

	// ���� ���� ȭ�� ���. �����̸� 1, �ƴϸ� 0���� ����
	showEnding(theTreatment, answer-1 == theTreatment);

	return 0;
}


void showStart(void) { // ���� ���� ȭ��
	printf("*------ �ڶ󳪶� �Ӹ�ī�� ���� v1.0 ------*\n");
	printf(" 3���� ���� ����� ���� ���� ����ȣ ������\n");
	printf("*-----------------------------------------*\n\n");
}

void showStage(int stage) {  // ��� ȸ������ ���
	printf("<< [%dȸ�� ����] \n", stage);
}

void showBottles(int magicBottle, int selectedBottles[], size_t no) { // ���� ����ȣ, ���õ� �� �迭, ������ �޾� ��� ���
	int isIncluded = 0;

	for (int i = 0; i < no; i++)	{
		if (selectedBottles[i] == 1) {
			printf("%d���� ", i + 1);
			if (magicBottle == i) isIncluded = 1;
		}		
	}
	printf("����, �Ӹ��� �ٸ��ϴ�!\n");

	if (isIncluded == 1)	{
		printf(">> ����!! �Ӹ�ī���� �����ϴ�!\n\n");
	}
	else {
		printf(">> ����!! �Ӹ�ī���� ���� �ʾҽ��ϴ�.. �Ф�\n\n");
	}
	
}

int getUserInput(size_t no) {
	int input;

	while (1)
	{
		printf("�߸����� �� �� ���ϱ��? ");
		int check = scanf_s(" %d", &input);
		
		if (check == 0) {
			printf("���ڸ� �Է��ϼ���!\n");
			char garbage[256];
			scanf_s("%s", garbage, sizeof(garbage));
		}
		else if (input < 1 || input > no) {
			printf("1 ~ %d ������ ���ڸ� �Է��ϼ���!\n", no);
		}
		else break;
	}

	return input;
}

void showEnding(int magicBottle, int code) {  // ���� ����ȣ, ���� ���� �ڵ�(0:����, 1:����) �޾� ����ϰ�, ���� ���� ȭ�� ���
	
	if (code == 1) printf("\n\n>> �����Դϴ�!\n\n");
	else printf("\n\n>> Ʋ�Ƚ��ϴ�! ������ %d�����Դϴ�.\n\n", magicBottle + 1);

	printf("*------------��--��---��--��--------------*\n\n");
}