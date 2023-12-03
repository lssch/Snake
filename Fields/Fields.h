//
// Created by Lars Schwarz on 01.12.2023.
//

#ifndef FIELDS_H
#define FIELDS_H

#include "opencv2/opencv.hpp"

class Fields {
public:
  Fields(cv::Mat &img_, int width_);
  void drawGrid();
  void update(std::vector<cv::Point2i> &body);

  int width;
  cv::Point2i grid_size{0,0};
private:
  cv::Point2i gridToPixel(cv::Point2i position);

  cv::Mat img;
};


#endif //FIELDS_H
