/*
 * Defines machines for CSR SiRFprimaII 
 *
 * Copyright (c) 2011 Cambridge Silicon Radio Limited, a CSR plc group company.
 *
 * Licensed under GPLv2 or later.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <asm/mach-types.h>
#include <asm/mach/arch.h>
#include <linux/of.h>
#include <linux/of_platform.h>
#include "common.h"

static struct of_device_id sirfsoc_of_bus_ids[] __initdata = {
	{ .compatible = "simple-bus", },
	{},
};

void __init sirfsoc_mach_init(void)
{
	of_platform_bus_probe(NULL, sirfsoc_of_bus_ids, NULL);
}

static const char *prima2cb_dt_match[] __initdata = {
       "sirf,prima2-cb",
       NULL
};

MACHINE_START(PRIMA2_EVB, "prima2cb")
	/* Maintainer: Barry Song <baohua.song@csr.com> */
	.boot_params	= 0x00000100,
	.init_early     = sirfsoc_of_clk_init,
	.map_io         = sirfsoc_map_lluart,
	.init_irq	= sirfsoc_of_irq_init,
	.timer		= &sirfsoc_timer,
	.init_machine	= sirfsoc_mach_init,
	.dt_compat      = prima2cb_dt_match,
MACHINE_END
