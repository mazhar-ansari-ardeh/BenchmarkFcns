#ifndef CEC_DATA_H
#define CEC_DATA_H

namespace BenchmarkFcns::CEC {
struct Data {
    const double *shift;
    const double *rotation;
    const int *permutation;
};
Data get_data(int year, int fid, int dim);
} // namespace BenchmarkFcns::CEC

#endif
