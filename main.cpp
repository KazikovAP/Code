#include <iostream>
#include <cstring>

#define MAXWORDCOUNT 1000
#define MAXSYMBOLCOUNT 10000

using namespace std;

int main()
{
	int currentWordCount = 0;
	int uniqueWordCount = 0;

	char fileInput[MAXSYMBOLCOUNT] = { '\0' };
	string parsedWordInput[MAXWORDCOUNT] = { { "" }, { "" } };
	string uniqueWordArray[MAXWORDCOUNT] = { { "" }, { "" } };

	int repetitionCounterArray[MAXWORDCOUNT] = { 0 };

	FILE* inputFileStream = fopen("C:\\Users\\Алексей\\Папка с лабами\\Пример\\alex\\alex\\input.txt", "r");

	//Разбитие файла на слова при помощи разделительного пробела
	//fgets считывает построчно
	while (fgets(fileInput, MAXSYMBOLCOUNT, inputFileStream) != NULL)
	{
		for (int i = 0; i < MAXSYMBOLCOUNT; i++)
		{
			if (fileInput[i] == '\0')
			{
				break;
			}
			if (fileInput[i] != ' ' && fileInput[i] != '\n')
			{
				parsedWordInput[currentWordCount] += fileInput[i];
			}
			else
			{
				//Если замечен пробел или символ перехода на новую строку, и при этом кандидат на новое слово не пустой, тогда счетчик слов увеличивается
				//В противном случае в пустой индекс запишется другое слово
				if (parsedWordInput[currentWordCount] != "")
				{
					currentWordCount++;
				}
			}
		}
	}

	fclose(inputFileStream);


	//Определение уникальности слова
	for (int i = 1; i <= currentWordCount; i++)
	{
		int elementExists = 0;

		//Цикл проходит по массиву уникальных слов, сравнивая с выбранным считанным словом. Если находится совпадение, переменная переключатель принимает значение 1.
		//При этом счетчик совпадений увеличивается на 1.
		for (int j = 0; j <= currentWordCount; j++)
		{
			if (parsedWordInput[i] == uniqueWordArray[j])
			{
				repetitionCounterArray[j]++;
				elementExists = 1;
			}
		}

		//Если переменная переключатель осталась 0, т.е. такого слова не найдено, оно записывается в уникальные, при этом устанавливая количество повторений этого индекса в 1
		if (!elementExists)
		{
			uniqueWordArray[uniqueWordCount] = parsedWordInput[i];
			repetitionCounterArray[uniqueWordCount] = 1;

			uniqueWordCount++;
		}
	}

	FILE* outputFileStream = fopen("C:\\Users\\Алексей\\Папка с лабами\\Пример\\alex\\alex\\output.txt", "w");

	//Перевод из cstring сначала в правильный выводный формат, потом в массив char для функции fputs.
	for (int i = 0; i < uniqueWordCount; i++)
	{
		char fileOutput[MAXSYMBOLCOUNT] = { '\0' };

		uniqueWordArray[i] += " - ";
		uniqueWordArray[i] += (repetitionCounterArray[i] + '0');
		uniqueWordArray[i] += '\n';
		int j = 0;

		while (uniqueWordArray[i][j] != '\0')
		{
			fileOutput[j] = uniqueWordArray[i][j];
			j++;
		}

		fputs(fileOutput, outputFileStream);
	}

	fclose(outputFileStream);
}
