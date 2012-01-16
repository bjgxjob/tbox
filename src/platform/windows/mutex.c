/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2011, ruki All rights reserved.
 *
 * \author		ruki
 * \file		mutex.c
 *
 */

/* /////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#include <windows.h>

/* /////////////////////////////////////////////////////////
 * implemention
 */

tb_handle_t tb_mutex_init(tb_char_t const* name)
{
	HANDLE handle = CreateMutex(NULL, FALSE, name);
	return ((handle != INVALID_HANDLE_VALUE)? handle : TB_NULL);
}
tb_void_t tb_mutex_exit(tb_handle_t handle)
{
	if (handle) CloseHandle(handle);
}
tb_bool_t tb_mutex_enter(tb_handle_t handle)
{
	if (handle && WAIT_OBJECT_0 == WaitForSingleObject(handle, INFINITE)) return TB_TRUE;
	return TB_FALSE;
}
tb_bool_t tb_mutex_leave(tb_handle_t handle)
{
	if (handle) return ReleaseMutex(handle)? TB_TRUE : TB_FALSE;
	return TB_FALSE;
}