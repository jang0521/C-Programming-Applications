#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 구조체 정의
typedef struct point { // 점(point)을 나타내는 구조체
    int x; // x 좌표
    int y; // y 좌표
} POINT;

// 사용자로부터 POINT 입력 받는 함수
POINT makePoint(void) {
    POINT p; // 새로운 POINT 변수 선언
    scanf("%d %d", &p.x, &p.y); // 사용자로부터 x와 y 값을 입력받음
    return p; // 입력받은 POINT 반환
}

// 배열 크기만큼 랜덤한 POINT 생성하는 함수
void makeRandomPoints(POINT p[], int size) {
    srand(time(NULL)); // 랜덤 시드 초기화
    for (int i = 0; i < size; i++) { // 배열 크기만큼 반복
        p[i].x = rand() % 100; // x 좌표를 0~99 범위의 랜덤 값으로 설정
        p[i].y = rand() % 100; // y 좌표를 0~99 범위의 랜덤 값으로 설정
    }
}

// POINT 배열 출력 함수
void printPoints(POINT p[], int size) {
    for (int i = 0; i < size; i++) // 배열 크기만큼 반복
        printf("point[%d] = x:%d, y:%d\n", i, p[i].x, p[i].y); // 각 POINT의 x와 y 좌표 출력
}

// 파일에서 POINT 배열을 읽어오는 함수
void loadFile(POINT p[], int size) {
    FILE *fp; // 파일 포인터 선언
    fp = fopen("struct.bin", "rb"); // "struct.bin" 파일을 읽기 모드로 열기
    if (fp == NULL) exit(-1); // 파일 열기에 실패하면 프로그램 종료
    fread(p, sizeof(POINT), size, fp); // 파일에서 size 개수만큼 POINT 읽기
    fclose(fp); // 파일 닫기
}

// 메인 함수
int main() {
    FILE *fp; // 파일 포인터 선언
    POINT p[10]; // POINT 배열 선언 (크기 10)
    POINT p2; // POINT 변수 선언 (파일에서 특정 위치의 POINT 읽기용)
    int pi; // 파일 포인터 위치를 저장할 변수

    // 파일에서 POINT 배열 읽어오기
    loadFile(p, 10);
    printPoints(p, 10); // 읽어온 POINT 배열 출력

    // 파일 다시 열기
    fp = fopen("struct.bin", "rb");
    if (fp == NULL) exit(-1); // 파일 열기에 실패하면 프로그램 종료

    // 파일에서 네 번째 POINT 읽기
    fseek(fp, sizeof(POINT) * 3, SEEK_SET); // 파일 포인터를 네 번째 POINT의 시작 위치로 이동
    pi = ftell(fp); // 현재 파일 포인터 위치 저장
    printf("pi = %d\n", pi); // 파일 포인터 위치 출력
    fread(&p2, sizeof(POINT), 1, fp); // 네 번째 POINT 읽기
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y); // 읽어온 POINT 출력

    // 파일의 끝에서 두 번째 POINT 읽기
    fseek(fp, sizeof(POINT) * -2, SEEK_END); // 파일 끝에서 두 번째 POINT로 이동
    printf("pi = %d\n", ftell(fp)); // 현재 파일 포인터 위치 출력
    fread(&p2, sizeof(POINT), 1, fp); // 해당 위치의 POINT 읽기
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y); // 읽어온 POINT 출력

    // 파일의 전체 크기 확인
    fseek(fp, 0, SEEK_END); // 파일 끝으로 이동
    printf("size = %ld\n", ftell(fp)); // 파일 크기 출력 (바이트 단위)

    fclose(fp); // 파일 닫기
    return 0; // 프로그램 종료
}
