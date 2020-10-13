//Authors:
//1. Prof. Madhav Desai
//2. Saurabh Bansode
//3. Vishnu Easwaran E
//Last updated: 12 Oct '20 by SB

#ifndef _SDHC_H
#define _SDHC_H

#include<stdint.h>

// bit masks for standard registers

// present state register
#define  SDHCI_CMD_INHIBIT	0x00000001
#define  SDHCI_DATA_INHIBIT	0x00000002
#define  SDHCI_DOING_WRITE	0x00000100
#define  SDHCI_DOING_READ	0x00000200
#define  SDHCI_SPACE_AVAILABLE	0x00000400
#define  SDHCI_DATA_AVAILABLE	0x00000800
#define  SDHCI_CARD_PRESENT	0x00010000
#define  SDHCI_WRITE_PROTECT	0x00080000
#define  SDHCI_DATA_LVL_MASK	0x00F00000
#define   SDHCI_DATA_LVL_SHIFT	20

// clk control
#define  SDHCI_DIVIDER_SHIFT	8
#define  SDHCI_DIVIDER_HI_SHIFT	6
#define  SDHCI_DIV_MASK		0xFF
#define  SDHCI_DIV_MASK_LEN	8
#define  SDHCI_DIV_HI_MASK	0x300
#define  SDHCI_PROG_CLOCK_MODE	0x0020
#define  SDHCI_CLOCK_CARD_EN	0x0004
#define  SDHCI_CLOCK_INT_STABLE	0x0002
#define  SDHCI_CLOCK_INT_EN	0x0001

//capabilities
#define  SDHCI_TIMEOUT_CLK_MASK	0x0000003F
#define  SDHCI_TIMEOUT_CLK_SHIFT 0
#define  SDHCI_TIMEOUT_CLK_UNIT	0x00000080
#define  SDHCI_CLOCK_BASE_MASK	0x00003F00
#define  SDHCI_CLOCK_V3_BASE_MASK	0x0000FF00
#define  SDHCI_CLOCK_BASE_SHIFT	8
#define  SDHCI_MAX_BLOCK_MASK	0x00030000
#define  SDHCI_MAX_BLOCK_SHIFT  16
#define  SDHCI_CAN_DO_8BIT	0x00040000
#define  SDHCI_CAN_DO_ADMA2	0x00080000
#define  SDHCI_CAN_DO_ADMA1	0x00100000
#define  SDHCI_CAN_DO_HISPD	0x00200000
#define  SDHCI_CAN_DO_SDMA	0x00400000
#define  SDHCI_CAN_VDD_330	0x01000000
#define  SDHCI_CAN_VDD_300	0x02000000
#define  SDHCI_CAN_VDD_180	0x04000000
#define  SDHCI_CAN_64BIT	0x10000000
#define  SDHCI_SUPPORT_SDR50	0x00000001
#define  SDHCI_SUPPORT_SDR104	0x00000002
#define  SDHCI_SUPPORT_DDR50	0x00000004
#define  SDHCI_DRIVER_TYPE_A	0x00000010
#define  SDHCI_DRIVER_TYPE_C	0x00000020
#define  SDHCI_DRIVER_TYPE_D	0x00000040
#define  SDHCI_RETUNING_TIMER_COUNT_MASK	0x00000F00
#define  SDHCI_RETUNING_TIMER_COUNT_SHIFT	8
#define  SDHCI_USE_SDR50_TUNING			0x00002000
#define  SDHCI_RETUNING_MODE_MASK		0x0000C000
#define  SDHCI_RETUNING_MODE_SHIFT		14
#define  SDHCI_CLOCK_MUL_MASK	0x00FF0000
#define  SDHCI_CLOCK_MUL_SHIFT	16


int card_insert_remove();
void SD_detection();

//register pipes/signals used by the SDHC
void register_sdhc_pipes();

//start SDHC thread
void start_sdhc_threads();
//SDHC control thread overlooks the overall ops
//SDHC Read will perform read ops 
//SDHC Write will perform write ops
void SDHC_Control();
void SDHC_Read();
void SDHC_Write();

// data structures

/* sdhc */
typedef struct SdhcState__ {
	// registers of SDHC
	uint32_t argument2; //addr-offset 0x00
	uint16_t blk_size; // 0x4
	uint16_t blk_count; //0x6
	uint32_t argument; //0x8
	uint16_t tx_mode; //0xC
	uint16_t command_reg; //0xE
	uint32_t response0; //0x10
	uint32_t response2; //0x14
	uint32_t response4; //0x18
	uint32_t response6; //0x1c
	uint32_t buffer_data_port; //0x20
	uint32_t present_state; //0x24
	uint8_t host_ctrl; //ox28
	uint8_t pwr_ctrl;//0x29
	uint8_t blk_gap_ctrl; //0x2A 
	uint8_t wakeup_ctrl; //0x2B
	uint16_t clk_ctrl; //0x2C
	uint8_t timeout_ctrl; //0x2E
	uint8_t sw_reset; //0x2F
	uint16_t normal_intr_status; //0x30
	uint16_t error_intr_status; //0x32
	uint16_t normal_intr_status_enable; //0x34
	uint16_t error_intr_status_enable; //0x36
	uint16_t normal_intr_signal_enable; //0x38
	uint16_t error_intr_signal_enable; //0x3A
	uint16_t autoCMD_error_status; //0x3C
	uint16_t host_ctrl2; //0x3E
	uint32_t capabilities; //0x40
	uint16_t host_controller_version; //0xFE
	SdcardState sd_card_state;
} SdhcState;

/* sd card */
typedef struct SdcardState {
	// registers

	// storage array.
} SdcardState;

void initSdcardState();
{
	// return 0 if read ok, else 1 - communication check
	int readBlock(SdcardState* s, int block_size_in_bytes, int block_start_byte_index, uint8_t* barray);
	int writeBlock(SdcardState* s, int block_size_in_bytes, int block_start_byte_index, uint8_t* barray);
	// etc...
}

#endif