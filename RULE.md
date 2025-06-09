# 函数文档

## main.c 模块

### 1. HandleStartupMode
```c
static void HandleStartupMode(HWND hwnd)
```
**功能**：处理应用程序启动模式  
**参数**：
- hwnd: 主窗口句柄  
**描述**：根据配置的启动模式(CLOCK_STARTUP_MODE)设置相应的应用程序状态，包括计时模式、显示状态等。

### 2. WinMain
```c
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
```
**功能**：应用程序主入口点  
**参数**：
- hInstance: 当前实例句柄
- hPrevInstance: 前一个实例句柄(总是NULL)
- lpCmdLine: 命令行参数
- nCmdShow: 窗口显示方式  
**返回值**：程序退出码  
**描述**：初始化应用程序环境，创建主窗口，并进入消息循环。处理单实例检查，确保只有一个程序实例在运行。

### 3. DlgProc
```c
INT_PTR CALLBACK DlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
```
**功能**：对话框过程函数  
**参数**：
- hwndDlg: 对话框句柄
- msg: 消息类型
- wParam: 消息参数
- lParam: 消息参数  
**返回值**：消息处理结果  
**描述**：处理对话框消息。

### 4. ExitProgram
```c
void ExitProgram(HWND hwnd)
```
**功能**：退出程序  
**参数**：
- hwnd: 窗口句柄  
**描述**：执行程序退出前的清理工作。

## 全局变量
- `default_countdown_time`: 默认倒计时时间
- `CLOCK_DEFAULT_START_TIME`: 默认启动时间(秒)
- `elapsed_time`: 已经过时间
- `inputText[256]`: 输入文本缓冲区
- `message_shown`: 消息显示标志
- `last_config_time`: 最后配置时间
- `CLOCK_RECENT_FILES[MAX_RECENT_FILES]`: 最近文件列表
- `CLOCK_RECENT_FILES_COUNT`: 最近文件数量
- `CLOCK_TIMEOUT_WEBSITE_URL[MAX_PATH]`: 超时网站URL

## 外部变量
- `CLOCK_TEXT_COLOR[10]`: 时钟文本颜色
- `FONT_FILE_NAME[]`: 当前字体文件名
- `FONT_INTERNAL_NAME[]`: 字体内部名称
- `PREVIEW_FONT_NAME[]`: 预览字体文件名
- `PREVIEW_INTERNAL_NAME[]`: 预览字体内部名称
- `IS_PREVIEWING`: 是否正在预览字体

## timer.c 模块

### 1. InitializeHighPrecisionTimer
```c
BOOL InitializeHighPrecisionTimer(void)
```
**功能**：初始化高精度计时器  
**返回值**：成功返回TRUE，失败返回FALSE  
**描述**：初始化系统高精度计时器，获取计时器频率。

### 2. GetElapsedMilliseconds
```c
double GetElapsedMilliseconds(void)
```
**功能**：获取经过的毫秒数  
**返回值**：自上次调用以来的毫秒数  
**描述**：使用高精度计时器计算精确的时间间隔。

### 3. UpdateElapsedTime
```c
void UpdateElapsedTime(void)
```
**功能**：更新已用时间  
**描述**：根据当前计时模式(倒计时/正计时)更新已用时间计数。

### 4. FormatTime
```c
void FormatTime(int remaining_time, char* time_text)
```
**功能**：格式化时间显示  
**参数**：
- remaining_time: 剩余时间(秒)
- time_text: 输出缓冲区(至少9字节)  
**描述**：根据当前设置(24小时制/显示秒数)将秒数转换为"HH:MM:SS"格式。

### 5. ParseInput
```c
int ParseInput(const char* input, int* total_seconds)
```
**功能**：解析用户输入时间  
**参数**：
- input: 用户输入字符串
- total_seconds: 输出解析后的总秒数  
**返回值**：解析成功返回1，失败返回0  
**描述**：支持"MM:SS"、"HH:MM:SS"及纯数字秒数格式。

### 6. isValidInput
```c
int isValidInput(const char* input)
```
**功能**：验证时间输入格式  
**参数**：
- input: 待验证字符串  
**返回值**：有效返回1，无效返回0  
**描述**：检查输入是否符合时间格式规范。

### 7. ResetTimer
```c
void ResetTimer(void)
```
**功能**：重置计时器  
**描述**：重置计时器状态和计数，恢复初始设置。

### 8. TogglePauseTimer
```c
void TogglePauseTimer(void)
```
**功能**：切换暂停状态  
**描述**：切换计时器的暂停/继续状态。

### 9. WriteConfigDefaultStartTime
```c
void WriteConfigDefaultStartTime(int seconds)
```
**功能**：写入默认启动时间配置  
**参数**：
- seconds: 默认启动时间(秒)  
**描述**：更新配置文件中的默认启动时间设置。

### 10. WriteConfigStartupMode
```c
void WriteConfigStartupMode(const char* mode)
```
**功能**：写入启动模式配置  
**参数**：
- mode: 启动模式字符串("COUNTDOWN"/"COUNTUP")  
**描述**：修改配置文件中的默认计时模式设置。

## 全局变量(timer模块)
- `POMODORO_WORK_TIME`: 番茄钟工作时间(秒)
- `POMODORO_SHORT_BREAK`: 番茄钟短休息时间(秒)
- `POMODORO_LONG_BREAK`: 番茄钟长休息时间(秒)
- `POMODORO_LOOP_COUNT`: 番茄钟循环次数
- `CLOCK_IS_PAUSED`: 暂停状态标识
- `CLOCK_SHOW_CURRENT_TIME`: 显示实时时钟模式
- `CLOCK_USE_24HOUR`: 24小时制显示
- `CLOCK_SHOW_SECONDS`: 显示秒数
- `CLOCK_COUNT_UP`: 正计时模式开关
- `CLOCK_STARTUP_MODE[20]`: 启动模式
- `CLOCK_TOTAL_TIME`: 总计时时间(秒)
- `countdown_elapsed_time`: 倒计时已用时间
- `countup_elapsed_time`: 正计时累计时间
- `CLOCK_LAST_TIME_UPDATE`: 最后更新时间戳
- `last_displayed_second`: 上一次显示的秒数
- `countdown_message_shown`: 倒计时提示显示状态
- `countup_message_shown`: 正计时提示显示状态
- `pomodoro_work_cycles`: 番茄钟工作周期计数
- `CLOCK_TIMEOUT_ACTION`: 当前超时动作类型
- `CLOCK_TIMEOUT_TEXT[50]`: 超时提示文本内容
- `CLOCK_TIMEOUT_FILE_PATH[MAX_PATH]`: 超时打开文件路径
- `CLOCK_TIMEOUT_WEBSITE_URL[MAX_PATH]`: 超时打开网站URL
- `time_options[MAX_TIME_OPTIONS]`: 预设时间选项数组
- `time_options_count`: 有效选项数量

## window.c 模块

### 1. SetClickThrough
```c
void SetClickThrough(HWND hwnd, BOOL enable)
```
**功能**：设置窗口点击穿透属性  
**参数**：
- hwnd: 窗口句柄
- enable: 是否启用点击穿透  
**描述**：控制窗口是否让鼠标点击事件穿透到下层窗口。

### 2. SetBlurBehind
```c
void SetBlurBehind(HWND hwnd, BOOL enable)
```
**功能**：设置窗口背景模糊效果  
**参数**：
- hwnd: 窗口句柄
- enable: 是否启用模糊效果  
**描述**：控制窗口背景是否应用DWM模糊效果。

### 3. AdjustWindowPosition
```c
void AdjustWindowPosition(HWND hwnd, BOOL forceOnScreen)
```
**功能**：调整窗口位置  
**参数**：
- hwnd: 窗口句柄
- forceOnScreen: 是否强制窗口在屏幕内  
**描述**：确保窗口位置在屏幕边界内。

### 4. SaveWindowSettings
```c
void SaveWindowSettings(HWND hwnd)
```
**功能**：保存窗口设置  
**参数**：
- hwnd: 窗口句柄  
**描述**：将窗口的当前位置、大小和缩放状态保存到配置文件。

### 5. LoadWindowSettings
```c
void LoadWindowSettings(HWND hwnd)
```
**功能**：加载窗口设置  
**参数**：
- hwnd: 窗口句柄  
**描述**：从配置文件加载窗口的位置、大小和缩放状态。

