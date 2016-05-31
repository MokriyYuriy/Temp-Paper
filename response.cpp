#include "basic_classes.h"

Response::Response() : cows(0), bulls(0) {}

Response::Response(int cows, int bulls) : cows(cows), bulls(bulls) {}

int Response::get_cows() const {
    return cows; 
}

int Response::get_bulls() const {
    return bulls;
}

int Response::get_cows_and_bulls() const {
    return bulls + cows;
}
