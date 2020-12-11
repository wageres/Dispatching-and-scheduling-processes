#include "MFQ.h"

MFQ::MFQ(std::vector<Proces>& process)
{
	system("cls");
	std::cout << "Ход выполнения: \n\n";
	int time = 0, i, in_process = 0;
	std::vector<Proces*>to_execute;

	for (i = 0; i < process.size(); i++)
	{
		if (process[i].get_appearance_time() <= time)
		{
			to_execute.push_back(&process[i]);
			in_process++;
		}
		else
		{
			break;
		}
	}
	int max = 0;
	while (in_process > 0)
	{
		for (int j = 0; j < to_execute.size(); j++)
		{
			if (to_execute[j]->get_time_left() > 0)
			{
				if (to_execute[max]->get_time_left() == 0 ||
					to_execute[j]->get_queue_number() < to_execute[max]->get_queue_number() ||
					(to_execute[j]->get_queue_number() == to_execute[max]->get_queue_number()
						&& to_execute[j]->get_appearance_time() < to_execute[max]->get_appearance_time()))
				{
					max = j;
				}
			}
		}
		--(*to_execute[max]);
		time++;
		to_execute[max]->up_time_l();
		std::cout << "Процесс " << max + 1 << " выполняется.  Приоритет: " << to_execute[max]->get_queue_number() << "\n";


		if (to_execute[max]->get_time_l() >= Proces::q*pow(2, to_execute[max]->get_queue_number()))
		{
			to_execute[max]->up_queue_number();
		}
		if (to_execute[max]->get_time_left() <= 0)
		{
			std::cout << "Процесс " << max + 1 << " ВЫПОЛНЕН!\n\n";
			to_execute[max]->set_total_time(time);
			in_process--;
		}

		if (i < process.size() && process[i].get_appearance_time() <= time)
		{
			std::cout << "Процесс " << i + 1 << " ДОБАВЛЕН!\n\n";
			to_execute.push_back(&process[i++]);
			in_process++;
		}
	}
	std::cout << "\n\n\nСтатистика:";
	std::cout << "\nВсего времени:" << time << "\n\n";
	for (i = 0; i < process.size(); i++)
	{
		process[i].get_statistic();
	}
}