#ifndef _REPORT_H // 헤더 파일이 중복 포함되지 않도록 방지
#define _REPORT_H

#include <stdio.h>   // 표준 입출력 함수 사용을 위해 포함
#include <time.h>    // 시간 및 날짜 관련 함수 사용을 위해 포함

// 특정 날짜와 오늘 날짜의 차이를 계산하는 함수
int week2(int year, int month, int day) {
    time_t current;           // 현재 시간을 저장할 변수
    time_t userday;           // 입력된 날짜를 저장할 변수
    int diff;                 // 날짜 차이를 저장할 변수
    struct tm* timeinfo;      // 날짜와 시간을 구조체 형태로 저장

    current = time(NULL);     // 현재 시간을 얻어 `current`에 저장
    timeinfo = localtime(&current); // `current`를 현지 시간대로 변환해 구조체로 저장

    timeinfo->tm_year = year - 1900; // 연도는 1900 기준으로 계산되므로 보정
    timeinfo->tm_mon = month - 1;    // 월은 0부터 시작하므로 1을 빼줌
    timeinfo->tm_mday = day;         // 입력받은 일자를 설정

    userday = mktime(timeinfo);      // 설정된 `timeinfo`를 time_t 형식으로 변환

    diff = difftime(userday, current); // 입력 날짜와 현재 날짜의 차이를 초 단위로 계산

    diff = diff / (60 * 60 * 24); // 초 단위를 일 단위로 변환
    printf("%d %d %d->오늘로부터 %d일 후(-전) 입니다.\n", year, month, day, diff);
    // 결과를 출력 (입력 날짜와 오늘 사이의 일 수를 표시)

    return 0; // 함수 종료
}

#endif // 헤더 파일의 끝
