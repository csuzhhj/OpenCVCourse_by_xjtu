#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


//int hmin = 0, smin = 0, vmin = 0;
//int hmax = 179, smax = 255, vmax = 255;//如何确定这6个值，每次都更改所有这些再次运行很痛苦 -->创建跟踪栏（使我们可以实时更改这些值）
//Mat img;
//Mat imgHSV, mask, imgColor;

//void main() {
//	VideoCapture cap(0);//相机id=0
//	
//	
//	namedWindow("Trackbars", (640, 200));//创建窗口，(640,200)是尺寸
//	//运行时，把3个min的都移到最小值，把3个max的都移到最大值，然后移动使其保持为白色
//	createTrackbar("Hue Min", "Trackbars", &hmin, 179);//对于hue色相饱和度最大180,对于另外两个色相饱和度最大255
//	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
//	createTrackbar("Sat Min", "Trackbars", &smin, 255);
//	createTrackbar("Sat Max", "Trackbars", &smax, 255);
//	createTrackbar("Val Min", "Trackbars", &vmin, 255);
//	createTrackbar("Val Max", "Trackbars", &vmax, 255);
//	
//	while (true) {
//		//检查数组元素是否位于其他两个数组的元素之间。
//		//imgHSV为输入图像，mask为输出图像
//		cap.read(img);
//		cvtColor(img, imgHSV, COLOR_BGR2HSV);//转换图像到HSV空间，在其中查找颜色更加容易
//		Scalar lower(hmin, smin, vmin);
//		Scalar upper(hmax, smax, vmax);
//		inRange(imgHSV, lower, upper, mask);//定义颜色下限和上限，因为由于照明和不同的阴影，颜色的值将不完全相同，会是一个值的范围
//		cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << endl;
//		imshow("Image", img);
//		imshow("Image HSV", imgHSV);
//		imshow("Image mask", mask);
//		waitKey(1);//增加延时
//	}
//}