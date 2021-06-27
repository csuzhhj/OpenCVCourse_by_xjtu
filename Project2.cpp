#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Project 2 – Document Scanner
/// 图像预处理：转换为灰度、添加模糊、使用Canny边缘检测器找到边缘（知道纸张在哪里）、基于纸张的坐标提取四个角得到顶视图
/// </summary>

//Mat imgOriginal, imgGray, imgBlur, imgCanny, imgDil, imgErode, imgThre, imgWarp, imgCrop;
//vector<Point> initialPoints,docPoints;
//float w = 420, h = 596;
//Mat preProcessing(Mat img) {
//	cvtColor(img, imgGray, COLOR_BGR2GRAY);//cvt是convert的缩写，将图像从一种颜色空间转换为另一种颜色空间。
//	GaussianBlur(imgGray, imgBlur,Size(7,7),5,0);//使用高斯滤波器模糊图像。该函数将源图像与指定的高斯核进行卷积,Size(7,7)是核大小,数字越大越模糊
//	Canny(imgBlur, imgCanny, 25, 75);//边缘检测，阈值1，2可调，目的：显示更多的边缘
//	
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//创建一个核，增加Size（只能是奇数）会扩张/侵蚀更多
//	dilate(imgCanny, imgDil, kernel);//扩张边缘（增加边缘厚度）
//	//erode(imgDil, imgErode, kernel);//侵蚀边缘（减小边缘厚度）
//	return imgDil;
//}
//
//vector<Point>/*返回纸张的4个角点*/ getContours(Mat imgDil) {//imgDil是传入的扩张边缘的图像用来查找轮廓，img是要在其上绘制轮廓的图像
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
//	vector<Point> biggest;
//	int maxArea = 0;
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
//			if (area > maxArea&&conPoly[i].size()==4) {
//				biggest = { conPoly[i][0],conPoly[i][1],conPoly[i][2],conPoly[i][3] };
//				maxArea = area;
//			}
//
//			//rectangle/*绘制边界矩形*/(imgOriginal, boundRect[i].tl()/*tl()：topleft矩形左上角坐标*/, boundRect[i].br()/*br()：bottom right矩形右下角坐标*/, Scalar(0, 255, 0), 5);
//			//drawContours(imgOriginal, conPoly, i, Scalar(255, 0, 255), 2);
//			
//		}
//	}
//	return biggest;
//}
//
//void drawPoints(vector<Point> points, Scalar color) {
//	for (int i = 0; i < points.size(); i++) {
//		circle(imgOriginal, points[i], 10, color, FILLED);
//		putText(imgOriginal, to_string(i), points[i], FONT_HERSHEY_PLAIN, 4, color, 4);
//	}
//}
//
//vector<Point> reorder(vector<Point> points) {//标记点的顺序会变，要确定一个顺序 0 1
//											//								 2 3
//	vector<Point> newPoints;
//	vector<int>  sumPoints, subPoints;
//	for (int i = 0; i < 4; i++) {
//		sumPoints.push_back(points[i].x + points[i].y);
//		subPoints.push_back(points[i].x - points[i].y);
//	}
//	
//	newPoints.push_back(points[min_element/* find smallest element*/(sumPoints.begin(), sumPoints.end())-sumPoints.begin()]);
//	newPoints.push_back(points[max_element/* find largest element*/(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
//	newPoints.push_back(points[min_element/* find smallest element*/(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
//	newPoints.push_back(points[max_element/* find largest element*/(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);
//
//	return newPoints;
//}
//
//Mat getWarp(Mat img,vector<Point> points,float w,float h) {
//	Point2f src[4] = { points[0],points[1],points[2],points[3] };//Point2f表示浮点数
//	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };//Point2f表示浮点数
//
//	Mat matrix = getPerspectiveTransform(src, dst);
//	warpPerspective(img, imgWarp, matrix, Point(w,h));
//
//	return imgWarp;
//}
//
//void main() {
//	string path = "Resources/paper.jpg";
//	imgOriginal=imread(path);
//
//	//resize(imgOriginal/*source*/, imgOriginal/*destination*/, Size()/*不定义尺寸*/, 0.5/*定义比例*/, 0.5/*定义比例*/);
//
//	//预处理
//	imgThre = preProcessing(imgOriginal);
//	//获得轮廓--获得最大矩形
//	initialPoints=getContours(imgThre);
//	//drawPoints(initialPoints, Scalar(0, 0, 255));
//	docPoints = reorder(initialPoints);
//	//drawPoints(docPoints, Scalar(0, 255, 0));
//	//扭曲
//	imgWarp = getWarp(imgOriginal, docPoints, w, h);
//	//裁剪多余的边--通过创建一个矩形
//	int cropValue = 5;
//	Rect roi(cropValue/*每条边要减去的像素*/, cropValue, w - 2 * cropValue/*宽度*/, h - 2 * cropValue/*高度*/);
//	imgCrop = imgWarp(roi);
//	imshow("Image", imgOriginal);
//	imshow("Image Dilation", imgThre);
//	imshow("Image Warp", imgWarp);
//	imshow("Image Crop", imgCrop);
//	waitKey(0);
//}
