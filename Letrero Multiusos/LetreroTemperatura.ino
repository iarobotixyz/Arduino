///////IAROBOTIXYZ/////////
/////YOUTUBE///////////////
/////BLOG//////////////////
//////GITHUB//////////////

#include <Wire.h>
#define MPU6050_AUX_VDDIO          0x01   // R/W
#define MPU6050_SMPLRT_DIV         0x19   // R/W
#define MPU6050_CONFIG             0x1A   // R/W
#define MPU6050_GYRO_CONFIG        0x1B   // R/W
#define MPU6050_ACCEL_CONFIG       0x1C   // R/W
#define MPU6050_FF_THR             0x1D   // R/W
#define MPU6050_FF_DUR             0x1E   // R/W
#define MPU6050_MOT_THR            0x1F   // R/W
#define MPU6050_MOT_DUR            0x20   // R/W
#define MPU6050_ZRMOT_THR          0x21   // R/W
#define MPU6050_ZRMOT_DUR          0x22   // R/W
#define MPU6050_FIFO_EN            0x23   // R/W
#define MPU6050_I2C_MST_CTRL       0x24   // R/W
#define MPU6050_I2C_SLV0_ADDR      0x25   // R/W
#define MPU6050_I2C_SLV0_REG       0x26   // R/W
#define MPU6050_I2C_SLV0_CTRL      0x27   // R/W
#define MPU6050_I2C_SLV1_ADDR      0x28   // R/W
#define MPU6050_I2C_SLV1_REG       0x29   // R/W
#define MPU6050_I2C_SLV1_CTRL      0x2A   // R/W
#define MPU6050_I2C_SLV2_ADDR      0x2B   // R/W
#define MPU6050_I2C_SLV2_REG       0x2C   // R/W
#define MPU6050_I2C_SLV2_CTRL      0x2D   // R/W
#define MPU6050_I2C_SLV3_ADDR      0x2E   // R/W
#define MPU6050_I2C_SLV3_REG       0x2F   // R/W
#define MPU6050_I2C_SLV3_CTRL      0x30   // R/W
#define MPU6050_I2C_SLV4_ADDR      0x31   // R/W
#define MPU6050_I2C_SLV4_REG       0x32   // R/W
#define MPU6050_I2C_SLV4_DO        0x33   // R/W
#define MPU6050_I2C_SLV4_CTRL      0x34   // R/W
#define MPU6050_I2C_SLV4_DI        0x35   // R  
#define MPU6050_I2C_MST_STATUS     0x36   // R
#define MPU6050_INT_PIN_CFG        0x37   // R/W
#define MPU6050_INT_ENABLE         0x38   // R/W
#define MPU6050_INT_STATUS         0x3A   // R  
#define MPU6050_ACCEL_XOUT_H       0x3B   // R  
#define MPU6050_ACCEL_XOUT_L       0x3C   // R  
#define MPU6050_ACCEL_YOUT_H       0x3D   // R  
#define MPU6050_ACCEL_YOUT_L       0x3E   // R  
#define MPU6050_ACCEL_ZOUT_H       0x3F   // R  
#define MPU6050_ACCEL_ZOUT_L       0x40   // R  
#define MPU6050_TEMP_OUT_H         0x41   // R  
#define MPU6050_TEMP_OUT_L         0x42   // R  
#define MPU6050_GYRO_XOUT_H        0x43   // R  
#define MPU6050_GYRO_XOUT_L        0x44   // R  
#define MPU6050_GYRO_YOUT_H        0x45   // R  
#define MPU6050_GYRO_YOUT_L        0x46   // R  
#define MPU6050_GYRO_ZOUT_H        0x47   // R  
#define MPU6050_GYRO_ZOUT_L        0x48   // R  
#define MPU6050_EXT_SENS_DATA_00   0x49   // R  
#define MPU6050_EXT_SENS_DATA_01   0x4A   // R  
#define MPU6050_EXT_SENS_DATA_02   0x4B   // R  
#define MPU6050_EXT_SENS_DATA_03   0x4C   // R  
#define MPU6050_EXT_SENS_DATA_04   0x4D   // R  
#define MPU6050_EXT_SENS_DATA_05   0x4E   // R  
#define MPU6050_EXT_SENS_DATA_06   0x4F   // R  
#define MPU6050_EXT_SENS_DATA_07   0x50   // R  
#define MPU6050_EXT_SENS_DATA_08   0x51   // R  
#define MPU6050_EXT_SENS_DATA_09   0x52   // R  
#define MPU6050_EXT_SENS_DATA_10   0x53   // R  
#define MPU6050_EXT_SENS_DATA_11   0x54   // R  
#define MPU6050_EXT_SENS_DATA_12   0x55   // R  
#define MPU6050_EXT_SENS_DATA_13   0x56   // R  
#define MPU6050_EXT_SENS_DATA_14   0x57   // R  
#define MPU6050_EXT_SENS_DATA_15   0x58   // R  
#define MPU6050_EXT_SENS_DATA_16   0x59   // R  
#define MPU6050_EXT_SENS_DATA_17   0x5A   // R  
#define MPU6050_EXT_SENS_DATA_18   0x5B   // R  
#define MPU6050_EXT_SENS_DATA_19   0x5C   // R  
#define MPU6050_EXT_SENS_DATA_20   0x5D   // R  
#define MPU6050_EXT_SENS_DATA_21   0x5E   // R  
#define MPU6050_EXT_SENS_DATA_22   0x5F   // R  
#define MPU6050_EXT_SENS_DATA_23   0x60   // R  
#define MPU6050_MOT_DETECT_STATUS  0x61   // R  
#define MPU6050_I2C_SLV0_DO        0x63   // R/W
#define MPU6050_I2C_SLV1_DO        0x64   // R/W
#define MPU6050_I2C_SLV2_DO        0x65   // R/W
#define MPU6050_I2C_SLV3_DO        0x66   // R/W
#define MPU6050_I2C_MST_DELAY_CTRL 0x67   // R/W
#define MPU6050_SIGNAL_PATH_RESET  0x68   // R/W
#define MPU6050_MOT_DETECT_CTRL    0x69   // R/W
#define MPU6050_USER_CTRL          0x6A   // R/W
#define MPU6050_PWR_MGMT_1         0x6B   // R/W
#define MPU6050_PWR_MGMT_2         0x6C   // R/W
#define MPU6050_FIFO_COUNTH        0x72   // R/W
#define MPU6050_FIFO_COUNTL        0x73   // R/W
#define MPU6050_FIFO_R_W           0x74   // R/W
#define MPU6050_WHO_AM_I           0x75   // R

#define MPU6050_D0 0
#define MPU6050_D1 1
#define MPU6050_D2 2
#define MPU6050_D3 3
#define MPU6050_D4 4
#define MPU6050_D5 5
#define MPU6050_D6 6
#define MPU6050_D7 7

#define MPU6050_AUX_VDDIO MPU6050_D7  // I2C high: 1=VDD, 0=VLOGIC

#define MPU6050_DLPF_CFG0     MPU6050_D0
#define MPU6050_DLPF_CFG1     MPU6050_D1
#define MPU6050_DLPF_CFG2     MPU6050_D2
#define MPU6050_EXT_SYNC_SET0 MPU6050_D3
#define MPU6050_EXT_SYNC_SET1 MPU6050_D4
#define MPU6050_EXT_SYNC_SET2 MPU6050_D5

