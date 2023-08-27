#include "main.h"

uint8_t ID;
int16_t AccX, AccY, AccZ, GyroX, GyroY, GyroZ; // 定义存储加速度计和陀螺仪数据的变量
uint32_t Counter;
uint16_t Prescaler;

int main(void)
{

	LCD_Init();
	MPU6050_Init();
	IC_Init();
	PWM_Set(100, 50);
	ID = MPU6050_ReadID();
	LCD_ShowHexNumber(0, 0, ID, Default_Font_Size);
	LCD_ShowNumber(0, 40, TIM_GetPrescaler(TIM2), 5, Default_Font_Size);
	LCD_ShowNumber(0, 60, Get_Frequency(), 9, Default_Font_Size);
	LCD_ShowNumber(0, 80, Get_Duty(), 3, Default_Font_Size);
	while (1)
	{
		// English_Font_test();//英文字体示例测试
		//Rotate_Test();   //旋转显示测试
		/*
		MPU6050_GetData(&AccX, &AccY, &AccZ, &GyroX, &GyroY, &GyroZ); // 读取陀螺仪数据
		LCD_ShowNumber(0, 140, AccX, 5, Default_Font_Size);			  // 显示加速度计X轴数据
		LCD_ShowNumber(0, 158, AccY, 5, Default_Font_Size);			  // 显示加速度计Y轴数据
		LCD_ShowNumber(0, 176, AccZ, 5, Default_Font_Size);			  // 显示加速度计Z轴数据
		LCD_ShowNumber(0, 200, GyroX, 5, Default_Font_Size);		  // 显示陀螺仪X轴数据
		LCD_ShowNumber(0, 218, GyroY, 5, Default_Font_Size);		  // 显示陀螺仪Y轴数据
		LCD_ShowNumber(0, 236, GyroZ, 5, Default_Font_Size);		  // 显示陀螺仪Z轴数据
		*/
	}
}
