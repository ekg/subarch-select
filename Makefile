LDFLAGS := $(LDFLAGS) -lcpu_features
prefix = /usr/local
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
CPPFLAGS := $(CPPFLAGS) -Icpu_features/include

all: subarch-select subarch-list

subarch-select: main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< $(LDFLAGS)

subarch-list: subarch-list.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< $(LDFLAGS)

clean:
	$(RM) -f subarch-select subarch-list

install:
	cp subarch-select ${bindir}/
	cp subarch-list ${bindir}/

.PHONY: clean
