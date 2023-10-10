/*
 * leds-s2mu205.h - Flash-led driver for Samsung S2MU205
 *
 * Copyright (C) 2019 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */
#ifndef __LEDS_S2MU205_H__
#define __LEDS_S2MU205_H__

#ifdef CONFIG_MUIC_NOTIFIER
#include <linux/muic/muic.h>
#include <linux/muic/muic_notifier.h>
#endif /* CONFIG_MUIC_NOTIFIER */

#define MASK(width, shift)		(((0x1 << (width)) - 1) << shift)
#define S2MU205_FLASH_LIGHT_MAX 5

/* Interrupt register */
#define S2MU205_FLED_INT1		0x04
#define S2MU205_FLED_INT2		0x05

#define S2MU205_FLED_INT1_MASK		0x0C
#define S2MU205_FLED_INT2_MASK		0x0D

/* Status register */
#define S2MU205_FLED_STATUS		0x3F

/* Mask for status register */
#define S2MU205_CH1_FLASH_ON		MASK(1,7)
#define S2MU205_CH1_TORCH_ON		MASK(1,6)

#define S2MU205_CH2_FLASH_ON		MASK(1,5)
#define S2MU205_CH2_TORCH_ON		MASK(1,4)

#define S2MU205_DHC_DET_ON		MASK(1,3)

/* Channel control */
#define S2MU205_FLED_CH1_CTRL0		0x40
#define S2MU205_FLED_CH1_CTRL1		0x41
#define S2MU205_FLED_CH1_CTRL2		0x42
#define S2MU205_FLED_CH1_CTRL3		0x43

#define S2MU205_FLED_CH2_CTRL0		0x44
#define S2MU205_FLED_CH2_CTRL1		0x45
#define S2MU205_FLED_CH2_CTRL2		0x46
#define S2MU205_FLED_CH2_CTRL3		0x47

/* Mask for channel control register */
#define S2MU205_CHX_OPEN_PROT_EN	MASK(1,7)
#define S2MU205_CHX_SHORT_PROT_EN	MASK(1,6)
#define S2MU205_CHX_FLASH_IOUT		MASK(5,0)
#define S2MU205_CHX_TORCH_IOUT		MASK(5,0)
#define S2MU205_CHX_FLASH_TMR_MODE	MASK(1,7)
#define S2MU205_CHX_TORCH_TMR_MODE	MASK(1,7)
#define S2MU205_CHX_FLASH_TMR_DUR	MASK(4,0)
#define S2MU205_CHX_TORCH_TMR_DUR	MASK(4,0)
#define S2MU205_CHX_DIS_TORCH_TMR	MASK(1,6)

/* Mode control */
#define S2MU205_FLED_CTRL0		0x48
#define S2MU205_FLED_CTRL1		0x49
#define S2MU205_FLED_CTRL2		0x4A
#define S2MU205_FLED_CTRL3		0x4B

#define S2MU205_FLED_TEST0		0x4C
#define S2MU205_FLED_TEST1		0x4D
#define S2MU205_FLED_TEST2		0x4E

/* Mask for channel control register */
#define S2MU205_FLED_CTRL0_MASK		MASK(8,0)
#define S2MU205_CH1_FLASH_FLED_EN	MASK(2,6)
#define S2MU205_CH1_TORCH_FLED_EN	MASK(2,4)

#define S2MU205_CH2_FLASH_FLED_EN	MASK(2,2)
#define S2MU205_CH2_TORCH_FLED_EN	MASK(2,0)

/* Mask for Mode control register */
#define S2MU205_TORCH_OFF		0x00
#define S2MU205_FLASH_OFF		0x00

#define S2MU205_CH1_TORCH_ON_I2C	MASK(2,4)
#define S2MU205_CH2_TORCH_ON_I2C	MASK(2,0)
#define S2MU205_CH1_TORCH_ON_GPIO	MASK(1,5)
#define S2MU205_CH2_TORCH_ON_GPIO	MASK(1,1)

#define S2MU205_CH1_FLASH_ON_I2C	MASK(2,6)
#define S2MU205_CH2_FLASH_ON_I2C	MASK(2,2)
#define S2MU205_CH1_FLASH_ON_GPIO	MASK(1,6)
#define S2MU205_CH2_FLASH_ON_GPIO	MASK(1,2)

