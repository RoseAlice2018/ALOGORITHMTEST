class Solution {
public:
    int nextGreaterElement(int n) {
        auto nums = to_string(n);
        int i = (int)nums.length() - 2;
        while(i >= 0 && nums[i] >= nums[i+1])
        {
            i--;
        }    
        if(i < 0)
        {
            return -1;
        }
        int j = nums.size() - 1;
        while(j >= 0 && nums[i] >= nums[j])
        {
            j--;
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        long ans = stol(nums);
        return ans > INT_MAX ? -1 : ans;
    }
};

Wayback Machine
https://blog.csdn.net/lyxx1021/article/details/107077579
2 captures
3 Jul 2022 - 3 Jul 2022
JUN	JUL	AUG
Previous capture	03	Next capture
2021	2022	2023
  
 About this capture
【Spring Boot + Datahub】阿里云流数据处理平台 基于2.15版本的数据读写【上】

帽子屋先生  于 2020-08-26 17:27:09 发布  3656  收藏 8
分类专栏： 架构学习 文章标签： java 队列 阿里云
版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。
本文链接：https://blog.csdn.net/lyxx1021/article/details/107077579
版权
 架构学习 专栏收录该内容
10 篇文章 0 订阅
订阅专栏
Datahub 2.15版本的数据读写
产品概述
产品优势
使用场景
数据总线服务器
datahub配置类的封装
yml 配置 (保密原因自我补全)
config配置类
核心线程池+主线程+工作线程
消费类
生产者工具类
产品概述
DataHub基本介绍
阿里云流数据处理平台DataHub是流式数据(Streaming Data)的处理平台，提供对流式数据的发布 (Publish)，订阅 (Subscribe)和分发功能，让您可以轻松构建基于流式数据的分析和应用。DataHub服务可以对各种移动设备，应用软件，网站服务，传感器等产生的大量流式数据进行持续不断的采集，存储和处理。用户可以编写应用程序或者使用流计算引擎来处理写入到DataHub的流式数据比如实时web访问日志、应用日志、各种事件等，并产出各种实时的数据处理结果比如实时图表、报警信息、实时统计等。

DataHub服务基于阿里云自研的飞天平台，具有高可用，低延迟，高可扩展，高吞吐的特点。DataHub与阿里云流计算引擎StreamCompute无缝连接，用户可以轻松使用SQL进行流数据分析。

DataHub服务也提供分发流式数据到各种云产品的功能，目前支持分发到MaxCompute(原ODPS)，OSS等。

系统整体功能图
在这里插入图片描述

产品优势
高吞吐
最高支持单shard每日8000万Record级别的写入量。

实时性
通过 DataHub ，您可以实时的收集各种方式生成的数据并进行实时的处理，对您的业务产生快速的响应。

易用性
DataHub 提供丰富的SDK包，包括C++, JAVA, Pyhon, Ruby, Go等语言。
DataHub服务也提供Restful API规范，您可以用自己的方式实现访问接口。
除了SDK以外，DataHub 还提供一些常用的客户端插件，包括：Fluentd，LogStash，Flume等。您可以使用这些客户端工具往 DataHub 里面写入流式数据。
DataHub 同时支持强Schema的结构化数据（创建Tuple类型的Topic）和无类型的非结构化数据（创建Blob类型的Topic），您可以自由选择。
高可用
服务可用性不低于99.9%。
规模自动扩展，不影响对外服务；数据持久性不低于99.999%。
数据自动多重冗余备份。
动态伸缩
每个主题(Topic)的数据流吞吐能力可以动态扩展和减少，最高可达到每主题256000 Records/s的吞吐量。

高安全性
提供企业级多层次安全防护，多用户资源隔离机制；
提供多种鉴权和授权机制及白名单、主子账号功能。

使用场景
在这里插入图片描述
DataHub作为一个流式数据处理服务，结合阿里云众多云产品，可以构建一站式的数据处理服务。

流计算StreamCompute
StreamCompute是阿里云提供的流计算引擎，提供使用类SQL的语言来进行流式计算。DataHub 和StreamCompute无缝结合，可以作为StreamCompute的数据源和输出源，具体可参考实时计算文档

aliyun-stream-dataflow

流处理应用
用户可以编写应用订阅DataHub中的数据，并进行实时的加工，把加工后的结果输出。用户可以把应用计算产生的结果输出到DataHub中，并使用另外一个应用来处理上一个应用生成的流式数据，来构建数据处理流程的DAG。

流式数据归档
用户的流式数据可以归档到 MaxCompute（原ODPS）中。用户通过创建DataHub Connector，指定相关配置，即可创建将Datahub中流式数据定期归档的同步任务。

以上来自于阿里云平台 Datahub在线文档

好了，先进入正题，Datahub 2.15版本是支持协同消费的，单是要保证阿里云数据总线服务器是最新版本的，否则是不支持协同消费类的，但是低版本数据总线服务器是支持高版本sdk向下兼容的

数据总线服务器
在这里插入图片描述
一开始我们新建一个项目
在这里插入图片描述
项目新建完成以后，再新建这个项目下的topic
在这里插入图片描述

datahub配置类的封装
pom依赖

yml 配置 (保密原因自我补全)
config配置类
核心线程池+主线程+工作线程
消费类
生产者工具类
帽子屋先生
关注
0
点赞

踩
 4
评论
8
收藏
打赏
打赏

扫一扫，分享内容

点击复制链接
专栏目录
datahub-client:用于使用DataHub的API（例如，推送或获取数据集）
05-12
节点客户端和实用程序，用于与进行交互并处理数据包。 介绍 平台存储许多不同的数据集-这些数据集是有用的数据包以及描述（此处是）。 存储在DataHub上的数据具有很好的结构，视图和描述，可帮助人们获得见解。 您还可以在DataHub上存储和共享自己的数据集 作为程序员，您可能希望自动化获取或存储数据的过程。 另外，您可能希望集成您的项目和DataHub。 datahub-client专门设计了datahub-client库。 让我们一起探索它。 重要笔记： 您需要使用Node version> 7.6 当您看到await关键字时，应该将代码的这种和平包装在async函数中。 安装 npm install datahub-client --save const datahub = require ( 'datahub-client' ) 快速概述 使用datahub-client
【starters】springboot-starter整合阿里云datahub
最新发布
haohaoxuexiyai的博客
04-05  686
文章目录1. 功能介绍2.快速开始2.1 启动客户端2.2 获取DataHub客户端2.3 写数据2.4 读数据3. 核心代码 DataHub 类似于传统大数据解决方案中 Kafka 的角色，提供了一个数据队列功能。 DataHub 除了供了一个缓冲的队列作用。同时由于 DataHub 提供了各种与其他阿里云 上下游产品的对接功能，所以 DataHub 又扮演了一个数据的分发枢纽工作。 datahub提供了开发者生产和消费的sdk，在平时的开发中往往会写很多重复的代码，我们可以利用springboot为我
评论 4 您还未登录，请先 登录 后发表或查看评论
DataHub简单的写入与获取demo
树洞树洞-单纯记录
06-11  5991
一、Maven依赖以及JDK 1. Maven Pom <dependency> <groupId>com.aliyun.datahub</groupId> <artifactId>aliyun-sdk-datahub</artifactId> <version>2.12.3-public<...
Datahub 根据传入的topic,查看相应的消费情况
tsgczf的博客
07-16  1439
public class Seek { private static Logger seekLog = Logger.getLogger(Seek.class.getName()); public static void main(String[] args) { if (args.length == 0) { System.out.pr...
springboot主项目打包，找不到符号，程序包不存在
qq_42714869的博客
05-19  639
主项目maven install打包报错如下： 项目结构，主项目data-center，集成bigdatabi项目、datahub项目： 1、主项目data-center结构如图 2、bigdatabi项目如图 3、datahub项目如图 产生问题的原因： 1、data-center以前只作为集成汇总项目，不写代码，但是由于特殊需要，在data-center里面写了代码，并且引用了datahub项目的代码 2、因为bigdatabi是一个pom项目，而datahub是jar
2020-09-07
weixin_49985645的博客
09-07  80
package zuoye20; // 导入 Scanner类 import java.util.Scanner; /** 需求：将指定数组元素值的位置前后互换，例如：[11, 32，55, 47，79，23] 置换后的数组元素为：[23, 79, 47, 55, 32, 11]，要求如下： 定义main方法，方法内完成： 1.定义一个整数数组arr; 2.键盘录入5个整数，并存入数组arr 3.定义一个新数组newArr 4.将指定数组arr的元素值的位置
datahub消费
wenzhenyu1990的专栏
01-11  398
datahub
SpringBoot Datahub DatahubException InjectionManagerFactory not found 暨 datahub中可能遇到的问题及解法
SeptDays的博客
10-22  573
产生原因: 依赖使用的是: compile (group: 'com.aliyun.datahub', name: 'aliyun-sdk-datahub', version: '2.12.0-public') 然后和之前自己加的包依赖产生冲突,看了下是sf4j-log4j和logback的冲突,logback是spring.boot依赖下的包,那自然要去掉datahub中s...
Datahub 入门之读取数据并消费到Hbase中
tsgczf的博客
07-16  4182
第一步： //new thread 消费datahub数据 SendData.toHbase(); 第二步： public class SendData{ public static void toHbase() { String accessId = DatahubConfig.accessId; String accessKey = Datahu...
阿里云 datahub python sdk补充（多shard订阅数据）
Great Expectations的博客
03-06  927
datahub 阿里云数据流处理通道 官方python sdk 只有单shards 案列，多shards数据订阅demo参考此文代码 发布数据(put)不指定shard_id默认轮询落shard #!/usr/bin/env python # -*- coding: utf-8 -*- # @Time : 2019-03-06 15:51 # @Author : yangshi...
阿里云常用产品汇总及解释
软件老王
05-19  1329
1. 场景描述 最近博客更新的少，跟朋友一起做些事情，最近主要给朋友做些售前工作，阿里云的产品线是真多，好多英文缩写，需要做沟通，系统汇总了一下，记录下，有需要的朋友拿走不谢。 2. 解决方案 从下面这个架构图开始吧： 2.1 云数据库 RDS 阿里云关系型数据库RDS（Relational Database Service）是一种稳定可靠、可弹性伸缩的在线数据库服务，提供容灾、备份、恢复、迁移等方面的全套解决方案，彻底解决数据库运维的烦恼。（软件老王） 2.2 ADB或ADS 云原生数据仓库Analyt
将SpringBoot项目（含数据库）部署到阿里云上详细教程
拧发条鸟的博客
04-30  2142
将SpringBoot项目（含数据库）部署到阿里云上 新用户特惠：https://www.aliyun.com/daily-act/ecs/activity_selection?utm_content=se_1008134918 免费试用： https://free.aliyun.com/product/product/ecs/freetrial?utm_content=se_1008957997 接下来的操作都是基于免费试用的服务器。 1.阿里云中的操作 购买时配置如下 购买成功后，等一会，
阿里云DataHub常见问题
lsj960922的博客
03-28  2689
FAQ常见问题1. 访问DataHub服务的域名是什么地区Region外网Endpoint经典网络ECS Endpoint（金融云）VPC ECS Endpoint华东1(杭州)dh-cn-hangzhouhttp://dh-cn-hangzhou.aliyuncs.comhttp://dh-cn-hangzhou.aliyun-inc.comhttp://dh-cn-hangzhou.aliyu...
datahub
weixin_30947043的博客
04-16  1203
shard自动分片 多个客户端订阅一个datahub TOPIC时， 服务端要考虑如何记录同步的点位 客户端自己维护订阅的点位， 比较麻烦 自动分片的时间间隔为分钟级 实现原理 通过心跳实现点位的同步, 每个consumer有拉数据线程和心跳线程 https://help.aliyun.com/document_detail/107957.html?spm=a2c4g.11186623.6.55...
阿里云产品之数据中台架构
软件老王
07-22  3386
1. 场景描述 客户打包买了很多阿里云的产品，但是阿里云不负责实施，基于阿里云产品与客户需求，拟采用的数据中台架构，有类似需求的，可以参考下，拿走不谢！ 2. 解决方案 阿里产品数据中台架构图： 从下到上，简要介绍下各个阿里产品作用及承担的任务： 2.1 云数据库 RDS 阿里云关系型数据库RDS（Relational Database Service）是一种稳定可靠、可弹性伸缩的在线数据库服务，提供容灾、备份、恢复、迁移等方面的全套解决方案，彻底解决数据库运维的烦恼。官方文档 2.2 数据传输DTS 数
DataHub Java接入实时数据
weixin_44058053的博客
12-11  6215
DataHub Java接入实时数据序言问题代码总结 序言 Datahub的相关介绍和优势，我在这里就不一一赘述，留个官方文档的连接（[DataHub官方文档](https://help.aliyun.com/document_detail/47439.html?spm=a2c0j.8235941.654670.ddoc.26d91a22JWAbt9)），大家可以自己去看看。我想在这里记录的是...
从datahub--streamingcomputer-tablestore
终生学习者的博客
07-24  144
表格存储只需要定义key 不用写value 在下面定义value就可以   CREATE TABLE st_rsvrfsr_b (     stcd VARCHAR,     bgmd VARCHAR,     edmd VARCHAR,     fsltdz BIGINT,     fsltdw BIGINT,     fstp VARCHAR,     moditime BI...
SpringBoot+Druid配置多数据源（注解切换）
qq_40823910的博客
08-15  1881
SpringBoot+Druid配置多数据源（注解切换）
学会DataHub服务让您可以轻松构建基于流式数据的分析和应用
京庐空间
09-14  1743
课程介绍 DataHub服务是阿里云提供的流式数据(Streaming Data)服务，它提供流式数据的发布 (Publish)和订阅 (Subscribe)的功能，让您可以轻松构建基于流式数据的分析和应用。 产品详情：https://data.aliyun.com/product/datahub 课时列表 课时1：初识DataHub 课时2：通过Connector同步到Odps
阿里云DataHub RestAPI使用示例
weixin_34216036的博客
01-05  466
概述 阿里云流数据处理平台DataHub是流式数据（Streaming Data）的处理平台，提供对流式数据的发布（Publish），订阅（Subscribe）和分发功能，让您可以轻松构建基于流式数据的分析和应用。目前官方提供了Java和Python的SDK，用户可以方便的使用SDK完成相关功能的集成开发。目前管理API还没有提供对应的SDK，本文以通用...
“相关推荐”对你有帮助么？
 
非常没帮助
 
没帮助
 
一般
 
有帮助
 
非常有帮助
请输入建议或反馈后点击提交
 提交
©️2022 CSDN 皮肤主题：大白 设计师：CSDN官方博客 返回首页

帽子屋先生 CSDN认证博客专家 CSDN认证企业博客
码龄10年  暂无认证
23
原创
25万+
周排名
181万+
总排名
9625
访问

等级
298
积分
7
粉丝
3
获赞
13
评论
29
收藏
分享小兵
分享达人
持之以恒
笔耕不辍
勤写标兵
学习力
原力新人
私信
关注
搜博主文章
 

热门文章
【Spring Boot + Datahub】阿里云流数据处理平台 基于2.15版本的数据读写【上】  2395
【idea】 使用idea远程调试Linux服务器线上运行jar包  769
【spring Boot】基于注解@Scheduled和基于接口SchedulingConfigurer的定时任务  676
java后台——http爬取图片，导出图片并打包。  486
spring cloud 微服务集成Nacos的注册中心和配置中心【上】  380
分类专栏
 架构学习 10篇
 工作记录 13篇
最新评论
【Spring Boot + Datahub】阿里云流数据处理平台 基于2.15版本的数据读写【上】
古酒道人: 建议仔细看看有无什么地方泄露了

【Spring Boot + Datahub】阿里云流数据处理平台 基于2.15版本的数据读写【上】
A努力中.......: aliyun-sdk-datahub和datahub-client-library各依赖版本对应图有嘛

spring cloud 微服务集成Nacos的注册中心和配置中心【下】
旺仔OO糖: 找了好多，你这里写的比较清楚

spring cloud 微服务集成Nacos的注册中心和配置中心【上】
旺仔OO糖: 受益匪浅。

【spring boot】spring boot项目架构学习总结【一】
water___Wang: 文章层次很清晰！优秀的文章~

您愿意向朋友推荐“博客详情页”吗？
 
强烈不推荐
 
不推荐
 
一般般
 
推荐
 
强烈推荐
请输入建议或反馈后点击提交
 提交
最新文章
【spring boot】spring boot项目架构学习总结【一】
【Mybatis】架构原理学习总结【四】
【Mybatis】架构原理学习总结【三】
2020年20篇
2019年3篇

目录

目录

分类专栏
 架构学习 10篇
 工作记录 13篇
目录
打赏作者


帽子屋先生

你的鼓励将是我创作的最大动力

¥2 ¥4 ¥6 ¥10 ¥20 
自定义
输入1-500的整数
  余额支付 (余额：-- )
  扫码支付
扫码支付：¥2
 获取中
  扫码支付
您的余额不足，请更换扫码支付或充值

打赏作者

实付元
使用余额支付
 点击重新获取
扫码支付
 钱包余额 0

抵扣说明：

1.余额是钱包充值的虚拟货币，按照1:1的比例进行支付金额的抵扣。
2.余额无法直接购买下载，可以购买VIP、C币套餐、付费专栏及课程。

余额充值
 新手
引导  客服
举报
 返回
顶部