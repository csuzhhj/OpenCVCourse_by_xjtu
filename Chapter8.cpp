//学习检测图像中的面部
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>//对象检测头文件
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Images
/// </summary>
//void main() {
//	string path = "Resources/test.png";
//	Mat img=imread(path);
//	CascadeClassifier faceCascade;/*用于对象检测的级联分类器类*/
//	faceCascade.load("Resources/haarcascade_frontalface_default.xml");//从文件加载分类器(已经训练好的模型)
//
//	if (faceCascade.empty()) { cout << "XML file not loaded" << endl; }//检测文件是否加载成功
//
//	vector<Rect> faces;
//	faceCascade.detectMultiScale(img/*输入*/, faces/*输出*/, 1.1/*比例因子*/, 10/*最小邻居*/);//在输入图像中检测不同大小的对象。检测到的对象将以矩形列表的形式返回。
//	
//	for (int i = 0; i < faces.size(); i++) {
//		rectangle(img, faces[i].tl(),faces[i].br(), Scalar(255, 0, 255), 3);//绘制矩形
//	}
//
//	imshow("Image", img);
//	waitKey(0);//增加延时，0表示无穷
//}