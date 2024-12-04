#include <stdio.h>

// 사용자 입력을 한 줄 단위로 읽어오는 함수
int getLine(char* line) {
    int ch; // 입력된 문자 저장
    int i = 0; // 현재 위치 인덱스
    while ((ch = getchar()) != '\n') { // 줄바꿈 문자('\n')이 나올 때까지 반복
        line[i++] = ch; // 입력된 문자를 배열에 저장
    }
    line[i] = '\0'; // 문자열 끝에 NULL 문자 추가
    return i; // 읽어온 문자열 길이 반환
}

int main() {
    char input[100]; // 파일에서 읽어올 문자열 저장 배열
    int num1, num2; // 파일에서 읽어올 숫자들
    FILE* fp_src; // 원본 파일 포인터
    FILE* fp_dest; // 복사할 대상 파일 포인터

    // 원본 파일 열기 (읽기 모드)
    if ((fp_src = fopen("output.txt", "r")) == NULL) { // 파일 열기 실패 시
        printf("error..."); // 에러 메시지 출력
        return 0; // 프로그램 종료
    }

    // 대상 파일 열기 (쓰기 모드)
    if ((fp_dest = fopen("output3.txt", "w")) == NULL) { // 파일 열기 실패 시
        printf("error..."); // 에러 메시지 출력
        return 0; // 프로그램 종료
    }

    // 파일의 끝까지 데이터를 읽고 복사
    while (!feof(fp_src)) { // 파일 끝까지 반복 (비효율적인 방식임)
        fscanf(fp_src, "%s %d %d\n", input, &num1, &num2); // 원본 파일에서 데이터를 읽기
        fprintf(fp_dest, "%s %d %d\n", input, num1, num2); // 대상 파일로 데이터를 쓰기
    }

    // 열었던 파일 닫기
    fclose(fp_src); // 원본 파일 닫기
    fclose(fp_dest); // 대상 파일 닫기

    return 0; // 프로그램 종료
}
