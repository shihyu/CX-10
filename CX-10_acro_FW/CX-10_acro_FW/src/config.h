// ===== CONFIG ===== //

// Throttle settings
#define MIN_COMMAND 80 // controll starts if throttle is higher then that 
#define MIN_THROTTLE 50 // minimum speed for the motors

// P term 40 == 4.0
#define GYRO_P_ROLL  45
#define GYRO_P_PITCH 45
#define GYRO_P_YAW   70

// I term 40 == 0.040
#define GYRO_I_ROLL  65
#define GYRO_I_PITCH 65
#define GYRO_I_YAW   85

// D term 40 == 40
#define GYRO_D_ROLL  120
#define GYRO_D_PITCH 120
#define GYRO_D_YAW   0

// RC Settings
#define RC_RATE 460 // 100-990
#define RC_ROLL_RATE 88 // 0-100
#define RC_PITCH_RATE 88 // 0-100
#define RC_YAW_RATE 88 // 0-100
// 0,1,2,3,4,5 for Spektrum PPM
// order is Throttle,Roll,Pitch,Yaw,Aux1,Aux2
#define RC_CHAN_ORDER 0,1,2,3,4,5




// ===== CONFIG END ===== //

//includes
#include "stm32f0xx_conf.h"
#include "adc.h"
#include "main.h"
#include "MPU6050.h"
#include "RX.h"
#include "timer.h"
#include "serial.h"

//defines
#define abs(x) ((x) > 0 ? (x) : -(x))
#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))

//globals
extern int16_t RXcommands[6];
extern int8_t Armed;
extern int16_t LiPoVolt;
extern int16_t GyroXYZ[3];
extern int16_t ACCXYZ[3];
extern int16_t I2C_Errors;
extern uint16_t calibGyroDone;