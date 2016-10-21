#ifndef GEOFUNCTIONS_H
#define GEOFUNCTIONS_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cstring>

enum Colors {BLUE, GREEN, RED};
void DrawPoint(cv::Mat &img, int x, int y, int color);
void DrawLine(cv::Mat img, int x0, int y0, int x1, int y1, int color);
void FloodFill(cv::Mat img, int x, int y, int outline_color, int replacement_color);
int PointInPolygon(int nvert, int *vertx, int *verty, int testx, int testy);
int *FindPointInPolygon(float point[], int poly_corners, int points_x_vals[], int points_y_vals[]);
int *FindPointInUniquePolygon(int point[], int poly_corners1, int polygon1_x_vals[], int polygon1_y_vals[], int poly_corners2, int polygon2_x_vals[], int polygon2_y_vals[]);
void DrawPolygon(cv::Mat img, std::vector<std::vector<int> > polygon, int outline_color, int fill_color);
void DrawUnion(cv::Mat img, std::vector<std::vector<int> > polygon1, std::vector<std::vector<int> > polygon2, int outline_color, int fill_color);
void DrawIntersection(cv::Mat img, std::vector<std::vector<int> > polygon1, std::vector<std::vector<int> > polygon2, int outline_color1, int fill_color1, int outline_color2, int fill_color2);

#endif
