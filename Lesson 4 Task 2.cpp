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

	Address(std::string city, std::string street, int house_number, int apartment_number)	//��� ����������� � �����������
	{
		this->city = city;													    // �������������
		this->street = street;													// �������������
		this->house_number = house_number;										// �������������
		this->apartment_number = apartment_number;								// �������������
	}

	// address*    // ������������ ������ ��� �������� ���� �������, ����������� ������ 

	//std::string get_output_address1() // �����, ������� �������� ������ ��� ������ � ����, ����� ����� ���������� �������� ���� std::string

};


int main() {

	setlocale(LC_ALL, "rus");

	std::ifstream fin("in.txt");                    // �������� ������� ������������ ����
	std::string s;									// ������� ���������� string ��� �������� ������

	std::ofstream fout("out.txt");					// ������� ���� �� ������

	fin >> s;										// ������� 1-� ����� �� ����� � �������� ��� � �����. s

	int n = std::stoi(s);							// ������������� �������� ���� std::string � �����
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
		std::string* ad = new std::string[3];			 // ������� ������������ ������
		for (int i = 0; i < 3; i++)
		{
			fin >> s;									 // ��������� �������� ������, �������� �����, ����� ����
			std::cout << s << ", ";
		}
		fin >> s;									     // ��������� ����� ��������
		std::cout << s << std::endl;
		delete[] ad;									 // ������� ������������ ������
	}

	fin.close();											 // ��������� ���� "in.txt"
	fout.close();											 // ��������� ���� "out.txt"
}








/*
������ 2. ��������� ������
� ���� ������� �� ������ ������ �� ����� ������ � �������� �� � ������ ���� � ������ �������, ���������������� �� �������� ������.

��� ��� ���� in.txt, � ������� ��������� N �������. ����� N ��� ������ � �����. ����� ����� N ������������� N ������ �� 4 ������ � ������. ������ ���� ������� �� ��������� �����: �������� ������, �������� �����, ����� ����, ����� ��������.

������ ��������� ����������� � ���, ����� ������� ������ �� ����� in.txt, ������������� �� �� �������� ������ � ������� ��������������� ������ ������� � ���� out.txt � ������ �������. �� �������� ������� ���������� ������� � ������.

������ ������ ���� ������������� � ���������� �������.

������ ������ ������: <�������� ������>, <�������� �����>, <����� ����>, <����� ��������>.

������ ������ ���������
in.txt
5
������
����������
34
12
�����������
�����
5
16
����
�������
2
13
������
�����
4
1
�����������
����
85
64
out.txt
5
������, ����������, 34, 12
������, �����, 4, 1
�����������, �����, 5, 16
�����������, ����, 85, 64
����, �������, 2, 13
*/
