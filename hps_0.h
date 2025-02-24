#ifndef _ALTERA_HPS_0_H_
#define _ALTERA_HPS_0_H_

/*
 * This file was automatically generated by the swinfo2header utility.
 * 
 * Created from SOPC Builder system 'soc_system' in
 * file './soc_system.sopcinfo'.
 */

/*
 * This file contains macros for module 'hps_0' and devices
 * connected to the following masters:
 *   h2f_axi_master
 *   h2f_lw_axi_master
 * 
 * Do not include this header file and another header file created for a
 * different module or master group at the same time.
 * Doing so may result in duplicate macro names.
 * Instead, use the system header file which has macros with unique names.
 */

/*
 * Macros for device 'sdram', class 'altera_avalon_new_sdram_controller'
 * The macros are prefixed with 'SDRAM_'.
 * The prefix is the slave descriptor.
 */
#define SDRAM_COMPONENT_TYPE altera_avalon_new_sdram_controller
#define SDRAM_COMPONENT_NAME sdram
#define SDRAM_BASE 0x0
#define SDRAM_SPAN 67108864
#define SDRAM_END 0x3ffffff
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO 
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 25
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 1
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_T_AC 5.5
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_WR 14.0
#define SDRAM_MEMORY_INFO_DAT_SYM_INSTALL_DIR SIM_DIR
#define SDRAM_MEMORY_INFO_GENERATE_DAT_SYM 1
#define SDRAM_MEMORY_INFO_MEM_INIT_DATA_WIDTH 16

/*
 * Macros for device 'dma_0', class 'altera_avalon_dma'
 * The macros are prefixed with 'DMA_0_'.
 * The prefix is the slave descriptor.
 */
#define DMA_0_COMPONENT_TYPE altera_avalon_dma
#define DMA_0_COMPONENT_NAME dma_0
#define DMA_0_BASE 0x0
#define DMA_0_SPAN 32
#define DMA_0_END 0x1f
#define DMA_0_ALLOW_BYTE_TRANSACTIONS 1
#define DMA_0_ALLOW_DOUBLEWORD_TRANSACTIONS 1
#define DMA_0_ALLOW_HW_TRANSACTIONS 1
#define DMA_0_ALLOW_QUADWORD_TRANSACTIONS 1
#define DMA_0_ALLOW_WORD_TRANSACTIONS 1
#define DMA_0_LENGTHWIDTH 32
#define DMA_0_MAX_BURST_SIZE 128

