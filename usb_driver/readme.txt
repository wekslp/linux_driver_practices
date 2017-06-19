利用usb serial、web camera，來寫一個新的usb driver，並透過usb_register來觀察probe的狀態。 
1. 了解如何註冊一個usb driver及probe的運作
2. 了解USB HID Spec.
3. URB packet
4. 實作irq handler及tasklet來接收serial port的資料

移除serial driver，並重新撰寫一個，讓系統能透過自已撰寫的driver來獲取板子的資訊。

平台: Ubuntu、linkit
