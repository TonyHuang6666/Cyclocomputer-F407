#include "stm32f10x.h"
#include "W25Q64_Order.h"
#include "SPI.h"

//W25Q64初始化
void W25Q64_Init(void)
{
    SPI_Initilize();
}

//W25Q64写使能
void W25Q64_WriteEnable(void)
{
    SPI_Start();
    SPI_ExchangeByte(W25Q64_WRITE_ENABLE);
    SPI_Stop();
}

void W25Q64_WaitBusy(void)
{
    uint32_t Timeout=100000;
    SPI_Start();
    SPI_ExchangeByte(W25Q64_READ_STATUS_REGISTER_1);
    while(SPI_ExchangeByte(W25Q64_Trash_BYTE)&0x01)
    {
        Timeout--;
        if(Timeout==0)
        {
            break;
        }
    }
    SPI_Stop();
}

//返回W25Q64的ID
void W25Q64_ReadID(uint8_t *MID, uint16_t *DID)
{
    SPI_Start();
    SPI_ExchangeByte(W25Q64_JEDEC_ID);//此时返回值无意义
    *MID=SPI_ExchangeByte(W25Q64_Trash_BYTE);
    *DID=SPI_ExchangeByte(W25Q64_Trash_BYTE);
    *DID<<=8;
    *DID|=SPI_ExchangeByte(W25Q64_Trash_BYTE);
    SPI_Stop();
}

//W25Q64页编程
void Page_Program(uint32_t Page_Address, uint8_t *DataArray, uint16_t Count)
{
    uint16_t i;
    W25Q64_WriteEnable();
    SPI_Start();
    SPI_ExchangeByte(W25Q64_PAGE_PROGRAM);
    SPI_ExchangeByte((Page_Address&0xFF0000)>>16);
    SPI_ExchangeByte((Page_Address&0xFF00)>>8);
    SPI_ExchangeByte(Page_Address&0xFF);
    for(i=0;i<Count&&i<255;i++)
    {
        SPI_ExchangeByte(DataArray[i]);
    }
    SPI_Stop();
    W25Q64_WaitBusy();//事后等待
}
/*
如果非要跨页写入则先计算要跨几页，然后分批次写入，最后封装成函数
*/

//W25Q64扇区擦除
void Sector_Erase(uint32_t Sector_Address)
{
    W25Q64_WriteEnable();
    SPI_Start();
    SPI_ExchangeByte(W25Q64_SECTOR_ERASE_4KB);
    SPI_ExchangeByte((Sector_Address&0xFF0000)>>16);
    SPI_ExchangeByte((Sector_Address&0xFF00)>>8);
    SPI_ExchangeByte(Sector_Address&0xFF);
    SPI_Stop();
    W25Q64_WaitBusy();//事后等待
}

//W25Q64块擦除
void Block_Erase_32KB(uint32_t Block_Address)
{
    W25Q64_WriteEnable();
    SPI_Start();
    SPI_ExchangeByte(W25Q64_BLOCK_ERASE_32KB);
    SPI_ExchangeByte((Block_Address&0xFF0000)>>16);
    SPI_ExchangeByte((Block_Address&0xFF00)>>8);
    SPI_ExchangeByte(Block_Address&0xFF);
    SPI_Stop();
    W25Q64_WaitBusy();//事后等待
}

//W25Q64芯片擦除
void Chip_Erase(void)
{
    W25Q64_WriteEnable();
    SPI_Start();
    SPI_ExchangeByte(W25Q64_CHIP_ERASE);
    SPI_Stop();
    W25Q64_WaitBusy();//事后等待
}

//W25Q64读取数据
void W25Q64_ReadData(uint32_t Page_Address, uint8_t *DataArray, uint32_t Count)
{
    uint32_t i;
    SPI_Start();
    SPI_ExchangeByte(W25Q64_READ_DATA);
    SPI_ExchangeByte((Page_Address&0xFF0000)>>16);
    SPI_ExchangeByte((Page_Address&0xFF00)>>8);
    SPI_ExchangeByte(Page_Address&0xFF);
    for(i=0;i<Count;i++)
    {
        DataArray[i]=SPI_ExchangeByte(W25Q64_Trash_BYTE);
    }
    SPI_Stop();
}