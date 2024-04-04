#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <cstdio>
#include <tuple>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <regex>
#include "Dop/Stroka.h"
#include "Dop/StringM.h"
#include "Dop/9.h"
#include "Dop/LinkedList.h"
//#include <stdafx.h>
//#include <alloc.h>
using namespace std;


void main(void)
{
	setlocale(LC_ALL, "rus");
	unsigned short int i;
	cout << "Введите номер задания от 1 до 10: ";
	cin >> i;
	void task1_1(), task1_2(), task1_3(), task2(), task3(), task4(), task5(), task6(), task7(), task8(), task9(), task10();
	switch (i)
	{
		case 1: 
			task1_1();
			printf("--------------\n");
			task1_2();
			printf("--------------\n");
			task1_3();
			printf("--------------\n");
		case 2: 
			task2();
			printf("--------------\n");
		case 3: 
			task3();
			printf("--------------\n");
		case 4: 
			task4();
			printf("--------------\n");
		case 5: 
			task5();
			printf("--------------\n");
		case 6: 
			task6();
			printf("--------------\n");
		case 7: 
			task7();
			printf("--------------\n");
		case 8: 
			task8();
			printf("--------------\n");
		case 9: 
			task9();
			printf("--------------\n");
		case 10: 
			task10();
			printf("--------------\n");
		//default: printf("Вы ввели не правильное значение\n");;
	}
	
}

void task1_1(void)
{
	int s, k;
	cout << "Введите степень числа: ";
	cin >> s;
	for (int i = 0; i < s; i++)
	{
		k = 2;
		for (int j = 0; j < i; j++) {
			k = k*2;
		}
		cout << "i = " << i+1 << ", k = " << k << endl;
	}
}
#define PR(x) printf("x=%u, *x=%d, &x=%u\n",x,*x,&x)
void task1_2(void)
{
	int mas[] = { 100, 200, 300 };
	int *ptr1, *ptr2;
	ptr1 = mas;
	ptr2 = &mas[2];
	PR(ptr1);
	ptr1++;
	PR(ptr1);
	PR(ptr2);
	++ptr2;
	printf("ptr2-ptr1=%u\n", ptr2 - ptr1);
	/*
	int a {10};
	int *pa {&a};
	std::cout << "address of pointer=" << &pa << std::endl;        // адрес указателя
	std::cout << "address stored in pointer=" << pa << std::endl;  // адрес, который хранится в указателе - адрес переменной a         
	std::cout << "value on pointer=" << *pa << std::endl;          // значение по адресу в указателе - значение переменной a
	*/
}
void task1_3(void)
{
	int a = 2, b = 5;
	void obmen1(int, int);
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	cout << "до обмена: a= " << a << " b=" << b << endl;
	//вызов obmen1(int, int);
	obmen1(a,b);
	cout << "после обмена 1: a= " << a << " b=" << b << endl;
	//вызов obmen2(int*, int*);
	obmen2(&a, &b);
	cout << "после обмена 2: a= " << a << " b=" << b << endl;
	//вызов obmen3(int&, int&);
	obmen3(a, b);
	cout << "после обмена 3: a= " << a << " b=" << b << endl;
}
void obmen1(int v, int g)
{
	int a = v, b = g;
	a = a + b;
	b = a - b;
	a = a - b;
}
void obmen2(int* v, int* g)
{
	int tmp;
	tmp = *v;
	*v = *g;
	*g = tmp;
}
void obmen3(int& v, int& g)
{
	int tmp;
	tmp = v;
	v = g;
	g = tmp;
}