#define S2MU205_CHGIN_ENGH		MASK(1,7)
#define S2MU205_FLED_BOOST_EN		MASK(1,6)
#define S2MU205_FLED_REG_RESET		MASK(1,5)
#define S2MU205_FLED_SOFT_ON_TIME	MASK(2,3)
#define S2MU205_ADAPTIVE_MODE_EN	MASK(1,2)
#define S2MU205_EN_CHANNEL_SHARE	MASK(1,1)
#define S2MU205_BOOST_VOUT_FLASH	MASK(6,0)
#define S2MU205_ADAP_BOOST_VOUT_FLASH	MASK(6,0)

/* Factory mode variable */
#define S2MU205_FACTORY			1
#define S2MU205_NORMAL			0

/* LED control variable */
#define S2MU205_LED_NUM			2
#define LED_TURN_OFF 			-1
#define S2MU205_FLED_DEBUG

enum s2mu205_led_id {
	S2MU205_OFF,
	S2MU205_FLASH_LED = 0,
	S2MU205_TORCH_LED,
	S2MU205_LED_MAX,
};

enum s2mu205_flash_current {
	S2MU205_FLASH_OUT_I_25MA,
	S2MU205_FLASH_OUT_I_50MA,
	S2MU205_FLASH_OUT_I_75MA,
	S2MU205_FLASH_OUT_I_100MA,
	S2MU205_FLASH_OUT_I_125MA,
	S2MU205_FLASH_OUT_I_150MA,
	S2MU205_FLASH_OUT_I_175MA,
	S2MU205_FLASH_OUT_I_200MA,
	S2MU205_FLASH_OUT_I_225MA,
	S2MU205_FLASH_OUT_I_250MA,
	S2MU205_FLASH_OUT_I_275MA,
	S2MU205_FLASH_OUT_I_300MA,
	S2MU205_FLASH_OUT_I_325MA,
	S2MU205_FLASH_OUT_I_350MA,
	S2MU205_FLASH_OUT_I_375MA,
	S2MU205_FLASH_OUT_I_400MA,
	S2MU205_FLASH_OUT_I_450MA,
	S2MU205_FLASH_OUT_I_500MA,
	S2MU205_FLASH_OUT_I_550MA,
	S2MU205_FLASH_OUT_I_600MA,
	S2MU205_FLASH_OUT_I_650MA,
	S2MU205_FLASH_OUT_I_700MA,
	S2MU205_FLASH_OUT_I_755MA,
	S2MU205_FLASH_OUT_I_800MA,
	S2MU205_FLASH_OUT_I_850MA,
	S2MU205_FLASH_OUT_I_900MA,
	S2MU205_FLASH_OUT_I_950MA,
	S2MU205_FLASH_OUT_I_1000MA,
	S2MU205_FLASH_OUT_I_1050MA,
	S2MU205_FLASH_OUT_I_1100MA,
	S2MU205_FLASH_OUT_I_1150MA,
	S2MU205_FLASH_OUT_I_1200MA,
};

enum s2mu205_torch_current {
	S2MU205_TORCH_OUT_I_10MA,
	S2MU205_TORCH_OUT_I_20MA,
	S2MU205_TORCH_OUT_I_30MA,
	S2MU205_TORCH_OUT_I_40MA,
	S2MU205_TORCH_OUT_I_50MA,
	S2MU205_TORCH_OUT_I_60MA,
	S2MU205_TORCH_OUT_I_70MA,
	S2MU205_TORCH_OUT_I_80MA,
	S2MU205_TORCH_OUT_I_90MA,
	S2MU205_TORCH_OUT_I_100MA,
	S2MU205_TORCH_OUT_I_110MA,
	S2MU205_TORCH_OUT_I_120MA,
	S2MU205_TORCH_OUT_I_130MA,
	S2MU205_TORCH_OUT_I_140MA,
	S2MU205_TORCH_OUT_I_150MA,
	S2MU205_TORCH_OUT_I_160MA,
	S2MU205_TORCH_OUT_I_170MA,
	S2MU205_TORCH_OUT_I_180MA,
	S2MU205_TORCH_OUT_I_190MA,
	S2MU205_TORCH_OUT_I_200MA,
	S2MU205_TORCH_OUT_I_210MA,
	S2MU205_TORCH_OUT_I_220MA,
	S2MU205_TORCH_OUT_I_230MA,
	S2MU205_TORCH_OUT_I_240MA,
	S2MU205_TORCH_OUT_I_250MA,
	S2MU205_TORCH_OUT_I_260MA,
	S2MU205_TORCH_OUT_I_270MA,
	S2MU205_TORCH_OUT_I_280MA,
	S2MU205_TORCH_OUT_I_290MA,
	S2MU205_TORCH_OUT_I_300MA,
	S2MU205_TORCH_OUT_I_310MA,
	S2MU205_TORCH_OUT_I_320MA,
};

