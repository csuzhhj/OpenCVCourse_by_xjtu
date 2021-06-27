//学习如何绘制形状（圆形、矩形、线段）和如何在图片上写字

#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Draw Shapes and Text
/// </summary>
//void main() {
//	//创建空白图像
//	//Scalar(255, 0, 255)，（蓝色：255，0，0），（紫色：255，0，255），（黑色：0，0，0），（白色：255，255，255）
//	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));//(512,512)为图片大小，CV8UC3中8表示每个像素的值从0到255，3表示3个颜色通道BGR,Scalar(255, 0, 0)表示图像将具有的颜色
//	
//	circle(img, Point(256, 256), 155,Scalar(0,69,255),FILLED);//第一个参数：图片，第二个参数是圆心坐标，第三个参数是圆大小，第四个参数是颜色，第五个参数是厚度（可以不写），想要填充可以填FILLED
//	rectangle(img, Point(130,226), Point(382,286),Scalar(255,255,255),FILLED);//第一个Point给矩形左上角坐标，第二个Point给矩形右下角坐标
//	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);//第一个Point是起点坐标、第二个Point是终点坐标
//	putText(img, "zhuhuijin", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);
//	
//	imshow("Image", img);
//	waitKey(0);//增加延时，0表示无穷
//}