#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

////IMPORTING IMAGE
//void main()
//{
//	string path = "Resources/test.png";
//	//Matrix data type of opencv for images
//	Mat img = imread(path);
//	imshow("Image", img);
//	// waitKey(0) ->0 is for infinity i.e. the image window will not close until we click the close button
//	waitKey(0);
//}

////IMPORTING VIDEO i.e. series of images
//void main()
//{
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//	while (true)
//	{
//		cap.read(img);
//		imshow("Image", img); //at the end there will always be an error as there are no more images to show. 
//		//Since we are learning, it is okay. We know how to code and read+display video
//		//We dont want to wait for infinity as its video. So we can set waitKey for 1ms i.e. waitKey(1). If we want it slower
//		// we can set as waitKey(5);
//		waitKey(20);
//	}	
//}

//WEBCAM
void main()
{
	//if there is only one camera => 0 is the value to put in VideoCapture cap(0). If there are other cams also, you can use 1 etc.
	VideoCapture cap(0);
	Mat img;
	while (true)
	{
		cap.read(img);
		imshow("Image", img); //at the end there will always be an error as there are no more images to show. 
		//Since we are learning, it is okay. We know how to code and read+display video
		//We dont want to wait for infinity as its video. So we can set waitKey for 1ms i.e. waitKey(1). If we want it slower
		// we can set as waitKey(5);
		waitKey(1);
	}
}