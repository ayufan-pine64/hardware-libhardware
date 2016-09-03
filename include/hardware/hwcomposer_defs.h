/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_INCLUDE_HARDWARE_HWCOMPOSER_DEFS_H
#define ANDROID_INCLUDE_HARDWARE_HWCOMPOSER_DEFS_H

#include <stdint.h>
#include <sys/cdefs.h>

#include <hardware/gralloc.h>
#include <hardware/hardware.h>
#include <cutils/native_handle.h>

__BEGIN_DECLS

/* Shared by HWC1 and HWC2 */

#define HWC_HEADER_VERSION          1

#define HWC_MODULE_API_VERSION_0_1  HARDWARE_MODULE_API_VERSION(0, 1)

#define HWC_DEVICE_API_VERSION_1_0  HARDWARE_DEVICE_API_VERSION_2(1, 0, HWC_HEADER_VERSION)
#define HWC_DEVICE_API_VERSION_1_1  HARDWARE_DEVICE_API_VERSION_2(1, 1, HWC_HEADER_VERSION)
#define HWC_DEVICE_API_VERSION_1_2  HARDWARE_DEVICE_API_VERSION_2(1, 2, HWC_HEADER_VERSION)
#define HWC_DEVICE_API_VERSION_1_3  HARDWARE_DEVICE_API_VERSION_2(1, 3, HWC_HEADER_VERSION)
#define HWC_DEVICE_API_VERSION_1_4  HARDWARE_DEVICE_API_VERSION_2(1, 4, HWC_HEADER_VERSION)
#define HWC_DEVICE_API_VERSION_1_5  HARDWARE_DEVICE_API_VERSION_2(1, 5, HWC_HEADER_VERSION)

#define HWC_DEVICE_API_VERSION_2_0  HARDWARE_DEVICE_API_VERSION_2(2, 0, HWC_HEADER_VERSION)

/**
 * The id of this module
 */
#define HWC_HARDWARE_MODULE_ID "hwcomposer"

/**
 * Name of the sensors device to open
 */
#define HWC_HARDWARE_COMPOSER "composer"

/* possible overlay formats */
typedef enum e_hwc_format
{
    HWC_FORMAT_MINVALUE     = 0x50,
    HWC_FORMAT_RGBA_8888    = 0x51,
    HWC_FORMAT_RGB_565      = 0x52,
    HWC_FORMAT_BGRA_8888    = 0x53,
    HWC_FORMAT_YCbYCr_422_I = 0x54,
    HWC_FORMAT_CbYCrY_422_I = 0x55,
    HWC_FORMAT_MBYUV420		= 0x56,
    HWC_FORMAT_MBYUV422		= 0x57,
    HWC_FORMAT_YUV420PLANAR	= 0x58,
    HWC_FORMAT_DEFAULT      = 0x99,    // The actual color format is determined
    HWC_FORMAT_MAXVALUE     = 0x100
}e_hwc_format_t;

typedef enum e_hwc_3d_src_mode
{
    HWC_3D_SRC_MODE_TB = 0x0,//top bottom
    HWC_3D_SRC_MODE_FP = 0x1,//frame packing
    HWC_3D_SRC_MODE_SSF = 0x2,//side by side full
    HWC_3D_SRC_MODE_SSH = 0x3,//side by side half
    HWC_3D_SRC_MODE_LI = 0x4,//line interleaved

    HWC_3D_SRC_MODE_NORMAL = 0xFF//2d
}e_hwc_3d_src_mode_t;

/* names for setParameter() */
typedef enum e_hwc_3d_out_mode{
    HWC_3D_OUT_MODE_2D 		            = 0x0,//left picture
    HWC_3D_OUT_MODE_HDMI_3D_1080P24_FP 	= 0x1,
    HWC_3D_OUT_MODE_ANAGLAGH 	        = 0x2,//*
    HWC_3D_OUT_MODE_ORIGINAL 	        = 0x3,//original pixture

    HWC_3D_OUT_MODE_LI                  = 0x4,//line interleaved
    HWC_3D_OUT_MODE_CI_1                = 0x5,//column interlaved 1
    HWC_3D_OUT_MODE_CI_2                = 0x6,//column interlaved 2
    HWC_3D_OUT_MODE_CI_3                = 0x7,//column interlaved 3
    HWC_3D_OUT_MODE_CI_4                = 0x8,//column interlaved 4

    HWC_3D_OUT_MODE_HDMI_3D_720P50_FP   = 0x9,
    HWC_3D_OUT_MODE_HDMI_3D_720P60_FP   = 0xa
}e_hwc_3d_out_mode_t;