#define N 5
void task2(void)
{
	float m[N][N];
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) m[i][j] = rand() / 10.;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << setw(8) << setprecision(5) << m[i][j];
		}
		cout << endl;
	}
	printf("--------------\n");
	//_getch();
	float max = 0, min = 80000, maxNT = 0, maxVT = 0, minNT = 80000, minVT = 80000, minG = 80000, maxG = 0, minV = 80000, maxV = 0, sred = 0, sredNT = 0, sredVT = 0,
		sumStrok[N]{ 0,0,0,0,0 }, sumStolb[N]{ 0,0,0,0,0 }, minStrok[N]{ 8000,8000,8000,8000,8000 }, maxStrok[N]{ 0,0,0,0,0 }, minStolb[N]{ 8000,8000,8000,8000,8000 }, maxStolb[N]{ 0,0,0,0,0 }, sredStrok[N]{ 0,0,0,0,0 }, sredStolb[N]{ 0,0,0,0,0 },
		sum_NT_i_VT, bliz_k_sred, kf = 0;

	//k = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {				//вся матрица
			if (max < m[i][j]) max = m[i][j];
			if (min > m[i][j]) min = m[i][j];
			if (i == j) {
				if (maxG < m[i][j]) maxG = m[i][j];
				if (minG > m[i][j]) minG = m[i][j];
				if (maxV < m[i][N - i]) maxV = m[i][N - i];
				if (minV > m[i][N - i]) minV = m[i][N - i];
				//kf = kf + 1;
			}
			sumStrok[i] = sumStrok[i] + m[j][i];
			sumStolb[j] = sumStolb[j] + m[i][j];
			if (maxStrok[i] < m[j][i]) maxStrok[i] = m[j][i];
			if (minStrok[i] > m[j][i]) minStrok[i] = m[j][i];
			if (maxStolb[j] < m[i][j]) maxStolb[j] = m[i][j];
			if (minStolb[j] > m[i][j]) minStolb[j] = m[i][j];
			sred += m[i][j];
		}
	}
	sred = sred / (N * N);
	//k = 0;
	for (i = 0; i < N; i++) {		//главного верхнего треугольника
		for (j = i + 1; j < N; j++) {
			if (maxVT < m[i][j]) maxVT = m[i][j];
			if (minVT > m[i][j]) minVT = m[i][j];
			sredVT += m[i][j];
			++kf;
		}
	}
	sum_NT_i_VT = sredVT;
	sredVT = sredVT / kf;
	kf = 0;
	for (i = 0; i < N; i++) {		//главного нижнего треугольника
		for (j = i - 1; j >= 0; j--) {
			if (maxNT < m[i][j]) maxNT = m[i][j];
			if (minNT > m[i][j]) minNT = m[i][j];
			sredNT += m[i][j];
			++kf;
		}
	}
	sum_NT_i_VT += sredNT;
	sredNT = sredNT / kf;
	//kf = 0;
	//bliz_k_sred = 0;
	float kk = max - sred;
	for (i = 0; i < N; i++) {
		sredStrok[i] = sumStrok[i] / N;
		sredStolb[i] = sumStolb[i] / N;
		for (j = 0; j < N; j++) {
			kf = m[i][j] - sred;
			if (kf < 0) {
				kf = kf * (-1);
			}
			if (kf < kk) bliz_k_sred = m[i][j];
		}
	}
	/*
	for (i = 0; i < N; i++) {		//второстепенного верхнего треугольника
		for (j = 0; j < N - i - 1; j++) {
			if (maxV < m[i][j]) maxV = m[i][j];
			if (minV > m[i][j]) minV = m[i][j];
		}
	}
	for (i = N - 1; i >= 0; i--) {	//второстепенного нижнего треугольника
		for (j = N - i; j < N; j++) {
			if (maxVT < m[i][j]) maxVT = m[i][j];
			if (minVT > m[i][j]) minVT = m[i][j];
		}
	}
	*/

	cout << "Минимум матрицы:	" << min << endl;
	cout << "Максимум матрицы:	" << max << endl;
	printf("--------------\n");
	cout << "Максимум нижнетреугольной части матрицы:	" << maxNT << endl;
	cout << "Максимум верхнетреугольной части матрицы:	" << maxVT << endl;
	cout << "Минимум нижнетреугольной части матрицы:		" << minNT << endl;
	cout << "Минимум верхнетреугольной части матрицы:	" << minVT << endl;
	printf("--------------\n");
	cout << "Минимум главной диагонали матрицы:		" << minG << endl;
	cout << "Максимум главной диагонали матрицы:		" << maxG << endl;
	cout << "Минимум второстепенной диагонали матрицы:	" << minV << endl;
	cout << "Максимум второстепенной диагонали матрицы:	" << maxV << endl;
	printf("--------------\n");
	cout << "Среднеарифметическое значение элементов матрицы:				" << sred << endl;
	cout << "Среднеарифметическое значение элементов — нижнетреугольной части матрицы:	" << sredNT << endl;
	cout << "Среднеарифметическое значение элементов — верхнетресугольной части матрицы:	" << sredVT << endl;
	printf("--------------\n");
	

	for (i = 0; i < N; i++) {
		cout << "Суммы строк матрицы:			" << sumStrok[i] << endl;
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		cout << "Минимальные значения строк:		" << minStrok[i] << endl;
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		cout << "Максимальные значения строк:		" << maxStrok[i] << endl;
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		cout << "Среднеарифметические значения строк:	" << sredStrok[i] << endl;
	}
	printf("--------------\n");
	
	printf("Суммы столбцов матрицы:			");
	for (i = 0; i < N; i++) {
		cout << sumStolb[i] << "\t";
	}
	printf("\n");
	printf("Минимальные значения столбцов:		");
	for (i = 0; i < N; i++) {
		cout << minStolb[i] << "\t";
	}
	printf("\n");
	printf("Максимальные значения столбцов:		");
	for (i = 0; i < N; i++) {
		cout << maxStolb[i] << "\t";
	}
	printf("\n");
	printf("Среднеарифметические значения столбцов:	");
	for (i = 0; i < N; i++) {
		cout << sredStolb[i] << "\t";
	}
	printf("\n");


	printf("--------------\n");
	cout << "Суммы нижне- и верхнетреугольных частей матрицы:		" << sum_NT_i_VT << endl;
	cout << "Элемент, наиболее близкий по значению к среднеарифметическому:	" << bliz_k_sred << endl;
}
/*
минимум матрицы;
максимум матрицы;

максимум нижнетреугольной части матрицы;
максимум верхнетреугольной части матрицы;
минимум нижнетреугольной части матрицы;
минимум верхнетреугольной части матрицы;

минимум главной диагонали матрицы;
максимум главной диагонали матрицы;
минимум второстепенной диагонали матрицы;
максимум второстепенной диагонали матрицы;

среднеарифметическое значение элементов матрицы;
среднеарифметическое значение элементов — нижнетреугольной части матрицы;
среднеарифметическое значение элементов — верхнетресугольной части матрицы;

суммы строк матрицы;
суммы столбцов матрицы;
минимальные значения строк;
минимальные значения столбцов;
максимальные значения строк;
максимальные значения столбцов;
среднеарифметические значения строк;
среднеарифметические значения столбцов;

суммы нижне- и верхнетреугольных частей матрицы;
элемент, наиболее близкий по значению к среднеарифмстическому.
*/

