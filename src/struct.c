#include <stdio.h>

struct key {
  int attack;
  int left;
  int right;
  int down;
  int up;
  int exit;
  int enter;
};

struct position {
  int x;
  int y;
};

struct player {
  int score;
  int lives;
  int level;
  struct position position;
};

struct spaceship {
  int points;
  struct position position;
};
