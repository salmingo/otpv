/*!
 * @file wcsparam.h 声明WCS参数
 * @version 0.1
 * @date 2019-06-19
 * @note
 * 声明WCS参数, 为天文常用的TAN投影及畸变改正函数提供操作接口
 * - TAN投影参数
 * - SIP畸变改正参数
 * - TNX畸变改正参数
 * @note
 * 天文所用的SIP算法, 对应的是以幂函数为函数基的半交叉多项式算法, 但自变量定义与TNX不同:
 * - SIP: 图像平面坐标系
 * - TNX: 理想平面参考系
 * @note
 * FITS头中关键字
 */

enum { // 畸变改正算法
	DISTORTION_SIP,	//< SIP改正算法
	DISTORTION_TNX	//< TNX改正算法
};

enum {	// 多项式函数基
	FUNC_CHEBYSHEV = 1,	//< 契比雪夫
	FUNC_LEGENDRE,		//< 勒让德
	FUNC_POWER			//< 幂函数
};


/*!
 * @class wcs_common 声明通用WCS参数
 */
class wcs_common {

};
