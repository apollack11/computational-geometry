#include "geofunctions.h"

//![drawPoint]
void DrawPoint(cv::Mat img, int x, int y, int color) {
  switch(color) {
    case BLUE:
      img.at<cv::Vec3b>(cv::Point(x, y))[0] = 255;
      img.at<cv::Vec3b>(cv::Point(x, y))[1] = 0;
      img.at<cv::Vec3b>(cv::Point(x, y))[2] = 0;
      break;
    case GREEN:
      img.at<cv::Vec3b>(cv::Point(x, y))[0] = 0;
      img.at<cv::Vec3b>(cv::Point(x, y))[1] = 255;
      img.at<cv::Vec3b>(cv::Point(x, y))[2] = 0;
      break;
    case RED:
      img.at<cv::Vec3b>(cv::Point(x, y))[0] = 0;
      img.at<cv::Vec3b>(cv::Point(x, y))[1] = 0;
      img.at<cv::Vec3b>(cv::Point(x, y))[2] = 255;
      break;
  }
}

//![drawLine]
void DrawLine(cv::Mat img, int x0, int y0, int x1, int y1, int color) {
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
      x1 = -x1;
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

void FloodFill(cv::Mat img, int x, int y, int outline_color, int replacement_color) {
  int outline[3] = {0,0,0};
  switch(outline_color) {
    case BLUE:
      outline[0] = 255;
      outline[1] = 0;
      outline[2] = 0;
      break;
    case GREEN:
      outline[0] = 0;
      outline[1] = 255;
      outline[2] = 0;
      break;
    case RED:
      outline[0] = 0;
      outline[1] = 0;
      outline[2] = 255;
      break;
  }
  int replacement[3] = {0,0,0};
  switch (replacement_color) {
    case BLUE:
      replacement[0] = 255;
      replacement[1] = 0;
      replacement[2] = 0;
      break;
    case GREEN:
      replacement[0] = 0;
      replacement[1] = 255;
      replacement[2] = 0;
      break;
    case RED:
      replacement[0] = 0;
      replacement[1] = 0;
      replacement[2] = 255;
      break;
  }
  if (img.at<cv::Vec3b>(cv::Point(x, y))[0] == replacement[0] && img.at<cv::Vec3b>(cv::Point(x, y))[1] == replacement[1] && img.at<cv::Vec3b>(cv::Point(x, y))[2] == replacement[2]) {
    return;
  }
  else if (img.at<cv::Vec3b>(cv::Point(x, y))[0] == outline[0] && img.at<cv::Vec3b>(cv::Point(x, y))[1] == outline[1] && img.at<cv::Vec3b>(cv::Point(x, y))[2] == outline[2]) {
    return;
  }
  img.at<cv::Vec3b>(cv::Point(x, y))[0] = replacement[0];
  img.at<cv::Vec3b>(cv::Point(x, y))[1] = replacement[1];
  img.at<cv::Vec3b>(cv::Point(x, y))[2] = replacement[2];
  FloodFill(img, x, y-1, outline_color, replacement_color);
  FloodFill(img, x, y+1, outline_color, replacement_color);
  FloodFill(img, x-1, y, outline_color, replacement_color);
  FloodFill(img, x+1, y, outline_color, replacement_color);
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

int *FindPointInUniquePolygon(int point[], int poly_corners1, int polygon1_x_vals[], int polygon1_y_vals[], int poly_corners2, int polygon2_x_vals[], int polygon2_y_vals[]) {
  int max_x = *std::max_element(polygon2_x_vals, polygon2_x_vals + poly_corners2);
  int max_y = *std::max_element(polygon2_y_vals, polygon2_y_vals + poly_corners2);
  int min_x = *std::min_element(polygon2_x_vals, polygon2_x_vals + poly_corners2);
  int min_y = *std::min_element(polygon2_y_vals, polygon2_y_vals + poly_corners2);
  int del_x = max_x - min_x;
  int del_y = max_y - min_y;
  while (!PointInPolygon(poly_corners2, polygon2_x_vals, polygon2_y_vals, point[0], point[1]) || PointInPolygon(poly_corners1, polygon1_x_vals, polygon1_y_vals, point[0], point[1])) {
    point[0] = rand() % del_x + min_x;
    point[1] = rand() % del_y + min_y;
  }
  return point;
}

int *FindPointInBothPolygons(int point[], int poly_corners1, int polygon1_x_vals[], int polygon1_y_vals[], int poly_corners2, int polygon2_x_vals[], int polygon2_y_vals[]) {
  int max_x = *std::max_element(polygon1_x_vals, polygon1_x_vals + poly_corners1);
  int max_y = *std::max_element(polygon1_y_vals, polygon1_y_vals + poly_corners1);
  int min_x = *std::min_element(polygon1_x_vals, polygon1_x_vals + poly_corners1);
  int min_y = *std::min_element(polygon1_y_vals, polygon1_y_vals + poly_corners1);
  int del_x = max_x - min_x;
  int del_y = max_y - min_y;
  while (!PointInPolygon(poly_corners1, polygon1_x_vals, polygon1_y_vals, point[0], point[1]) || !PointInPolygon(poly_corners2, polygon2_x_vals, polygon2_y_vals, point[0], point[1])) {
    point[0] = rand() % del_x + min_x;
    point[1] = rand() % del_y + min_y;
  }
  return point;
}

// Draws the outline and fills a polygon given a set of coordinates for the polygon corners
void DrawPolygon(cv::Mat img, std::vector<std::vector<int> > polygon, int outline_color, int fill_color) {
  int poly_corners = polygon.size();
  // Draw lines to create polygon
  for (int i = 0; i < poly_corners - 1; i++) {
    DrawLine(img, polygon[i][0], polygon[i][1], polygon[i+1][0], polygon[i+1][1], outline_color);
  }
  // X values
  int points_x_vals[poly_corners];
  for (int i = 0; i < sizeof(points_x_vals)/sizeof(*points_x_vals); i++) {
    points_x_vals[i] = polygon[i][0];
  }
  // Y values
  int points_y_vals[poly_corners];
  for (int i = 0; i < sizeof(points_y_vals)/sizeof(*points_x_vals); i++) {
    points_y_vals[i] = polygon[i][1];
  }

  int point[2] = {-1,-1};
  // Find a point in the selected polygon to fill from
  FindPointInPolygon(point, poly_corners, points_x_vals, points_y_vals);
  int fill_x = (int)point[0];
  int fill_y = (int)point[1];
  FloodFill(img, fill_x, fill_y, outline_color, fill_color);
}

// Draws the union of two polygons given two sets of points describing the corners of two polygons
void DrawUnion(cv::Mat img, std::vector<std::vector<int> > polygon1, std::vector<std::vector<int> > polygon2, int outline_color, int fill_color) {
  // Draw the union of the two polygons as one color
  int poly_corners1 = polygon1.size();
  int poly_corners2 = polygon2.size();

  // Draw First Polygon
  DrawPolygon(img, polygon1, outline_color, fill_color);

  // Manually draw second polygon finding a point to fill which is not also in polygon1
  for (int i = 0; i < poly_corners2 - 1; i++) {
    DrawLine(img, polygon2[i][0], polygon2[i][1], polygon2[i+1][0], polygon2[i+1][1], outline_color);
  }

  // Polygon 1 X values
  int polygon1_x_vals[poly_corners1];
  for (int i = 0; i < sizeof(polygon1_x_vals)/sizeof(*polygon1_x_vals); i++) {
    polygon1_x_vals[i] = polygon1[i][0];
  }
  // Poylgon 1 Y values
  int polygon1_y_vals[poly_corners1];
  for (int i = 0; i < sizeof(polygon1_y_vals)/sizeof(*polygon1_y_vals); i++) {
    polygon1_y_vals[i] = polygon1[i][1];
  }
  // Polygon 2 X values
  int polygon2_x_vals[poly_corners2];
  for (int i = 0; i < sizeof(polygon2_x_vals)/sizeof(*polygon2_x_vals); i++) {
    polygon2_x_vals[i] = polygon2[i][0];
  }
  // Polygon 2 Y values
  int polygon2_y_vals[poly_corners2];
  for (int i = 0; i < sizeof(polygon2_y_vals)/sizeof(*polygon2_y_vals); i++) {
    polygon2_y_vals[i] = polygon2[i][1];
  }

  int point[2] = {-1,-1};
  // Find a point that is in polygon2 but not polygon1 so we can fill the remainder of the union
  FindPointInUniquePolygon(point, poly_corners1, polygon1_x_vals, polygon1_y_vals, poly_corners2, polygon2_x_vals, polygon2_y_vals);
  int fill_x = (int)point[0];
  int fill_y = (int)point[1];
  FloodFill(img, fill_x, fill_y, outline_color, fill_color);
}

void DrawIntersection(cv::Mat img, std::vector<std::vector<int> > polygon1, std::vector<std::vector<int> > polygon2, int outline_color1, int fill_color1, int outline_color2, int fill_color2) {
  // Draw the the intersection of the two polygons as the color of the left-most polygon
  int poly_corners1 = polygon1.size();
  int poly_corners2 = polygon2.size();

  int polygon1_x_vals[poly_corners1];
  for (int i = 0; i < sizeof(polygon1_x_vals)/sizeof(*polygon1_x_vals); i++) {
    polygon1_x_vals[i] = polygon1[i][0];
  }
  // Poylgon 1 Y values
  int polygon1_y_vals[poly_corners1];
  for (int i = 0; i < sizeof(polygon1_y_vals)/sizeof(*polygon1_y_vals); i++) {
    polygon1_y_vals[i] = polygon1[i][1];
  }
  // Polygon 2 X values
  int polygon2_x_vals[poly_corners2];
  for (int i = 0; i < sizeof(polygon2_x_vals)/sizeof(*polygon2_x_vals); i++) {
    polygon2_x_vals[i] = polygon2[i][0];
  }
  // Polygon 2 Y values
  int polygon2_y_vals[poly_corners2];
  for (int i = 0; i < sizeof(polygon2_y_vals)/sizeof(*polygon2_y_vals); i++) {
    polygon2_y_vals[i] = polygon2[i][1];
  }

  // Find the left-most point of each polygon
  int min_x1 = *std::min_element(polygon1_x_vals, polygon1_x_vals + poly_corners1);
  int min_x2 = *std::min_element(polygon2_x_vals, polygon2_x_vals + poly_corners2);

  // Set values of fill_color, outline_color, polygon_x_vals, polygon_y_vals, and poly_corners depending on which polygon is left-most
  int fill_color;
  int outline_color;
  if (min_x1 < min_x2) {
    // Polygon 1 is the left-most and should determine the color
    fill_color = fill_color1;
    outline_color = outline_color1;
  }
  else {
    // Polygon 2 is the left-most and should determine the color
    fill_color = fill_color2;
    outline_color = outline_color2;
  }

  // Draw the second polygon first
  for (int i = 0; i < poly_corners2 - 1; i++) {
    DrawLine(img, polygon2[i][0], polygon2[i][1], polygon2[i+1][0], polygon2[i+1][1], outline_color);
  }
  // Draw the first polygon second so it ends up on top
  for (int i = 0; i < poly_corners1 - 1; i++) {
    DrawLine(img, polygon1[i][0], polygon1[i][1], polygon1[i+1][0], polygon1[i+1][1], outline_color);
  }

  int point[2] = {-1, -1};
  // Find a point that is in polygon1 and polygon2
  FindPointInBothPolygons(point, poly_corners1, polygon1_x_vals, polygon1_y_vals, poly_corners2, polygon2_x_vals, polygon2_y_vals);
  int fill_x = (int)point[0];
  int fill_y = (int)point[1];
  FloodFill(img, fill_x, fill_y, outline_color, fill_color);

  // Re-draw polygon2 with accurate outline_color
  for (int i = 0; i < poly_corners2 - 1; i++) {
    DrawLine(img, polygon2[i][0], polygon2[i][1], polygon2[i+1][0], polygon2[i+1][1], outline_color2);
  }
  // Re-draw polygon1 to draw over polygon2
  for (int i = 0; i < poly_corners1 - 1; i++) {
    DrawLine(img, polygon1[i][0], polygon1[i][1], polygon1[i+1][0], polygon1[i+1][1], outline_color1);
  }
}

void InputFile(std::vector<std::vector<int> > &polygon1, std::vector<std::vector<int> > &polygon2, std::string file_name) {
  // create a file-reading object
  std::ifstream file;
  file.open(file_name.c_str()); // open a file

  std::string inputString;
  std::string str;
  std::vector<std::string> word_vector;
  while (file.good()) {
    std::getline(file, str);
    word_vector.push_back(str);
  }

  for (int i = 0; i < word_vector.size(); i++) {
    word_vector[i].erase(std::remove(word_vector[i].begin(), word_vector[i].end(), 'P'), word_vector[i].end());
  }

  int index;
  bool second_poly = false;
  char delimiter1, delimiter2, delimiter3;
  int val1, val2;
  std::vector<int> num_vector;
  for(int i=0; i<word_vector.size(); i++) {
    std::stringstream ss(word_vector[i]);
    ss >> delimiter1 >> val1 >> delimiter2 >> val2 >> delimiter3;
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

  for (int i = 0; i < num_vector.size() - 1; i = i+2) {
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

  if (second_poly) {
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
  }
}
