#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Basic Function
/// </summary>
//void main() {
//	string path = "Resources/test.png";
//	Mat img=imread(path);//matrix data type 由opencv引入来处理图像
//	Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
//
//	cvtColor(img, imgGray, COLOR_BGR2GRAY);//cvt是convert的缩写，将图像从一种颜色空间转换为另一种颜色空间。
//	GaussianBlur(imgGray, imgBlur,Size(7,7),5,0);//使用高斯滤波器模糊图像。该函数将源图像与指定的高斯核进行卷积,Size(7,7)是核大小,数字越大越模糊
//	Canny(imgBlur, imgCanny, 25, 75);//边缘检测，阈值1，2可调，目的：显示更多的边缘
//	
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//创建一个核，增加Size（只能是奇数）会扩张/侵蚀更多
//	dilate(imgCanny, imgDil, kernel);//扩张边缘（增加边缘厚度）
//	erode(imgDil, imgErode, kernel);//侵蚀边缘（减小边缘厚度）
//	imshow("Image", img);
//	imshow("Image Gray", imgGray);
//	imshow("Image Blur", imgBlur);
//	imshow("Image Canny", imgCanny);
//	imshow("Image Dilation", imgDil);
//	imshow("Image Erode", imgErode);
//	waitKey(0);//增加延时，0表示无穷
//}