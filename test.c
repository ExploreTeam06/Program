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
    String data[100];
    struct Folder* next;
}Folder;

void printFolder(Folder* f) {
    int i = 0;
    if (f == NULL)
    {
        system("cls");
        printf("������ ������ �ּ���");
        return;
    }
    Folder* p = f->next;
    system("cls");
    printf("--------------------���� �ϴ� ����---------------\n");
    do {
        if (p == NULL) break;
        printf("%d. %s\n", ++i, p->name.str);
        p = p->next;
    } while (p != f->next);
}

void resetFolder(Folder* f) {
    String reset = { "" };
    for (int i = 0; i < 100; i++) f->data[i] = reset;
}

Folder* makeFolder(Folder* f, String name) {
    Folder* newFolder = (Folder*)malloc(sizeof(Folder));
    newFolder->name = name;
    if (f == NULL) {
        f = newFolder;
        f->next = f;
    }
    else {
        newFolder->next = f->next;
        f->next = newFolder;
        f = newFolder;
    }
    return f;
}

void addFile(Folder* f) {
    String file_name = { "" };
    printf("���� �Է� >> ");
    scanf("%s", file_name.str);
    for (int i = 0; i < 100; i++) {
        if (!strlen(f->data[i].str)) {
            f->data[i] = file_name;
            system("cls");  
            printf("�Ϸ�Ǿ����ϴ�\n");
            Sleep(2000);
            return;
        }
    }
}

void searchFolder(Folder* f, String name) {
    if (f == NULL) {
        system("cls");
        printf("������ �������� �ʽ��ϴ�\n");
        Sleep(2000);
        return;
    }
    Folder* p = f->next;
    do {
        if (p == NULL) break;
        if (!strcmp(p->name.str, name.str)) {
            addFile(p);
            break;
        }
        p = p->next;
    } while (p != NULL);
}

void printFile(Folder* f) {
    for (int i = 0; i < 100; i++) {
        if (strlen(f->data[i].str)) {
            printf("%s\n", f->data[i].str);
        }
    }
    Sleep(2000);
}

void searchFile(Folder* f, String name) {
    if (f == NULL) {
        system("cls");
        printf("������ �������� �ʽ��ϴ�\n");
        Sleep(2000);
        return;
    }
    Folder* p = f->next;
    do {
        if (p == NULL) break;
        if (!strcmp(p->name.str, name.str)) {
            printFile(p);
            break;
        }
        p = p->next;
    } while (p != NULL);
}

int menu(int controller) {
    system("cls");
    printf("--------------------���� ���� ���α׷�---------------\n");
    printf("**������ ���� �������� ������ ���ư��� �ʽ��ϴ�**    Made by �̵���, ���켺\n");
    printf("\t1.���� ����\n");
    printf("\t2.���� ����\n");
    printf("\t3.���� ����\n");
    printf("\t4.���� ����\n");
    printf("\t5.���� ã��\n");
    printf("\t6.���� ����\n");
    printf("\t7.���α׷� ����\n");
    printf("�Է� >> ");
    scanf("%d", &controller);
    return controller;
}

String folderName(String folder_name) {
    printf("���� �̸��� �Է��ϼ��� >> ");
    scanf("%s", folder_name.str);
    return folder_name;
}

int main() {
    system("color a");
    Folder* Folder = NULL;
    int appController = 1;
    int controller = 0;
    String folder_name = { "" };
    while (appController)
    {
        controller = menu(controller);
        switch (controller)
        {
        case 1:
            system("cls");
            printf("--------------------���� ����---------------\n");
            folder_name = folderName(folder_name);
            Folder = makeFolder(Folder, folder_name);
            resetFolder(Folder);
            break;
        case 2:
            system("cls");
            printf("--------------------���� ����---------------\n");
            printFolder(Folder);
            Sleep(2000);
            break;
        case 4:
            system("cls");
            printf("--------------------���� ����---------------\n");
            printFolder(Folder);
            folder_name = folderName(folder_name);
            searchFolder(Folder, folder_name);
            break;
        case 6:
            system("cls");
            printf("--------------------���� ����---------------\n");
            printFolder(Folder);
            folder_name = folderName(folder_name);
            searchFile(Folder, folder_name);
            break;
        case 7:
            appController = 0;
            break;
        default:
            system("cls");
            printf("�߸��� �����Դϴ�\n");
            Sleep(2000);
            break;
        }
    }
    
    return 0;
}