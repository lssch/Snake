//
// Created by Lars Schwarz on 01.12.2023.
//

#include "Fields.h"

Fields::Fields(cv::Mat &img_, int width_)
  : img(img_),
    width(width_) {
  if (img.cols%width != 0) throw std::invalid_argument("image width is not a multiple of grid width");
  if (img.rows%width != 0) throw std::invalid_argument("image height is not a multiple of grid width");

  grid_size = {img.cols/width, img.rows/width};
}

void Fields::drawGrid() {
  // Draw vertical lines
  for (int x = 0; x < grid_size.x; ++x)
    cv::line(img, {x*width, 0}, {x*width, img.cols}, {255,255,255});

  // Draw horizontal lines
  for (int y = 0; y < grid_size.y; ++y)
    cv::line(img, {0, y*width}, {img.rows, y*width}, {255,255,255});
}

cv::Point2i Fields::gridToPixel(cv::Point2i position) {
  return {position.x*img.cols/grid_size.x - grid_size.x, position.y*img.rows/grid_size.y - grid_size.y};
}

void Fields::update(std::vector<cv::Point2i> &body) {
  img.setTo(cv::Scalar(0,0,0));

  drawGrid();

  for (const auto &link: body) {
    if (link == body.front())
      cv::circle(img, gridToPixel(link), width/2, {255,0,0}, -1);
    else
      cv::circle(img, gridToPixel(link), width/2, {0,255,0}, -1);
  }
}
