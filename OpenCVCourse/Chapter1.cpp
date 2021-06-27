#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Images
/// </summary>
//void main() {
//	string path = "Resources/test.png";
//	Mat img=imread(path);//matrix data type 由opencv引入来处理图像
//	imshow("Image", img);
//	waitKey(0);//增加延时，0表示无穷
//}


/// <summary>
/// Video
/// //视频是一系列图像，需要遍历所有图像或帧 一一捕获并显示，因此将使用while循环
/// </summary>
//void main() {
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	while (true) {
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(20);//增加延时 20ms
//	}
//	
//}

/// <summary>
/// Webcam
/// 与导入视频不同的是，不需要视频路径，只需要给相机ID，id=0表示默认的摄像头
/// </summary>
//void main() {
//	VideoCapture cap(0);//相机id=0
//	Mat img;
//
	//while (true) {
	//	cap.read(img);
	//	imshow("Image", img);
	//	waitKey(1);//增加延时 1ms，以免太慢
	//}
//
//}
