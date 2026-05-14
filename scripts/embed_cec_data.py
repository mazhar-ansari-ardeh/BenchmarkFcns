import os


def parse_txt(filepath):
    if not os.path.exists(filepath):
        return None
    with open(filepath, "r") as f:
        data = []
        for line in f:
            vals = line.strip().replace("\t", " ").split()
            if vals:
                data.extend([float(v) for v in vals])
    return data


def main():
    cpp_header = """#include "cec_data.h"
#include <stdexcept>
#include <string>

namespace BenchmarkFcns::CEC {

"""
    cpp_arrays = ""

    # Track which (year, fid, dim) are available
    registry = {}  # (year, fid, dim) -> {shift_name, rot_name, shuffle_name}

    years = [2014, 2017, 2019, 2020, 2022]
    for year in years:
        base_dir = f"data/cec{year}"
        if not os.path.exists(base_dir):
            continue

        for fid in range(1, 31):
            # Shift data
            shift_file = f"{base_dir}/shift_{fid}.txt"
            shift_vals = parse_txt(shift_file)
            if shift_vals:
                s_name = f"data_{year}_f{fid}_shift"
                cpp_arrays += f"static const double {s_name}[] = {{{', '.join([f'{v:.16e}' for v in shift_vals])}}};\n"

                # Check for various dimensions
                for dim in [2, 5, 9, 10, 15, 16, 18, 20, 30, 50, 100]:
                    # Rotation data
                    rot_file = f"{base_dir}/M_{fid}_D{dim}.txt"
                    rot_vals = parse_txt(rot_file)

                    # Shuffle data
                    shuffle_file = f"{base_dir}/shuffle_{fid}_D{dim}.txt"
                    shuffle_vals = parse_txt(shuffle_file)

                    if rot_vals:
                        r_name = f"data_{year}_f{fid}_d{dim}_rot"
                        cpp_arrays += f"static const double {r_name}[] = {{{', '.join([f'{v:.16e}' for v in rot_vals])}}};\n"

                        sh_name = "nullptr"
                        if shuffle_vals:
                            sh_name = f"data_{year}_f{fid}_d{dim}_shuffle"
                            # Convert to 0-based indexing if they are 1-based (CEC files are 1-based)
                            zero_based = [int(v) - 1 for v in shuffle_vals]
                            cpp_arrays += f"static const int {sh_name}[] = {{{', '.join([str(v) for v in zero_based])}}};\n"

                        if (year, fid, dim) not in registry:
                            registry[(year, fid, dim)] = {}
                        registry[(year, fid, dim)]["shift"] = s_name
                        registry[(year, fid, dim)]["rot"] = r_name
                        registry[(year, fid, dim)]["shuffle"] = sh_name

                    # Special case for functions without rotation (e.g. 2019 F1-F3 or 2014 F8/F10)
                    # We only register them if they don't have rotation but ARE known to be valid.
                    # For now, let's register any (year, fid) that has shift data but no rotation for dim=0.

                if (year, fid, 0) not in registry:
                    registry[(year, fid, 0)] = {}
                registry[(year, fid, 0)]["shift"] = s_name
                registry[(year, fid, 0)]["rot"] = "nullptr"
                registry[(year, fid, 0)]["shuffle"] = "nullptr"

    # Generate get_data function
    get_data_func = "Data get_data(int year, int fid, int dim) {\n"
    for (y, f, d), names in registry.items():
        get_data_func += f"    if (year == {y} && fid == {f} && dim == {d}) return {{ {names['shift']}, {names['rot']}, {names['shuffle']} }};\n"
    get_data_func += '    throw std::invalid_argument("CEC data not found for year " + std::to_string(year) + " fid " + std::to_string(fid) + " dim " + std::to_string(dim));\n'
    get_data_func += "}\n\n} // namespace BenchmarkFcns::CEC\n"

    with open("src/C++/cec_data.cpp", "w") as f:
        f.write(cpp_header)
        f.write(cpp_arrays)
        f.write("\n")
        f.write(get_data_func)

    # Generate cec_data.h
    with open("src/C++/cec_data.h", "w") as f:
        f.write("""#ifndef CEC_DATA_H
#define CEC_DATA_H

namespace BenchmarkFcns::CEC {
    struct Data {
        const double* shift;
        const double* rotation;
        const int* permutation;
    };
    Data get_data(int year, int fid, int dim);
}

#endif
""")


if __name__ == "__main__":
    main()
