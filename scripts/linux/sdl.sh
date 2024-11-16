set -e -x 
mkdir -p .tmp || true 
pushd .tmp 
mkdir -p linux || true 
cd linux 
rm -rf .tmp/linux/SDL || true 
git clone https://github.com/libsdl-org/SDL
cd SDL
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --parallel
#sudo cmake --install . --config Release
popd 
cp -rf .tmp/linux/SDL/include/* include
cp .tmp/linux/SDL/build/libSDL3.so lib/linux
cp -rf .tmp/linux/SDL/docs docs/SDL
rm -rf .tmp/linux/SDL || true 
