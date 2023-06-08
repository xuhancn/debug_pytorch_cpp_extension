#include <torch/extension.h>
#include <ATen/cpu/vec/vec.h>

//#include "/tmp/torchinductor_xu/lr/clrlgu27q4ggd472umdzwsu6qcpqxcuusjxqvx2hwitjbujiiz7z.h"
extern "C" void cpp_fused_add_mul_0(float* in_out_ptr0)
{
    {
        for(long i0=static_cast<long>(0L); i0<static_cast<long>(9216L); i0+=static_cast<long>(8L))
        {
            auto tmp0 = at::vec::Vectorized<float>::loadu(in_out_ptr0 + static_cast<long>(i0));
            auto tmp1 = tmp0 + tmp0;
            auto tmp2 = tmp0 * tmp1;
            tmp2.store(in_out_ptr0 + static_cast<long>(i0));
        }
    }
}
std::vector<at::Tensor> inductor_entry_cpp_2(const std::vector<at::Tensor>& args) {
    at::Tensor arg0_1 = args[0];
    at::Tensor arg1_1 = args[1];

    c10::optional<at::Scalar> optional_scalar;
    c10::optional<c10::string_view> optional_string;
    torch::List<c10::optional<at::Scalar>> optional_list;
        
    static auto op_convolution_pointwise =
    c10::Dispatcher::singleton()
        .findSchemaOrThrow(
            "mkldnn::_convolution_pointwise",
            "")
        .typed<
            at::Tensor(
                const at::Tensor& input_t,
                const at::Tensor& weight_t,
                const c10::optional<at::Tensor>& bias_opt,
                at::IntArrayRef padding,
                at::IntArrayRef stride,
                at::IntArrayRef dilation,
                int64_t groups,
                c10::string_view attr,
                torch::List<c10::optional<at::Scalar>> scalars,
                c10::optional<c10::string_view> algorithm)>();
            
        auto buf0 = op_convolution_pointwise.call(arg1_1, arg0_1, at::Tensor(), {0, 0}, {2, 2}, {1, 1}, 1, "none", optional_list, optional_string);
        arg0_1.reset();
        arg1_1.reset();
        auto buf1 = buf0; buf0.reset();  // reuse
        cpp_fused_add_mul_0((float*)(buf1.data_ptr()));
        return {buf1};
}

