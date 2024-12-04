#include <stdio.h>   // 표준 입출력 함수 사용을 위해 포함
#include <time.h>    // 시간 관련 함수 사용을 위해 포함
#include "report.h"  // 사용자가 정의한 헤더 파일, 함수 또는 데이터 포함 (구체적 정의는 없는 상태)
#include "wday.h"    // 사용자가 정의한 헤더 파일, 함수 또는 데이터 포함 (구체적 정의는 없는 상태)

// main 함수: 프로그램의 진입점
int main(int argc, char* argv[]) {
    // 명령줄 인자의 개수와 내용 확인
    // argc는 명령줄에서 입력받은 인자의 개수, argv는 각 인자의 문자열 배열
    // 프로그램 실행 시 필요한 세 가지 인자를 받아 처리

    week2(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    // argv 배열의 문자열을 정수로 변환하여 `week2` 함수에 전달
    // `week2`는 "wday.h" 헤더에 정의된 함수로, 세 개의 정수를 인자로 받음
    // 예: 프로그램 실행 시 `program 2024 12 25`라면
    //     argv[1] = "2024", argv[2] = "12", argv[3] = "25"
    //     atoi 함수로 각각 2024, 12, 25로 변환되어 `week2`에 전달

    return 0; // 프로그램 정상 종료
}
