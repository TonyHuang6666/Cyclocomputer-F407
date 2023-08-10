#include "stm32f10x.h"
#include "SPI.h"

//以下函数为对引脚操作的封装和改名，方便移植
void SPI_SS(uint8_t BitValue)//写SS引脚电平
{
    GPIO_WriteBit(SPI_GPIO_PORT, GPIO_Pin_4, (BitAction)BitValue);
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
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  // 浮空输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    //2.SS引脚置高电平，SPI总线空闲状态
    GPIO_SetBits(GPIOA, GPIO_Pin_4);
    */
    //以下为硬件实现
    //1.初始化GPIO配置
    RCC_APB2PeriphClockCmd(SPI_GPIO_CLK, ENABLE);//使能GPIOA时钟
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin =SPI_SCK_PIN | SPI_MOSI_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
    GPIO_Init(SPI_GPIO_PORT, &GPIO_InitStructure);//初始化GPIOA

    GPIO_InitStructure.GPIO_Pin = SPI_CS_PIN; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//通用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
    GPIO_Init(SPI_GPIO_PORT, &GPIO_InitStructure);//初始化GPIOA

    GPIO_InitStructure.GPIO_Pin = SPI_MISO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
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
    /*软件实现
    uint8_t i;
    for(i=0;i<8;i++)
    {
        //当i=0时，SS下降沿，MISO与MOSI都移出数据
        //MOSI移出数据
        if(TxData & 0x80)
            SPI_MOSI(1);//MOSI引脚拉高
        else
            SPI_MOSI(0);//MOSI引脚拉低
        TxData <<= 1;
        
        //SCK上升沿，数据移入
        SPI_SCK(1);//SCK引脚拉高
        //MISO读取数据
        if(SPI_MISO())
            TxData |= 0x01;
        SPI_SCK(0);//SCK引脚拉低
    }
    uint8_t temp,RxData;
    while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE) != SET);//等待发送缓冲区空
    SPI_I2S_SendData(SPI1, TxData);//发送数据
    while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE) != RESET);//等待接收缓冲区非空
    temp = SPI_I2S_ReceiveData(SPI1);//读取数据
    while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE) != SET);//等待发送缓冲区空
    SPI_I2S_SendData(SPI1, 0xFF);//发送数据
    while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE) != RESET);//等待接收缓冲区非空
    RxData = SPI_I2S_ReceiveData(SPI1);//读取数据
    return RxData;
    */

    /*硬件实现，连续传输
    uint32_t RxData;
    uint8_t TxDataArray[5];
    TxDataArray[0] = (TxData >> 24) & 0xFF;
    TxDataArray[1] = (TxData >> 16) & 0xFF;
    TxDataArray[2] = (TxData >> 8) & 0xFF;
    TxDataArray[3] = TxData & 0xFF;
    TxDataArray[4] = 0x00;
    SPI_I2S_SendData(SPI1, TxDataArray[0]);//发送数据
    for(int i =1;i<5;i++)
    {
        while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE) != SET);//等待发送缓冲区空
        SPI_I2S_SendData(SPI1, TxDataArray[i]);//发送数据
        while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE) != SET);//等待接收缓冲区非空
        RxData |= SPI_I2S_ReceiveData(SPI1);//读取数据
        RxData <<= 8;
    }
    return RxData;
    */
    //硬件实现，非连续传输
    while(SPI_I2S_GetFlagStatus(SPI_PORT,SPI_I2S_FLAG_TXE) != SET);//等待发送缓冲区空。写入DR会顺便清除TXE标志
    SPI_I2S_SendData(SPI_PORT, TxData);//发送数据
    while(SPI_I2S_GetFlagStatus(SPI_PORT,SPI_I2S_FLAG_RXNE) != SET);//等待接收缓冲区非空。要想接收必须得先发送
    return SPI_I2S_ReceiveData(SPI_PORT);//读取数据

    //硬件实现，连续传输
}

/*
void SPI_I2S_DeInit(SPI_TypeDef* SPIx);//复位SPI/I2S外设
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);//初始化SPI外设
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);//SPI外设初始化结构体
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_I2S_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT, FunctionalState NewState);//使能或者失能指定的SPI/I2S中断
void SPI_I2S_DMACmd(SPI_TypeDef* SPIx, uint16_t SPI_I2S_DMAReq, FunctionalState NewState);//使能或者失能指定的SPI/I2S DMA请求

void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data);//通过SPIx发送一个数据
uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx);//从SPIx接收一个数据

void SPI_NSSInternalSoftwareConfig(SPI_TypeDef* SPIx, uint16_t SPI_NSSInternalSoft);//配置SPI NSS内部软件管理
void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState);//使能或者失能SPI NSS输出
void SPI_DataSizeConfig(SPI_TypeDef* SPIx, uint16_t SPI_DataSize);//配置SPI数据大小
void SPI_TransmitCRC(SPI_TypeDef* SPIx);//使能SPI CRC传输
void SPI_CalculateCRC(SPI_TypeDef* SPIx, FunctionalState NewState);//使能或者失能SPI CRC计算
uint16_t SPI_GetCRC(SPI_TypeDef* SPIx, uint8_t SPI_CRC);//返回SPI CRC寄存器的接收值或者发送值
uint16_t SPI_GetCRCPolynomial(SPI_TypeDef* SPIx);//返回CRC多项式寄存器的值

void SPI_BiDirectionalLineConfig(SPI_TypeDef* SPIx, uint16_t SPI_Direction);//配置SPI单向或者双向的数据模式

FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);//检查指定的SPI/I2S标志位设置与否

void SPI_I2S_ClearFlag(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);//清除指定的SPI/I2S标志位
ITStatus SPI_I2S_GetITStatus(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT);//检查指定的SPI/I2S中断发生与否
void SPI_I2S_ClearITPendingBit(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT);//清除指定的SPI/I2S中断标志位
*/