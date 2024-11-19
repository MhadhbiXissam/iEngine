import bpy
import sys
sys.path.append("/home/issam/Desktop/__VED__/grpcblender")
from PIL import Image
import io
import grpc
import blender_pb2
import blender_pb2_grpc

def my_timer_function():
    # Connect to the server
    channel = grpc.insecure_channel('localhost:50051')
    stub = blender_pb2_grpc.ImageServiceStub(channel)

    # Specify the image filename
    bpy.ops.screen.screenshot(filepath='/tmp/screenshot.png')  # Save the screenshot to a file
    filename = '/tmp/screenshot.png'

    # Read the image file to send
    with open(filename, 'rb') as f:
        image_data = f.read()

    # Get the image dimensions (width and height)
    with Image.open(filename) as img:
        width, height = img.size

    # Create a Viewport message with the image data, width, and height
    request = blender_pb2.Viewport(
        image_data=image_data,
        width=width,
        height=height
    )

    # Send the image to the server
    response = stub.ReceiveImage(request)

    # Print the server's response
    print(response.message)
    return 0.05

# Register the timer function
bpy.app.timers.register(my_timer_function)

# To unregister the timer function when it's no longer needed
# bpy.app.timers.unregister(my_timer_function)
