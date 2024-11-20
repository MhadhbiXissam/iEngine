import bpy
import gpu
from gpu_extras.presets import draw_texture_2d

WIDTH = 512
HEIGHT = 256

offscreen = gpu.types.GPUOffScreen(WIDTH, HEIGHT)


def draw():
    context = bpy.context
    scene = context.scene

    view_matrix = scene.camera.matrix_world.inverted()

    projection_matrix = scene.camera.calc_matrix_camera(
        context.evaluated_depsgraph_get(), x=WIDTH, y=HEIGHT)

    offscreen.draw_view3d(
        scene,
        context.view_layer,
        context.space_data,
        context.region,
        view_matrix,
        projection_matrix,
        do_color_management=True)

    gpu.state.depth_mask_set(False)
    [print(i) for i in dir(offscreen)]
    print("*"*60)
    print(type(offscreen.texture_color))
    draw_texture_2d(offscreen.texture_color, (10, 10), WIDTH, HEIGHT)


bpy.types.SpaceView3D.draw_handler_add(draw, (), 'WINDOW', 'POST_PIXEL')