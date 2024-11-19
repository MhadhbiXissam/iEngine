pushd .downloads
git clone https://github.com/LibVNC/libvncserver.git
cd libvncserver
mkdir build
cd build
cmake ..
cmake --build .
popd 
cp .downloads/libvncserver/build/libvncserver.so libs/
cp .downloads/libvncserver/build/libvncclient.so libs/
cp -r .downloads/libvncserver/build/include/rfb include
cp -r .downloads/libvncserver/build/include/rfb include
cp .downloads/libvncserver/include/rfb/*  include/rfb/