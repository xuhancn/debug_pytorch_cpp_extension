#include <torch/extension.h>
#include <ATen/cpu/vec/vec.h>

//#include "/tmp/torchinductor_xu/lr/clrlgu27q4ggd472umdzwsu6qcpqxcuusjxqvx2hwitjbujiiz7z.h"
extern "C" void cpp_fused__convolution_pointwise_0(const float* in_ptr0,
                       float* out_ptr0)
{
    {
        #pragma GCC ivdep
        for(long i0=static_cast<long>(0L); i0<static_cast<long>(2L); i0+=static_cast<long>(1L))
        {
            #pragma GCC ivdep
            for(long i1=static_cast<long>(0L); i1<static_cast<long>(3L); i1+=static_cast<long>(1L))
            {
                #pragma GCC ivdep
                for(long i2=static_cast<long>(0L); i2<static_cast<long>(256L); i2+=static_cast<long>(1L))
                {
                    auto tmp0 = in_ptr0[static_cast<long>(i2 + (256L*i1) + (768L*i0))];
                    out_ptr0[static_cast<long>(i1 + (3L*i2) + (768L*i0))] = tmp0;
                }
            }
        }
    }
}
std::vector<at::Tensor> inductor_entry_cpp_1(const std::vector<at::Tensor>& args) {
    at::Tensor arg0_1 = args[0];
    at::Tensor arg1_1 = args[1];

    c10::optional<at::Scalar> optional_scalar;
    c10::optional<c10::string_view> optional_string;
    torch::List<c10::optional<at::Scalar>> optional_list;
        auto buf0 = at::empty_strided({2L, 3L, 16L, 16L}, {768L, 1L, 48L, 3L}, at::device(at::kCPU).dtype(at::kFloat));
        cpp_fused__convolution_pointwise_0((float*)(arg1_1.data_ptr()), (float*)(buf0.data_ptr()));
        arg1_1.reset();
        
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
            
        auto buf1 = op_convolution_pointwise.call(buf0, arg0_1, at::Tensor(), {0, 0}, {2, 2}, {1, 1}, 1, "none", optional_list, optional_string);
        arg0_1.reset();
        return {buf1};
}

