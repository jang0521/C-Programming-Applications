#include <stdio.h>
#include <stdlib.h>

// POINT 구조체 정의
typedef struct point {
    int x; // x 좌표
    int y; // y 좌표
} POINT;

// 메뉴 입력 함수
int inputMenu(void) {
    int input;
    printf("1.만들기,2.출력하기,3.클리어,4.파일저장,5.파일로드,-1.종료:"); // 메뉴 출력
    scanf("%d", &input); // 사용자 입력 받기
    return input; // 입력된 메뉴 반환
}

// POINT 구조체를 동적 생성하는 함수
POINT* makePoint(void) {
    POINT* p = (POINT*)malloc(sizeof(POINT)); // 동적 메모리 할당
    p->x = rand() % 100; // 랜덤한 x 값 설정
    p->y = rand() % 100; // 랜덤한 y 값 설정
    return p; // 생성된 POINT 구조체 반환
}

// POINT 구조체 배열을 출력하는 함수
void printPoint(POINT* p[], int size) {
    for (int i = 0; i < size; i++) {
        printf("x:%d,y:%d\n", p[i]->x, p[i]->y); // 각 POINT의 좌표 출력
    }
}

// 동적으로 할당된 POINT 구조체 배열의 메모리를 해제하는 함수
void freePoints(POINT* p[], int size) {
    for (int i = 0; i < size; i++) {
        free(p[i]); // 각각의 POINT 메모리 해제
    }
}

// POINT 구조체 배열을 파일에 저장하는 함수
int saveFile(POINT* p[], int count) {
    FILE* fp;
    fp = fopen("points.bin", "rb"); // 파일을 읽기 모드로 열기 (오류 있음)
    if (fp == NULL) { // 파일 열기에 실패한 경우
        return 0; // 실패 반환
    }
    for (int i = 0; i < count; i++) {
        fwrite(p[i], sizeof(POINT), 1, fp); // POINT 구조체를 파일에 저장
    }
    fclose(fp); // 파일 닫기
    return 1; // 성공 반환
}

// 파일에서 POINT 구조체 배열을 읽어오는 함수
int loadFile(POINT* p[], int max) {
    FILE* fp;
    int fsize, fCount;

    // fp에 파일 오픈 정보 저장 (오류 있음)
    fp = fopen = ftell(fp);

    // 파일 크기와 POINT 개수 계산 (오류 있음)
    fCount = fSize / sizeof(POINT);
    rewind(fp); // 파일 포인터를 처음으로 이동

    // POINT 구조체 배열 읽기
    for (int i = 0; i < fCount; i++) {
        if (i == max) { // 최대 크기에 도달하면 중지
            break;
        }
        p[i] = (POINT*)malloc(sizeof(POINT)); // 메모리 할당
        fread(p[i], sizeof(POINT), 1, fp); // 파일에서 POINT 읽기
    }
    fclose(fp); // 파일 닫기
    return count; // 읽어온 POINT 개수 반환
}

// 메인 함수
int main() {
    int menu; // 메뉴 선택 변수
    int count = 0; // POINT 개수
    POINT* points[100]; // POINT 구조체 포인터 배열 (최대 100개)
    
    do {
        menu = inputMenu(); // 메뉴 입력 받기
        switch (menu) {
            case 1: // POINT 생성
                points[count] = makePoint(); // 새 POINT 생성
                count++; // POINT 개수 증가
                break;
            case 2: // POINT 출력
                printPoint(points, count); // POINT 배열 출력
                break;
            case 3: // 화면 클리어
                system("clear"); // 화면 초기화 (Linux 명령어)
                break;
            case 4: // POINT 저장
                if (!saveFile(points, count)) { // 파일 저장 실패 시
                    printf("file open error...\n"); // 오류 메시지 출력
                } else {
                    printf("file writing success...\n"); // 성공 메시지 출력
                }
                break;
            case 5: // 파일에서 POINT 로드
                count = loadFile(points, 100); // POINT 배열 로드
                break;
            case -1: // 종료
                freePoints(points, count); // 할당된 메모리 해제
                printf("프로그램을 종료합니다.\n"); // 종료 메시지 출력
                break;
        }
    } while (menu > 0); // 메뉴가 0보다 클 때 반복
    return 0; // 프로그램 종료
}
