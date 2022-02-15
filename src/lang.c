#include "include/opl.h"
#include "include/lang.h"
#include "include/util.h"
#include "include/fntsys.h"
#include "include/ioman.h"
#include "include/themes.h"

// Language support
static char *internalEnglish[LANG_STR_COUNT] = {
    "正體中文 (internal)",
    "保存設定",
    "返回",
    "網路設定",
    "進階設定",
    "<無數值>",
    "設定保存到 %s",
    "寫入設定錯誤!",
    "離開",
    "設定",
    "選單",
    "BDM 遊戲",
    "HDD 遊戲",
    "ETH 遊戲",
    "應用程式",
    "主題",
    "語言",
    "系統電源將會關閉",
    "退出到瀏覽介面?",
    "取消更新?",
    "%d: 檢測不到硬碟",
    "%d: 硬碟未格式化",
    "%d: 啟動網路錯誤",
    "%d: 檢測不到網卡",
    "%d: 無法連接 SMB 伺服器",
    "%d: 無法登入 SMB 伺服器",
    "%d: 無法開啟 SMB 共享",
    "%d: 無法列出 SMB 共享清單",
    "%d: 無法列出遊戲清單",
    "%d: DHCP 伺服器不存在",
    "%d: 無網路連接",
    "開啟",
    "關閉",
    "確定",
    "選擇",
    "取消",
    "◯",
    "✕",
    "遊戲列表",
    "遊戲設定",
    "刪除設定",
    "捲動速度",
    "較慢",
    "中等",
    "較快",
    "預設選單",
    "從光碟中讀取",
    "請稍後",
    "讀取 遊戲ID 時出錯",
    "自動排序",
    "載入語言檔案時出錯",
    "偵錯彩屏",
    "未偵測到控制器, 等待中...",
    "封面圖片",
    "寬螢幕",
    "關機",
    "設定讀取中...",
    "設定儲存中...",
    "啟動設備",
    "重新整理",
    "BDM 設備啟動模式",
    "HDD 設備啟動模式",
    "ETH 設備啟動模式",
    //START of OPL_DB tweaks
    "應用程式啟動模式",
    //END of OPL_DB tweaks
    "自動",
    "手動",
    "啟動 NBD 服務",
    "NBD 服務啟動中...",
    "NBD 服務正在運行...",
    "啟動 NBD 服務時出錯",
    "NBD 服務未能讀取...",
    "IGR 位置",
    "背景顏色",
    "文字顏色",
    "- SMB 伺服器 -",
    "IP 地址模式",
    "靜態",
    "DHCP",
    "IP 位址",
    "位址",
    "網路遮罩",
    "預設閘道",
    "DNS 伺服器",
    "通訊埠",
    "共享資料夾",
    "使用者",
    "密碼",
    "<無設定>",
    "位址格式",
    "IP",
    "NetBIOS",
    "允許",
    "項目將被永久刪除, 繼續嗎?",
    "重新命名",
    "刪除",
    "運行",
    "顯示設定",
    "啟用寫入操作",
    "紀錄最後運行遊戲",
    "確認鍵",
    "錯誤, 遊戲有碎片",
    "錯誤, 無法運行該項目",
    "測試修改",
    "GUEST驗證請留白",
    "精確讀取",
    "同步模式",
    "解除系統調用",
    "跳過影片",
    "模擬 DVD-DL",
    "禁用 IGR",
    "改變大小將會重新格式化 VMC",
    "生成",
    "開始",
    "變更",
    "放棄",
    "重置",
    "使用通用",
    "設定 VMC",
    "名稱",
    "大小",
    "狀態",
    "進度",
    "VMC 存檔已存在",
    "無效的 VMC 存檔, 大小有誤",
    "需要建立VMC 存檔",
    "訪問VMC %s 出錯。繼續使用插槽%d中的記憶卡 %d?",
    "自動重新整理",
    "關於",
    "程式",
    "測試",
    "BDM 前綴路徑",
    "自定義 IGR 啟動程式",
    "數值以分鐘計,設為 0 禁用降速",
    "自動 HDD 降速",
    "影像模式",
    "對話框顏色",
    "被選擇顏色",
    "重置顏色設定",
    "訊息",
    "自定義 ELF",
    "顏色選項",
    "重新連接",
    "列出共享清單請留白",
    "ETH 前綴路徑",
    "退格",
    "空格",
    "輸入",
    "模式",
    "VMC 插槽 1",
    "VMC 插槽 2",
    "遊戲 ID",
    "DMA 模式",
    "垂直同步",
    "模式 1",
    "模式 2",
    "模式 3",
    "模式 4",
    "模式 5",
    "模式 6",
    "設定 GSM",
    "乙太網連接模式",
    "100Mbit 全雙工",
    "100Mbit 半雙工",
    "10Mbit 全雙工",
    "10Mbit 半雙工",
    "GSM 設定",
    "GSM 選擇器",
    "切換 GSM 開或關",
    "強制自定義顯示模式",
    "水平調整",
    "調整水平方向的顯示位置",
    "垂直調整",
    "調整垂直方向的顯示位置",
    "Overscan",
    "Overscan 調整",
    "跳過 FMV",
    "跳過全動態影片",
    "金手指設定",
    "PS2RD 金手指引擎",
    "允許對選定遊戲使用PS2RD金手指",
    "PS2RD 金手指模式",
    "自動或手動選擇",
    "自動選擇",
    "手動選擇",
    "錯誤: 讀取金手指檔案出錯",
    "未發現金手指檔案",
    "下載預設設定",
    "網路更新",
    "覆蓋現有記錄",
    "更新失敗",
    "連結更新伺服器失敗",
    "更新已完成",
    "更新已取消",
    "從網路上下載設定檔?",
    "自定義設定",
    "已下載預設值",
    "將自動於 %i 秒後啟動...",
    "自動啟動",
    "以秒為單位,設為 0 禁用自動啟動",
    "PS2 Logo",
    "顯示與主機區域匹配的光碟 Logo",
    "設定PADEMU",
    "Pad 模擬器設定",
    "Pad 模擬器",
    "為選定遊戲開啟/關閉 Pad 模擬器",
    "Pad 模擬器連接模式",
    "選擇 Pad 模擬器連接模式",
    "DualShock3/4 USB",
    "DualShock3/4 藍牙",
    "設定埠:",
    "選擇應用的 Pad 模擬器埠",
    "模擬",
    "打開/關閉選定埠的模擬",
    "振動",
    "打開/關閉選定埠的振動",
    "藍牙適配器 MAC 位址:",
    "DS 控制器 MAC 位址:",
    "配對",
    "配對 DS 控制器",
    "藍牙適配器和 DS 控制器進行 MAC 地址配對",
    "無連接",
    "藍牙適配器資訊",
    "顯示更多的資訊和支援的功能",
    "HCI 版本:",
    "LMP 版本:",
    "製造商 ID:",
    "支援的功能:",
    "是",
    "否",
    "藍牙適配器完全相容 DS3/DS4 控制器",
    "藍牙適配器與 DS3/DS4 控制器不匹配",
    "分插模擬",
    "打開/關閉分插模擬",
    "模擬分插埠:",
    "選擇模擬的分插埠",
    "Fake DS3 Workaround",
    "部分 Fake DS3 需要 Workaround，開啟此選項啟用",
    "模擬播片掃描方式切換",
    "修正逐行模式下影片播放有問題的遊戲",
    "家長鎖設定",
    "家長鎖密碼",
    "留白將不啟用家長鎖",
    "輸入家長鎖密碼",
    "家長鎖密碼不正確",
    "已禁用家長鎖",
    "創建選項:",
    "錯誤 - 無法使用此密碼",
    "VMC %s 檔案碎片化.是否繼續使用插槽 %d 中的記憶卡？",
    "音訊設定",
    "效果音效",
    "啟動音效",
    "效果音效音量",
    "啟動音效音量",
    "確認視訊模式更改？",
    "快取遊戲列表 (硬碟)",
    "通知",
    "已從 %s 讀取設定",
    "已從 %s 讀取主題",
    "已從 %s 讀取語言",
    "%s 已掛載",
    "選項",
    "已保存遊戲設定",
    "已刪除 %s 設定",
    "啟用時覆蓋現有的遊戲相容性設定",
    "設定模式",
    "全局",
    "當前遊戲",
    "全部",
    "選擇要刪除的設定",
    "支援論壇:",
    "標題",
    "類型",
    "發行日",
    "開發商",
    "敘述",
    "Block 設備",
    "控制設定",
    "開啟或關閉 Block 設備管理器",
    "開啟或關閉 Block 設備 (e.g. USB)",
    "USB 遊戲",
    "iLink 遊戲",
    "MX4SIO 遊戲",
    // START of OPL_DB tweaks
    "PS1 遊戲",
    "PS1 遊戲啟動模式",
    "在 '%s' 沒有找到 POPSTARTER.ELF!",
    "在 '%s' 沒有找到 VCD 檔案!",
    "重新命名文件時發生錯誤",
    "刪除檔案時發生錯誤",
    "永遠不要購買OPEN-PS2-LOADER (OPL)，而是免費獲得:",
    "ifcaro OPL 版本從 psx-place.com",
    "OPL 日常開發版(DB)從 ps2-home.com",
    // END of OPL_DB tweaks
};

