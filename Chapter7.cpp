#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void getContours(Mat imgDil, Mat img)
{
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 10);
	////if its rectangle, it will have 4 points
	
	
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());

		string objectType;
		cout << area << endl;
		
		if (area > 1000)
		{
			//perimeter
			float peri = arcLength(contours[i], true);
			//find the number of corner point or curves that this polygon have. If polygon has 3 corner points then its triangle, if it has a lot then its circle etc
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 10);
			//finding the number of edges i.e. if edge 3 its triagle
			cout << conPoly[i].size() << endl;
			//to find the bounding rectange
			boundRect[i] = boundingRect(conPoly[i]);
			//rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

			int objCor = (int)conPoly[i].size();
			if (objCor == 3)
				objectType = "Tri";
			if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				if(aspRatio>0.95 && aspRatio<1.05)
					objectType = "Square";
				else
					objectType = "Rect";
			}
			
			if (objCor > 4)
				objectType = "Circle";

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 10);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x, boundRect[i].y-5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 1);
			
		}
	}
}
Mat imgCanny, imgBlur, imgDil, imgGray, imgErode;
void main()
{
	string path = "Resources/shapes.png";
	Mat img = imread(path);

	//Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
	//50 and 150 are 2 thresholds. We can playaround to find how modifying it, our img changes.
	Canny(imgBlur, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	/*imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilate", imgDil);*/
	waitKey(0);
}