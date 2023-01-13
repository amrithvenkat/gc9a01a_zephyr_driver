/*
 * Copyright (c) 2017 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 * Copyright (c) 2019 Nordic Semiconductor ASA
 * Copyright (c) 2020 Teslabs Engineering S.L.
 * Copyright (c) 2021 Krivorot Oleg <krivorot.oleg@gmail.com>
 * Copyright (c) 2023 Mr Beam Lasers GmbH.
 * Copyright (c) 2023 Amrith Venkat Kesavamoorthi <amrith@mr-beam.org> 
 * SPDX-License-Identifier: Apache-2.0
 */

#include "display_gc9a01a.h"

#include <zephyr/dt-bindings/display/gc9a01a.h>
#include <zephyr/drivers/display.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(display_gc9a01a, CONFIG_DISPLAY_LOG_LEVEL);

struct gc9a01a_data {
	uint8_t bytes_per_pixel;
	enum display_pixel_format pixel_format;
	enum display_orientation orientation;
};


int gc9a01a_regs_init(const struct device *dev)
{
	
    const struct gc9a01a_config *config = dev->config;
	const struct gc9a01a_regs *regs = config->regs;

    int r;
	r = gc9a01a_transmit(dev, GC9A01A_INREGEN1, NULL,0);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, GC9A01A_INREGEN2, NULL,0);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0xeb, regs->regeb,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x84, regs->reg84,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x85, regs->reg85,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x86, regs->reg86,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x87, regs->reg87,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x88, regs->reg88,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x89, regs->reg89,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x8a, regs->reg8a,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x8b, regs->reg8b,1);
	if (r < 0) {
		return r;
	}
		r = gc9a01a_transmit(dev, 0x8c, regs->reg8c,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x8d, regs->reg8d,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x8e, regs->reg8e,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x8f, regs->reg8f,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0xb6, regs->regb6,2);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0x90, regs->reg90,4);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0xbd, regs->regbd,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0xbc, regs->regbc,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev, 0xff, regs->regff,3);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_VREG1A, regs->regvreg1a,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_VREG1B, regs->regvreg1b,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_VREG2A, regs->regvreg2a,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0xbe, regs->regbe,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_GMCTRN1, regs->reggmctrn1,2);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0xdf, regs->regdf,3);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_GAMMA1, regs->reggamma1,6);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_GAMMA2, regs->reggamma2,6);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_GAMMA3, regs->reggamma3,6);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_GAMMA4, regs->reggamma4,6);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0xed, regs->reged,2);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0xae, regs->regae,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0xcd, regs->regcd,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0x70, regs->reg70,9);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_FRAMERATE, regs->regframerate,1);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0x62, regs->reg62,12);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0x63, regs->reg63,12);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0x64, regs->reg64,7);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0x66, regs->reg66,10);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0x67, regs->reg67,10);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0x74, regs->reg74,7);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,0x98, regs->reg98,2);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_TEON, NULL,0);
	if (r < 0) {
		return r;
	}
	r = gc9a01a_transmit(dev,GC9A01A_SLPOUT, NULL,0);
	if (r < 0) {
		return r;
	}
	k_sleep(K_MSEC(GC9A01A_SLEEP_OUT_TIME));

	r = gc9a01a_transmit(dev,GC9A01A_DISPON, NULL,0);
	if (r < 0) {
		return r;
	}
	k_sleep(K_MSEC(20));

    return 0;
}


int gc9a01a_transmit(const struct device *dev, uint8_t cmd, const void *tx_data,
		     size_t tx_len)
{
	const struct gc9a01a_config *config = dev->config;

	int r;
	struct spi_buf tx_buf;
	struct spi_buf_set tx_bufs = { .buffers = &tx_buf, .count = 1U };

	/* send command */
	tx_buf.buf = &cmd;
	tx_buf.len = 1U;

	gpio_pin_set_dt(&config->cmd_data, GC9A01A_CMD);
	r = spi_write_dt(&config->spi, &tx_bufs);
	if (r < 0) {
		return r;
	}

	/* send data (if any) */
	if (tx_data != NULL) {
		tx_buf.buf = (void *)tx_data;
		tx_buf.len = tx_len;

		gpio_pin_set_dt(&config->cmd_data, GC9A01A_DATA);
		r = spi_write_dt(&config->spi, &tx_bufs);
		if (r < 0) {
			return r;
		}
	}

	return 0;
}

static int gc9a01a_exit_sleep(const struct device *dev)
{
	int r;

	r = gc9a01a_transmit(dev, GC9A01A_SLPOUT, NULL, 0);
	if (r < 0) {
		return r;
	}

	k_sleep(K_MSEC(GC9A01A_SLEEP_OUT_TIME));

	return 0;
}


