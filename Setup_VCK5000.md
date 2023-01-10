# Local Environment Setup
1.	Click on the following link and request access to the VCK5000 Versal Development Card for AI Engine Secure Site. This will take one or two days.
https://www.xilinx.com/products/boards-and-kits/vck5000.html
 
2.	Download the Vitis 2022.1 version, XRT, Deployment Target Platform and Development Platform according to your OS vision
Please Download and install the XRT 202210.2* and DON’T download the XRT-APU
https://www.xilinx.com/member/vck5000-aie.html#vitis-flow
![setup_vck5000](/images/setup_guide/VCK5000_download.png)

3. Please install the **VCK5000 Gen4x8 xdma platform** platform by following the steps here: https://docs.xilinx.com/r/en-US/ug1531-vck5000-install/XRT-and-Deployment-Platform-Installation-Procedures-on-RedHat-and-CentOS

4.	Once you have got the access to VCK5000 tutorial, please refer to the following website to download the Mixed kernel example lab files the tutorials and run the example.
https://www.xilinx.com/member/vck5000-aie.html#tutorials


5. Patch the xilinx_vck5000_gen4x8_xdma_2_202210_1 platform

To be able to use the AI Engine on the VCK5000 from the Vitis IDE, please apply this change

```sh
sudo ./sources/patch_vck5000_gen4x8_xdma/aie_domain_patch.sh
```

# HACC Getting Started With VCK5000

## Login HACC@NUS

Please setup 2FA following the instructions in the email of registration. After that, you can use SSH with the given username and 2FA key to login HACC@NUS.

```
ssh username@xacchead.d2.comp.nus.edu.sg
```

you will login to the node __hacchead__

After getting into __hacchead__, please clone this repository so that you can use the script tools provided by HACC@NUS.

```
git clone https://github.com/XACCNUS/hacc_demo.git
```

## Demo: VCK5000 Exploration

This demo shows how to use the VCK5000 in HACC@NUS. We highly recommend you to use ```tmux``` for multiple tasking, which lets you switch easily between several programs in one terminal.


### Compiling VCK5000 Project
HACC@NUS provides following software environment for the compilation and execution of VCK5000 program.

XRT:   __2.13.478__

Vitis: __2022.1__

Due the compatibility issues with other Alveo boards, we provide a separate compilation node for VCK5000. To use this node, simply run the following command:
```
./env/vck5000_compile
```

You will login to a node with VCK5000 software environment. To setup XRT and Vitis environment.
```
source ./env/vck5000_env
```

The terminal will print the toolchain version information like this:
```
{
  "BUILD_VERSION" : "2.13.478",
  "BUILD_VERSION_DATE" : "Mon, 16 May 2022 15:30:19 -0700",
  "BUILD_BRANCH" : "2022.1",
  "VERSION_HASH" : "458699e9617da693e354d95b637df38daa2ed40a",
  "VERSION_HASH_DATE" : "Mon, 16 May 2022 11:11:42 -0700"
}

/tools/Xilinx/Vitis/2022.1/bin/vitis
```


Then you can compile your project (e.g., the mixed kernel demo from the early access page).


### Run VCK5000 Program
To execute your VCK5000 program, you should allocate an idle VCK5000 compute node according ```sinfo``` 

For example, an output of ```sinfo``` like this:
```
PARTITION                         AVAIL  TIMELIMIT  NODES  STATE NODELIST
cpu_only*                            up 7-00:00:00      1   idle hacc-node2
head                                 up 2-00:00:00      1   unk* hacchead
u50_standard_reservation_pool        up   12:00:00      1   idle hacc-u50-1
vck5000_standard_reservation_pool    up      20:00      1  alloc hacc-vck5000-1
vck5000_standard_reservation_pool    up      20:00      3   idle hacc-vck5000-[2-4]
vck5000_compile                      up 7-00:00:00      1    mix hacc-node0
u250_standard_reservation_pool       up   12:00:00      4   idle hacc-u250-[1-4]
```

It indicates that the board 1 is allocated by other users, and your available VCK5000 boards are board 2, 3 and 4. Suppose you want to allocate board 2, simply run:
```
./env/vck5000_alloc 2
```

Setup env:
```
source ./env/vck5000_env
```

Run the example:

```
./vck5000_example/vadd_aie ./vck5000_example/fpga.xclbin
```

__NOTE:__ The AI Engine of VCK5000 array is configured during the boot (through PLM) thus you can only run this single application. If you need to run another AIE graph during runtime then you would need to reboot the node. We provide an script to do the reboot and re-initialization:

In the case of:

- You have finished your program and want to exit.
- You want to run another AIE graph.
- Your PL kernels are stalled by an unknown reason.

Please run the following command in the allocated VCK5000 node.
```
./env/vck5000_exit
```

It may pop some error messages, feel free to ignore them. The node will be set to __down__ for several minutes (around two minutes), after that, it will be available for new allocation.



