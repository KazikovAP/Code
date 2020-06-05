#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int words; //колличество слов посчитанных на данный момент
    vector<string> wordsInput; //массив содержащий отдельные слова
    int uniqueWord; // количество уникальных слов
    vector<string> uniqueWords; //массив уникальных слов
    vector<int> repetitionWords; //в нём собранно количество повторение каждого слова

    ifstream fin("C:\\Users\\Алексей\\Папка с лабами\\Пример\\alex\\alex\\input.txt", ifstream::in); // ввод из файла
    ofstream fout("C:\\Users\\Алексей\\Папка с лабами\\Пример\\alex\\alex\\output.txt", ofstream::out); //вывод в файл

    fin.seekg (0, fin.end); //считывается длина файла
    int length = fin.tellg(); //length длина которая считывается
    fin.seekg (0, fin.beg);

    char* buffer; //buffer это массив или вектор куда будут считываться символы
    fin.read (buffer, length); //считывается содержимое файла

    for (int i = 0; i < length; i++) //цикл разбития файла на слова
		{
			if (buffer[i] != ' ' && buffer[i] != '\n') //проверка, если символ не пробел и не перенос на следующую строку, значит это слово
			{
				wordsInput[words] += buffer[i];
			}
			else
			{

				if (wordsInput[words] != "")
				{
					words++; //значит можно записывать в конец строки с индексом ++
				}
			}
		}
    fin.close();

    for (int i = 1; i <= words; i++) //определение уникальности слова (ищет уникальные слова)
	{
		bool flag = false; //будет true если в списке обнаружется одинаковое слово

		for (int j = 0; j <= words; j++) //ищет совпадение слов
		{
			if (wordsInput[i] == uniqueWords[j])
			{
				repetitionWords[j]++;
				bool flag = true;
			}
		}

        if (!flag)
		{
			uniqueWords[uniqueWord] = wordsInput[i];
			repetitionWords[uniqueWord] = 1;

			uniqueWord++;
		}
	}

	fout.open("output.txt"); //вывод данных в файл
	for (int i = 0; i < uniqueWord; i++)
	{
		//vector<char> outputs; //в него будет собиратся всё что нужно вынести в файл

		uniqueWords[i] += " - ";
		uniqueWords[i] += (repetitionWords[i]);
		uniqueWords[i] += '\n';

		fout << uniqueWords[i];
	}
	fout.close();
    return 0;
}
