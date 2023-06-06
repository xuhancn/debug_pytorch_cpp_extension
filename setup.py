import os
import torch
from setuptools import setup

from torch.utils.cpp_extension import BuildExtension, CppExtension

torch_path = os.path.dirname(torch.__file__)
print(torch_path)

PACKAGE_NAME = "dummy_ext"

setup(
    name='PACKAGE_NAME',
    ext_modules=[
        CppExtension('mod_test_add_ninja', [
            'src/main.cpp',
        ], extra_compile_args=[])
    ],
    cmdclass={
        'build_ext': BuildExtension.with_options(use_ninja=True)
    }
)