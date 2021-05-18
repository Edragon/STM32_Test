/* USER CODE BEGIN PFP */


/* Direct printf to output somewhere */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */


/* USER CODE END PFP */


/* USER CODE BEGIN 2 */

// main 

  char uart1Data[24] = "Connected to UART Two\r\n";
   /*
    * Output to uart2
    * use screen or putty or whatever terminal software
    * 8N1 115200
    */
   HAL_UART_Transmit(&huart1, (uint8_t *)&uart1Data,sizeof(uart1Data), 0xFFFF);

 	printf("\r\n");

 	printf("Scanning I2C bus:\r\n");
	HAL_StatusTypeDef result;
 	uint8_t i;
 	for (i=1; i<128; i++)
 	{
 	  /*
 	   * the HAL wants a left aligned i2c address
 	   * &hi2c1 is the handle
 	   * (uint16_t)(i<<1) is the i2c address left aligned
 	   * retries 2
 	   * timeout 2
 	   */
 	  result = HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(i<<1), 2, 2);
 	  if (result != HAL_OK) // HAL_ERROR or HAL_BUSY or HAL_TIMEOUT
 	  {
 		  printf("."); // No ACK received at that address
 	  }
 	  if (result == HAL_OK)
 	  {
 		  printf("0x%X", i); // Received an ACK at that address
 	  }
 	}
 	printf("\r\n");

/* USER CODE END 2 */






/* USER CODE BEGIN 4 */

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART2 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}


/* USER CODE END 4 */






#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h> // printf()
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>

