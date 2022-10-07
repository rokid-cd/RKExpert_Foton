#ifndef __ZMF_UTILS_H__
#define __ZMF_UTILS_H__
#include <stdarg.h>
#ifdef __GNUC__
#pragma GCC visibility push(default)
#endif
/**
 * @file zmf_utils.h
 * @brief ZMF图像转换工具函数
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup ZmfLog 日志接口
 * @brief 自定义ZMF模块的日志打印等级。
 * @{
 */

/**
 * @brief 日志等级
 */
typedef enum {
    ZmfLogDebug     = 0,
    ZmfLogInfo      = 1,
    ZmfLogWarn      = 2,
    ZmfLogError     = 3,
} ZmfLogLevel;

/**
 * @brief   将格式化输出内容打印至zmf的日志系统
 * @param   iLogLevel   要打印的日志等级， @ref ZmfLogLevel
 * @param   format      要打印的格式化输出字符串
 * @param   argv        要打印的格式化输出字符串对应的参数列表
 * @note    无返回值，不进行错误管理。
 */
void Zmf_LogV(int iLogLevel, const char *format, va_list argv);

/**
 * @}
 */

/**
 * @defgroup ZmfVideoType 视频数据类型
 * @{
 */

/**
 * @brief ZMF模块支持的图像类型
 */
typedef enum {
    ZmfPixelFormatI420              = 1,  /**< @brief YUVI420格式，通道顺序Y-U-V，4:1:1 */
    ZmfPixelFormatIYUV              = 2,  /**< @brief IYUV格式 */
    ZmfPixelFormatRGB24             = 3,  /**< @brief RGB24格式 */
    ZmfPixelFormatABGR              = 4,  /**< @brief ABGR格式 */
    ZmfPixelFormatARGB              = 5,  /**< @brief ARGB格式 */
    ZmfPixelFormatARGB4444          = 6,  /**< @brief ARGB4444格式 */
    ZmfPixelFormatRGB565            = 7,  /**< @brief RGB565格式 */
    ZmfPixelFormatARGB1555          = 8,  /**< @brief ARGB1555格式 */
    ZmfPixelFormatYUY2              = 9,  /**< @brief YUY2格式 */
    ZmfPixelFormatYV12              = 10, /**< @brief YV12格式 */
    ZmfPixelFormatUYVY              = 11, /**< @brief UYVY格式 */
    ZmfPixelFormatMJPG              = 12, /**< @brief Motion JPG格式 */
    ZmfPixelFormatNV21              = 13, /**< @brief NV21格式 */
    ZmfPixelFormatNV12              = 14, /**< @brief NV12格式 */
    ZmfPixelFormatBGRA              = 15  /**< @brief BGRA格式 */
} ZmfPixelFormatType;

/**
 * @}
 */

/**
 * @defgroup ZmfVideoInterface 视频基础接口
 *
 * @{
 */

/**
 * @brief       将I420图像转换成别的类型
 * @param       dstFrame    用于保存转换后的图像数据
 * @param       dstStride   表示一行像素的字节数
 * @param       dstFormat   输出图像类型 @see ZmfPixelFormatType
 * @param       srcFrame    源图像数据
 * @param       srcWidth    源图像宽
 * @param       srcHeight   源图像高
 * @return      int，函数执行结果

 * dstFormat 不等于 ZmfPixelFormatMJPG时,\n
 *               0:                          函数执行成功\n
 *              -ZMF_ERROR_ARGUMENT_INVALID: 接口输入参数错误\n
 *              -ZMF_ERROR_YUV_NOT_SUPPORTED:当前版本ZMF不支持使用libyuv\n
 *              -ZMF_ERROR_YUV_FMT_ANY:      指定的yuv fomat不支持\n
 *              -ZMF_ERROR_YUV_LIB_ERROR:    libyuv报错，具体错误信息需查看日志获取。\n
 * dstFormat 等于 ZmfPixelFormatMJPG时,\n
 *               大于0:                        返回  dstFrame的大小,函数执行成功\n
 *              -ZMF_ERROR_ARGUMENT_INVALID: 接口输入参数错误\n
 *              -ZMF_ERROR_YUV_NOT_SUPPORTED:当前版本ZMF不支持使用libyuv\n
 *              -ZMF_ERROR_YUV_FMT_ANY:      指定的yuv fomat不支持\n
 *              -ZMF_ERROR_YUV_LIB_ERROR:    libyuv报错，具体错误信息需查看日志获取。\n
 * @see         Zmf_ImageFromYV12, Zmf_ConvertToI420, Zmf_ScaleI420, Zmf_MirrorI420UpDown
 */
