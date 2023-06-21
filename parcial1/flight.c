/*
  @file layover.c
  @brief Implements flight structure and methods
*/
#include <stdlib.h>
#include "flight.h"

static const int AMOUNT_OF_FLIGHT_VARS = 3 ;

Flight flight_from_file(FILE* file, char code)
{
    /* COMPLETAR */
    Flight flight;
    flight.code = code;
    int type, time, passangers, res;
    res = fscanf(file, "%d %d %d ", &type, &time, &passangers);
    if (res != AMOUNT_OF_FLIGHT_VARS)
    {
        fprintf(stderr, "Invalid file.\n");
        exit(EXIT_FAILURE);
    }
    if (type !=0 && type !=1)
    {   
        fprintf(stderr, "Invalid flight type.\n");
        exit(EXIT_FAILURE);
    }
    if (time <1 || time >24)
    {
        fprintf(stderr, "Invalid arrival hour.\n");
        exit(EXIT_FAILURE);
    }
    flight.hour = time;
    flight.passengers_amount = passangers;
    flight.type = type;
    return flight;
}