#include "geofunctions.h"

using namespace cv;

// Main function
int main(int argc, char *argv[]) {
  //![create_images]
  /// Windows names
  char polygon_window[] = "Polygon Intersection";

  /// Create black empty images
  Mat polygon_image = Mat::zeros(950, 1280, CV_8UC3);
  polygon_image.setTo(cv::Scalar(255,255,255));
  //![create_images]

  // Take in file name from command line argument
  std::string file;
  if (argc != 2) { // argc should be 2 for correct execution
    std::cout << "Error: Incorrect amount of arguments for "<< argv[0] << std::endl;
    std::cout << "Correct formatting: '" << argv[0] << " example.txt'" << std::endl;
    return 1;
  }
  else {
    file = argv[1];
  }

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
