#ifndef SPI_H_
#define SPI_H_
void SPI_Initilize(void);
void SPI_Start(void);
void SPI_Stop(void);
uint8_t SPI_ExchangeByte(uint8_t TxData);
#endif