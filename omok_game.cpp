//	2021-04-10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define MAP_SIZE 19

#define DRAW_BLACK printf("\u25CB")
#define DRAW_WHITE printf("\u25CF")

#define WHITE 2
#define BLACK 1

static int map[MAP_SIZE][MAP_SIZE] = { 0, };

int flag = 0;

void intro();
void drawmap(int map[][19]);
int drawstone(int map[][19], int x, int y);
int winFlag(int map[][19], int x, int y);

int main() {


	intro();
	
	while (1) {

		int x, y;
		drawmap(map);

		printf("input coordinate :  ");
		scanf("%d %d", &x, &y);

		drawstone(map, x, y);

		flag = winFlag(map, x, y);
		if (flag == 1) {
			printf("���� �̰���ϴ�!\n");
			break;
		}
		else if (flag == 2) {
			printf("���� �̰���ϴ�!\n");
			break;
		}
		else
			continue;
		
	}

	return 0;
}



void intro() {

	printf("\n\n");
	printf("---------------- 2�ο� ���� ���� ------------------\n");
	printf("* ����� 2���� �����ư��鼭 ���� ��ġ��ŵ�ϴ�\n");
	printf("* ���� 5�� �̻� ����Ǹ� �¸��մϴ�\n");
	printf("* �浹���� ������ ���۵˴ϴ�. ���ϴ� ��ġ�� ��ǥ���� �Է����ּ��� (EX. 4 6) \n");
	printf("* Enter �� ������ ������ ���۵˴ϴ�\n");
	printf("\n\n");

}


void drawmap(int map[][19]) {

	printf("\t");
	for (int a = 0; a < MAP_SIZE; a++) {
		printf("%d|", a + 1);
	}
	printf("\n");
	
	for (int i = 0; i < MAP_SIZE; i++) {
		printf("%d\t", i+1);
		for (int j = 0; j < MAP_SIZE; j++) {
			if (i == 0) {
				if (j == 0)
					printf("\u250C");
				else if (j == MAP_SIZE - 1)
					//printf("%c%c", 196, 191);
					printf("\u2500\u2510");
				else
					printf("\u2500\u252C");
			}
			else if (j == 0) {
				if (i == MAP_SIZE - 1)
					printf("\u2514");
				else
					printf("\u251C\u2500");
					//printf("%c", 195);
			}
			else if (j == MAP_SIZE - 1) {
				if (i == MAP_SIZE - 1)
					printf("\u2500\u2518");
					//printf("%c%c", 196, 217);
				else
					printf("\u2524");
					//printf("%c%c", 196, 180);
			}
			else if (i == MAP_SIZE - 1) {
				printf("\u2500\u2534");
				//printf("%c%c", 196, 193);
			}
			else
				//���⿡ �� ����
				if (map[i][j] == 0) {
					printf("\u253C\u2500");
				}
				else if (map[i][j] == 1) {
					//printf("\u2500");r
					DRAW_BLACK;
				}
				else {
					//printf("\u2500");
					DRAW_WHITE;
				}
				
		}
		printf("\n");

	}

}

int drawstone(int map[][19], int x, int y) {

	static int turn = 1;

	if (map[x][y] || x <= 0 || x > MAP_SIZE || y <= 0 || y > MAP_SIZE) {
		printf("��ȿ�������� ��ǥ���Դϴ�. �ٽ� �Է����ּ���\n");
		return 0;
	}
	else {
		if (turn % 2 == 1) {
			map[x][y] = BLACK;
			printf("  %d   ��° ���Դϴ�\n", turn);
			printf("  �� ������ ��\n");
			turn++;
		}
		else {
			map[x][y] = WHITE;
			printf("  %d   ��° ���Դϴ�\n", turn);
			printf("  �� ������ ��\n");
			turn++;
		}
	}

	return turn;
}


int winFlag(int map[][19], int x, int y) {

	//���� ��
	static int rowflag, colflag, crossleflag, crossriflag = 0;	
	static int flag = 0;		//win flag -> 1 : �� �¸�, 2: �� �¸�

	int color = map[x][y];

	int i = 0;
	for (i =  -5; i <= 5; i++) {
		if (y + i <= 0 && y + i >= 19)
			continue;
		if (map[x][y + i] == color) {
			rowflag++;
			if (rowflag == 5) {
				flag = color;
				return flag;
			}
		}
		else rowflag = 0;
	}

	for (i = -5; i <= 5; i++) {
		if (x + i <= 0 && x + i >= 19)
			continue;

		if (map[x + i][y] == color) {
			colflag++;
			if (colflag == 5) {
				flag = color;
				return flag;
			}
		}
		else colflag = 0;
	}

	for (i = -5; i <= 5; i++) {
		if (x + i <= 0 && x + i >= 19)
			continue;
		if (y + i <= 0 && y + i >= 19) continue;

		if (map[x + i][y + i] == color) {
			crossriflag++;
			if (crossriflag == 5) {
				flag = color;
				return flag;
			}
		}
		else crossriflag = 0;
	}

	for (i = -5; i <= 5; i++) {
		if (x + i <= 0 && x + i >= 19)
			continue;
		if (y - i <= 0 && y - i >= 19) continue;

		if (map[x + i][y - i] == color) {
			crossleflag++;
			if (crossleflag == 5) {
				flag = color;
				return flag;
			}
		}
		else crossleflag = 0;
	}



	return flag;
}


