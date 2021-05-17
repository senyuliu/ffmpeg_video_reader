#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include "ffmpegDecode.h"
#include "time.h"

using namespace std; 
using namespace cv; 

bool run_opencv (void);
bool run_ffmpeg (void); 


int main()
{
	std::cout<<"main in!"<<std::endl; 

    time_t c_start, c_end;  

    c_start = time(NULL); 
    run_ffmpeg(); //run_opencv(); //run_ffmpeg(); 
    c_end = time(NULL); 

    std::cout << difftime(c_end, c_start) << std::endl; 

	return 0; 
}

bool run_ffmpeg(void)
{
    //[0]input
    char* file = "/home/sen/Downloads/496514500000"; 
    ffmpegDecode ffmpegObj(file);

    //[1]get frame 
    int count = 0; 
    while(1)
    {
        int result = ffmpegObj.readOneFrame(); 
        //std::cout << result <<","<< count <<std::endl; 

        count++; 
        if(result){break;}

        cv::Mat matImage = ffmpegObj.getDecodedFrame(); 
        //std::cout << matImage.rows << "," << matImage.cols << std::endl; 
        //imshow
        //namedWindow("show",2); 
        //imshow("show", matImage);
        //waitKey(10);
        //destroyWindow("show");   
    }

} 

bool run_opencv( void )
{
    //打开视频文件。创建VideoCapture类对象capture，用初始化为括号里的视频（VideoCapture类的构造函数）。
    //VideoCapture capture("video.mp4");//创建VideoCapture类对象capture
    //或
    VideoCapture capture;
    capture.open("/home/sen/Downloads/496514500000");//VideoCapture类的方法

    string outpath = "../data/"; 
 
    //检查是否打开成功
    if (!capture.isOpened())
    {
        cout << "视频没有打开"<<endl;
        return 1;
    }
 
 
    Mat frame;
    cv::namedWindow("video",2);
 
    //循环遍历视频中的全部帧
    int count = 0;

    while (1)
    {
        
        capture >> frame;
 
        if (!frame.empty())//如果读完就结束
        {
            //imshow("video", frame);
            //waitKey(4);
        }
        else
        {
            break;
        }
        count++; 
        string savepath = outpath + "/" + std::to_string(count) + ".png";
        //imwrite(savepath, frame);

    }
    capture.release();//不是必须的（由于在VideoCapture类的析构函数中已经调用了）。用于关闭视频文件
}