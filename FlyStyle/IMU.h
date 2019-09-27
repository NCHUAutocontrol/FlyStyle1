
#include <stm32f4xx_hal.h>
//#include "sysconfig.h"

extern float 	AngleOffset_Rol, AngleOffset_Pit;

typedef struct T_float {
	float X;
	float Y;
	float Z;
}T_float_xyz;
typedef struct T_float_an {
	float pit;
	float yaw;
	float rol;
}T_float_angle;


//void Prepare_Data(T_int16_xyz *acc_in,T_int16_xyz *acc_out);

void AHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz, T_float_angle *angle);





