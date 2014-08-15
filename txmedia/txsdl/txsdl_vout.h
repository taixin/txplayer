/*****************************************************************************
 * txsdl_vout.h
 *****************************************************************************
 *
 * copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of txPlayer.
 *
 * txPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * txPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with txPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef TXSDL__TXSDL_VOUT_H
#define TXSDL__TXSDL_VOUT_H

#include "txsdl_stdinc.h"
#include "txsdl_mutex.h"
#include "txsdl_video.h"

typedef struct SDL_VoutOverlay_Opaque SDL_VoutOverlay_Opaque;
typedef struct SDL_VoutOverlay SDL_VoutOverlay;
typedef struct SDL_VoutOverlay {
    int w; /**< Read-only */
    int h; /**< Read-only */
    Uint32 format; /**< Read-only */
    int planes; /**< Read-only */
    Uint16 *pitches; /**< in bytes, Read-only */
    Uint8 **pixels; /**< Read-write */

    void *opaque;
    void (*free_l)(SDL_VoutOverlay *overlay);
    int (*lock)(SDL_VoutOverlay *overlay);
    int (*unlock)(SDL_VoutOverlay *overlay);
} SDL_VoutOverlay;

typedef struct SDL_Vout_Opaque SDL_Vout_Opaque;
typedef struct SDL_Vout SDL_Vout;
typedef struct SDL_Vout {
    SDL_mutex *mutex;

    SDL_Vout_Opaque *opaque;
    SDL_VoutOverlay *(*create_overlay)(int width, int height, Uint32 format, SDL_Vout *vout);
    void (*free_l)(SDL_Vout *vout);
    int (*display_overlay)(SDL_Vout *vout, SDL_VoutOverlay *overlay);
} SDL_Vout;

void SDL_VoutFree(SDL_Vout *vout);
void SDL_VoutFreeP(SDL_Vout **pvout);
int SDL_VoutDisplayYUVOverlay(SDL_Vout *vout, SDL_VoutOverlay *overlay);

SDL_VoutOverlay *SDL_Vout_CreateOverlay(int width, int height, Uint32 format, SDL_Vout *vout);
int SDL_VoutLockYUVOverlay(SDL_VoutOverlay *overlay);
int SDL_VoutUnlockYUVOverlay(SDL_VoutOverlay *overlay);
void SDL_VoutFreeYUVOverlay(SDL_VoutOverlay *overlay);

#endif
