#include "SPI.h"

//以下函数为对引脚操作的封装和改名，方便移植
void SPI_SS(uint8_t BitValue)//写SS引脚电平
{
    GPIO_WriteBit(SPI_GPIO_PORT, SPI_CS_PIN, (BitAction)BitValue);
}

//以下为SPI的三种基本条件：起始条件、终止条件、交换一个字节（模式0）

void SPI_Start(void)//硬件SPI起始条件
{
    SPI_SS(0);//SS引脚拉低
}

void SPI_Stop(void)//硬件SPI终止条件
{
    SPI_SS(1);//SS引脚拉高
}

void SPI_Initilize(void)
{
    /*
    以下为软件实现
    //1.初始化SPI引脚
 
    //2.SS引脚置高电平，SPI总线空闲状态
   
    */
    //以下为硬件实现
    //1.初始化GPIO配置
    RCC_AHB1PeriphClockCmd(SPI_GPIO_CLK, ENABLE);//使能GPIOA时钟
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin =SPI_SCK_PIN | SPI_MOSI_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上拉也不下拉
    GPIO_Init(SPI_GPIO_PORT, &GPIO_InitStructure);//初始化GPIOA

    GPIO_InitStructure.GPIO_Pin = SPI_CS_PIN; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//通用输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上拉也不下拉
    GPIO_Init(SPI_GPIO_PORT, &GPIO_InitStructure);//初始化GPIOA

    GPIO_InitStructure.GPIO_Pin = SPI_MISO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//输入
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(SPI_GPIO_PORT, &GPIO_InitStructure);//初始化GPIOA
    //2.初始化SPI配置
    RCC_APB2PeriphClockCmd(SPI_PORT_CLK, ENABLE);//使能SPI时钟
    SPI_InitTypeDef SPI_InitStructure;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;//主机模式
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;//NSS软件管理
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;//双线全双工
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;//数据传输从MSB位开始
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge ;//第一个时钟沿捕获数据,CPHA=0
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;//时钟空闲状态为低电平
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;//波特率预分频值为2
    SPI_InitStructure.SPI_CRCPolynomial = 7;//CRC多项式寄存器值为7
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;//数据大小为8位
    SPI_Init(SPI_PORT, &SPI_InitStructure);//初始化SPI
    SPI_Cmd(SPI_PORT, ENABLE);//使能SPI
    SPI_SS(1);//SS引脚置高电平，SPI总线空闲状态。默认不选中从机
}

uint8_t SPI_ExchangeByte(uint8_t TxData)//硬件交换一个字长数据；连续传输；模式0
{
  
    //硬件实现，非连续传输
    while(SPI_I2S_GetFlagStatus(SPI_PORT,SPI_I2S_FLAG_TXE) != SET);//等待发送缓冲区空。写入DR会顺便清除TXE标志
    SPI_I2S_SendData(SPI_PORT, TxData);//发送数据
    while(SPI_I2S_GetFlagStatus(SPI_PORT,SPI_I2S_FLAG_RXNE) != SET);//等待接收缓冲区非空。要想接收必须得先发送
    return SPI_I2S_ReceiveData(SPI_PORT);//读取数据

    //硬件实现，连续传输
}