int  Zmf_ImageFromI420 (void* dstFrame, int dstFormat, int dstStride,
                        const void* srcFrame, int srcWidth, int srcHeight);
///@cond
/** deprecated, use Zmf_ImageFromI420 */
int  Zmf_ConvertFromI420 (void* dstFrame, int dstFormat,
                          const void* srcFrame, int srcWidth, int srcHeight);
///@endcond

/**
 * @brief       将YV12图像转换成别的类型
 * @param       dstFrame    用于保存转换后的图像数据
 * @param       dstFormat   输出图像类型 @ref ZmfPixelFormatType
 * @param       dstStride   表示一行像素的字节数
 * @param       srcFrame    源图像数据
 * @param       srcWidth    源图像宽
 * @param       srcHeight   源图像高
 * @return      int，函数执行结果\n
 *              0:                          函数执行成功\n
 *              -ZMF_ERROR_ARGUMENT_INVALID: 接口输入参数错误\n
 *              -ZMF_ERROR_YUV_NOT_SUPPORTED:当前版本ZMF不支持使用libyuv\n
 *              -ZMF_ERROR_YUV_FMT_ANY:      指定的yuv fomat不支持\n
 *              -ZMF_ERROR_YUV_LIB_ERROR:    libyuv报错，具体错误信息需查看日志获取。\n
 * @see         Zmf_ImageFromI420
 */
int  Zmf_ImageFromYV12 (void* dstFrame, int dstFormat, int dstStride,
                          const void* srcFrame, int srcWidth, int srcHeight);
///@cond
/** deprecated, use Zmf_ImageFromYV12 */
int  Zmf_ConvertFromYV12 (void* dstFrame, int dstFormat,
                          const void* srcFrame, int srcWidth, int srcHeight);
///@endcond

/**
 * @brief       将图像类型转换成I420
 * @param       dstFrame    用于保存转换后的图像数据
 * @param       srcFormat   源图像类型 @ref ZmfPixelFormatType
 * @param       srcFrame    源图像数据
 * @param       srcBufLen   源图像数据字节数
 * @param       srcWidth    源图像宽
 * @param       srcHeight   源图像高
 * @param       crop_x      相对于左上角的裁剪起始宽度偏移
 * @param       crop_y      相对于左上角的裁剪起始高度偏移
 * @param       dstWidth    输出图像宽度(4字节对齐)，同时作为输出值表示转换后图像的实际宽
 * @param       dstHeight   输出图像高度(4字节对齐)，同时作为输出值表示转换后图像的实际高
 * @param       rotateAngle 顺时针旋转角度
 * @return      int，函数执行结果\n
 *              0:                          函数执行成功\n
 *              -ZMF_ERROR_ARGUMENT_INVALID: 接口输入参数错误\n
 *              -ZMF_ERROR_YUV_NOT_SUPPORTED:当前版本ZMF不支持使用libyuv\n
 *              -ZMF_ERROR_YUV_FMT_ANY:      指定的yuv fomat不支持\n
 *              -ZMF_ERROR_YUV_LIB_ERROR:    libyuv报错，具体错误信息需查看日志获取。\n
 * @see         Zmf_ImageFromI420, Zmf_ScaleI420, Zmf_MirrorI420UpDown
 */
int  Zmf_ConvertToI420(void* dstFrame,
                       int srcFormat, const void* srcFrame, unsigned srcBufLen,
                       int srcWidth, int srcHeight, int crop_x, int crop_y,
                       int *dstWidth, int *dstHeight, int rotateAngle);

/**
 * @brief       缩放I420图像
 * @param       srcFrame    源图像数据
 * @param       srcWidth    源图像宽
 * @param       srcHeight   源图像高
 * @param       dstFrame    输出图像数据
 * @param       dstWidth    输出图像宽度
 * @param       dstHeight   输出图像高度
 * @return      int，函数执行结果\n
 *              0:                          函数执行成功\n
 *              -ZMF_ERROR_ARGUMENT_INVALID: 接口输入参数错误\n
 *              -ZMF_ERROR_YUV_NOT_SUPPORTED:当前版本ZMF不支持使用libyuv\n
 *              -ZMF_ERROR_YUV_LIB_ERROR:    libyuv报错，具体错误信息需查看日志获取。\n
 * @see         Zmf_ConvertToI420, Zmf_ImageFromI420, Zmf_MirrorI420UpDown
 */
int  Zmf_ScaleI420(void* srcFrame, int srcWidth, int srcHeight,
                   void* dstFrame, int dstWidth, int dstHeight);

