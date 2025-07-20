CC = gcc
CFLAGS = -Wall -O2
LIBS = -lX11 -lXtst
TARGET = numlockctl
SRC = numlockctl.c
PKGNAME = numlockctl_1.0.0
DEBFILE = $(PKGNAME).deb

.PHONY: all clean deb

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -f $(TARGET)
	rm -f $(DEBFILE)
	rm -rf $(PKGNAME)

deb: all
	@echo "Creating directory structure for .deb..."
	rm -rf $(PKGNAME)
	mkdir -p $(PKGNAME)/usr/bin
	mkdir -p $(PKGNAME)/DEBIAN
	cp $(TARGET) $(PKGNAME)/usr/bin/
	cp ./control $(PKGNAME)/DEBIAN/control
	dpkg-deb --build $(PKGNAME)
	@echo "Package $(DEBFILE) created successfully."
