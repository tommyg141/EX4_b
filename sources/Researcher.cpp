#include "Researcher.hpp"
using namespace pandemic;
using namespace std;
const int the_number_of_cards = 5;
Player &Researcher::discover_cure(Color c){
     int temp = 0;
    // check if there cure already
    // if (!board.check_research_station(city))
    // {
    //     throw invalid_argument("not research station");
    // }
  
    set<City> temporry;
    for (const auto &p : cards)
    {
        if (Board::get_color(p) == c)
        {
            temp++;
            temporry.insert(p);
        }
    }
        if (temp >=  the_number_of_cards)
        {
            board.update_cure(c);
            for (auto p : temporry)
            {
                cards.erase(p);
            }
        }
        else
        {
            throw invalid_argument("not have inough cards");
        }
    
    return *this;
}