//
// Created by Lars Schwarz on 01.12.2023.
//

#include "Snake.h"

Snake::Snake(Fields &field_, int initial_length)
  : field(field_),
    direction(Direction::EAST){
  for (int x = 0; x < initial_length; ++x) {
    body.insert(body.begin(), {x, field.grid_size.y/2});
  }
  field.update(body);
}

void Snake::move(bool erase_tail) {
  switch (direction) {
    case Direction::NORTH:
      if (body.front().y == 0)
        body.insert(body.begin(), {body.front().x, field.grid_size.y});
      else
        body.insert(body.begin(), {body.front().x, body.front().y-1});
      break;
    case Direction::EAST:
      if (body.front().x == field.grid_size.x)
        body.insert(body.begin(), {0, body.front().y});
      else
        body.insert(body.begin(), {body.front().x+1, body.front().y});
      break;
    case Direction::SOUTH:
      if (body.front().y == field.grid_size.y)
        body.insert(body.begin(), {body.front().x, 0});
      else
        body.insert(body.begin(), {body.front().x, body.front().y+1});
      break;
    case Direction::WEST:
      if (body.front().x == 0)
        body.insert(body.begin(), {field.grid_size.x, body.front().y});
      else
        body.insert(body.begin(), {body.front().x-1, body.front().y});
      break;
  }

  if (erase_tail) body.pop_back();

  field.update(body);
}

void Snake::setDirection(int key) {
  if (key == 0 || key == 1 || key == 2 || key == 3)
    direction = static_cast<Direction>(key);
}

void Snake::setDirection(Direction new_direction) {
  direction = new_direction;
}

Direction Snake::getDirection() {
  return direction;
}

std::vector<cv::Point2i> Snake::getBody() {
  return body;
}