static int guiLangID = 0;
static char **lang_strs = internalEnglish;
static int nValidEntries = LANG_STR_COUNT;

static int nLanguages = 0;
static language_t languages[MAX_LANGUAGE_FILES];
static char **guiLangNames;

// localised string getter
char *_l(unsigned int id)
{
    return lang_strs[id];
}

static void lngFreeFromFile(char **lang_strs)
{
    if (guiLangID == 0)
        return;

    int strId = 0;
    for (; strId < nValidEntries; strId++) {
        free(lang_strs[strId]);
        lang_strs[strId] = NULL;
    }
    free(lang_strs);
    lang_strs = NULL;
}

static int lngLoadFont(const char *dir, const char *name)
{
    char path[256];

    snprintf(path, sizeof(path), "%sfont_%s.ttf", dir, name);
    LOG("LANG Custom TTF font path: %s\n", path);
    if (fntLoadDefault(path) == 0)
        return 0;

    snprintf(path, sizeof(path), "%sfont_%s.otf", dir, name);
    LOG("LANG Custom OTF font path: %s\n", path);
    if (fntLoadDefault(path) == 0)
        return 0;

    LOG("LANG cannot load font.\n");

    return -1;
}

static int lngLoadFromFile(char *path, char *name)
{
    char dir[128];

    file_buffer_t *fileBuffer = openFileBuffer(path, O_RDONLY, 1, 1024);
    if (fileBuffer) {
        // file exists, try to read it and load the custom lang
        char **curL = lang_strs;
        char **newL = (char **)calloc(LANG_STR_COUNT, sizeof(char *));

        int strId = 0;
        while (strId < LANG_STR_COUNT && readFileBuffer(fileBuffer, &newL[strId])) {
            strId++;
        }
        closeFileBuffer(fileBuffer);

        LOG("LANG Loaded %d entries\n", strId);

        int newEntries = strId;
        // if necessary complete lang with default internal
        while (strId < LANG_STR_COUNT) {
            LOG("LANG Default entry added: %s\n", internalEnglish[strId]);
            newL[strId] = internalEnglish[strId];
            strId++;
        }
        lang_strs = newL;
        lngFreeFromFile(curL);

        // remember how many entries were read from the file (for the free later)
        nValidEntries = newEntries;

        int len = strlen(path) - strlen(name) - 9; // -4 for extension,  -5 for prefix
        memcpy(dir, path, len);
        dir[len] = '\0';

        lngLoadFont(dir, name);

        return 1;
    }
    return 0;
}

