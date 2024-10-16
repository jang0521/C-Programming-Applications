#include <stdio.h>  // 표준 입출력 라이브러리
#include <time.h>   // 시간 관련 함수 사용을 위한 라이브러리
#include <stdlib.h> // 난수 생성 함수 등을 위한 라이브러리
#define SIZE 100    // 배열 크기를 100으로 정의

// POINT 구조체 정의: x, y 좌표를 나타내는 두 개의 정수형 변수
typedef struct point {
	int x;  // x 좌표
	int y;  // y 좌표
} POINT;

// POINT 배열에 랜덤 좌표를 입력하는 함수
void input_random_point(POINT* p, int size) {
	srand(time(NULL));  // 난수 생성을 위한 시드 설정 (현재 시간을 기반)
	for (int i = 0; i < size; i++) {
		(p + i)->x = rand() % 101;  // 0에서 100까지의 랜덤한 x 좌표 생성
		(p + i)->y = rand() % 101;  // 0에서 100까지의 랜덤한 y 좌표 생성
	}
}

// 두 POINT 구조체의 값을 서로 바꾸는 함수
void swap_point(POINT* p1, POINT* p2) {
	POINT temp;   // 임시로 값을 저장할 구조체 선언
	temp = *p1;   // p1의 값을 temp에 복사
	*p1 = *p2;    // p2의 값을 p1에 복사
	*p2 = temp;   // temp에 저장된 p1 값을 p2에 복사
}

// 선택 정렬을 사용하여 POINT 배열을 정렬하는 함수
void selection_sort_point(POINT* point, int size) {
	for (int i = 0; i < SIZE - 1; i++) {
		int least;   // 가장 작은 값을 가진 인덱스를 저장할 변수
		least = i;   // 처음에는 현재 인덱스를 최소로 설정
		for (int j = i + 1; j < SIZE; j++) {
			// x 좌표가 더 작은 경우 또는 x 좌표가 같고 y 좌표가 더 작은 경우 최소값 갱신
			if (point[least].x > point[j].x)
				least = j;
			else if ((point + least)->x == point[j].x && point[least].y > point[j].y) {
				least = j;
			}
		}
		// 가장 작은 값과 현재 위치의 값을 교환
		swap_point(&point[i], point + least);
	}
}

// POINT 배열을 출력하는 함수
void print_point_array(POINT p[], int size) {
	for (int i = 0; i < size; i++) {
		// 각 좌표를 출력 (인덱스와 x, y 좌표)
		printf("p[%3d]:(%3d,%3d)\n", i, p[i].x, p[i].y);
	}
}

int main() {
	POINT point[SIZE] = { 0 };  // POINT 구조체 배열 선언 및 0으로 초기화
	POINT temp = { 0,0 };       // 임시 POINT 구조체 선언 및 초기화

	// 랜덤한 좌표를 가진 POINT 배열 생성
	input_random_point(point, SIZE);

	// 정렬 전 POINT 배열 출력
	print_point_array(point, SIZE);

	// POINT 배열을 x, y 좌표 기준으로 정렬
	selection_sort_point(point, SIZE);

	// 정렬 후 POINT 배열 출력
	printf("after sorting>>>>>>>>>>>>>>>>>>>>>>..\n");
	print_point_array(point, SIZE);

	return 0;  // 프로그램 종료
}