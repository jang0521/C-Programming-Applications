#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int Quantity_list[SIZE];
int Sell_list[SIZE];
int Sub_Sell_list[SIZE];

void Quantity1() {
    printf("전체 상품 입고량을 입력해주십시오\n");
    for (int i = 0; i < SIZE; i++) {
        scanf_s("%d", &Quantity_list[i]);
    }
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", Quantity_list[i]);
    }
    printf("\n");
}

void Quantity2() {
    printf("원하는 상품을 선택한 후, 입고량을 입력해주십시오\n");
    int quantity_num = 0;
    scanf_s("%d", &quantity_num);
    if (quantity_num < 0 || quantity_num >= SIZE) {
        printf("유효하지 않은 상품 번호입니다.\n");
        return;
    }
    printf("입고량을 입력해주십시오\n");
    scanf_s("%d", &Quantity_list[quantity_num]);
}

void Selling1() {
    printf("전체 상품 판매수량을 입력해주세요\n");
    for (int i = 0; i < SIZE; i++) {
        scanf_s("%d", &Sell_list[i]);
        if (Sell_list[i] > Quantity_list[i]) {
            printf("판매량이 재고보다 많습니다. 조정해주세요.\n");
            Sell_list[i] = Quantity_list[i];
        }
        Quantity_list[i] -= Sell_list[i];
    }
}

void Selling2() {
    printf("원하는 상품을 선택한 후, 판매량을 입력해주십시오\n");
    int sell_num = 0;
    scanf_s("%d", &sell_num);
    if (sell_num < 0 || sell_num >= SIZE) {
        printf("유효하지 않은 상품 번호입니다.\n");
        return;
    }
    printf("판매량을 입력해주십시오\n");
    scanf_s("%d", &Sell_list[sell_num]);
    if (Sell_list[sell_num] > Quantity_list[sell_num]) {
        printf("판매량이 재고보다 많습니다. 조정해주세요.\n");
        Sell_list[sell_num] = Quantity_list[sell_num];
    }
    Quantity_list[sell_num] -= Sell_list[sell_num];
}

void Cur_Situation() {
    int Sell_All = 0;
    int Quan_All = 0;
    int MaxValue = Sell_list[0];
    int MaxValue_i = 0;
    int MiniValue = Sell_list[0];
    int MiniValue_i = 0;

    // Sub_Sell_list 배열 복사
    for (int i = 0; i < SIZE; i++) {
        Sub_Sell_list[i] = Sell_list[i];
    }

    printf("재고수량을 출력합니다\n");
    printf("재고 수량: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", Quantity_list[i]);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        Sell_All += Sell_list[i];
        Quan_All += Quantity_list[i] + Sell_list[i]; // 총 입고량 계산
        if (Sell_list[i] > MaxValue) {
            MaxValue = Sell_list[i];
            MaxValue_i = i;
        }
        if (Sell_list[i] < MiniValue) {
            MiniValue = Sell_list[i];
            MiniValue_i = i;
        }
    }

    double sell_rate = ((double)Sell_All / Quan_All) * 100;
    printf("총 판매량: %d (판매율 %.2f%%)\n", Sell_All, sell_rate);
    printf("가장 많이 판매된 상품: %d (판매량 %d)\n", MaxValue_i, MaxValue);
    printf("가장 적게 판매된 상품: %d (판매량 %d)\n", MiniValue_i, MiniValue);

    for (int i = 0; i < SIZE; i++) {
        if (Quantity_list[i] <= 2) {
            printf("재고 부족 ID %d 남은 재고 %d\n", i, Quantity_list[i]);
        }
    }
}

int main(void) {
    while (1) {
        int menu_choice = 0; // 메뉴 선택 변수
        printf("원하는 메뉴를 선택하세요 (1.입고 2.판매 3.상품현황 4.종료)\n");
        scanf_s("%d", &menu_choice);

        if (menu_choice == 1) {
            printf("입고수량 입력: 전체 상품 압고수량 입력 1, 개별 상품 입력 2를 선택\n");
            scanf_s("%d", &menu_choice);
            if (menu_choice == 1) {
                Quantity1();
            }
            else if (menu_choice == 2) {
                Quantity2();
            }
        }
        else if (menu_choice == 2) {
            printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n");
            scanf_s("%d", &menu_choice);
            if (menu_choice == 1) {
                Selling1();
            }
            else if (menu_choice == 2) {
                Selling2();
            }
        }
        else if (menu_choice == 3) {
            Cur_Situation();
        }
        else if (menu_choice == 4) {
            printf("프로그램을 종료합니다.\n");
            exit(0);
        }
        else {
            printf("유효하지 않은 메뉴입니다.\n");
        }
    }
}
