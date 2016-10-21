#include "geofunctions.h"

using namespace cv;

/**
 * @function main
 * @brief Main function
 */
int main(void){
  //![create_images]
  /// Windows names
  char polygon_window[] = "Polygon Intersection";

  /// Create black empty images
  Mat polygon_image = Mat::zeros(950, 1280, CV_8UC3);
  polygon_image.setTo(cv::Scalar(255,255,255));
  //![create_images]

  // Define polygons
  std::vector<std::vector<int> > polygon1;
  std::vector<std::vector<int> > polygon2;

  InputFile(polygon1, polygon2, "input2.txt");

  // Draw intersection of the two polygons
  DrawIntersection(polygon_image, polygon1, polygon2, BLUE, BLUE, RED, RED);

  // display images in windows
  imshow(polygon_window, polygon_image);
  moveWindow(polygon_window, 0, 0);

  waitKey(0);
  return(0);
}
