//学习如何调整大小以及裁剪图像

#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/// <summary>
/// Resize and Crop
/// </summary>
//void main() {
//	string path = "Resources/test.png";
//	Mat img=imread(path);//matrix data type 由opencv引入来处理图像
//	Mat imgResize,imgCrop;
//	cout << img.size() << endl;//打印图像尺寸
//	//resize(img, imgResize, Size(640, 480));//指定图片尺寸缩放
//	resize(img, imgResize, Size(),0.5,0.5);//指定缩放比例，不指定图片尺寸
//
//	//矩形数据类型
//	Rect roi(200, 100, 300, 300);//以左上角为坐标原点，（200，100）为矩形的左上角坐标，300,300为矩形长宽
//	imgCrop = img(roi);//裁剪图像，为了找到特定区域 添加更多处理 roi:region of interest
//	imshow("Image", img);
//	imshow("Image Resize", imgResize);
//	imshow("Image Crop", imgCrop);
//	
//	waitKey(0);//增加延时，0表示无穷
//}