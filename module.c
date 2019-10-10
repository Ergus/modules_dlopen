/*
 * Copyright (C) 2019  Jimmy Aguilar Mena
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include "main.h"

// FUnction defined in the module. It will be assigned in the init_module
// function.
void print_lib (void)
{
	printf ("Printing from Library %s\n", MNAME);
}

// This will be executed before dlopen returns
void __attribute__ ((constructor)) my_init(void)
{
	printf ("Load module %s\n", MNAME);
}

// This will be executed before dlclose returns.
void __attribute__ ((destructor)) my_fini(void)
{
	printf ("Unload module %s\n", MNAME);
}

// Function to initialize the module.
// Will be called after dlopen.
void init_module ()
{
	printf ("Executing loader %s\n", MNAME);
	set_ptr (&print_lib);  // Call a function in the caller program.
}
