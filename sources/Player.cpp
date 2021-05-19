#include "Player.hpp"
using namespace pandemic;
using namespace std;
#include <set>
const int the_number_of_cards = 5;

Player &Player::take_card(City c)
{
    cards.insert(c);
    return *this;
}
Player &Player::remove_cards()
{
    cards = set<City>();
    return *this;
}
Player &Player::drive(City c)
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
    return *this;
}

Player &Player::fly_direct(City c)
{
    if (city == c)
    {
        throw invalid_argument("you already here");
    }
    if (cards.count(c)==0)
    {
        throw invalid_argument("not");
    }
    cards.erase(c);
    city = c;

    return *this;
}
Player &Player::fly_charter(City c)
{
    if (city == c)
    {
        throw invalid_argument("you already here");
    }
    if (cards.count(city)!=0)
    {
        cards.erase(city);
        city = c;
    }
    else
    {
        throw invalid_argument("dont have the card");
    }
    return *this;
}
Player &Player::fly_shuttle(City c)
{
    if (city == c)
    {
        throw invalid_argument("you already here");
    }
    if (!board.check_research_station(c) || !board.check_research_station(city))
    {
        throw invalid_argument("there no research station in one of the city`s");
    }
    //cards.erase(city);
    city = c;
    return *this;
}
Player &Player::build()
{
    if (cards.count(city)==0)
    {
        throw invalid_argument("not have the right card");
    }
    if (board.check_research_station(city))
    {
        return *this;
    }
    board.update_station(city);
    cards.erase(city);
    return *this;
}

Player &Player::discover_cure(Color c)
{
    int temp = 0;
    // check if there cure already
    if (!board.check_research_station(city))
    {
        throw invalid_argument("not research station");
    }
  
    set<City> temporry;
    for (const auto &p : cards)
    {
        if (Board::get_color(p) == c)
        {
            temp++;
            temporry.insert(p);
        }
    }
        if (temp >= the_number_of_cards)
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
Player &Player::treat(City c)
{
if(city!=c){
    throw invalid_argument ("not in the city i need");
}
if(board[c]==0){
    throw invalid_argument ("aready zero");
}
 if(board.have_cure(Board::get_color(c))){
     board.update_level(c,0);
 }
 
if(board[c]>0){
   board.update_level(c,board[c]-1);}
    return *this;
}
