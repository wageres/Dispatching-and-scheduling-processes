#include "Proces.h"

int Proces::q = 2;

int Proces::id_generator = 0;

Proces::Proces(int a_t, int l_t) : appearance_time(a_t), lead_time(l_t), time_left(l_t)
{
	id = ++id_generator;
}

int Proces::get_appearance_time()
{
	return appearance_time;
}

int Proces::get_time_left()
{
	return time_left;
}



void Proces::get_statistic()
{
	std::cout << "Время появления: " << appearance_time << '\n';
	std::cout << "Время выполнения: " << lead_time << '\n';
	std::cout << "Общее время в системе: " << total_time << '\n';
	std::cout << "Потерянное время: " << (total_time - lead_time) << '\n';
	std::cout << "Отношение рективности: " << static_cast<double>(lead_time) / total_time << '\n';
	std::cout << "Штрафное отношение: " << static_cast<double>(total_time) / lead_time << '\n';
	std::cout << "\n\n";
}

void Proces::set_total_time(int time_of_end)
{
	total_time = time_of_end - appearance_time;
}

int Proces::get_id()
{
	return id;
}

Proces Proces::operator-- ()
{
	time_left--;
	return *this;
}
