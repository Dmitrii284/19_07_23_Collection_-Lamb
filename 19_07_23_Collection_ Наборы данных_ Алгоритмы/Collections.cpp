#include<iostream>
#include<random> // �������� ��� ���������� �������

// ���������� ��� ������������ ������ ����������
#include<vector>
#include<list>

//���������� ����������� ��������� ��������� � ������ � �������
#include<algorithm>
#include<functional>

// ��������� ��� �� ���� ����� ������( ���� ��������� ������� , ����������)

bool IsMore(int a, int b) { // �� ����� ����� bool ����� ����������� lamb - ������ ���������
	return a > b;
}


int main()
{
	
	std::list<int> coll1;
	std::vector<int> coll2;

	std::random_device rd;// ��������� �������� - ��� ������� ��������� ����� (����������)
	//std::mt19937 generator(rd());// ��������� ������ ��������� ����� -  ������������� �� ������� �� ����������� ����� ( ��� � ������)
	std::mt19937 generator(15);
	std::uniform_int_distribution<int> provider(10, 99);// ��������������� ��������� ����� ����� (�� ��� �������� ������� 2 ����� ������ �����.

	// ������� ����������� ��������� � ����� ����������
	for (size_t i = 0; i < 20; ++i) {
		coll1.push_back(provider(generator));
		coll2.push_back(provider(generator));
	}

	// ��������� ���� �� ��������� �������� �������� ��������� ��������� (���������� �����
	
	int count{}; // ����������� �������  � ��� ����� ���������
	//for (const auto& node : coll1) {
	//	for (const auto& el : coll2) {
	//		if (el == node){
	//			count++;
	//			break;
	//		}
	//	}
	//}

	// ������ ������� �������� ���������� ��������� � ����������

	for (const auto& node : coll1) {
		count += std::count(coll2.begin(), coll2.end(), node); // ������� ���������� ���������� ����. ������ ����� �� ������
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
	// ���� count > 0 �� �������
	//if (count > 0) {
	//	std::find(coll2.begin(), coll2.end(), 15); // ���� �� ������ ��������� ����� 15
	//}

	if (count > 0) {
		for (const auto& node : coll1) {
			auto it = std::find(coll2.begin(), coll2.end(), node); // ����� ��������� �� 100% ��������� ���� ��� ����������� �� �������� 
			if (it != coll2.end()) {
				coll2.erase(it);
			}
		}
		for (const auto& node : coll2) {
				std:: cout << node << ' ';
		}
		//std::find(coll2.begin(), coll2.end(), 15); // ���� �� ������ ��������� ����� 15
		for (const auto& node : coll2) {
		std::cout << node << ' ';
		}
		std::cout << '\n';
	}

	// min, max, min_ma, sort, shuffle, splist 
	//  IsMore ���������� ������� ������� 
	std::sort(coll2.begin(), coll2.end(), IsMore);


	// lamb - ������ ��������� - ��������� �� �� �����������. 
	// ����� ����� � ���������� �� �������� ������ ��������� � ���������� ������������ ���������� lamb - (���������� � ��� �������) ��� � ����� ������������
	/*auto lamb = [](int a, int b) {
		return a > b;
	}*/

	// ��� ������ ������

	//auto lamb = [](int a, int b) -> bool {
	//	return a + b;
	//}
	//else // ��� ������ ������
	//{
	//	return a > b;
	//};

	//std::sort(coll2.begin(), coll2.end(), IsMore);

	// ������ ������ ������� ���������� � �������� 

	/*auto lamb = [](int a, int b) -> bool {
		return a > b;
	};

		std::sort(coll2.begin(), coll2.end(), lamb);*/
		// ������ �������� ������������ lamb - ������ ���������

	// ������ ������ ������� ���������� � �������� 

		std::sort(coll2.begin(), coll2.end(), [](int a, int b) -> bool {
			return a > b;
		});

		for (const auto& el : coll2) {
			std::cout << el << ' ';
		}
		std::cout << '\n';

		// ������ ����  ����� ��������� �� 100% ��������� ���� ��� ����������� �� �������� 

	std::find_if(coll2.begin(), coll2.end(), [](int a)-> bool {return true; });



		// {return a>30; } ��� ����� ���������� �������  a>30 - � ��� ������ ������ �� �������� (� ����� �� �������������)

		auto search = std::find_if(coll2.begin(), coll2.end(), [](int a)-> bool {return a>30; });// ������ ������� ������ 30 (������ ���������� ���� �������� ����������� coll2.rbegin(), coll2.rend()) 

		// find - ���� ������ �����������
		// find_if - ���� �� ������ ������� ��� �������

		// ����� ������ return a>30
		if (search != coll2.end()) {
			std::cout << *search << '\n';
		}

		//Taask1 
		/*
		  � ��������� ����������� ���������� ���������� ���� ��������� ��� ������������� �������� � ������ ���������
		  ������� �������������� � ��������� ��������� �� ������ ��������� ��� �������� ���������
		*/

	return 0;
}