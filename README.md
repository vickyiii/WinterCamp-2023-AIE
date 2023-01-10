# WinterCamp-2023-AIE

This is a private repository to deliver the 2023 Winter Camp AIE Training Material on Jan 11~16, 2023.
Please DO NOT distribute this document for any commercial purposes.

## Tools Versions

This version of the tutorial has been verified for the following environments. VCK5000 Local HW-EMU environment setup and HACC Getting started steps can be found [here](./Setup_VCK5000.md)

| Environment  | Vitis   |    XRT   | Shell | Notes |
|--------------|---------|----------|-------|-------|
| HACC-NUS      | 2022.1  | 2.13.478  | xilinx_vck5000_gen4x8_xdma_2_202210_1| 6 VCK5000s are available |



## Schedule

<table border="0" width="100%">
    <tbody>
        <tr>
		    <td height="20">
                <strong> DATE  </strong>
            </td>
            <td height="24">
                <strong> Time</strong>
            </td>            
            <td height="24">
                <strong> Subject </strong>
            </td>
            <td height="24">
                <strong> Resource  </strong>
            </td>
        </tr>
        <tr>
            <td height="24">
            Wednesday, January 11
            </td>
            <td>
            9:30 AM-11:30 AM
            </td>
            <td>
			Overview of Versal ACAP Architecture
			</td>
            <td>
            <a href= "https://docs.xilinx.com/v/u/en-US/wp506-ai-engine" >
            1. AI Engines and Their Applications |  </a>
            <a href= "https://docs.xilinx.com/v/u/en-US/ds950-versal-overview" >
            2. Versal Overview </a>
            </td>
        </tr>
        <tr>
            <td height="24">
            </td>
            <td>
            </td>
            <td>
            Introduction to AI Engine Architecture
            </td>
			<td>
			<a href= "https://docs.xilinx.com/r/en-US/am009-versal-ai-engine/AI-Engine-Tile-Architecture">AI Engine Tile Architecture</a>
			</td>
        <tr>
                <tr>
            <td height="24">
            </td>
            <td>
            </td>
            <td>
            Versal AI Engine Memory and Data Movement
            </td>
			<td>
            <a href= "https://docs.xilinx.com/r/en-US/am009-versal-ai-engine/AI-Engine-Data-Movement-Architecture">AI Engine Data Movement Architecture</a>
			</td>
        </tr>
            <td height="24">
            </td>
            <td>
            2:00 PM-4:00 PM
            </td>
            <td>
			VCK5000 Platform Introduction and Versal ACAP Tool Flow
			</td>
            <td>
            <a href= "https://docs.xilinx.com/r/en-US/ug1076-ai-engine-environment/Integrating-the-Application-Using-the-Vitis-Tools-Flow" >Integrating the Application Using the Vitis Tools Flow</a>
            </td>
        </tr>
        <tr>
            <td height="24">
            </td>
            <td>
            </td>
            <td>
            Demo on how to get started with VCK5000 Card on HACC
            </td>
			<td>
			<a href= "./Setup_VCK5000.md"> VCK5000 Getting Started on HACC</a>
		</td>
        <tr>
            <td height="24">
            </td>
            <td>
            </td>
            <td>
            Lab1: Vecter Addition Using Streams 
            </td>
			<td>
			<a href= "./lab1_vadd_part1.md">VADD Lab Guide Part1 | </a>
            <a href= "./lab1_vadd_part2.md">VADD Lab Guide Part2</a>
		</td>
        </tr>
            <tr>
            <td height="24">
            Thursday, January 12
            </td>
            <td>
            9:30 AM-11:30 AM
            </td>
            <td>
			Scalar and Vector Data Types              
			</td>
            <td>
            <a href= "https://docs.xilinx.com/r/en-US/ug1079-ai-engine-kernel-coding/Introduction-to-Scalar-and-Vector-Programming?tocId=7~QEMIZKf_i6S~Gzi4RKVA" >Introduction to Scalar and Vector Programming</a>
            </td>
        </tr>
        <tr>
            <td height="24">
            </td>
            <td>
            </td>
            <td>
            AI Engine APIs
            </td>
			<td>
            <a href= "https://www.xilinx.com/htmldocs/xilinx2022_2/aiengine_api/aie_api/doc/index.html">AI Engine API User Guide</a>
			</td>
        </tr>
        <tr>
            <td height="24">
            </td>
            <td>
            </td>
            <td>
            Windows and Streaming Data APIs
            </td>
			<td>
			<a href= "https://docs.xilinx.com/r/en-US/ug1079-ai-engine-kernel-coding/Window-and-Streaming-Data-API">Window and Streaming Data API</a>
			</td>
        </tr>
                <tr>
            <td height="24">
            </td>
            <td>
            2:00 PM-4:00 PM
            </td>
            <td>
			Vitis Analyzer
			</td>
            <td>
            <a href= "https://docs.xilinx.com/r/en-US/ug1076-ai-engine-environment/Performance-Analysis-of-AI-Engine-Graph-Application-during-Simulation" >Performance Analysis of AI Engine Graph Application during Simulation and Hardware</a>
            </td>
        </tr>
        <tr>
            <td height="24">
            </td>
            <td>
            </td>
            <td>
            Lab2: Full system running the AI Engine
            </td>
			<td>
			<a href= "./lab2_matmult_lab.md">Matmult Lab Guide</a>
			</td>
        </tr>
            <tr>
            <td height="24">
            Monday, January 16
            </td>
            <td>
            9:30 AM-11:30 AM
            </td>
            <td>
			The Programming Model - Single Kernel
			</td>
            <td>
            <a href= "https://docs.xilinx.com/r/en-US/ug1079-ai-engine-kernel-coding/Single-Kernel-Programming" >Single Kernel Programming</a>
            </td>
        </tr>
        <tr>
            <td height="24">
            </td>
            <td>
            </td>
            <td>
            The Programming Model - Adaptive Data Flow Graph
            </td>
			<td>
            <a href= "https://docs.xilinx.com/r/en-US/ug1079-ai-engine-kernel-coding/Introduction-to-Graph-Programming">Graph Programming</a>
			</td>
        </tr>
        <tr>
            <td height="24">
            </td>
            <td>
            </td>
            <td>
            The Programming Model - Multiple Kernels Using Graphs
            </td>
			<td>
			<a href= "https://docs.xilinx.com/r/en-US/ug1079-ai-engine-kernel-coding/Vectorized-Version-Using-Multiple-Kernels">Multiple Kernels Using Graphs</a>
			</td>
        </tr>
           <tr>
            <td height="24">
            </td>
            <td>
            2:00 PM-4:00 PM
            </td>
            <td>
			Lab3: Code vectorization of a FIR filter using the AIE APIs
			</td>
            <td>
            <a href= "./lab3_fir_filter.md" > Fir Filter Lab Guide</a>
            </td>
        </tr>
