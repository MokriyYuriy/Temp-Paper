#include "basic_classes.h"

#ifndef PLAYER_H
#define PLAYER_H

class SimplePlayer : public Player {
 public:
    SimplePlayer(Oracle *); 
    Response query(const std::vector <int> &query_string);
};

#endif


