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
	Mat imgGray;
	Mat imgBlur, imgCanny, imgDil, imgErode;

	//convert to grayscale
	//OpenCV has a convention of BGR rather than RGB
	//imgGray is the destination img
	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	//Size is size of kernel -> 7*7; Then we have sigma value which in our case is 5 and 0.
	//We can press ctrl+Func to understand meaning of sigma value or we can directly keep altering the range and see the result.
	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
	//50 and 150 are 2 thresholds. We can playaround to find how modifying it, our img changes.
	Canny(imgBlur, imgCanny, 50, 150);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);

	imshow("Image Erode", imgErode);
	imshow("Image Dilation", imgDil);
	imshow("Image Canny", imgCanny);
	imshow("Image Blur", imgBlur);
	imshow("Image", img);
	imshow("Image Gray", imgGray);
	
	waitKey(0);
}