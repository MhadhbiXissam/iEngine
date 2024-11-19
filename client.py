import grpc
import blender_pb2
import blender_pb2_grpc
from PIL import Image
import io

def run():
    # Connect to the server
    channel = grpc.insecure_channel('localhost:50051')
    stub = blender_pb2_grpc.ImageServiceStub(channel)

    # Specify the image filename
    filename = "x.jpg"

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

if __name__ == '__main__':
    run()
