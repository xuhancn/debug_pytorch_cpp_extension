import os
import torch
from setuptools import setup

import time

from torch.utils.cpp_extension import BuildExtension, CppExtension

torch_path = os.path.dirname(torch.__file__)
print(torch_path)

PACKAGE_NAME = "inductor_entry"

start = time.time()
print('!!!!!compiling start.')
setup(
    name=PACKAGE_NAME,
    ext_modules=[
        CppExtension(PACKAGE_NAME, [
            'src/inductor_entry.cpp',
        ], extra_compile_args=[])
    ],
    cmdclass={
        'build_ext': BuildExtension.with_options(use_ninja=True)
    }
)
end = time.time()
print('!!!!!compiling time: ',end - start)