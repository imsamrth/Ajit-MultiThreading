#ifndef __SDHC_ACCESS_H_
#define __SDHC_ACCESS_H_


/* Device register addresses */

#define ADDR_SDHC_ARG_2                         0xFFFF3300      // 4 BYTES WIDE
#define ADDR_SDHC_BLOCK_SIZE                    0xFFFF3304      // 2 BYTES WIDE
#define ADDR_SDHC_BLOCK_COUNT                   0xFFFF3306      // 2 BYTES WIDE
#define ADDR_SDHC_ARG_1                         0xFFFF3308      // 4 BYTES WIDE
#define ADDR_SDHC_TRANSFER_MODE                 0xFFFF330C      // 2 BYTES WIDE
#define ADDR_SDHC_REGISTER_COMMAND              0xFFFF330E      // 2 BYTES WIDE
#define ADDR_SDHC_RESPONSE0                     0xFFFF3310      // 2 BYTES WIDE
#define ADDR_SDHC_RESPONSE1                     0xFFFF3312      // 2 BYTES WIDE
#define ADDR_SDHC_RESPONSE2                     0xFFFF3314      // 2 BYTES WIDE
#define ADDR_SDHC_RESPONSE3                     0xFFFF3316      // 2 BYTES WIDE
#define ADDR_SDHC_RESPONSE4                     0xFFFF3318      // 2 BYTES WIDE
#define ADDR_SDHC_RESPONSE5                     0xFFFF331A      // 2 BYTES WIDE
#define ADDR_SDHC_RESPONSE6                     0xFFFF331C      // 2 BYTES WIDE
#define ADDR_SDHC_RESPONSE7                     0xFFFF331E      // 2 BYTES WIDE
#define ADDR_SDHC_BUFFER_DATA_PORT              0xFFFF3320      // 4 BYTES WIDE
#define ADDR_SDHC_PRESENT_STATE                 0xFFFF3324      // 4 BYTES WIDE
#define ADDR_SDHC_HOST_CONTROL_1                0xFFFF3328      // 1 BYTES WIDE
#define ADDR_SDHC_POWER_CONTROL                 0xFFFF3329      // 1 BYTES WIDE
#define ADDR_SDHC_BLOCK_GAP_CONTROL             0xFFFF332A      // 1 BYTES WIDE
#define ADDR_SDHC_WAKEUP_CONTROL                0xFFFF332B      // 1 BYTES WIDE
#define ADDR_SDHC_CLOCK_CONTROL                 0xFFFF332C      // 2 BYTES WIDE
#define ADDR_SDHC_TIMEOUT_CONTROL               0xFFFF332E      // 1 BYTES WIDE
#define ADDR_SDHC_SOFTWARE_RESET                0xFFFF332F      // 1 BYTES WIDE
#define ADDR_SDHC_NORMAL_INTR_STATUS            0xFFFF3330      // 2 BYTES WIDE
#define ADDR_SDHC_ERROR_INTR_STATUS             0xFFFF3332      // 2 BYTES WIDE
#define ADDR_SDHC_NORMAL_INTR_STATUS_EN         0xFFFF3334      // 2 BYTES WIDE
#define ADDR_SDHC_ERROR_INTR_STATUS_EN          0xFFFF3336      // 2 BYTES WIDE
#define ADDR_SDHC_NORMAL_INTR_SIGNAL_EN         0xFFFF3338      // 2 BYTES WIDE
#define ADDR_SDHC_ERROR_INTR_SIGNAL_EN          0xFFFF333A      // 2 BYTES WIDE
#define ADDR_SDHC_AUTO_CMD_ERROR_STATUS         0xFFFF333C      // 2 BYTES WIDE
#define ADDR_SDHC_HOST_CONTROL_2                0xFFFF333E      // 2 BYTES WIDE
#define ADDR_SDHC_CAPS                          0xFFFF3340      // 8 BYTES WIDE
#define ADDR_SDHC_MAX_CURRENT_CAPS              0xFFFF3348      // 4 BYTES WIDE
#define ADDR_SDHC_MAX_CURRENT_CAPS_RES          0xFFFF334C      // 4 BYTES WIDE
#define ADDR_SDHC_FORCE_EVENT_AUTOCMD_ERRSTAT   0xFFFF3350      // 2 BYTES WIDE
#define ADDR_SDHC_FORCE_EVENT_AUTOCMD_ERR_INTRSTAT 0xFFFF3352      // 2 BYTES WIDE
#define ADDR_SDHC_ADMA_ERR_STAT                 0xFFFF3354      // 1 BYTE WIDE
#define ADDR_SDHC_ADMA_SYSTEM_ADDR              0xFFFF3358      // 8 BYTES WIDE
#define ADDR_SDHC_HOST_PRESET_VALUES            0xFFFF3360      // 16 BYTES WIDE
#define ADDR_SDHC_SHARED_BUS_CTRL               0xFFFF33E0      // 2 BYTES WIDE
#define ADDR_SDHC_SLOT_INTR_STATUS              0xFFFF33FC      // 2 BYTES WIDE
#define ADDR_SDHC_HOST_CONTROLLER_VERSION       0xFFFF33FE      // 2 BYTES WIDE


/* SDHC bypass based methods */

inline void __ajit_bypass_write_sdhc_reg_byte(uint32_t addr, uint8_t val);
inline void __ajit_bypass_write_sdhc_reg_word(uint32_t addr, uint16_t val);
inline void __ajit_bypass_write_sdhc_reg_dword(uint32_t addr, uint32_t val);

inline uint32_t __ajit_bypass_read_sdhc_reg_byte(uint32_t addr);
inline uint32_t __ajit_bypass_read_sdhc_reg_word(uint32_t addr);
inline uint32_t __ajit_bypass_read_sdhc_reg_dword(uint32_t addr);

#endif