#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
#define NAME_LENGTH 50 // ��ǰ�� ���� ����

int Quantity_list[SIZE];
int Sell_list[SIZE];
int Sub_Sell_list[SIZE];
char Quantitiy_list_name[SIZE][NAME_LENGTH]; // ��ǰ�� �迭

void Quantity1() {
    printf("��ü ��ǰ �԰��� �Է����ֽʽÿ�\n");
    for (int i = 0; i < SIZE; i++) {
        scanf_s("%d", &Quantity_list[i]);
    }
    printf("�԰�: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", Quantity_list[i]);
    }
    printf("\n");
}

void Quantity2() {
    printf("���ϴ� ��ǰ�� ������ ��, �԰��� �Է����ֽʽÿ�\n");
    int quantity_num = 0;
    scanf_s("%d", &quantity_num);
    if (quantity_num < 0 || quantity_num >= SIZE) {
        printf("��ȿ���� ���� ��ǰ ��ȣ�Դϴ�.\n");
        return;
    }
    printf("�԰��� �Է����ֽʽÿ�\n");
    scanf_s("%d", &Quantity_list[quantity_num]);
}

void Selling1() {
    printf("��ü ��ǰ �Ǹż����� �Է����ּ���\n");
    for (int i = 0; i < SIZE; i++) {
        scanf_s("%d", &Sell_list[i]);
        if (Sell_list[i] > Quantity_list[i]) {
            printf("�Ǹŷ��� ����� �����ϴ�.\n");
            Sell_list[i] = Quantity_list[i];
        }
        Quantity_list[i] -= Sell_list[i];
    }
}

void Selling2() {
    printf("���ϴ� ��ǰ�� ������ ��, �Ǹŷ��� �Է����ֽʽÿ�\n");
    int sell_num = 0;
    scanf_s("%d", &sell_num);
    if (sell_num < 0 || sell_num >= SIZE) {
        printf("��ȿ���� ���� ��ǰ ��ȣ�Դϴ�.\n");
        return;
    }
    printf("�Ǹŷ��� �Է����ֽʽÿ�\n");
    scanf_s("%d", &Sell_list[sell_num]);
    if (Sell_list[sell_num] > Quantity_list[sell_num]) {
        printf("�Ǹŷ��� ����� �����ϴ�. �������ּ���.\n");
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

    // Sub_Sell_list �迭 ����
    for (int i = 0; i < SIZE; i++) {
        Sub_Sell_list[i] = Sell_list[i];
    }

    printf("�Ǹ� ��Ȳ�� ����մϴ�\n");
    for (int i = 0; i < SIZE; i++) {
        printf("ID%d, ��ǰ��: %s, �Ǹŷ�: %d\n", i, Quantitiy_list_name[i], Sell_list[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        Sell_All += Sell_list[i];
        Quan_All += Quantity_list[i] + Sell_list[i]; // �� �԰� ���
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
    printf("�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", Sell_All, sell_rate);
    printf("���� ���� �Ǹŵ� ��ǰ: ID%d, ��ǰ��: %s, �Ǹŷ�: %d\n",
        MaxValue_i, Quantitiy_list_name[MaxValue_i], MaxValue);
    printf("���� ���� �Ǹŵ� ��ǰ: ID%d, ��ǰ��: %s, �Ǹŷ�: %d\n",
        MiniValue_i, Quantitiy_list_name[MiniValue_i], MiniValue);

    for (int i = 0; i < SIZE; i++) {
        if (Quantity_list[i] <= 2) {
            printf("��� ���� ID%d, ��ǰ��: %s, ���� ���: %d\n",
                i, Quantitiy_list_name[i], Quantity_list[i]);
        }
    }
}

void Enter_Name() {
    printf("�� ��ǰ�� �̸��� �Է��ϼ���:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("ID%d ��ǰ��: ", i);
        scanf_s(" %[^\n]", Quantitiy_list_name[i], NAME_LENGTH);
    }
    printf("��ǰ���� ���������� ����Ǿ����ϴ�.\n");
}

int main(void) {
    while (1) {
        int menu_choice = 0; // �޴� ���� ����
        printf("���ϴ� �޴��� �����ϼ��� (1.�԰� 2.�Ǹ� 3.��ǰ��Ȳ 4.��ǰ���Է� 5.����)\n");
        scanf_s("%d", &menu_choice);

        if (menu_choice == 1) {
            printf("�԰���� �Է�: ��ü ��ǰ �а���� �Է� 1, ���� ��ǰ �Է� 2�� ����\n");
            scanf_s("%d", &menu_choice);
            if (menu_choice == 1) {
                Quantity1();
            }
            else if (menu_choice == 2) {
                Quantity2();
            }
        }
        else if (menu_choice == 2) {
            printf("�Ǹż��� �Է�: ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Է� 2�� ����\n");
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
            Enter_Name();
        }
        else if (menu_choice == 5) {
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        }
        else {
            printf("��ȿ���� ���� �޴��Դϴ�.\n");
        }
    }
}
