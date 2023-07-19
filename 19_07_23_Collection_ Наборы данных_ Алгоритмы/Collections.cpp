#include<iostream>
#include<random> // создадим для заполнения данными

// Коллекуция для демонстрации работы алгоритмов
#include<vector>
#include<list>

//Библиотека облегчающие обработку коллекций и работу с данными
#include<algorithm>
#include<functional>

// Коллекция это по сути Архив данных( Надо добавлять удалять , перемещать)

bool IsMore(int a, int b) { // За место этого bool можно использоват lamb - лямбда выражения
	return a > b;
}


int main()
{
	
	std::list<int> coll1;
	std::vector<int> coll2;

	std::random_device rd;// Генератор энтропии - это истинно случайных чисел (Беспорядок)
	//std::mt19937 generator(rd());// Генератор псевдо случайных чисел -  высчитывается по формуле от предыдцщего числа ( вот и псевдо)
	std::mt19937 generator(15);
	std::uniform_int_distribution<int> provider(10, 99);// УНИФИЦИРОВАННЫЙ ПОСТАВЩИК ЦЕЛЫХ ЧИСЕЛ (Он при создании требует 2 числа Предел чисел.

	// Сколько совпадающих жлементов в обоих коллекциях
	for (size_t i = 0; i < 20; ++i) {
		coll1.push_back(provider(generator));
		coll2.push_back(provider(generator));
	}

	// Переберем одну из коллекций Алгоритм подсчета Рандомных коллекций (Одинаковые числа
	
	int count{}; // Понадобится счетчик  и его будем добавлять
	//for (const auto& node : coll1) {
	//	for (const auto& el : coll2) {
	//		if (el == node){
	//			count++;
	//			break;
	//		}
	//	}
	//}

	// Второй вариант подсчета одинаковых элементов в коллекциях

	for (const auto& node : coll1) {
		count += std::count(coll2.begin(), coll2.end(), node); // Считает количество повторенйи элем. одного цикла во втором
	}

	std::cout<<count << " duplicate ekements in collection\n";
	for (const auto& node : coll1) {
		std::cout << node << ' ';
	}
	std::cout << '\n';
	for (const auto& el : coll2) {
		std::cout << el << ' ';
	}
	std::cout << '\n';

	// -----------------------
	// Если count > 0 то удаляем
	//if (count > 0) {
	//	std::find(coll2.begin(), coll2.end(), 15); // Ищет во второй коллекции число 15
	//}

	if (count > 0) {
		for (const auto& node : coll1) {
			auto it = std::find(coll2.begin(), coll2.end(), node); // Такое сравнение на 100% попадание если нет уверинности то алгоритм 
			if (it != coll2.end()) {
				coll2.erase(it);
			}
		}
		for (const auto& node : coll2) {
				std:: cout << node << ' ';
		}
		//std::find(coll2.begin(), coll2.end(), 15); // Ищет во второй коллекции число 15
		for (const auto& node : coll2) {
		std::cout << node << ' ';
		}
		std::cout << '\n';
	}

	// min, max, min_ma, sort, shuffle, splist 
	//  IsMore Используем скрытую функцию 
	std::sort(coll2.begin(), coll2.end(), IsMore);


	// lamb - лямбда выражения - Сохрянять их не обязательно. 
	// Нужны чтобы в глобальном не занимать память функциями в глобальном пространстве используют lamb - (отработало и все исчезло) Оно в мейне используется
	/*auto lamb = [](int a, int b) {
		return a > b;
	}*/

	// Так делать нельзя

	//auto lamb = [](int a, int b) -> bool {
	//	return a + b;
	//}
	//else // Так делать нельзя
	//{
	//	return a > b;
	//};

	//std::sort(coll2.begin(), coll2.end(), IsMore);

	// Второй способ правила сортировки в алгоритм 

	/*auto lamb = [](int a, int b) -> bool {
		return a > b;
	};

		std::sort(coll2.begin(), coll2.end(), lamb);*/
		// Пример передачи сохраненного lamb - лямбда выражения

	// Третий способ правила сортировки в алгоритм 

		std::sort(coll2.begin(), coll2.end(), [](int a, int b) -> bool {
			return a > b;
		});

		for (const auto& el : coll2) {
			std::cout << el << ' ';
		}
		std::cout << '\n';

		// Смотри выше  Такое сравнение на 100% попадание если нет уверинности то алгоритм 

	std::find_if(coll2.begin(), coll2.end(), [](int a)-> bool {return true; });



		// {return a>30; } Это когда требования вернуть  a>30 - и она никуда больше не протечет (и никто не воспользуется)

		auto search = std::find_if(coll2.begin(), coll2.end(), [](int a)-> bool {return a>30; });// вернет элемент больше 30 (первый попавшийся если поменять направление coll2.rbegin(), coll2.rend()) 

		// find - ищет полное соответсвие
		// find_if - ищет по любому нужному нам условию

		// Вывод нашего return a>30
		if (search != coll2.end()) {
			std::cout << *search << '\n';
		}

		//Taask1 
		/*
		  в коллекции заполненной случайными значениями надо перенести все повторяющиеся элементы в другую коллекцию
		  перенос осуществляется в единичном экземпяре из первой коллекции все элементы удаляются
		*/

	return 0;
}