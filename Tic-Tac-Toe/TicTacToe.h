#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iomanip>

class TicTacToe
{
  public:
    TicTacToe();
    void Matrix();
    bool Check();
    void print();
    ~TicTacToe();
  private:
    char** matrix;
};

#endif //TICTACTOE_H