/*
 * Copyright (c) 2017 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 * Copyright (c) 2019 Nordic Semiconductor ASA
 * Copyright (c) 2020 Teslabs Engineering S.L.
 * Copyright (c) 2021 Krivorot Oleg <krivorot.oleg@gmail.com>
 * Copyright (c) 2023 Mr Beam Lasers GmbH.
 * Copyright (c) 2023 Amrith Venkat Kesavamoorthi <amrith@mr-beam.org> 
 * 
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_DRIVERS_DISPLAY_DISPLAY_GC9A01A_H_
#define ZEPHYR_DRIVERS_DISPLAY_DISPLAY_GC9A01A_H_

#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/sys/util.h>

/* Command registers*/
// #define GC9A01A_SWRESET 0x01 ///< Software reset register
// #define GC9A01A 0x04   ///< Read display identification information
#define GC9A01A 0x09   ///< Read Display Status

#define GC9A01A_SLPIN 0x10  ///< Enter Sleep Mode
#define GC9A01A_SLPOUT 0x11 ///< Sleep Out
#define GC9A01A_PTLON 0x12  ///< Partial Mode ON
#define GC9A01A_NORON 0x13  ///< Normal Display Mode ON

#define GC9A01A_INVOFF 0x20   ///< Display Inversion OFF
#define GC9A01A_INVON 0x21    ///< Display Inversion ON
#define GC9A01A_DISPOFF 0x28  ///< Display OFF
#define GC9A01A_DISPON 0x29   ///< Display ON

#define GC9A01A_CASET 0x2A ///< Column Address Set
#define GC9A01A_PASET 0x2B ///< Page Address Set
#define GC9A01A_RAMWR 0x2C ///< Memory Write

#define GC9A01A_PTLAR 0x30    ///< Partial Area
#define GC9A01A_VSCRDEF 0x33  ///< Vertical Scrolling Definition
#define GC9A01A_TEOFF 0x34    ///< Tearing effect line off
#define GC9A01A_TEON 0x35     ///< Tearing effect line on
#define GC9A01A_MADCTL 0x36   ///< Memory Access Control
#define GC9A01A_VSCRSADD 0x37 ///< Vertical Scrolling Start Address
#define GC9A01A_PIXFMT 0x3A   ///< COLMOD: Pixel Format Set

#define GC9A01A1_DFUNCTR 0xB6 ///< Display Function Control

#define GC9A01A_VREG1A 0xC3 ///< Vreg1a voltage control
#define GC9A01A_VREG1B 0xC4 ///< Vreg1b voltage control
#define GC9A01A_VREG2A 0xC9 ///< Vreg2a voltage control

#define GC9A01A_RDID1 0xDA ///< Read ID 1
#define GC9A01A_RDID2 0xDB ///< Read ID 2
#define GC9A01A_RDID3 0xDC ///< Read ID 3

#define ILI9341_GMCTRP1 0xE0 ///< Positive Gamma Correction
#define GC9A01A_GMCTRN1 0xE1 ///< Negative Gamma Correction
#define GC9A01A_FRAMERATE 0xE8 ///< Frame rate control

#define GC9A01A_INREGEN2 0xEF ///< Inter register enable 2
#define GC9A01A_GAMMA1 0xF0 ///< Set gamma 1
#define GC9A01A_GAMMA2 0xF1 ///< Set gamma 2
#define GC9A01A_GAMMA3 0xF2 ///< Set gamma 3
#define GC9A01A_GAMMA4 0xF3 ///< Set gamma 4
#define GC9A01A_INREGEN1 0xFE ///< Inter register enable 1

// Color definitions
#define GC9A01A_BLACK 0x0000       ///<   0,   0,   0
#define GC9A01A_NAVY 0x000F        ///<   0,   0, 123
#define GC9A01A_DARKGREEN 0x03E0   ///<   0, 125,   0
#define GC9A01A_DARKCYAN 0x03EF    ///<   0, 125, 123
#define GC9A01A_MAROON 0x7800      ///< 123,   0,   0
#define GC9A01A_PURPLE 0x780F      ///< 123,   0, 123
#define GC9A01A_OLIVE 0x7BE0       ///< 123, 125,   0
#define GC9A01A_LIGHTGREY 0xC618   ///< 198, 195, 198
#define GC9A01A_DARKGREY 0x7BEF    ///< 123, 125, 123
#define GC9A01A_BLUE 0x001F        ///<   0,   0, 255
#define GC9A01A_GREEN 0x07E0       ///<   0, 255,   0
#define GC9A01A_CYAN 0x07FF        ///<   0, 255, 255
#define GC9A01A_RED 0xF800         ///< 255,   0,   0
#define GC9A01A_MAGENTA 0xF81F     ///< 255,   0, 255
#define GC9A01A_YELLOW 0xFFE0      ///< 255, 255,   0
#define GC9A01A_WHITE 0xFFFF       ///< 255, 255, 255
#define GC9A01A_ORANGE 0xFD20      ///< 255, 165,   0
#define GC9A01A_GREENYELLOW 0xAFE5 ///< 173, 255,  41
#define GC9A01A_PINK 0xFC18        ///< 255, 130, 198


/* MADCTL register fields. */
#define GC9A01A_MADCTL_MY BIT(7U)
#define GC9A01A_MADCTL_MX BIT(6U)
#define GC9A01A_MADCTL_MV BIT(5U)
#define GC9A01A_MADCTL_ML BIT(4U)
#define GC9A01A_MADCTL_BGR BIT(3U)
#define GC9A01A_MADCTL_MH BIT(2U)

/* PIXSET register fields. */
#define GC9A01A_PIXSET_RGB_18_BIT 0x60
#define GC9A01A_PIXSET_RGB_16_BIT 0x50
#define GC9A01A_PIXSET_MCU_18_BIT 0x06
#define GC9A01A_PIXSET_MCU_16_BIT 0x05

