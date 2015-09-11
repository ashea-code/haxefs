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

#include "linc_physfs.h"

namespace linc {

	namespace haxefs
	{

		// Must be called before any other function
		void fsinit(::String baseExePath)
		{
			if (!PHYSFS_init(baseExePath.c_str()))
			{
				printf("HaxeFS: PHYSFS_init() failed!\n  reason: %s.\n", PHYSFS_getLastError());
			}
		}

		// Should be called before Haxe application closes
		void fsdeinit()
		{
			PHYSFS_deinit();
		}

		/*
		* Mounts an archive or a directory
		* path - the archive/directory to mount
		* mntPaht - the virtual path to mount the archive at
		* append - append this to the current context?
		*/
		bool fsmnt(::String path, ::String mntPath, ::Bool append)
		{
			// Let's try and mount the archive
			if (PHYSFS_mount(path.__CStr(), mntPath.__CStr(), append))
			{
				return true;
			}
			else
			{
				printf("Failure. reason: %s.\n", PHYSFS_getLastError());
				return false;
			}
		}

		/*
		* Unmount the directory or archive from the virtual file system
		* path - the virtual path to unmount
		*/
		bool fsumnt(::String path)
		{
			if (PHYSFS_removeFromSearchPath(path.__CStr()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		/*
		* Returns string array of files in the virtual path specified
		*/
		::Array< ::String> fslist(::String path)
		{
			::Array< ::String> retArray = Array_obj< ::String>::__new();

			char **rc;
			rc = PHYSFS_enumerateFiles(path.__CStr());
			int file_count;
			char **i;
			for (i = rc, file_count = 0; *i != NULL; i++, file_count++)
			{
				retArray->__SetSize(file_count);
				retArray->__push(::String(*i));
			}

			return retArray;
		}

		/**
		* Check to see if this file exists in the mounted file system
		*/
		bool fsexist(::String path)
		{
			if (PHYSFS_exists(path.__CStr()))
			{
				return true;
			}

			return false;
		}

		/**
		* Check if a specific path is a directory
		*/
		bool fsisdir(::String path)
		{
			if(PHYSFS_isDirectory(path.__CStr()))
			{
				return true;
			}

			return false;
		}

		/**
		* Gets the text content from a file
		*/
		::Array< ::Int> fsread(::String path)
		{
			if (PHYSFS_exists(path.__CStr()))
			{
				// Get a handle to the file
				PHYSFS_File* f = PHYSFS_openRead(path.__CStr());

				char *buf;
				buf = new char[PHYSFS_fileLength(f)];
				int length_read = PHYSFS_read(f, buf, 1, PHYSFS_fileLength(f));

				::Array< ::Int> dataArr = Array_obj< ::Int>::__new(length_read);
				for (int i = 0; i < length_read; i++)
				{
					dataArr->__SetItem(i, ::Int(buf[i]));
				}

				PHYSFS_close(f);

				delete buf;

				return dataArr;
			}

			return NULL;
		}

		/*
		* Sets the write directory of PhysFS
		*/
		bool fssetwrite(::String path)
		{
			if(!PHYSFS_setWriteDir(path.__CStr()))
			{
				return false;
			}

			return true;
		}

		/**
		* Returns the current write directory
		*/
		::String fsgetwrite()
		{
			return ::String(PHYSFS_getWriteDir());
		}

		/*
		* Debug - Lists files in virtual path
		*/
		void debug_ls(::String path)
		{
			char **rc;
			rc = PHYSFS_enumerateFiles(path.__CStr());
			int file_count;
			char **i;
			for (i = rc, file_count = 0; *i != NULL; i++, file_count++)
				printf("%s\n", *i);

			printf("\n total (%d) files.\n", file_count);
			PHYSFS_freeList(rc);
		}

		/*
		* Get the last error from PhysicsFS
		*/
		::String fsgeterr()
		{
			return ::String(PHYSFS_getLastError());
		}
	}

}