#define MPU6050_EXT_SYNC_SET_0 (0)
#define MPU6050_EXT_SYNC_SET_1 (bit(MPU6050_EXT_SYNC_SET0))
#define MPU6050_EXT_SYNC_SET_2 (bit(MPU6050_EXT_SYNC_SET1))
#define MPU6050_EXT_SYNC_SET_3 (bit(MPU6050_EXT_SYNC_SET1)|bit(MPU6050_EXT_SYNC_SET0))
#define MPU6050_EXT_SYNC_SET_4 (bit(MPU6050_EXT_SYNC_SET2))
#define MPU6050_EXT_SYNC_SET_5 (bit(MPU6050_EXT_SYNC_SET2)|bit(MPU6050_EXT_SYNC_SET0))
#define MPU6050_EXT_SYNC_SET_6 (bit(MPU6050_EXT_SYNC_SET2)|bit(MPU6050_EXT_SYNC_SET1))
#define MPU6050_EXT_SYNC_SET_7 (bit(MPU6050_EXT_SYNC_SET2)|bit(MPU6050_EXT_SYNC_SET1)|bit(MPU6050_EXT_SYNC_SET0))

// Alternative names for the combined definitions.
#define MPU6050_EXT_SYNC_DISABLED     MPU6050_EXT_SYNC_SET_0
#define MPU6050_EXT_SYNC_TEMP_OUT_L   MPU6050_EXT_SYNC_SET_1
#define MPU6050_EXT_SYNC_GYRO_XOUT_L  MPU6050_EXT_SYNC_SET_2
#define MPU6050_EXT_SYNC_GYRO_YOUT_L  MPU6050_EXT_SYNC_SET_3
#define MPU6050_EXT_SYNC_GYRO_ZOUT_L  MPU6050_EXT_SYNC_SET_4
#define MPU6050_EXT_SYNC_ACCEL_XOUT_L MPU6050_EXT_SYNC_SET_5
#define MPU6050_EXT_SYNC_ACCEL_YOUT_L MPU6050_EXT_SYNC_SET_6
#define MPU6050_EXT_SYNC_ACCEL_ZOUT_L MPU6050_EXT_SYNC_SET_7

// Combined definitions for the DLPF_CFG values
#define MPU6050_DLPF_CFG_0 (0)
#define MPU6050_DLPF_CFG_1 (bit(MPU6050_DLPF_CFG0))
#define MPU6050_DLPF_CFG_2 (bit(MPU6050_DLPF_CFG1))
#define MPU6050_DLPF_CFG_3 (bit(MPU6050_DLPF_CFG1)|bit(MPU6050_DLPF_CFG0))
#define MPU6050_DLPF_CFG_4 (bit(MPU6050_DLPF_CFG2))
#define MPU6050_DLPF_CFG_5 (bit(MPU6050_DLPF_CFG2)|bit(MPU6050_DLPF_CFG0))
#define MPU6050_DLPF_CFG_6 (bit(MPU6050_DLPF_CFG2)|bit(MPU6050_DLPF_CFG1))
#define MPU6050_DLPF_CFG_7 (bit(MPU6050_DLPF_CFG2)|bit(MPU6050_DLPF_CFG1)|bit(MPU6050_DLPF_CFG0))

// Alternative names for the combined definitions
// This name uses the bandwidth (Hz) for the accelometer,
// for the gyro the bandwidth is almost the same.
#define MPU6050_DLPF_260HZ    MPU6050_DLPF_CFG_0
#define MPU6050_DLPF_184HZ    MPU6050_DLPF_CFG_1
#define MPU6050_DLPF_94HZ     MPU6050_DLPF_CFG_2
#define MPU6050_DLPF_44HZ     MPU6050_DLPF_CFG_3
#define MPU6050_DLPF_21HZ     MPU6050_DLPF_CFG_4
#define MPU6050_DLPF_10HZ     MPU6050_DLPF_CFG_5
#define MPU6050_DLPF_5HZ      MPU6050_DLPF_CFG_6
#define MPU6050_DLPF_RESERVED MPU6050_DLPF_CFG_7

#define MPU6050_FS_SEL0 MPU6050_D3
#define MPU6050_FS_SEL1 MPU6050_D4
#define MPU6050_ZG_ST   MPU6050_D5
#define MPU6050_YG_ST   MPU6050_D6
#define MPU6050_XG_ST   MPU6050_D7

// Combined definitions for the FS_SEL values
#define MPU6050_FS_SEL_0 (0)
#define MPU6050_FS_SEL_1 (bit(MPU6050_FS_SEL0))
#define MPU6050_FS_SEL_2 (bit(MPU6050_FS_SEL1))
#define MPU6050_FS_SEL_3 (bit(MPU6050_FS_SEL1)|bit(MPU6050_FS_SEL0))

// The name uses the range in degrees per second.
#define MPU6050_FS_SEL_250  MPU6050_FS_SEL_0
#define MPU6050_FS_SEL_500  MPU6050_FS_SEL_1
#define MPU6050_FS_SEL_1000 MPU6050_FS_SEL_2
#define MPU6050_FS_SEL_2000 MPU6050_FS_SEL_3

#define MPU6050_ACCEL_HPF0 MPU6050_D0
#define MPU6050_ACCEL_HPF1 MPU6050_D1
#define MPU6050_ACCEL_HPF2 MPU6050_D2
#define MPU6050_AFS_SEL0   MPU6050_D3
#define MPU6050_AFS_SEL1   MPU6050_D4
#define MPU6050_ZA_ST      MPU6050_D5
#define MPU6050_YA_ST      MPU6050_D6
#define MPU6050_XA_ST      MPU6050_D7

// Combined definitions for the ACCEL_HPF values
#define MPU6050_ACCEL_HPF_0 (0)
#define MPU6050_ACCEL_HPF_1 (bit(MPU6050_ACCEL_HPF0))
#define MPU6050_ACCEL_HPF_2 (bit(MPU6050_ACCEL_HPF1))
#define MPU6050_ACCEL_HPF_3 (bit(MPU6050_ACCEL_HPF1)|bit(MPU6050_ACCEL_HPF0))
#define MPU6050_ACCEL_HPF_4 (bit(MPU6050_ACCEL_HPF2))
#define MPU6050_ACCEL_HPF_7 (bit(MPU6050_ACCEL_HPF2)|bit(MPU6050_ACCEL_HPF1)|bit(MPU6050_ACCEL_HPF0))

// Alternative names for the combined definitions
// The name uses the Cut-off frequency.
#define MPU6050_ACCEL_HPF_RESET  MPU6050_ACCEL_HPF_0
#define MPU6050_ACCEL_HPF_5HZ    MPU6050_ACCEL_HPF_1
#define MPU6050_ACCEL_HPF_2_5HZ  MPU6050_ACCEL_HPF_2
#define MPU6050_ACCEL_HPF_1_25HZ MPU6050_ACCEL_HPF_3
#define MPU6050_ACCEL_HPF_0_63HZ MPU6050_ACCEL_HPF_4
#define MPU6050_ACCEL_HPF_HOLD   MPU6050_ACCEL_HPF_7

// Combined definitions for the AFS_SEL values
#define MPU6050_AFS_SEL_0 (0)
#define MPU6050_AFS_SEL_1 (bit(MPU6050_AFS_SEL0))
#define MPU6050_AFS_SEL_2 (bit(MPU6050_AFS_SEL1))
#define MPU6050_AFS_SEL_3 (bit(MPU6050_AFS_SEL1)|bit(MPU6050_AFS_SEL0))

