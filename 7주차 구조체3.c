#include <stdio.h>  // ǥ�� ����� ���̺귯��
#include <time.h>   // �ð� ���� �Լ� ����� ���� ���̺귯��
#include <stdlib.h> // ���� ���� �Լ� ���� ���� ���̺귯��
#define SIZE 100    // �迭 ũ�⸦ 100���� ����

// POINT ����ü ����: x, y ��ǥ�� ��Ÿ���� �� ���� ������ ����
typedef struct point {
	int x;  // x ��ǥ
	int y;  // y ��ǥ
} POINT;

// POINT �迭�� ���� ��ǥ�� �Է��ϴ� �Լ�
void input_random_point(POINT* p, int size) {
	srand(time(NULL));  // ���� ������ ���� �õ� ���� (���� �ð��� ���)
	for (int i = 0; i < size; i++) {
		(p + i)->x = rand() % 101;  // 0���� 100������ ������ x ��ǥ ����
		(p + i)->y = rand() % 101;  // 0���� 100������ ������ y ��ǥ ����
	}
}

// �� POINT ����ü�� ���� ���� �ٲٴ� �Լ�
void swap_point(POINT* p1, POINT* p2) {
	POINT temp;   // �ӽ÷� ���� ������ ����ü ����
	temp = *p1;   // p1�� ���� temp�� ����
	*p1 = *p2;    // p2�� ���� p1�� ����
	*p2 = temp;   // temp�� ����� p1 ���� p2�� ����
}

// ���� ������ ����Ͽ� POINT �迭�� �����ϴ� �Լ�
void selection_sort_point(POINT* point, int size) {
	for (int i = 0; i < SIZE - 1; i++) {
		int least;   // ���� ���� ���� ���� �ε����� ������ ����
		least = i;   // ó������ ���� �ε����� �ּҷ� ����
		for (int j = i + 1; j < SIZE; j++) {
			// x ��ǥ�� �� ���� ��� �Ǵ� x ��ǥ�� ���� y ��ǥ�� �� ���� ��� �ּҰ� ����
			if (point[least].x > point[j].x)
				least = j;
			else if ((point + least)->x == point[j].x && point[least].y > point[j].y) {
				least = j;
			}
		}
		// ���� ���� ���� ���� ��ġ�� ���� ��ȯ
		swap_point(&point[i], point + least);
	}
}

// POINT �迭�� ����ϴ� �Լ�
void print_point_array(POINT p[], int size) {
	for (int i = 0; i < size; i++) {
		// �� ��ǥ�� ��� (�ε����� x, y ��ǥ)
		printf("p[%3d]:(%3d,%3d)\n", i, p[i].x, p[i].y);
	}
}

int main() {
	POINT point[SIZE] = { 0 };  // POINT ����ü �迭 ���� �� 0���� �ʱ�ȭ
	POINT temp = { 0,0 };       // �ӽ� POINT ����ü ���� �� �ʱ�ȭ

	// ������ ��ǥ�� ���� POINT �迭 ����
	input_random_point(point, SIZE);

	// ���� �� POINT �迭 ���
	print_point_array(point, SIZE);

	// POINT �迭�� x, y ��ǥ �������� ����
	selection_sort_point(point, SIZE);

	// ���� �� POINT �迭 ���
	printf("after sorting>>>>>>>>>>>>>>>>>>>>>>..\n");
	print_point_array(point, SIZE);

	return 0;  // ���α׷� ����
}