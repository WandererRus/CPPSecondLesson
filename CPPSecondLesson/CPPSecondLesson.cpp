// CPPSecondLesson.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Computer
{
	int memory;
	int procFrequency;
	int hddspace;
	int ssdspace;
	int videomemory;
public:
	Computer(int mem, int procFreq, int hdd, int ssd, int videomem) : memory{ mem },
		procFrequency{ procFreq }, hddspace{ hdd }, ssdspace{ ssd }, videomemory{ videomem }
	{
		if (memory < 4096) memory = 4096;
		if (procFrequency < 3700) procFrequency = 3700;
		if (hddspace < 120) hddspace = 120;
		cout << "Вызван конструктор на 5 параметров" << endl;
	}
	Computer(int mem, int procFreq, int hdd, int ssd) : Computer(mem, procFreq, hdd, ssd, 0) { cout << "Вызван конструктор на 4 параметра" << endl;  }
	Computer(int mem, int procFreq, int hdd) : Computer(mem, procFreq, hdd, 0, 0) { cout << "Вызван конструктор на 3 параметров" << endl;  }
	Computer() : Computer(4096, 3700, 120, 0, 0) { cout << "Вызван пустой конструктор" << endl;  }
	void print() {
		cout << "Данный компьютер содержит в себе: \n Процессор на " << procFrequency <<
			"KHz\n Оперативная память на " << memory << "MB\n Жесткий диск на " << hddspace
			<< "GB" << endl;
		if (ssdspace != 0)
			cout << " Твердотельное пространство на " << ssdspace << "GB" << endl;
		if (videomemory != 0)
			cout << " Видеокарту на " << videomemory << "МB" << endl;
	}
};



int main()
{
	setlocale(LC_ALL, "");

	Computer comp1;
	comp1.print();
	Computer comp2{ 8192,4200,500,240,6072 };
	comp2.print();
	Computer comp3{ 4096,3700,120,120 };
	comp3.print();
	Computer comp4{ 2048,3000,80 };
	comp4.print();
	Computer comp5{ 0,0,0,0,0 };
	comp5.print();

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
