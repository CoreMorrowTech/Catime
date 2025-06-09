# Catime 项目目录结构说明

## 根目录文件
- `.gitignore` - Git版本控制忽略规则文件
- `LICENSE` - 项目许可证文件
- `PRIVACY.md` - 隐私政策文档
- `README-zh.md` - 中文项目说明文档
- `README.md` - 英文项目说明文档
- `xmake.lua` - Xmake构建配置文件

## asset/ 资源目录
### asset/font/ 字体资源
#### asset/font/MIT/ MIT许可证字体
- `LICENSE` - 字体许可证文件
- `ProFont IIx Nerd Font Essence.ttf` - 等宽编程字体

#### asset/font/OFL/ OFL许可证字体
- 包含多种OFL授权字体文件(.ttf)
- `OFL.txt` - Open Font License文件

#### asset/font/SIL/ SIL许可证字体
- 包含多种SIL授权字体文件(.ttf)
- `SIL Open Font License.txt` - SIL开源字体许可证

### asset/icon/ 图标资源
- `catime.ico` - 应用程序图标文件

## build/ 构建目录
- `.gitkeep` - 空文件，用于保持目录结构

## Images/ 图片资源
- `catime.png` - 应用主图标
- `catime_resize.png` - 调整大小的应用图标

## include/ 头文件目录
- `async_update_checker.h` - 异步更新检查器头文件
- `audio_player.h` - 音频播放功能头文件
- `color.h` - 颜色处理相关头文件
- `config.h` - 配置管理头文件
- `dialog_language.h` - 语言对话框头文件
- `dialog_procedure.h` - 对话框过程处理头文件
- `drag_scale.h` - 拖拽缩放功能头文件
- `drawing.h` - 绘图功能头文件
- `font.h` - 字体管理头文件
- `hotkey.h` - 热键功能头文件
- `language.h` - 多语言支持头文件
- `log.h` - 日志功能头文件
- `media.h` - 媒体处理头文件
- `notification.h` - 通知功能头文件
- `pomodoro.h` - 番茄钟功能头文件
- `shortcut_checker.h` - 快捷键检查器头文件
- `startup.h` - 启动配置头文件
- `timer_events.h` - 定时器事件头文件
- `timer.h` - 定时器功能头文件
- `tray_events.h` - 托盘事件处理头文件
- `tray_menu.h` - 托盘菜单头文件
- `tray.h` - 系统托盘功能头文件
- `update_checker.h` - 更新检查器头文件
- `window_events.h` - 窗口事件处理头文件
- `window_procedure.h` - 窗口过程处理头文件
- `window.h` - 窗口管理头文件

## libs/ 第三方库
### libs/miniaudio/ 音频库
- `miniaudio.c` - 音频库实现
- `miniaudio.h` - 音频库头文件

## resource/ 资源文件
- `about_dialog.rc` - 关于对话框资源
- `app.manifest` - 应用程序清单文件
- `catime.rc` - 主资源文件
- `color_dialog.rc` - 颜色对话框资源
- `countdown_dialog.rc` - 倒计时对话框资源
- `error_dialog.rc` - 错误对话框资源
- `hotkey_dialog.rc` - 热键对话框资源
- `languages.rc` - 语言资源
- `notification_dialog.rc` - 通知对话框资源
- `pomodoro_combo_dialog.rc` - 番茄钟组合对话框资源
- `pomodoro_loop_dialog.rc` - 番茄钟循环对话框资源
- `pomodoro_time_dialog.rc` - 番茄钟时间对话框资源
- `resource.h` - 资源定义头文件
- `resource.rc` - 主资源脚本
- `shortcut_dialog.rc` - 快捷键对话框资源
- `startup_dialog.rc` - 启动对话框资源
- `update_dialog.rc` - 更新对话框资源
- `website_dialog.rc` - 网站对话框资源

### resource/languages/ 语言文件
- 包含多种语言的.ini翻译文件(de,en,es,fr,ja,ko,pt,ru,zh_CN,zh-Hant)

## src/ 源代码文件
- `async_update_checker.c` - 异步更新检查器实现
- `audio_player.c` - 音频播放功能实现
- `color.c` - 颜色处理实现
- `config.c` - 配置管理实现
- `dialog_language.c` - 语言对话框实现
- `dialog_procedure.c` - 对话框过程处理实现
- `drag_scale.c` - 拖拽缩放功能实现
- `drawing.c` - 绘图功能实现
- `font.c` - 字体管理实现
- `hotkey.c` - 热键功能实现
- `language.c` - 多语言支持实现
- `log.c` - 日志功能实现
- `main.c` - 程序主入口
- `media.c` - 媒体处理实现
- `notification.c` - 通知功能实现
- `shortcut_checker.c` - 快捷键检查器实现
- `startup.c` - 启动配置实现
- `timer_events.c` - 定时器事件实现
- `timer.c` - 定时器功能实现
- `tray_events.c` - 托盘事件处理实现
- `tray_menu.c` - 托盘菜单实现
- `tray.c` - 系统托盘功能实现
- `update_checker.c` - 更新检查器实现
- `window_events.c` - 窗口事件处理实现
- `window_procedure.c` - 窗口过程处理实现
- `window.c` - 窗口管理实现
