#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "2.4TFT.h"
#include "test.h"
#include "MPU6050.h"

uint8_t ID;
int16_t AccX,AccY,AccZ,GyroX,GyroY,GyroZ;//定义存储加速度计和陀螺仪数据的变量

int main(void)
{
	MPU6050_Init(); // 陀螺仪初始化
	LCD_Init(); // 液晶屏初始化
	while (1)
	{
		/*
		main_test(); 		//测试主界面
		Test_Color();  		//简单刷屏填充测试
		Test_FillRec();		//GUI矩形绘图测试
		Test_Circle(); 		//GUI画圆测试
		Test_Triangle();    //GUI三角形绘图测试
		English_Font_test();//英文字体示例测试
		Chinese_Font_test();//中文字体示例测试
		Pic_test();			//图片显示示例测试
		Rotate_Test();
		*/
		MPU6050_GetData(&AccX,&AccY,&AccZ,&GyroX,&GyroY,&GyroZ);//读取陀螺仪数据
		LCD_ShowNumber(0,140,AccX,5,Default_Font_Size);//显示加速度计X轴数据
		LCD_ShowNumber(0,158,AccY,5,Default_Font_Size);//显示加速度计Y轴数据
		LCD_ShowNumber(0,176,AccZ,5,Default_Font_Size);//显示加速度计Z轴数据
		LCD_ShowNumber(0,200,GyroX,5,Default_Font_Size);//显示陀螺仪X轴数据
		LCD_ShowNumber(0,218,GyroY,5,Default_Font_Size);//显示陀螺仪Y轴数据
		LCD_ShowNumber(0,236,GyroZ,5,Default_Font_Size);//显示陀螺仪Z轴数据
	}
}
