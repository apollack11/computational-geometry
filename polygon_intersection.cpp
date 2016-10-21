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

  // create a file-reading object
  std::ifstream file;
  file.open("input2.txt"); // open a file
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

  int index;
  bool second_poly = false;
  char delimiter1, delimiter2, delimiter3;
  int val1, val2;
  std::vector<int> num_vector;
  for(int i=0; i<word_vector.size(); i++) {
    std::stringstream ss(word_vector[i]);
    ss >> delimiter1 >> val1 >> delimiter2 >> val2 >> delimiter3;
    std::cout << "delimiter1: " << delimiter1 << std::endl;
    std::cout << "val1: " << val1 << std::endl;
    std::cout << "delimiter2: " << delimiter2 << std::endl;
    std::cout << "val2: " << val2 << std::endl;
    std::cout << "delimiter3: " << delimiter3 << std::endl;
    if (delimiter3 == ',' && i > 2) {
      second_poly = true;
      index = i;
      break;
    }
    else if (val1 > 0 && val1 < 1280 && val2 > 0 && val2 < 1280) {
      num_vector.push_back(val1);
      num_vector.push_back(val2);
    }
  }

  for (int i = 0; i < num_vector.size(); i++) {
    std::cout << "num_vector: [" << i << "]" << num_vector[i] << std::endl;
  }

  for (int i = 0; i < num_vector.size() - 1; i = i+2) {
    std::cout << "i = " << i << std::endl;
    std::vector<int> temp;
    for (int j = 0; j < 2; j++) {
      temp.push_back(num_vector[i+j]);
    }
    polygon1.push_back(temp);
  }

  // Add the first point as the last point to close the polygon
  std::vector<int> temp;
  temp.push_back(polygon1[0][0]);
  temp.push_back(polygon1[0][1]);
  polygon1.push_back(temp);

  for (int i = 0; i < polygon1.size(); i++) {
    for (int j = 0; j < polygon1[i].size(); j++) {
      std::cout << "polgyon: [" << i << "][" << j << "]" << polygon1[i][j] << std::endl;
    }
  }

  if (second_poly) {
    std::cout << "move to 2nd polygon" << std::endl;
    std::vector<int> num_vector2;
    for(int i=index; i<word_vector.size(); i++) {
      std::stringstream ss(word_vector[i]);
      ss >> delimiter1 >> val1 >> delimiter2 >> val2 >> delimiter3;
      if (val1 > 0 && val1 < 1280 && val2 > 0 && val2 < 1280) {
        num_vector2.push_back(val1);
        num_vector2.push_back(val2);
      }
    }
    for (int i = 0; i < num_vector2.size() - 1; i = i+2) {
      std::vector<int> temp;
      for (int j = 0; j < 2; j++) {
        temp.push_back(num_vector2[i+j]);
      }
      polygon2.push_back(temp);
    }
    // Add the first point as the last point to close the polygon
    std::vector<int> temp2;
    temp2.push_back(polygon2[0][0]);
    temp2.push_back(polygon2[0][1]);
    polygon2.push_back(temp2);

    for (int i = 0; i < polygon2.size(); i++) {
      for (int j = 0; j < polygon2[i].size(); j++) {
        std::cout << "polgyon2: [" << i << "][" << j << "]" << polygon2[i][j] << std::endl;
      }
    }
  }

  // Draw intersection of the two polygons
  DrawIntersection(polygon_image, polygon1, polygon2, BLUE, BLUE, RED, RED);

  // display images in windows
  imshow(polygon_window, polygon_image);
  moveWindow(polygon_window, 0, 0);

  waitKey(0);
  return(0);
}
