import bpy

# Create a new Blender file
bpy.ops.wm.read_factory_settings(use_empty=True)

# Create a new mesh and object
mesh = bpy.data.meshes.new(name="RectangleMesh")
obj = bpy.data.objects.new(name="Rectangle", object_data=mesh)

# Link the object to the scene
bpy.context.collection.objects.link(obj)

# Define the vertices and faces of the rectangle
vertices = [(1, 1, 0), (1, -1, 0), (-1, -1, 0), (-1, 1, 0)]
faces = [(0, 1, 2, 3)]

# Create the mesh from the vertices and faces
mesh.from_pydata(vertices, [], faces)
mesh.update()

# Save the Blender file
bpy.ops.wm.save_as_mainfile(filepath="rectangle.blend")
