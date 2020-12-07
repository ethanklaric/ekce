#ifndef DEFS_H
#define DEFS_H

#include "stdlib.h"

#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed",#n); \
printf("On %s ",__DATE__); \
printf("At %s ",__TIME__); \
printf("In File %s ",__FILE__); \
printf("At Line %d\n",__LINE__); \
exit(1);}
#endif

typedef unsigned long long U64;

#define NAME "ekce 1.0"
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK  };
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

enum { WHITE, BLACK, BOTH };

enum {
  a1 = 21, b1, c1, d1, e1, f1, g1, h1,
  a2 = 31, b2, c2, d2, e2, f2, g2, h2,
  a3 = 41, b3, c3, d3, e3, f3, g3, h3,
  a4 = 51, b4, c4, d4, e4, f4, g4, h4,
  a5 = 61, b5, c5, d5, e5, f5, g5, h5,
  a6 = 71, b6, c6, d6, e6, f6, g6, h6,
  a7 = 81, b7, c7, d7, e7, f7, g7, h7,
  a8 = 91, b8, c8, d8, e8, f8, g8, h8, no_sq
};

enum { FALSE, TRUE };

enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 };

typedef struct {
	
	int move;
	int castlePerm;
	int enPas;
	int fiftyMove;
	U64 posKey;

} S_UNDO;

typedef struct {

	int pieces[BRD_SQ_NUM];
	U64 pawns[3];
		
	int KingSq[2];
	
	int side;
	int enPas;
	int fiftyMove;
	
	int ply;
	int hisPly;
	
	int castlePerm;
	
	U64 posKey;
	
	int pieceNum[13];
	int bigPiece[3];
	int majPiece[3];
	int minPiece[3];
	
	S_UNDO history[MAXGAMEMOVES];
	
	// piece list
	int pList[13][10];	
	
} S_BOARD;

/* MACROS */

#define FR2SQ(f,r) ( (21 + (f) ) + ( (r) * 10 ) ) 

/* GLOBALS */

extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];


/* FUNCTIONS */

extern void AllInit();

// init.c



#endif
