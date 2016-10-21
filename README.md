# Computational Geometry
Repo containing projects completed for Computational Geometry (EECS495)

**NOTE:** Memory allocated to the Stack Size must be increased in order for FloodFill algorithm to run.
To do this type `ulimit -s 64000` in the terminal.

# Project 1
## Tasks:
1. Given a polygon, represented by the sequence of its vertices in counter-clockwise order,
highlight is border (pixels corresponding to the edges) and color the interior of the polygon with a
different color.
2. Given two polygons, determine their union and color it red.
3. Given two polygons with different colors, assume that the one who has a smallest x-coordinate
of the vertices is “front” and the other is “rear”. Display the coverage-aware representation of the two
polygons (i.e., find the intersection and color it with the color-value of the “front” polygon).

## Executables:
**Note:** To compile executables, type `make` into the command line while in the parent directory. CMakeLists.txt has specified the build output for this directory.
### DrawPolygon  
**Description:** Draws and fills a polygon using points from a text file which has been passed in through a command line argument.  
**Run Using:** `./DrawPolygon input1.txt`

### PolygonUnion  
**Description:** Draws the union of two polygons in one color using points from a text file which has been passed in through a command line argument.  
**Run Using:** `./PolygonUnion input2.txt`

### PolygonIntersection  
**Description:** Draws the intersection of two polygons and fills the intersection using the fill color of the left-most polygon. The polygons are determined using points from a text file which has been passed in through a command line argument.  
**Run Using:** `./PolygonIntersection input2.txt`

## Other Files:
### geofunctions.cpp
**Description:** Contains custom functions to perform all tasks in the project. Was compiled along with a file containing a "main" function to create each executable.

### input1.txt  
**Description:** A file containing a list of points which define the polygon.

### input2.txt  
**Description:** A file containing a list of points which define two separate polygons.

## Functions Included in geofunctions.cpp:
**DrawPoint:** Draws a point by setting the RGB value of a pixel at a particular location in the image.  
**DrawLine:** Uses Bresenham's Algorithm to determine which pixels to color to form a line.  
**FloodFill:** Recursively fills the interior of a given polygon.  
**PointInPolygon:** Returns an integer indicating whether or not a point is in a given polygon.  
**FindPointInPolygon:** Finds a point in a given polygon.  
**FindPointInUniquePolygon:** Given two polygons, finds a point which is in the first but not the second.
**FindPointInBothPolygons:** Given two polygons, finds a point which is shared by both polygons.  
**DrawPolygon:** Draws and fills a polygon given the points of that polygon.  
**DrawUnion:** Draws and fills the union of two given polygons.  
**DrawIntersection:** Draws and fills the intersection of two given polygons.  
**InputFile:** Parses the desired text file input.  