### 6. InitDWMFunctions
```c
BOOL InitDWMFunctions(void)
```
**功能**：初始化DWM模糊功能  
**返回值**：初始化是否成功  
**描述**：加载并初始化DWM API函数指针。

### 7. HandleMouseWheel
```c
BOOL HandleMouseWheel(HWND hwnd, int delta)
```
**功能**：处理窗口鼠标滚轮消息  
**参数**：
- hwnd: 窗口句柄
- delta: 滚轮滚动量  
**返回值**：是否处理了消息  
**描述**：在编辑模式下调整窗口大小。

### 8. HandleMouseMove
```c
BOOL HandleMouseMove(HWND hwnd)
```
**功能**：处理窗口鼠标移动消息  
**参数**：
- hwnd: 窗口句柄  
**返回值**：是否处理了消息  
**描述**：在编辑模式下拖拽窗口。

### 9. CreateMainWindow
```c
HWND CreateMainWindow(HINSTANCE hInstance, int nCmdShow)
```
**功能**：创建并初始化主窗口  
**参数**：
- hInstance: 应用实例句柄
- nCmdShow: 显示命令参数  
**返回值**：创建的窗口句柄  
**描述**：创建应用程序的主窗口。

### 10. InitializeApplication
```c
BOOL InitializeApplication(HINSTANCE hInstance)
```
**功能**：初始化应用程序  
**参数**：
- hInstance: 应用程序实例句柄  
**返回值**：初始化是否成功  
**描述**：执行应用程序启动时的初始化工作。

### 11. OpenFileDialog
```c
BOOL OpenFileDialog(HWND hwnd, char* filePath, DWORD maxPath)
```
**功能**：打开文件选择对话框  
**参数**：
- hwnd: 父窗口句柄
- filePath: 存储选中文件路径的缓冲区
- maxPath: 缓冲区最大长度  
**返回值**：是否成功选择文件  
**描述**：显示标准文件选择对话框。

### 12. SetWindowTopmost
```c
void SetWindowTopmost(HWND hwnd, BOOL topmost)
```
**功能**：设置窗口置顶状态  
**参数**：
- hwnd: 窗口句柄
- topmost: 是否置顶  
**描述**：控制窗口是否始终显示在其他窗口之上。

## 全局变量(window模块)
- `CLOCK_BASE_WINDOW_WIDTH`: 基础窗口宽度
- `CLOCK_BASE_WINDOW_HEIGHT`: 基础窗口高度
- `CLOCK_WINDOW_SCALE`: 窗口缩放比例
- `CLOCK_WINDOW_POS_X`: 窗口X坐标
- `CLOCK_WINDOW_POS_Y`: 窗口Y坐标
- `CLOCK_EDIT_MODE`: 是否处于编辑模式
- `CLOCK_IS_DRAGGING`: 是否正在拖拽窗口
- `CLOCK_LAST_MOUSE_POS`: 上次鼠标位置
- `CLOCK_WINDOW_TOPMOST`: 窗口是否置顶
- `CLOCK_TEXT_RECT`: 文本区域矩形
- `CLOCK_TEXT_RECT_VALID`: 文本区域是否有效
- `CLOCK_FONT_SCALE_FACTOR`: 字体缩放比例
- `CLOCK_BASE_FONT_SIZE`: 基础字体大小

## tray.c 模块

### 1. RegisterTaskbarCreatedMessage
```c
void RegisterTaskbarCreatedMessage(void)
```
**功能**：注册TaskbarCreated消息  
**描述**：注册系统发送的TaskbarCreated消息，用于在资源管理器重启后重新创建托盘图标。

### 2. InitTrayIcon
```c
void InitTrayIcon(HWND hwnd, HINSTANCE hInstance)
```
**功能**：初始化系统托盘图标  
**参数**：
- hwnd: 与托盘图标关联的窗口句柄
- hInstance: 应用程序实例句柄  
**描述**：创建并显示带有默认设置的系统托盘图标。

### 3. RemoveTrayIcon
```c
void RemoveTrayIcon(void)
```
**功能**：删除系统托盘图标  
**描述**：从系统托盘中移除应用程序的图标。

### 4. ShowTrayNotification
```c
void ShowTrayNotification(HWND hwnd, const char* message)
```
**功能**：在系统托盘中显示通知  
**参数**：
- hwnd: 与通知关联的窗口句柄
- message: 要在通知中显示的文本消息  
**描述**：从系统托盘图标显示气球提示通知。

### 5. RecreateTaskbarIcon
```c
void RecreateTaskbarIcon(HWND hwnd, HINSTANCE hInstance)
```
**功能**：重新创建托盘图标  
**参数**：
- hwnd: 窗口句柄
- hInstance: 实例句柄  
**描述**：在Windows资源管理器重启后重新创建托盘图标。

### 6. UpdateTrayIcon
```c
void UpdateTrayIcon(HWND hwnd)
```
**功能**：更新托盘图标和菜单  
**参数**：
- hwnd: 窗口句柄  
**描述**：在应用程序语言或设置更改后更新托盘图标和菜单。

## 全局变量(tray模块)
- `nid`: NOTIFYICONDATAW结构，存储托盘图标信息
- `WM_TASKBARCREATED`: TaskbarCreated消息ID

## 宏定义(tray模块)
- `CLOCK_WM_TRAYICON`: 自定义托盘图标消息ID
- `CLOCK_ID_TRAY_APP_ICON`: 托盘图标标识ID

## config.c 模块

### 1. GetConfigPath
```c
void GetConfigPath(char* path, size_t size)
```
**功能**：获取配置文件路径  
**参数**：
- path: 存储路径的缓冲区
- size: 缓冲区大小  
**描述**：获取应用程序配置文件的完整路径。

### 2. ReadConfig
```c
void ReadConfig()
```
**功能**：读取配置文件  
**描述**：从配置文件中读取所有配置项。

### 3. WriteConfig
```c
void WriteConfig(const char* config_path)
```
**功能**：写入配置文件  
**参数**：
- config_path: 配置文件路径  
**描述**：将所有配置项写入配置文件。

### 4. ReadIniString
```c
DWORD ReadIniString(const char* section, const char* key, const char* defaultValue,
                   char* returnValue, DWORD returnSize, const char* filePath)
```
**功能**：读取INI文件字符串值  
**参数**：
- section: 节名
- key: 键名
- defaultValue: 默认值
- returnValue: 返回值缓冲区
- returnSize: 缓冲区大小
- filePath: 文件路径  
**返回值**：读取的字符串长度  
**描述**：从INI文件中读取字符串配置项。

### 5. WriteIniString
```c
BOOL WriteIniString(const char* section, const char* key, const char* value,
                   const char* filePath)
```
**功能**：写入INI文件字符串值  
**参数**：
- section: 节名
- key: 键名
- value: 值
- filePath: 文件路径  
**返回值**：写入是否成功  
**描述**：向INI文件中写入字符串配置项。

### 6. ReadIniInt
```c
int ReadIniInt(const char* section, const char* key, int defaultValue,
              const char* filePath)
```
**功能**：读取INI文件整数值  
**参数**：
- section: 节名
- key: 键名
- defaultValue: 默认值
- filePath: 文件路径  
**返回值**：读取的整数值  
**描述**：从INI文件中读取整数配置项。

### 7. WriteIniInt
```c
BOOL WriteIniInt(const char* section, const char* key, int value,
                const char* filePath)
```
**功能**：写入INI文件整数值  
**参数**：
- section: 节名
- key: 键名
- value: 值
- filePath: 文件路径  
**返回值**：写入是否成功  
**描述**：向INI文件中写入整数配置项。

### 8. ReadIniBool
```c
BOOL ReadIniBool(const char* section, const char* key, BOOL defaultValue,
                const char* filePath)
```
**功能**：读取INI文件布尔值  
**参数**：
- section: 节名
- key: 键名
- defaultValue: 默认值
- filePath: 文件路径  
**返回值**：读取的布尔值  
**描述**：从INI文件中读取布尔配置项。

### 9. WriteIniBool
```c
BOOL WriteIniBool(const char* section, const char* key, BOOL value,
                 const char* filePath)
```
**功能**：写入INI文件布尔值  
**参数**：
- section: 节名
- key: 键名
- value: 值
- filePath: 文件路径  
**返回值**：写入是否成功  
**描述**：向INI文件中写入布尔配置项。

### 10. FileExists
```c
BOOL FileExists(const char* filePath)
```
**功能**：检查文件是否存在  
**参数**：
- filePath: 文件路径  
**返回值**：文件是否存在  
**描述**：检查指定路径的文件是否存在。