static void gc9a01a_hw_reset(const struct device *dev)
{
	const struct gc9a01a_config *config = dev->config;

	if (config->reset.port == NULL) {
		return;
	}

	gpio_pin_set_dt(&config->reset, 1);
	k_sleep(K_MSEC(100));
	gpio_pin_set_dt(&config->reset, 0);
	k_sleep(K_MSEC(100));
	gpio_pin_set_dt(&config->reset, 1);
	k_sleep(K_MSEC(100));

}

static int gc9a01a_display_blanking_off(const struct device *dev)
{
	LOG_DBG("Turning display blanking off");
	return gc9a01a_transmit(dev, GC9A01A_DISPON, NULL, 0);
}

static int gc9a01a_display_blanking_on(const struct device *dev)
{
	LOG_DBG("Turning display blanking on");
	return gc9a01a_transmit(dev, GC9A01A_DISPOFF, NULL, 0);
}


static int gc9a01a_set_pixel_format(const struct device *dev,
			 const enum display_pixel_format pixel_format)
{
	struct gc9a01a_data *data = dev->data;

	int r;
	uint8_t tx_data;
	uint8_t bytes_per_pixel;

	if (pixel_format == PIXEL_FORMAT_RGB_565) {
		bytes_per_pixel = 2U;
		tx_data = GC9A01A_PIXSET_MCU_16_BIT | GC9A01A_PIXSET_RGB_16_BIT;
	} else if (pixel_format == PIXEL_FORMAT_RGB_888) {
		bytes_per_pixel = 3U;
		tx_data = GC9A01A_PIXSET_MCU_18_BIT | GC9A01A_PIXSET_RGB_18_BIT;
	} else {
		LOG_ERR("Unsupported pixel format");
		return -ENOTSUP;
	}

	r = gc9a01a_transmit(dev, GC9A01A_PIXFMT, &tx_data, 1U);
	if (r < 0) {
		return r;
	}

	data->pixel_format = pixel_format;
	data->bytes_per_pixel = bytes_per_pixel;

	return 0;
}

static int gc9a01a_set_orientation(const struct device *dev,
				   const enum display_orientation orientation)
{
	struct gc9a01a_data *data = dev->data;

	int r;
	uint8_t tx_data = GC9A01A_MADCTL_BGR;

	if (orientation == DISPLAY_ORIENTATION_NORMAL) { // workss
		tx_data |= 0;
	} else if (orientation == DISPLAY_ORIENTATION_ROTATED_90) { // works CW 90
		tx_data |= GC9A01A_MADCTL_MV | GC9A01A_MADCTL_MY ;
	} else if (orientation == DISPLAY_ORIENTATION_ROTATED_180) { // works CW 180
		tx_data |= GC9A01A_MADCTL_MY | GC9A01A_MADCTL_MX | GC9A01A_MADCTL_MH;
	} else if (orientation == DISPLAY_ORIENTATION_ROTATED_270) { // works CW 270
		tx_data |= GC9A01A_MADCTL_MV | GC9A01A_MADCTL_MX ;
	}

	r = gc9a01a_transmit(dev, GC9A01A_MADCTL, &tx_data, 1U);
	if (r < 0) {
		return r;
	}

	data->orientation = orientation;

	return 0;
}


static int gc9a01a_configure(const struct device *dev)
{
	const struct gc9a01a_config *config = dev->config;

	int r;
	enum display_pixel_format pixel_format;
	enum display_orientation orientation;

	/* pixel format */
	if (config->pixel_format == GC9A01A_PIXEL_FORMAT_RGB565) {
		pixel_format = PIXEL_FORMAT_RGB_565;
	} else {
		pixel_format = PIXEL_FORMAT_RGB_888;
	}

	r = gc9a01a_set_pixel_format(dev, pixel_format);
	if (r < 0) {
		return r;
	}

	/* orientation */
	if (config->rotation == 0U) {
		orientation = DISPLAY_ORIENTATION_NORMAL;
	} else if (config->rotation == 90U) {
		orientation = DISPLAY_ORIENTATION_ROTATED_90;
	} else if (config->rotation == 180U) {
		orientation = DISPLAY_ORIENTATION_ROTATED_180;
	} else {
		orientation = DISPLAY_ORIENTATION_ROTATED_270;
	}

	r = gc9a01a_set_orientation(dev, orientation);
	if (r < 0) {
		return r;
	}

	if (config->inversion) {
		r = gc9a01a_transmit(dev, GC9A01A_INVON, NULL, 0U);
		if (r < 0) {
			return r;
		}
	}

	r = config->regs_init_fn(dev);
	if (r < 0) {
		return r;
	}

	return 0;
}

