

# 1. 怎样接入文心一言
视频讲解：


[video(video-4zOgxQhB-1704373517751)(type-bilibili)(url-https://player.bilibili.com/player.html?aid=238157710)(image-https://img-blog.csdnimg.cn/img_convert/87ca554359ee9ef629e02dc3b8ab2072.jpeg)(title-【ESP32接入国产大模型之文心一言】)]

[【ESP32接入国产大模型之MiniMax】](https://vor2345.blog.csdn.net/article/details/136768206)
[【ESP32接入语言大模型之智谱清言】](https://vor2345.blog.csdn.net/article/details/135522961)
[【ESP32接入国产大模型之文心一言】](https://vor2345.blog.csdn.net/article/details/135372118)
[【ESP32接入语言大模型之通义千问】](https://blog.csdn.net/vor234/article/details/135395143)

下面是不标准测评，参考而已

|模型| 响应时间|内容质量|免费token次数|地址|
|--|--|--|--|--|
| MiniMax | 3s | 8分|50万|[https://www.minimaxi.com/](https://www.minimaxi.com/)|
| 智谱清言 | 7s | 8分|300万|[https://open.bigmodel.cn/](https://open.bigmodel.cn/)|
|文心一言 | 10s | 9分|500万|[https://cloud.baidu.com/doc/WENXINWORKSHOP/s/Nlks5zkzu](https://cloud.baidu.com/doc/WENXINWORKSHOP/s/Nlks5zkzu)|
| 通义千问 | 8s | 8分|800万|[https://tongyi.aliyun.com/qianwen/](https://tongyi.aliyun.com/qianwen/)|

随着人工智能技术的不断发展，自然语言处理领域也得到了广泛的关注和应用。在这个领域中，文心一言作为一款强大的自然语言处理工具，具有许多重要的应用价值。本文将重点介绍如何通过ESP32接入国产大模型之文心一言api，以及其中的重点词汇或短语。
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/28badf911cea40d1b143657ea5028cbf.png)

## 1.1 了解文心一言
文心一言是百度打造出来的人工智能大语言模型，具备跨模态、跨语言的深度语义理解与生成能力，文心一言有五大能力，文学创作、商业文案创作、数理逻辑推算、中文理解、多模态生成，其在搜索问答、内容创作生成、智能办公等众多领域都有更广阔的想象空间。文心一言企业服务由千帆大模型平台提供，包括推理服务及大模型微调等一系列开发和应用工具链。文心一言大模型现已升级至4.0，企业客户可通过百度智能云千帆大模型平台申请接入。

## 1.2 接入文心一言
API 列表
百度智能云千帆平台提供了丰富的API，保留对话Chat、续写Completions、向量Embeddings、插件应用、Prompt工程、大模型训练、管理及服务等API能力，详情请查看[API列表](https://cloud.baidu.com/doc/WENXINWORKSHOP/s/Nlks5zkzu)。

1. 大模型相关

>  - 对话Chat：支持创建chat，用于发起一次对话。
>  - 续写Completions：支持创建completion，用于发起一次续写请求，不支持多轮会话等。
>  - 向量Embeddings：支持Embeddings，用于根据输入内容生成对应的向量表示。 
>  - 自定义模型导入：支持HuggingFace Transformer架构的自定义模型导入，提供自定义模型导入相关API能力。 
>  - 图像Images：提供图像相关API能力。

2. 插件应用：提供域内知识搜索增强插件API相关能力。
3. Prompt工程：提供模版相关API能力。
4. 大模型训练：提供创建训练任务、任务运行、停止任务运行及获取任务运行详情等API能力。
5. 大模型管理：提供获取模型、模型版本详情及将训练任务发布为模型等API能力。
6. 大模型服务：提供创建服务、获取服务详情等API能力。

## 1.3 API 调用流程简介
API 的调用流程如下图所示。

![image.png](https://img-blog.csdnimg.cn/direct/4370f8719d734a8eabfcfd6e068f5c67.png)


1. 创建一个千帆应用。根据实际需求创建千帆应用，创建成功后，获取AppID、API Key、Secret Key 等信息。
2. API 授权。对应用的 AppID 进行授权。
3. 获取接口访问凭证 access_token 。根据第1步获取的 API Key 和 Secret Key ，调用获取[access_token](https://cloud.baidu.com/doc/WENXINWORKSHOP/s/Ilkkrb0i5)接口获取 access_token ，通过 access_token 鉴权调用者身份。
4. 调用API接口。例如调用ERNIE-Bot相关接口，详见[API列表](https://cloud.baidu.com/doc/WENXINWORKSHOP/s/Nlks5zkzu)。
## 1.4 API 调用流程
### 1.4.1 步骤一. 创建千帆应用
（1）登录百度智能云千帆控制台。

请您注册并登录[百度智能云千帆控制台](https://console.bce.baidu.com/qianfan/ais/console/applicationConsole/application) 。

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/4236758e8b8b441bbf35c5ddc5267d83.png)

注意：为保障服务稳定运行，账户最好不处于欠费状态。

（2）创建千帆应用

进入[控制台创建应用](https://console.bce.baidu.com/qianfan/ais/console/applicationConsole/application/create) 。

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/a2098963cb874d8f88ce46729a09990a.png)

（3）创建应用后，获取AppID、API Key、Secret Key。

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/3663d66252dc49a2bd68be78984270f5.png)


### 1.4.2 步骤二. 服务授权
应用创建后，选择对应授权的公有云服务。
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/6f0419fc30314b5888b5bf3e3f769d91.png)

### 1.4.3 步骤三. 调用API接口
调用千帆提供的相关接口，如ERNIE-Bot等，详见[API列表](https://cloud.baidu.com/doc/WENXINWORKSHOP/s/Nlks5zkzu)。
1. ERNIE-Bot
我们选择ERNIE-Bot：ERNIE-Bot是百度自行研发的大语言模型，覆盖海量中文数据，具有更强的对话问答、内容创作生成等能力。

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/b48fe35fc5c247e399f310715c74de82.png)

2. 在线调试
百度智能云千帆提供了 API在线调试平台-示例代码 ，用于帮助开发者调试接口，平台集成快速检索、查看开发文档、查看在线调用的请求内容和返回结果、复制和下载示例代码等功能，简单易用，更多内容请查看API在线调试介绍。
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/334e877312b64893b4dff45fae5fe7bf.png)

3. 获取AccessToken

应用列表选择自己创建的《ESP32语音聊天助手》，采用C#示例代码，
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/1ab8acfaff2041ac8a57bd113dad7b59.png)
然后点击调试，复制获取的AccessToken：`24.7cc213f615669e6191cf3f65fad26ed2.2592000.1706881758.282335-46332156`
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/df07085e0d414659809bcf4318bf4cdf.png)
1处粘贴上面的AccessToken，在2处中括号中输入

> "role":"user","content":"介绍一下你自己"

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/f12096b8387340b788d5e91bbccdc6ad.png)
调试结果如下
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/b3af286516054e66be872bdd494fd467.png)
查看C#代码需要三部分代码
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/755437958248499298e2569583b4bf9e.png)

```c
"https://aip.baidubce.com/rpc/2.0/ai_custom/v1/wenxinworkshop/chat/completions?access_token=24.7cc213f615669e6191cf3f65fad26ed2.2592000.1706881758.282335-46332156"
"Content-Type", "application/json"
"{""messages"":[{""role"":""user"",""content"":""介绍一下你自己""},{""role"":""assistant"",""content"":""您好，我是文心一言，英文名是ERNIE Bot。我能够与人对话互动，回答问题，协助创作，高效便捷地帮助人们获取信息、知识和灵感。""}],""disable_search"":false,""enable_citation"":false}"

```
# 2. 先决条件
在继续此项目之前，请确保检查以下先决条件。

我们将使用 Arduino IDE 对 ESP32/ESP8266 开发板进行编程，因此在继续本教程之前，请确保已在 Arduino IDE 中安装这些开发板。
## 2.1 环境配置
1. Arduino IDE：下载并安装 Arduino IDE；
2. ESP32 开发板库：在 Arduino IDE 中添加 ESP32 支持；
参考博客：[【esp32c3配置arduino IDE教程】](https://vor2345.blog.csdn.net/article/details/133853534)
为安装过程留出一些时间，具体时间可能因您的互联网连接而异。

## 2.2 所需零件
要学习本教程，您需要1个 ESP32 开发板（**推荐硬件，请不要使用esp8266，问就是不行**）。
 - 1 x ESP32（[阅读最佳 ESP32开发板](https://makeradvisor.com/esp32-development-boards-review-comparison/)) 

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/3279f0a0c4fc4e00a2cd7141caed3b2d.png)
简约版需要设置CDC下载，经典版直接下载
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/affaed0ed8d84533b373c1d170f847c7.jpeg)

# 3. 核心代码
esp32 Arduino代码如下

```c
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// 1. Replace with your network credentials
const char* ssid = "J09 502";
const char* password = "qwertyuiop111";

// Replace with your OpenAI API key
// const char* apiKey = "1CeoUoYgnfc6s5liNR2uoQrk";
// const char* secret_Key = "G3n9aHVerzGqr0EWsLnca0fVkiXI9BVz";
//const char* access_token = "24.01bb97173188a1a22d6a6991918f6508.2592000.1706880634.282335-46332156";
// Send request to OpenAI API
String inputText = "你好，文心一言";
// 2. Replace with your access_token
String apiUrl = "https://aip.baidubce.com/rpc/2.0/ai_custom/v1/wenxinworkshop/chat/completions?access_token=24.23087285c9ab53cbfd7aad5c032ae371.2592000.1706878581.282335-46332156";

String answer;
String getGPTAnswer(String inputText) {
  HTTPClient http;
  http.setTimeout(10000);
  http.begin(apiUrl);
  http.addHeader("Content-Type", "application/json");
  // http.addHeader("access_token", String(access_token));
  String payload = "{\"messages\":[{\"role\": \"user\",\"content\": \"" + inputText + "\"}],\"disable_search\": false,\"enable_citation\": false}";
  int httpResponseCode = http.POST(payload);
  if (httpResponseCode == 200) {
    String response = http.getString();
    http.end();
    Serial.println(response);

    // Parse JSON response
    DynamicJsonDocument jsonDoc(1024);
    deserializeJson(jsonDoc, response);
    String outputText = jsonDoc["result"];
    return outputText;
    // Serial.println(outputText);
  } else {
    http.end();
    Serial.printf("Error %i \n", httpResponseCode);
    return "<error>";
  }
}

void setup() {
  // Initialize Serial
  Serial.begin(115200);

  // Connect to Wi-Fi network
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  answer = getGPTAnswer(inputText);
  Serial.println("Answer: " + answer);
  Serial.println("Enter a prompt:");

}

void loop() {
  // do nothing
  if (Serial.available()) {
    inputText = Serial.readStringUntil('\n');
    // inputText.trim();
    Serial.println("\n Input:"+inputText);

    answer = getGPTAnswer(inputText);
    Serial.println("Answer: " + answer);
    Serial.println("Enter a prompt:");
  }
  // delay(2);
}

```


这段代码是一个基于Arduino平台（可能是ESP32或ESP8266）的示例，它通过WiFi连接到指定的无线网络，并利用HTTPClient库向百度文心一言API发送POST请求以获取AI生成的回答。以下是详细的解释：

1. 导入必要的库：

```c
#include <WiFi.h>：用于处理Wi-Fi连接功能。
#include <HTTPClient.h>：用于发送HTTP请求。
#include <ArduinoJson.h>：用于解析从服务器返回的JSON格式数据。
```

2. 第一处修改定义Wi-Fi网络凭证：

```c
const char* ssid = "J09 502";：Wi-Fi网络名。
const char* password = "qwertyuiop111";：Wi-Fi网络密码。
```

3. 第二处修改定义要调用的API地址：

```c
String apiUrl = "https://aip.baidubce.com/rpc/2.0/ai_custom/v1/wenxinworkshop/chat/completions?access_token=24.23087285c9ab53cbfd7aad5c032ae371.2592000.1706878581.282335-46332156";
```

4. 定义输入文本和函数 getGPTAnswer(String inputText)：
- 输入文本是固定的问候语"你好，文心一言"，在实际应用中可以根据需要修改。
- 函数 getGPTAnswer() 负责执行以下操作：
初始化HTTPClient对象并设置目标URL。设置Content-Type头信息，构造请求体payload，将用户输入的内容添加到JSON结构中。发送POST请求并检查HTTP响应码。如果响应码为200，则读取并解析返回的JSON数据，提取出结果字段作为回答。若非200，则返回错误字符串 "<error>"。
5. setup() 函数：
- 初始化串口通信， 连接到指定的Wi-Fi网络。
- 连接成功后，获取一个初始的回答并打印出来，然后提示用户输入新的问题。
6. loop() 函数：
- 检查串口是否有可用的数据输入。
- 如果有新输入，读取一行内容，调用 getGPTAnswer() 函数获取AI回答，并将对话过程输出到串口。

> 注意：虽然代码中有OpenAI API相关注释，但实际上该代码是针对百度文心一言API编写的。如果你想要与OpenAI
> API交互，你需要使用OpenAI提供的API URL、access token及相应的JSON结构进行请求。

# 4. 上传验证

打开串口监视器，==注意右下角选择换行符，选择115200波特率==，输入你想问的问题，他就可以回答你
## 4.1 测试对话
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/bc79daef274a4027b41f3b0d9e98a0cc.png)
## 4.2 报错
如果返回error ，大家对照列表查询错误代码，结合提示排查解决
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/e6e7b3fdc398426eb7bc015c52dd2751.png)

# 5. 总结


🥳🥳🥳现在，我们在本教程中，您学习了如何使用ESP32接入国产大模型之文心一言。🛹🛹🛹从而实现对外部世界进行感知，充分认识这个有机与无机的环境，后期会持续分享esp32跑freertos实用案列🥳🥳🥳科学地合理地进行创作和发挥效益，然后为人类社会发展贡献一点微薄之力。🤣🤣🤣
如果你有任何问题，可以通过下面的二维码加入鹏鹏小分队，期待与你思维的碰撞😘😘😘

