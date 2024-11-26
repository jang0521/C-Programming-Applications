#include <stdio.h>
#include <string.h>

#define SIZE 5

// 상품 구조체 정의
typedef struct {
    int product_id;         
    char name[50];        
    int price;             
    int stock;         
    int sales;         
    int total_sales;      
} Product;

Product products[SIZE];
int product_count = 0;

int find_product(int product_id) {
    for (int i = 0; i < product_count; i++) {
        if (products[i].product_id == product_id) {
            return i;
        }
    }
    return -1;
}

void add_stock() {
    if (product_count >= SIZE) {
        printf("상품 개수가 최대치를 초과했습니다.\n");
        return;
    }

    int product_id, stock, price;
    char name[50];

    printf("상품ID : ");
    scanf("%d", &product_id);

    int index = find_product(product_id);
    if (index != -1) {
        // 기존 상품 업데이트
        printf("상품명 : ");
        scanf("%s", name);  // 업데이트를 위해 입력받음
        printf("입고량 : ");
        scanf("%d", &stock);
        printf("판매가격 : ");
        scanf("%d", &price);

        products[index].stock += stock;
        products[index].price = price;  // 가격 갱신
        printf("상품 정보가 업데이트되었습니다.\n");
    } else {
        // 새로운 상품 추가
        printf("상품명 : ");
        scanf("%s", name);
        printf("입고량 : ");
        scanf("%d", &stock);
        printf("판매가격 : ");
        scanf("%d", &price);

        Product new_product = {product_id, "", price, stock, 0, 0};
        strcpy(new_product.name, name);
        products[product_count++] = new_product;
        printf("새로운 상품을 추가했습니다.\n");
    }
}

void sell_product() {
    int product_id, quantity;

    printf("상품ID : ");
    scanf("%d", &product_id);

    int index = find_product(product_id);
    if (index == -1) {
        printf("해당 상품이 없습니다.\n");
        return;
    }

    printf("판매량 : ");
    scanf("%d", &quantity);

    if (quantity > products[index].stock) {
        printf("재고가 부족합니다.\n");
    } else {
        products[index].stock -= quantity;
        products[index].sales + = quantity;
        products[index].total_sales += quantity * products[index].price;
        printf("판매 완료.\n");
    }
}
void view_product() {
    int product_id;

    printf("상품ID : ");
    scanf("%d", &product_id);

    int index = find_product(product_id);
    if (index == -1) {
        printf("해당 상품이 존재하지 않습니다.\n");
        return;
    }

    Product p = products[index];
    printf("ID: %d, 이름: %s, 가격: %d, 재고: %d, 판매량: %d, 총 판매금액: %d\n",
           p.product_id, p.name, p.price, p.stock, p.sales, p.total_sales);
}
void view_all_products() {
    if (product_count == 0) {
        printf("등록된 상품이 없습니다.\n");
        return;
    }

    for (int i = 0; i < product_count; i++) {
        Product p = products[i];
        printf("ID: %d, 이름: %s, 가격: %d, 재고: %d, 판매량: %d, 총 판매금액: %d\n",
               p.product_id, p.name, p.price, p.stock, p.sales, p.total_sales);
    }
}
int main() {
    int choice;

    while (1) {
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료)\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                sell_product();
                break;
            case 3:
                view_product();
                break;
            case 4:
                view_all_products();
                break;
            case 5:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}
