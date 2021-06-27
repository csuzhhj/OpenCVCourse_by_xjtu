//学习如何检测车牌和如何裁剪并保存这些区域

#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>//对象检测头文件
#include<iostream>

using namespace std;
using namespace cv;


/// <summary>
/// Project 3 – License Plate(车牌) Detector
/// </summary>


void main() {

	
	VideoCapture cap(0);//相机id=0
	Mat img;

	//加载模型
	CascadeClassifier plateCascade;/*用于对象检测的级联分类器类*/
	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");//从文件加载分类器(已经训练好的模型)
	if (plateCascade.empty()) { cout << "XML file not loaded" << endl; }//检测文件是否加载成功

	vector<Rect> plates;

	while (true) {
		cap.read(img);
		//可以更改比例因子和最小邻居来调整检测成功率
		plateCascade.detectMultiScale(img/*输入*/, plates/*输出*/, 1.1/*比例因子*/, 10/*最小邻居*/);//在输入图像中检测不同大小的对象。检测到的对象将以矩形列表的形式返回。

		
		
		for (int i = 0; i < plates.size(); i++) {
			Mat imgCrop = img(plates[i]);//plates是矩形列表，plates[i]是矩形
			//imshow(to_string(i), imgCrop);
			imwrite("Resources/Plates/" + to_string(i) + ".png", imgCrop);
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);//绘制矩形
		}

		imshow("Image", img);
		waitKey(1);//增加延时，0表示无穷
	}
}