#include <stdio.h>  // 입출력을 위해 포함
#include <stdlib.h> // 난수 생성을 위해 포함
#include <time.h>   // srand 함수에 사용할 시간 기반 시드 생성을 위해 포함
#define ROW 100     // 행렬의 최대 행 크기를 정의
#define COL 100     // 행렬의 최대 열 크기를 정의

// 행렬에 값을 입력하는 함수
void input2DArray(int array[][100], int row, int col) {
    for (int i = 0; i < row; i++) { // 행 반복
        for (int j = 0; j < col; j++)  // 열 반복
            array[i][j] = rand() % 2 + 1; // 난수를 생성하여 (1 또는 2) 배열에 저장
    }
}

// 행렬을 출력하는 함수
void print2DArray(int array[][100], int row, int col) {
    printf("======================\n");
    for (int i = 0; i < row; i++) { // 행 반복
        for (int j = 0; j < col; j++) { // 열 반복
            printf("[%4d] ", array[i][j]); // 각 요소를 출력
        }
        printf("\n"); // 행 끝나면 개행
    }
}

// 두 행렬의 덧셈을 수행하는 함수
void addMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
    for (int i = 0; i < row; i++) { // 행 반복
        for (int j = 0; j < col; j++) { // 열 반복
            target[i][j] = s1[i][j] + s2[i][j]; // 요소별 덧셈 결과를 target에 저장
        }
    }
}

// 두 행렬의 뺄셈을 수행하는 함수
void subMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
    for (int i = 0; i < row; i++) { // 행 반복
        for (int j = 0; j < col; j++) { // 열 반복
            target[i][j] = s1[i][j] - s2[i][j]; // 요소별 뺄셈 결과를 target에 저장
        }
    }
}

// 두 행렬의 곱셈을 수행하는 함수
void mulMatrix(int s1[][100], int s2[][100], int target[][100], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) { // 결과 행렬의 행 반복
        for (int j = 0; j < col2; j++) { // 결과 행렬의 열 반복
            target[i][j] = 0; // 초기화
            for (int k = 0; k < col1; k++) // 행렬 곱셈 계산
                target[i][j] += s1[i][k] * s2[k][j]; // 행렬 곱셈 규칙 적용
            }
        }
    }
}

// 메인 함수
int main() {
    int matrix1[ROW][COL]; // 첫 번째 행렬 선언
    int matrix2[ROW][COL]; // 두 번째 행렬 선언
    int result[ROW][COL];  // 결과 행렬 선언
    int row1, col1, row2, col2; // 행렬의 행과 열 크기를 저장할 변수
    srand(time(NULL)); // 난수 생성을 위한 시드 초기화

    // 사용자로부터 행렬의 크기를 입력받음
    printf("Input matrix1 row & col: ");
    scanf("%d %d", &row1, &col1);
    printf("Input matrix2 row & col: ");
    scanf("%d %d", &row2, &col2);

    // 행렬 곱셈 가능 여부를 확인
    if (col1 != row2) { // col1이 row2와 다르면 곱셈 불가능
        input2DArray(matrix1, row1, col1); // 첫 번째 행렬 입력
        input2DArray(matrix2, row2, col2); // 두 번째 행렬 입력
        printf("\n행렬1:\n");
        print2DArray(matrix1, row1, col1); // 첫 번째 행렬 출력
        printf("\n행렬2:\n");
        print2DArray(matrix2, row2, col2); // 두 번째 행렬 출력
        mulMatrix(matrix1, matrix2, result, row1, col1, col2); // 행렬 곱셈 수행
        printf("두 행렬의 곱 값:\n");
        print2DArray(result, row1, col2); // 결과 행렬 출력
    }
    else { // col1 == row2인 경우
        printf("no"); // 곱셈이 가능하지 않음을 출력
    }
    return 0; // 프로그램 종료
}
