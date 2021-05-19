
#pragma once
#include <map>
#include "City.hpp"
#include "Color.hpp"
#include <set>
using namespace std;
namespace pandemic
{
  class Board

  {
    
    set<City> research_station;
    set<Color> discovered_cure;
    static std::map<City, std::set<City>> connect_maps;
    std::map<City, int> temp;
     static std::map< City,  Color> city_color;

  public:
    Board() {};
    bool is_clean();
    int &operator[](City s);
    friend std::ostream &operator<<(std::ostream &output, const Board &boaed);
    void remove_cures();
    void remove_station();
   static bool is_connected(City a, City b);
    bool check_research_station(City n1);
    static Color get_color(City c);
    void update_cure(Color c);
    void update_station(City c);
    void update_level(City c , int n  );
    bool have_cure(Color c);
  };

}