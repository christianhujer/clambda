# Copyright (C) 2015 Christian Hujer.
# All rights reserved.
# Licensed under LGPLv3.
# See file LICENSE in the root directory of this project.

## Installation prefix.
PREFIX=/usr/local/

## Installation directory for include files.
INCDIR=$(PREFIX)/include/

.PHONY: all
all:
	echo "No build required. Maybe try 'make install' for installation."

.PHONY: install
## Installs clambda on your system.
install:
	install -d $(INCDIR)
	install -t $(INCDIR) clambda.h

.PHONY: uninstall
## Removes clambda from your system.
uninstall:
	$(RM) $(INCDIR)/clambda.h

control.Description=clambda - poor C programmer\'s pseudo lambda for a little bit of functional programming in C. Requires statement expressions and nested functions, therefore works in GCC only.
-include makedist/MakeDist.mak

-include makehelp/Help.mak