static int gc9a01a_set_brightness(const struct device *dev,
				  const uint8_t brightness)
{
	const struct gc9a01a_config *config = dev->config;
	uint32_t step=config->backlight.period/100;
	int ret = pwm_set_pulse_dt(&config->backlight,brightness*step);

	if(ret){
		LOG_ERR("Failed to set pulse width");
		return ret;
	}
	return 0;

}


static int gc9a01a_init(const struct device *dev)
{
	const struct gc9a01a_config *config = dev->config;

	int r;

	if (!spi_is_ready_dt(&config->spi)) {
		LOG_ERR("SPI device is not ready");
		return -ENODEV;
	}

	if (!device_is_ready(config->cmd_data.port)) {
		LOG_ERR("Command/Data GPIO device not ready");
		return -ENODEV;
	}

	r = gpio_pin_configure_dt(&config->cmd_data, GPIO_OUTPUT);
	if (r < 0) {
		LOG_ERR("Could not configure command/data GPIO (%d)", r);
		return r;
	}

	if (config->reset.port != NULL) {
		if (!device_is_ready(config->reset.port)) {
			LOG_ERR("Reset GPIO device not ready");
			return -ENODEV;
		}

		r = gpio_pin_configure_dt(&config->reset, GPIO_OUTPUT_INACTIVE);
		if (r < 0) {
			LOG_ERR("Could not configure reset GPIO (%d)", r);
			return r;
		}
	}

	gc9a01a_hw_reset(dev);

	k_sleep(K_MSEC(5));

	gc9a01a_display_blanking_on(dev);

	r = gc9a01a_configure(dev);
	if (r < 0) {
		LOG_ERR("Could not configure display (%d)", r);
		return r;
	}

	r = gc9a01a_exit_sleep(dev);
	if (r < 0) {
		LOG_ERR("Could not exit sleep mode (%d)", r);
		return r;
	}

	r=gc9a01a_set_brightness(dev,50);
	if (r < 0) {
		LOG_ERR("Could not set brightness (%d)", r);
		return r;
	}

	return 0;
}

static int gc9a01a_set_mem_area(const struct device *dev, const uint16_t x,
				const uint16_t y, const uint16_t w,
				const uint16_t h)
{
	int r;
	uint16_t spi_data[2];

	spi_data[0] = sys_cpu_to_be16(x);
	spi_data[1] = sys_cpu_to_be16(x + w - 1U);
	r = gc9a01a_transmit(dev, GC9A01A_CASET, &spi_data[0], 4U);
	if (r < 0) {
		return r;
	}

	spi_data[0] = sys_cpu_to_be16(y);
	spi_data[1] = sys_cpu_to_be16(y + h - 1U);
	r = gc9a01a_transmit(dev, GC9A01A_PASET, &spi_data[0], 4U);
	if (r < 0) {
		return r;
	}

	return 0;
}

static int gc9a01a_write(const struct device *dev, const uint16_t x,
			 const uint16_t y,
			 const struct display_buffer_descriptor *desc,
			 const void *buf)
{
	const struct gc9a01a_config *config = dev->config;
	struct gc9a01a_data *data = dev->data;

	int r;
	const uint8_t *write_data_start = (const uint8_t *)buf;
	struct spi_buf tx_buf;
	struct spi_buf_set tx_bufs;
	uint16_t write_cnt;
	uint16_t nbr_of_writes;
	uint16_t write_h;

	__ASSERT(desc->width <= desc->pitch, "Pitch is smaller than width");
	__ASSERT((desc->pitch * data->bytes_per_pixel * desc->height) <=
			 desc->buf_size,
		 "Input buffer to small");

	LOG_DBG("Writing %dx%d (w,h) @ %dx%d (x,y)", desc->width, desc->height,
		x, y);
	r = gc9a01a_set_mem_area(dev, x, y, desc->width, desc->height);
	if (r < 0) {
		return r;
	}

	if (desc->pitch > desc->width) {
		write_h = 1U;
		nbr_of_writes = desc->height;
	} else {
		write_h = desc->height;
		nbr_of_writes = 1U;
	}

	r = gc9a01a_transmit(dev, GC9A01A_RAMWR, write_data_start,
			     desc->width * data->bytes_per_pixel * write_h);
	if (r < 0) {
		return r;
	}

	tx_bufs.buffers = &tx_buf;
	tx_bufs.count = 1;

	write_data_start += desc->pitch * data->bytes_per_pixel;
	for (write_cnt = 1U; write_cnt < nbr_of_writes; ++write_cnt) {
		tx_buf.buf = (void *)write_data_start;
		tx_buf.len = desc->width * data->bytes_per_pixel * write_h;

		r = spi_write_dt(&config->spi, &tx_bufs);
		if (r < 0) {
			return r;
		}

		write_data_start += desc->pitch * data->bytes_per_pixel;
	}

	return 0;
}

