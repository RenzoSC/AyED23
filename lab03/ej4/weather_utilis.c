#include "weather_utilis.h"
#include <stdlib.h>

int min_temp_hist(WeatherTable array){
    int min_temp;
    if (array != NULL)
    {
        min_temp = array[0][0][0]._min_temp;
    }else{
        fprintf(stderr, "Cannot read array given\n");
        exit(EXIT_FAILURE);
    }
    for(int year=0; year < YEARS; year++){
        for(int month=0; month < MONTHS; month++){
            for (int day = 0; day < DAYS; day++){
                if(min_temp > array[year][month][day]._min_temp){
                    min_temp = array[year][month][day]._min_temp;
                }
            }
        }
    }
    return min_temp;
}

void max_temp_by_year(int maxTemp_bYear[], WeatherTable array){
    int max_temp;
    if (array == NULL)
    {
        fprintf(stderr, "Cannot read array given\n");
        exit(EXIT_FAILURE);
    }
    for(int year=0; year < YEARS; year++){
        max_temp = array[year][0][0]._max_temp;
        for(int month=0; month < MONTHS; month++){
            for (int day = 0; day < DAYS; day++){
                if(max_temp < array[year][month][day]._max_temp){
                    max_temp = array[year][month][day]._max_temp;
                }
            }
        }
        maxTemp_bYear[year] = max_temp;
    }
}

void monthMaxPrecip_per_year(int month_maxPrecp_bYear[],WeatherTable array){
    for(int year=0; year < YEARS; year++){
        int topMonthOfYear=0;
        int topTotalPrepMonth=0;
        for(int month=0; month < MONTHS; month++){
            
            int totalPrepMonth= 0;
            
            for (int day = 0; day < DAYS; day++){
                totalPrepMonth += array[year][month][day]._rainfall;
            }

            if (topTotalPrepMonth<= totalPrepMonth)
            {
                topTotalPrepMonth = totalPrepMonth;
                topMonthOfYear = month;
            }
        }
        month_maxPrecp_bYear[year] = topMonthOfYear;
    }
}