#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdlib.h>

using namespace cv;

/// Function headers
void DrawPoint(Mat img, int x, int y, char color[]);
void DrawLine(Mat img, int x0, int y0, int x1, int y1, char color[]);
void FloodFill(Mat img, int x, int y, char old_color[], char replacement_color[]);
bool PointInPolygon(int poly_corners, int poly_x[], int poly_y[], int x, int y);

struct Polygon {
  int num_points;
  int points[num_points][2];
  int points_x[];
  int points_y[];
  char outline_color[];
  char fill_color[];
};

/**
 * @function main
 * @brief Main function
 */
int main(void){
  //![create_images]
  /// Windows names
  char polygon_window[] = "Polygon Drawing";

  /// Create black empty images
  Mat polygon_image = Mat::zeros(720, 1280, CV_8UC3);
  polygon_image.setTo(cv::Scalar(255,255,255));
  //![create_images]

  int polygon1[6][2] = {
    {10,10},
    {40,63},
    {70,90},
    {130,70},
    {50,40},
    {10,10}
  };

  int polygon2[4][2] = {
    {200,200},
    {400,200},
    {400,400},
    {200,200}
  };

  int polygon3[5][2] = {
    {700,546},
    {430,500},
    {1000,700},
    {600,400},
    {700,546}
  };

  int polygon1_x_vals[sizeof(polygon1)/sizeof(polygon1[0])];
  for (int i = 0; i < sizeof(polygon1_x_vals)/sizeof(*polygon1_x_vals); i++) {
    polygon1_x_vals[i] = polygon1[i][0];
  }
  int polygon1_y_vals[sizeof(polygon1)/sizeof(polygon1[0])];
  for (int i = 0; i < sizeof(polygon1_y_vals)/sizeof(*polygon1_x_vals); i++) {
    polygon1_y_vals[i] = polygon1[i][1];
  }

  int polygon2_x_vals[sizeof(polygon2)/sizeof(polygon2[0])];
  for (int i = 0; i < sizeof(polygon2_x_vals)/sizeof(*polygon2_x_vals); i++) {
    polygon2_x_vals[i] = polygon2[i][0];
  }
  int polygon2_y_vals[sizeof(polygon2)/sizeof(polygon2[0])];
  for (int i = 0; i < sizeof(polygon2_y_vals)/sizeof(*polygon2_x_vals); i++) {
    polygon2_y_vals[i] = polygon2[i][1];
  }

  int polygon3_x_vals[sizeof(polygon3)/sizeof(polygon3[0])];
  for (int i = 0; i < sizeof(polygon3_x_vals)/sizeof(*polygon3_x_vals); i++) {
    polygon3_x_vals[i] = polygon3[i][0];
  }
  int polygon3_y_vals[sizeof(polygon3)/sizeof(polygon3[0])];
  for (int i = 0; i < sizeof(polygon3_y_vals)/sizeof(*polygon3_x_vals); i++) {
    polygon3_y_vals[i] = polygon3[i][1];
  }


  std::cout << "Drawing Polygon 1" << std::endl;
  for (int i = 0; i < sizeof(polygon1)/sizeof(polygon1[0]) - 1; i++) {
    DrawLine(polygon_image, polygon1[i][0], polygon1[i][1], polygon1[i+1][0], polygon1[i+1][1], "red");
  }
  std::cout << "Drawing Polygon 2" << std::endl;
  for (int i = 0; i < sizeof(polygon2)/sizeof(polygon2[0]) - 1; i++) {
    DrawLine(polygon_image, polygon2[i][0], polygon2[i][1], polygon2[i+1][0], polygon2[i+1][1], "blue");
  }
  std::cout << "Drawing Polygon 3" << std::endl;
  for (int i = 0; i < sizeof(polygon3)/sizeof(polygon3[0]) - 1; i++) {
    DrawLine(polygon_image, polygon3[i][0], polygon3[i][1], polygon3[i+1][0], polygon3[i+1][1], "green");
  }

  bool point_in_poly1 = PointInPolygon(sizeof(polygon1)/sizeof(polygon1[0]), polygon1_x_vals, polygon1_y_vals, 72, 77);
  std::cout << "Is the point in poly1? " << point_in_poly1 << std::endl;

  FloodFill(polygon_image, 76, 68, "white", "green");
  FloodFill(polygon_image, 350, 250, "white", "red");
  FloodFill(polygon_image, 768, 564, "white", "blue");

  // display images in windows
  imshow(polygon_window, polygon_image);
  moveWindow(polygon_window, 0, 100);

  waitKey(0);
  return(0);
}

//![drawPoint]
void DrawPoint(Mat img, int x, int y, char color[]) {
  if (color == "blue") {
    img.at<Vec3b>(Point(x, y))[0] = 255;
    img.at<Vec3b>(Point(x, y))[1] = 0;
    img.at<Vec3b>(Point(x, y))[2] = 0;
  }
  if (color == "green") {
    img.at<Vec3b>(Point(x, y))[0] = 0;
    img.at<Vec3b>(Point(x, y))[1] = 255;
    img.at<Vec3b>(Point(x, y))[2] = 0;
  }
  if (color == "red") {
    img.at<Vec3b>(Point(x, y))[0] = 0;
    img.at<Vec3b>(Point(x, y))[1] = 0;
    img.at<Vec3b>(Point(x, y))[2] = 255;
  }
}