enum s2mu205_flash_timeout {
	S2MU205_FLASH_TIMEOUT_62MS,
	S2MU205_FLASH_TIMEOUT_124MS,
	S2MU205_FLASH_TIMEOUT_186MS,
	S2MU205_FLASH_TIMEOUT_248MS,
	S2MU205_FLASH_TIMEOUT_310MS,
	S2MU205_FLASH_TIMEOUT_372MS,
	S2MU205_FLASH_TIMEOUT_434MS,
	S2MU205_FLASH_TIMEOUT_496MS,
	S2MU205_FLASH_TIMEOUT_558MS,
	S2MU205_FLASH_TIMEOUT_620MS,
	S2MU205_FLASH_TIMEOUT_682MS,
	S2MU205_FLASH_TIMEOUT_744MS,
	S2MU205_FLASH_TIMEOUT_806MS,
	S2MU205_FLASH_TIMEOUT_868MS,
	S2MU205_FLASH_TIMEOUT_930MS,
	S2MU205_FLASH_TIMEOUT_992MS,
};


enum s2mu205_torch_timeout {
	S2MU205_TORCH_TIMEOUT_262MS,
	S2MU205_TORCH_TIMEOUT_524MS,
	S2MU205_TORCH_TIMEOUT_768MS,
	S2MU205_TORCH_TIMEOUT_1048MS,
	S2MU205_TORCH_TIMEOUT_1572MS,
	S2MU205_TORCH_TIMEOUT_2096MS,
	S2MU205_TORCH_TIMEOUT_2620MS,
	S2MU205_TORCH_TIMEOUT_3144MS,
	S2MU205_TORCH_TIMEOUT_4192MS,
	S2MU205_TORCH_TIMEOUT_5242MS,
	S2MU205_TORCH_TIMEOUT_6291MS,
	S2MU205_TORCH_TIMEOUT_7340MS,
	S2MU205_TORCH_TIMEOUT_9437MS,
	S2MU205_TORCH_TIMEOUT_11534MS,
	S2MU205_TORCH_TIMEOUT_13631MS,
	S2MU205_TORCH_TIMEOUT_15728MS,
};

/* FLED operating mode enable */
enum operating_mode {
	AUTO_MODE = 0,
	BOOST_MODE,
	TA_MODE,
	SYS_MODE,
};

enum s2mu205_fled_mode {
	S2MU205_FLED_MODE_OFF = 0,
	S2MU205_FLED_MODE_PREFLASH,
	S2MU205_FLED_MODE_FLASH,
	S2MU205_FLED_MODE_MOVIE,
};

enum s2mu205_fled_select {
	S2MU205_FLED_OFF = 0,
	S2MU205_FLED_CH1,	/* FLED1 */
	S2MU205_FLED_CH2,	/* FLED2 */
};

struct s2mu205_led {
	const char *name;
	u32 id;
	int brightness;
	int timeout;
	int max_brightness;
};

struct s2mu205_fled_platform_data {
	int num_leds;
	struct s2mu205_led leds[S2MU205_LED_MAX];
	int torch_pin;
	int flash_pin;
	unsigned int flash_brightness;
	unsigned int preflash_brightness;
	unsigned int movie_brightness;
	unsigned int torch_brightness;
	unsigned int factory_brightness;
	unsigned int flashlight_brightness[S2MU205_FLASH_LIGHT_MAX];
};

void s2mu205_led_dump_reg(void);
int s2mu205_led_mode_ctrl(int mode);
extern void s2mu205_set_operation_mode(int value);
#endif