/**
 * @brief       上下翻转I420图像
 * @param       srcFrame    源图像数据
 * @param       dstFrame    输出图像数据
 * @param       width       图像宽度
 * @param       height      图像高度
 * @return      int，函数执行结果\n
 *              0:                          函数执行成功\n
 *              -ZMF_ERROR_ARGUMENT_INVALID: 接口输入参数错误\n
 *              -ZMF_ERROR_YUV_NOT_SUPPORTED:当前版本ZMF不支持使用libyuv\n
 *              -ZMF_ERROR_YUV_LIB_ERROR:    libyuv报错，具体错误信息需查看日志获取。\n
 * @see         Zmf_ConvertToI420, Zmf_ImageFromI420, Zmf_ScaleI420
 */
int Zmf_MirrorI420UpDown(void* srcFrame, void* dstFrame,
                     int width, int height);

/**
 * @brief THEA收集信息的等级枚举
 */
enum ZmfTessarCollectLevel {
    ZmfTessarError,
    ZmfTessarWarn,
    ZmfTessarImportant,
    ZmfTessarDebug,
};

/**
 * @brief THEA收集信息的类型枚举
 */
enum ZmfTessarCollectType {
    ZmfTessarData     = 0x01,
    ZmfTessarEvent    = 0x02,
    ZmfTessarAll      = 0x03,
};

/**
 * @brief THEA收集信息出错通知方式枚举
 */
enum ZmfTessarInform {
    ZmfTessarTimeOut        = 1 << 0,   /**< @brief 内部有新的数据写入，但至少持续5秒没有输出数据 */
    ZmfTessarErrorOccured   = 1 << 1,   /**< @brief 发生Error级别的事件 */
};

/**
 * @brief       注册天赛ID。
 * @return      int，注册天赛ID的结果。\n
 *              >0:                       注册分配到的天赛ID\n
 *              -ZMF_ERROR_TESSAR_ID_FULL: 当前zmf中的天赛ID已满\n
 */
int Zmf_TessarRegister();

/**
 * @brief       注销天赛ID。
 * @param id    用户id, 通过 @ref Zmf_TessarRegister 获取。
 * @note        此接口无返回值，也不会产生错误信息。
 */
void Zmf_TessarDeregister(int id);

/**
 * @brief       获取tessar字符串(json)
 * @param level 天赛等级, @ref ZmfTessarCollectLevel
 * @param type  数据类型, @ref ZmfTessarCollectType
 * @param id    用户id, 通过 @ref Zmf_TessarRegister 获取。
 * @return      const char*, 如果获取失败返回NULL，通过 @ref Zmf_GetLastError 获取错误码和详细错误信息。\n
 *              错误码由错误编号和领域码组成，其中错误编号的取值为如下之一:\n
 *              -ZMF_ERROR_TESSAR_ID_INVALID:   指定的id无效。\n
 *              -ZMF_ERROR_TESSAR_UNREGISTERED: 指定的id对应的天赛未注册。\n
 */
const char* Zmf_GetTessarData(int level, int type, int id);

/**
 * @brief           写入天赛数据
 * @param keys      关键字, @ref TessarKey
 * @param values    值, 顺序要和keys对应。
 * @param size      keys数组大小。
 * @param flag      是否去重，仅针对event。=0不去重，否则表示5s内若有相同事件，则本次不写入。
 * @return int
 * @retval >=0      实际写入参数数量
 * @warning         函数不检查values数组，使用时务必确保values数组内容和大小与key对应。
 */
int Zmf_TessarRecord(int keys[], int values[], const int size, int flag);

/**
 * @brief       设置天赛消息提醒回调。
 * @param       cookie      cookie
 * @param       pfnCb       回调函数， event: 回调消息类型,
 *                          info: 携带信息  ZmfTessarTimeOut - 没有数据输出持续时长
 *                                        ZmfTessarErrorOccured - 事件码
 * @param       eventMask   订阅消息类型掩码， @ref ZmfTessarInform
 * @note        此接口无返回值，也不会产生错误信息。
 */
void Zmf_TessarAddCallback(void* cookie, void (*pfnCb) (void* cookie, int event, int info), unsigned int eventMask);

/**
 * @brief       取消消息提醒。
 * @param       cookie  cookie
 * @note        此接口无返回值，也不会产生错误信息。
 */
void Zmf_TessarRemoveCallback(void* cookie);

/**
 * @brief       获得last error。
 * @param       code    错误码。格式 "[ErrorNumber][DomainCode]."
 * @param       msg     描述信息。
 * @return      返回错误值
 */
int Zmf_GetLastError(char code[16], char msg[2048]);
#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 */

#ifdef __GNUC__
#pragma GCC visibility pop
#endif
#endif