// Alternative names for the combined definitions
// The name uses the full scale range for the accelerometer.
#define MPU6050_AFS_SEL_2G  MPU6050_AFS_SEL_0
#define MPU6050_AFS_SEL_4G  MPU6050_AFS_SEL_1
#define MPU6050_AFS_SEL_8G  MPU6050_AFS_SEL_2
#define MPU6050_AFS_SEL_16G MPU6050_AFS_SEL_3

// FIFO_EN Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_SLV0_FIFO_EN  MPU6050_D0
#define MPU6050_SLV1_FIFO_EN  MPU6050_D1
#define MPU6050_SLV2_FIFO_EN  MPU6050_D2
#define MPU6050_ACCEL_FIFO_EN MPU6050_D3
#define MPU6050_ZG_FIFO_EN    MPU6050_D4
#define MPU6050_YG_FIFO_EN    MPU6050_D5
#define MPU6050_XG_FIFO_EN    MPU6050_D6
#define MPU6050_TEMP_FIFO_EN  MPU6050_D7

// I2C_MST_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_I2C_MST_CLK0  MPU6050_D0
#define MPU6050_I2C_MST_CLK1  MPU6050_D1
#define MPU6050_I2C_MST_CLK2  MPU6050_D2
#define MPU6050_I2C_MST_CLK3  MPU6050_D3
#define MPU6050_I2C_MST_P_NSR MPU6050_D4
#define MPU6050_SLV_3_FIFO_EN MPU6050_D5
#define MPU6050_WAIT_FOR_ES   MPU6050_D6
#define MPU6050_MULT_MST_EN   MPU6050_D7

// Combined definitions for the I2C_MST_CLK
#define MPU6050_I2C_MST_CLK_0 (0)
#define MPU6050_I2C_MST_CLK_1  (bit(MPU6050_I2C_MST_CLK0))
#define MPU6050_I2C_MST_CLK_2  (bit(MPU6050_I2C_MST_CLK1))
#define MPU6050_I2C_MST_CLK_3  (bit(MPU6050_I2C_MST_CLK1)|bit(MPU6050_I2C_MST_CLK0))
#define MPU6050_I2C_MST_CLK_4  (bit(MPU6050_I2C_MST_CLK2))
#define MPU6050_I2C_MST_CLK_5  (bit(MPU6050_I2C_MST_CLK2)|bit(MPU6050_I2C_MST_CLK0))
#define MPU6050_I2C_MST_CLK_6  (bit(MPU6050_I2C_MST_CLK2)|bit(MPU6050_I2C_MST_CLK1))
#define MPU6050_I2C_MST_CLK_7  (bit(MPU6050_I2C_MST_CLK2)|bit(MPU6050_I2C_MST_CLK1)|bit(MPU6050_I2C_MST_CLK0))
#define MPU6050_I2C_MST_CLK_8  (bit(MPU6050_I2C_MST_CLK3))
#define MPU6050_I2C_MST_CLK_9  (bit(MPU6050_I2C_MST_CLK3)|bit(MPU6050_I2C_MST_CLK0))
#define MPU6050_I2C_MST_CLK_10 (bit(MPU6050_I2C_MST_CLK3)|bit(MPU6050_I2C_MST_CLK1))
#define MPU6050_I2C_MST_CLK_11 (bit(MPU6050_I2C_MST_CLK3)|bit(MPU6050_I2C_MST_CLK1)|bit(MPU6050_I2C_MST_CLK0))
#define MPU6050_I2C_MST_CLK_12 (bit(MPU6050_I2C_MST_CLK3)|bit(MPU6050_I2C_MST_CLK2))
#define MPU6050_I2C_MST_CLK_13 (bit(MPU6050_I2C_MST_CLK3)|bit(MPU6050_I2C_MST_CLK2)|bit(MPU6050_I2C_MST_CLK0))
#define MPU6050_I2C_MST_CLK_14 (bit(MPU6050_I2C_MST_CLK3)|bit(MPU6050_I2C_MST_CLK2)|bit(MPU6050_I2C_MST_CLK1))
#define MPU6050_I2C_MST_CLK_15 (bit(MPU6050_I2C_MST_CLK3)|bit(MPU6050_I2C_MST_CLK2)|bit(MPU6050_I2C_MST_CLK1)|bit(MPU6050_I2C_MST_CLK0))

// Alternative names for the combined definitions
// The names uses I2C Master Clock Speed in kHz.
#define MPU6050_I2C_MST_CLK_348KHZ MPU6050_I2C_MST_CLK_0
#define MPU6050_I2C_MST_CLK_333KHZ MPU6050_I2C_MST_CLK_1
#define MPU6050_I2C_MST_CLK_320KHZ MPU6050_I2C_MST_CLK_2
#define MPU6050_I2C_MST_CLK_308KHZ MPU6050_I2C_MST_CLK_3
#define MPU6050_I2C_MST_CLK_296KHZ MPU6050_I2C_MST_CLK_4
#define MPU6050_I2C_MST_CLK_286KHZ MPU6050_I2C_MST_CLK_5
#define MPU6050_I2C_MST_CLK_276KHZ MPU6050_I2C_MST_CLK_6
#define MPU6050_I2C_MST_CLK_267KHZ MPU6050_I2C_MST_CLK_7
#define MPU6050_I2C_MST_CLK_258KHZ MPU6050_I2C_MST_CLK_8
#define MPU6050_I2C_MST_CLK_500KHZ MPU6050_I2C_MST_CLK_9
#define MPU6050_I2C_MST_CLK_471KHZ MPU6050_I2C_MST_CLK_10
#define MPU6050_I2C_MST_CLK_444KHZ MPU6050_I2C_MST_CLK_11
#define MPU6050_I2C_MST_CLK_421KHZ MPU6050_I2C_MST_CLK_12
#define MPU6050_I2C_MST_CLK_400KHZ MPU6050_I2C_MST_CLK_13
#define MPU6050_I2C_MST_CLK_381KHZ MPU6050_I2C_MST_CLK_14
#define MPU6050_I2C_MST_CLK_364KHZ MPU6050_I2C_MST_CLK_15

// I2C_SLV0_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_I2C_SLV0_RW MPU6050_D7

// I2C_SLV0_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_I2C_SLV0_LEN0    MPU6050_D0
#define MPU6050_I2C_SLV0_LEN1    MPU6050_D1
#define MPU6050_I2C_SLV0_LEN2    MPU6050_D2
#define MPU6050_I2C_SLV0_LEN3    MPU6050_D3
#define MPU6050_I2C_SLV0_GRP     MPU6050_D4
#define MPU6050_I2C_SLV0_REG_DIS MPU6050_D5
#define MPU6050_I2C_SLV0_BYTE_SW MPU6050_D6
#define MPU6050_I2C_SLV0_EN      MPU6050_D7

// A mask for the length
#define MPU6050_I2C_SLV0_LEN_MASK 0x0F

#define MPU6050_I2C_SLV1_RW MPU6050_D7

#define MPU6050_I2C_SLV1_LEN0    MPU6050_D0
#define MPU6050_I2C_SLV1_LEN1    MPU6050_D1
#define MPU6050_I2C_SLV1_LEN2    MPU6050_D2
#define MPU6050_I2C_SLV1_LEN3    MPU6050_D3
#define MPU6050_I2C_SLV1_GRP     MPU6050_D4
#define MPU6050_I2C_SLV1_REG_DIS MPU6050_D5
#define MPU6050_I2C_SLV1_BYTE_SW MPU6050_D6
#define MPU6050_I2C_SLV1_EN      MPU6050_D7

