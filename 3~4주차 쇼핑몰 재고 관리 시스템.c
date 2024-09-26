#include <stdio.h>
#define SIZE 5
store_list[SIZE];
sale_list[SIZE];
inventory_list[SIZE];
void store_menu(*store_menu_list){
    for (int i = 0; i < SIZE; i++){
        
    }
}
void sale_menu1(*sale1_menu_list){
    for( int i = 0; i < SIZE; i++ ){
        scanf("%d",&sale1_menu_list[i]);
    }
}
void sale_menu2(*sale2_menu_list){
    int a = 0;
    printf("상품 ID: ");
    scanf("%d",&a);
    printf("입고 수량: ");
    scanf("%d",&store2_menu_list[a])
}
void inventory_menu(*inventory_menu_list){
    printf("상품 현황: ")
    for (int i = 0; i<SIZE;i++){
        inventory_menu_list[i]=store_menu_list[i]-sale_menu_list[i];
    }
    printf("%d",inventory_list[i]);
}
int main(){
    int menu_choice;
    while (1){
        printf("[쇼핑몰 재고 관리 프로그램]\n원하는 메뉴를 선택하세요.(1.입고 2.판매 3.상품현황 4.종료)");
        scanf("%d",&menu_choice);
        
        if (menu_choice==1){
        store_menu(store_list);
        menu_choice=0;
        }
        
        else if (menu_choice==2){
            printf("판매수량 입력:전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n")
            sale_list();
            menu_choice=0;
            scanf("%d",&menu_choice);
            if (menu_choice == 1){
                sale_menu1(sale_list);
            }
            else if(menu_choice == 2){
                sale_menu2(sale_list);
            }
        }
    
        else if (menu_choice==3){
            inventory_menu(store_list,sale_list,inventory_list)
        }
    }
    
    
}
