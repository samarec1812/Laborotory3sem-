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

bool Proverka1(int *mas1, int n) {
	bool f1 = false;
	//int j = 0;

	for (int i = 0; i < n; ++i) {
		if (mas1[i] == 0) { f1 = true; }
	}

	return f1;
}

double SredArifm1(int *mas1, int n, double k) { 
	for (int j = 0; j < n; ++j) {
		if (mas1[j] > 0) k += mas1[j];
	}
	return k; 
}
void VivodMatriciDin2(FILE *fout, int *mas1, int n) {

	
		for (int j = 0; j < n; ++j) {
			fprintf(fout, "%d ", mas1[j]);
		}
	
	
	fprintf(fout, "\n");

	return;
}

void VivodOtvetaDin(FILE *fout, double sr, int m, int n, int u){
//	for (int i = 0; i < m; ++i) {
		if (sr ==  0) { fprintf(fout, " Все элементы неположительны в строке %d\n", u + 1); }
		else {
			fprintf(fout, "Среднее арифметической строки %d =", u + 1);
			fprintf(fout, " %4.4f\n", sr / n);
		}
//	}
	
//	delete [] sr; 
	return; 
}
bool matrica(int **mas1, int m, int n) {
//	bool *k1, 
 bool f1; 
//	k1 = new bool[m];
	for (int i = 0; i < m; i++) {
		//k1[i] = Proverka1(mas1[i], n);
		if (Proverka1(mas1[i], n) == true) { f1 = true; }

	}
	return f1; 
}
void SredDopolnit(FILE *fout, int m, int n, int **mas1) {
	double *sr1;
	int k22 = 0;
	//sr1 = new double[m];
	
	
	for (int i = 0; i < m; i++) {
		VivodMatriciDin2(fout, mas1[i], n);
	}

    for (int i = 0; i < m; ++i) {
	int k = SredArifm1(mas1[i], n, k22);
    VivodOtvetaDin(fout, k, m, n,i); //"или"   VivodOtvetaDin(fout, SredArifm1(mas1[i], n, k22), m, n);
	}
	//VivodOtvetaDin(fout, sr1, m, n);
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
	 bool *k1,*k2, f1, f2; 
	 k1 = new bool[m]; 
	 k2 = new bool[m1]; 
	double k11 =0, k22 = 0 ; 
	
	f1 = matrica(mas1, m, n); 
		if (f1 == false) { fprintf(fout, "У матрицы 1 нет хотя бы одного нулевого элемента\n"); }
	else {
		fprintf(fout, "В матрице 1:\n");
		SredDopolnit(fout, m, n, mas1); 
	}

		f2 = matrica(mas2, m1, n1); 
if (f2 == false) { fprintf(fout, "У матрицы 2 нет хотя бы одного нулевого элемента\n"); }
else {

	fprintf(fout, "В матрице 2:\n");
	SredDopolnit(fout, m1, n1, mas2); 
}

	fclose(fin); 
	fclose(fout); 
	return 0; 

}