import os
import torch
from setuptools import setup

import time

from torch.utils.cpp_extension import BuildExtension, CppExtension

torch_path = os.path.dirname(torch.__file__)
print(torch_path)

PACKAGE_NAME = "combine_inductor"

include_dirs = [
    os.path.realpath("."),
    os.path.join(torch_path, "include"),
    os.path.join(torch_path, "include", "torch", "csrc", "api", "include"),
]

library_dirs = ["lib", os.path.join(torch_path, "lib")]

start = time.time()
print('!!!!!compiling start.')
setup(
    name=PACKAGE_NAME,
    ext_modules=[
        CppExtension(PACKAGE_NAME, [
            'src_1/cpp_0.cpp',
            'src_1/cpp_1.cpp',
            'src_1/cpp_2.cpp',
            'src_1/pybinder.cpp',
        ],
        include_dirs=include_dirs,
        library_dirs=library_dirs,
        extra_compile_args=[])
    ],
    cmdclass={
        'build_ext': BuildExtension.with_options(use_ninja=True)
    }
)
end = time.time()
print('!!!!!compiling time: ',end - start)