//![drawLine]
void DrawLine(Mat img, int x0, int y0, int x1, int y1, char color[]) {
  // Bresenham's algorithm

  int dx = x1 - x0;
  int dy = y1 - y0;

  int octant = 8;
  int tmp_x0 = 0;
  int tmp_x1 = 0;

  if (dx >= 0 && dy >= 0) {
    if (abs(dx) > abs(dy)) {
      octant = 0;
    }
    else {
      octant = 1;
    }
  }
  else if (dx < 0 && dy >= 0) {
    if (abs(dx) > abs(dy)) {
      octant = 3;
    }
    else {
      octant = 2;
    }
  }
  else if (dx < 0 && dy < 0) {
    if (abs(dx) > abs(dy)) {
      octant = 4;
    }
    else {
      octant = 5;
    }
  }
  else if (dx >= 0 && dy < 0) {
    if (abs(dx) > abs(dy)) {
      octant = 7;
    }
    else {
      octant = 6;
    }
  }

  std::cout << "OCTANT = " << octant << std::endl;

  switch(octant) {
    case 0:
      break;
    case 1:
      tmp_x0 = x0;
      tmp_x1 = x1;
      x0 = y0;
      x1 = y1;
      y0 = tmp_x0;
      y1 = tmp_x1;
      break;
    case 2:
      tmp_x0 = x0;
      tmp_x1 = x1;
      x0 = y0;
      x1 = y1;
      y0 = -tmp_x0;
      y1 = -tmp_x1;
      break;
    case 3:
      x0 = -x0;
      y0 = -y0;
      break;
    case 4:
      x0 = -x0;
      x1 = -x1;
      y0 = -y0;
      y1 = -y1;
      break;
    case 5:
      tmp_x0 = x0;
      tmp_x1 = x1;
      x0 = -y0;
      x1 = -y1;
      y0 = -tmp_x0;
      y1 = -tmp_x1;
      break;
    case 6:
      tmp_x0 = x0;
      tmp_x1 = x1;
      x0 = -y0;
      x1 = -y1;
      y0 = tmp_x0;
      y1 = tmp_x1;
      break;
    case 7:
      y0 = -y0;
      y1 = -y1;
      break;
  }

  dx = x1 - x0;
  dy = y1 - y0;
  int D = 2*dy - dx;
  int y = y0;

  for (int x=x0; x<=x1-1; x=x+1) { // x from x0 to x1-1
    switch(octant) {
      case 0:
        DrawPoint(img, x, y, color);
        break;
      case 1:
        DrawPoint(img, y, x, color);
        break;
      case 2:
        DrawPoint(img, -y, x, color);
        break;
      case 3:
        DrawPoint(img, -x, y, color);
        break;
      case 4:
        DrawPoint(img, -x, -y, color);
        break;
      case 5:
        DrawPoint(img, -y, -x, color);
        break;
      case 6:
        DrawPoint(img, y, -x, color);
        break;
      case 7:
        DrawPoint(img, x, -y, color);
        break;
    }
    if (D >= 0) {
      y = y + 1;
      D = D - dx;
    }
    D = D + dy;
  }
}

void FloodFill(Mat img, int x, int y, char old_color[], char replacement_color[]) {
  // bool point_in_poly = PointInPolygon()
  int old[3] = {0,0,0};
  if (old_color == "blue") {
    old[0] = 255;
    old[1] = 0;
    old[2] = 0;
  }
  if (old_color == "green") {
    old[0] = 0;
    old[1] = 255;
    old[2] = 0;
  }
  if (old_color == "red") {
    old[0] = 0;
    old[1] = 0;
    old[2] = 255;
  }
  if (old_color == "white") {
    old[0] = 255;
    old[1] = 255;
    old[2] = 255;
  }
  int replacement[3] = {0,0,0};
  if (replacement_color == "blue") {
    replacement[0] = 255;
    replacement[1] = 0;
    replacement[2] = 0;
  }
  if (replacement_color == "green") {
    replacement[0] = 0;
    replacement[1] = 255;
    replacement[2] = 0;
  }
  if (replacement_color == "red") {
    replacement[0] = 0;
    replacement[1] = 0;
    replacement[2] = 255;
  }
  if (old_color == replacement_color) {
    std::cout << "old_color is the same as replacement_color" << std::endl;
    return;
  }
  else if (img.at<Vec3b>(Point(x, y))[0] != old[0] || img.at<Vec3b>(Point(x, y))[1] != old[1] || img.at<Vec3b>(Point(x, y))[2] != old[2]) {
    return;
  }
  img.at<Vec3b>(Point(x, y))[0] = replacement[0];
  img.at<Vec3b>(Point(x, y))[1] = replacement[1];
  img.at<Vec3b>(Point(x, y))[2] = replacement[2];
  FloodFill(img, x, y-1, old_color, replacement_color);
  FloodFill(img, x, y+1, old_color, replacement_color);
  FloodFill(img, x-1, y, old_color, replacement_color);
  FloodFill(img, x+1, y, old_color, replacement_color);
  return;
}

bool PointInPolygon(int poly_corners, int poly_x[], int poly_y[], int x, int y) {
  int j = poly_corners - 1;
  bool odd_nodes = false;

  for (int i = 0; i < poly_corners; i++) {
    std::cout << "Current poly_x = " << poly_x[i] << std::endl;
    std::cout << "Current poly_y = " << poly_y[i] << std::endl;
    if (poly_y[i] < y && poly_y[j]>=y || poly_y[j]<y && poly_y[i]>=y) {
      if (poly_x[i] + (y - poly_y[i])/(poly_y[j]-poly_y[i])*(poly_x[j]-poly_x[i]) < x) {
        odd_nodes = !odd_nodes;
      }
    }
    j = i;
  }
  return odd_nodes;
}
