include $(GENERIC_X86_CONFIG_MK)
TARGET_HAS_THIRD_PARTY_APPS := true
BOARD_USES_TSLIB := false
BOARD_WPA_SUPPLICANT_DRIVER := WIRED
WPA_SUPPLICANT_VERSION      := VER_0_6_X
BOARD_WLAN_DEVICE           := eth1
BUILD_EMULATOR_OPENGL:=true
TARGET_ARCH_VARIANT := x86
TARGET_ARCH := x86
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1024M
BOARD_USES_GENERIC_AUDIO := false
BOARD_USES_ALSA_AUDIO := true
BUILD_WITH_ALSA_UTILS := true
TARGET_NO_KERNEL := false
BOARD_KERNEL_CMDLINE := init=/init console=tty0 quiet androidboot.hardware=vbox86 androidboot.console=tty0
TARGET_SHELL := mksh
