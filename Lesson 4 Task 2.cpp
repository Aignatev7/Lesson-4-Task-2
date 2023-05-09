#include <iostream>
#include <string>
#include <fstream>

class Address
{
private:
	std::string city;
	std::string street;
	int house_number;
	int apartment_number;

public:

	Address(std::string city, std::string street, int house_number, int apartment_number)	//это конструктор с параметрами
	{
		this->city = city;													    // инициализация
		this->street = street;													// инициализация
		this->house_number = house_number;										// инициализация
		this->apartment_number = apartment_number;								// инициализация
	}

	// address*    // динамический массив для хранения всех адресов, экземпляров класса 

	//std::string get_output_address1() // метод, который собирает строку для вывода в файл, метод будет возвращать значение типа std::string

};


int main() {

	setlocale(LC_ALL, "rus");

	std::ifstream fin("in.txt");                    // пытаемся открыть существующий файл
	std::string s;									// создали переменную string для хранения строки

	std::ofstream fout("out.txt");					// открыли файл на запись

	fin >> s;										// считали 1-е слово из файла и записали его в перем. s

	int n = std::stoi(s);							// преобразовали значение типа std::string в число
	std::cout << n << std::endl;
	fout << n << std::endl;

	//std::string s1;
	//fin >> s1;
	////std::cout << s1 << ", ";
	//std::string s2;
	//fin >> s2;
	////std::cout << s2 << ", ";
	//std::string s3;
	//fin >> s3;
	//int n1 = std::stoi(s3);
	////std::cout << n1 << ", ";
	//std::string s4;
	//fin >> s4;
	//int n2 = std::stoi(s4);
	////std::cout << n2 << std::endl;


	/*Address address1 = { s1, s2, n1, n2 };
	std::cout << address1.get_output_address();*/


	for (int x = 0; x < n; x++)
	{
		std::string* ad = new std::string[3];			 // создаем динамический массив
		for (int i = 0; i < 3; i++)
		{
			fin >> s;									 // считываем название города, название улицы, номер дома
			std::cout << s << ", ";
		}
		fin >> s;									     // считываем номер квартиры
		std::cout << s << std::endl;
		delete[] ad;									 // удаляем динамический массив
	}

	fin.close();											 // закрываем файл "in.txt"
	fout.close();											 // закрываем файл "out.txt"
}








/*
Задача 2. Сортируем адреса
В этом задании вы будете читать из файла адреса и выводить их в другой файл в другом формате, отсортированными по названию города.

Вам дан файл in.txt, в котором находится N адресов. Число N идёт первым в файле. После числа N располагаются N блоков по 4 строки в каждом. Каждый блок состоит из следующих строк: название города, название улицы, номер дома, номер квартиры.

Задача программы заключается в том, чтобы считать адреса из файла in.txt, отсортировать их по названию города и вывести отсортированный список адресов в файл out.txt в другом формате. Не забудьте вывести количество адресов в начале.

Города должны быть отсортированы в алфавитном порядке.

Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>.

Пример работы программы
in.txt
5
Москва
Строителей
34
12
Новокузнецк
Науки
5
16
Омск
Пушкина
2
13
Москва
Арбат
4
1
Новосибирск
Мира
85
64
out.txt
5
Москва, Строителей, 34, 12
Москва, Арбат, 4, 1
Новокузнецк, Науки, 5, 16
Новосибирск, Мира, 85, 64
Омск, Пушкина, 2, 13
*/