</table>

## Additional Material

1. [Download Vitis Unified Software](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vitis.html)

1. [Vitis Unified Software Documentation](https://docs.xilinx.com/v/u/en-US/ug1416-vitis-documentation)

1. [Vitis Community Forum](https://support.xilinx.com/s/topic/0TO2E000000YKYAWA4/vitis-acceleration-acceleration?language=en_US)

1. [Webinar: Vitis End-to-End Flow for Mixed Kernel Acceleration on VCK5000](https://pages.xilinx.com/EN-WB-2022-04-20-VCK5000VitisFlow_LP-Registration.html)

1. [Generate an aiengine license for free](https://support.xilinx.com/s/article/76792?language=en_US)

1. [Versal ACAP AI Engines for Dummies](https://support.xilinx.com/s/article/1132493?language=en_US)

1. [Versal ACAP AI Engine Architecture Manual](https://docs.xilinx.com/r/en-US/am009-versal-ai-engine/Revision-History)

1. [Versal ACAP AI Engine Programming Environment User Guide](https://docs.xilinx.com/r/en-US/ug1076-ai-engine-environment)

   1. [Adaptive Data Flow Graph Specification Reference](https://docs.xilinx.com/r/en-US/ug1076-ai-engine-environment/Adaptive-Data-Flow-Graph-Specification-Reference)

   1. [Compiling an AI Engine Graph Application](https://docs.xilinx.com/r/en-US/ug1076-ai-engine-environment/Compiling-an-AI-Engine-Graph-Application)

   1. [Simulating an AI Engine Graph Application](https://docs.xilinx.com/r/en-US/ug1076-ai-engine-environment/Simulating-an-AI-Engine-Graph-Application)

1. [AI Engine API User Guide](https://www.xilinx.com/htmldocs/xilinx2022_2/aiengine_api/aie_api/doc/index.html)

1. [AI Engine Intrinsics](https://www.xilinx.com/htmldocs/xilinx2022_2/aiengine_intrinsics/intrinsics/index.html)

1. [AI Engine Development Tutorial](https://github.com/Xilinx/Vitis-Tutorials/tree/2022.2/AI_Engine_Development/Feature_Tutorials)

1. [Versal ACAP AI Engine Register Reference](https://www.xilinx.com/htmldocs/registers/am015/am015-versal-aie-register-reference.html)

1. [Versal ACAP Design Process Documentation](https://www.xilinx.com/support/documentation-navigation/design-process/ai-engine-development.html)

1. [System-Level Benefits of the Versal Platform](https://www.xilinx.com/content/dam/xilinx/support/documents/white_papers/wp539-versal-system-level-benefits.pdf)

1. [Vitis Unified Software Platform Documentation: Application Acceleration Development](https://docs.xilinx.com/r/en-US/ug1393-vitis-application-acceleration)

1. [Vitis Application Development Flow](https://docs.xilinx.com/r/en-US/ug1393-vitis-application-acceleration/Vitis-Application-Development-Flow)

1. [Data Center Acceleration Terminology](https://docs.xilinx.com/r/en-US/ug1393-vitis-application-acceleration/Terminology)
