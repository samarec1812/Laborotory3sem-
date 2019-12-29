#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
#define NMAX 10
using namespace std; 


void Zapolnenie(FILE *fin, int **&mas1, int &m, int &n) {
	//ввод размеров матрицы
	fscanf(fin, "%d", &m);
	fscanf(fin, "%d", &n);
	//заполнение
	mas1 = new int*[m]; 
	for (int i = 0; i < m; ++i) mas1[i] = new int[n]; 
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			fscanf(fin, "%d", &mas1[i][j]);
		}
	}

	return;
}
void SredArifm(int **mas1, int m, int n, double *sr) {
	
	
	for (int i = 0; i < m; ++i) {
		sr[i] = 0;
		for (int j = 0; j < n; ++j) {
			if (mas1[i][j] > 0) sr[i] += mas1[i][j];
		}
	}

	return;
}
bool Proverka(int **mas1, int m, int n) {
	bool f1 = false;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mas1[i][j] == 0) { f1 = true; }
		}
	}
	return f1;
}
void VivodMatriciDin(FILE *fout, int **mas1, int m, int n) {

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			fprintf(fout, "%d ", mas1[i][j]);
		}
		fprintf(fout, "\n");
	}
	fprintf(fout, "\n");
	delete[] mas1;
	return;
}
void VivodOtvetaDin(FILE *fout, double *sr, int m, int n){
	for (int i = 0; i < m; ++i) {
		if (sr[i] == 0) { fprintf(fout, " Все элементы неположительны в строке %d\n", i + 1); }
		else {
			fprintf(fout, "Среднее арифметической строки %d =", i + 1);
			fprintf(fout, " %4.4f\n", sr[i] / n);
		}
	}
	
	delete [] sr; 
	return; 
}


int main(int argc, char *argv[])
{
	SetConsoleOutputCP(1251);
	FILE *fin, *fout;
	if ((fin = fopen(argv[1], "rt")) == NULL) {
		printf("Errror: Ошибка при открытии файла %s для чтения\nPress any key\n", argv[1]);
		system("Pause");
		return 0;
	}
	if ((fout = fopen(argv[2], "wt")) == NULL) {
		printf("Errror: Ошибка при открытии файла %s для записи\nPress any keyn\n", argv[2]);
		fclose(fin);
		system("Pause");
		return 0;
	}

	int **mas1, **mas2;
	int m, n, m1, n1;
	


	Zapolnenie(fin, mas1, m, n);
	Zapolnenie(fin, mas2, m1, n1);
	double *sr1, *sr2; 
	sr1 = new double[m]; 
	 sr2 = new double[m1];
	//начало 1 способа


bool f1 = Proverka(mas1, m, n);
if (f1 == false) { fprintf(fout, "У матрицы 1 нет хотя бы одного нулевого элемента\n"); }
else {
	fprintf(fout, "В матрице 1:\n");
	SredArifm(fout, mas1, m, n, sr1);
	VivodMatriciDin(fout, mas1, m, n);
	VivodOtvetaDin(fout, sr1, m, n);
}
Zapolnenie(fin, mas2, m1, n1);
 bool f2 = Proverka(mas2, m1, n1);
if (f2 == false) { fprintf(fout, "У матрицы 2 нет хотя бы одного нулевого элемента\n"); }
else {

	fprintf(fout, "В матрице 2:\n");
	SredArifm(fout, mas2, m1, n1,sr2);
	VivodMatriciDin(fout, mas2, m1, n1);
	VivodOtvetaDin(fout, sr2, m1, n1);
}//конец 2 способа

	fclose(fin); 
	fclose(fout); 
	return 0; 

}