### 11. CreateDefaultConfig
```c
void CreateDefaultConfig(const char* config_path)
```
**功能**：创建默认配置文件  
**参数**：
- config_path: 配置文件路径  
**描述**：创建包含默认配置的配置文件。

### 12. CheckAndCreateResourceFolders
```c
void CheckAndCreateResourceFolders()
```
**功能**：检查并创建资源文件夹  
**描述**：确保应用程序所需的资源文件夹存在。

### 13. LoadRecentFiles
```c
void LoadRecentFiles(void)
```
**功能**：加载最近文件列表  
**描述**：从配置文件中加载最近使用的文件列表。

### 14. SaveRecentFile
```c
void SaveRecentFile(const char* filePath)
```
**功能**：保存最近文件  
**参数**：
- filePath: 文件路径  
**描述**：将文件添加到最近文件列表并保存。

### 15. WriteConfigTimeoutAction
```c
void WriteConfigTimeoutAction(const char* action)
```
**功能**：写入超时动作配置  
**参数**：
- action: 超时动作  
**描述**：更新配置文件中的超时动作设置。

### 16. WriteConfigTimeOptions
```c
void WriteConfigTimeOptions(const char* options)
```
**功能**：写入时间选项配置  
**参数**：
- options: 时间选项  
**描述**：更新配置文件中的时间选项设置。

### 17. WriteConfigPomodoroTimes
```c
void WriteConfigPomodoroTimes(int work, int short_break, int long_break)
```
**功能**：写入番茄钟时间配置  
**参数**：
- work: 工作时间(秒)
- short_break: 短休息时间(秒)
- long_break: 长休息时间(秒)  
**描述**：更新配置文件中的番茄钟时间设置。

### 18. WriteConfigPomodoroLoopCount
```c
void WriteConfigPomodoroLoopCount(int loop_count)
```
**功能**：写入番茄钟循环次数配置  
**参数**：
- loop_count: 循环次数  
**描述**：更新配置文件中的番茄钟循环次数设置。

### 19. WriteConfigTimeoutFile
```c
void WriteConfigTimeoutFile(const char* filePath)
```
**功能**：写入超时文件路径配置  
**参数**：
- filePath: 文件路径  
**描述**：更新配置文件中的超时文件路径设置。

### 20. WriteConfigTimeoutWebsite
```c
void WriteConfigTimeoutWebsite(const char* url)
```
**功能**：写入超时网站URL配置  
**参数**：
- url: 网站URL  
**描述**：更新配置文件中的超时网站URL设置。

### 21. WriteConfigPomodoroTimeOptions
```c
void WriteConfigPomodoroTimeOptions(int* times, int count)
```
**功能**：写入番茄钟时间选项配置  
**参数**：
- times: 时间选项数组
- count: 选项数量  
**描述**：更新配置文件中的番茄钟时间选项设置。

### 22. WriteConfigNotificationMessages
```c
void WriteConfigNotificationMessages(const char* timeout_msg, const char* pomodoro_msg, const char* cycle_complete_msg)
```
**功能**：写入通知消息配置  
**参数**：
- timeout_msg: 超时消息
- pomodoro_msg: 番茄钟消息
- cycle_complete_msg: 循环完成消息  
**描述**：更新配置文件中的通知消息设置。

### 23. ReadNotificationMessagesConfig
```c
void ReadNotificationMessagesConfig(void)
```
**功能**：读取通知消息配置  
**描述**：从配置文件中读取通知消息设置。

### 24. WriteConfigNotificationTimeout
```c
void WriteConfigNotificationTimeout(int timeout_ms)
```
**功能**：写入通知超时配置  
**参数**：
- timeout_ms: 超时时间(毫秒)  
**描述**：更新配置文件中的通知超时设置。

### 25. ReadNotificationTimeoutConfig
```c
void ReadNotificationTimeoutConfig(void)
```
**功能**：读取通知超时配置  
**描述**：从配置文件中读取通知超时设置。

### 26. ReadNotificationOpacityConfig
```c
void ReadNotificationOpacityConfig(void)
```
**功能**：读取通知透明度配置  
**描述**：从配置文件中读取通知透明度设置。

### 27. WriteConfigNotificationOpacity
```c
void WriteConfigNotificationOpacity(int opacity)
```
**功能**：写入通知透明度配置  
**参数**：
- opacity: 透明度(0-100)  
**描述**：更新配置文件中的通知透明度设置。

### 28. ReadNotificationTypeConfig
```c
void ReadNotificationTypeConfig(void)
```
**功能**：读取通知类型配置  
**描述**：从配置文件中读取通知类型设置。

### 29. WriteConfigNotificationType
```c
void WriteConfigNotificationType(NotificationType type)
```
**功能**：写入通知类型配置  
**参数**：
- type: 通知类型  
**描述**：更新配置文件中的通知类型设置。

### 30. GetAudioFolderPath
```c
void GetAudioFolderPath(char* path, size_t size)
```
**功能**：获取音频文件夹路径  
**参数**：
- path: 路径缓冲区
- size: 缓冲区大小  
**描述**：获取应用程序音频文件夹的完整路径。

### 31. ReadNotificationSoundConfig
```c
void ReadNotificationSoundConfig(void)
```
**功能**：读取通知声音配置  
**描述**：从配置文件中读取通知声音设置。

### 32. WriteConfigNotificationSound
```c
void WriteConfigNotificationSound(const char* sound_file)
```
**功能**：写入通知声音配置  
**参数**：
- sound_file: 声音文件路径  
**描述**：更新配置文件中的通知声音设置。

### 33. ReadNotificationVolumeConfig
```c
void ReadNotificationVolumeConfig(void)
```
**功能**：读取通知音量配置  
**描述**：从配置文件中读取通知音量设置。

### 34. WriteConfigNotificationVolume
```c
void WriteConfigNotificationVolume(int volume)
```
**功能**：写入通知音量配置  
**参数**：
- volume: 音量(0-100)  
**描述**：更新配置文件中的通知音量设置。

### 35. HotkeyToString
```c
void HotkeyToString(WORD hotkey, char* buffer, size_t bufferSize)
```
**功能**：热键转字符串  
**参数**：
- hotkey: 热键值
- buffer: 字符串缓冲区
- bufferSize: 缓冲区大小  
**描述**：将热键值转换为可读字符串。

### 36. StringToHotkey
```c
WORD StringToHotkey(const char* str)
```
**功能**：字符串转热键  
**参数**：
- str: 热键字符串  
**返回值**：热键值  
**描述**：将热键字符串转换为热键值。

### 37. ReadConfigHotkeys
```c
void ReadConfigHotkeys(WORD* showTimeHotkey, WORD* countUpHotkey, WORD* countdownHotkey,
                     WORD* quickCountdown1Hotkey, WORD* quickCountdown2Hotkey, WORD* quickCountdown3Hotkey,
                     WORD* pomodoroHotkey, WORD* toggleVisibilityHotkey, WORD* editModeHotkey,
                     WORD* pauseResumeHotkey, WORD* restartTimerHotkey)
```
**功能**：读取热键配置  
**参数**：
- showTimeHotkey: 显示时间热键
- countUpHotkey: 正计时热键
- countdownHotkey: 倒计时热键
- quickCountdown1Hotkey: 快速倒计时1热键
- quickCountdown2Hotkey: 快速倒计时2热键
- quickCountdown3Hotkey: 快速倒计时3热键
- pomodoroHotkey: 番茄钟热键
- toggleVisibilityHotkey: 切换可见性热键
- editModeHotkey: 编辑模式热键
- pauseResumeHotkey: 暂停/继续热键
- restartTimerHotkey: 重置计时器热键  
**描述**：从配置文件中读取所有热键设置。

### 38. WriteConfigHotkeys
```c
void WriteConfigHotkeys(WORD showTimeHotkey, WORD countUpHotkey, WORD countdownHotkey,
                      WORD quickCountdown1Hotkey, WORD quickCountdown2Hotkey, WORD quickCountdown3Hotkey,
                      WORD pomodoroHotkey, WORD toggleVisibilityHotkey, WORD editModeHotkey,
                      WORD pauseResumeHotkey, WORD restartTimerHotkey)
```
**功能**：写入热键配置  
**参数**：
- showTimeHotkey: 显示时间热键
- countUpHotkey: 正计时热键
- countdownHotkey: 倒计时热键
- quickCountdown1Hotkey: 快速倒计时1热键
- quickCountdown2Hotkey: 快速倒计时2热键
- quickCountdown3Hotkey: 快速倒计时3热键
- pomodoroHotkey: 番茄钟热键
- toggleVisibilityHotkey: 切换可见性热键
- editModeHotkey: 编辑模式热键
- pauseResumeHotkey: 暂停/继续热键
- restartTimerHotkey: 重置计时器热键  
**描述**：向配置文件中写入所有热键设置。