/* names for setParameter() */
typedef enum e_hwc_layer_cmd{
    /* rotation of the source image in degrees (0 to 359) */
    HWC_LAYER_ROTATION_DEG  	= 1,
    /* enable or disable dithering */
    HWC_LAYER_DITHER        	= 3,
    /* transformation applied (this is a superset of COPYBIT_ROTATION_DEG) */
    HWC_LAYER_SETINITPARA = 4,
    /* set videoplayer init overlay parameter */
    HWC_LAYER_SETVIDEOPARA = 5,
    /* set videoplayer play frame overlay parameter*/
    HWC_LAYER_SETFRAMEPARA = 6,
    /* get videoplayer play frame overlay parameter*/
    HWC_LAYER_GETCURFRAMEPARA = 7,
    /* query video blank interrupt*/
    HWC_LAYER_QUERYVBI = 8,
    /* set overlay screen id*/
    HWC_LAYER_SETMODE = 9,

    HWC_LAYER_SHOW = 0xa,
    HWC_LAYER_RELEASE = 0xb,
    HWC_LAYER_SET3DMODE = 0xc,
    HWC_LAYER_SETFORMAT = 0xd,
    HWC_LAYER_VPPON = 0xe,
    HWC_LAYER_VPPGETON = 0xf,
    HWC_LAYER_SETLUMASHARP = 0x10,
    HWC_LAYER_GETLUMASHARP = 0x11,
    HWC_LAYER_SETCHROMASHARP = 0x12,
    HWC_LAYER_GETCHROMASHARP = 0x13,
    HWC_LAYER_SETWHITEEXTEN = 0x14,
    HWC_LAYER_GETWHITEEXTEN = 0x15,
    HWC_LAYER_SETBLACKEXTEN = 0x16,
    HWC_LAYER_GETBLACKEXTEN = 0x17,
    HWC_LAYER_SET_3D_PARALLAX = 0x18,
    HWC_LAYER_SET_SCREEN_PARA = 0x19,

	HWC_LAYER_SETTOP		= 0x1a,
	HWC_LAYER_SETBOTTOM		= 0x1b,

	HWC_LAYER_HDMI_OUT		= 0x1c,
}e_hwc_layer_cmd_t;

typedef enum e_hwc_mode
{
	HWC_MODE_SCREEN0                = 0,
	HWC_MODE_SCREEN1                = 1,
	HWC_MODE_SCREEN0_TO_SCREEN1     = 2,
	HWC_MODE_SCREEN0_AND_SCREEN1    = 3,
	HWC_MODE_SCREEN0_BE             = 4,
	HWC_MODE_SCREEN0_GPU            = 5,
}e_hwc_mode_t;

typedef struct tag_HWCLayerInitPara
{
	uint32_t		w;
	uint32_t		h;
	uint32_t		format;
	uint32_t		screenid;
}layerinitpara_t;

typedef struct tag_Video3DInfo
{
	unsigned int width;
	unsigned int height;
	e_hwc_format_t format;
	e_hwc_3d_src_mode_t src_mode;
	e_hwc_3d_out_mode_t display_mode;
}video3Dinfo_t;

typedef struct tag_LIBHWCLAYERPARA
{
    unsigned long   number;

    unsigned long   top_y;              // the address of frame buffer, which contains top field luminance
    unsigned long   top_c;              // the address of frame buffer, which contains top field chrominance
    unsigned long   bottom_y;           // the address of frame buffer, which contains bottom field luminance
    unsigned long   bottom_c;           // the address of frame buffer, which contains bottom field chrominance

    signed char     bProgressiveSrc;    // Indicating the source is progressive or not
    signed char     bTopFieldFirst;     // VPO should check this flag when bProgressiveSrc is FALSE
    unsigned long   flag_addr;          //dit maf flag address
    unsigned long   flag_stride;        //dit maf flag line stride
    unsigned char   maf_valid;
    unsigned char   pre_frame_valid;
    unsigned char   drm_flag;
}libhwclayerpara_t;


typedef struct screen_para
{
    unsigned int width[2];//screen total width
    unsigned int height[2];//screen total height
    unsigned int valid_width[2];//screen width that can be seen
    unsigned int valid_height[2];//screen height that can be seen
    unsigned int app_width[2];//the width that app use
    unsigned int app_height[2];//the height that app use
}screen_para_t;


/*****************************************************************************/


typedef struct hwc_color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} hwc_color_t;

typedef struct hwc_frect {
    float left;
    float top;
    float right;
    float bottom;
} hwc_frect_t;

