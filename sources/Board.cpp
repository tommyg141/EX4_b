#include "Board.hpp"
using namespace pandemic;
using namespace std;
#include <set>

int &Board::operator[](City s)
{
    
    return temp[s];
}
bool Board::is_clean()
{
    for (auto const &p : temp)
    {
        if (p.second!= 0)
        {
            return false;
        }
    }
    return true;
}
std::ostream &pandemic::operator<<(std::ostream &output, const Board &boaed)
{
    return output;
}
void pandemic::Board::remove_cures()
{
    discovered_cure = set<Color>();
}
bool Board::is_connected(City a, City b){
   return connect_maps.at(a).count(b)!=0;

}
bool Board::check_research_station(City n1){
    return research_station.count(n1)!=0;

}
    void Board::update_station (City c){
        research_station.insert(c);
    }
  void Board::update_cure(Color c){
      
    discovered_cure.insert(c);
  }

  bool Board::have_cure(Color c){
      return (discovered_cure.count(c)!=0 &&discovered_cure.count(c)>=0);
  }
std::map<City, std::set<City>> Board::connect_maps
{
    {Algiers, {Madrid, Paris, Istanbul, Cairo}},
        {Atlanta, {Chicago, Miami, Washington}},
        {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
        {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
        {Beijing, {Shanghai, Seoul}},
        {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
        {BuenosAires, {Bogota, SaoPaulo}},
        {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
        {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
        {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
        {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
        {Essen, {London, Paris, Milan, StPetersburg}},
        {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
        {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
        {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
        {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
        {Johannesburg, {Kinshasa, Khartoum}},
        {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
        {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
        {Kinshasa, {Lagos, Khartoum, Johannesburg}},
        {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
        {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
        {Lima, {MexicoCity, Bogota, Santiago}},
        {London, {NewYork, Madrid, Essen, Paris}},
        {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
        {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
        {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
        {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
        {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
        {Milan, {Essen, Paris, Istanbul}},
        {Montreal, {Chicago, Washington, NewYork}},
        {Moscow, {StPetersburg, Istanbul, Tehran}},
        {Mumbai, {Karachi, Delhi, Chennai}},
        {NewYork, {Montreal, Washington, London, Madrid}},
        {Osaka, {Taipei, Tokyo}},
        {Paris, {Algiers, Essen, Madrid, Milan, London}},
        {Riyadh, {Baghdad, Cairo, Karachi}},
        {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
        {Santiago, {Lima}},
        {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
        {Seoul, {Beijing, Shanghai, Tokyo}},
        {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
        {StPetersburg, {Essen, Istanbul, Moscow}},
        {Sydney, {Jakarta, Manila, LosAngeles}},
        {Taipei, {Shanghai, HongKong, Osaka, Manila}},
        {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
        {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
    {
        Washington, { Atlanta, NewYork, Montreal, Miami }
    }
};
 std::map< City, Color>Board::city_color{
{Algiers ,Black} ,
{Atlanta, Blue} ,
{Baghdad, Black} ,
{Bangkok ,Red },
{Beijing ,Red },
{Bogota ,Yellow}, 
{BuenosAires, Yellow}, 
{Cairo ,Black },
{Chennai ,Black}, 
{Chicago ,Blue },
{Delhi ,Black },
{Essen ,Blue },
{HoChiMinhCity ,Red} ,
{HongKong, Red}, 
{Istanbul ,Black}, 
{Jakarta ,Red },
{Johannesburg ,Yellow} ,
{Karachi ,Black} ,
{Khartoum ,Yellow}, 
{Kinshasa ,Yellow} ,
{Kolkata ,Black },
{Lagos ,Yellow},
{Lima ,Yellow },
{London ,Blue },
{LosAngeles, Yellow} ,
{Madrid ,Blue},
{Manila ,Red },
{MexicoCity ,Yellow} ,
{Miami ,Yellow },
{Milan ,Blue },
{Montreal, Blue} ,
{Moscow, Black },
{Mumbai, Black },
{NewYork, Blue},
{Osaka ,Red },
{Paris ,Blue },
{Riyadh ,Black},
{SanFrancisco, Blue} ,
{Santiago ,Yellow},
{SaoPaulo ,Yellow} ,
{Seoul, Red },
{Shanghai, Red}, 
{StPetersburg, Blue} ,
{Sydney, Red },
{Taipei, Red },
{Tehran, Black}, 
{Tokyo ,Red },
{Washington, Blue} 
};
Color Board::get_color(City c){
    return city_color.at(c);
}
  void Board::update_level(City c , int n  ){
      temp[c] = n;
  }