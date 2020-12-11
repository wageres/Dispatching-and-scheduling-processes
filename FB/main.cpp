#include "FB.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "¬ведите q: ";
	std::cin >> Proces::q;
	std::vector<Proces> vec = { Proces(0,9),Proces(3,5),Proces(5,8),Proces(6,5),Proces(8,6) };
	FB bf(vec);
}