#!/usr/bin/env python3
#
# Script to create the seal and add add it to the keyscanner firmware
#

import argparse
import struct
import zlib
import numpy as np
import math
import re
from intelhex import IntelHex

BLDR_SEAL_VERSION = 2
BLDR_SEAL_ADDRESS = 0xFD000
BLDR_DEVICE_TYPE = 0x4F535944      # "DYSO" - Dygma Sonshi

FLASH_SECTOR_SIZE = 4 * 1024
FLASH_PAGE_SIZE = 256

def auto_int(x):
    return int(x, 0)

def padarray(A, size):
    t = size - len(A)
    return np.pad(A, pad_width=(0, t), mode='constant')

def pack_version(parts):
    major = parts[0] if len(parts) > 0 else 0
    minor = parts[1] if len(parts) > 1 else 0
    patch = parts[2] if len(parts) > 2 else 0
    suffix = parts[3] if len(parts) > 3 else 0

    for p in (major, minor, patch, suffix):
        if not 0 <= p <= 255:
            raise ValueError("Version component out of byte range")

    return (
        (suffix << 24) |
        (patch  << 16) |
        (minor  << 8)  |
        major
    )

def parse_version(version_str):
    # Remove leading 'v' or 'V'
    version_str = version_str.lstrip('vV')

    # Extract digits
    parts = re.findall(r'\d+', version_str)

    version_nums = list(map(int, parts))
    
    return pack_version(version_nums)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-v', type=str, dest='version', nargs='?', required=True)
    parser.add_argument('-ps', type=auto_int, dest='programStart', nargs='?', required=True)
    parser.add_argument('-o', dest='outfile', nargs='?', required=True)
    parser.add_argument('infile', nargs=1)

    args = parser.parse_args()
    print("Version of Firmware", args.version)
    print("Program start address", hex(args.programStart))

    program = open(args.infile[0] + ".bin", mode='rb').read()

    # Parse the program version string
    version_int = parse_version(args.version)

    # uint32_t version;        /* Version of the Seal */
    # uint32_t size;           /* Size of the Seal */
    # uint32_t crc;            /* CRC of the Seal */

    sealVersion = BLDR_SEAL_VERSION
    size = 0x00000020
    crc = 0x00000000
    
    # uint32_t deviceId
    
    deviceId = BLDR_DEVICE_TYPE
    
    # uint32_t programStart;
    # uint32_t programSize;
    # uint32_t programCrc;
    # uint32_t programVersion;

    versioning = struct.pack(b"<IIIIIIII",
                             sealVersion,
                             size,
                             crc,
                             deviceId,
                             args.programStart,
                             len(program),
                             zlib.crc32(program),
                             version_int)

    crc32Seal = zlib.crc32(versioning)
    print("CRC Seal", hex(crc32Seal))

    versioning = struct.pack(b"<IIIIIIII",
                             sealVersion,
                             size,
                             crc32Seal,
                             deviceId,
                             args.programStart,
                             len(program),
                             zlib.crc32(program),
                             version_int)

    print("CRC", hex(zlib.crc32(program)))
    versioning_padded = padarray(bytearray(versioning), FLASH_SECTOR_SIZE)

    print("Program Size", len(program))
    program = bytearray(program)

    KeyScanner_WithHeaderBin = open(args.outfile + "_sealed.bin", mode='wb')
    concatenate = np.concatenate((versioning_padded, program))
    KeyScanner_WithHeaderBin.write(padarray(bytearray(concatenate), math.ceil(
        len(concatenate) / FLASH_PAGE_SIZE) * FLASH_PAGE_SIZE).tobytes())
    print("FullProgram Size", len(concatenate))
    
    #############################
    # Create hex file with seal #
    #############################
    
    ih = IntelHex()
    
    # Load application
    ih.frombytes(program, offset=args.programStart)
    
    # Load seal
    ih.frombytes(versioning, offset=BLDR_SEAL_ADDRESS)
    
    # Write combined HEX
    ih.write_hex_file(args.outfile + "_sealed.hex")

main()