// A mask for the length
#define MPU6050_I2C_SLV1_LEN_MASK 0x0F
#define MPU6050_I2C_SLV2_RW MPU6050_D7
#define MPU6050_I2C_SLV2_LEN0    MPU6050_D0
#define MPU6050_I2C_SLV2_LEN1    MPU6050_D1
#define MPU6050_I2C_SLV2_LEN2    MPU6050_D2
#define MPU6050_I2C_SLV2_LEN3    MPU6050_D3
#define MPU6050_I2C_SLV2_GRP     MPU6050_D4
#define MPU6050_I2C_SLV2_REG_DIS MPU6050_D5
#define MPU6050_I2C_SLV2_BYTE_SW MPU6050_D6
#define MPU6050_I2C_SLV2_EN      MPU6050_D7

// A mask for the length
#define MPU6050_I2C_SLV2_LEN_MASK 0x0F

// I2C_SLV3_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_I2C_SLV3_RW MPU6050_D7

// I2C_SLV3_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_I2C_SLV3_LEN0    MPU6050_D0
#define MPU6050_I2C_SLV3_LEN1    MPU6050_D1
#define MPU6050_I2C_SLV3_LEN2    MPU6050_D2
#define MPU6050_I2C_SLV3_LEN3    MPU6050_D3
#define MPU6050_I2C_SLV3_GRP     MPU6050_D4
#define MPU6050_I2C_SLV3_REG_DIS MPU6050_D5
#define MPU6050_I2C_SLV3_BYTE_SW MPU6050_D6
#define MPU6050_I2C_SLV3_EN      MPU6050_D7

// A mask for the length
#define MPU6050_I2C_SLV3_LEN_MASK 0x0F
#define MPU6050_I2C_SLV4_RW MPU6050_D7
#define MPU6050_I2C_MST_DLY0     MPU6050_D0
#define MPU6050_I2C_MST_DLY1     MPU6050_D1
#define MPU6050_I2C_MST_DLY2     MPU6050_D2
#define MPU6050_I2C_MST_DLY3     MPU6050_D3
#define MPU6050_I2C_MST_DLY4     MPU6050_D4
#define MPU6050_I2C_SLV4_REG_DIS MPU6050_D5
#define MPU6050_I2C_SLV4_INT_EN  MPU6050_D6
#define MPU6050_I2C_SLV4_EN      MPU6050_D7

// A mask for the delay
#define MPU6050_I2C_MST_DLY_MASK 0x1F

// I2C_MST_STATUS Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_I2C_SLV0_NACK MPU6050_D0
#define MPU6050_I2C_SLV1_NACK MPU6050_D1
#define MPU6050_I2C_SLV2_NACK MPU6050_D2
#define MPU6050_I2C_SLV3_NACK MPU6050_D3
#define MPU6050_I2C_SLV4_NACK MPU6050_D4
#define MPU6050_I2C_LOST_ARB  MPU6050_D5
#define MPU6050_I2C_SLV4_DONE MPU6050_D6
#define MPU6050_PASS_THROUGH  MPU6050_D7

// I2C_PIN_CFG Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_CLKOUT_EN       MPU6050_D0
#define MPU6050_I2C_BYPASS_EN   MPU6050_D1
#define MPU6050_FSYNC_INT_EN    MPU6050_D2
#define MPU6050_FSYNC_INT_LEVEL MPU6050_D3
#define MPU6050_INT_RD_CLEAR    MPU6050_D4
#define MPU6050_LATCH_INT_EN    MPU6050_D5
#define MPU6050_INT_OPEN        MPU6050_D6
#define MPU6050_INT_LEVEL       MPU6050_D7

// INT_ENABLE Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_DATA_RDY_EN    MPU6050_D0
#define MPU6050_I2C_MST_INT_EN MPU6050_D3
#define MPU6050_FIFO_OFLOW_EN  MPU6050_D4
#define MPU6050_ZMOT_EN        MPU6050_D5
#define MPU6050_MOT_EN         MPU6050_D6
#define MPU6050_FF_EN          MPU6050_D7

// INT_STATUS Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_DATA_RDY_INT   MPU6050_D0
#define MPU6050_I2C_MST_INT    MPU6050_D3
#define MPU6050_FIFO_OFLOW_INT MPU6050_D4
#define MPU6050_ZMOT_INT       MPU6050_D5
#define MPU6050_MOT_INT        MPU6050_D6
#define MPU6050_FF_INT         MPU6050_D7

// MOT_DETECT_STATUS Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_MOT_ZRMOT MPU6050_D0
#define MPU6050_MOT_ZPOS  MPU6050_D2
#define MPU6050_MOT_ZNEG  MPU6050_D3
#define MPU6050_MOT_YPOS  MPU6050_D4
#define MPU6050_MOT_YNEG  MPU6050_D5
#define MPU6050_MOT_XPOS  MPU6050_D6
#define MPU6050_MOT_XNEG  MPU6050_D7

// IC2_MST_DELAY_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_I2C_SLV0_DLY_EN MPU6050_D0
#define MPU6050_I2C_SLV1_DLY_EN MPU6050_D1
#define MPU6050_I2C_SLV2_DLY_EN MPU6050_D2
#define MPU6050_I2C_SLV3_DLY_EN MPU6050_D3
#define MPU6050_I2C_SLV4_DLY_EN MPU6050_D4
#define MPU6050_DELAY_ES_SHADOW MPU6050_D7

// SIGNAL_PATH_RESET Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_TEMP_RESET  MPU6050_D0
#define MPU6050_ACCEL_RESET MPU6050_D1
#define MPU6050_GYRO_RESET  MPU6050_D2

// MOT_DETECT_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_MOT_COUNT0      MPU6050_D0
#define MPU6050_MOT_COUNT1      MPU6050_D1
#define MPU6050_FF_COUNT0       MPU6050_D2
#define MPU6050_FF_COUNT1       MPU6050_D3
#define MPU6050_ACCEL_ON_DELAY0 MPU6050_D4
#define MPU6050_ACCEL_ON_DELAY1 MPU6050_D5

// Combined definitions for the MOT_COUNT
#define MPU6050_MOT_COUNT_0 (0)
#define MPU6050_MOT_COUNT_1 (bit(MPU6050_MOT_COUNT0))
#define MPU6050_MOT_COUNT_2 (bit(MPU6050_MOT_COUNT1))
#define MPU6050_MOT_COUNT_3 (bit(MPU6050_MOT_COUNT1)|bit(MPU6050_MOT_COUNT0))

// Alternative names for the combined definitions
#define MPU6050_MOT_COUNT_RESET MPU6050_MOT_COUNT_0

// Combined definitions for the FF_COUNT
#define MPU6050_FF_COUNT_0 (0)
#define MPU6050_FF_COUNT_1 (bit(MPU6050_FF_COUNT0))
#define MPU6050_FF_COUNT_2 (bit(MPU6050_FF_COUNT1))
#define MPU6050_FF_COUNT_3 (bit(MPU6050_FF_COUNT1)|bit(MPU6050_FF_COUNT0))

// Alternative names for the combined definitions
#define MPU6050_FF_COUNT_RESET MPU6050_FF_COUNT_0

