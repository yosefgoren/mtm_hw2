#include "Auxiliaries.h"

#include <random>
#include <math.h>

bool closeToOne(double num){
    return fabs(num - 1.0) < PROBABILITY_DEVIATION_TOLERANCE;
}

double getRandomUniform(double range_start, double range_end){
    return (double(rand()%10000)/10000)*(range_end-range_start)+range_start;
}