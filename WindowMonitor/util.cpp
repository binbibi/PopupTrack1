#include "stdafx.h"
#include "Util.h"


unsigned long BKDRHash(const wchar_t *str)
{
	register unsigned long hash = 0;
	while (unsigned long ch = (unsigned long)*str++)
	{
		hash = hash * 131 + ch;   
		// 也可以乘以31、131、1313、13131、131313..  
		// 有人说将乘法分解为位运算及加减法可以提高效率，如将上式表达为：hash = hash << 7 + hash << 1 + hash + ch;  
		// 但其实在Intel平台上，CPU内部对二者的处理效率都是差不多的，  
		// 我分别进行了100亿次的上述两种运算，发现二者时间差距基本为0（如果是Debug版，分解成位运算后的耗时还要高1/3）；  
		// 在ARM这类RISC系统上没有测试过，由于ARM内部使用Booth's Algorithm来模拟32位整数乘法运算，它的效率与乘数有关：  
		// 当乘数8-31位都为1或0时，需要1个时钟周期  
		// 当乘数16-31位都为1或0时，需要2个时钟周期  
		// 当乘数24-31位都为1或0时，需要3个时钟周期  
		// 否则，需要4个时钟周期  
		// 因此，虽然我没有实际测试，但是我依然认为二者效率上差别不大          
	}
	return hash;
}