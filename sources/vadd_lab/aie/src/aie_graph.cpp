// Copyright (C) 2022 Advanced Micro Devices, Inc
//
// SPDX-License-Identifier: MIT

#include "aie_graph.hpp"

simpleGraph vadd_graph;

#if defined(__AIESIM__) || defined(__X86SIM__)
int main(int argc, char** argv) {
    vadd_graph.init();
    vadd_graph.run(512);
    vadd_graph.end();
    return 0;
}
#endif