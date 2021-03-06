//Tomuța Dan Claudiu, PABDI, sem II

#include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	VideoCapture cap("taichi.mp4");

	if (cap.isOpened() == false)
	{
		cout << "Nu se poate reda fisierul!" << endl;
		cin.get(); 
		return -1;
	}

	//daca vreau sa se porneasca clipul in mijloc
	//cap.set(CAP_PROP_POS_MSEC, 300); 

	double fps = cap.get(CAP_PROP_FPS);
	cout << "Frames per seconds : " << fps << endl;

	String window_name = "Clip taichi";

	namedWindow(window_name, WINDOW_NORMAL); 

	while (true)
	{
		Mat frame;
		bool bSuccess = cap.read(frame); 

										
		if (bSuccess == false)
		{
			cout << "Clipul s-a terminat!" << endl;
			break;
		}

		imshow(window_name, frame);

		//wait for for 10 ms until any key is pressed.  
		//If the 'Esc' key is pressed, break the while loop.
		//If the any other key is pressed, continue the loop 
		//If any key is not pressed withing 10 ms, continue the loop
		if (waitKey(10) == 27)
		{
			cout << "S-a apasat tasta Esc. Se inchide videoul!" << endl;
			break;
		}
	}

	return 0;

}