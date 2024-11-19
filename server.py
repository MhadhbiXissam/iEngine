import grpc
import blender_pb2
import blender_pb2_grpc
from concurrent import futures
from PIL import Image
import io

class ImageService(blender_pb2_grpc.ImageServiceServicer):
    def ReceiveImage(self, request, context):
        image_data = request.image_data
        width = request.width
        height = request.height
        
        # Save the received image using the image data
        with open("received_image.jpg", 'wb') as f:
            f.write(image_data)

        # Return a response indicating success
        return blender_pb2.ImageResponse(
            message=f"Image received successfully with dimensions {width}x{height}."
        )

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    blender_pb2_grpc.add_ImageServiceServicer_to_server(ImageService(), server)
    server.add_insecure_port('[::]:50051')
    print("Server started on port 50051")
    server.start()
    server.wait_for_termination()

if __name__ == '__main__':
    serve()