// Combined definitions for the ACCEL_ON_DELAY
#define MPU6050_ACCEL_ON_DELAY_0 (0)
#define MPU6050_ACCEL_ON_DELAY_1 (bit(MPU6050_ACCEL_ON_DELAY0))
#define MPU6050_ACCEL_ON_DELAY_2 (bit(MPU6050_ACCEL_ON_DELAY1))
#define MPU6050_ACCEL_ON_DELAY_3 (bit(MPU6050_ACCEL_ON_DELAY1)|bit(MPU6050_ACCEL_ON_DELAY0))

// Alternative names for the ACCEL_ON_DELAY
#define MPU6050_ACCEL_ON_DELAY_0MS MPU6050_ACCEL_ON_DELAY_0
#define MPU6050_ACCEL_ON_DELAY_1MS MPU6050_ACCEL_ON_DELAY_1
#define MPU6050_ACCEL_ON_DELAY_2MS MPU6050_ACCEL_ON_DELAY_2
#define MPU6050_ACCEL_ON_DELAY_3MS MPU6050_ACCEL_ON_DELAY_3

// USER_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_SIG_COND_RESET MPU6050_D0
#define MPU6050_I2C_MST_RESET  MPU6050_D1
#define MPU6050_FIFO_RESET     MPU6050_D2
#define MPU6050_I2C_IF_DIS     MPU6050_D4   // must be 0 for MPU-6050
#define MPU6050_I2C_MST_EN     MPU6050_D5
#define MPU6050_FIFO_EN        MPU6050_D6

// PWR_MGMT_1 Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_CLKSEL0      MPU6050_D0
#define MPU6050_CLKSEL1      MPU6050_D1
#define MPU6050_CLKSEL2      MPU6050_D2
#define MPU6050_TEMP_DIS     MPU6050_D3    // 1: disable temperature sensor
#define MPU6050_CYCLE        MPU6050_D5    // 1: sample and sleep
#define MPU6050_SLEEP        MPU6050_D6    // 1: sleep mode
#define MPU6050_DEVICE_RESET MPU6050_D7    // 1: reset to default values

// Combined definitions for the CLKSEL
#define MPU6050_CLKSEL_0 (0)
#define MPU6050_CLKSEL_1 (bit(MPU6050_CLKSEL0))
#define MPU6050_CLKSEL_2 (bit(MPU6050_CLKSEL1))
#define MPU6050_CLKSEL_3 (bit(MPU6050_CLKSEL1)|bit(MPU6050_CLKSEL0))
#define MPU6050_CLKSEL_4 (bit(MPU6050_CLKSEL2))
#define MPU6050_CLKSEL_5 (bit(MPU6050_CLKSEL2)|bit(MPU6050_CLKSEL0))
#define MPU6050_CLKSEL_6 (bit(MPU6050_CLKSEL2)|bit(MPU6050_CLKSEL1))
#define MPU6050_CLKSEL_7 (bit(MPU6050_CLKSEL2)|bit(MPU6050_CLKSEL1)|bit(MPU6050_CLKSEL0))

// Alternative names for the combined definitions
#define MPU6050_CLKSEL_INTERNAL    MPU6050_CLKSEL_0
#define MPU6050_CLKSEL_X           MPU6050_CLKSEL_1
#define MPU6050_CLKSEL_Y           MPU6050_CLKSEL_2
#define MPU6050_CLKSEL_Z           MPU6050_CLKSEL_3
#define MPU6050_CLKSEL_EXT_32KHZ   MPU6050_CLKSEL_4
#define MPU6050_CLKSEL_EXT_19_2MHZ MPU6050_CLKSEL_5
#define MPU6050_CLKSEL_RESERVED    MPU6050_CLKSEL_6
#define MPU6050_CLKSEL_STOP        MPU6050_CLKSEL_7

// PWR_MGMT_2 Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU6050_STBY_ZG       MPU6050_D0
#define MPU6050_STBY_YG       MPU6050_D1
#define MPU6050_STBY_XG       MPU6050_D2
#define MPU6050_STBY_ZA       MPU6050_D3
#define MPU6050_STBY_YA       MPU6050_D4
#define MPU6050_STBY_XA       MPU6050_D5
#define MPU6050_LP_WAKE_CTRL0 MPU6050_D6
#define MPU6050_LP_WAKE_CTRL1 MPU6050_D7

// Combined definitions for the LP_WAKE_CTRL
#define MPU6050_LP_WAKE_CTRL_0 (0)
#define MPU6050_LP_WAKE_CTRL_1 (bit(MPU6050_LP_WAKE_CTRL0))
#define MPU6050_LP_WAKE_CTRL_2 (bit(MPU6050_LP_WAKE_CTRL1))
#define MPU6050_LP_WAKE_CTRL_3 (bit(MPU6050_LP_WAKE_CTRL1)|bit(MPU6050_LP_WAKE_CTRL0))

// Alternative names for the combined definitions
// The names uses the Wake-up Frequency.
#define MPU6050_LP_WAKE_1_25HZ MPU6050_LP_WAKE_CTRL_0
#define MPU6050_LP_WAKE_2_5HZ  MPU6050_LP_WAKE_CTRL_1
#define MPU6050_LP_WAKE_5HZ    MPU6050_LP_WAKE_CTRL_2
#define MPU6050_LP_WAKE_10HZ   MPU6050_LP_WAKE_CTRL_3
#define MPU6050_I2C_ADDRESS 0x68
typedef union accel_t_gyro_union
{
  struct
  {
    uint8_t x_accel_h;
    uint8_t x_accel_l;
    uint8_t y_accel_h;
    uint8_t y_accel_l;
    uint8_t z_accel_h;
    uint8_t z_accel_l;
    uint8_t t_h;
    uint8_t t_l;
    uint8_t x_gyro_h;
    uint8_t x_gyro_l;
    uint8_t y_gyro_h;
    uint8_t y_gyro_l;
    uint8_t z_gyro_h;
    uint8_t z_gyro_l;
  } reg;
  struct 
  {
    int16_t x_accel;
    int16_t y_accel;
    int16_t z_accel;
    int16_t temperature;
    int16_t x_gyro;
    int16_t y_gyro;
    int16_t z_gyro;
  } value;
};
//Display
int timer = 2;
int letra = 6;//13-6
int cont=0;

void setup()
{      
  int error;
  uint8_t cm;


  //Serial.begin(9600);


  // Initialize the 'Wire' class for the I2C-bus.
  Wire.begin();
  error = MPU6050_read (MPU6050_WHO_AM_I, &cm, 1);
  error = MPU6050_read (MPU6050_PWR_MGMT_2, &cm, 1);
  // Clear the 'sleep' bit to start the sensor.
  MPU6050_write_reg (MPU6050_PWR_MGMT_1, 0);

  //Display
    pinMode(13, OUTPUT);//P 13
  pinMode(12, OUTPUT);//A 12
  pinMode(11, OUTPUT);//B 11
  pinMode(10, OUTPUT);//c 10
  pinMode(9, OUTPUT);//d 9
  pinMode(8, OUTPUT);//e 8
  pinMode(7, OUTPUT);//F 7
  pinMode(6, OUTPUT);//G 6 -
  /////////////////////////////////
  //NOTA:////PIN 2 NO SIRVE DE SALIDA EN ESTE CIRCUITO
  //En su lugar Ocupamos A0 para Display 3
  pinMode(0, OUTPUT);//D1
  pinMode(1, OUTPUT);//D2 
  pinMode(A0, OUTPUT);//D3
  pinMode(3, OUTPUT);//D4 
  pinMode(4, OUTPUT);//D5 
  pinMode(5, OUTPUT);//D6 
  
}


