#include<stdio.h>
          
int main() {

    int num;
    printf("0�̻� ������..�Է�\n");
    scanf_s("%d", &num);

    switch (num / 10)  //num �� int���̶� �Ǽ��κ��� ����
    {
    case 0:
        printf("0�̻� 10�̸�");
        break;                  //0�̻� 10�̸��̸� break�ϰ� ���
    case 1:
        printf("10�̻�");
        break;                  //10�̻� 20�̸��̸� break�ϰ� ���
    case 2:
        printf("20�̻�");
        break;                  //20�̻� 30�̸��̸� break�ϰ� ���
                      
    default:
        printf("30�̻�");   //�׿� 30���̻�



    }
}