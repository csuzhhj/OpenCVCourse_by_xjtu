//学习如何扭曲图像，来扫描文档
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Warp Images
/// </summary>
//float w = 250, h = 350;//图片大小
//Mat matrix, imgWarp;
//void main() {
//	//图片用画图打开，在屏幕左下角会显示点的坐标
//	string path = "Resources/cards.jpg";
//	Mat img=imread(path);//matrix data type 由opencv引入来处理图像
//	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };//Point2f表示浮点数
//	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };//Point2f表示浮点数
//
//	matrix = getPerspectiveTransform(src, dst);
//	warpPerspective(img, imgWarp, matrix, Point(w,h));
//	
//	//确定src坐标是否正确
//	for (int i = 0; i < 4; i++) {
//		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
//	}
//
//	imshow("Image", img);
//	imshow("Image Warp", imgWarp);
//	waitKey(0);//增加延时，0表示无穷
//}