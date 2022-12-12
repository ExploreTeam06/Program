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

int isEmpty(Folder* f) {
    if (f == NULL) return 1;
    return 0;
}

void printFolder(Folder* f) {
    int i = 0;
    if (isEmpty(f)) {
        system("cls");
        printf("������ �������� �ʽ��ϴ�\n");
        Sleep(2000);
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
    if (f == NULL || f->next == NULL) {
        f = newFolder;
        f->next = f;
    }
    else {
        Folder* p = f->next;
        while (p != NULL) {
            if (!strcmp(p->name.str, name.str)) {
                return f;
            }
            p = p->next;
        }
        newFolder->next = f->next;
        f->next = newFolder;
        f = newFolder;
    }
    return f;
}

void fileSort(Folder* f) {
    int check = 0;
    String checkdata;
    for (int i = 0; i < 99; i++) {
        check = strcmp(f->data[i].str, f->data[i + 1].str);
        if (check)  {
            strcpy(checkdata.str, f->data[i + 1].str);
            strcpy(f->data[i + 1].str, f->data[i].str);
            strcpy(f->data[i].str, checkdata.str);
        }
        else if (check == 0) {
            deleteFile();
        }
    }
}

void addFile(Folder* f) {
    String file_name = { "" };
    printf("���� �Է� >> ");
    scanf("%s", file_name.str);
    for (int i = 0; i < 100; i++) {
        if (!strcmp(f->data[i].str, file_name.str)) {
            return;
        }
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
    if (isEmpty(f)) {
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
    int j = 0;
    if (isEmpty(f)) {
        system("cls");
        printf("������ �������� �ʽ��ϴ�\n");
        Sleep(2000);
        return;
    }
    for (int i = 0; i < 100; i++) {
        if (strlen(f->data[i].str)) {
            printf("%d. %s\n", ++j, f->data[i].str);
        }
    }
    Sleep(2000);
}

void searchFile(Folder* f, String name) {
    if (isEmpty(f)) {
        system("cls");
        printf("������ �������� �ʽ��ϴ�\n");
        Sleep(2000);
        return;
    }
    Folder* p = f->next;
    do {
        if (p == NULL) break;
        if (!strcmp(p->name.str, name.str)) {
            fileSort(p);
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
    printf("\t5.���� ����\n");
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

void removeFolder(Folder* f, String name) {
    Folder* p = f->next;
    if (!strcmp(p->name.str, f->name.str)) {
        f->next = NULL;
        f = NULL;
    }
    else {
        while (p != NULL) {
            if (!strcmp(p->next->name.str, name.str)) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
    }
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
        case 3:
            system("cls");
            printf("--------------------���� ����---------------\n");
            printFolder(Folder);
            if (isEmpty(Folder)) break;
            folder_name = folderName(folder_name);
            removeFolder(Folder, folder_name);
            break;
        case 4:
            system("cls");
            printf("--------------------���� ����---------------\n");
            printFolder(Folder);
            if (isEmpty(Folder)) break;
            folder_name = folderName(folder_name);  
            searchFolder(Folder, folder_name);
            break;
        case 5:
            system("cls");
            printf("--------------------���� ����---------------\n");
            printFolder(Folder);
            if (isEmpty(Folder)) break;
            folder_name = folderName(folder_name);
            searchFile(Folder, folder_name);
            break;
        case 6:

        case 7:
            appController = 0;
            break;
        default:
            system("cls");
            printf("--------------------���� ���� ���α׷�---------------\n");
            printf("�߸��� �����Դϴ�\n");
            Sleep(2000);
            break;
        }
    }
    
    return 0;
}