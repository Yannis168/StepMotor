#ifndef __TMC5031_H
	#define __TMC5031_H

	#define		SPI_CS1					PCout(4)
	
	#define		GONF_Add				0x00
	#define		Motor1_RampMode_Add		0x20
	#define		Motor2_RampMode_Add		0x40
	#define		Motor1_XACTUAL_Add		0x21
	#define		Motor2_XACTUAL_Add		0x41	
	#define		Motor1_Speed_Add		0x22  //read
	#define		Motor2_Speed_Add		0x42  //read
	
	#define		Motor1_VSTART_Add		0x23
	#define		Motor2_VSTART_Add		0x43
	
	#define		Motor1_V1_Add			0x25
	#define		Motor2_V1_Add			0x45
	
	#define		Motor1_A1_Add			0x24
	#define		Motor2_A1_Add			0x44	
	
	#define		Motor1_AMAX_Add			0x26
	#define		Motor2_AMAX_Add			0x46
	
	#define		Motor1_VMAX_Add			0x27
	#define		Motor2_VMAX_Add			0x47	
	
	#define		Motor1_DMAX_Add			0x28
	#define		Motor2_DMAX_Add			0x48
	
	#define		Motor1_D1_Add			0x2a
	#define		Motor2_D1_Add			0x4a
	
	#define		Motor1_VSTOP_Add		0x2b
	#define		Motor2_VSTOP_Add		0x4b
	
	#define		Motor1_TZEROWAIT_Add	0x2c
	#define		Motor2_TZEROWAIT_Add	0x4c	
	
	#define		Motor1_XTARGET_Add		0x2d
	#define		Motor2_XTARGET_Add		0x4d	
	
	#define		Motor1_IHOLD_IRUN_Add	0x30	
	#define		Motor2_IHOLD_IRUN_Add	0x50
	
	#define		Motor1_Vcoolthrs_Add	0x31
	#define		Motor2_Vcoolthrs_Add	0x51
	
	#define     Motor1_PWMCONF_Add		0x10
	#define		Motor2_PWMCONF_Add		0x18
	
	#define 	Motor1_SW_MODE_Add		0x34
	#define 	Motor2_SW_MODE_Add		0x54
	
	#define 	Motor1_RAMP_STAT_Add	0x35
	#define 	Motor2_RAMP_STAT_Add	0x55	
	
	#define 	Motor1_VHIGH_Add		0x32
	#define		Motor2_VHIGH_Add		0x52
		
	enum RAMPMODE
	{
		Position=0,
		Velocity_Positive,
		Velocity_Negative,
		Hold,	
	};
	union GCONF
	{
		unsigned int DWord;
		struct
		{
			unsigned char	Reserved   	:3
			unsigned char	INT_PP		:1
			unsigned char	Reserved1	:3
			unsigned char	TestMode	:1
			unsigned char	Motor1_Dir	:1
			unsigned char	Motor2_Dir	:1
			unsigned char	Lock_Gconf	:1	
		}Bits;
	};
	
	union	IHOLD_IRUN	
	{
		unsigned int	DWord;
		struct
		{
			unsigned char	IHOLD 		:5
			unsigned char	Reserved	:3
			unsigned char	IRUN		:5
			unsigned char	Reserved1	:3	
			unsigned char 	IHOLD_DELAY	:4 
		}Bits;
	};

	union	SW_MODE
	{
		unsigned int  DWord
		struct
		{	
			unsigned char	Stop_L_Enable	 :1  //使能开关
			unsigned char	Stop_R_Enable	 :1  //使能开关
			unsigned char	Pol_Stop_L		 :1
			unsigned char	Pol_Stop_R		 :1
			unsigned char	Swap_LR			 :1
			unsigned char	Latch_L_Active	 :1
			unsigned char	Latch_L_Inactive :1
			unsigned char	Latch_R_Active	 :1
			unsigned char	Latch_R_Inactive :1	
			unsigned char	Reverse			 :1
			unsigned char	Sg_Stop			 :1			
			unsigned char	En_SoftStop		 :1
		}Bits;		
	};
	
	union	RAMP_STAT
	{
		unsigned int DWord;
		struct
		{
			unsigned char	Status_Stop_L		:1	
			unsigned char	Status_Stop_R		:1
			unsigned char	Status_Latch_L		:1
			unsigned char	Status_Latch_R		:1	
			unsigned char	Event_Stop_L		:1	
			unsigned char	Event_Stop_R		:1		
			unsigned char	Event_Stop_ sg		:1
			unsigned char	Event_Pos_Reached	:1
			unsigned char	Velocity_Reached	:1
			unsigned char	Position_Reached	:1	
			unsigned char	Vzero				:1	
			unsigned char	T_Zerowait_Active	:1
			unsigned char	Second_move			:1		
			unsigned char	Status_sg			:1
		}Bits;
	};
		
	union	GCONF		Gconf;
	union	SW_MODE		Sw_Mode;
	union	RAMP_STAT	Ramp_Stat;
	union	IHOLD_IRUN	Ihold_Irun
	
    void WriteTMC562Datagram(unsigned char  Address, unsigned char  x1, unsigned char  x2, unsigned char  x3, unsigned char  x4);
    unsigned char  ReadWriteSPI(unsigned char Data);
	int ReadTMC5031Datagram(unsigned char  Address);
	void WriteTMC5031(unsigned char  Address,  int regData);
	int ReadTmc5031(unsigned addr);
#endif