static int gc9a01a_read(const struct device *dev, const uint16_t x,
			const uint16_t y,
			const struct display_buffer_descriptor *desc, void *buf)
{
	LOG_ERR("Reading not supported");
	return -ENOTSUP;
}

static void *gc9a01a_get_framebuffer(const struct device *dev)
{
	LOG_ERR("Direct framebuffer access not supported");
	return NULL;
}


static int gc9a01a_set_contrast(const struct device *dev,
				const uint8_t contrast)
{
	LOG_ERR("Set contrast not supported");
	return -ENOTSUP;
}

static void gc9a01a_get_capabilities(const struct device *dev,
				     struct display_capabilities *capabilities)
{
	struct gc9a01a_data *data = dev->data;
	const struct gc9a01a_config *config = dev->config;

	memset(capabilities, 0, sizeof(struct display_capabilities));

	capabilities->supported_pixel_formats =
		PIXEL_FORMAT_RGB_565 | PIXEL_FORMAT_RGB_888;
	capabilities->current_pixel_format = data->pixel_format;

	if (data->orientation == DISPLAY_ORIENTATION_NORMAL ||
	    data->orientation == DISPLAY_ORIENTATION_ROTATED_180) {
		capabilities->x_resolution = config->x_resolution;
		capabilities->y_resolution = config->y_resolution;
	} else {
		capabilities->x_resolution = config->y_resolution;
		capabilities->y_resolution = config->x_resolution;
	}

	capabilities->current_orientation = data->orientation;
}


static const struct display_driver_api gc9a01a_api = {
	.blanking_on = gc9a01a_display_blanking_on,
	.blanking_off = gc9a01a_display_blanking_off,
	.write = gc9a01a_write,
	.read = gc9a01a_read,
	.get_framebuffer = gc9a01a_get_framebuffer,
	.set_brightness = gc9a01a_set_brightness,
	.set_contrast = gc9a01a_set_contrast,
	.get_capabilities = gc9a01a_get_capabilities,
	.set_pixel_format = gc9a01a_set_pixel_format,
	.set_orientation = gc9a01a_set_orientation,
};


#define INST_DT_GC9A01A(n) DT_INST(n, waveshare_gc9a01a)

#define GC9A01A_INIT(n,t)													\
	GC9A01A_REGS_INIT(n);												\
	static const struct gc9a01a_config gc9a01a_config_##n = { 			\
		.spi = SPI_DT_SPEC_GET(INST_DT_GC9A01A(n), 						\
			SPI_OP_MODE_MASTER | SPI_WORD_SET(8),						\
			0 ) , 														\
		.cmd_data= GPIO_DT_SPEC_GET(INST_DT_GC9A01A(n),					\
			cmd_data_gpios),											\
		.reset = GPIO_DT_SPEC_GET_OR(INST_DT_GC9A01A(n),        		\
			reset_gpios, {0}),    										\
		.backlight = PWM_DT_SPEC_GET(DT_PROP(INST_DT_GC9A01A(n), backlight_gpios)),\
		.pixel_format = DT_PROP(INST_DT_GC9A01A(n), pixel_format), 		\
		.rotation= DT_PROP(INST_DT_GC9A01A(n), rotation),        		\
		.x_resolution = GC9A01A_X_RES,                                	\
		.y_resolution = GC9A01A_Y_RES,                                	\
		.inversion = DT_PROP(INST_DT_GC9A01A(n), display_inversion),	\
		.regs = &gc9a01a_regs_##n,                                   	\
		.regs_init_fn = gc9a01a_regs_init,                            	\
	};                                           						\
	static struct gc9a01a_data gc9a01a_data_##n;						\
	DEVICE_DT_DEFINE(INST_DT_GC9A01A(n), gc9a01a_init,                  \
			    NULL, &gc9a01a_data_##n,                           		\
			    &gc9a01a_config_##n, POST_KERNEL,                 		\
			    CONFIG_DISPLAY_INIT_PRIORITY, &gc9a01a_api)


#define DT_INST_FOREACH_GC9A01A_STATUS_OKAY                         \
	LISTIFY(DT_NUM_INST_STATUS_OKAY(waveshare_gc9a01a), GC9A01A_INIT,(;))

#ifdef CONFIG_GC9A01A
DT_INST_FOREACH_GC9A01A_STATUS_OKAY;
#endif
