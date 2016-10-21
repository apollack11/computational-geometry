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

  // create a file-reading object
  std::ifstream file;
  file.open("input1.txt"); // open a file
  if (!file.good()) {
    return 1; // exit if file not found
  }

  std::string inputString;
  std::string str;
  std::vector<std::string> word_vector;
  while (file.good()) {
    std::getline(file, str);
    std::cout << "Line String: " << str << std::endl;
    word_vector.push_back(str);
  }

  for (int i = 0; i < word_vector.size(); i++) {
    word_vector[i].erase(std::remove(word_vector[i].begin(), word_vector[i].end(), 'P'), word_vector[i].end());
    std::cout << "word_vector: [" << i << "]" << word_vector[i] << std::endl;
  }

  std::vector<int> num_vector;
  char delimiter1, delimiter2, delimiter3;
  int val1, val2;
  for(int i=0; i<word_vector.size(); i++) {
    std::stringstream ss(word_vector[i]);
    ss >> delimiter1 >> val1 >> delimiter2 >> val2 >> delimiter3;
    if (val1 > 0 && val1 < 1280 && val2 > 0 && val2 < 1280) {
      num_vector.push_back(val1);
      num_vector.push_back(val2);
    }
  }

  std::vector<std::vector<int> > polygon;
  for (int i = 0; i < num_vector.size() - 1; i = i+2) {
    std::vector<int> temp;
    for (int j = 0; j < 2; j++) {
      temp.push_back(num_vector[i+j]);
    }
    polygon.push_back(temp);
  }

  // Add the first point as the last point to close the polygon
  std::vector<int> temp;
  temp.push_back(polygon[0][0]);
  temp.push_back(polygon[0][1]);
  polygon.push_back(temp);

  for (int i = 0; i < polygon.size(); i++) {
    for (int j = 0; j < polygon[i].size(); j++) {
      std::cout << "polgyon: [" << i << "][" << j << "]" << polygon[i][j] << std::endl;
    }
  }

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
  DrawPolygon(polygon_image, polygon, poly_corners1, GREEN, BLUE);

  // display images in windows
  imshow(polygon_window, polygon_image);
  moveWindow(polygon_window, 0, 0);

  waitKey(0);
  return(0);
}
