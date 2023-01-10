# Edgelab Example For Vision AI Module
This guide shows how to deploy your own tflite model to **Seeed Grove Vision AI Module**.

## How to build the firmware?

This explains how you can build the firmware for Grove - Vision AI Module.

**Note:** The following has been tested to work on Ubuntu 20.04 PC

- **Step 1:** Install the following prerequisites

```sh
sudo apt install make
sudo apt install python3-numpy
```

- **Step 2:** Download GNU Development Toolkit

```sh
cd ~
wget https://github.com/foss-for-synopsys-dwc-arc-processors/toolchain/releases/download/arc-2020.09-release/arc_gnu_2020.09_prebuilt_elf32_le_linux_install.tar.gz
```

- **Step 3:** Extract the file

```sh
tar -xvf arc_gnu_2020.09_prebuilt_elf32_le_linux_install.tar.gz
```

- **Step 4:** Add **arc_gnu_2020.09_prebuilt_elf32_le_linux_install/bin** to **PATH**

```sh
export PATH="$HOME/arc_gnu_2020.09_prebuilt_elf32_le_linux_install/bin:$PATH"
```

- **Step 5:** Clone the following repository and go into the directory

```sh
git clone https://github.com/Seeed-Studio/Edgelab
cd Edgelab/examples/vision_ai
```

- **Step 6:** Download related third party, tflite model and library data (only need to download once)

```sh
make download
```

- **Step 7:** Compile the firmware

```sh
make HW=grove_vision_ai APP=meter or make HW=sensecap_vision_ai APP=meter 
make flash
```

This will generate **output.img** inside **tools/image_gen_cstm/output/** directory


- **Step 8:** Generate firmware image **firmware.uf2** file

```sh
python3 tools/ufconv/uf2conv.py -t 0 -c tools/image_gen_cstm/output/output.img -o firmware.uf2
```

- **Step 9:** Convert pre-trained model meter.tflite to **model.uf2** file

```sh
wget https://github.com/Seeed-Studio/Edgelab/releases/download/model_zoo/pfld_meter_int8.tflite 
python3 tools/ufconv/uf2conv.py -t 1 -c pfld_meter_int8.tflite -o model.uf2
```
## How to flash the firmware?

This explains how you can flash the firmware to Grove - Vision AI Module.

- **Step 1:** Connect Grove - Vision AI Module to the host PC via USB Type-C cable 

<div align=center><img width=460 src="https://files.seeedstudio.com/wiki/SenseCAP-A1101/47.png"/></div>

- **Step 2:** Double-click the boot button on Grove - Vision AI Module to enter mass storage mode

<div align=center><img width=220 src="https://files.seeedstudio.com/wiki/SenseCAP-A1101/48.png"/></div>

- **Step 3:** After this you will see a new storage drive shown on your file explorer as **GROVEAI**

<div align=center><img width=250 src="https://files.seeedstudio.com/wiki/SenseCAP-A1101/19.jpg"/></div>

- **Step 4:** Drag and drop the prevous **firmware.uf2** and **model.uf2** file to GROVEAI drive

Once the copying is finished **GROVEAI** drive will disapper. This is how we can check whether the copying is successful or not.

## How to view the camera stream? (Grove AI Family firmware)

- **Step 1:** After loading the firmware and connecting to PC, visit [this URL](https://files.seeedstudio.com/grove_ai_vision/index.html)

- **Step 2:** Click **Connect** button. Then you will see a pop up on the browser. Select **Grove AI - Paired** and click **Connect**
  
<div align=center><img width=1000 src="../_static/meter_p1.png"/></div>

- **Step 2:** Setup **config** 

After that, you can see the real-time video stream on the web UI.

<div align=center><img width=1000 src="../_static/meter_p2.png"/></div>