### 39. ReadCustomCountdownHotkey
```c
void ReadCustomCountdownHotkey(WORD* hotkey)
```
**功能**：读取自定义倒计时热键  
**参数**：
- hotkey: 热键值  
**描述**：从配置文件中读取自定义倒计时热键。

### 40. WriteConfigKeyValue
```c
void WriteConfigKeyValue(const char* key, const char* value)
```
**功能**：写入键值对配置  
**参数**：
- key: 键名
- value: 值  
**描述**：向配置文件中写入任意键值对。

### 41. WriteConfigLanguage
```c
void WriteConfigLanguage(int language)
```
**功能**：写入语言配置  
**参数**：
- language: 语言ID  
**描述**：更新配置文件中的语言设置。

### 42. IsShortcutCheckDone
```c
bool IsShortcutCheckDone(void)
```
**功能**：检查快捷方式是否已创建  
**返回值**：快捷方式是否已创建  
**描述**：检查应用程序快捷方式是否已创建。

### 43. SetShortcutCheckDone
```c
void SetShortcutCheckDone(bool done)
```
**功能**：设置快捷方式检查状态  
**参数**：
- done: 是否已完成  
**描述**：设置应用程序快捷方式检查状态。

## 全局变量(config模块)
- `CLOCK_RECENT_FILES[MAX_RECENT_FILES]`: 最近文件列表
- `CLOCK_RECENT_FILES_COUNT`: 最近文件数量
- `CLOCK_DEFAULT_START_TIME`: 默认启动时间(秒)
- `last_config_time`: 最后配置时间
- `POMODORO_WORK_TIME`: 番茄钟工作时间(秒)
- `POMODORO_SHORT_BREAK`: 番茄钟短休息时间(秒)
- `POMODORO_LONG_BREAK`: 番茄钟长休息时间(秒)
- `CLOCK_TIMEOUT_MESSAGE_TEXT[100]`: 超时消息文本
- `POMODORO_TIMEOUT_MESSAGE_TEXT[100]`: 番茄钟超时消息文本
- `POMODORO_CYCLE_COMPLETE_TEXT[100]`: 番茄钟循环完成消息文本
- `NOTIFICATION_TIMEOUT_MS`: 通知超时时间(毫秒)
- `NOTIFICATION_TYPE`: 通知类型
- `NOTIFICATION_SOUND_FILE[MAX_PATH]`: 通知声音文件路径
- `NOTIFICATION_SOUND_VOLUME`: 通知音量(0-100)

## 宏定义(config模块)
- `MAX_RECENT_FILES`: 最大最近文件数(5)
- `INI_SECTION_GENERAL`: 一般设置节名
- `INI_SECTION_DISPLAY`: 显示设置节名
- `INI_SECTION_TIMER`: 计时器设置节名
- `INI_SECTION_POMODORO`: 番茄钟设置节名
- `INI_SECTION_NOTIFICATION`: 通知设置节名
- `INI_SECTION_HOTKEYS`: 热键设置节名
- `INI_SECTION_RECENTFILES`: 最近文件节名
- `INI_SECTION_COLORS`: 颜色选项节名
- `INI_SECTION_OPTIONS`: 其他选项节名

## notification.c 模块

### 1. ShowNotification
```c
void ShowNotification(HWND hwnd, const char* message)
```
**功能**：显示通知（根据配置的通知类型）  
**参数**：
- hwnd: 父窗口句柄
- message: 要显示的通知消息文本(UTF-8编码)  
**描述**：根据配置的通知类型显示不同风格的通知。

### 2. ShowToastNotification
```c
void ShowToastNotification(HWND hwnd, const char* message)
```
**功能**：显示自定义样式的提示通知  
**参数**：
- hwnd: 父窗口句柄
- message: 要显示的通知消息文本(UTF-8编码)  
**描述**：在屏幕右下角显示一个带动画效果的自定义通知窗口。

### 3. ShowModalNotification
```c
void ShowModalNotification(HWND hwnd, const char* message)
```
**功能**：显示系统模态对话框通知  
**参数**：
- hwnd: 父窗口句柄
- message: 要显示的通知消息文本(UTF-8编码)  
**描述**：显示一个阻塞的系统消息框通知。

### 4. CloseAllNotifications
```c
void CloseAllNotifications(void)
```
**功能**：关闭所有当前显示的Catime通知窗口  
**描述**：查找并关闭所有由Catime创建的通知窗口。

### 5. RegisterNotificationClass
```c
void RegisterNotificationClass(HINSTANCE hInstance)
```
**功能**：注册通知窗口类  
**参数**：
- hInstance: 应用程序实例句柄  
**描述**：注册用于显示自定义通知的窗口类。

### 6. NotificationWndProc
```c
LRESULT CALLBACK NotificationWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
```
**功能**：通知窗口消息处理  
**参数**：
- hwnd: 窗口句柄
- msg: 消息类型
- wParam: 消息参数
- lParam: 消息参数  
**返回值**：消息处理结果  
**描述**：处理通知窗口的所有消息。

### 7. DrawRoundedRectangle
```c
void DrawRoundedRectangle(HDC hdc, RECT rect, int radius)
```
**功能**：绘制圆角矩形  
**参数**：
- hdc: 设备上下文
- rect: 矩形区域
- radius: 圆角半径  
**描述**：在指定设备上下文中绘制圆角矩形。

## 全局变量(notification模块)
- `NOTIFICATION_TIMEOUT_MS`: 通知显示持续时间(毫秒)

## 枚举类型(notification模块)
- `AnimationState`: 动画状态枚举(ANIM_FADE_IN, ANIM_VISIBLE, ANIM_FADE_OUT)

## language.c 模块

### 1. GetLocalizedString
```c
const wchar_t* GetLocalizedString(const wchar_t* chinese, const wchar_t* english)
```
**功能**：获取本地化字符串  
**参数**：
- chinese: 简体中文版本的字符串
- english: 英语版本的字符串  
**返回值**：根据当前语言设置返回对应语言的字符串指针  
**描述**：根据当前语言设置自动返回对应语言的字符串。

### 2. SetLanguage
```c
BOOL SetLanguage(AppLanguage language)
```
**功能**：设置应用程序语言  
**参数**：
- language: 要设置的语言  
**返回值**：是否设置成功  
**描述**：手动设置应用程序语言，会自动重新加载对应语言的翻译文件。

### 3. GetCurrentLanguage
```c
AppLanguage GetCurrentLanguage(void)
```
**功能**：获取当前应用程序语言  
**返回值**：当前设置的语言  
**描述**：返回当前应用程序使用的语言设置。

### 4. LoadLanguageResource
```c
static int LoadLanguageResource(AppLanguage language)
```
**功能**：加载语言资源  
**参数**：
- language: 要加载的语言  
**返回值**：加载是否成功  
**描述**：从资源文件加载指定语言的翻译字符串。

### 5. DetectSystemLanguage
```c
static void DetectSystemLanguage()
```
**功能**：检测系统语言  
**描述**：根据系统UI语言设置自动检测并设置应用程序语言。

### 6. FindTranslation
```c
static const wchar_t* FindTranslation(const wchar_t* english)
```
**功能**：查找翻译字符串  
**参数**：
- english: 英文键  
**返回值**：找到的翻译字符串指针，未找到返回NULL  
**描述**：在已加载的翻译资源中查找对应的翻译字符串。

### 7. ParseIniLine
```c
static int ParseIniLine(const wchar_t* line)
```
**功能**：解析INI文件行  
**参数**：
- line: 要解析的行  
**返回值**：解析是否成功  
**描述**：解析语言资源INI文件中的单行内容。

### 8. UTF8ToWideChar
```c
static int UTF8ToWideChar(const char* utf8, wchar_t* wstr, int wstr_size)
```
**功能**：UTF8转宽字符  
**参数**：
- utf8: UTF8编码字符串
- wstr: 宽字符输出缓冲区
- wstr_size: 缓冲区大小  
**返回值**：转换后的字符数  
**描述**：将UTF8编码字符串转换为宽字符字符串。

