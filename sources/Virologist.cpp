#include "Virologist.hpp"
using namespace pandemic;
using namespace std;
Player &Virologist::treat(City c){
//     if(city!=c){
//     throw invalid_argument ("not in the city i need");
// }
// if(city==c){
//     board.update_level(c,board[c]-1);

// }
 if(cards.count(c)==0 && city!=c){
     throw invalid_argument ("not have the card");
 }
if(board[c]==0){
    throw invalid_argument ("aready zero");
}
 if(board.have_cure(Board::get_color(c))){
     board.update_level(c,0);   
 }

if(board[c]>0){
    board.update_level(c,board[c]-1);}
    if(city!=c){cards.erase(c);}
    return *this;
}