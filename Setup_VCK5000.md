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


