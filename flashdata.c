uint32_t writeFlashData = 0x55555555;
uint32_t addr = 0x08007000;

//FLASH写入数据测试
void writeFlashTest(void) {
	//1、解锁FLASH
	HAL_FLASH_Unlock();

	//2、擦除FLASH
	//初始化FLASH_EraseInitTypeDef
	FLASH_EraseInitTypeDef f;
	f.TypeErase = FLASH_TYPEERASE_PAGES;
	f.PageAddress = addr;
	f.NbPages = 1;
	//设置PageError
	uint32_t PageError = 0;
	//调用擦除函数
	HAL_FLASHEx_Erase(&f, &PageError);

	//3、对FLASH烧写
	HAL_FLASH_Program(TYPEPROGRAM_WORD, addr, writeFlashData);

	//4、锁住FLASH
	HAL_FLASH_Lock();
}

//FLASH读取数据测试
void printFlashTest(void) {
	uint32_t temp = *(__IO uint32_t*)(addr);

	printf("addr:0x%x, data:0x%x\r\n", addr, temp);
}
