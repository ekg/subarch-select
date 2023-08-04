LDFLAGS := $(LDFLAGS) -lcpu_features
prefix = /usr/local
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
CPPFLAGS := $(CPPFLAGS) -Icpu_features/include

all: subarch-select

subarch-select: main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< $(LDFLAGS)

clean:
	$(RM) -f subarch-select

install:
	cp subarch-select ${bindir}/

.PHONY: clean
