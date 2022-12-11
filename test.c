#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
typedef struct String
{
    char str[100];
}String;

typedef struct Folder 
{
    String name;
    struct String data[100];
    struct Folder* next;
}Folder;
void printFolder(Folder* f){
    if(f==NULL)
    {
        system("cls");
        printf("������ ������ �ּ���");
        Sleep(5000);
        return;
    }
    Folder *p=f->next;
    system("cls");
    do{
        if(p==NULL) break;
        printf("%s\n",f->name.str);
        p=p->next;
    }while(p!=f->next);
    Sleep(5000); 
}

Folder* makeFolder(Folder* f,String name){
    Folder* newFolder =(Folder*)malloc(sizeof(Folder));
    newFolder->name=name;
    if(f==NULL){
        f=newFolder;
        f->next=f;
    }
    else{
        newFolder->next=f->next->next;
        f->next=newFolder;
        f=newFolder;
    }
    return f;
}
int main(){
    system("color 2");
    Folder* Folder=NULL;
    int appController=1;
    int controller=0;
    String folder_name;
    while (appController)
    {
        system("cls");
        printf("���� ���� ���α׷�\n");
        printf("1.������\n");
        printf("2.��������\n");
        printf("3.��������\n");
        printf("4.��������\n");
        printf("5.���� ����\n");
        printf("6.���� ã��\n");
        printf("7.���α׷� ����\n");
        scanf("%d",&controller);
        switch (controller)
        {
        case 1:
            system("cls");
            printf("������ ���� �������� ������ ���ư��� �ʽ��ϴ�\n");
            scanf("%d",&controller);
            break;
        case 2:
            system("cls");
            printf("������ �̸��� �Է��ϼ���\n");
            scanf("%s",folder_name.str);
            Folder=makeFolder(Folder,folder_name);
        break;
        case 3:
            printFolder(Folder);
        break;
        default:
            system("cls");
            printf("�߸��� �����Դϴ�\n");
            appController=0;
            break;
        }
    }
    
}