/*
 * Macros for device 'hps_0_axi_sdram', class 'axi_sdram'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_COMPONENT_TYPE axi_sdram
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_COMPONENT_NAME hps_0_axi_sdram
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_BASE 0x0
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_SPAN 0x80000000
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_END 0x7fffffff
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_SIZE_MULTIPLE 1
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_SIZE_VALUE 1<<31
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_WRITABLE 1
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_MEMORY_INFO_GENERATE_DAT_SYM 0
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_MEMORY_INFO_GENERATE_HEX 0
#define DMA_0_READ_MASTER_HPS_0_AXI_SDRAM_MEMORY_INFO_MEM_INIT_DATA_WIDTH 31

/*
 * Macros for device 'hps_0_gmac0', class 'stmmac'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_GMAC0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_GMAC0_COMPONENT_TYPE stmmac
#define DMA_0_READ_MASTER_HPS_0_GMAC0_COMPONENT_NAME hps_0_gmac0
#define DMA_0_READ_MASTER_HPS_0_GMAC0_BASE 0xff700000
#define DMA_0_READ_MASTER_HPS_0_GMAC0_SPAN 8192
#define DMA_0_READ_MASTER_HPS_0_GMAC0_END 0xff701fff

/*
 * Macros for device 'hps_0_gmac1', class 'stmmac'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_GMAC1_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_GMAC1_COMPONENT_TYPE stmmac
#define DMA_0_READ_MASTER_HPS_0_GMAC1_COMPONENT_NAME hps_0_gmac1
#define DMA_0_READ_MASTER_HPS_0_GMAC1_BASE 0xff702000
#define DMA_0_READ_MASTER_HPS_0_GMAC1_SPAN 8192
#define DMA_0_READ_MASTER_HPS_0_GMAC1_END 0xff703fff

/*
 * Macros for device 'hps_0_sdmmc', class 'sdmmc'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_SDMMC_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_SDMMC_COMPONENT_TYPE sdmmc
#define DMA_0_READ_MASTER_HPS_0_SDMMC_COMPONENT_NAME hps_0_sdmmc
#define DMA_0_READ_MASTER_HPS_0_SDMMC_BASE 0xff704000
#define DMA_0_READ_MASTER_HPS_0_SDMMC_SPAN 4096
#define DMA_0_READ_MASTER_HPS_0_SDMMC_END 0xff704fff

/*
 * Macros for device 'hps_0_qspi', class 'cadence_qspi'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_QSPI_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_QSPI_COMPONENT_TYPE cadence_qspi
#define DMA_0_READ_MASTER_HPS_0_QSPI_COMPONENT_NAME hps_0_qspi
#define DMA_0_READ_MASTER_HPS_0_QSPI_BASE 0xff705000
#define DMA_0_READ_MASTER_HPS_0_QSPI_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_QSPI_END 0xff7050ff

/*
 * Macros for device 'hps_0_fpgamgr', class 'altera_fpgamgr'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_FPGAMGR_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_FPGAMGR_COMPONENT_TYPE altera_fpgamgr
#define DMA_0_READ_MASTER_HPS_0_FPGAMGR_COMPONENT_NAME hps_0_fpgamgr
#define DMA_0_READ_MASTER_HPS_0_FPGAMGR_BASE 0xff706000
#define DMA_0_READ_MASTER_HPS_0_FPGAMGR_SPAN 4096
#define DMA_0_READ_MASTER_HPS_0_FPGAMGR_END 0xff706fff

/*
 * Macros for device 'hps_0_gpio0', class 'dw_gpio'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_GPIO0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_GPIO0_COMPONENT_TYPE dw_gpio
#define DMA_0_READ_MASTER_HPS_0_GPIO0_COMPONENT_NAME hps_0_gpio0
#define DMA_0_READ_MASTER_HPS_0_GPIO0_BASE 0xff708000
#define DMA_0_READ_MASTER_HPS_0_GPIO0_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_GPIO0_END 0xff7080ff

/*
 * Macros for device 'hps_0_gpio1', class 'dw_gpio'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_GPIO1_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_GPIO1_COMPONENT_TYPE dw_gpio
#define DMA_0_READ_MASTER_HPS_0_GPIO1_COMPONENT_NAME hps_0_gpio1
#define DMA_0_READ_MASTER_HPS_0_GPIO1_BASE 0xff709000
#define DMA_0_READ_MASTER_HPS_0_GPIO1_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_GPIO1_END 0xff7090ff

/*
 * Macros for device 'hps_0_gpio2', class 'dw_gpio'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_GPIO2_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_GPIO2_COMPONENT_TYPE dw_gpio
#define DMA_0_READ_MASTER_HPS_0_GPIO2_COMPONENT_NAME hps_0_gpio2
#define DMA_0_READ_MASTER_HPS_0_GPIO2_BASE 0xff70a000
#define DMA_0_READ_MASTER_HPS_0_GPIO2_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_GPIO2_END 0xff70a0ff

/*
 * Macros for device 'hps_0_l3regs', class 'altera_l3regs'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_L3REGS_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_L3REGS_COMPONENT_TYPE altera_l3regs
#define DMA_0_READ_MASTER_HPS_0_L3REGS_COMPONENT_NAME hps_0_l3regs
#define DMA_0_READ_MASTER_HPS_0_L3REGS_BASE 0xff800000
#define DMA_0_READ_MASTER_HPS_0_L3REGS_SPAN 4096
#define DMA_0_READ_MASTER_HPS_0_L3REGS_END 0xff800fff

/*
 * Macros for device 'hps_0_nand0', class 'denali_nand'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_NAND0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_NAND0_COMPONENT_TYPE denali_nand
#define DMA_0_READ_MASTER_HPS_0_NAND0_COMPONENT_NAME hps_0_nand0
#define DMA_0_READ_MASTER_HPS_0_NAND0_BASE 0xff900000
#define DMA_0_READ_MASTER_HPS_0_NAND0_SPAN 65536
#define DMA_0_READ_MASTER_HPS_0_NAND0_END 0xff90ffff

/*
 * Macros for device 'hps_0_usb0', class 'usb'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_USB0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_USB0_COMPONENT_TYPE usb
#define DMA_0_READ_MASTER_HPS_0_USB0_COMPONENT_NAME hps_0_usb0
#define DMA_0_READ_MASTER_HPS_0_USB0_BASE 0xffb00000
#define DMA_0_READ_MASTER_HPS_0_USB0_SPAN 262144
#define DMA_0_READ_MASTER_HPS_0_USB0_END 0xffb3ffff

/*
 * Macros for device 'hps_0_usb1', class 'usb'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_USB1_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_USB1_COMPONENT_TYPE usb
#define DMA_0_READ_MASTER_HPS_0_USB1_COMPONENT_NAME hps_0_usb1
#define DMA_0_READ_MASTER_HPS_0_USB1_BASE 0xffb40000
#define DMA_0_READ_MASTER_HPS_0_USB1_SPAN 262144
#define DMA_0_READ_MASTER_HPS_0_USB1_END 0xffb7ffff

/*
 * Macros for device 'hps_0_dcan0', class 'bosch_dcan'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_DCAN0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_DCAN0_COMPONENT_TYPE bosch_dcan
#define DMA_0_READ_MASTER_HPS_0_DCAN0_COMPONENT_NAME hps_0_dcan0
#define DMA_0_READ_MASTER_HPS_0_DCAN0_BASE 0xffc00000
#define DMA_0_READ_MASTER_HPS_0_DCAN0_SPAN 4096
#define DMA_0_READ_MASTER_HPS_0_DCAN0_END 0xffc00fff

/*
 * Macros for device 'hps_0_dcan1', class 'bosch_dcan'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_DCAN1_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_DCAN1_COMPONENT_TYPE bosch_dcan
#define DMA_0_READ_MASTER_HPS_0_DCAN1_COMPONENT_NAME hps_0_dcan1
#define DMA_0_READ_MASTER_HPS_0_DCAN1_BASE 0xffc01000
#define DMA_0_READ_MASTER_HPS_0_DCAN1_SPAN 4096
#define DMA_0_READ_MASTER_HPS_0_DCAN1_END 0xffc01fff

/*
 * Macros for device 'hps_0_uart0', class 'snps_uart'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_UART0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_UART0_COMPONENT_TYPE snps_uart
#define DMA_0_READ_MASTER_HPS_0_UART0_COMPONENT_NAME hps_0_uart0
#define DMA_0_READ_MASTER_HPS_0_UART0_BASE 0xffc02000
#define DMA_0_READ_MASTER_HPS_0_UART0_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_UART0_END 0xffc020ff
#define DMA_0_READ_MASTER_HPS_0_UART0_FIFO_DEPTH 128
#define DMA_0_READ_MASTER_HPS_0_UART0_FIFO_HWFC 0
#define DMA_0_READ_MASTER_HPS_0_UART0_FIFO_MODE 1
#define DMA_0_READ_MASTER_HPS_0_UART0_FIFO_SWFC 0
#define DMA_0_READ_MASTER_HPS_0_UART0_FREQ 100000000

/*
 * Macros for device 'hps_0_uart1', class 'snps_uart'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_UART1_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_UART1_COMPONENT_TYPE snps_uart
#define DMA_0_READ_MASTER_HPS_0_UART1_COMPONENT_NAME hps_0_uart1
#define DMA_0_READ_MASTER_HPS_0_UART1_BASE 0xffc03000
#define DMA_0_READ_MASTER_HPS_0_UART1_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_UART1_END 0xffc030ff
#define DMA_0_READ_MASTER_HPS_0_UART1_FIFO_DEPTH 128
#define DMA_0_READ_MASTER_HPS_0_UART1_FIFO_HWFC 0
#define DMA_0_READ_MASTER_HPS_0_UART1_FIFO_MODE 1
#define DMA_0_READ_MASTER_HPS_0_UART1_FIFO_SWFC 0
#define DMA_0_READ_MASTER_HPS_0_UART1_FREQ 100000000

/*
 * Macros for device 'hps_0_i2c0', class 'designware_i2c'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_I2C0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_I2C0_COMPONENT_TYPE designware_i2c
#define DMA_0_READ_MASTER_HPS_0_I2C0_COMPONENT_NAME hps_0_i2c0
#define DMA_0_READ_MASTER_HPS_0_I2C0_BASE 0xffc04000
#define DMA_0_READ_MASTER_HPS_0_I2C0_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_I2C0_END 0xffc040ff

/*
 * Macros for device 'hps_0_i2c1', class 'designware_i2c'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_I2C1_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_I2C1_COMPONENT_TYPE designware_i2c
#define DMA_0_READ_MASTER_HPS_0_I2C1_COMPONENT_NAME hps_0_i2c1
#define DMA_0_READ_MASTER_HPS_0_I2C1_BASE 0xffc05000
#define DMA_0_READ_MASTER_HPS_0_I2C1_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_I2C1_END 0xffc050ff

/*
 * Macros for device 'hps_0_i2c2', class 'designware_i2c'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_I2C2_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_I2C2_COMPONENT_TYPE designware_i2c
#define DMA_0_READ_MASTER_HPS_0_I2C2_COMPONENT_NAME hps_0_i2c2
#define DMA_0_READ_MASTER_HPS_0_I2C2_BASE 0xffc06000
#define DMA_0_READ_MASTER_HPS_0_I2C2_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_I2C2_END 0xffc060ff

/*
 * Macros for device 'hps_0_i2c3', class 'designware_i2c'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_I2C3_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_I2C3_COMPONENT_TYPE designware_i2c
#define DMA_0_READ_MASTER_HPS_0_I2C3_COMPONENT_NAME hps_0_i2c3
#define DMA_0_READ_MASTER_HPS_0_I2C3_BASE 0xffc07000
#define DMA_0_READ_MASTER_HPS_0_I2C3_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_I2C3_END 0xffc070ff

/*
 * Macros for device 'hps_0_timer0', class 'dw_apb_timer_sp'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_TIMER0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_TIMER0_COMPONENT_TYPE dw_apb_timer_sp
#define DMA_0_READ_MASTER_HPS_0_TIMER0_COMPONENT_NAME hps_0_timer0
#define DMA_0_READ_MASTER_HPS_0_TIMER0_BASE 0xffc08000
#define DMA_0_READ_MASTER_HPS_0_TIMER0_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_TIMER0_END 0xffc080ff

/*
 * Macros for device 'hps_0_timer1', class 'dw_apb_timer_sp'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_TIMER1_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_TIMER1_COMPONENT_TYPE dw_apb_timer_sp
#define DMA_0_READ_MASTER_HPS_0_TIMER1_COMPONENT_NAME hps_0_timer1
#define DMA_0_READ_MASTER_HPS_0_TIMER1_BASE 0xffc09000
#define DMA_0_READ_MASTER_HPS_0_TIMER1_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_TIMER1_END 0xffc090ff

/*
 * Macros for device 'hps_0_sdrctl', class 'altera_sdrctl'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_SDRCTL_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_SDRCTL_COMPONENT_TYPE altera_sdrctl
#define DMA_0_READ_MASTER_HPS_0_SDRCTL_COMPONENT_NAME hps_0_sdrctl
#define DMA_0_READ_MASTER_HPS_0_SDRCTL_BASE 0xffc25000
#define DMA_0_READ_MASTER_HPS_0_SDRCTL_SPAN 4096
#define DMA_0_READ_MASTER_HPS_0_SDRCTL_END 0xffc25fff

/*
 * Macros for device 'hps_0_timer2', class 'dw_apb_timer_osc'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_TIMER2_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_TIMER2_COMPONENT_TYPE dw_apb_timer_osc
#define DMA_0_READ_MASTER_HPS_0_TIMER2_COMPONENT_NAME hps_0_timer2
#define DMA_0_READ_MASTER_HPS_0_TIMER2_BASE 0xffd00000
#define DMA_0_READ_MASTER_HPS_0_TIMER2_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_TIMER2_END 0xffd000ff

/*
 * Macros for device 'hps_0_timer3', class 'dw_apb_timer_osc'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_TIMER3_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_TIMER3_COMPONENT_TYPE dw_apb_timer_osc
#define DMA_0_READ_MASTER_HPS_0_TIMER3_COMPONENT_NAME hps_0_timer3
#define DMA_0_READ_MASTER_HPS_0_TIMER3_BASE 0xffd01000
#define DMA_0_READ_MASTER_HPS_0_TIMER3_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_TIMER3_END 0xffd010ff

/*
 * Macros for device 'hps_0_clkmgr', class 'asimov_clkmgr'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_CLKMGR_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_CLKMGR_COMPONENT_TYPE asimov_clkmgr
#define DMA_0_READ_MASTER_HPS_0_CLKMGR_COMPONENT_NAME hps_0_clkmgr
#define DMA_0_READ_MASTER_HPS_0_CLKMGR_BASE 0xffd04000
#define DMA_0_READ_MASTER_HPS_0_CLKMGR_SPAN 4096
#define DMA_0_READ_MASTER_HPS_0_CLKMGR_END 0xffd04fff

/*
 * Macros for device 'hps_0_rstmgr', class 'altera_rstmgr'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_RSTMGR_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_RSTMGR_COMPONENT_TYPE altera_rstmgr
#define DMA_0_READ_MASTER_HPS_0_RSTMGR_COMPONENT_NAME hps_0_rstmgr
#define DMA_0_READ_MASTER_HPS_0_RSTMGR_BASE 0xffd05000
#define DMA_0_READ_MASTER_HPS_0_RSTMGR_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_RSTMGR_END 0xffd050ff

/*
 * Macros for device 'hps_0_sysmgr', class 'altera_sysmgr'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_SYSMGR_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_SYSMGR_COMPONENT_TYPE altera_sysmgr
#define DMA_0_READ_MASTER_HPS_0_SYSMGR_COMPONENT_NAME hps_0_sysmgr
#define DMA_0_READ_MASTER_HPS_0_SYSMGR_BASE 0xffd08000
#define DMA_0_READ_MASTER_HPS_0_SYSMGR_SPAN 1024
#define DMA_0_READ_MASTER_HPS_0_SYSMGR_END 0xffd083ff

/*
 * Macros for device 'hps_0_dma', class 'arm_pl330_dma'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_DMA_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_DMA_COMPONENT_TYPE arm_pl330_dma
#define DMA_0_READ_MASTER_HPS_0_DMA_COMPONENT_NAME hps_0_dma
#define DMA_0_READ_MASTER_HPS_0_DMA_BASE 0xffe01000
#define DMA_0_READ_MASTER_HPS_0_DMA_SPAN 4096
#define DMA_0_READ_MASTER_HPS_0_DMA_END 0xffe01fff

/*
 * Macros for device 'hps_0_spim0', class 'spi'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_SPIM0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_SPIM0_COMPONENT_TYPE spi
#define DMA_0_READ_MASTER_HPS_0_SPIM0_COMPONENT_NAME hps_0_spim0
#define DMA_0_READ_MASTER_HPS_0_SPIM0_BASE 0xfff00000
#define DMA_0_READ_MASTER_HPS_0_SPIM0_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_SPIM0_END 0xfff000ff

/*
 * Macros for device 'hps_0_spim1', class 'spi'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_SPIM1_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_SPIM1_COMPONENT_TYPE spi
#define DMA_0_READ_MASTER_HPS_0_SPIM1_COMPONENT_NAME hps_0_spim1
#define DMA_0_READ_MASTER_HPS_0_SPIM1_BASE 0xfff01000
#define DMA_0_READ_MASTER_HPS_0_SPIM1_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_SPIM1_END 0xfff010ff

/*
 * Macros for device 'hps_0_timer', class 'arm_internal_timer'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_TIMER_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_TIMER_COMPONENT_TYPE arm_internal_timer
#define DMA_0_READ_MASTER_HPS_0_TIMER_COMPONENT_NAME hps_0_timer
#define DMA_0_READ_MASTER_HPS_0_TIMER_BASE 0xfffec600
#define DMA_0_READ_MASTER_HPS_0_TIMER_SPAN 256
#define DMA_0_READ_MASTER_HPS_0_TIMER_END 0xfffec6ff

/*
 * Macros for device 'hps_0_arm_gic_0', class 'arm_gic'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_ARM_GIC_0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_ARM_GIC_0_COMPONENT_TYPE arm_gic
#define DMA_0_READ_MASTER_HPS_0_ARM_GIC_0_COMPONENT_NAME hps_0_arm_gic_0
#define DMA_0_READ_MASTER_HPS_0_ARM_GIC_0_BASE 0xfffed000
#define DMA_0_READ_MASTER_HPS_0_ARM_GIC_0_SPAN 4096
#define DMA_0_READ_MASTER_HPS_0_ARM_GIC_0_END 0xfffedfff

/*
 * Macros for device 'hps_0_L2', class 'arm_pl310_L2'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_L2_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_L2_COMPONENT_TYPE arm_pl310_L2
#define DMA_0_READ_MASTER_HPS_0_L2_COMPONENT_NAME hps_0_L2
#define DMA_0_READ_MASTER_HPS_0_L2_BASE 0xfffef000
#define DMA_0_READ_MASTER_HPS_0_L2_SPAN 4096
#define DMA_0_READ_MASTER_HPS_0_L2_END 0xfffeffff

/*
 * Macros for device 'hps_0_axi_ocram', class 'axi_ocram'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_COMPONENT_TYPE axi_ocram
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_COMPONENT_NAME hps_0_axi_ocram
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_BASE 0xffff0000
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_SPAN 65536
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_END 0xffffffff
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_SIZE_MULTIPLE 1
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_SIZE_VALUE 1<<16
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_WRITABLE 1
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_MEMORY_INFO_GENERATE_DAT_SYM 0
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_MEMORY_INFO_GENERATE_HEX 0
#define DMA_0_READ_MASTER_HPS_0_AXI_OCRAM_MEMORY_INFO_MEM_INIT_DATA_WIDTH 16

/*
 * Macros for device 'sdram', class 'altera_avalon_new_sdram_controller'
 * Path to the device is from the master group 'dma_0_write_master'.
 * The macros are prefixed with 'DMA_0_WRITE_MASTER_SDRAM_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_WRITE_MASTER_SDRAM_COMPONENT_TYPE altera_avalon_new_sdram_controller
#define DMA_0_WRITE_MASTER_SDRAM_COMPONENT_NAME sdram
#define DMA_0_WRITE_MASTER_SDRAM_BASE 0x0
#define DMA_0_WRITE_MASTER_SDRAM_SPAN 67108864
#define DMA_0_WRITE_MASTER_SDRAM_END 0x3ffffff
#define DMA_0_WRITE_MASTER_SDRAM_CAS_LATENCY 3
#define DMA_0_WRITE_MASTER_SDRAM_CONTENTS_INFO 
#define DMA_0_WRITE_MASTER_SDRAM_INIT_NOP_DELAY 0.0
#define DMA_0_WRITE_MASTER_SDRAM_INIT_REFRESH_COMMANDS 2
#define DMA_0_WRITE_MASTER_SDRAM_IS_INITIALIZED 1
#define DMA_0_WRITE_MASTER_SDRAM_POWERUP_DELAY 100.0
#define DMA_0_WRITE_MASTER_SDRAM_REFRESH_PERIOD 15.625
#define DMA_0_WRITE_MASTER_SDRAM_REGISTER_DATA_IN 1
#define DMA_0_WRITE_MASTER_SDRAM_SDRAM_ADDR_WIDTH 25
#define DMA_0_WRITE_MASTER_SDRAM_SDRAM_BANK_WIDTH 2
#define DMA_0_WRITE_MASTER_SDRAM_SDRAM_COL_WIDTH 10
#define DMA_0_WRITE_MASTER_SDRAM_SDRAM_DATA_WIDTH 16
#define DMA_0_WRITE_MASTER_SDRAM_SDRAM_NUM_BANKS 4
#define DMA_0_WRITE_MASTER_SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define DMA_0_WRITE_MASTER_SDRAM_SDRAM_ROW_WIDTH 13
#define DMA_0_WRITE_MASTER_SDRAM_SHARED_DATA 0
#define DMA_0_WRITE_MASTER_SDRAM_SIM_MODEL_BASE 1
#define DMA_0_WRITE_MASTER_SDRAM_STARVATION_INDICATOR 0
#define DMA_0_WRITE_MASTER_SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define DMA_0_WRITE_MASTER_SDRAM_T_AC 5.5
#define DMA_0_WRITE_MASTER_SDRAM_T_MRD 3
#define DMA_0_WRITE_MASTER_SDRAM_T_RCD 20.0
#define DMA_0_WRITE_MASTER_SDRAM_T_RFC 70.0
#define DMA_0_WRITE_MASTER_SDRAM_T_RP 20.0
#define DMA_0_WRITE_MASTER_SDRAM_T_WR 14.0
#define DMA_0_WRITE_MASTER_SDRAM_MEMORY_INFO_DAT_SYM_INSTALL_DIR SIM_DIR
#define DMA_0_WRITE_MASTER_SDRAM_MEMORY_INFO_GENERATE_DAT_SYM 1
#define DMA_0_WRITE_MASTER_SDRAM_MEMORY_INFO_MEM_INIT_DATA_WIDTH 16

/*
 * Macros for device 'jtag_uart', class 'altera_avalon_jtag_uart'
 * The macros are prefixed with 'JTAG_UART_'.
 * The prefix is the slave descriptor.
 */
