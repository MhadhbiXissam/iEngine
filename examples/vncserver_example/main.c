#include "rfb/rfb.h"

int main(int argc, char** argv) {
    int width = 800, height = 600, bpp = 4;
    rfbScreenInfoPtr server = rfbGetScreen(&argc, argv, width, height, 8, 3, bpp);
    server->port = 5910; // Custom display port
    server->frameBuffer = (char*)malloc(width * height * bpp);
    server->alwaysShared = TRUE;

    // Initialize the framebuffer with some content
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int offset = (y * width + x) * bpp;
            server->frameBuffer[offset] = x % 256;     // Red
            server->frameBuffer[offset + 1] = y % 256; // Green
            server->frameBuffer[offset + 2] = (x + y) % 256; // Blue
            server->frameBuffer[offset + 3] = 255;     // Alpha
        }
    }

    rfbInitServer(server);
    rfbRunEventLoop(server, -1, FALSE);

    free(server->frameBuffer);
    return 0;
}
