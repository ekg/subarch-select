LDFLAGS := $(LDFLAGS) -lcpu_features

subarch-select: main.cpp
	g++ $(CXXFLAGS) -o $@ $< $(LDFLAGS)
