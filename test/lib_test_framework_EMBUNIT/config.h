/*
 * COPYRIGHT AND PERMISSION NOTICE
 * 
 * Copyright (c) 2003 Embedded Unit Project
 * 
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the 
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, and/or sell copies of the Software, and to permit persons 
 * to whom the Software is furnished to do so, provided that the above 
 * copyright notice(s) and this permission notice appear in all copies 
 * of the Software and that both the above copyright notice(s) and this 
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT 
 * OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY 
 * SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER 
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF 
 * CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 * Except as contained in this notice, the name of a copyright holder 
 * shall not be used in advertising or otherwise to promote the sale, 
 * use or other dealings in this Software without prior written 
 * authorization of the copyright holder.
 *
 * $Id: config.h,v 1.7 2004/02/10 16:17:07 arms22 Exp $
 */
#ifndef __CONFIG_H__
#define __CONFIG_H__

/*	#define NO_STDIO_PRINTF*/
	#ifdef	NO_STDIO_PRINTF
		extern void stdimpl_print(const char *string);
	#elif TTY_PORTMUX
		#include<libStreamRouter.h>
		#define stdimpl_print(...) libStreamRouter_Print(STREAM_control,__VA_ARGS__)
	#else
		#include<stdio.h>
		#define stdimpl_print printf
	#endif


	#ifdef	NO_STDIO_VPRINTF
		extern void stdimpl_print(const char *string);
	#elif TTY_PORTMUX
		#define stdimpl_vprintf(format, arglist) libStreamRouter_Vprint(STREAM_control,format,arglist)
	#else
		#define stdimpl_vprintf vprintf
	#endif
	
	#ifdef NO_STDIO_SPRINTF
	//	extern void stdimpl_sprintf(char *buffer, size_t size, const char* _fmt, ...);
	#elif MINI_PRINTF
		#include <mini-printf.h>
		#define stdimpl_sprintf(buffer, size, format,...) mini_snprintf(buffer,size,format,__VA_ARGS__)
	#else
		#include<stdio.h>
		#define stdimpl_sprintf(buffer, size, format,...) sprintf(buffer,format,__VA_ARGS__)

	#endif

	#define ASSERT_STRING_BUFFER_MAX	64

#endif/*__CONFIG_H__*/