char *lngGetValue(void)
{
    return guiLangNames[guiLangID];
}

static int lngReadEntry(int index, const char *path, const char *separator, const char *name, unsigned int mode)
{
    if (!S_ISDIR(mode)) {
        if (strstr(name, ".lng") || strstr(name, ".LNG")) {

            language_t *currLang = &languages[nLanguages + index];

            // filepath for this language file
            int length = strlen(path) + 1 + strlen(name) + 1;
            currLang->filePath = (char *)malloc(length * sizeof(char));
            sprintf(currLang->filePath, "%s%s%s", path, separator, name);

            // extract name for this language (will be used for the English translation)
            length = strlen(name) - 5 - 4 + 1;
            currLang->name = (char *)malloc(length * sizeof(char));
            memcpy(currLang->name, name + 5, length);
            currLang->name[length - 1] = '\0';

            /*file_buffer_t* fileBuffer = openFileBuffer(currLang->filePath, 1, 1024);
            if (fileBuffer) {
                // read localized name of language from file
                if (readLineContext(fileBuffer, &currLang->name))
                    readLineContext(fileBuffer, &currLang->fontName);
                closeFileBuffer(fileBuffer);
            }*/

            index++;
        }
    }
    return index;
}

static void lngRebuildLangNames(void)
{
    if (guiLangNames)
        free(guiLangNames);

    // build the languages name list
    guiLangNames = (char **)malloc((nLanguages + 2) * sizeof(char **));

    // add default internal (english)
    guiLangNames[0] = internalEnglish[0];

    int i = 0;
    for (; i < nLanguages; i++) {
        guiLangNames[i + 1] = languages[i].name;
    }

    guiLangNames[nLanguages + 1] = NULL;
}

