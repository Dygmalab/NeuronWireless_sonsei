/*
 * Copyright (C) 2025  Dygma Lab S.L.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * The purpose of this module is for defining the HID descriptors and functions for
 * getting the USB and BLE HID descriptor versions in hidDefy module
 */

#include "hidDefy.h"

#warning "Temporary SONSHI usage definition needs to be added to hidDefy.h when we publicly announce the new Sonshi product."
#define RAW_USAGE_SONSHI    0x01

const uint8_t hid_report_descriptor_sonshi[] = HID_DEFY_REPORT_DESCRIPTOR( RAW_USAGE_SONSHI );

void hid_report_descriptor_get( const uint8_t ** pp_desc, uint32_t * p_desc_len )
{
    *pp_desc = &hid_report_descriptor_sonshi[0];
    *p_desc_len = sizeof( hid_report_descriptor_sonshi );
}

void hid_report_descriptor_usb_get( const uint8_t ** pp_desc, uint32_t * p_desc_len )
{
    /* Dummy generic inout part of the descriptor for determining its size */
    const uint8_t sizeRawHID[] = {TUD_HID_REPORT_DESC_GENERIC_INOUT(OUTPUT_REPORT_LEN_RAW, HID_REPORT_ID(RAW_USAGE_UNKNOWN))};

    /* Get the valid descriptor */
    hid_report_descriptor_get( pp_desc, p_desc_len );

    /* Modify the descriptor length to omit the BLE part */
    *p_desc_len -= sizeof( sizeRawHID );
}

void hid_report_descriptor_ble_get( const uint8_t ** pp_desc, uint32_t * p_desc_len )
{
    /* Get the valid descriptor */
    hid_report_descriptor_get( pp_desc, p_desc_len );
}
