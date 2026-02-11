#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"
#include "weather.h"

/// @brief calculates the lowest temperature ever
/// @param array includes all days and months of an year
/// @return the lowest temprature ever 
int lowest_temperature(WeatherTable array);


/// @brief creates an array with the highest temperature of each year
/// @param array includes all days and months of an year
/// @param output the array which will contain al the highest temperature per year
/// @param max_year the lastest year
/// @param max_month  the lastest month
/// @param int_max_day the lastest day
void highest_temperature_years(WeatherTable array);



/// @brief calculates in which month there was the highest  rainfall in the year
/// @param array includes all days and months of an year
/// @param output the array which will contain al the months with the highest rainfall per year
/// @param max_year the lastest year
/// @param max_month  the lastest month
/// @param int_max_day the lastest day
void highest_rainfall_month(WeatherTable array);



#endif