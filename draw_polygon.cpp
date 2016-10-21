#include "geofunctions.h"

using namespace cv;

/**
 * @function main
 * @brief Main function
 */
int main(void){
  //![create_images]
  /// Windows names
  char polygon_window[] = "Polygon Drawing";

  /// Create black empty images
  Mat polygon_image = Mat::zeros(950, 1280, CV_8UC3);
  polygon_image.setTo(cv::Scalar(255,255,255));
  //![create_images]

  // POLYGON 1 Definition
  int polygon1[8][2] = {
    {150,300},
    {450,300},
    {570,525},
    {653,780},
    {495,845},
    {350,740},
    {100,345},
    {150,300}
  };
  // Number of points constituting the polygon
  int poly_corners1 = sizeof(polygon1)/sizeof(polygon1[0]);

  // Draw polygon
  DrawPolygon(polygon_image, polygon1, poly_corners1, GREEN, BLUE);

  // display images in windows
  imshow(polygon_window, polygon_image);
  moveWindow(polygon_window, 0, 0);

  waitKey(0);
  return(0);
}