typedef struct hwc_rect {
    int left;
    int top;
    int right;
    int bottom;
} hwc_rect_t;

typedef struct hwc_region {
    size_t numRects;
    hwc_rect_t const* rects;
} hwc_region_t;

/*
 * hwc_layer_t::transform values
 */
typedef enum {
    /* flip source image horizontally */
    HWC_TRANSFORM_FLIP_H = HAL_TRANSFORM_FLIP_H,
    /* flip source image vertically */
    HWC_TRANSFORM_FLIP_V = HAL_TRANSFORM_FLIP_V,
    /* rotate source image 90 degrees clock-wise */
    HWC_TRANSFORM_ROT_90 = HAL_TRANSFORM_ROT_90,
    /* rotate source image 180 degrees */
    HWC_TRANSFORM_ROT_180 = HAL_TRANSFORM_ROT_180,
    /* rotate source image 270 degrees clock-wise */
    HWC_TRANSFORM_ROT_270 = HAL_TRANSFORM_ROT_270,
    /* flip source image horizontally, the rotate 90 degrees clock-wise */
    HWC_TRANSFORM_FLIP_H_ROT_90 = HAL_TRANSFORM_FLIP_H | HAL_TRANSFORM_ROT_90,
    /* flip source image vertically, the rotate 90 degrees clock-wise */
    HWC_TRANSFORM_FLIP_V_ROT_90 = HAL_TRANSFORM_FLIP_V | HAL_TRANSFORM_ROT_90,
} hwc_transform_t;

/*******************************************************************************
 * Beyond this point are things only used by HWC1, which should be ignored when
 * implementing a HWC2 device
 ******************************************************************************/

enum {
    /* hwc_composer_device_t::set failed in EGL */
    HWC_EGL_ERROR = -1
};

/*
 * hwc_layer_t::hints values
 * Hints are set by the HAL and read by SurfaceFlinger
 */
enum {
    /*
     * HWC can set the HWC_HINT_TRIPLE_BUFFER hint to indicate to SurfaceFlinger
     * that it should triple buffer this layer. Typically HWC does this when
     * the layer will be unavailable for use for an extended period of time,
     * e.g. if the display will be fetching data directly from the layer and
     * the layer can not be modified until after the next set().
     */
    HWC_HINT_TRIPLE_BUFFER  = 0x00000001,

    /*
     * HWC sets HWC_HINT_CLEAR_FB to tell SurfaceFlinger that it should clear the
     * framebuffer with transparent pixels where this layer would be.
     * SurfaceFlinger will only honor this flag when the layer has no blending
     *
     */
    HWC_HINT_CLEAR_FB       = 0x00000002
};

/*
 * hwc_layer_t::flags values
 * Flags are set by SurfaceFlinger and read by the HAL
 */
enum {
    /*
     * HWC_SKIP_LAYER is set by SurfaceFlnger to indicate that the HAL
     * shall not consider this layer for composition as it will be handled
     * by SurfaceFlinger (just as if compositionType was set to HWC_OVERLAY).
     */
    HWC_SKIP_LAYER = 0x00000001,

    /*
     * HWC_IS_CURSOR_LAYER is set by surfaceflinger to indicate that this
     * layer is being used as a cursor on this particular display, and that
     * surfaceflinger can potentially perform asynchronous position updates for
     * this layer. If a call to prepare() returns HWC_CURSOR_OVERLAY for the
     * composition type of this layer, then the hwcomposer will allow async
     * position updates to this layer via setCursorPositionAsync().
     */
    HWC_IS_CURSOR_LAYER = 0x00000002
};

/*
 * hwc_layer_t::compositionType values
 */
enum {
    /* this layer is to be drawn into the framebuffer by SurfaceFlinger */
    HWC_FRAMEBUFFER = 0,

    /* this layer will be handled in the HWC */
    HWC_OVERLAY = 1,

    /* this is the background layer. it's used to set the background color.
     * there is only a single background layer */
    HWC_BACKGROUND = 2,

    /* this layer holds the result of compositing the HWC_FRAMEBUFFER layers.
     * Added in HWC_DEVICE_API_VERSION_1_1. */
    HWC_FRAMEBUFFER_TARGET = 3,

    /* this layer's contents are taken from a sideband buffer stream.
     * Added in HWC_DEVICE_API_VERSION_1_4. */
    HWC_SIDEBAND = 4,

