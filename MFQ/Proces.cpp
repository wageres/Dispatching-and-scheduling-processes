#include "Proces.h"

int Proces::q = 2;
int Proces::number_of_priorities = 3;

Proces::Proces(int a_t, int l_t): appearance_time(a_t), lead_time(l_t), time_left(l_t)
{
	queue_number = 0;
	time_l = 0;
}

int Proces::get_appearance_time()
{
	return appearance_time;
}

int Proces::get_time_left()
{
	return time_left;
}

int Proces::get_queue_number()
{
	return queue_number;
}

int Proces::up_queue_number()
{
	if (queue_number < number_of_priorities)
	{
		time_l = 0;
		return queue_number++;
	}
	
}


void Proces::get_statistic()
{
	std::cout << "Время появления: " << appearance_time << '\n';
	std::cout << "Время выполнения: " << lead_time << '\n';
	std::cout << "Приоритет: " << queue_number << '\n';
	std::cout << "Общее время в системе: " << total_time << '\n';
	std::cout << "Потерянное время: " << (total_time - lead_time) << '\n';
	std::cout << "Отношение рективности: " << static_cast<double>(lead_time)/total_time << '\n';
	std::cout << "Штрафное отношение: " << static_cast<double>(total_time) / lead_time << '\n';
	std::cout << "\n\n";
}

void Proces::set_total_time(int time_of_end)
{
	total_time = time_of_end - appearance_time;
}

int Proces::get_time_l()
{
	return time_l;
}

void Proces::up_time_l()
{
	time_l++;
}

Proces Proces::operator-- ()
{
	time_left--;
	return *this;
}
