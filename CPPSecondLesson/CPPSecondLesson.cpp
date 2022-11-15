// CPPSecondLesson.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

class Computer
{
	int memory;
	int procFrequency;
	int hddspace;
	int ssdspace;
	int videomemory;	

	string* programms;
public:
	static int computerCount;
	Computer(int mem, int procFreq, int hdd, int ssd, int videomem, string* progs) : memory{ mem },
		procFrequency{ procFreq }, hddspace{ hdd }, ssdspace{ ssd }, videomemory{ videomem }, programms{ progs}
	{
		if (memory < 4096) memory = 4096;
		if (procFrequency < 3700) procFrequency = 3700;
		if (hddspace < 120) hddspace = 120;
		cout << "Вызван конструктор на 6 параметров" << endl;
		computerCount++;
	}
	Computer(int mem, int procFreq, int hdd, int ssd) : Computer(mem, procFreq, hdd, ssd, 0, new string[5]{ "Word","Excel","Chrome","WinRAR","Opera" }) { cout << "Вызван конструктор на 5 параметра" << endl;  }
	Computer(int mem, int procFreq, int hdd) : Computer(mem, procFreq, hdd, 0, 0, new string[5]{ "Word","Excel","Chrome","WinRAR","Opera" }) { cout << "Вызван конструктор на 4 параметров" << endl;  }
	Computer() : Computer(4096, 3700, 120, 0, 0, new string[5]{ "Word","Excel","Chrome","WinRAR","Opera" }) { cout << "Вызван пустой конструктор" << endl;  }
	Computer(const Computer& comp) : memory{ comp.memory }, procFrequency{ comp.procFrequency },
		hddspace{ comp.hddspace }, ssdspace{ comp.ssdspace }, videomemory{ comp.videomemory }, programms{ new string [5]}
	{
		cout << "Объект был скопирован" << endl;
		computerCount++;

		for (int i = 0; i < 5; i++)
		{
			programms[i] = comp.programms[i];
		}
	}
	void print() {
		cout << "Данный компьютер содержит в себе: \n Процессор на " << procFrequency <<
			"KHz\n Оперативная память на " << memory << "MB\n Жесткий диск на " << hddspace
			<< "GB" << endl;
		if (ssdspace != 0)
			cout << " Твердотельное пространство на " << ssdspace << "GB" << endl;
		if (videomemory != 0)
			cout << " Видеокарту на " << videomemory << "МB" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << " Список программ на компьютере " << programms[i] << endl;
		}
		
	}
	~Computer() {
		delete[] programms;
		computerCount--;
		cout << "Компьютер был уничтожен" << endl;
	}
};


int Computer::computerCount{ 0 };
int main()
{
	setlocale(LC_ALL, "");	
	Computer comp1;
	comp1.print();
	cout << "" << endl;
	Computer comp2{ 8192,4200,500,240,6072,new string[5]{ "Word","Excel","Chrome","WinRAR","Opera" } };
	comp2.print();
	cout << "" << endl;
	Computer comp3{ 4096,3700,120,120 };
	comp3.print();
	cout << "" << endl;
	Computer comp4{ 2048,3000,80 };
	comp4.print();
	cout << "" << endl;
	Computer comp5{ 0,0,0,0,0,new string[5]{ "Word","Excel","Chrome","WinRAR","Opera" } };
	comp5.print();
	cout << "" << endl;
	Computer comp6{comp3};
	comp6.print();
	cout << "" << endl;
	cout << "Количество собранных компьютеров: " << Computer::computerCount << endl;
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
