#pragma once
#include <iostream>
class Proces
{
private:
	int appearance_time;
	int lead_time;
	int time_left;
	int queue_number;
	int total_time;
	int time_l;

	
public:
	static int q;
	static int number_of_priorities;

	Proces(int a_t, int l_t);
	int get_appearance_time();
	int get_time_left();
	int get_queue_number();
	int up_queue_number();
	void get_statistic();
	void set_total_time(int time_of_end);
	int get_time_l();
	void up_time_l();
	Proces operator-- ();
};

