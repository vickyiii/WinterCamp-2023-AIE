## 
1.	Click on the following link and request access to the VCK5000 Versal Development Card for AI Engine Secure Site. This will take one or two days.
https://www.xilinx.com/products/boards-and-kits/vck5000.html
 

2.	Download the Vitis 2022.1 version, XRT, Deployment Target Platform and Development Platform according to your OS vision
Please Download and install the XRT 202210.2* and DON’T download the XRT-APU
https://www.xilinx.com/member/vck5000-aie.html#vitis-flow
![setup_vck5000](/images/setup_guide/VCK5000_download.png)

3.	Follow the UG1531 to power on the card 
https://docs.xilinx.com/r/en-US/ug1531-vck5000-install/Installing-the-Card
shut down the server with power plug out.
              Wait 5 minutes until the machine is fully discharged, put the accelerator card into the PCIe card slot, and connect the 6 pins and 8 pins power cables 
              Power on the machine
4.	Run :
a.	Source /opt/xilinx/xrt/setup.sh
b.	Lspci -vd 10ee:
c.	Xbutil examine
5.	If you are able to see the device present correctly with shell xilinx_vck5000_gen4x8_qdma_base_2, you don’t need to install and fresh the shell again
 
6.	If you cannot see the card on PCIe or shell installed, Please install the vck5000 platform by following the steps here: https://docs.xilinx.com/r/en-US/ug1531-vck5000-install/XRT-and-Deployment-Platform-Installation-Procedures-on-RedHat-and-CentOS

7.	Once you have got the access to VCK5000 tutorial, please refer to the following website to download the Mixed kernel example lab files the tutorials and run the example.
https://www.xilinx.com/member/vck5000-aie.html#tutorials


## Setup VCK5000 platform

In this step, we are going to setup a local copy of the VCK5000 Gen4x8 xdma platform. We are also going to patch it to include the aie engine domain.

Copy the following code snippet and then past it on a terminal in your server.

```sh
mkdir /scratch/$USER/vck5000_gen4x8/ -p
cp -r /opt/xilinx/platforms/xilinx_vck5000_gen4x8_xdma_2_202210_1/ /scratch/$USER/vck5000_gen4x8/

cat > /scratch/$USER/vck5000_gen4x8/xilinx_vck5000_gen4x8_xdma_2_202210_1/sw/sw.spfm << EOT
<?xml version="1.0" encoding="UTF-8"?>
<sdx:platform xmlns:sdx="http://www.xilinx.com/sdx" sdx:vendor="xilinx" sdx:library="vck5000" sdx:name="gen4x8_xdma_2" sdx:version="202210.1" sdx:schemaVersion="1.0">
   <sdx:description>This platform targets the Versal VCK5000 Alveo Developer Kit. This high-performance acceleration platform features four channels of DDR4-3200 SDRAM, and Xilinx XDMA for PCI Express with PCIe Gen4x8 connectivity.</sdx:description>
   <sdx:systemConfigurations sdx:defaultConfiguration="config0_0">
      <sdx:configuration sdx:name="config0_0" sdx:displayName="Linux" sdx:defaultProcessorGroup="x86_0" sdx:runtimes="ocl">
         <sdx:description>config0_0 Linux OS on x86_0</sdx:description>
         <sdx:processorGroup sdx:name="x86_0" sdx:displayName="x86_0" sdx:cpuType="x86" sdx:cpuInstance="x86_0">
            <sdx:os sdx:name="linux" sdx:displayName="Linux OS" />
         </sdx:processorGroup>
         <sdx:processorGroup sdx:name="aie_domain" sdx:displayName="aie_domain" sdx:cpuType="ai_engine" sdx:cpuInstance="ai_engine">
            <sdx:os sdx:name="aie_runtime" sdx:displayName="aie_runtime" />
         </sdx:processorGroup>
      </sdx:configuration>
   </sdx:systemConfigurations>
</sdx:platform>
EOT
```

## Getting Started


