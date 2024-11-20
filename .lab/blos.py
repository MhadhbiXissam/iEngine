import bpy , gpu , sys
import pip
pip.main(['install', 'grpcio'])
pip.main(['install', 'grpcio-tools'])
pip.main(['install', 'Pillow'])
sys.path.append("/root/workspace/iEngine/QBlender")
from PIL import Image
import io , PIL
import grpc
import blender_pb2
import blender_pb2_grpc
WIDTH = 512
HEIGHT = 256




def draw():
    context = bpy.context
    scene = context.scene

    view_matrix = scene.camera.matrix_world.inverted()

    projection_matrix = scene.camera.calc_matrix_camera(
        context.evaluated_depsgraph_get(), x=WIDTH, y=HEIGHT)
    offscreen = gpu.types.GPUOffScreen(WIDTH, HEIGHT)
    offscreen.draw_view3d(
        scene,
        context.view_layer,
        context.space_data,
        context.region,
        view_matrix,
        projection_matrix,
        do_color_management=True)

    gpu_texture = offscreen.texture_color
    print(f"width : {offscreen.texture_color.width}")
    width, height = gpu_texture.width , gpu_texture.height
    buffer = bytearray(width * height * 4)  # Assuming RGBA format

    # Read the pixel data into the buffer
    buffer = gpu_texture.read()

    # Convert the buffer to bytes
    pixel_data = bytes(buffer)
    print(pixel_data)

    channel = grpc.insecure_channel('localhost:50051')
    stub = blender_pb2_grpc.ImageServiceStub(channel)


    # Create a Viewport message with the image data, width, and height
    request = blender_pb2.Viewport(
        image_data=pixel_data ,
        width=WIDTH,
        height=WIDTH
    )

    # Send the image to the server
    response = stub.ReceiveImage(request)

    # Print the server's response
    print(response.message)



bpy.types.SpaceView3D.draw_handler_add(draw, (), 'WINDOW', 'POST_PIXEL')
#/root/workspace/iEngine/.downloads/blender-4.2.0-linux-x64/blender -P /root/workspace/iEngine/.lab/blos.py