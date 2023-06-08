#include <torch/extension.h>
#include <ATen/cpu/vec/vec.h>

//#include "/tmp/torchinductor_xu/lr/clrlgu27q4ggd472umdzwsu6qcpqxcuusjxqvx2hwitjbujiiz7z.h"
extern "C" void cpp_fused_relu_0(const float* in_ptr0,
                       float* out_ptr0)
{
    {
        for(long i0=static_cast<long>(0L); i0<static_cast<long>(9216L); i0+=static_cast<long>(8L))
        {
            auto tmp0 = at::vec::Vectorized<float>::loadu(in_ptr0 + static_cast<long>(i0));
            auto tmp1 = at::vec::clamp_min(tmp0, decltype(tmp0)(0));
            tmp1.store(out_ptr0 + static_cast<long>(i0));
        }
    }
}
std::vector<at::Tensor> inductor_entry_cpp_0(const std::vector<at::Tensor>& args) {
    at::Tensor arg0_1 = args[0];

    c10::optional<at::Scalar> optional_scalar;
    c10::optional<c10::string_view> optional_string;
    torch::List<c10::optional<at::Scalar>> optional_list;
        auto buf0 = at::empty_strided({2L, 512L, 3L, 3L}, {4608L, 1L, 1536L, 512L}, at::device(at::kCPU).dtype(at::kFloat));
        cpp_fused_relu_0((float*)(arg0_1.data_ptr()), (float*)(buf0.data_ptr()));
        arg0_1.reset();
        return {buf0};
}

