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
 * struct param_distoration 声明畸变改正参数
 */
struct param_distoration {
	int dist;			//< 畸变改正算法
	int func;			//< 畸变改正函数基
	int xorder, yorder;	//< 畸变改正函数基阶次
	int xterm;			//< 交叉项类型
	int ncoef;			//< 畸变改正算法系数数量
	double norm[4];		//< 图像坐标归一化范围.  0: xmin, 1: ymin; 2: xmax; 3: ymax
	double *coef;		//< 畸变改正系数
	double *x, *y;		//< 多项式各项变量存储区

protected:
	void release_memory(double **ptr) {
		if ((*ptr)) {
			delete[] (*ptr);
			(*ptr) = NULL;
		}
	}

	void release_all_memory() {
		release_memory(&coef);
		release_memory(&x);
		release_memory(&y);
	}

	/*!
	 * @brief 计算系数数量
	 * @return
	 * 系数数量
	 */
	int coef_count() {
		return 0;
	}

public:
	param_distoration() {
		coef = x = y = NULL;
		ncoef = 0;
	}

	virtual ~param_distoration() {
		release_all_memory();
	}
	/*!
	 * @brief 为畸变系数及多项式分配内存
	 * @return
	 * 内存分配结果
	 * @note
	 * 在设置成员变量dist, func, xorder, yorder, xterm后执行
	 */
	bool alloc_memory() {
		int n = coef_count();
		if (n != ncoef) {
			ncoef = n;
			release_all_memory();
		}
		return (coef != NULL && x != NULL && y != NULL);
	}
};

/*!
 * @struct wcs_tan 声明TAN投影WCS<->图像坐标转换关系
 */
struct wcs_tan {
	int wimg, himg;		//< 图像尺寸
	double crpix[2];	//< 参考点对应的图像坐标
	double crval[2];	//< 参考点对应的WCS坐标
	double ctm[2][2];	//< 坐标转换矩阵: xy=>中间坐标系
	double ctmr[2][2];	//< 坐标逆转换矩阵: 中间坐标系=>xy
	bool valid[2];		//< 畸变修正模型有效性
	param_distoration dist[2];	//< RA/DEC轴畸变改正模型
};