void loop()
{

  guapaguao();

  //delay(500);
}


//Display
void guapaguao()
{
  //Temp
    int error;
  double dT;
  accel_t_gyro_union accel_t_gyro;

  error = MPU6050_read (MPU6050_ACCEL_XOUT_H, (uint8_t *) &accel_t_gyro, sizeof(accel_t_gyro));

  uint8_t swap;
  #define SWAP(x,y) swap = x; x = y; y = swap

  SWAP (accel_t_gyro.reg.x_accel_h, accel_t_gyro.reg.x_accel_l);
  SWAP (accel_t_gyro.reg.y_accel_h, accel_t_gyro.reg.y_accel_l);
  SWAP (accel_t_gyro.reg.z_accel_h, accel_t_gyro.reg.z_accel_l);
  SWAP (accel_t_gyro.reg.t_h, accel_t_gyro.reg.t_l);
  SWAP (accel_t_gyro.reg.x_gyro_h, accel_t_gyro.reg.x_gyro_l);
  SWAP (accel_t_gyro.reg.y_gyro_h, accel_t_gyro.reg.y_gyro_l);
  SWAP (accel_t_gyro.reg.z_gyro_h, accel_t_gyro.reg.z_gyro_l);

  // Print the raw acceleration values
 int accel_x, accel_y, accel_z;

 accel_x=accel_t_gyro.value.x_accel*0.061035156;
 accel_y=accel_t_gyro.value.y_accel*0.061035156;
 accel_z=accel_t_gyro.value.z_accel*0.061035156;
 
  //Serial.print(F("Aceleracion: x="));
  //Serial.print(accel_x, DEC);
  //Serial.print(F(" mG, y="));
  //Serial.print(accel_y, DEC);
  //Serial.print(F(" mG, z="));
  //Serial.print(accel_z, DEC);
  //Serial.print(F(" mG, Giroscopio: x="));
  
  // Print the raw gyro values.
  //Serial.print(accel_t_gyro.value.x_gyro, DEC);
  //Serial.print(F(" b, y="));
  //Serial.print(accel_t_gyro.value.y_gyro, DEC);
  //Serial.print(F(" b, z="));
  //Serial.print(accel_t_gyro.value.z_gyro, DEC);
  //Serial.print(F(", Temp: "));
  
  // The temperature sensor is -40 to +85 degrees Celsius.
  // It is a signed integer.
  // According to the datasheet: 
  //   340 per degrees Celsius, -512 at 35 degrees.
  // At 0 degrees: -512 - (340 * 35) = -12412
 
  dT = ( (double) accel_t_gyro.value.temperature + 12412.0) / 340.0;
  //Serial.print(dT, 3);
  //Serial.println(F(" C"));

  //Display
  int del=200;
  cont=cont+1;
   if (cont <= del) 
     {
          r(5);
          e(4);
          n(3);
          a(2);
          t(1);
          a(0);
          
          //h(5);
          //a(4);
          //z(3);
          
          //e(1);
          //l(0);
          
          //dos(4);
          //cero(3);
          //dos(2);
          //cero(1);
          
              
        cont=cont+1;  
      } 
 if (cont > del  && cont <= (del*2))
    {
          //m(4);
          //a(3);
          //i(2);
          //z(1);
          
          //m(4);
          //u(3);
          //n(2);
          //d(1);
          //o(0);
          
          t(4);
          e(3);
          m(2);
          p(1);
         
    }
 if (cont > (del*2)  && cont <= (del*3))
    {
          //r(4);
          //e(3);
          //n(2);
          //a(1);
          //t(1);
          //a(0);
          
          //x(3);
          //y(2);
          //z(1);
          
          //dT
          escribir(dT);
          gr(2);//Simbolo de Grados
          c(1);//C de Centigrados
          
      if (cont == (del*3))
      {
        cont=0;
       }
      
    }

}//Fin Var guapaguao

void escribir(int n){ //funcion para escribir el numero en el display
   switch(n){
//////////////////////////////////////////////////Numeracion Grados 

         case -10: // 
         menos(5);
         uno(4);
         cero(3);
         break;
         case -9: //
         menos(4);
         nueve(3);
         break;
         case -8: // 
         menos(4);
         ocho(3);
         break;
         case -7: // 
         menos(4);
         siete(3);
         break;
         case -6: // 
         menos(4);
         seis(3);
         break;
         case -5: // 
         menos(4);
         cinco(3);
         break;
         case -4: // 
         menos(4);
         cuatro(3);
         break;
         case -3: // 
         menos(4);
         tres(3);
         break;
         case -2: // 
         menos(4);
         dos(3);
         break;
         case -1: // 
         menos(4);
         uno(3);
         break;
         case 0: // 
         cero(3);
         break;
         case 1: //  
         uno(3);
         break;
         case 2: //  
         dos(3);
         break;
         case 3: //  
         tres(3);
         break;
         case 4: //  
         cuatro(3);
         break;
         case 5: //  
         cinco(3);
         break;
         case 6: //  
         seis(3);
         break;
         case 7: //  
         siete(3);
         break;
         case 8: //  
         ocho(3);
         break;
         case 9: //  
         nueve(3);
         break;
         case 10: //  
         uno(4);
         cero(3);
         break;
         case 11: //  
         uno(4);
         uno(3);
         break;
         case 12: //  
         uno(4);
         dos(3);
         break;
         case 13: //  
         uno(4);
         tres(3);
         break;
         case 14: //  
         uno(4);
         cuatro(3);
         break;
         case 15: //  
         uno(4);
         cinco(3);
         break;
         case 16: //  
         uno(4);
         seis(3);
         break;
         case 17: //  
         uno(4);
         siete(3);
         break;
         case 18: //  
         uno(4);
         ocho(3);
         break;
         case 19: //  
         uno(4);
         nueve(3);
         break;
         case 20: //  
         dos(4);
         cero(3);
         break;
         case 21: //  
         dos(4);
         uno(3);
         break;
         case 22: //  
         dos(4);
         dos(3);
         break;
         case 23: // 
         dos(4);
         tres(3);
         break;
         case 24: //
         dos(4);
         cuatro(3);
         break;
         case 25: // 
         dos(4);
         cinco(3);
         break;
         case 26: // 
         dos(4);
         seis(3);
         break;
         case 27: // 
         dos(4);
         siete(3);
         break;
         case 28: // 
         dos(4);
         ocho(3);
         break;
         case 29: // 
         dos(4);
         nueve(3);
         break;
         case 30: //  
         tres(4);
         cero(3);
         break;
         case 31: //  
         tres(4);
         uno(3);
         break;
         case 32: //  
         tres(4);
         dos(3);
         break;
         case 33: //  
         tres(3);
         tres(4);
         break;
         case 34: //  
         tres(4);
         cuatro(3);
         break;
         case 35: //  
         tres(4);
         cinco(3);
         break;
         case 36: //  
         tres(4);
         seis(3);
         break;
         case 37: //  
         tres(4);
         siete(3);
         break;
         case 38: //  
         tres(4);
         ocho(3);
         break;
         case 39: //  
         tres(4);
         nueve(3);
         break;
         case 40: //  
         cuatro(4);
         cero(3);
         break;
         case 41: //  
         cuatro(4);
         uno(3);
         break;
         case 42: //  
         cuatro(4);
         dos(3);
         break;
         case 43: //  
         cuatro(4);
         tres(3);
         break;
         case 44: //  
         cuatro(4);
         cuatro(3);
         break;
         case 45: //  
         cuatro(4);
         cinco(3);
         break;
         case 46: //  
         cuatro(4);
         seis(3);
         break;
         case 47: //  
         cuatro(4);
         siete(3);
         break;
         case 48: //  
         cuatro(4);
         ocho(3);
         break;
         case 49: //  
         cuatro(4);
         nueve(3);
         break;
         case 50: //  
         cinco(4);
         cero(3);
         break;
     /////Arriba de 36 grados 
   }}

