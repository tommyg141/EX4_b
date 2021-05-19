#include "FieldDoctor.hpp"
using namespace pandemic;
using namespace std;
Player &FieldDoctor::treat(City c)
{
    if (!Board::is_connected(city, c)&&city!=c)
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
        board[c] = board[c] - 1;
    }
    return *this;
}