//Define a XModem packet by using union

struct xmodem
{
	char type;//XModem XModem-1k Checksum or CRC
	union 
	{
		char data_xmodem_checksum[132]; //XModem-Checksum
		char data_xmodem_crc[133]; //XModem-CRC
		char data_xmodem_1k_checksum[1028];//XModem-1k-Checksum
		char data_xmodem_1k_crc[1029];//XModem-1k-CRC
	}data;
};