    /* this layer's composition will be handled by hwcomposer by dedicated
       cursor overlay hardware. hwcomposer will also all async position updates
       of this layer outside of the normal prepare()/set() loop. Added in
       HWC_DEVICE_API_VERSION_1_4. */
    HWC_CURSOR_OVERLAY =  5
 };
/*
 * hwc_layer_t::blending values
 */
enum {
    /* no blending */
    HWC_BLENDING_NONE     = 0x0100,

    /* ONE / ONE_MINUS_SRC_ALPHA */
    HWC_BLENDING_PREMULT  = 0x0105,

    /* SRC_ALPHA / ONE_MINUS_SRC_ALPHA */
    HWC_BLENDING_COVERAGE = 0x0405
};

/* attributes queriable with query() */
enum {
    /*
     * Must return 1 if the background layer is supported, 0 otherwise.
     */
    HWC_BACKGROUND_LAYER_SUPPORTED      = 0,

    /*
     * Returns the vsync period in nanoseconds.
     *
     * This query is not used for HWC_DEVICE_API_VERSION_1_1 and later.
     * Instead, the per-display attribute HWC_DISPLAY_VSYNC_PERIOD is used.
     */
    HWC_VSYNC_PERIOD                    = 1,

    /*
     * Availability: HWC_DEVICE_API_VERSION_1_1
     * Returns a mask of supported display types.
     */
    HWC_DISPLAY_TYPES_SUPPORTED         = 2,
};

/* display attributes returned by getDisplayAttributes() */
enum {
    /* Indicates the end of an attribute list */
    HWC_DISPLAY_NO_ATTRIBUTE                = 0,

    /* The vsync period in nanoseconds */
    HWC_DISPLAY_VSYNC_PERIOD                = 1,

    /* The number of pixels in the horizontal and vertical directions. */
    HWC_DISPLAY_WIDTH                       = 2,
    HWC_DISPLAY_HEIGHT                      = 3,

    /* The number of pixels per thousand inches of this configuration.
     *
     * Scaling DPI by 1000 allows it to be stored in an int without losing
     * too much precision.
     *
     * If the DPI for a configuration is unavailable or the HWC implementation
     * considers it unreliable, it should set these attributes to zero.
     */
    HWC_DISPLAY_DPI_X                       = 4,
    HWC_DISPLAY_DPI_Y                       = 5,

    /* Indicates which of the vendor-defined color transforms is provided by
     * this configuration. */
    HWC_DISPLAY_COLOR_TRANSFORM             = 6,
};

/* Allowed events for hwc_methods::eventControl() */
enum {
    HWC_EVENT_VSYNC     = 0
};

/* Display types and associated mask bits. */
enum {
    HWC_DISPLAY_PRIMARY     = 0,
    HWC_DISPLAY_EXTERNAL    = 1,    // HDMI, DP, etc.
    HWC_DISPLAY_VIRTUAL     = 2,

    HWC_NUM_PHYSICAL_DISPLAY_TYPES = 2,
    HWC_NUM_DISPLAY_TYPES          = 3,
};

enum {
    HWC_DISPLAY_PRIMARY_BIT     = 1 << HWC_DISPLAY_PRIMARY,
    HWC_DISPLAY_EXTERNAL_BIT    = 1 << HWC_DISPLAY_EXTERNAL,
    HWC_DISPLAY_VIRTUAL_BIT     = 1 << HWC_DISPLAY_VIRTUAL,
};

/* Display power modes */
enum {
    /* The display is turned off (blanked). */
    HWC_POWER_MODE_OFF      = 0,
    /* The display is turned on and configured in a low power state
     * that is suitable for presenting ambient information to the user,
     * possibly with lower fidelity than normal but greater efficiency. */
    HWC_POWER_MODE_DOZE     = 1,
    /* The display is turned on normally. */
    HWC_POWER_MODE_NORMAL   = 2,
    /* The display is configured as in HWC_POWER_MODE_DOZE but may
     * stop applying frame buffer updates from the graphics subsystem.
     * This power mode is effectively a hint from the doze dream to
     * tell the hardware that it is done drawing to the display for the
     * time being and that the display should remain on in a low power
     * state and continue showing its current contents indefinitely
     * until the mode changes.
     *
     * This mode may also be used as a signal to enable hardware-based doze
     * functionality.  In this case, the doze dream is effectively
     * indicating that the hardware is free to take over the display
     * and manage it autonomously to implement low power always-on display
     * functionality. */
    HWC_POWER_MODE_DOZE_SUSPEND  = 3,
};

/*****************************************************************************/

__END_DECLS

#endif /* ANDROID_INCLUDE_HARDWARE_HWCOMPOSER_DEFS_H */
