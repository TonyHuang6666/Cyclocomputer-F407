#ifndef W25Q64_H_
#define W25Q64_H_
void W25Q64_WriteEnable(void);
void W25Q64_ReadID(uint8_t *MID, uint16_t *DID);
void W25Q64_Init(void);
void Sector_Erase(uint32_t Sector_Address);
void Block_Erase_32KB(uint32_t Block_Address);
void W25Q64_ReadData(uint32_t Page_Address, uint8_t *DataArray, uint32_t Count);
void Page_Program(uint32_t Page_Address, uint8_t *DataArray, uint16_t Count);
void Chip_Erase(void);
void W25Q64_WaitBusy(void);

#endif