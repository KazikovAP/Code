#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int words = 0; //колличество слов посчитанных на данный момент
    vector<string> wordsInput; //массив содержащий отдельные слова
    wordsInput.resize(1); //убеждаемс€, что изначальный размер вектора 1
    int uniqueWord = 0; // количество уникальных слов
    vector<string> uniqueWords; //массив уникальных слов
    uniqueWords.resize(1);
    vector<int> repetitionWords; //в нЄм собранно количество повторение каждого слова
    repetitionWords.resize(1);

    ifstream fin("C:\\Users\\јлексей\\ѕапка с лабами\\ѕример\\alex\\alex\\input.txt", ifstream::in); // ввод из файла
    ofstream fout("C:\\Users\\јлексей\\ѕапка с лабами\\ѕример\\alex\\alex\\output.txt", ofstream::out); //вывод в файл

    fin.seekg (0, fin.end); // перемещает каретку (|) в конец файла
    int length = fin.tellg(); // получает положение каретки и заполн€ет им переменную length
    fin.seekg (0, fin.beg); //возвращает каретку в начало файла

    vector<char> buffer; //buffer это массив или вектор куда будут считыватьс€ символы
    buffer.resize(length);
    fin.read (&buffer[0], length); //считываетс€ содержимое файла
    //&buffer[0] означает адрес первого элемента вектора, что как раз воспринимаетс€ readom как масси, т.к. fin.read ожидает указатель на массив чаров, а не вектор

    for (int i = 0; i < length; i++) //цикл разбити€ файла на слова
		{
			if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\0') //проверка, если символ не пробел и не перенос на следующую строку, значит это слово
			{
				wordsInput[words] += buffer[i];
			}
			else
			{

				if (wordsInput[words] != "")
				{
					wordsInput.push_back(""); //увел вектор на 1, и заполн€ет этот элемент пустой строчкой
					words++; //значит можно записывать в конец строки с индексом ++
				}
			}
		}
    fin.close();

    for (int i = 1; i <= words; i++) //определение уникальности слова (ищет уникальные слова)
	{
		bool flag = false; //будет true если в списке обнаружетс€ одинаковое слово

		for (int j = 0; j <= uniqueWord; j++) //ищет совпадение слов
		{
			if (wordsInput[i] == uniqueWords[j])
			{
				repetitionWords[j]++;
				flag = true;
			}
		}

        if (!flag)
		{
			uniqueWords[uniqueWord] = wordsInput[i];
			repetitionWords[uniqueWord] = 1;
			uniqueWord++;
			uniqueWords.push_back("");
			repetitionWords.push_back(0);
		}
	}

	//fout.open("output.txt"); //вывод данных в файл
	for (int i = 0; i < uniqueWord; i++)
	{
		uniqueWords[i] += " - ";
		uniqueWords[i] += (repetitionWords[i] + '0');
		uniqueWords[i] += '\n';

		fout << uniqueWords[i];
	}
	fout.close();
    return 0;
}
