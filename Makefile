# Copyright (C) 2019  Jimmy Aguilar Mena

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

files:= main.x libmodule1.so libmodule2.so

all: $(files)

%.x: main.c
	$(CC) main.c -o main.x -ldl -rdynamic

%.o: module.c
	$(CC) -DMNAME=\"$@\" -c -fpic $< -o $@

lib%.so: %.o
	$(CC) -shared $^ -o $@

.PHONY: test clean

test: $(files)
	./main.x

clean:
	rm -rf *.so *.o *.x
