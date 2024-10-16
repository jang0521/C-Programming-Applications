#include <stdio.h>

int main() {
    char input[200] = "";      // 입력받은 문자열을 저장할 배열 (최대 200자)
    int count[26] = { 0 };     // 알파벳 소문자 각 글자의 출현 횟수를 저장할 배열
    int ch;                    // 입력 문자를 임시로 저장할 변수
    int i = 0;                 // 배열 인덱스에 사용될 변수

    // EOF (End Of File)까지 한 문자씩 입력받아 input 배열에 저장
    while ((ch = getchar()) != EOF) {
        input[i++] = ch;       // 입력받은 문자를 배열에 저장하고 인덱스 증가
    }

    i = 0;  // 다시 처음부터 읽기 위해 인덱스를 0으로 초기화

    // input 배열에 저장된 문자열에서 알파벳 소문자의 출현 횟수를 계산
    while (input[i] != '\0') {  // null 문자 ('\0')가 나올 때까지 반복
        if (input[i] >= 'a' && input[i] <= 'z') {  // 소문자 알파벳 범위 검사
            count[input[i] - 'a']++;  // 해당 문자의 출현 횟수를 증가
        }
        i++;  // 다음 문자로 이동
    }

    // 입력된 문자열 출력
    printf("입력 문자열: %s\n", input);

    // 각 알파벳의 출현 횟수를 출력
    for (int i = 0; i < 26; i++) {
        printf("%c 출현회수 : %d\n", 'a' + i, count[i]);  // a부터 z까지 출력
    }

    return 0;  // 프로그램 종료
}