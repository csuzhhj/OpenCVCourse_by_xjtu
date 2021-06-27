#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


/// <summary>
/// Project 1
/// 使用HSV空间检测颜色、找到轮廓所在位置、取轮廓的位置然后创建一个圆
/// </summary>

//Mat img;
//vector<vector<int>> newPoints;
//
//vector<vector<int>> myColors{ {98,109,54,127,255,255},//蓝色（hmin smin vmin hmax smax vmax）
//								{35,0,0,77,245,255} };//绿色（hmin smin vmin hmax smax vmax）
//
//vector<Scalar> myColorValues{ {255,0,255},//蓝色
//								{0,255,0} };//绿色
//
////! 获取轮廓
//Point getContours(Mat imgDil) {//imgDil是传入的扩张边缘的图像用来查找轮廓，img是要在其上绘制轮廓的图像
//	vector<vector<Point>> contours;//轮廓检测到的轮廓。每个轮廓线存储为一个点的向量
//
//	vector<Vec4i> hierarchy;//包含关于映像拓扑的信息  typedef Vec<int, 4> Vec4i;具有4个整数值
//
//	//在二值图像中查找轮廓。该函数利用该算法从二值图像中提取轮廓
//	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);//img：要绘制轮廓在什么图片上，contours：要绘制的轮廓，-1定义要绘制的轮廓号（-1表示所有轮廓），Saclar表示轮廓颜色，2表示厚度
//	
//	vector<vector<Point>> conPoly(contours.size());//conploy的数量应小于contours
//	vector<Rect> boundRect(contours.size());
//
//	Point myPoint(0, 0);
//
//	//过滤器：通过轮廓面积来过滤噪声
//	for (int i = 0; i < contours.size(); i++) {//遍历检测到的轮廓
//		int area = contourArea(contours[i]);
//		
//		//cout << area << endl;
//
//		string objectType;
//		if (area > 1000) {//轮廓面积＞1000才绘制
//			//计算轮廓周长或凹坑长度。该函数计算了曲线长度和封闭的周长。
//			float peri = arcLength(contours[i], true);//计算封闭轮廓周长
//			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);//以指定的精度近似多边形曲线。第二个参数conPloy[i]存储近似的结果，是输出。
//
//			boundRect[i] = boundingRect(conPoly[i]);//计算边界矩形
//
//			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
//			myPoint.y = boundRect[i].y;
//
//			rectangle/*绘制边界矩形*/(img, boundRect[i].tl()/*tl()：topleft矩形左上角坐标*/, boundRect[i].br()/*br()：bottom right矩形右下角坐标*/, Scalar(0, 255, 0), 5);
//			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
//			
//		}
//	}
//	return myPoint;
//}
//
//
//vector<vector<int>> findColor(Mat img) {
//	Mat imgHSV;
//	cvtColor(img, imgHSV, COLOR_BGR2HSV);//转换图像到HSV空间，在其中查找颜色更加容易
//
//	for (int i = 0; i < myColors.size(); i++)
//	{
//		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
//		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
//		Mat mask;
//		inRange(imgHSV, lower, upper, mask);//定义颜色下限和上限，因为由于照明和不同的阴影，颜色的值将不完全相同，会是一个值的范围
//		//imshow(to_string(i), mask);
//		Point myPoint=getContours(mask);
//		if (myPoint.x != 0 && myPoint.y != 0) {//没检测到东西的时候就不加入新点
//			newPoints.push_back({ myPoint.x,myPoint.y,i });//i为颜色索引
//		}
//	}
//	return newPoints;
//	
//}
//
//void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues) {
//	for (int i = 0; i < newPoints.size(); i++) {
//		circle(img, Point(newPoints[i][0], newPoints[i][1]),6,myColorValues[newPoints[i][2]],FILLED);
//	}
//}
//
//void main() {
//	VideoCapture cap(0);//相机id=0
//	
//
//	while (true) {
//		cap.read(img);
//
//		newPoints=findColor(img);
//		drawOnCanvas(newPoints,myColorValues);
//		imshow("Image", img);
//		waitKey(1);//增加延时 1ms，以免太慢
//	}
//
//}
