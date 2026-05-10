#include <reg52.h>
void UART_Init()
{
    TMOD |= 0x20;
    TH1 = 0xF9; // 12MHz晶振，2400波特率
    TL1 = 0xF9;
    TR1 = 1;
    SCON = 0x50;
}
void UART_SendByte(unsigned char dat)
{
    SBUF = dat;
    while(!TI);
    TI = 0;
}
void main()
{
    unsigned char recv;
    UART_Init();
    while(1)
    {
        if(RI)
        {
            RI = 0;
            recv = SBUF;
            UART_SendByte(recv); // 收到什么发回什么
        }
    }
}
