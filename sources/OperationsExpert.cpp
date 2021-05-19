#include "OperationsExpert.hpp"
using namespace pandemic;
using namespace std;
Player &OperationsExpert::build(){
    //   if (!cards.count(city))
    // {
    //     throw invalid_argument("not have the right card");
    // }
    if (board.check_research_station(city))
    {
        return *this;
    }
    board.update_station(city);
    cards.erase(this->city);
    return *this;
}
