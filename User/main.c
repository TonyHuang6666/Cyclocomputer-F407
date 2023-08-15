#include "main.h"

uint8_t ID;
int main(void)
{
	LCD_Init();
	MPU6050_Init();
	ID=MPU6050_ReadID();
	LCD_ShowHexNumber(0,0,ID,Default_Font_Size);
	while (1)
	{	
		//English_Font_test();//英文字体示例测试
		//Rotate_Test();   //旋转显示测试
		
	}
}