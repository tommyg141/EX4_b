#include "Dispatcher.hpp"
using namespace pandemic;
using namespace std;
Player &Dispatcher::fly_direct(City c)
{
    if (city == c)
    {
        throw invalid_argument("already here");
    }
    if ( !board.check_research_station(city) )
    {
        if (cards.count(c)==0)
        {
            throw invalid_argument("not have station and card ");
        }
        city = c;
        cards.erase(c);
    }
    city = c;
    return *this;
}