void menos(int menoss)
{
if (menoss==2)
{
  menoss=A0;
}
    //Letra 0
  digitalWrite(6, HIGH);//
  ///PIN ACTIVA
  digitalWrite(menoss, HIGH);
  delay(timer);
      //Letra -
  digitalWrite(6, LOW);//
  ///PIN ACTIVA
  digitalWrite(menoss, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  }

 void cero(int ceroo)
{
if (ceroo==2)
{
  ceroo=A0;
}
    //Letra 0
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(9, HIGH);//d
  ///PIN ACTIVA
  digitalWrite(ceroo, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(9, LOW);//d 
  ///PIN ACTIVA
  digitalWrite(ceroo, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  }
  
 void uno(int unoo)
{
if (unoo==2)
{
  unoo=A0;
}
    //Letra 0
  //digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  //digitalWrite(7, HIGH);//F
  //digitalWrite(9, HIGH);//d
  ///PIN ACTIVA
  digitalWrite(unoo, HIGH);
  delay(timer);
      //Letra 1
  //digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  //digitalWrite(7, LOW);//F
  //digitalWrite(9, LOW);//d 
  ///PIN ACTIVA
  digitalWrite(unoo, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

void dos(int doss)
{
  if (doss==2)
{
  doss=A0;
}
   //Letra E
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//
  digitalWrite(9, HIGH);//D
  digitalWrite(8, HIGH);//E
  //digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(doss, HIGH);
  delay(timer);
  
    digitalWrite(12, LOW);//A
    digitalWrite(11, LOW);//
  digitalWrite(9, LOW);//D
  digitalWrite(8, LOW);//E
  //digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(doss, LOW);
  //delay(timer);
  }

void tres(int tress)
{
if (tress==2)
{
  tress=A0;
}
    //Letra 0
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  //digitalWrite(7, HIGH);//F
  digitalWrite(9, HIGH);//d
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(tress, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  //digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G
  digitalWrite(9, LOW);//d 
  ///PIN ACTIVA
  digitalWrite(tress, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

void cuatro(int cuatroo)
{
  if (cuatroo==2)
{
  cuatroo=A0;
}
   //Letra P
  //digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(cuatroo, HIGH);
  delay(timer);
  
    //digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(cuatroo, LOW);
  //delay(timer);
  }

void cinco(int cincoo)
{
if (cincoo==2)
{
  cincoo=A0;
}
    //Letra 0
  digitalWrite(12, HIGH);//A
  //digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(9, HIGH);//d
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(cincoo, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  //digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G
  digitalWrite(9, LOW);//d 
  ///PIN ACTIVA
  digitalWrite(cincoo, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

void seis(int seiss)
{
  if (seiss==2)
{
  seiss=A0;
}
    //Letra b
    digitalWrite(12, HIGH);//A
  digitalWrite(7, HIGH);//F
  digitalWrite(8, HIGH);//E
  digitalWrite(9, HIGH);//D
  digitalWrite(6, HIGH);//G 
  digitalWrite(10, HIGH);// 
  ///PIN ACTIVA
  digitalWrite(seiss, HIGH);
  delay(timer);
  ///
  digitalWrite(12, LOW);//A
    digitalWrite(7, LOW);//F
  digitalWrite(8, LOW);//E
  digitalWrite(9, LOW);//D
  digitalWrite(6, LOW);//G
  digitalWrite(10, LOW);// 
  ///PIN ACTIVA
  digitalWrite(seiss, LOW);
  //delay(timer);

  }

 void siete(int sietee)
{
if (sietee==2)
{
  sietee=A0;
}
    //Letra 0
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  //digitalWrite(7, HIGH);//F
  //digitalWrite(9, HIGH);//d
  ///PIN ACTIVA
  digitalWrite(sietee, HIGH);
  delay(timer);
      //Letra 7
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  //digitalWrite(7, LOW);//F
  //digitalWrite(9, LOW);//d 
  ///PIN ACTIVA
  digitalWrite(sietee, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }
 void ocho(int ochoo)
{
if (ochoo==2)
{
  ochoo=A0;
}
    //Letra 0
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  digitalWrite(9, HIGH);//d
  ///PIN ACTIVA
  digitalWrite(ochoo, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  digitalWrite(9, LOW);//d 
  ///PIN ACTIVA
  digitalWrite(ochoo, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  }
  
   void nueve(int nuevee)
{
if (nuevee==2)
{
  nuevee=A0;
}
    //Letra 9
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  digitalWrite(9, HIGH);//d
  ///PIN ACTIVA
  digitalWrite(nuevee, HIGH);
  delay(timer);
      //Letra 9
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  digitalWrite(9, LOW);//d 
  ///PIN ACTIVA
  digitalWrite(nuevee, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

  
   void a(int vari)
{
if (vari==2)
{
  vari=A0;
}
    //Letra A
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vari, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vari, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

void b(int vbb)
{
  if (vbb==2)
{
  vbb=A0;
}
    //Letra b
  digitalWrite(7, HIGH);//F
  digitalWrite(8, HIGH);//E
  digitalWrite(9, HIGH);//D
  digitalWrite(6, HIGH);//G 
  digitalWrite(10, HIGH);// 
  ///PIN ACTIVA
  digitalWrite(vbb, HIGH);
  delay(timer);
  ///
    digitalWrite(7, LOW);//F
  digitalWrite(8, LOW);//E
  digitalWrite(9, LOW);//D
  digitalWrite(6, LOW);//G
  digitalWrite(10, LOW);// 
  ///PIN ACTIVA
  digitalWrite(vbb, LOW);
  //delay(timer);

  }

   void c(int ce)
{
if (ce==2)
{
  ce=A0;
}
    //Letra 0
  digitalWrite(12, HIGH);//A
  //digitalWrite(11, HIGH);//B
  //digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(9, HIGH);//d
  ///PIN ACTIVA
  digitalWrite(ce, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  //digitalWrite(11, LOW);//B
  //digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(9, LOW);//d 
  ///PIN ACTIVA
  digitalWrite(ce, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }
  
void d(int vdd)
{
  if (vdd==2)
{
  vdd=A0;
}
    //Letra d
  digitalWrite(11, HIGH);//
  digitalWrite(10, HIGH);//
  digitalWrite(9, HIGH);//d
  digitalWrite(8, HIGH);//E
  
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vdd, HIGH);
 
  delay(timer);
      //Letra d
  digitalWrite(11, LOW);//
  digitalWrite(10, LOW);//
  digitalWrite(9, LOW);//d
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vdd, LOW);
 
  //delay(timer);
  }
  
void e(int vae)
{
  if (vae==2)
{
  vae=A0;
}
   //Letra E
  digitalWrite(12, HIGH);//A
  digitalWrite(9, HIGH);//D
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vae, HIGH);
  delay(timer);
  
    digitalWrite(12, LOW);//A
  digitalWrite(9, LOW);//D
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vae, LOW);
  //delay(timer);
  }

 void g(int gee)
{
if (gee==2)
{
  gee=A0;
}
    //Letra 0
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  digitalWrite(9, HIGH);//d
  ///PIN ACTIVA
  digitalWrite(gee, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  digitalWrite(9, LOW);//d 
  ///PIN ACTIVA
  digitalWrite(gee, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

   void h(int vhri)
{
if (vhri==2)
{
  vhri=A0;
}
    //Letra h
  //digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vhri, HIGH);
  delay(timer);
      //Letra h
  //digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vhri, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

 void i(int vii)
{
if (vii==2)
{
  vii=A0;
}
    //Letra h
  //digitalWrite(12, HIGH);//A
  //digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  //digitalWrite(7, HIGH);//F
  //digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vii, HIGH);
  delay(timer);
      //Letra h
  //digitalWrite(12, LOW);//A
 // digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  //digitalWrite(7, LOW);//F
  //digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vii, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

void r(int varr)
{
  if (varr==2)
{
  varr=A0;
}
    //Letra r
  digitalWrite(8, HIGH);//E
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(varr, HIGH);
  delay(timer);
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(varr, LOW);
  //delay(timer);
  }
void l(int vall)
{
  if (vall==2)
{
  vall=A0;
}
    //Letra l
  digitalWrite(7, HIGH);//F
  digitalWrite(8, HIGH);//E
  digitalWrite(9, HIGH);//D
  //digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vall, HIGH);
  delay(timer);
  ///
    digitalWrite(7, LOW);//F
  digitalWrite(8, LOW);//E
  digitalWrite(9, LOW);//D
  //digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vall, LOW);
  //delay(timer);

  }

  void t(int vat)
{
  if (vat==2)
{
  vat=A0;
}
    //Letra t
  digitalWrite(7, HIGH);//F
  digitalWrite(8, HIGH);//E
  digitalWrite(9, HIGH);//D
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vat, HIGH);
  delay(timer);
  ///
    digitalWrite(7, LOW);//F
  digitalWrite(8, LOW);//E
  digitalWrite(9, LOW);//D
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vat, LOW);
  //delay(timer);

  }
void m(int vamm)
{
  if (vamm==2)
{
  vamm=A0;
}
    //Letra n
  digitalWrite(12, HIGH);//
  digitalWrite(10, HIGH);//
  
  //digitalWrite(7, HIGH);//
  digitalWrite(8, HIGH);//E
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vamm, HIGH);
 
  delay(timer);
      //Letra n
  digitalWrite(12, LOW);//
  digitalWrite(10, LOW);//
  //digitalWrite(7, LOW);//
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vamm, LOW);
 
  //delay(timer);
  }
  
void n(int vann)
{
  if (vann==2)
{
  vann=A0;
}
    //Letra n
  digitalWrite(10, HIGH);//
  digitalWrite(8, HIGH);//E
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vann, HIGH);
 
  delay(timer);
      //Letra n
  digitalWrite(10, LOW);//
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vann, LOW);
 
  //delay(timer);
  }
void o(int vao)
{
  if (vao==2)
{
  vao=A0;
}
    //Letra n
  digitalWrite(10, HIGH);//
  digitalWrite(9, HIGH);//d
  digitalWrite(8, HIGH);//E
  
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vao, HIGH);
 
  delay(timer);
      //Letra o
  digitalWrite(10, LOW);//
  digitalWrite(9, LOW);//d
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vao, LOW);
 
  //delay(timer);
  }


void p(int vap)
{
  if (vap==2)
{
  vap=A0;
}
   //Letra P
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vap, HIGH);
  delay(timer);
  
    digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vap, LOW);
  //delay(timer);
  }

  void u(int vu)
{
  if (vu==2)
{
  vu=A0;
}
    //Letra u
  digitalWrite(10, HIGH);//
  digitalWrite(9, HIGH);//d
  digitalWrite(8, HIGH);//E
  
  //digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vu, HIGH);
 
  delay(timer);
      //Letra u
  digitalWrite(10, LOW);//
  digitalWrite(9, LOW);//d
  digitalWrite(8, LOW);//E
  //digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vu, LOW);
 
  //delay(timer);
  }

     void x(int xxx)
{
if (xxx==2)
{
  xxx=A0;
}
    //Letra 0
  //digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//
  ///PIN ACTIVA
  digitalWrite(xxx, HIGH);
  delay(timer);
      //Letra A
  //digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);// 
  ///PIN ACTIVA
  digitalWrite(xxx, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }


void y(int yy)
{
if (yy==2)
{
  yy=A0;
}
    //Letra 0
  //digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(9, HIGH);//d
  digitalWrite(6, HIGH);//G
  ///PIN ACTIVA
  digitalWrite(yy, HIGH);
  delay(timer);
      //Letra A
  //digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(9, LOW);//d 
  digitalWrite(6, LOW);//G
  ///PIN ACTIVA
  digitalWrite(yy, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

void z(int zz)
{
if (zz==2)
{
  zz=A0;
}
   //Letra E
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//
  digitalWrite(9, HIGH);//D
  digitalWrite(8, HIGH);//E
  //digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(zz, HIGH);
  delay(timer);
  
    digitalWrite(12, LOW);//A
    digitalWrite(11, LOW);//
  digitalWrite(9, LOW);//D
  digitalWrite(8, LOW);//E
  //digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(zz, LOW);
  //delay(timer);
  
  }

 
void gr(int vgr)
{
  if (vgr==2)
{
  vgr=A0;
}
   //Letra P
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//
  //digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vgr, HIGH);
  delay(timer);
  
    digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//
  //digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vgr, LOW);
  //delay(timer);
  }

//FINDisplay
// --------------------------------------------------------
// MPU6050_read
int MPU6050_read(int start, uint8_t *buffer, int size)
{
  int i, n, error;

  Wire.beginTransmission(MPU6050_I2C_ADDRESS);
  n = Wire.write(start);
  if (n != 1)
    return (-10);

  n = Wire.endTransmission(false);    // hold the I2C-bus
  if (n != 0)
    return (n);

  // Third parameter is true: relase I2C-bus after data is read.
  Wire.requestFrom(MPU6050_I2C_ADDRESS, size, true);
  i = 0;
  while(Wire.available() && i<size)
  {
    buffer[i++]=Wire.read();
  }
  if ( i != size)
    return (-11);

  return (0);  // return : no error
}


// --------------------------------------------------------
// MPU6050_write
int MPU6050_write(int start, const uint8_t *pData, int size)
{
  int n, error;

  Wire.beginTransmission(MPU6050_I2C_ADDRESS);
  n = Wire.write(start);        // write the start address
  if (n != 1)
    return (-20);

  n = Wire.write(pData, size);  // write data bytes
  if (n != size)
    return (-21);

  error = Wire.endTransmission(true); // release the I2C-bus
  if (error != 0)
    return (error);

  return (0);         // return : no error
}

// --------------------------------------------------------
// MPU6050_write_reg
int MPU6050_write_reg(int reg, uint8_t data)
{
  int error;

  error = MPU6050_write(reg, &data, 1);

  return (error);
}
