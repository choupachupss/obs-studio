/******************************************************************************
    Copyright (C) 2013 by Hugh Bailey <obs.jim@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#pragma once

#include <util/c99defs.h>
#include <obs.h>
#include <x264.h>

struct obs_x264 {
	obs_encoder_t  encoder;

	x264_param_t   params;
	x264_t         *context;
	x264_picture_t pic_out;
};

EXPORT const char *obs_x264_getname(const char *locale);

EXPORT struct obs_x264 *obs_x264_create(obs_data_t settings,
		obs_encoder_t encoder);
EXPORT void obs_x264_destroy(struct obs_x264 *data);

EXPORT void obs_x264_update(struct obs_x264 *data, obs_data_t settings);

EXPORT void obs_x264_reset(struct obs_x264 *data);

EXPORT int obs_x264_encode(struct obs_x264 *data,
		struct encoder_packet **packets);
EXPORT int obs_x264_getheader(struct obs_x264 *data,
		struct encoder_packet **packets);

EXPORT void obs_x264_setbitrate(struct obs_x264 *data, uint32_t bitrate,
		uint32_t buffersize);
EXPORT void obs_x264_request_keyframe(struct obs_x264 *data);
