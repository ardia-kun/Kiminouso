/* Copyright (c) 2015-2016, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __MSM_COMMON
#define __MSM_COMMON

#include <sound/soc.h>
#include <sound/q6afe-v2.h>
#include "../codecs/wcd-mbhc-v2.h"

#define SAMPLING_RATE_8KHZ      8000
#define SAMPLING_RATE_11P025KHZ 11025
#define SAMPLING_RATE_16KHZ     16000
#define SAMPLING_RATE_22P05KHZ  22050
#define SAMPLING_RATE_32KHZ     32000
#define SAMPLING_RATE_44P1KHZ   44100
#define SAMPLING_RATE_48KHZ     48000
#define SAMPLING_RATE_88P2KHZ   88200
#define SAMPLING_RATE_96KHZ     96000
#define SAMPLING_RATE_176P4KHZ  176400
#define SAMPLING_RATE_192KHZ    192000
#define SAMPLING_RATE_352P8KHZ  352800
#define SAMPLING_RATE_384KHZ    384000

extern const struct snd_kcontrol_new msm_common_snd_controls[];
struct msmfalcon_codec {
	void* (*get_afe_config_fn)(struct snd_soc_codec *codec,
				   enum afe_config_type config_type);
};

struct msm_asoc_mach_data {
	int us_euro_gpio; /* used by gpio driver API */
	int hph_en1_gpio;
	int hph_en0_gpio;
	struct device_node *us_euro_gpio_p; /* used by pinctrl API */
	struct device_node *hph_en1_gpio_p; /* used by pinctrl API */
	struct device_node *hph_en0_gpio_p; /* used by pinctrl API */
	struct snd_soc_codec *codec;
	struct msmfalcon_codec msmfalcon_codec_fn;
	struct snd_info_entry *codec_root;
	int spk_ext_pa_gpio;
	int mclk_freq;
	int lb_mode;
	u8 micbias1_cap_mode;
	u8 micbias2_cap_mode;
	atomic_t int_mclk0_rsc_ref;
	atomic_t int_mclk0_enabled;
	struct mutex cdc_int_mclk0_mutex;
	struct delayed_work disable_int_mclk0_work;
	struct afe_clk_set digital_cdc_core_clk;
	bool int_codec;
};

int msm_common_be_hw_params_fixup(struct snd_soc_pcm_runtime *rtd,
				  struct snd_pcm_hw_params *params);
int msm_aux_pcm_snd_startup(struct snd_pcm_substream *substream);
void msm_aux_pcm_snd_shutdown(struct snd_pcm_substream *substream);
int msm_mi2s_snd_startup(struct snd_pcm_substream *substream);
void msm_mi2s_snd_shutdown(struct snd_pcm_substream *substream);
#endif