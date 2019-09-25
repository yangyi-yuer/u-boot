/*
 * Copyright (C) 2011 Samsung Electronics
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/cpu.h>
#include <asm/arch/mmc.h>
#include <asm/arch/periph.h>
#include <asm/arch/pinmux.h>
#include <usb.h>

#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <dm.h>
#include <errno.h>
#include <mmc.h>
#include <usb/dwc2_udc.h>
#include <samsung/misc.h>

DECLARE_GLOBAL_DATA_PTR;

u32 get_board_rev(void)
{
	return 0;
}

int exynos_init(void)
{
	return 0;
}

#ifdef CONFIG_USB_EHCI_EXYNOS
int board_usb_init(int index, enum usb_init_type init)
{
	/* Configure gpios for usb 3503 hub:
	 * disconnect, toggle reset and connect
	 */
	printf("%s\n", __func__);

	gpio_request(EXYNOS4X12_GPIO_M33, "usb_connect");
	gpio_request(EXYNOS4X12_GPIO_M24, "usb_reset");
	gpio_direction_output(EXYNOS4X12_GPIO_M33, 0);
	gpio_direction_output(EXYNOS4X12_GPIO_M24, 0);

	mdelay(100);
	gpio_direction_output(EXYNOS4X12_GPIO_M24, 1);
	gpio_direction_output(EXYNOS4X12_GPIO_M33, 1);

	return 0;
}
#endif

#ifdef CONFIG_BOARD_EARLY_INIT_F
int exynos_early_init_f(void)
{
	return 0;
}
#endif
