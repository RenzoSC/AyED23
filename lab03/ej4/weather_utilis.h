#ifndef _WHEATER_UTILIS_H
#define _WHEATER_UTILIS_H
#include "array_helpers.h"

int min_temp_hist(WeatherTable array);

void max_temp_by_year(int maxTemp_bYear[], WeatherTable array); 


void monthMaxPrecip_per_year(int month_maxPrecp_bYear[], WeatherTable array); 
#endif