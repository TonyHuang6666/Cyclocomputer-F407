#ifndef _2 .4TFT_H
#define _2 .4TFT_H
#include "sys.h"
#include "Delay.h"

extern uint16_t POINT_COLOR; // 画笔颜色：点的颜色默认为黑色
extern uint16_t BACK_COLOR;	 // 画笔颜色：背景颜色默认为白色


/*LCD
********************************************************************************************************
*/
// LCD端口定义
#define LED 9	  // 背光控制引脚        PB9
#define LCD_CS 11 // 片选引脚            PB11
#define LCD_RS 10 // 寄存器/数据选择引脚 PB10
#define LCD_RST 4 // 复位引脚            PA4

// 采用了三极管控制背光亮灭，也可以接PWM调节背光亮度
#define LCD_LED PBout(LED) // LCD背光    		 PB9

// GPIO置位（拉高）
#define LCD_CS_SET GPIOB->BSRR = 1 << LCD_CS   // 片选端口    PB11
#define LCD_RS_SET GPIOB->BSRR = 1 << LCD_RS   // 数据/命令   PB10
#define LCD_RST_SET GPIOA->BSRR = 1 << LCD_RST // 复位		  PA4
// GPIO复位（拉低）
#define LCD_CS_CLR GPIOB->BRR = 1 << LCD_CS	  // 片选端口   PB11
#define LCD_RS_CLR GPIOB->BRR = 1 << LCD_RS	  // 数据/命令  PB10
#define LCD_RST_CLR GPIOA->BRR = 1 << LCD_RST // 复位		PA4
typedef struct
{
	uint16_t Width;			// LCD 宽度
	uint16_t Height;		// LCD 高度
	uint16_t ID;			// LCD ID
	uint8_t Direction;		// 横屏还是竖屏控制：0，竖屏；1，横屏。
	uint16_t Write_RAM_Cmd; // 开始写gram指令
	uint16_t Set_x_Cmd;		// 设置x坐标指令
	uint16_t Set_y_Cmd;		// 设置y坐标指令
} LCD_Dev;
extern LCD_Dev lcddev; // 管理LCD重要参数

// 字体大小参数
#define Default_Font_Size 18

// 定义液晶屏顺时针旋转方向
#define USE_HORIZONTAL 0 // 0-0度旋转，1-90度旋转，2-180度旋转，3-270度旋转

// 定义LCD的尺寸
#define LCD_Width 240
#define LCD_Height 320

// 定义颜色
#define WHITE 0xFFFF
#define BLACK 0x0000
#define BLUE 0x001F
#define BRED 0XF81F
#define GRED 0XFFE0
#define GBLUE 0X07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define GREEN 0x07E0
#define CYAN 0x7FFF
#define YELLOW 0xFFE0
#define BROWN 0XBC40
#define BRRED 0XFC07
#define GRAY 0X8430
#define DARKBLUE 0X01CF
#define LIGHTBLUE 0X7D7C
#define GRAYBLUE 0X5458
#define LIGHTGREEN 0X841F

#define LIGHTGRAY 0XEF5B // 浅灰色(Panel)
#define LGRAY 0XC618	 // 浅灰色(Panel),窗体背景色
#define LGRAYBLUE 0XA651 // 浅灰蓝色(中间层颜色)
#define LBBLUE 0X2B12	 // 浅棕蓝色(选择条目的反色)

void LCD_Init(void);															   // 初始化
void LCD_Clear(uint16_t Color);													   // 清屏
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);								   // 设置光标
void LCD_DrawPoint(uint16_t x, uint16_t y);										   // 画点
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);			   // 画线
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);		   // 画矩形
void LCD_SetWindows(uint16_t xStar, uint16_t yStar, uint16_t xEnd, uint16_t yEnd); // 设置窗口
void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue);						   // 写寄存器
void LCD_WR_DATA(uint8_t data);													   // 写数据
void LCD_WriteRAM_Prepare(void);												   // 开始写GRAM
void Lcd_WriteData_16Bit(uint16_t Data);										   // 写数据
void LCD_Direction(uint8_t Direction);											   // 设置屏幕显示方向
/*LCD
********************************************************************************************************
*/

/*GUI
********************************************************************************************************
*/
void GUI_DrawPoint(uint16_t x, uint16_t y, uint16_t color);													  // 画点
void LCD_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color);							  // 填充单色
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);										  // 画线
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);									  // 画矩形
void Draw_Triangel(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);			  // 画三角形
void Fill_Triangel(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);			  // 填充三角形
void LCD_ShowChar(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t num, uint8_t size, uint8_t mode); // 显示一个字符
void LCD_ShowNumber(uint16_t x, uint16_t y, int32_t number, uint8_t length, uint8_t size);					  // 显示一个数字
void LCD_ShowHexNumber(uint16_t x, uint16_t y, uint32_t number, uint8_t size);								  // 显示一个十六进制数字
void LCD_ShowString(uint16_t x, uint16_t y, uint8_t size, uint8_t *p, uint8_t mode);						  // 显示一个字符串,12/16字体
void GUI_DrawFont16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s, uint8_t mode);
void GUI_DrawFont24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s, uint8_t mode);
void GUI_DrawFont32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s, uint8_t mode);
void Show_Str(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str, uint8_t size, uint8_t mode);		// 显示字符串
void Gui_Drawbmp16(uint16_t x, uint16_t y, const unsigned char *p);												// 显示16位BMP图片
void gui_circle(int xc, int yc, uint16_t c, int r, int fill);													// 画圆
void Gui_StrCenter(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str, uint8_t size, uint8_t mode); // 显示字符串
void LCD_DrawFillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);									// 填充矩形
/*GUI
********************************************************************************************************
*/

#endif