#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/imgcodecs.hpp>
#include<iostream>

using namespace std;
using namespace cv;
/// <summary>
/// BASIC FUNCTIONS: cvtColor(originalimg, destination img, color_BGR2GRAY), Convert to grayscale, GaussianBlur, Canny, Dilation, Erode
/// </summary>
void main()
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgCrop;
	
	//
	//cout << "Size" << img.size();
	resize(img, imgResize, Size(), 0.5, 0.5);

	//roi(x, y, width, height) -> rectagle of interest
	Rect roi(100, 100, 200, 250);
	imgCrop = img(roi);

	imshow("Image", img);
	imshow("Image Resized", imgResize);
	imshow("Image Crop", imgCrop);
	waitKey(0);
}