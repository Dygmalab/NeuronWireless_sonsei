
  # Name of directory containing target MCU specific content
  TARGET_MCU_DIR_NAME = $(TARGET_MCU)

  # Flags common to compiler, assembler and linker
  COMMONFLAGS += -mfloat-abi=hard

  # MCU device
  DEFINES += -DNRF52840_XXAA
  
  DEFINES += -DMCU_ALIGNMENT_SIZE=4


#-------------------------------------------------------------------------------
# SDK defines
#-------------------------------------------------------------------------------

DEFINES += -DNRFX_GPIOTE_CONFIG_NUM_OF_LOW_POWER_EVENTS=48	# P0_PIN_NUM + P1_PIN_NUM .. 32 + 16

#-------------------------------------------------------------------------------
# Application defines
#-------------------------------------------------------------------------------

  DEFINES += -DHAL_CFG_MCU=HAL_MCU_NRF52840

#-------------------------------------------------------------------------------
# Root directories
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
# Library search directiories
#-------------------------------------------------------------------------------

# SDK

#-------------------------------------------------------------------------------
# Include search directories
#-------------------------------------------------------------------------------

# HAL
INCDIR += -I$(HAL_ROOT_DIR)/mcu/nrf52/nrf52840/

## SDK
#INCDIR += -I$(SDK_NRF5_SDK_ROOT_DIR)/config/nrf52840/config/

#-------------------------------------------------------------------------------
# C sources
#-------------------------------------------------------------------------------

# System initialization
SRCSA += $(SDK_NRF5_SDK_ROOT_DIR)/modules/nrfx/mdk/gcc_startup_nrf52840.S

# SDK
SRCSC += $(SDK_NRF5_SDK_ROOT_DIR)/modules/nrfx/mdk/system_nrf52840.c

# HAL

# Drivers

# SDK
