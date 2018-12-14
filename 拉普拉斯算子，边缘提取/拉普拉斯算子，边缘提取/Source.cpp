#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;

int main(int argc, char** argv){
	// 拉普拉斯算子，提取图像边缘

	// 读取图像
	Mat src = imread("D:/OpenCVProject/day1214/拉普拉斯算子，边缘提取/拉普拉斯算子，边缘提取/test.jpg");
	if(!src.data){
		printf("could not load image");
		return -1;
	}
	imshow("origin image", src);

	// 高斯模糊
	Mat gs;
	GaussianBlur(src, gs, Size(3, 3), 0);
	//imshow("高斯模糊后的图像", gs);

	// 转灰度图
	Mat gray_src;
	cvtColor(gs, gray_src, CV_BayerBG2GRAY);
	//imshow("灰度图", gray_src);

	// 拉普拉斯算子，得到2介梯度
	Mat lpl;
	Laplacian(gray_src, lpl, -1, 3);
	convertScaleAbs(lpl, lpl);
	imshow("最终图像", lpl);

	waitKey(0);
	return 0;
}