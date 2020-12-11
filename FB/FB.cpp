#include "FB.h"

FB::FB(std::vector<Proces>& process)
{
	int i, time;
	std::queue<Proces*> front_queue;
	std::queue<Proces*> back_queue;
	time = 0;
	for (i = 0; i < process.size(); i++)
	{
		if (process[i].get_appearance_time() <= time)
		{
			front_queue.push(&(process[i]));
		}
		else
		{
			break;
		}
	}
	int number = 0;
	std::cout << "�������� �������: " << '\n';
	while (!front_queue.empty() || !back_queue.empty())
	{
		int lead_time = 0;
		while (!front_queue.empty())
		{
			time++;
			lead_time++;
			--(*front_queue.front());
			std::cout << "������� " << front_queue.front()->get_id() << " �����������.\n";
			if (front_queue.front()->get_time_left() <= 0)
			{
				lead_time = 0;
				front_queue.front()->set_total_time(time);
				std::cout << "������� " << front_queue.front()->get_id() << " ����������!\n\n";
				front_queue.pop();
			}
			if (lead_time >= Proces::q)
			{
				lead_time = 0;
				back_queue.push(front_queue.front());
				front_queue.pop();
			}
			if (i < process.size() && process[i].get_appearance_time() <= time)
			{
				
				front_queue.push(&process[i++]);
				std::cout << "������� " << front_queue.back()->get_id() << " ��������!\n\n";
			}
		}
		std::cout << "������ �������: " << '\n';
		while (!back_queue.empty())
		{
			time++;
			--(*back_queue.front());
			std::cout << "������� " << back_queue.front()->get_id() << " �����������.\n";
			if (back_queue.front()->get_time_left() <= 0)
			{
				back_queue.front()->set_total_time(time);
				std::cout << "������� " << back_queue.front()->get_id() << " ����������!\n\n";
				back_queue.pop();
			}

			if (i < process.size() && process[i].get_appearance_time() <= time)
			{
				front_queue.push(&process[i++]);
				std::cout << "������� " << front_queue.back()->get_id() << " ��������!\n\n";
				break;
			}
		}
	}
	std::cout << "����� �������: " << time << std::endl;
	for (i = 0; i < process.size(); i++)
	{
		process[i].get_statistic();
	}
}