void task3(void)
{
	//setlocale(LC_ALL, "rus");
	int mas[] = { 2,5,-8,1,-4,6,3,-5,+9,13,0,4,9 };
	int masP[] = { 2,5,-8,1,-4,6,3,-5,+9,13,0,4,9 };
	int masB[] = { 2,5,-8,1,-4,6,3,-5,+9,13,0,4,9 };
	int masDvunapr[] = { 2,5,-8,1,-4,6,3,-5,+9,13,0,4,9 };
	int masPoVozrast[] = { 2,5,-8,1,-4,6,3,-5,+9,13,0,4,9 };
	int masPoUbivaniu[] = { 2,5,-8,1,-4,6,3,-5,+9,13,0,4,9 };
	void qsortRecursive(int*, int);
	//текущие индексы мин и макс элементов
	int imin, imax;
	//вычисление n - количества элементов
	const int n = sizeof(mas) / sizeof(int);
	int i, j;
	//установка наальных индексов для мин и макс
	imin = i = 0; imax = i = 0;
	//clrscr();
	printf("Исходный массив:		");
	for (i = 0; i < n; i++)
		cout << mas[i] << ' ';
	cout << endl;
	printf("\n");
	for (i = 0; i < n - 1; i++) //нахождение мин и макс
	{
		imin = i;
		for (j = i + 1; j < n; j++)
			if (mas[j] < mas[imin]) imin = j;
		int t = mas[i];
		mas[i] = mas[imin];
		mas[imin] = t;
	}
	printf("Сортировка \"Мини-маской\":	");
	for (i = 0; i < n; i++) //вывод на экран
		cout << mas[i] << ' ';
	cout << endl;
	printf("\n");
	printf("Сортировка \"Пузырьком\":		");
	//*
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (masP[j] > masP[j + 1]) {
				int b = masP[j]; // создали дополнительную переменную
				masP[j] = masP[j + 1]; // меняем местами
				masP[j + 1] = b; // значения элементов
			}
		}
	}
	//*/
	/*
	for (i = 0; i < n; i++) {
		bool flag = true;
		for (j = 0; j < n - (i + 1); j++) { 
			if (masP[j] > masP[j + 1]) {
				flag = false;
				swap (masP[j], masP[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
	*/
	for (i = 0; i < n; i++) //вывод на экран
		cout << masP[i] << ' ';
	cout << endl;
	printf("\n");
	printf("\"Быстрая cортировка\":		");
	qsortRecursive(masB,n);
	for (i = 0; i < n; i++) //вывод на экран
		cout << masB[i] << ' ';
	cout << endl;
	printf("\n");
	//printf("Две сортировки:		\n");
	int mChet[n] = {0}, mNechet[n] = {0};
	int jc = 0, jn = 0;
	for (i = 0; i < n; i++)
	{
		if ((masDvunapr[i] % 2) == 0) {
			mChet[jc] = masDvunapr[i];
			jc++;
		}
		else {
			mNechet[jn] = masDvunapr[i];
			jn++;
		}
	}
	/*
	printf("Первая до:		");
	for (i = 0; i < n; i++) //вывод на экран
		cout << mChet[i] << ' ';
	cout << endl;
	printf("Вторая до:		");
	for (i = 0; i < n; i++) //вывод на экран
		cout << mNechet[i] << ' ';
	cout << endl;
	*/
	for (i = 0; i < jc; i++) {
		bool flag = true;
		for (j = 0; j < jc - (i + 1); j++) {
			if (mChet[j] > mChet[j + 1]) {
				flag = false;
				swap(mChet[j], mChet[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
	for (i = 0; i < jn; i++) {
		bool flag = true;
		for (j = 0; j < jn - (i + 1); j++) {
			if (mNechet[j] < mNechet[j + 1]) {
				flag = false;
				swap(mNechet[j], mNechet[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
	/*
	printf("Первая после:		");
	for (i = 0; i < n; i++) //вывод на экран
		cout << mChet[i] << ' ';
	cout << endl;
	printf("Вторая после:		");
	for (i = 0; i < n; i++) //вывод на экран
		cout << mNechet[i] << ' ';
	cout << endl;
	*/
	for (i = 0; i < jn; i++)
	{
		masDvunapr[i] = mNechet[i];
	}
	for (i = 0; i < jc; i++)
	{
		masDvunapr[i+jn] = mChet[i];
	}
	printf("Две сортировки:			");
	for (i = 0; i < n; i++) //вывод на экран
		cout << masDvunapr[i] << ' ';
	cout << endl;
	printf("\n");
	printf("По возрастанию от N1 до N2:	");
	jc = 3; jn = 13; //N1 и N2
	for (i = jc; i < jn; i++) {
		bool flag = true;
		for (j = jc; j < jn - (i + 1); j++) {
			if (masPoVozrast[j] > masPoVozrast[j + 1]) {
				flag = false;
				swap(masPoVozrast[j], masPoVozrast[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
	for (i = 0; i < n; i++) //вывод на экран
		cout << masPoVozrast[i] << ' ';
	cout << endl;
	printf("\n");
	printf("По убыванию от N1 до N2:	");
	for (i = jc; i < jn; i++) {
		bool flag = true;
		for (j = jc; j < jn - (i + 1); j++) {
			if (masPoUbivaniu[j] < masPoUbivaniu[j + 1]) {
				flag = false;
				swap(masPoUbivaniu[j], masPoUbivaniu[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
	for (i = 0; i < n; i++) //вывод на экран
		cout << masPoUbivaniu[i] << ' ';
	cout << endl;
}
void qsortRecursive(int* mas, int size) {
	//Указатели в начало и в конец массива
	int i = 0;
	int j = size - 1;
	//Центральный элемент массива
	int mid = mas[size / 2];

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (mas[i] < mid) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (mas[j] > mid) {
			j--;
		}
		//Меняем элементы местами
		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		qsortRecursive(mas, j + 1);
	}
	if (i < size) {
		//"Првый кусок"
		qsortRecursive(&mas[i], size - i);
	}
}

void task4(void) {
	char str1[] = "qwerty", str2[] = "1234567890";
	char str3[80] = {};
	int dlina1(char*);
	int dlina2(char*);
	int dlina3(char*);
	void kopir(char*, char*);
	int sravn(char*, char*);
	void konkat(char*, char*);
	cout << "Стандартные операции: " << endl;
	cout << "Определение длинны строки \"strlen\": " << strlen(str2) << endl;
	cout << "Конкатенация строк \"strcat\": " << str1 << str2 << endl;
	cout << "Копирование строк \"strcpy\"" << endl;
	cout << "Сравнение строк \"strcmp\": " << strcmp(str1, str2) << endl;
	//использование функции длинны строки
	cout << "длнна str1=" << dlina1(str1) << ", str2=" << dlina1(str2) << endl;
	cout << "длнна str1=" << dlina2(str1) << ", str2=" << dlina2(str2) << endl;
	cout << "длнна str1=" << dlina3(str1) << ", str2=" << dlina3(str2) << endl;
	
	//вызов kopir(char*, char*);
	kopir(str3, str1);
	cout << "результат копирования:str1= " << str1 << " , str3=" << str3 << endl;
	//вызов sravn(char*, char*);
	cout << "результат сравнения: str1 и str3= " << sravn(str1, str3) << endl; 
	//вызов konkat(char*, char*);
	konkat(str3, str2);
	cout << "результат сцепления:str1= " << str1 << " , str3=" << str3 << endl;

	printf("--------------\n");
	char *mstr1, *mstr2;
	mstr1 = (char*)malloc(20);
	mstr2 = (char*)malloc(20 * sizeof(char));
	kopir(mstr1, str1);
	cout << "результат копирования: mstr1= " << mstr1 << endl;
	kopir(mstr2, str2);
	cout << "результат копирования: mstr2= " << mstr2 << endl;
	cout << "длнна mstr1=" << dlina1(mstr1) << ", mstr2=" << dlina1(mstr2) << endl;
	cout << "длнна mstr1=" << dlina2(mstr1) << ", mstr2=" << dlina2(mstr2) << endl;
	cout << "длнна mstr1=" << dlina3(mstr1) << ", mstr2=" << dlina3(mstr2) << endl;
	cout << "результат сравнения: mstr1 и mstr2= " << sravn(mstr1, mstr2) << endl;
	konkat(mstr2, mstr1);
	cout << "результат сцепления:mstr1= " << mstr1 << " , mstr2=" << mstr2 << endl;
	free(mstr1);
	free(mstr2);

	printf("--------------\n");
	char* cstr1, * cstr2;
	cstr1 = (char*)calloc(100, sizeof(char));
	cstr2 = (char*)calloc(100, sizeof(char));
	kopir(cstr1, str1);
	cout << "результат копирования: cstr1= " << cstr1 << endl;
	kopir(cstr2, str2);
	cout << "результат копирования: cstr2= " << cstr2 << endl;
	cout << "длнна cstr1=" << dlina1(cstr1) << ", cstr2=" << dlina1(cstr2) << endl;
	cout << "длнна cstr1=" << dlina2(cstr1) << ", cstr2=" << dlina2(cstr2) << endl;
	cout << "длнна cstr1=" << dlina3(cstr1) << ", cstr2=" << dlina3(cstr2) << endl;
	cout << "результат сравнения: cstr1 и cstr2= " << sravn(cstr1, cstr2) << endl;
	konkat(cstr2, cstr1);
	cout << "результат сцепления:cstr1= " << cstr1 << " , cstr2=" << cstr2 << endl;
	free(cstr1);
	free(cstr2);
}
int dlina1(char* ch) {
	int i = 0;
	while (*ch++)
	{
		i++;
	}
	return i;
}
int dlina2(char* ch) {
	char* tmp = ch;
	while (*ch != '\0')
	{
		ch++;
	}
	return ch - tmp;
}
int dlina3(char* ch) {
	int i = 0;
	while (ch[i] != '\0')
	{
		i++;
	}
	return i;
}
void kopir(char* a, char* b) {
	int k = 0;
	char* pa = a;
	char* pb = b;
	while (*b++ != '\0')
	{
		*(pa + k) = *(pb + k);
		k++;
	}
	//return a;
}
/*
const char* sravn(char* a, char* b) {
	if (dlina1(a) != dlina1(b))
		return "Не одинаковы";
	for (int k = 0; a[k] != '\0'; k++) {
		if (a[k] != b[k])
			return "Не одинаковы";
	}
	return "Строки идентичны";
}
*/
int sravn(char* a, char* b) {
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0') {
		if (a[i] < b[i])
			return -1;
		if (a[i] > b[i])
			return 1;
		i++;
	}
	return 0;
}
void konkat(char* a, char* b) {
	int k = 0;
	int n = 0;
	char* pa = a;
	char* pb = b;
	while (*a++ != '\0')
	{
		k++;
	}
	while (*b++ != '\0')
	{
		*(pa + k) = *(pb + n);
		k++;
		n++;
	}
}

//*
void task5(void) {
	char name[50];
	void search(FILE*, char*), movePageNumbers(), printAllFile(FILE*);
	tuple<int, int> countPrintedAndEmptySymbols(FILE*);
	printf("Введите имя файла для просмотра: ");
	scanf("%s", name);
	//cin >> name;
	FILE* in = fopen(name, "r");
	if (in == nullptr) {
		printf("Файл %s не открыт", name);
	}

	printAllFile(in);

	auto symbolsCount = countPrintedAndEmptySymbols(in);
	printf("\n\nВ файле %d \"непустых\" символов и %d \"пустых\"\n", get<0>(symbolsCount), get<1>(symbolsCount));

	//search(in, "ipsum");
	search(in, name);

	movePageNumbers();

	fclose(in);
}
void printAllFile(FILE* in) {
	fseek(in, 0, SEEK_SET);
	while (!feof(in)) {
		putchar(getc(in));
	}
}
tuple<int, int> countPrintedAndEmptySymbols(FILE* in) {
	fseek(in, 0, SEEK_SET);
	int symbols = 0;
	int emptySymbols = 0;
	while (!feof(in)) {
		char chr = getc(in);
		if (chr <= 32)
			emptySymbols++;
		else
			symbols++;
	}

	return { symbols, emptySymbols };
}
void search(FILE* in, char* query) {
	fseek(in, 0, SEEK_SET);
	char* buffer = (char*)malloc(1024);
	FILE* out = fopen("Dop/5-search.txt", "w");

	if (out == nullptr) {
		printf("Не удалось открыть выходной файл");
		return;
	}

	char* line;
	int i = 0;
	while ((line = fgets(buffer, 1024, in))) {
		i++;
		if (strstr(line, query) != nullptr) {
			char* bufferLocal = (char*)malloc(20 + strlen(line));
			sprintf(bufferLocal, "LINE %d: %s", i, line);

			fputs(bufferLocal, out);
			free(bufferLocal);
		}
	}

	fclose(out);
	free(buffer);
}
void movePageNumbers() {
	char* line = (char*)malloc(1024);

	ifstream ifs("Dop/test.txt");
	if (!ifs) {
		printf("Не удалось открыть файл test.txt");
		return;
	}

	ofstream ofs("Dop/test-moved.txt");
	if (!ofs) {
		printf("Не удалось открыть файл test-moved.txt");
		return;
	}

	bool is_next_line_with_number = false;
	char* pageNumStr = new char[1024];
	while (ifs && ofs) {
		ifs.getline(line, 1024);
		if (strstr(line, "\f") != nullptr) {
			is_next_line_with_number = true;
		}
		else {
			if (is_next_line_with_number) {
				strcpy(pageNumStr, line);
			}
			else {
				if (strlen(pageNumStr) > 0) {
					string str = string(pageNumStr);
					replace(str.begin(), str.end(), '-', ' ');
					ofs << str << endl << '\f';
				}
				ofs << line << endl;
				pageNumStr[0] = '\0';
			}
			is_next_line_with_number = false;
		}
	}
	
}
//*/

void task6(void) {
	setlocale(LC_ALL, "ru");
	Stroka s1((char*)"qwert"), s3, s4(s1), s5;
	s3.vvod();
	s3 = "asdfg";
	s3.vyvod();
	s5 = s1 + s3 + s4;
	cout << "length s5 = " << s5.dlina() << endl;
	s5.vyvod();
	if (s1 == s5)
		cout << "strings s1 & s5 equal" << endl;
	else
		if (s1 == s4)
			cout << "strings s1 & s4 equal" << endl;
}

//*
class Rectangle {	// Класс прямоугольника
	// protected поля, чтобы был доступ из наследников
protected:
	int x, y;
	int width, height;

public:
	Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

	// Метод вывода на консоль
	virtual void print() {
		cout << "Rectangle: (" << x << ", " << y << "), width = " << width << ", height = " << height << endl;
	}
};
class Square : public Rectangle {
public:
	Square(int x, int y, int sideSize) : Rectangle(x, y, sideSize, sideSize) {}

	// Переопределенный метод
	void print() override {
		cout << "Square: (" << x << ", " << y << "), sideSize = " << width << endl;
	}
};
void task7(void) {
	//class Rectangle;
	//class Square;
	Rectangle rect = Rectangle(10, 20, 100, 50);
	Square square = Square(30, 40, 40);

	// Печатаем прямоугольник
	rect.print();
	// Печатаем квадрат
	square.print();
	// Печатаем квадрат как прямоугольник
	((Rectangle)square).print();
}
//*/

//*
void task8(void) {
	void stringM(), open1(), open2(), open3();
//    stringM();
//    open1();
//    open2();
	open3();
}
void stringM() {
	char* str = {};
	//str = str + "asdasf";
	//strcat(str, "asdasf");
	StringM str(strcat(str, "asdasf"));
	cout << str << endl;

	cout << "Введите строку: ";
	cin >> str;
	cout << str << endl;
}
void open1() {
	char fname[15], c;
	cout << "Введите имя входного файла";
	cin >> fname;
	ifstream ifs(fname);
	if (!ifs)
		cout << "Не открыт входной файл " << fname;
	cout << "Введите имя выходного файла";
	cin >> fname;
	ofstream ofs(fname);
	if (!ofs)
		cout << "Не открыт выходной файл " << fname;

	while (ifs && ofs) {
		ifs.get(c);
		c = toupper(c);
		ofs.put(c);
	}
	cout << '.';
	cout << endl << "Выходной файл является копией входного файла в верхнем регистре" << endl;
}
void open2() {
	char name[12];
	fstream fin;
	cout << "Введите имя файла: ";
	cin >> name;

	fin.open(name, ios::in);
	if (fin) {
		cout << "Файл открыт " << name << endl;
		fin.close();
	}
	else {
		cout << "Не открыт выходной файл " << name << endl;
	}
}
void open3() {
	const char* fname = "Dop/8-fname.txt";
	fstream ofs(fname, ios::out);

	if (!ofs) {
		cout << "Файл " << fname << " уже существует" << endl;
		return;
	}
	ofs << "Эта строка записывается в новый файл. ";
	ofs.close();
	fstream fs;
	fs.open(fname, ios::out | ios::app);
	fs << " Сейчас к ней сделано добавление";
	fs.close();
	fstream ifs;
	ifs.open(fname, ios::in);
	if (ifs) {
		cout << "В старом файле содержится ..." << endl;
		char line[80];
		ifs.getline(line, sizeof(line));
		cout << line;
	}
	else {
		cout << "Ошибка при повторном открытии fname" << endl;
	}
}
//*/
//void task8(void) {}

void task9(void) {
	void sort_arr(), max(), max_str(), train_sort();
	sort_arr();
	max();
	max_str();
	train_sort();
}
void sort_arr() {
	int arr[] = { 5, 2, 7, 10, -2, -5 };
	for (int i : arr)
		cout << i << ' ';
	cout << endl;

	sort(arr, sizeof(arr) / sizeof(int));

	for (int i : arr)
		cout << i << ' ';
	cout << endl;

	double arr_double[] = { 5.2, 2.1, 7.2, -1.9, 7.3 };

	for (double i : arr_double)
		cout << i << ' ';
	cout << endl;

	sort(arr_double, sizeof(arr_double) / sizeof(double));

	for (double i : arr_double)
		cout << i << ' ';
	cout << endl;
}
void max() {
	int i1 = 3, i2 = 5;
	int arr[] = { 3, 9, 5, 8 };
	cout << "max int = " << getmax(i1, i2) << endl;
	cout << "max int = " << getmax(arr, sizeof(arr) / sizeof(int)) << endl;
}
void max_str() {
	//char* s1 = "строка1";
	//char* s2 = "строка2";
	char* s1 = {};
	strcat(s1, "строка1");
	char* s2 = {};
	strcat(s2, "строка1");
	cout << "max str = " << getmax(s1, s2) << endl;
}
void train_sort() {
	int train[] = { 5, 3, 1 };
	Tstack<int> stack;
	for (int i : train) {
		stack.push(i);
	}

	for (int i = 0; i < sizeof(train) / sizeof(int); i++) {
		cout << stack.pop() << ' ';
	}
	cout << endl;
}


void task10(void) {
	auto* park = new Park();

	auto bus1 = *new Bus(1, (char*)"Иванов И.И.", 15);
	park->addBus(bus1);
	auto bus2 = *new Bus(2, (char*)"Петров П.П.", 20);
	park->addBus(bus2);
	auto bus3 = *new Bus(3, (char*)"Смирнов С.С.", 33);
	park->addBus(bus3);

	park->print();

	cout << endl;
	park->goOnRoute(bus2);
	park->print();

	cout << endl;
	park->goInPark(bus2);
	park->print();

	//_getch();
}
