#ifndef MOVES_H_
#define MOVES_H_

#include "Chess.h"


#define direction(x) ((x>3)? (2): (1))
#define up_down(x) ((x%2<1)? (3): (1))
#define left_right(x) (((x/2)%2<1)? (3):(1))

#define direction_to_go(x) ((x>3)? deg_0_180(x%4): deg_180_360(x%4))
#define deg_0_180(x) ((x>1)? or_0_45(x%2): or_90_135(x%2))
#define deg_180_360(x) (((x>1)? or_180_225(x%2):or_270_315(x%2))
#define or_0_45(x) ((x>0)? (12): (22))
#define or_90_135(x) ((x%2>0)? (21):(20))
#define or_180_225(x) ((x>0)? (10): (0))
#define or_270_315(x) ((x%2>0)? (1):(2))


#define type(color,i) ((color)? (white_Orthogonal_Diagonal(i)):(black_Orthogonal_Diagonal(i)))
#define white_Orthogonal_Diagonal(i) ((i%2<1)? (WHITE_B):(WHITE_R))
#define black_Orthogonal_Diagonal(i) ((i%2<1)? (BLACK_B):(BLACK_R))
#define QUEEN(color) ((color)? (WHITE_Q):(BLACK_Q))
#define KNIGHT(color) ((color)? (WHITE_N):(BLACK_N))
#define KING(color) ((color)? (WHITE_K):(BLACK_K))
#define ROOK(color) ((color)? (WHITE_R):(BLACK_R))


int isWhite(char c);

int isBlack(char c);

int isCheck(char Board[BOARD_SIZE][BOARD_SIZE], int color);

Move *createMove(int x, int y, int xnew, int ynew, char type);

Move *legalMove(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, int xnew, int ynew, int color, Move *moves);

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);

int isKingMove(int color);

int whichRook(int color, int side);

Move *pawnMovesList(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, int color, Move *moves);

Move *bishopMovesList(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, int color, Move *moves);

Move *rookMovesList(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, int color, Move *moves);

Move *knightMovesList(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, int color, Move *moves);

Move *getMoves(char board[BOARD_SIZE][BOARD_SIZE], int color);

Move *castelingMove(char Board[BOARD_SIZE][BOARD_SIZE], int color, int side, Move *moves);

int isEmpty(char board[BOARD_SIZE][BOARD_SIZE], int color, int side);

#endif
