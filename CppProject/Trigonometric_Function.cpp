#include "pch.h"
#include "Trigonometric_Function.h"
#include "math.h"

const int ORDER_NUM = 10;  //麦克劳林展开的阶数
const double pi = 3.14159265358979323846;

/*求n的阶乘*/
LONG64 factorial(int n)    //7！就会超出int所能表示的范围，故要用long64
{
	LONG64 y = 1;
	for (int i = 1; i <= n; i++)
		y = y * i;
	return y;
}

/*sin函数，输入的是角度*/
double f_sin(double x)
{
	if (x > 1048576.0)//输入大于2^20
		return INFINITY;

	if (x >= 360)  //将输入规范至-360—360°之间
		x -= floor(x / 360) * 360;
	if (x <= -360)
		x += floor(-x / 360) * 360;

	x = pi / 180 * x;  //将角度转化为弧度

	double y = 0;      //初始化输出为零
	for (int i = 1; i <= ORDER_NUM; i++)
		y += pow(-1, i - 1) * pow(x, 2 * i - 1) / factorial(2 * i - 1);

	if (y > 0 && y < 1.0e-8)  //清零误差
		y = 0;
	else if (y > -1.0e-8 && y < 0)
		y = 0;

	return y;
}

/*cos函数*/
double f_cos(double x)
{
	if (x > 1048576.0)//输入大于2^20
		return INFINITY;

    x = (x / 180) * pi;
    for (; 1;)
    {
        if (x > pi)
        {
            x = x - 2 * pi;
        }
        if (x < -pi)
        {
            x = x + 2 * pi;
        }
        if (-pi <= x && x <= pi)
        {
            break;
        }
    }
    double result;
    double temp = 0;
    int symbol = 1;


    for (int i = 2; i < 21; i = i + 2)
    {
        symbol = symbol * (-1);
        double mi_x = 1;
        double jicheng = 1;
        for (int j = 1; j <= i; j = j + 1)
        {
            mi_x = mi_x * x;
            jicheng = jicheng * j;
        }
        temp = temp + symbol * mi_x / jicheng;
    }
    result = 1 + temp;
	if (-0.0000001 < result && result < 0.0000001)
		result = 0;
    return result;
}

/*tan函数*/
double f_tan(double input)
{
	//使用麦克劳林展开近似tan函数，默认阶数为10
	double o;
	double x, y;

	if (input > 1048576.0)//输入大于2^20
		return INFINITY;


	//不存在则返回INFINITY，输出显示inf
	if (fmod(input, 180) == 90)
	{
		return INFINITY;
	}		

	//对输入进行处理：使得输入在-90到+90范围内
	x = fmod(input, 180);//将数轴上的点全部映射到-180到180上,此时x的取值范围为-180到180,需要再将其压缩为-90到90
	if (x > 90)
	{
		x = x - 180;//将90-180上的点映射为-90-0
	}
	else if (x < -90)
	{
		x = x + 180;//将-180--90的点映射为0-90
	}

	//常用特殊值
	if (x == 45)
		return 1;
	if (x == -45)
		return -1;

	y = x / 180 * pi;	//将角度输入转化为弧度输入
	o = y + (double(1.0 / 3.0)) * pow(y, 3) + double(2.0 / 15.0) * pow(y, 5) + double(17.0 / 315.0) * pow(y, 7) + double(62.0 / 2835.0) * pow(y, 9);
	return o;
}

/*cot函数*/
double f_cot(double x)
{
	int quotient = 1;
	// cot函数周期为pi

	if (x > 1048576.0)//输入大于2^20
		return INFINITY;

	//double和fioat型不能用%符号求余 ！！ 所以(a - int(a) + int(a) % 180)是相当与 a%180  
	if ((x - int(x) + int(x) % 180) == 0)
	{
		return INFINITY;
		//printf("不能输入180的倍数，因为该值在正切函数中是没有意义的！！！\n\a");
		//exit(0);
	}
	else if (x > 180)    //double转化成int，向下取整
	{

		quotient = x / 180;      //若a=365.3，则quotient=365/180=2 ，a=365.3-2*180= 5.3 
		x = x - quotient * 180;
	}
	else if (x < -180)     //向上取整，如 -359.7-> 359  ,抹去小数点
	{
		quotient = x / 180;        //若a=-365.3，则quotient=-365/180=-2 ，a=-365.3-（-2）*180 = -5.3 
		x = x - quotient * 180;
	}
	//化为主区间 -90<x<90
	if (x >= 90)
	{
		x = x - 180;
	}
	else if (x <= -90)
	{
		x = x + 180;
	}
	double newa = x * pi / 180.0;
	//根据cot函数的泰勒公式展开，取前面的4项。
	double cotx = 1.0 / newa - newa / 3.0 - pow(newa, 3) / 45 - 2 * pow(newa, 5) / 945.0;
	if (-0.007 < cotx < 0.007)
	{
		cotx = 0;
	}
	return cotx;
}