#include "Fields/Fields.h"
#include "Snake/Snake.h"

const int rounds_before_snake_gets_longer{5};

cv::Mat image = cv::Mat(cv::Size(600, 600), CV_8UC3, {0,0,0});
Fields field{image, 24};
Snake snake{field, 5};

[[maybe_unused]] void autoplayer() {
  if (snake.getBody().front().x == field.grid_size.x && snake.getDirection() == Direction::EAST)
    snake.setDirection(Direction::SOUTH);
  else if (snake.getBody().front().x == field.grid_size.x && snake.getDirection() == Direction::SOUTH)
    snake.setDirection(Direction::WEST);
  else if (snake.getBody().front().x == 0 && snake.getDirection() == Direction::WEST)
    snake.setDirection(Direction::SOUTH);
  else if (snake.getBody().front().x == 0 && snake.getDirection() == Direction::SOUTH)
    snake.setDirection(Direction::EAST);
  cv::waitKey(50);
}

[[maybe_unused]] void userplayer() {
  snake.setDirection(cv::waitKey(100));
}

int main() {
  int i = 0;
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
  while (true) {
    if (i == rounds_before_snake_gets_longer) {
      snake.move(false);
      i = 0;
    } else
      snake.move(true);
    cv::imshow("Snake von wish", image);
    autoplayer();
    //userplayer();
    i++;
  }
#pragma clang diagnostic pop
  return 0;
}