### 9. GetLanguageResourceID
```c
static UINT GetLanguageResourceID(AppLanguage language)
```
**功能**：获取语言资源ID  
**参数**：
- language: 语言类型  
**返回值**：对应的资源ID  
**描述**：根据语言类型获取对应的资源文件ID。

## 全局变量(language模块)
- `CURRENT_LANGUAGE`: 当前应用程序使用的语言
- `g_translations[MAX_TRANSLATIONS]`: 翻译字符串数组
- `g_translation_count`: 已加载的翻译字符串数量

## 枚举类型(language模块)
- `AppLanguage`: 应用程序支持的语言枚举
  - `APP_LANG_CHINESE_SIMP`: 简体中文
  - `APP_LANG_CHINESE_TRAD`: 繁体中文
  - `APP_LANG_ENGLISH`: 英语
  - `APP_LANG_SPANISH`: 西班牙语
  - `APP_LANG_FRENCH`: 法语
  - `APP_LANG_GERMAN`: 德语
  - `APP_LANG_RUSSIAN`: 俄语
  - `APP_LANG_PORTUGUESE`: 葡萄牙语
  - `APP_LANG_JAPANESE`: 日语
  - `APP_LANG_KOREAN`: 韩语
  - `APP_LANG_COUNT`: 语言总数

## audio_player.c 模块

### 1. PlayNotificationSound
```c
BOOL PlayNotificationSound(HWND hwnd)
```
**功能**：播放通知音频  
**参数**：
- hwnd: 父窗口句柄  
**返回值**：成功返回TRUE，失败返回FALSE  
**描述**：播放配置的通知音频文件，如果文件不存在或播放失败则播放系统默认提示音。

### 2. PauseNotificationSound
```c
BOOL PauseNotificationSound(void)
```
**功能**：暂停当前播放的通知音频  
**返回值**：成功返回TRUE，失败返回FALSE  
**描述**：暂停当前正在播放的通知音频，仅当音频处于播放状态时有效。

### 3. ResumeNotificationSound
```c
BOOL ResumeNotificationSound(void)
```
**功能**：继续播放已暂停的通知音频  
**返回值**：成功返回TRUE，失败返回FALSE  
**描述**：继续播放之前被暂停的通知音频，仅当音频处于暂停状态时有效。

### 4. StopNotificationSound
```c
void StopNotificationSound(void)
```
**功能**：停止播放通知音频  
**描述**：停止当前正在播放的任何通知音频。

### 5. SetAudioVolume
```c
void SetAudioVolume(int volume)
```
**功能**：设置音频播放音量  
**参数**：
- volume: 音量百分比(0-100)  
**描述**：设置所有通知音频的播放音量。

### 6. SetAudioPlaybackCompleteCallback
```c
void SetAudioPlaybackCompleteCallback(HWND hwnd, AudioPlaybackCompleteCallback callback)
```
**功能**：设置音频播放完成回调  
**参数**：
- hwnd: 回调窗口句柄
- callback: 回调函数  
**描述**：设置音频播放完成时的回调通知。

### 7. CleanupAudioResources
```c
void CleanupAudioResources(void)
```
**功能**：清理音频资源  
**描述**：释放所有音频相关资源，停止任何正在播放的音频。

## 全局变量(audio_player模块)
- `g_audioEngine`: miniaudio引擎实例
- `g_sound`: 音频实例
- `g_engineInitialized`: 引擎初始化状态
- `g_soundInitialized`: 音频初始化状态
- `g_isPlaying`: 播放状态标识
- `g_isPaused`: 暂停状态标识
- `g_audioCompleteCallback`: 播放完成回调函数
- `g_audioCallbackHwnd`: 回调窗口句柄
- `g_audioTimerId`: 音频定时器ID

## 类型定义(audio_player模块)
- `AudioPlaybackCompleteCallback`: 音频播放完成回调函数类型

## drawing.c 模块

### 1. HandleWindowPaint
```c
void HandleWindowPaint(HWND hwnd, PAINTSTRUCT *ps)
```
**功能**：处理窗口绘制  
**参数**：
- hwnd: 窗口句柄
- ps: 绘制结构体  
**描述**：处理窗口的WM_PAINT消息，实现以下功能：
1. 创建内存DC双缓冲防止闪烁
2. 根据模式计算剩余时间/获取当前时间
3. 动态加载字体资源(支持实时预览)
4. 解析颜色配置(支持HEX/RGB格式)
5. 使用双缓冲机制绘制文本
6. 自动调整窗口尺寸适应文本内容

## 全局变量(drawing模块)
- `elapsed_time`: 已用时间(从window_procedure.c引入)

## font.c 模块

### 1. LoadFontFromResource
```c
BOOL LoadFontFromResource(HINSTANCE hInstance, int resourceId)
```
**功能**：从资源文件加载字体  
**参数**：
- hInstance: 应用程序实例句柄
- resourceId: 字体资源ID  
**返回值**：加载成功返回TRUE，失败返回FALSE  
**描述**：从应用程序资源中加载指定的字体资源。

### 2. LoadFontByName
```c
BOOL LoadFontByName(HINSTANCE hInstance, const char* fontName)
```
**功能**：按名称加载字体  
**参数**：
- hInstance: 应用程序实例句柄
- fontName: 字体名称  
**返回值**：加载成功返回TRUE，失败返回FALSE  
**描述**：根据字体名称加载对应的字体资源。

### 3. WriteConfigFont
```c
void WriteConfigFont(const char* font_file_name)
```
**功能**：写入字体配置  
**参数**：
- font_file_name: 字体文件名  
**描述**：将当前使用的字体配置写入配置文件。

### 4. ListAvailableFonts
```c
void ListAvailableFonts(void)
```
**功能**：列出可用字体  
**描述**：枚举系统中所有可用的字体。

### 5. PreviewFont
```c
BOOL PreviewFont(HINSTANCE hInstance, const char* fontName)
```
**功能**：预览字体  
**参数**：
- hInstance: 应用程序实例句柄
- fontName: 要预览的字体名称  
**返回值**：预览成功返回TRUE，失败返回FALSE  
**描述**：临时加载指定字体用于预览效果。

### 6. CancelFontPreview
```c
void CancelFontPreview(void)
```
**功能**：取消字体预览  
**描述**：取消当前的字体预览状态，恢复原字体。

### 7. ApplyFontPreview
```c
void ApplyFontPreview(void)
```
**功能**：应用字体预览  
**描述**：将预览的字体设置为当前使用的字体。

### 8. SwitchFont
```c
BOOL SwitchFont(HINSTANCE hInstance, const char* fontName)
```
**功能**：切换字体  
**参数**：
- hInstance: 应用程序实例句柄
- fontName: 要切换的字体名称  
**返回值**：切换成功返回TRUE，失败返回FALSE  
**描述**：将应用程序字体切换为指定字体。

## 全局变量(font模块)
- `FONT_FILE_NAME[100]`: 当前使用的字体文件名
- `FONT_INTERNAL_NAME[100]`: 字体内部名称
- `PREVIEW_FONT_NAME[100]`: 预览字体文件名
- `PREVIEW_INTERNAL_NAME[100]`: 预览字体内部名称
- `IS_PREVIEWING`: 是否正在预览字体
- `fontResources[]`: 字体资源数组
- `FONT_RESOURCES_COUNT`: 字体资源数量

## 类型定义(font模块)
- `FontResource`: 字体资源结构体

## color.c 模块

### 1. InitializeDefaultLanguage
```c
void InitializeDefaultLanguage(void)
```
**功能**：初始化默认语言和颜色设置  
**描述**：读取配置文件中的颜色设置，若未找到则创建默认配置。

### 2. AddColorOption
```c
void AddColorOption(const char* hexColor)
```
**功能**：添加颜色选项  
**参数**：
- hexColor: 颜色的十六进制值  
**描述**：添加一个颜色选项到全局颜色选项数组中。

### 3. ClearColorOptions
```c
void ClearColorOptions(void)
```
**功能**：清除所有颜色选项  
**描述**：释放所有颜色选项占用的内存，并重置颜色选项计数。

### 4. WriteConfigColor
```c
void WriteConfigColor(const char* color_input)
```
**功能**：将颜色写入配置文件  
**参数**：
- color_input: 要写入的颜色值  
**描述**：将指定的颜色值写入应用程序配置文件。

### 5. normalizeColor
```c
void normalizeColor(const char* input, char* output, size_t output_size)
```
**功能**：标准化颜色格式  
**参数**：
- input: 输入的颜色字符串
- output: 输出的标准化颜色字符串
- output_size: 输出缓冲区大小  
**描述**：将各种格式的颜色字符串转换为标准的十六进制颜色格式。

