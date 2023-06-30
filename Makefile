LDFLAGS := $(LDFLAGS) -lcpu_features

subarch-select: main.cpp
	g++ $(CXXFLAGS) $(CPPFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f subarch-select

.PHONY: clean
