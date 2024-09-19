#include <stdio.h>
#define SIZE 5
store_list[SIZE];
sale_list[SIZE];
inventory[SIZE];
void store_menu(*store_menu_list){
    for (int i = 0; i < SIZE < i++){
        
    }
}
void sale_menu1(*sale1_menu_list){
    for (int i = 0; i < SIZE < i++){
        
    }
}
void sale_menu2(*sale2_menu_list){
    for (int i = 0; i < SIZE < i++){
        
    }
}
void inventory_menu(*inventory_menu_list){
    for (int i = 0; i < SIZE < i++){
        
    }
}
int main(){
    int menu_choice;
    while (1){
    printf("[쇼핑몰 재고 관리 프로그램]\n원하는 메뉴를 선택하세요.(1.입고 2.판매 3.상품현황 4.종료)");
    scanf("%d",&menu_choice);
    }
    
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
            
        }
        else if(menu_choice == 2){
            
        }
    }
    
    else if (menu_choice==3){
        
    }
    
    
}