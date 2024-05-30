# Women-s-Safety-IoT
A device designed for women in danger, equipped with features such as GSM, GPS, Image capturing, Voice recording, and Face recognition to identify strangers and provide evidence.
# Abstract
The project is titled "IoT Shield: Smart Safety for Women". The main goal of the project is to provide security for women in unsafe situations. When a woman senses danger, she can press the SOS emergency button, which automatically activates all other modules simultaneously. First, the GSM and GPS module gets activated, sending a message along with the victim's live location and a call alert to the pre-defined contact numbers and the nearby police station. Once the call alert is sent, a Raspberry Pi camera captures the stranger's face and the surrounding area, and this footage is sent to the recently used apps. The APR33A3 module is then used to record the stranger's voice and any harassing words he uses. Finally, a CNN algorithm is used to compare the faces captured by the Raspberry Pi camera to faces in government databases, such as Aadhaar cards. This creates accurate evidence to identify the stranger who harasses the woman.
# HARDWARE REQUIREMENTS
* Arduino UNO
* GPS Module
* GSM Module
* Raspberry Pi Camera
* APR33A3 Module (Voice Recorder)
* IoT Wi-fi Module
* Buzzer
* Node MCU
