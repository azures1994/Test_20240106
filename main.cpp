#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <ncnn/net.h>
#include <MNN/Interpreter.hpp>
#include <MNN/MNNDefine.h>
#include <MNN/Tensor.hpp>
#include <MNN/ImageProcess.hpp>

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

void test_spdlog(){
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");
    
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");    
    
    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    
    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");
}

using json = nlohmann::json;
void test_json(){
    // create an empty structure (null)
    json j;

    // add a number that is stored as double (note the implicit conversion of j to an object)
    j["pi"] = 3.141;

    // add a Boolean that is stored as bool
    j["happy"] = true;

    // add a string that is stored as std::string
    j["name"] = "Niels";

    // add another null object by passing nullptr
    j["nothing"] = nullptr;

    // add an object inside the object
    j["answer"]["everything"] = 42;

    // add an array that is stored as std::vector (using an initializer list)
    j["list"] = { 1, 0, 2 };

    // add another object (using an initializer list of pairs)
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };

    // instead, you could also write (which looks very similar to the JSON above)
    json j2 = {
    {"pi", 3.141},
    {"happy", true},
    {"name", "Niels"},
    {"nothing", nullptr},
    {"answer", {
        {"everything", 42}
    }},
    {"list", {1, 0, 2}},
    {"object", {
        {"currency", "USD"},
        {"value", 42.99}
    }}
    };

    std::cout << "j: " << std::endl << j << std::endl;
    std::cout << "j2: " << std::endl << j2 << std::endl;
}

void test_ncnn(){
    ncnn::Net net;
}

int main(int, char**){
    std::cout << "Hello, from test_20240106!\n";

    // test_opencv();
    // test_spdlog();
    // test_json();
    test_ncnn();

    return 0;
}
