
#include <IIC.h>
#include <MPU6050.h>
#include <HMC5883L.h>
  
void HMC5883L_WriteReg(int reg_add, int reg_dat)
{
	IIC_Start();
	IIC_Send_Byte(0X3C);
	IIC_Wait_Ack();
	IIC_Send_Byte(reg_add);
	IIC_Wait_Ack();
	IIC_Send_Byte(reg_dat);
	IIC_Wait_Ack(); 
	IIC_Stop();
	
}



void HMC5883L_ReadData(int reg_add, unsigned char*Read, int num)
{
	unsigned char i;
	
	IIC_Start();
	IIC_Send_Byte(0x3c);
	IIC_Wait_Ack();
	IIC_Send_Byte(reg_add);
	IIC_Wait_Ack();
	
	IIC_Start();
	IIC_Send_Byte(0x3d);
	IIC_Wait_Ack(); 
	;
	
	for (i = 0; i < (num - 1); i++) {
		*Read = IIC_Read_Byte(1);
		Read++;
	}
	*Read = IIC_Read_Byte(0);
	IIC_Stop();
}




	 
	
void HMC5883_Init(void)
{
	MPU6050_WriteReg(MPU6050_RA_INT_PIN_CFG, 0x82);
	MPU6050_WriteReg(MPU6050_RA_USER_CTRL, 0x00);
	HMC5883_WriteReg(HMC5883_Register_A, 0x70);
	HMC5883_WriteReg(HMC5883_Register_B, 0x20);	    
	HMC5883_WriteReg(HMC5883_ModeReg, 0x00);			 
}

		 

void GetAngle(short *hcmData)
{ 
	u8 hmc5883_buffer[6]; 
	HMC5883_ReadData(HMC5883_XOUT_H, hmc5883_buffer, 6); 
	hcmData[0] = hmc5883_buffer[0] << 8 | hmc5883_buffer[1]; 
	hcmData[1] = hmc5883_buffer[2] << 8 | hmc5883_buffer[3]; 
	hcmData[2] = hmc5883_buffer[4] << 8 | hmc5883_buffer[5]; 
		
				
}  

	
 
 
 