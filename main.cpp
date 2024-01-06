#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

void test_opencv(){
    std::string srcImgPath{"./temp/image_001.jpg"};

    cv::Mat srcImg = cv::imread(srcImgPath);
    if(srcImg.empty()){
        printf("cv::imread fail!(%s)\n", srcImgPath.c_str());
        return;
    }

#ifdef __linux__
    cv::Mat showImg = srcImg.clone();
    cv::imwrite("./temp/showImg.jpg", showImg);
#elif _WIN32
    cv::imshow("showImg", showImg);
    cv::waitKey(20);
#endif
}

int main(int, char**){
    std::cout << "Hello, from test_20240105!\n";

    test_opencv();

    return 0;
}
