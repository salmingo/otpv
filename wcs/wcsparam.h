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
 * 天文所用的SIP算法, 对应的是以幂函数为函数基的半交叉多项式算法
 * @note
 * - RA/DEC必须采用相同的畸变改正算法 ?
 * - RA/DEC必须采用相同的交叉项数量   ?
 */

enum { //< 畸变改正算法
	DISTORTION_SIP,	//< SIP改正算法
	DISTORTION_TNX	//< TNX改正算法
};

enum {	//< 多项式函数基
	FUNC_CHEBYSHEV = 1,	//< 契比雪夫
	FUNC_LEGENDRE,		//< 勒让德
	FUNC_POWER			//< 幂函数
};

enum {	//< 多项式交叉系数类型
	X_NONE,		//< 无交叉项
	X_FULL,		//< 全交叉
	X_HALF		//< 半交叉
};

/*!
 * struct param_wcs 声明通用WCS参数
 */
struct param_wcs {
	int distortion;		//< 畸变改正算法
	int function;		//< 畸变改正函数基
	int xorder, yorder;	//< 畸变改正函数基阶次
	int xterm;			//< 交叉项类型. SIP默认为
	int wimg, himg;		//< 图像尺寸
	double xmin, ymin;	//< 归一化范围
	double xmax, ymax;
	double crpix[2];	//< 参考点对应的图像坐标
	double crval[2];	//< 参考点对应的WCS坐标
	double ctm[2][2];	//< 转换矩阵: xy=>中间坐标系
	double ctmr[2][2];	//< 逆转换矩阵: 中间坐标系=>xy
};
