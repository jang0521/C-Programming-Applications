#include <stdio.h>
int main() {
    int a,b,id,inventory;
    while (1){
        scanf("%d",&a);
        if (a > 100){
            printf(" too high value.\n");
        }
        else if (a<1){
            printf("too low value.\n");
        }
        else{
            break;
        }
    }
    int store_list[a];
    int sale_list[a];
    int inventory_list[a];
    for (int i =0;i<a;i++){
        scanf("%d",&store_list[i]);
    }
    for (int i =0;i<a;i++){
        scanf("%d",&sale_list[i]);
    }
    while (1){
        scanf("%d",&id);
        if (id > 100){
            printf(" too high value.\n");
        }
        else if (id>a){
            printf("too high value.\n");
        }
        else if (id < 0){
            printf("too low value.\n");
        }
        else{
            break;
        }
    }
    inventory= store_list[id]-sale_list[id];
    printf("%d\n",inventory);
    for(int i = 0;i<a;i++){
        inventory_list[i]=store_list[i]-sale_list[i];
    }
    for(int i = 0;i<a;i++){
        printf("%d",inventory_list[i]);
    }
    return 0;
}