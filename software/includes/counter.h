#ifndef __COUNTER_H
#define __COUNTER_H

int COUNTER_get(void);

int COUNTER_set(int new_value);

int COUNTER_get_maximum(void);

void COUNTER_set_maximum(int new_max_value);

int COUNTER_get_minimum(void);

void COUNTER_set_minimum(int new_min_value);

void COUNTER_reset(void);

int COUNTER_increase(void);

int COUNTER_decrease(void);

#endif // __COUNTER_H