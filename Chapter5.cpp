#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//WARP IMAGES

float w = 250, h = 350;
Mat matrix, imgWarp;
void main()
{
	string path = "Resources/cards.jpg";
	Mat img=imread(path);
	//the points I have already checked from our img by opening it on paint and hovering over any particular point and at the 
	//bottom it gives us the coordinate
	Point2f src[4] = { {529,142}, {771, 190}, {405, 395}, {674, 457} };
	Point2f dst[4] = { {0.0f,0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	//Extra - add circles to the points where we cropped/warped
	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey(0);
}