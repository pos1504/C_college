#include<stdio.h>

int main() {

    int score[3] = { 0 }; 
    int avg = 0;
    for (int i = 0; i < 3; i++)
    {
        scanf_s("%d", &score[i]);  //���� ���� ���� ���� �ޱ� 
        avg += score[i];        //���� ���� ���� ���� �� ���ϱ�
    }
    avg = avg / 3; //������ ��� 
    printf("����� ���: %d\n", avg);

    switch (avg / 10)  //avg �� int���̶� �Ǽ��κ��� ����
    {
    case 10:
        printf("A");
        break;                  //�����̸� �극��ũ �ϰ� ���!
    case 9:
        printf("A");
        break;                  //90���̻��̸� �극��ũ �ϰ� ���!
    case 8:
        printf("B");
        break;                  //80���̻��̸� �극��ũ �ϰ� ���!
    case 7:
        printf("C");
        break;                  //70���̻��̸� �극��ũ �ϰ� ���!
    case 5:
        printf("D");
        break;                  //50���̻��̸� �극��ũ �ϰ� ���!
    default:
        printf("F");            
 
     

    }
}