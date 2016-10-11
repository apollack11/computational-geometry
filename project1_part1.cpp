#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

/// Function headers
void DrawPoint(Mat img, int x, int y, char color[]);

/**
 * @function main
 * @brief Main function
 */
int main( void ){

  //![create_images]
  /// Windows names
  char polygon_window[] = "Polygon Drawing";

  /// Create black empty images
  Mat polygon_image = Mat::zeros(720, 1280, CV_8UC3);
  polygon_image.setTo(cv::Scalar(255,255,255));
  //![create_images]

  polygon_image.at<Vec3b>(Point(50, 50))[0] = 255;
  DrawPoint(polygon_image,51,51,"red");
  DrawPoint(polygon_image,52,51,"red");
  DrawPoint(polygon_image,53,51,"red");
  DrawPoint(polygon_image,51,52,"green");
  DrawPoint(polygon_image,52,52,"green");
  DrawPoint(polygon_image,53,52,"green");

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
