git clone https://github.com/libsdl-org/SDL
cd SDL
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --parallel
sudo cmake --install . --config Release