/** X resolution (pixels). */
#define GC9A01A_X_RES 240U
/** Y resolution (pixels). */
#define GC9A01A_Y_RES 240U

/* pg 103 section 6.4.2 of datasheet */
#define GC9A01A_SLEEP_OUT_TIME 120

/** Command/data GPIO level for commands. */
#define GC9A01A_CMD 0U
/** Command/data GPIO level for data. */
#define GC9A01A_DATA 1U

struct gc9a01a_config {
    struct spi_dt_spec spi;
    struct gpio_dt_spec cmd_data;
    struct gpio_dt_spec reset;
    struct pwm_dt_spec backlight;
    uint8_t pixel_format;
	  uint16_t rotation;
	  uint16_t x_resolution;
	  uint16_t y_resolution;
	  bool inversion;
    const void *regs;
    int (*regs_init_fn)(const struct device *dev);
};

/* GC9A01A registers to be intitialized*/
struct gc9a01a_regs {
  uint8_t regeb[1];
  uint8_t reg84[1];
  uint8_t reg85[1];
  uint8_t reg86[1];
  uint8_t reg87[1];
  uint8_t reg88[1];
  uint8_t reg89[1];
  uint8_t reg8a[1];
  uint8_t reg8b[1];
  uint8_t reg8c[1];
  uint8_t reg8d[1];
  uint8_t reg8e[1];
  uint8_t reg8f[1];
  uint8_t regb6[2];
  uint8_t reg90[4];
  uint8_t regbd[1];
  uint8_t regbc[1];
  uint8_t regff[3];
  uint8_t regvreg1a[1];
  uint8_t regvreg1b[1];
  uint8_t regvreg2a[1];
  uint8_t regbe[1];
  uint8_t reggmctrn1[2];
  uint8_t regdf[3];
  uint8_t reggamma1[6];
  uint8_t reggamma2[6];
  uint8_t reggamma3[6];
  uint8_t reggamma4[6];
  uint8_t reged[2];
  uint8_t regae[1];
  uint8_t regcd[1];
  uint8_t reg70[9];
  uint8_t regframerate[1];
  uint8_t reg62[12];
  uint8_t reg63[12];
  uint8_t reg64[7];
  uint8_t reg66[10];
  uint8_t reg67[10];
  uint8_t reg74[7];
  uint8_t reg98[2];
};


#define GC9A01A_REGS_INIT(n) \
  static const struct gc9a01a_regs gc9a01a_regs_##n = { \
  .regeb=DT_PROP(DT_INST(n,waveshare_gc9a01a),regeb),\
  .reg84=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg84),\
  .reg85=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg85),\
  .reg86=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg86),\
  .reg87=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg87),\
  .reg88=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg88),\
  .reg89=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg89),\
  .reg8a=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg8a),\
  .reg8b=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg8b),\
  .reg8c=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg8c),\
  .reg8d=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg8d),\
  .reg8e=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg8e),\
  .reg8f=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg8f),\
  .regb6=DT_PROP(DT_INST(n,waveshare_gc9a01a),regb6),\
  .reg90=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg90),\
  .regbd=DT_PROP(DT_INST(n,waveshare_gc9a01a),regbd),\
  .regbc=DT_PROP(DT_INST(n,waveshare_gc9a01a),regbc),\
  .regff=DT_PROP(DT_INST(n,waveshare_gc9a01a),regff),\
  .regvreg1a=DT_PROP(DT_INST(n,waveshare_gc9a01a),regvreg1a),\
  .regvreg1b=DT_PROP(DT_INST(n,waveshare_gc9a01a),regvreg1b),\
  .regvreg2a=DT_PROP(DT_INST(n,waveshare_gc9a01a),regvreg2a),\
  .regbe=DT_PROP(DT_INST(n,waveshare_gc9a01a),regbe),\
  .reggmctrn1=DT_PROP(DT_INST(n,waveshare_gc9a01a),reggmctrn1),\
  .regdf=DT_PROP(DT_INST(n,waveshare_gc9a01a),regdf),\
  .reggamma1=DT_PROP(DT_INST(n,waveshare_gc9a01a),reggamma1),\
  .reggamma2=DT_PROP(DT_INST(n,waveshare_gc9a01a),reggamma2),\
  .reggamma3=DT_PROP(DT_INST(n,waveshare_gc9a01a),reggamma3),\
  .reggamma4=DT_PROP(DT_INST(n,waveshare_gc9a01a),reggamma4),\
  .reged=DT_PROP(DT_INST(n,waveshare_gc9a01a),reged),\
  .regae=DT_PROP(DT_INST(n,waveshare_gc9a01a),regae),\
  .regcd=DT_PROP(DT_INST(n,waveshare_gc9a01a),regcd),\
  .regframerate=DT_PROP(DT_INST(n,waveshare_gc9a01a),regframerate),\
  .reg70=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg70),\
  .reg62=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg62),\
  .reg63=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg63),\
  .reg64=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg64),\
  .reg66=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg66),\
  .reg67=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg67),\
  .reg74=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg74),\
  .reg98=DT_PROP(DT_INST(n,waveshare_gc9a01a),reg98),\
  }
  
/**
 * @brief Initialize GC9A01A registers with DT values.
 *
 * @param dev GC9A01A device instance
 * @return 0 on success, errno otherwise.
 */
int gc9a01a_regs_init(const struct device *dev);


int gc9a01a_transmit(const struct device *dev, uint8_t cmd,
		     const void *tx_data, size_t tx_len);

#endif /* ZEPHYR_DRIVERS_DISPLAY_DISPLAY_GC9A01A_H_ */
