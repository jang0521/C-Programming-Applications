#include <stdio.h>
int main() {
    int a,b,id,inventory;
    scanf("%d",&a);
    int store_list[a];
    int sale_list[a];
    int inventory_list[a];
    for (int i =0;i<a;i++){
        scanf("%d ",&store_list[i]);
    }
    for (int i =0;i<a;i++){
        scanf("%d ",&sale_list[i]);
    }
    scanf("%d",&id);
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