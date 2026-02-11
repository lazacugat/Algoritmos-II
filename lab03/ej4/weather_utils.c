#include "array_helpers.h"
#include "weather.h"
#include "weather_utils.h"
#include <limits.h>

int lowest_temperature(WeatherTable array){
    int lowest_temp = INT_MAX;
    for (int years = 0; years < YEARS; years++){

        for (int months = 1; months < MONTHS; months++){
        
            for (int days = 1; days < DAYS; days++){
                if (array[years][months][days]._min_temp < lowest_temp)
                {
                    lowest_temp = array[years][months][days]._min_temp;
                }
            }
        }
    }
    printf("\nThe lowest temperature ever is : %d \n\n", lowest_temp);
    return lowest_temp;
}

void highest_temperature_years(WeatherTable array){
    int highest_temp_ye[YEARS];
    int highest_temp;
    int printyears = FST_YEAR;
    printf("The highest temperatures from 1980 to 2016 per year were: \n[");
    for (int years = 0; years < YEARS; years++)
    {
        highest_temp = INT_MIN;
        for (int months = 1; months < MONTHS; months++)
        {
            for (int days = 1; days < DAYS; days++)
            {
                if (highest_temp < array[years][months][days]._max_temp)
                {
                    highest_temp = array[years][months][days]._max_temp;
                }
            }
            
        }
        highest_temp_ye[years] = highest_temp;
        printf("%d : %d", printyears, highest_temp_ye[years]);
        if ((YEARS-1) != years)
        {
            printf(", ");
        }
        else
            printf("] \n\n");       
        printyears ++;
    }
}

void highest_rainfall_month(WeatherTable array){
    int highest_rainfall[YEARS];
    int most_rainy_month;
    int precipitation_counter;
    int precipitation_total;
    int printyears = FST_YEAR;
    printf("The highest rainfall from 1980 to 2016 per year were in the month: \n[");
    for (int years = 0; years < YEARS; years++){
        
        most_rainy_month = 1;
        precipitation_total = INT_MIN;

        for (int  months = 0;  months < MONTHS;  months++)
        {
            precipitation_counter = 0;
            for (int days = 0; days < DAYS; days++)
            {
                precipitation_counter = precipitation_counter + array[years][months][days]._rainfall;
            }
            if (precipitation_counter > precipitation_total)
            {
                precipitation_total = precipitation_counter;
                most_rainy_month = months;
            }
            
        }
        highest_rainfall[years] = most_rainy_month;   
        printf("%d : %d", printyears, highest_rainfall[years] + 1);
        if ((YEARS-1) != years)
        {
            printf(", ");
        }
        else
            printf("] \n\n");       
        printyears ++;  
    }
}