#define JTAG_UART_COMPONENT_TYPE altera_avalon_jtag_uart
#define JTAG_UART_COMPONENT_NAME jtag_uart
#define JTAG_UART_BASE 0x20000
#define JTAG_UART_SPAN 8
#define JTAG_UART_END 0x20007
#define JTAG_UART_IRQ 0
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8

/*
 * Macros for device 'VLC_0', class 'VLC_01'
 * The macros are prefixed with 'VLC_0_'.
 * The prefix is the slave descriptor.
 */
#define VLC_0_COMPONENT_TYPE VLC_01
#define VLC_0_COMPONENT_NAME VLC_0
#define VLC_0_BASE 0x4000000
#define VLC_0_SPAN 16
#define VLC_0_END 0x400000f

/*
 * Macros for device 'Switch', class 'altera_avalon_pio'
 * The macros are prefixed with 'SWITCH_'.
 * The prefix is the slave descriptor.
 */
#define SWITCH_COMPONENT_TYPE altera_avalon_pio
#define SWITCH_COMPONENT_NAME Switch
#define SWITCH_BASE 0x4000010
#define SWITCH_SPAN 16
#define SWITCH_END 0x400001f
#define SWITCH_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH_CAPTURE 0
#define SWITCH_DATA_WIDTH 9
#define SWITCH_DO_TEST_BENCH_WIRING 0
#define SWITCH_DRIVEN_SIM_VALUE 0
#define SWITCH_EDGE_TYPE NONE
#define SWITCH_FREQ 50000000
#define SWITCH_HAS_IN 1
#define SWITCH_HAS_OUT 0
#define SWITCH_HAS_TRI 0
#define SWITCH_IRQ_TYPE NONE
#define SWITCH_RESET_VALUE 0


#endif /* _ALTERA_HPS_0_H_ */
