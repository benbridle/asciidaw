asciidaw: main.cpp fracture/* fracture/components/* seismic/components/*
	g++ -g main.cpp seismic/components/Session.cpp seismic/components/tiny_xml_2/tinyxml2.cpp -l rtaudio -l stdc++fs -Wno-return-type -o asciidaw

tapedeck: tapedeck.cpp
	g++ -g tapedeck.cpp seismic/components/tiny_xml_2/tinyxml2.cpp seismic/components/Session.cpp -std=c++2a -o tapedeck -l rtaudio