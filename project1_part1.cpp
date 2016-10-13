#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdlib.h>

using namespace cv;

/// Function headers
void DrawPoint(Mat img, int x, int y, char const* color);
void DrawLine(Mat img, int x0, int y0, int x1, int y1, char const* color);
void FloodFill(Mat img, int x, int y, char const* old_color, char const* replacement_color);
int PointInPolygon(int nvert, int *vertx, int *verty, int testx, int testy);
int *FindPointInPolygon(float point[], int poly_corners, int points_x_vals[], int points_y_vals[]);
void DrawPolygon(Mat img, int points[][2], int poly_corners, char const* outline_color, char const* fill_color);

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

  // POLYGON 1 Definition
  // Points
  int polygon1[6][2] = {
    {10,10},
    {40,63},
    {70,90},
    {130,70},
    {50,40},
    {10,10}
  };
  // number of points
  int poly_corners1 = sizeof(polygon1)/sizeof(polygon1[0]);

  // POLYGON 2 Definition
  // Points
  int polygon2[4][2] = {
    {200,200},
    {400,200},
    {400,400},
    {200,200}
  };
  // number of points
  int poly_corners2 = sizeof(polygon2)/sizeof(polygon2[0]);

  // POLYGON 2 Definition
  // Points
  int polygon3[5][2] = {
    {700,546},
    {430,500},
    {1000,700},
    {600,400},
    {700,546}
  };
  // number of points
  int poly_corners3 = sizeof(polygon3)/sizeof(polygon3[0]);

  // DRAWING POLYGONS
  DrawPolygon(polygon_image, polygon1, poly_corners1, "red", "green");
  DrawPolygon(polygon_image, polygon2, poly_corners2, "blue", "red");
  DrawPolygon(polygon_image, polygon3, poly_corners3, "green", "blue");

  // display images in windows
  imshow(polygon_window, polygon_image);
  moveWindow(polygon_window, 0, 100);

  waitKey(0);
  return(0);
}

//![drawPoint]
void DrawPoint(Mat img, int x, int y, char const* color) {
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
void DrawLine(Mat img, int x0, int y0, int x1, int y1, char const* color) {
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

void FloodFill(Mat img, int x, int y, char const* old_color, char const* replacement_color) {
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

// from: http://stackoverflow.com/questions/217578/how-can-i-determine-whether-a-2d-point-is-within-a-polygon
int PointInPolygon(int nvert, int *vertx, int *verty, int testx, int testy) {
  int i, j, c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((verty[i]>testy) != (verty[j]>testy)) &&
     (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
       c = !c;
  }
  return c;
}

int *FindPointInPolygon(int point[], int poly_corners, int points_x_vals[], int points_y_vals[]) {
  std::cout << "Finding a point in the given polygon" << std::endl;
  std::cout << *std::max_element(points_x_vals, points_x_vals + poly_corners) << std::endl;
  std::cout << *std::max_element(points_y_vals, points_y_vals + poly_corners) << std::endl;
  int max_x = *std::max_element(points_x_vals, points_x_vals + poly_corners);
  int max_y = *std::max_element(points_y_vals, points_y_vals + poly_corners);
  int min_x = *std::min_element(points_x_vals, points_x_vals + poly_corners);
  int min_y = *std::min_element(points_y_vals, points_y_vals + poly_corners);
  int del_x = max_x - min_x;
  int del_y = max_y - min_y;
  while (!PointInPolygon(poly_corners, points_x_vals, points_y_vals, point[0], point[1])) {
    point[0] = rand() % del_x + min_x;
    point[1] = rand() % del_y + min_y;
  }
  return point;
}

void DrawPolygon(Mat img, int points[][2], int poly_corners, char const* outline_color, char const* fill_color) {
  std::cout << "DRAWING POLYGON" << std::endl;
  // X values
  int points_x_vals[poly_corners];
  for (int i = 0; i < sizeof(points_x_vals)/sizeof(*points_x_vals); i++) {
    points_x_vals[i] = points[i][0];
  }
  // Y values
  int points_y_vals[poly_corners];
  for (int i = 0; i < sizeof(points_y_vals)/sizeof(*points_x_vals); i++) {
    points_y_vals[i] = points[i][1];
  }

  for (int i = 0; i < poly_corners - 1; i++) {
    DrawLine(img, points[i][0], points[i][1], points[i+1][0], points[i+1][1], outline_color);
  }

  int point[2] = {-1,-1};
  FindPointInPolygon(point, poly_corners, points_x_vals, points_y_vals);
  int fill_x = (int)point[0]; // 250
  int fill_y = (int)point[1]; // 350
  FloodFill(img, fill_x, fill_y, "white", fill_color);
}
