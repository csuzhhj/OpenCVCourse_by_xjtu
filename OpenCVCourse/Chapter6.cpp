//ѧϰ���ͼƬ�е���ɫ���������ض�����Ķ�������
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Color Detection
/// </summary>


//int hmin = 0, smin = 0, vmin = 0;
//int hmax = 179, smax = 255, vmax = 255;//���ȷ����6��ֵ��ÿ�ζ�����������Щ�ٴ����к�ʹ�� -->������������ʹ���ǿ���ʵʱ������Щֵ��
//void main() {
//	string path = "Resources/shapes.png";
//	Mat img=imread(path);
//	Mat imgHSV,mask;
//	cvtColor(img, imgHSV, COLOR_BGR2HSV);//ת��ͼ��HSV�ռ䣬�����в�����ɫ��������
//	namedWindow("Trackbars", (640, 200));//(640,200)�ǳߴ�
//	//����ʱ����3��min�Ķ��Ƶ���Сֵ����3��max�Ķ��Ƶ����ֵ��Ȼ���ƶ�ʹ�䱣��Ϊ��ɫ
//	createTrackbar("Hue Min", "Trackbars", &hmin, 179);//����hueɫ�౥�Ͷ����180,������������ɫ�౥�Ͷ����255
//	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
//	createTrackbar("Sat Min", "Trackbars", &smin, 255);
//	createTrackbar("Sat Max", "Trackbars", &smax, 255);
//	createTrackbar("Val Min", "Trackbars", &vmin, 255);
//	createTrackbar("Val Max", "Trackbars", &vmax, 255);
//	
//	while (true) {
//		//�������Ԫ���Ƿ�λ���������������Ԫ��֮�䡣
//		//imgHSVΪ����ͼ��maskΪ���ͼ��
//
//		Scalar lower(hmin, smin, vmin);
//		Scalar upper(hmax, smax, vmax);
//		inRange(imgHSV, lower, upper, mask);//������ɫ���޺����ޣ���Ϊ���������Ͳ�ͬ����Ӱ����ɫ��ֵ������ȫ��ͬ������һ��ֵ�ķ�Χ
//		imshow("Image", img);
//		imshow("Image HSV", imgHSV);
//		imshow("Image mask", mask);
//		waitKey(1);//������ʱ
//	}
//}