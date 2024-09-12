#include <stdio.h>

int main() {
    int a = 0;
    int id = 0;
    int inventory = 0;
    int complete_sale_value = 0;
    int all_inventory = 0;
    int all_sale = 0;
    double sale_percentage = 0;

    while (1) {
        printf("Enter the number of items (1-100): ");
        scanf_s("%d", &a);
        if (a > 100) {
            printf("Value too high. Enter a value between 1 and 100.\n");
        }
        else if (a < 1) {
            printf("Value too low. Enter a value between 1 and 100.\n");
        }
        else {
            break;
        }
    }

    int store_list[100];
    int sale_list[100];
    int inventory_list[100];

    printf("Enter store list values:\n");
    for (int i = 0; i < a; i++) {
        scanf_s("%d", &store_list[i]);
    }

    printf("Enter sale list values:\n");
    for (int i = 0; i < a; i++) {
        scanf_s("%d", &sale_list[i]);
    }


    inventory = store_list[id] - sale_list[id];
    for (int i = 0; i < a; i++) {
        inventory_list[i] = store_list[i] - sale_list[i];
    }


    printf("재고 수량:\n");
    for (int i = 0; i < a; i++) {
        printf("%d ", inventory_list[i]);
    }
    printf("\n");
    for (int i = 0; i < a; i++) {
        complete_sale_value += sale_list[i];
    }
    for (int i = 0; i < a; i++) {
        all_inventory += inventory_list[i];
        all_sale += sale_list[i];
    }
    sale_percentage = (all_sale / all_inventory) * 100;
    printf("총판매량:%d (판매율%.2lf %%\n",complete_sale_value,sale_percentage);


    //최대 판매량 및 최소 판매량 계산
    for (int i = 0; i < a; i++) {
        int temp = 0;
        int id_temp = 0;
        temp = inventory_list[i] - sale_list[i];
        if (temp < inventory_list[i + 1] - sale_list[i + 1]) {
            temp = inventory_list[i + 1];
            id_temp = i + 1;
        }
        printf("가장 많이 판매 된 상품: ID %d,판매량 %d", id_temp, temp);
    for (int i = 0; i < a; i++) {
        int temp = 0;
        int id_temp = 0;
        temp = inventory_list[i] - sale_list[i];
        if (temp > inventory_list[i + 1] - sale_list[i + 1]) {
            temp = inventory_list[i + 1];
            id_temp = i + 1;
        }
        printf("가장 적게 판매 된 상품: ID %d,판매량 %d", id_temp, temp);
        }

    





    //재고 부족 확인
    for (int i = 0; i < a; i++) { 
        if (inventory_list[i] <= 2) {
            printf("상품 ID %d:재고부족(%d)\n", i, inventory_list[i]);
        }
        
    }
    return 0;
}
