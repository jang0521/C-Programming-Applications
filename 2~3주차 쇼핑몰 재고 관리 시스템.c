#include <stdio.h>
#define SIZE 5
int main() {
    int product_number = 1000;
    scanf("%d", &product_number);
    int id[SIZE];
    int store_list[SIZE];
    int sell_list[SIZE];
    int inventory_list[SIZE];
    int all_selling = 0;
    double all_selling_percentage = 0.0;
    for (int i = 0; i < product_number; i++) {
        id[i] = i + 1;
        scanf("%d", &store_list[i]);
    }
    for (int i = 0; i < product_number; i++) {
        scanf("%d", &sell_list[i]);
        inventory_list[i] = store_list[i] - sell_list[i];
    }
    printf("\n재고수량 : ");
    for (int i = 0; i < product_number; i++) {
        printf("%d ", inventory_list[i]);
    }
    for (int i = 0; i < product_number; i++) {
        all_selling += sell_list[i];
        all_selling_percentage += ((double)sell_list[i] / store_list[i]) * 100;
    }
    all_selling_percentage = all_selling_percentage / product_number;
    printf("\n총 판매량 : %d (판매율 %.2f%%)\n", all_selling, all_selling_percentage);

    int maximum_sale_ID = id[0];
    int minimum_sale_ID = id[0];
    int maximum_sale = sell_list[0];
    int minimum_sale = sell_list[0];

    for (int i = 1; i < product_number; i++) {
        if (sell_list[i] > maximum_sale) {
            maximum_sale = sell_list[i];
            maximum_sale_ID = id[i];
        }
        if (sell_list[i] < minimum_sale) {
            minimum_sale = sell_list[i];
            minimum_sale_ID = id[i];
        }
    }
    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maximum_sale_ID, maximum_sale);
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minimum_sale_ID, minimum_sale);
    for (int i = 0; i < product_number; i++) {
        if (inventory_list[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", id[i], inventory_list[i]);
        }
    }

    return 0;
}