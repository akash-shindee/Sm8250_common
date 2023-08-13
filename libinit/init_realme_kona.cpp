/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_variant.h>

#include "vendor_init.h"
#include <cstdlib>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <sys/sysinfo.h>
#include <android-base/properties.h>
#include "property_service.h"

using android::base::GetProperty;
using std::string;

void property_override(string prop, string value)
{
    auto pi = (prop_info*) __system_property_find(prop.c_str());

    if (pi != nullptr)
        __system_property_update(pi, value.c_str(), value.size());
    else
        __system_property_add(prop.c_str(), prop.size(), value.c_str(), value.size());
}

static const variant_info_t RMX2071_CN_info = {
    .prjversion_value = "19795",

    .device = "RMX2071CN",
    .model = "RMX2071",
    .name = "RMX2071",
};

static const variant_info_t RMX2072_CN_info = {
    .prjversion_value = "20607",

    .device = "RMX2072CN",
    .model = "RMX2072",
    .name = "RMX2072",
};

static const variant_info_t RMX2075_GLOBAL_info = {
    .prjversion_value = "19705",

    .device = "RMX2075L1",
    .model = "RMX2075",
    .name = "RMX2075",
};

static const variant_info_t RMX2076_IN_info = {
    .prjversion_value = "19706",

    .device = "RMX2076L1",
    .model = "RMX2076",
    .name = "RMX2076",
};

static const variant_info_t RMX3370_CN_info = {
    .prjversion_value = "21619",

    .device = "RE5473",
    .model = "RMX3370",
    .name = "RMX3370",
};

static const variant_info_t RMX3370_CNLZ_info = {
    .prjversion_value = "136730",

    .device = "RE5473",
    .model = "RMX3370",
    .name = "RMX3370",
};

static const variant_info_t RMX3370_GLOBAL_info = {
    .prjversion_value = "136859",

    .device = "RE879AL1",
    .model = "RMX3370",
    .name = "RMX3370",
};

static const variant_info_t RMX3370_IN_info = {
    .prjversion_value = "136858",

    .device = "RE879AL1",
    .model = "RMX3370",
    .name = "RMX3370",
};

static const std::vector<variant_info_t> variants = {
    RMX2071_CN_info,
    RMX2072_CN_info,
    RMX2075_GLOBAL_info,
    RMX2076_IN_info,
    RMX3370_CN_info,
    RMX3370_CNLZ_info,
    RMX3370_GLOBAL_info,
    RMX3370_IN_info,
};

void vendor_load_properties() {
    search_variant(variants);
    
    // Misc
    property_override("ro.rising.chipset", "Qualcomm® Snapdragon® 870 5G");
    property_override("ro.rising.device", "Realme X50 Pro");
    property_override("ro.rising.maintainer", "AAMIRR ALI");
}
