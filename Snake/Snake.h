//
// Created by Lars Schwarz on 01.12.2023.
//

#ifndef SNAKE_H
#define SNAKE_H

#include "../Fields/Fields.h"

enum class Direction {
  NORTH = 0,
  SOUTH,
  WEST,
  EAST,
};

class Snake {
public:
  Snake(Fields &field_, int initial_length);
  void move(bool erase_tail = true);
  void setDirection(int key);
  void setDirection(Direction new_direction);
  Direction getDirection();
  std::vector<cv::Point2i> getBody();
private:

  Fields &field;
  std::vector<cv::Point2i> body;
  Direction direction;
};

#endif //SNAKE_H
