#include <p18cxxx.h>

static int unique_counter = 0;
static int max_value = 999;
static int min_value = 0;

int
COUNTER_get(void)
{
	return unique_counter;
}

int
COUNTER_set(int new_value)
{
	if(new_value < min_value)
	{
		unique_counter = min_value;
	}
	else if(new_value > max_value)
	{
		unique_counter = max_value;
	}
	else
	{
		unique_counter = new_value;
	}
}

int
COUNTER_get_maximum(void)
{
	return max_value;
}

void
COUNTER_set_maximum(int new_max_value)
{
	max_value = new_max_value;
}

int
COUNTER_get_minimum(void)
{
	return min_value;
}

void
COUNTER_set_minimum(int new_min_value)
{
	min_value = new_min_value;
}

void
COUNTER_reset(void)
{
	unique_counter = min_value;
}

int
COUNTER_increase(void)
{
	return COUNTER_set(unique_counter + 1);
}

int
COUNTER_decrease(void)
{
	return COUNTER_set(unique_counter - 1);
}

