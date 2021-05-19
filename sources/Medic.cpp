#include "Medic.hpp"
using namespace pandemic;
using namespace std;
Player &Medic::treat(City c)
{
    if (city != c)
    {
        throw invalid_argument("not in the city i need");
    }
    if (board[c] == 0)
    {
        throw invalid_argument("aready zero");
    }
    if (board.have_cure(Board::get_color(c)))
    {
        board.update_level(c, 0);
    }
    if (board[c] > 0)
    {
        board.update_level(c, 0);
    }
    return *this;
}
Player &Medic::drive(City c)
{
    if (city == c)
    {
        throw invalid_argument("you now at the same city");
    }
    if (!Board::is_connected(city, c))
    {
        throw invalid_argument("no way there");
    }
    city = c;
     if (board.have_cure(Board::get_color(c)))
    {
        board.update_level(c, 0);
    }
    return *this;
}
Player &Medic::fly_direct(City c)
{
    if (city == c)
    {
        throw invalid_argument("you already here");
    }
    if (cards.count(c)==0)
    {
        throw invalid_argument("not");
    }
  if (board.have_cure(Board::get_color(c)))
    {
        board.update_level(c, 0);
    }
    cards.erase(c);
    city = c;

    return *this;
}
Player &Medic::fly_charter(City c)
{
    if (city == c)
    {
        throw invalid_argument("you already here");
    }
    if (cards.count(city)!=0)
    {
      if (board[c] > 0 &&board.have_cure(Board::get_color(c)))
    {
        board.update_level(c, 0);
    } 
    
        cards.erase(city);
        city = c;
    }
    else
    {
        throw invalid_argument("dont have the card");
    }
    return *this;
}
Player &Medic::fly_shuttle(City c)
{
    if (city == c)
    {
        throw invalid_argument("you already here");
    }
    if (!board.check_research_station(c) || !board.check_research_station(city))
    {
        throw invalid_argument("there no research station in one of the city`s");
    }
   if (board[c] > 0)
    {
        board.update_level(c, 0);
    }
    cards.erase(city);
    city = c;
    return *this;
}
