#include <stdio.h>    // 표준 입출력 라이브러리
#include <stdlib.h>   // rand(), srand() 등의 함수 사용을 위한 라이브러리
#include <time.h>     // time() 함수를 사용하여 난수 생성을 위한 시드 설정
#define SIZE 100      // 배열 크기를 100으로 정의

// 배열에 랜덤한 값(0 ~ 99)을 입력하는 함수
void inputRandomArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % 100;  // 각 배열 요소에 0 ~ 99 사이의 난수를 저장
    }
}

// 배열의 값을 출력하는 함수 (10개씩 출력 후 줄바꿈)
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d\t", *(array + i));  // 각 배열 요소를 출력 (3자리로 맞춤)
        if ((i + 1) % 10 == 0) printf("\n");  // 10번째마다 줄바꿈
    }
}

int main() {
    int number[SIZE];  // 크기가 100인 배열 선언

    srand(time(NULL));  // 난수 생성을 위한 시드 설정 (현재 시간을 기반으로 시드 설정)

    inputRandomArray(number, SIZE);  // 배열에 랜덤 값 입력
    printArray(number, SIZE);        // 배열을 출력

    return 0;  // 프로그램 종료
}