### 6. isValidColor
```c
BOOL isValidColor(const char* input)
```
**功能**：检查颜色是否有效  
**参数**：
- input: 要检查的颜色字符串  
**返回值**：颜色有效返回TRUE，否则返回FALSE  
**描述**：验证给定的颜色表示是否可以被解析为有效的颜色。

### 7. ColorEditSubclassProc
```c
LRESULT CALLBACK ColorEditSubclassProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
```
**功能**：颜色编辑框子类化处理  
**参数**：
- hwnd: 窗口句柄
- msg: 消息ID
- wParam: 消息参数
- lParam: 消息参数  
**返回值**：消息处理结果  
**描述**：处理颜色编辑框的消息事件，实现颜色预览功能。

### 8. ColorDlgProc
```c
INT_PTR CALLBACK ColorDlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
```
**功能**：颜色设置对话框处理  
**参数**：
- hwndDlg: 对话框窗口句柄
- msg: 消息ID
- wParam: 消息参数
- lParam: 消息参数  
**返回值**：消息处理结果  
**描述**：处理颜色设置对话框的消息事件。

### 9. IsColorExists
```c
BOOL IsColorExists(const char* hexColor)
```
**功能**：检查颜色是否已存在  
**参数**：
- hexColor: 十六进制颜色值  
**返回值**：颜色已存在返回TRUE，否则返回FALSE  
**描述**：检查指定的颜色是否已存在于颜色选项列表中。

### 10. ShowColorDialog
```c
COLORREF ShowColorDialog(HWND hwnd)
```
**功能**：显示颜色选择对话框  
**参数**：
- hwnd: 父窗口句柄  
**返回值**：选择的颜色值，取消返回(COLORREF)-1  
**描述**：显示Windows标准颜色选择对话框，允许用户选择颜色。

### 11. ColorDialogHookProc
```c
UINT_PTR CALLBACK ColorDialogHookProc(HWND hdlg, UINT msg, WPARAM wParam, LPARAM lParam)
```
**功能**：颜色对话框钩子处理  
**参数**：
- hdlg: 对话框窗口句柄
- msg: 消息ID
- wParam: 消息参数
- lParam: 消息参数  
**返回值**：消息处理结果  
**描述**：处理颜色选择对话框的自定义消息事件，实现颜色预览功能。

## 全局变量(color模块)
- `COLOR_OPTIONS`: 预定义颜色选项数组
- `COLOR_OPTIONS_COUNT`: 颜色选项数量
- `PREVIEW_COLOR[10]`: 预览颜色值
- `IS_COLOR_PREVIEWING`: 是否正在预览颜色
- `CLOCK_TEXT_COLOR[10]`: 当前文本颜色值

## 类型定义(color模块)
- `PredefinedColor`: 预定义颜色结构体
- `CSSColor`: CSS颜色名称结构体

## dialog_procedure.c 模块

### 1. DlgProc
```c
INT_PTR CALLBACK DlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
```
**功能**：输入对话框处理过程  
**参数**：
- hwndDlg: 对话框句柄
- msg: 消息类型
- wParam: 消息参数
- lParam: 消息参数  
**返回值**：消息处理结果  
**描述**：处理倒计时输入对话框的：
1. 控件初始化与焦点设置
2. 背景/控件颜色管理
3. 确定按钮点击处理
4. 回车键响应
5. 资源清理

### 2. ShowAboutDialog
```c
void ShowAboutDialog(HWND hwndParent)
```
**功能**：显示关于对话框  
**参数**：
- hwndParent: 父窗口句柄  
**描述**：显示包含程序版本、作者和第三方库信息的关于对话框。

### 3. AboutDlgProc
```c
INT_PTR CALLBACK AboutDlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
```
**功能**：关于对话框处理过程  
**参数**：
- hwndDlg: 对话框句柄
- msg: 消息类型
- wParam: 消息参数
- lParam: 消息参数  
**返回值**：消息处理结果  
**描述**：处理关于对话框的消息事件。

### 4. ShowErrorDialog
```c
void ShowErrorDialog(HWND hwndParent)
```
**功能**：显示错误对话框  
**参数**：
- hwndParent: 父窗口句柄  
**描述**：显示统一的错误提示对话框。

### 5. ShowPomodoroLoopDialog
```c
void ShowPomodoroLoopDialog(HWND hwndParent)
```
**功能**：显示番茄钟循环次数设置对话框  
**参数**：
- hwndParent: 父窗口句柄  
**描述**：显示用于设置番茄钟循环次数的对话框，允许用户输入1-99之间的循环次数。

### 6. PomodoroLoopDlgProc
```c
INT_PTR CALLBACK PomodoroLoopDlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
```
**功能**：番茄钟循环对话框处理过程  
**参数**：
- hwndDlg: 对话框句柄
- msg: 消息类型
- wParam: 消息参数
- lParam: 消息参数  
**返回值**：消息处理结果  
**描述**：处理番茄钟循环次数设置对话框的消息事件。

### 7. ShowWebsiteDialog
```c
void ShowWebsiteDialog(HWND hwndParent)
```
**功能**：显示网站URL输入对话框  
**参数**：
- hwndParent: 父窗口句柄  
**描述**：显示用于输入超时时打开的网站URL的对话框。

### 8. ShowPomodoroComboDialog
```c
void ShowPomodoroComboDialog(HWND hwndParent)
```
**功能**：显示番茄钟组合对话框  
**参数**：
- hwndParent: 父窗口句柄  
**描述**：显示用于设置番茄钟时间组合的对话框，允许用户输入自定义的番茄钟时间序列。

### 9. ParseTimeInput
```c
BOOL ParseTimeInput(const char* input, int* seconds)
```
**功能**：解析时间输入  
**参数**：
- input: 输入字符串 (如 "25m", "30s", "1h30m")
- seconds: 输出秒数  
**返回值**：解析成功返回TRUE，失败返回FALSE  
**描述**：将各种时间格式转换为秒数。

### 10. ShowNotificationMessagesDialog
```c
void ShowNotificationMessagesDialog(HWND hwndParent)
```
**功能**：显示通知消息设置对话框  
**参数**：
- hwndParent: 父窗口句柄  
**描述**：显示通知消息设置对话框，用于修改各种通知提示文本。

### 11. ShowNotificationDisplayDialog
```c
void ShowNotificationDisplayDialog(HWND hwndParent)
```
**功能**：显示通知显示设置对话框  
**参数**：
- hwndParent: 父窗口句柄  
**描述**：显示通知显示设置对话框，用于修改通知显示时间和透明度。

### 12. ShowNotificationSettingsDialog
```c
void ShowNotificationSettingsDialog(HWND hwndParent)
```
**功能**：显示整合后的通知设置对话框  
**参数**：
- hwndParent: 父窗口句柄  
**描述**：显示同时包含通知内容和通知显示设置的整合对话框。

## 全局变量(dialog_procedure模块)
- `g_hwndInputDialog`: 全局倒计时输入对话框句柄
- `g_hwndAboutDlg`: 关于对话框句柄
- `g_hwndErrorDlg`: 错误对话框句柄
- `inputText[256]`: 输入文本缓冲区
- `POMODORO_TIMES[MAX_POMODORO_TIMES]`: 番茄钟时间数组
- `POMODORO_TIMES_COUNT`: 番茄钟时间数量
- `wpOrigEditProc`: 原始编辑框过程

## window_events.c 模块

### 1. HandleWindowCreate
```c
BOOL HandleWindowCreate(HWND hwnd)
```
**功能**：处理窗口创建事件  
**参数**：
- hwnd: 窗口句柄  
**返回值**：处理结果  
**描述**：窗口创建时执行以下操作：
1. 加载窗口设置
2. 设置点击穿透状态
3. 设置窗口置顶状态

### 2. HandleWindowDestroy
```c
void HandleWindowDestroy(HWND hwnd)
```
**功能**：处理窗口销毁事件  
**参数**：
- hwnd: 窗口句柄  
**描述**：窗口销毁时执行以下操作：
1. 保存窗口设置
2. 移除托盘图标
3. 清理更新检查线程
4. 发送退出消息

### 3. HandleWindowReset
```c
void HandleWindowReset(HWND hwnd)
```
**功能**：处理窗口重置事件  
**参数**：
- hwnd: 窗口句柄  
**描述**：窗口重置时执行以下操作：
1. 强制设置窗口置顶状态
2. 确保窗口可见
3. 更新配置文件中的置顶设置

