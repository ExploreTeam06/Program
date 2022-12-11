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

void printFolder(Folder* f) {
    if (f == NULL)
    {
        system("cls");
        printf("폴더를 생성해 주세요");
        Sleep(3000);
        return;
    }
    Folder* p = f->next;
    system("cls");
    do {
        if (p == NULL) break;
        printf("%s\n", p->name.str);
        p = p->next;
    } while (p != f->next);
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

void addFolder(Folder* f) {
    String file_name;
    system("cls");
    printf("파일 입력 >> ");
    scanf("%s", file_name);
    for (int i = 0; i < 100; i++) {
        if (f->data[i].str == NULL) {
            f->data[i] = file_name;
            system("cls");
            printf("완료되었습니다\n");
            Sleep(2000);
            return;
        }
    }
}

void searchFolder(Folder* f, String name) {
    if (f == NULL) {
        system("cls");
        printf("폴더가 존재하지 않습니다\n");
        Sleep(2000);
        return;
    }
    Folder* p = f->next;
    do {
        if (p == NULL) break;
        if (!strcmp(p->name.str, name.str)) {
            addFile(p);
        }
        p = p->next;
    } while (p != NULL);
}

int main() {
    system("color 2");
    Folder* Folder = NULL;
    int appController = 1;
    int controller = 0;
    String folder_name;
    while (appController)
    {
        system("cls");
        printf("파일 정리 프로그램\n");
        printf("1.설명서\n");
        printf("2.폴더생성\n");
        printf("3.폴더보기\n");
        printf("4.폴더삭제\n");
        printf("5.파일 삽입\n");
        printf("6.파일 찾기\n");
        printf("7.프로그램 종료\n");
        printf("입력 >> ");
        scanf("%d", &controller);
        switch (controller)
        {
        case 1:
            system("cls");
            printf("폴더를 먼저 생성하지 않으면 돌아가지 않습니다\n");
            scanf("%d", &controller);
            break;
        case 2:
            system("cls");
            printf("폴더의 이름을 입력하세요\n");
            scanf("%s", folder_name.str);
            Folder = makeFolder(Folder, folder_name);
            break;
        case 3:
            printFolder(Folder);
            Sleep(2000);
            break;
        case 4:
            scanf("%s", folder_name);
            searchFolder(Folder, folder_name);
            break;
        case 7:
            appController = 0;
            break;
        default:
            system("cls");
            printf("잘못된 선택입니다\n");
            appController = 0;
            break;
        }
    }

}