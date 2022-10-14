// Персональный шаблон
#include <iostream>
#include <ctime>
#include <cstdlib>
//Заполнения массива случайными числами от begin до end
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//вывод массива arr в консоль
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename T>
void Middle_sort(T arr[], const int length) {
	int FirstIndex = 0, LastIndex = 0;
	for(int i =0;i<length;i++)
		if (arr[i] < 0) {
			FirstIndex = i; break;
		}
	for (int i = length-1; i >=0; i--)
		if (arr[i] < 0) {
			LastIndex = i; break;
		}
	//пузырьковая сортировка
	for (int i = LastIndex-1; i > 0; i--)
		for (int j = FirstIndex+1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
	//Быстрая сортировка
	sort(arr + FirstIndex + 1, arr + LastIndex - 1);
		
}
void type_off(int num);
template <typename T>
void move_arr(T arr[], const int length, int num);
void type_off(double num);
void type_off(char num);
int Sym_AtoB(int A, int B);
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//Задача 1. Вывод типа данных 
	/*
	std::cout << "Задача 1.\n";
	std::cout << "12 - ";
	type_off(12);
	std::cout << "9.11 - ";
	type_off(9.11);
	std::cout << "\'T\' - ";
	type_off('T');
	
	//Задача 2.Рекурсия от A до B
	std::cout << "Введите два числа:";
	std::cin >> n >> m;
	std::cout << "Сумма чисел от A до B = " << Sym_AtoB(n, m) << '\n';
	
	//Задача 3. Сортировка центра массива
	std::cout<<"Изначальный массив:\n";
	const int size3 = 20;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	show_arr(arr3, size3);
	Middle_sort(arr3, size3);
	std::cout << "итоговый массив:\n";
	show_arr(arr3, size3);
	std::cout << '\n';
	*/
	//Задачач 4.Сдвиг массива
	std::cout << "Начальный массив:\n";
	const int size4 = 10;
	int arr4[size4]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	show_arr(arr4, size4);
	std::cout << "Введите количество сдвигов:\n";
	std::cin >> n;
	move_arr(arr4, size4, n);
	std::cout << "Итоговый массив:\n";
	show_arr(arr4, size4);
	return 0;
}
//Задача 1
void type_off(int num) {
	std::cout << "INT" << '\n';
}
void type_off(double num) {
	std::cout << "DOUBLE" << '\n';
}
void type_off(char num) {
	std::cout << "CHAR" << '\n';
}
//Задача 2
int Sym_AtoB(int A, int B) {
	if (B == A+1)
		return A+B;
	return Sym_AtoB(A, B - 1)+B;
}
//Задача 4
template <typename T>
void move_arr(T arr[], const int length, int num) {
	if(num >=0) //сдвиг вправо
		for (int j =0;j<num;j++)
			for (int i = length - 2; i >= 0; i--)
				std::swap(arr[i], arr[i + 1]);
	else         //сдвиг влево
		for (int j = num; j < 0; j++)
			for (int i = 0; i < length-1; i++)
				std::swap(arr[i], arr[i + 1]);
	}