/**
* HaxeFS - PhysicsFS bindings for Haxe
*
* The MIT License (MIT)
*
* Copyright (c) 2015 Aaron M. Shea
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#ifndef _LINC_HAXEFS_H_
#define _LINC_HAXEFS_H_

#pragma once
#define IMPLEMENT_API
#include <hxcpp.h>

#if (defined __MWERKS__)
#include <SIOUX.h>
#endif

#if (defined PHYSFS_HAVE_READLINE)
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#endif

#include "physfs.h"
#include <string>

namespace linc {

	namespace haxefs {
		
		// Must be called before any other function
		extern void fsinit(::String baseExePath);

		// Should be called before Haxe application closes
		extern void fsdeinit();

		/*
		* Mounts an archive or a directory
		* path - the archive/directory to mount
		* mntPaht - the virtual path to mount the archive at
		* append - append this to the current context?
		*/
		extern bool fsmnt(::String path, ::String mntPath, ::Bool append = false);

		/*
		* Unmount the directory or archive from the virtual filesystem
		* path - the virtual path to unmount
		*/
		extern bool fsumnt(::String path);

		/*
		* Returns string array of files in the virtual path specified
		*/
		extern ::Array<::String> fslist(::String path);

		/**
		* Check to see if this file exists in the mounted filesystem
		*/
		extern bool fsexist(::String path);

		/**
		* Gets the byte content from a file
		*/
		extern ::Array<Int> fsread(::String path);

		/*
		* Debug - Lists files in virtual path
		*/
		extern void debug_ls(::String path);

		/*
		* Get the last error from PhysicsFS
		*/
		extern ::String fsgeterr();

	}

}

#endif