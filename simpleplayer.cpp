#include "player.h"
#include <iostream>

SimplePlayer::SimplePlayer(Oracul *_oracul) {
    oracul = _oracul;
    score = 0;
    end = false;
}

Response SimplePlayer::query(const std::vector <int> &query_string) {
    Response result;
#ifdef DEBUG
    for (std::size_t i = 0; i < query_string.size(); i++) {
        std::cout << query_string[i] << ' ';
    }
#endif
    result = oracul->query(query_string);
#ifdef DEBUG
    std::cout << "\nbulls:" << result.get_bulls() << " bulls:" << result.get_cows() << '\n';
#endif
    if (result.get_bulls() == 0/*(int)oracul->get_n()*/) {
        end = true;
    }
    score++;
    return result;
}
