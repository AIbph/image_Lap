#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;

int main(int argc, char** argv){
	// ������˹���ӣ���ȡͼ���Ե

	// ��ȡͼ��
	Mat src = imread("D:/OpenCVProject/day1214/������˹���ӣ���Ե��ȡ/������˹���ӣ���Ե��ȡ/test.jpg");
	if(!src.data){
		printf("could not load image");
		return -1;
	}
	imshow("origin image", src);

	// ��˹ģ��
	Mat gs;
	GaussianBlur(src, gs, Size(3, 3), 0);
	//imshow("��˹ģ�����ͼ��", gs);

	// ת�Ҷ�ͼ
	Mat gray_src;
	cvtColor(gs, gray_src, CV_BayerBG2GRAY);
	//imshow("�Ҷ�ͼ", gray_src);

	// ������˹���ӣ��õ�2���ݶ�
	Mat lpl;
	Laplacian(gray_src, lpl, -1, 3);
	convertScaleAbs(lpl, lpl);
	imshow("����ͼ��", lpl);

	waitKey(0);
	return 0;
}