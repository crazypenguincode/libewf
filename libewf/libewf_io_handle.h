/*
 * IO handle functions
 *
 * Copyright (c) 2006-2012, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBEWF_IO_HANDLE_H )
#define _LIBEWF_IO_HANDLE_H

#include <common.h>
#include <types.h>

#include "libewf_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libewf_io_handle libewf_io_handle_t;

struct libewf_io_handle
{
	/* The access flags
	 */
	int access_flags;

	/* The current (storage media) offset
	 */
	off64_t current_offset;

	/* The segment file type
	 */
	uint8_t segment_file_type;

	/* Value to indicate which file format is used
	 */
	uint8_t format;

/* TODO deprecate */
	/* Value to indicate which ewf format is used
	 */
	uint8_t ewf_format;

	/* The format major version
	 */
	uint8_t major_version;

	/* The format minor version
	 */
	uint8_t minor_version;

	/* Value to indicate the compression level used
	 */
	int8_t compression_level;

	/* Value to indicate certain compression modes
	 * like empty block compression
	 */
	uint8_t compression_flags;

	/* Value to indicate compression is forces
	 * Used by EWF-S01
	 */
	uint8_t force_compression;

	/* Value to indicate the data and some metadata is encrypted
	 */
	uint8_t is_encrypted;

	/* The header codepage
	 */
	int header_codepage;

	/* Value to indicate if abort was signalled
	 */
	int abort;
};

int libewf_io_handle_initialize(
     libewf_io_handle_t **io_handle,
     libcerror_error_t **error );

int libewf_io_handle_free(
     libewf_io_handle_t **io_handle,
     libcerror_error_t **error );

int libewf_io_handle_clone(
     libewf_io_handle_t **destination_io_handle,
     libewf_io_handle_t *source_io_handle,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