### 4. HandleWindowResize
```c
BOOL HandleWindowResize(HWND hwnd, int delta)
```
**功能**：处理窗口大小调整事件  
**参数**：
- hwnd: 窗口句柄
- delta: 鼠标滚轮增量  
**返回值**：是否处理了事件  
**描述**：调用drag_scale.c中的HandleScaleWindow函数处理窗口缩放

### 5. HandleWindowMove
```c
BOOL HandleWindowMove(HWND hwnd)
```
**功能**：处理窗口位置调整事件  
**参数**：
- hwnd: 窗口句柄  
**返回值**：是否处理了事件  
**描述**：调用drag_scale.c中的HandleDragWindow函数处理窗口拖拽

## timer_events.c 模块

### 1. HandleTimerEvent
```c
BOOL HandleTimerEvent(HWND hwnd, WPARAM wp)
```
**功能**：处理计时器消息  
**参数**：
- hwnd: 窗口句柄
- wp: 消息参数  
**返回值**：是否处理了消息  
**描述**：处理WM_TIMER消息，包括：
1. 倒计时模式：更新剩余时间并执行超时动作
2. 计时模式：累计已过时间
3. 显示当前时间模式

### 2. OnTimerTimeout
```c
void OnTimerTimeout(HWND hwnd)
```
**功能**：处理计时器超时事件  
**参数**：
- hwnd: 窗口句柄  
**描述**：根据配置执行超时动作：
1. 显示通知消息
2. 播放提示音
3. 执行系统操作（休眠/关机等）

### 3. InitializePomodoro
```c
void InitializePomodoro(void)
```
**功能**：初始化番茄钟状态  
**描述**：重置番茄钟相关变量：
1. 设置初始阶段为工作阶段
2. 重置时间索引
3. 重置已完成循环计数

## 全局变量(timer_events模块)
- `current_pomodoro_time_index`: 当前番茄钟时间索引
- `current_pomodoro_phase`: 当前番茄钟阶段
- `complete_pomodoro_cycles`: 已完成番茄钟循环数
- `g_clockState`: 计时器状态枚举
- `g_pomodoroState`: 番茄钟状态结构体

## update_checker.c 模块

### 1. CheckForUpdate
```c
void CheckForUpdate(HWND hwnd)
```
**功能**：检查应用程序更新  
**参数**：
- hwnd: 窗口句柄  
**描述**：
1. 连接到GitHub检查是否有新版本
2. 如果有更新，提示用户是否通过浏览器下载
3. 如果用户确认，打开浏览器到下载页面并退出程序

### 2. CheckForUpdateSilent
```c
void CheckForUpdateSilent(HWND hwnd, BOOL silentCheck)
```
**功能**：静默检查应用程序更新  
**参数**：
- hwnd: 窗口句柄
- silentCheck: 是否仅在有更新时显示提示  
**描述**：
1. 连接到GitHub检查新版本
2. 根据silentCheck参数决定是否显示无更新提示
3. 仅在有更新时才显示提示(silentCheck=TRUE)

### 3. CompareVersions
```c
int CompareVersions(const char* version1, const char* version2)
```
**功能**：比较版本号  
**参数**：
- version1: 第一个版本号
- version2: 第二个版本号  
**返回值**：
- 1: version1 > version2
- 0: version1 == version2  
- -1: version1 < version2  
**描述**：支持语义化版本号比较(如1.2.3)

### 4. ParseLatestVersionFromJson
```c
BOOL ParseLatestVersionFromJson(const char* jsonResponse, char* latestVersion, size_t maxLen, char* downloadUrl, size_t urlMaxLen)
```
**功能**：从JSON响应解析版本信息  
**参数**：
- jsonResponse: JSON响应字符串
- latestVersion: 存储最新版本号的缓冲区
- maxLen: 版本号缓冲区长度
- downloadUrl: 存储下载URL的缓冲区
- urlMaxLen: URL缓冲区长度  
**返回值**：解析成功返回TRUE，失败返回FALSE

### 5. OpenBrowserForUpdateAndExit
```c
BOOL OpenBrowserForUpdateAndExit(const char* url, HWND hwnd)
```
**功能**：打开浏览器下载更新并退出程序  
**参数**：
- url: 下载页面URL
- hwnd: 窗口句柄  
**返回值**：操作成功返回TRUE，失败返回FALSE

## 全局变量(update_checker模块)
- `GITHUB_API_URL`: GitHub API地址
- `USER_AGENT`: 用户代理字符串

## window_procedure.c 模块

### 1. WindowProcedure
```c
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
```
**功能**：主窗口消息处理函数  
**参数**：
- hwnd: 窗口句柄
- msg: 消息ID
- wp: 消息参数
- lp: 消息参数  
**返回值**：消息处理结果  
**描述**：处理应用程序主窗口的所有窗口消息，包括：
1. 创建和销毁事件
2. 绘制和重绘
3. 鼠标和键盘输入
4. 窗口位置和大小变化
5. 托盘图标事件
6. 菜单命令消息
7. 定时器事件

### 2. RegisterGlobalHotkeys
```c
BOOL RegisterGlobalHotkeys(HWND hwnd)
```
**功能**：注册全局热键  
**参数**：
- hwnd: 窗口句柄  
**返回值**：是否成功注册至少一个热键  
**描述**：从配置文件读取并注册全局热键设置，用于快速切换显示当前时间、正计时和默认倒计时。

### 3. UnregisterGlobalHotkeys
```c
void UnregisterGlobalHotkeys(HWND hwnd)
```
**功能**：取消注册全局热键  
**参数**：
- hwnd: 窗口句柄  
**描述**：取消注册所有已注册的全局热键。

### 4. ToggleShowTimeMode
```c
void ToggleShowTimeMode(HWND hwnd)
```
**功能**：切换到显示当前时间模式  
**参数**：
- hwnd: 窗口句柄  
**描述**：切换窗口显示模式为实时时钟。

### 5. StartCountUp
```c
void StartCountUp(HWND hwnd)
```
**功能**：开始正计时  
**参数**：
- hwnd: 窗口句柄  
**描述**：启动正计时模式，从0开始累计时间。

### 6. StartDefaultCountDown
```c
void StartDefaultCountDown(HWND hwnd)
```
**功能**：开始默认倒计时  
**参数**：
- hwnd: 窗口句柄  
**描述**：使用默认倒计时时间启动倒计时模式。

### 7. StartPomodoroTimer
```c
void StartPomodoroTimer(HWND hwnd)
```
**功能**：开始番茄钟  
**参数**：
- hwnd: 窗口句柄  
**描述**：启动番茄钟计时模式。

### 8. ToggleEditMode
```c
void ToggleEditMode(HWND hwnd)
```
**功能**：切换编辑模式  
**参数**：
- hwnd: 窗口句柄  
**描述**：切换窗口编辑模式，允许调整窗口大小和位置。

### 9. TogglePauseResume
```c
void TogglePauseResume(HWND hwnd)
```
**功能**：暂停/继续计时  
**参数**：
- hwnd: 窗口句柄  
**描述**：切换计时器的暂停/继续状态。

### 10. RestartCurrentTimer
```c
void RestartCurrentTimer(HWND hwnd)
```
**功能**：重新开始当前计时  
**参数**：
- hwnd: 窗口句柄  
**描述**：重置并重新启动当前计时模式。

### 11. StartQuickCountdown1
```c
void StartQuickCountdown1(HWND hwnd)
```
**功能**：快捷倒计时1  
**参数**：
- hwnd: 窗口句柄  
**描述**：使用预设时间选项中的第一项启动倒计时。

### 12. StartQuickCountdown2
```c
void StartQuickCountdown2(HWND hwnd)
```
**功能**：快捷倒计时2  
**参数**：
- hwnd: 窗口句柄  
**描述**：使用预设时间选项中的第二项启动倒计时。

### 13. StartQuickCountdown3
```c
void StartQuickCountdown3(HWND hwnd)
```
**功能**：快捷倒计时3  
**参数**：
- hwnd: 窗口句柄  
**描述**：使用预设时间选项中的第三项启动倒计时。

