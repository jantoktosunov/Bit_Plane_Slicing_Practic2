#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>
using namespace cv;
using namespace std;

/*Сделать функцию нарезки битовой плоскости изображений (Bit-Plane slicing).
 * Сделать 2-мя методами:
 * 1) Свой метод по пиксельно
 * 2) Готовой функцией OpenCV по нарезке битовой плоскости изображений.
 * Изображения переведите сперва черно-белое 8-бит
 */

/*Свой метод для нарезки битовой плоскости, НЕ НАШЛИ ГОТОВЫЙ МЕТОД OPENCV*/
void bit_plane_clice(Mat in,Mat out, int bit){
    int cols = in.cols;
    int rows = in.rows;

    for (int y = 0; y < rows; y++){
        for (int x = 0; x < cols; x++){
            out.at<uchar>(y, x) = (in.at<uchar>(y, x) & uchar(bit)) ? uchar(255) : uchar(0);
        }
    }
}

int main(int argc, char** argv) {
    Mat m1 = imread(argv[1], CV_8U);//Cчитываем рисунок через аргумент
    imshow("Original_GRAY", m1);
    int cols, rows, x, y;
    cols = m1.cols;
    rows = m1.rows;
    //printf("%d %d \n", m1.rows, m1.cols);
    Mat out1(rows, cols, CV_8UC1, Scalar(0));
    Mat out2 = out1.clone();
    Mat out3 = out1.clone();
    Mat out4 = out1.clone();
    Mat out5 = out1.clone();
    Mat out6 = out1.clone();
    Mat out7 = out1.clone();
    Mat out8 = out1.clone();

    bit_plane_clice(m1,out1,1);
    bit_plane_clice(m1,out2,2);
    bit_plane_clice(m1,out3,4);
    bit_plane_clice(m1,out4,8);
    bit_plane_clice(m1,out5,16);
    bit_plane_clice(m1,out6,32);
    bit_plane_clice(m1,out7,64);
    bit_plane_clice(m1,out8,128);

    imshow("out1", out1);
    imshow("out2", out2);
    imshow("out3", out3);
    imshow("out4", out4);
    imshow("out5", out5);
    imshow("out6", out6);
    imshow("out7", out7);
    imshow("out8", out8);
    waitKey(0);


    return 0;
}