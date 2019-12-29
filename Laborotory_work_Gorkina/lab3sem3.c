#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#define NMAX 3

typedef double mas[NMAX];


void Prosmotr(int argc, char* argv[], int kol) {
    if (argc < 2) {
        printf("Мало параметров\nPress any key");
        _getch();
        return;
    }
    FILE *fb = fopen(argv[1], "rb+");
    if (fb == NULL) {
        printf("Error: не удалось открыть двоичный файл %s\n", argv[1]);
        printf("Press ENTER");
        _getch();
        return;
    }
int kol1 =0;

    mas ker1;
    int nr = 1, nv =1 ;
    int i=0;
    printf("|     Число 1     |     Число 2     |    Число 3     |\n");

      while (!feof(fb) && nr ) {
          nr = fread(ker1, sizeof(mas), 1, fb);
              if (nr > 0) {
              printf("|%17.4lf|%17.4lf|%16.4lf|\n", ker1[0], ker1[1], ker1[2]);
          }
          kol1++;
      }
    fclose(fb);
    printf("Press any key to continue");
    _getch();
    system("Pause");
    return;
}

void Swap1(int argc, char* argv[], int kol) {
    FILE *fb = fopen(argv[1], "rb+");
    if (fb == NULL) {
        printf("Error: не удалось открыть двоичный файл %s\n", argv[1]);
        printf("Press ENTER");
        _getch();
        return;
    }

    mas ker1,ker2;
    int n1, n2;
    printf("Введите номер 1-ой записи: ");
    scanf("%d", &n1);
    printf("Введите номер 2-ой записи: ");
    scanf("%d", &n2);
    if (fseek(fb, (n1-1)*sizeof(mas), SEEK_SET) != 0 )
    {
        printf("Не существует записи под номером n1");
        return;
    };

    if (fseek(fb, (n2-1)*sizeof(mas), SEEK_SET) != 0 )
    {
        printf("Не существует записи под номером n2");
        return ;
    };

    fseek(fb, (n1-1) *sizeof(mas), SEEK_SET);
    fread(&ker1, sizeof(mas), 1, fb);

    fseek(fb, (n2-1)* sizeof(mas), SEEK_SET);
    fread(&ker2, sizeof(mas), 1, fb);

    fseek(fb, (n2-1) * sizeof(mas), SEEK_SET);
    fwrite(&ker1, sizeof(mas), 1, fb);


    fseek(fb, (n1-1) * sizeof(mas), SEEK_SET);
    fwrite(&ker2, sizeof(mas), 1, fb);

    fclose(fb);
    printf("Press any key to continue");

    return;
}
void Create(int argc, char* argv[]) {


    SetConsoleOutputCP(CP_UTF8);
    mas ker1;

    if (argc < 3) {
        printf("Мало параметров\nPress any key");
        _getch();
        return;
    }
    FILE *fin = fopen(argv[2], "rt");
    if (fin == NULL) {
        printf("Error: не удалось открыть файл с \
исходными данными %s\n", argv[2]);
        printf("Press any key "); _getch();
        return;
    }
    FILE *fb = fopen(argv[1], "wb");
    if (fb == NULL) {
        fclose(fin);
        printf("Error: не удалось создать \
двоичный файл %s\n", argv[1]);
        system("Press Enter");

        printf("Press any key"); _getch();
        return;
    }

    int kol =0;
    int  nw =1;
    int i= 0;
    while (!feof(fin)) {

      i =  fscanf(fin, "%lf %lf %lf ", &ker1[0], &ker1[1], &ker1[2]);
      if(i == 3){
            nw = fwrite(ker1, sizeof(mas), 1, fb);
            printf("%d: %4.4lf %4.4lf %4.4lf\n", kol + 1, ker1[0], ker1[1], ker1[2]);

            kol++;}
        }

    if (nw != 1) printf("Error: Ошибка при записи");
    fclose(fin);
    fclose(fb);
    printf("Создан двоичный файл из %d записей \
по %d байт\n", kol, sizeof(mas));
    printf("Press any key to continue");
    _getch();
    return;
}

int main(int argc, char* argv[]){

    FILE* fin;
    char fin_name;

int kol =0;
    fin = NULL;
    char ch;

    SetConsoleOutputCP(CP_UTF8);
    do {
        printf("\nN - создать новый тип.файл;\nD - просмотр;\
 \nC - коррекция;\nE - конец.\nВаш выбор?");
        ch = getchar(); fflush(stdin);
        ch = toupper(ch);
        switch (ch) {
            //----------первая часть: создание двоичного из текстового
            case 'N': Create(argc, argv); break;
                //--------вторая часть:просмотр в двоичном файле--------
            case 'D': Prosmotr(argc, argv,kol); break;
                //-------третья часть: корректировка в двоичном файле ----
            case 'C': Swap1(argc, argv, kol); break;
                //-----------выход----------------------------------------
            case 'E': return 0;
                //--------------------------------------------------------
            default:
                printf("Нет такой команды\nPress any key");
                _getch();
        }
    } while (ch != 'E');
}