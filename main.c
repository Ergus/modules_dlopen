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
#include <dlfcn.h>

void (*fun_ptr)(void) = NULL;

void set_ptr (void (*in)(void))
{
	printf ("Executing set_ptr\n");
	fun_ptr = in;
}

void print_main ()
{
	printf ("Printing from main\n");
}

int main ()
{
	void (*loader) (void);

	void *module = dlopen("./libmodule.so", RTLD_LAZY);

	loader = (void (*)(void)) dlsym (module, "init_module");
	(*loader)();

	(*fun_ptr)();

	return 0;
}
