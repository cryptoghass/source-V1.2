
Debian
====================
This directory contains files used to package pandorad/pandora-qt
for Debian-based Linux systems. If you compile pandorad/pandora-qt yourself, there are some useful files here.

## pandora: URI support ##


pandora-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install pandora-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your pandoraqt binary to `/usr/bin`
and the `../../share/pixmaps/pandora128.png` to `/usr/share/pixmaps`

pandora-qt.protocol (KDE)