## 热键ID定义(window_procedure模块)
- `HOTKEY_ID_SHOW_TIME`: 显示当前时间热键ID
- `HOTKEY_ID_COUNT_UP`: 正计时热键ID
- `HOTKEY_ID_COUNTDOWN`: 倒计时热键ID
- `HOTKEY_ID_QUICK_COUNTDOWN1`: 快捷倒计时1热键ID
- `HOTKEY_ID_QUICK_COUNTDOWN2`: 快捷倒计时2热键ID
- `HOTKEY_ID_QUICK_COUNTDOWN3`: 快捷倒计时3热键ID
- `HOTKEY_ID_POMODORO`: 番茄钟热键ID
- `HOTKEY_ID_TOGGLE_VISIBILITY`: 隐藏/显示热键ID
- `HOTKEY_ID_EDIT_MODE`: 编辑模式热键ID
- `HOTKEY_ID_PAUSE_RESUME`: 暂停/继续热键ID
- `HOTKEY_ID_RESTART_TIMER`: 重新开始热键ID

## drag_scale.c 模块

### 1. HandleDragWindow
```c
BOOL HandleDragWindow(HWND hwnd)
```
**功能**：处理窗口拖动事件  
**参数**：
- hwnd: 窗口句柄  
**返回值**：是否处理了事件  
**描述**：在编辑模式下，处理鼠标拖动窗口的事件。根据鼠标移动距离更新窗口位置。

### 2. HandleScaleWindow
```c
BOOL HandleScaleWindow(HWND hwnd, int delta)
```
**功能**：处理窗口缩放事件  
**参数**：
- hwnd: 窗口句柄
- delta: 鼠标滚轮增量  
**返回值**：是否处理了事件  
**描述**：在编辑模式下，处理鼠标滚轮缩放窗口的事件。根据滚轮方向调整窗口和字体大小。

### 3. StartDragWindow
```c
void StartDragWindow(HWND hwnd)
```
**功能**：开始拖动窗口  
**参数**：
- hwnd: 窗口句柄  
**描述**：在编辑模式下，开始拖动窗口操作。记录初始鼠标位置并设置捕获。

### 4. EndDragWindow
```c
void EndDragWindow(HWND hwnd)
```
**功能**：结束拖动窗口  
**参数**：
- hwnd: 窗口句柄  
**描述**：结束拖动窗口操作。释放鼠标捕获并调整窗口位置。

### 5. StartEditMode
```c
void StartEditMode(HWND hwnd)
```
**功能**：开始编辑模式  
**参数**：
- hwnd: 窗口句柄  
**描述**：启用编辑模式前，确保窗口为置顶状态，记录原始置顶状态以便退出编辑模式时恢复。

### 6. EndEditMode
```c
void EndEditMode(HWND hwnd)
```
**功能**：结束编辑模式  
**参数**：
- hwnd: 窗口句柄  
**描述**：退出编辑模式，恢复窗口原始置顶状态，清除模糊效果并更新相关设置。

## 全局变量(drag_scale模块)
- `PREVIOUS_TOPMOST_STATE`: 记录编辑模式前的窗口置顶状态

## media.c 模块

### 1. PauseMediaPlayback
```c
void PauseMediaPlayback(void)
```
**功能**：暂停媒体播放  
**描述**：通过模拟媒体控制键的按键事件来暂停当前正在播放的媒体。包括停止和暂停/播放的组合操作，以确保媒体被正确暂停。  
**实现细节**：
1. 发送VK_MEDIA_STOP按键事件
2. 发送VK_MEDIA_PLAY_PAUSE按键事件(两次)
3. 包含适当的延迟确保操作可靠性

## audio_player.c 模块

### 1. InitializeAudioEngine
```c
static BOOL InitializeAudioEngine()
```
**功能**：初始化音频引擎  
**返回值**：初始化成功返回TRUE，失败返回FALSE  
**描述**：初始化miniaudio音频引擎，为后续音频播放做准备。

### 2. UninitializeAudioEngine
```c
static void UninitializeAudioEngine()
```
**功能**：卸载音频引擎  
**描述**：清理音频引擎资源，应在程序退出前调用。

### 3. PlayNotificationSound
```c
BOOL PlayNotificationSound(HWND hwnd)
```
**功能**：播放通知音频  
**参数**：
- hwnd: 父窗口句柄  
**返回值**：播放成功返回TRUE，失败返回FALSE  
**描述**：播放配置文件中指定的通知音频文件，如果文件无效则播放系统默认提示音。

### 4. PauseNotificationSound
```c
BOOL PauseNotificationSound(void)
```
**功能**：暂停当前播放的通知音频  
**返回值**：暂停成功返回TRUE，失败返回FALSE  
**描述**：暂停当前正在播放的音频，保持当前播放位置。

### 5. ResumeNotificationSound
```c
BOOL ResumeNotificationSound(void)
```
**功能**：继续播放已暂停的通知音频  
**返回值**：继续播放成功返回TRUE，失败返回FALSE  
**描述**：从暂停位置继续播放音频。

### 6. StopNotificationSound
```c
void StopNotificationSound(void)
```
**功能**：停止播放通知音频  
**描述**：立即停止当前播放的音频，释放相关资源。

### 7. SetAudioVolume
```c
void SetAudioVolume(int volume)
```
**功能**：设置音频播放音量  
**参数**：
- volume: 音量百分比(0-100)  
**描述**：调整所有音频播放的音量大小。

### 8. SetAudioPlaybackCompleteCallback
```c
void SetAudioPlaybackCompleteCallback(HWND hwnd, AudioPlaybackCompleteCallback callback)
```
**功能**：设置音频播放完成回调  
**参数**：
- hwnd: 回调窗口句柄
- callback: 回调函数指针  
**描述**：设置音频播放完成时的通知回调。

## 全局变量(audio_player模块)
- `g_audioEngine`: miniaudio引擎实例
- `g_sound`: 音频实例
- `g_engineInitialized`: 引擎初始化状态
- `g_soundInitialized`: 音频初始化状态
- `g_isPlaying`: 播放状态标志
- `g_isPaused`: 暂停状态标志
- `g_audioCompleteCallback`: 播放完成回调函数
- `g_audioCallbackHwnd`: 回调窗口句柄
- `g_audioTimerId`: 音频检查定时器ID

## notification.c 模块

### 1. ShowNotification
```c
void ShowNotification(HWND hwnd, const char* message)
```
**功能**：根据配置类型显示通知  
**参数**：
- hwnd: 父窗口句柄
- message: 通知消息文本(UTF-8编码)  
**描述**：根据NOTIFICATION_TYPE配置显示不同风格的通知：
1. NOTIFICATION_TYPE_CATIME: 自定义通知窗口
2. NOTIFICATION_TYPE_SYSTEM_MODAL: 系统模态对话框
3. NOTIFICATION_TYPE_OS: 系统托盘通知

### 2. ShowToastNotification
```c
void ShowToastNotification(HWND hwnd, const char* message)
```
**功能**：显示自定义Toast通知  
**参数**：
- hwnd: 父窗口句柄
- message: 通知消息文本(UTF-8编码)  
**描述**：在屏幕右下角显示带动画效果的自定义通知窗口，支持淡入淡出效果。

### 3. ShowModalNotification
```c
void ShowModalNotification(HWND hwnd, const char* message)
```
**功能**：显示系统模态对话框通知  
**参数**：
- hwnd: 父窗口句柄
- message: 通知消息文本(UTF-8编码)  
**描述**：创建新线程显示阻塞的系统消息框通知。

### 4. CloseAllNotifications
```c
void CloseAllNotifications(void)
```
**功能**：关闭所有Catime通知窗口  
**描述**：查找并关闭所有由Catime创建的通知窗口，无视当前显示时间设置。

### 5. NotificationWndProc
```c
LRESULT CALLBACK NotificationWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
```
**功能**：通知窗口消息处理函数  
**描述**：处理通知窗口的所有消息，包括绘制、动画计时器等。

### 6. RegisterNotificationClass
```c
void RegisterNotificationClass(HINSTANCE hInstance)
```
**功能**：注册通知窗口类  
**参数**：
- hInstance: 应用实例句柄  
**描述**：注册自定义通知窗口类。

### 7. DrawRoundedRectangle
```c
void DrawRoundedRectangle(HDC hdc, RECT rect, int radius)
```
**功能**：绘制圆角矩形  
**参数**：
- hdc: 设备上下文
- rect: 矩形区域
- radius: 圆角半径  
**描述**：用于绘制通知窗口的背景。

## 全局变量(notification模块)
- `NOTIFICATION_TIMEOUT_MS`: 通知显示时间(毫秒)
- `NOTIFICATION_TYPE`: 当前通知类型配置