int lngAddLanguages(char *path, const char *separator, int mode)
{
    int result;

    result = listDir(path, separator, MAX_LANGUAGE_FILES - nLanguages, &lngReadEntry);
    nLanguages += result;
    lngRebuildLangNames();

    const char *temp;
    if (configGetStr(configGetByType(CONFIG_OPL), "language_text", &temp)) {
        if (lngSetGuiValue(lngFindGuiID(temp)))
            moduleUpdateMenu(mode, 0, 1);
    }

    return result;
}

void lngInit(void)
{
    fntInit();

    lngAddLanguages(gBaseMCDir, "/", -1);
}

void lngEnd(void)
{
    lngFreeFromFile(lang_strs);

    int i = 0;
    for (; i < nLanguages; i++) {
        free(languages[i].name);
        free(languages[i].filePath);
    }

    free(guiLangNames);

    fntEnd();
}

int lngSetGuiValue(int langID)
{
    if (langID != -1) {
        if (guiLangID != langID) {
            if (langID != 0) {
                language_t *currLang = &languages[langID - 1];
                if (lngLoadFromFile(currLang->filePath, currLang->name)) {
                    guiLangID = langID;
                    thmSetGuiValue(thmGetGuiValue(), 1);
                    return 1;
                }
            }
            lang_strs = internalEnglish;
            guiLangID = 0;
            // lang switched back to internalEnglish, reload default font
            fntLoadDefault(NULL);
            thmSetGuiValue(thmGetGuiValue(), 1);
        }
    }
    return 0;
}

int lngGetGuiValue(void)
{
    return guiLangID;
}

int lngFindGuiID(const char *lang)
{
    if (lang) {
        int i = 0;
        for (; i < nLanguages; i++) {
            if (strcasecmp(languages[i].name, lang) == 0)
                return i + 1; // shift for Gui id
        }
    }
    return 0;
}

char **lngGetGuiList(void)
{
    return guiLangNames;
}

char *lngGetFilePath(int langID)
{
    language_t *currLang = &languages[langID - 1];
    char *path = currLang->filePath;

    return path;
}
