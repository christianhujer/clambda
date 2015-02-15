# Copyright (C) 2015 Christian Hujer.
# All rights reserved.
# Licensed under LGPLv3.
# See file LICENSE in the root directory of this project.

## Installation prefix.
PREFIX=/usr/local/

## Installation directory for include files.
INCDIR=$(PREFIX)/include/

## Installation directory for man pages.
MANDIR=$(PREFIX)/man/

.PHONY: all
all:
	echo "No build required. Maybe try 'make install' for installation."

.PHONY: install
## Installs clambda on your system.
install:
	install -d $(INCDIR) $(MANDIR)/man3/
	install -t $(INCDIR) include/clambda.h
	install -m 0644 -t $(MANDIR)/man3/ man/man3/clambda.3

.PHONY: uninstall
## Removes clambda from your system.
uninstall:
	$(RM) $(INCDIR)/clambda.h $(MANDIR)/man3/clambda.3

control.Description=clambda - poor C programmer\'s pseudo lambda for a little bit of functional programming in C. Requires statement expressions and nested functions, therefore works in GCC only.
-include makedist/MakeDist.mak

-include makehelp/Help.mak
