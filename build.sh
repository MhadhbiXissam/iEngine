set -e -x 
pip install -r requirements.txt
pushd QBlender
python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. blender.proto
popd 