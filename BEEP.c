#include "BEEP.h"

void BEEP1_Init()
{
  u8 temp;
  BEEP_DeInit();        
  FLASH_Unlock(FLASH_MEMTYPE_DATA);
  while(!(FLASH->IAPSR & FLASH_IAPSR_DUL));
  temp=(uint8_t)(FLASH_ReadOptionByte(0x4803)>>8);
  FLASH_ProgramOptionByte(0x4803,0x80|temp);
  FLASH_Lock(FLASH_MEMTYPE_DATA);         
  BEEP_LSICalibrationConfig(128000);
  BEEP_Init(BEEP_FREQUENCY_4KHZ);
  Clr_BEEP;                     
}