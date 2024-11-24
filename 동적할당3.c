#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
}POINT;

POINT* makePoint(void){
    POINT* p =(POINT*)malloc(sizeof(POINT));
    p->x = rand() % 100;
    p->y = rand() % 100;
    return p;
}
void printPoint(POINT* p[],int size){
    for (int i =0;i<size;i++){
        printf("x:%d,y:%d\n",p[i]->x,p[i]->y);
    }
}
void freePoints(POINT* p[],int size){
    for(int i = 0; i<size;i++){
        free(p[i]);
    }
}
int main(){
    do{
        menu = inputMenu();
        if (menu==1){
            points[count] = makePoint();
            count++;
            printf("잘 만들었습니다.\n");
        }
        else if(menu==2){
            printPoint(points,count);
        }
        else if(menu==3){
            freePoints(points,count);
            printf("프로그램을 종료합니다.\n");
        }
    }while(menu>0);
    
    return 0;
}