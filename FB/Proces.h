#pragma once
#include <vector>
#include <iostream>
#include <queue>
class Proces
{
private:
	static int id_generator;
	int id;
	int appearance_time;
	int lead_time;
	int time_left;
	int total_time;


public:
	static int q;
	Proces(int a_t, int l_t);
	int get_appearance_time();
	int get_time_left();
	void get_statistic();
	void set_total_time(int time_of_end);
	int get_id();
	Proces operator-- ();
};



