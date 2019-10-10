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

void (*fun_ptr[2])(void);
int cont = 0;

void set_ptr (void (*in)(void))
{
	printf ("Executing set_ptr\n");
	fun_ptr[cont++] = in;
}


int main ()
{
	int i;
	void (*loader) (void);   // pointer to loader
	char filename[32];       // string filename
	void (*modules[2]);      // Array of handlers

	for (i = 0; i < 2; ++i) {
		sprintf (filename, "./libmodule%d.so", i + 1);
		printf ("Call dlopen %s\n", filename);
		modules[i] = dlopen(filename, RTLD_LAZY);

		loader = (void (*)(void)) dlsym (modules[i], "init_module");
		(*loader)();
	}

	for (i = 0; i < 2; ++i)
		(*fun_ptr[i])();


	for (i = 0; i < 2; ++i) {
		printf ("Call dlclose %d\n", i);
		dlclose (modules[i]);
	}

	return 0;
}
