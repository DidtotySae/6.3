#include <iostream>
#include <time.h>
#include <vector>

void BubbleSort(std::vector<int>& number)
{
	for (int i = 0; i < number.size() - 1; i++)
	{
		for (int j = 0; j < number.size() - i - 1; j++)
		{
			if (number[j] > number[j + 1])
			{
				std::swap(number[j], number[j + 1]);
			}
		}
	}
}
void InsertionSort(std::vector<int>& number)
{
	int key = 0;

	for (int i = 1; i < number.size(); i++)
	{
		int j = i - 1;

		key = number[i];

		while (j >= 0 && number[j] > key)
		{
			std::swap(number[j + 1], number[j]);

			j = j - 1;
		}
	}
}


int Index(std::vector<int>& Number, int start, int end)
{
	int pivot = Number[end];
	int i = start - 1;

	for (int j = start; j <= end - 1; j++)
	{
		if (Number[j] < pivot)
		{
			i++;

			std::swap(Number[i], Number[j]);
		}
	}

	std::swap(Number[i + 1], Number[end]);

	return (i + 1);
}

void QuickSort(std::vector<int>& Number, int start, int end)
{

	int PartitionIndex = 0;

	if (start < end)
	{
		PartitionIndex = Index(Number, start, end);

		QuickSort(Number, start, PartitionIndex - 1);
		QuickSort(Number, PartitionIndex + 1, end);
	}
}

int main()
{
	int nb_aleatoire = rand();
	std::vector<int> number;
	srand((unsigned)time(NULL));

	int chiffre;
	int ChooseSort;

	std::cout << "combien de chiffre aleatoire voulez vous ? :";
	std::cin >> chiffre;

	for (int i = 0; i < chiffre; i++) {
		int b = rand() % 1000 + 1;
		number.push_back(b);
		std::cout << number[i] << "\n";
	}
	int start = 0;
	int end = number.size() - 1;

	std::cout << "veuillez choisir une methode de trie: 1 Bubble sort\n2 insertion sort\n3 Quick sort : ";

	std::cin >> ChooseSort;
	switch (ChooseSort)
	{
	case 1: BubbleSort(number);
		std::cout << "\nThe sorted list is: ";
		for (int i = 0; i < number.size(); i++)
		{
			std::cout << number[i] << " ";
		}
		break;
	case 2:InsertionSort(number);
		std::cout << "\nThe sorted list is: ";
		for (int i = 0; i < number.size(); i++)
		{
			std::cout << number[i] << " ";
		}
		break;
	case 3: QuickSort(number, start, end);
		std::cout << "\nThe sorted list is: ";
		for (int i = 0; i < number.size(); i++)
		{
			std::cout << number[i] << " ";
		}
		break;

	}

	InsertionSort(number);

	system("pause");
	return EXIT_SUCCESS;

}