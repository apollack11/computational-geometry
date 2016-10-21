#include "geofunctions.h"

using namespace cv;

// Main Function
int main(void){
  //![create_images]
  /// Windows names
  char polygon_window[] = "Polygon Union";

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

  // POLYGON 2 Definition
  int polygon2[7][2] = {
    {285,420},
    {500,225},
    {831,543},
    {625,695},
    {444,710},
    {285,555},
    {285,420}
  };
  // Number of points constituting the polygon
  int poly_corners2 = sizeof(polygon2)/sizeof(polygon2[0]);

  // Draw union of the two polygons
  // DrawUnion(polygon_image, polygon1, poly_corners1, polygon2, poly_corners2, RED, RED);

  // display images in windows
  imshow(polygon_window, polygon_image);
  moveWindow(polygon_window, 0, 0);

  waitKey(0);
  return(0);
}
