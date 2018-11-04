// ��������ػ����̣�search.c

#include <ansi.h>

string *lost_objs = ({
        "/clone/questob/bsdao",
        "/clone/questob/chouyin",
        "/clone/questob/guanyin",
        "/clone/questob/gumu",
        "/clone/questob/jinbagua",
        "/clone/questob/jinfw",
        "/clone/questob/jingui",
        "/clone/questob/jinyd",
        "/clone/questob/jinyt",
        "/clone/questob/longxu",
        "/clone/questob/maozy",
        "/clone/questob/plbi",
        "/clone/questob/ruyiqiu",
        "/clone/questob/xrzhi",
        "/clone/questob/xyta",
        "/clone/questob/yufo",
        "/clone/questob/yugy",
        "/clone/questob/yulong",
        "/clone/questob/zisj",
        "/clone/questob/zizhubi",
});

// ���ܹ�Ӧ��NPC��Ҫ����Щ�˱�����ָ���ĳ�������������ָ����
// �ǳ�����NPC��ID��
mapping rcv_npcs = ([
        "/d/city/duchang"          : "pang tongtuo",
        "/d/city/houyuan"          : "cui yuanwai",
        "/d/city/ymzhengting"      : "cheng yaofa",
        "/d/city/beidajie1"        : "ouyang ke",
        "/d/city/qianzhuang"       : "qian yankai",
        "/d/city/shuyuan"          : "zhu xi",
        "/d/city/zahuopu"          : "yang yongfu",
        "/d/city/garments"         : "zeng rou",
        "/d/city/lichunyuan"       : "wei chunfang",
        "/d/city/nanmen"           : "shi song",
        "/d/city/chaguan"          : "aqing sao",
        "/d/city/yaopu"            : "ping yizhi",
        "/d/city/wuguan"           : "chen youde",

        "/d/fuzhou/fzroad9"        : "jia renda",
        "/d/fuzhou/ximendajie"     : "cui biaotou",
        "/d/fuzhou/biaoju"         : "bai er",
        "/d/fuzhou/biaoju"         : "chen qi",
        "/d/fuzhou/biaojudy"       : "shi biaotou",
        "/d/fuzhou/biaojuzt"       : "lin zhennan",
        "/d/fuzhou/biaojuhy"       : "zheng biaotou",
        "/d/fuzhou/biaojunz"       : "wang furen",
        "/d/fuzhou/yamen"          : "ge shiha",
        "/d/fuzhou/shiqiao"        : "sha tianjiang",
        "/d/fuzhou/fzroad10"       : "yu renyan",

        "/d/xiangyang/westjie2"    : "wu santong",
        "/d/xiangyang/juyihuayuan" : "guo fu",
        "/d/xiangyang/jiangjuntang": "wang jian",
        "/d/xiangyang/dangpu"      : "qiu hang",
        "/d/xiangyang/xinluofang"  : "gaoli shang",
        "/d/xiangyang/mujiang"     : "mu jiang",
        "/d/xiangyang/qianzhuang"  : "huang zhen",

        "/d/beijing/kangfu_dating" : "kang qinwang",
        "/d/beijing/dangpu"        : "zhang degui",
        "/d/beijing/qingmu_dayuan" : "xuan zhen",
        "/d/beijing/liandan_yaoshi": "yao chun",
        "/d/beijing/gate"          : "tong zhaohe",
        "/d/beijing/quanjudeup"    : "cheng laoban",
        "/d/beijing/xiyuanup"      : "hua dan",
        "/d/beijing/xiyuanup"      : "lao dan",
        "/d/beijing/yihongyuan"    : "laobao po",
        "/d/beijing/xingchang"     : "guizi shou",
        "/d/beijing/zahuo"         : "hu zhanggui",
        "/d/beijing/mianguan"      : "shuaijiao touling",
        "/d/beijing/hai_dating"    : "duo long",
        "/d/beijing/hai_dating"    : "zheng keshuang",
        "/d/beijing/hai_dating"    : "feng xifan",
        "/d/beijing/huiyingup"     : "zhao min",
        "/d/beijing/weifu_men"     : "li lishi",
        "/d/beijing/weifu_dating"  : "gui erniang",
        "/d/beijing/weifu_dating"  : "gui xinshu",
        "/d/beijing/weifu_dating"  : "liu dahong",

        "/d/jingzhou/yaopu"        : "huatuo ershi",
        "/d/jingzhou/chaliao"      : "a fang",
        "/d/jingzhou/baita2"       : "shi ren",
        "/d/jingzhou/shuyuan"      : "xiao xiangzi",
        "/d/jingzhou/qianzhuang"   : "qian defa",
        "/d/jingzhou/ymzhengting"  : "ling situi",
        "/d/jingzhou/baita"        : "xiu cai",

        "/d/suzhou/yamen"          : "feng zhengdong",
        "/d/suzhou/jubaozhai"      : "sun baopi",
        "/d/suzhou/canlangting"    : "hong niang",
        "/d/suzhou/baodaiqiao"     : "jiao shi",
        "/d/suzhou/dangpu"         : "wang heji",
        "/d/suzhou/yamen"          : "zhen youqing",
        "/d/suzhou/shuchang"       : "gongzi ge",

        "/d/hangzhou/road12"       : "li kexiu",
        "/d/hangzhou/lingyinsi"    : "lao heshang",
        "/d/hangzhou/yaodian"      : "hu qingyu",
        "/d/hangzhou/marryroom"    : "hong niang",
        "/d/hangzhou/road17"       : "chu yuan",
        "/d/hangzhou/suti4"        : "li yuanzhi",
        "/d/hangzhou/road16"       : "bai zhen",
        "/d/hangzhou/road19"       : "long jun",
        "/d/hangzhou/liuzhuang"    : "guan jia",
        "/d/hangzhou/yuquan"       : "yue nv",

        "/d/kunming/kedian"        : "yuan cai",
        "/d/kunming/shufan"        : "wu sangui",
        "/d/kunming/dangpu"        : "liu tong",
        "/d/kunming/jinrilou"      : "fujia dizi",
        "/d/kunming/shilin1"       : "young boy",

        "/d/luoyang/kaoshi"        : "kao guan",
        "/d/luoyang/liangpu"       : "liangcao guan",
        "/d/luoyang/zuixianlou4"   : "li bai",
        "/d/luoyang/tangsancai"    : "qin zhanggui",
        "/d/luoyang/armor"         : "zhu zheng",
        "/d/luoyang/weapon"        : "zhu yin",
        "/d/luoyang/sishu"         : "xian sheng",
        "/d/luoyang/yuelao"        : "hong niang",
        "/d/luoyang/ciqi"          : "han yun",
        "/d/luoyang/xinluofang"    : "gaoli shang",
        "/d/luoyang/huqing"        : "hu xueyuan",
        "/d/luoyang/shudian"       : "shudian laoban",
        "/d/luoyang/dangpu"        : "qi laoer",
        "/d/luoyang/shuoshu"       : "cha boshi",
        "/d/luoyang/xiyuan"        : "hua dan",
        "/d/luoyang/xiyuan"        : "lao dan",
        "/d/luoyang/zahuopu"       : "xiao nanzhong",
        "/d/luoyang/jiyuan"        : "laobao po",
        "/d/luoyang/jiyuan2"       : "piao ke",
        "/d/luoyang/shoushi"       : "zhou yifeng",
        "/d/luoyang/muqipu"        : "lu kai",
        "/d/luoyang/miaopu"        : "hua nong",
        "/d/luoyang/suishi9"       : "duyuan chanshi",
        "/d/luoyang/xiaoshe"       : "lvzhu weng",

        "/d/lingzhou/neizai"       : "haolian tieshu",
        "/d/lingzhou/yipindayuan"  : "yun zhonghe",
        "/d/lingzhou/yipinjieyin"  : "nu erhai",
        "/d/lingzhou/yipinzhang"   : "zhang fang",

        "/d/lanzhou/beidajie1"     : "li wenxiu",
        "/d/lanzhou/qianzhuang"    : "qian mixin",
        "/d/lanzhou/nandajie1"     : "fujia dizi",

        "/d/city3/jiudian"         : "tang hua",
        "/d/city3/tidufu"          : "wu tiande",
        "/d/city3/chufang"         : "chu niang",
        "/d/city3/bingqidian"      : "tang huai",
        "/d/city3/wuguan"          : "ma wude",
        "/d/city3/wuguan"          : "lao zhangfang",
        "/d/city3/wuguanliu"       : "liu hongying",
        "/d/city3/wuguanchen"      : "chen hu",
        "/d/city3/wuguanxiao"      : "xiao fei",
        "/d/city3/wuguanlong"      : "long quan",

        "/d/foshan/yingxionglou"   : "feng qi",
        "/d/foshan/dangpu"         : "lao chaofeng",
        "/d/foshan/street3"        : "liumang tou",
        "/d/foshan/yingxionglou2"  : "pang shangren",
        "/d/foshan/yingxionglou2"  : "shou shangren",
        "/d/foshan/road8"          : "zhang chaotang",
        "/d/foshan/road8"          : "zhang kang",

        "/d/kaifeng/road4"         : "lu feiqing",
        "/d/kaifeng/tieta"         : "luo bing",
        "/d/kaifeng/tinyuan"       : "shi qing",
        "/d/kaifeng/datang"        : "bao zheng",
        "/d/kaifeng/chufang"       : "kong guanren",
        "/d/kaifeng/chufang"       : "liu caizhu",
        "/d/kaifeng/hh_damen"      : "yang chengxie",
        "/d/kaifeng/hh_damen"      : "jiang sigen",
        "/d/kaifeng/kaifeng"       : "zhang long",
        "/d/kaifeng/kaifeng"       : "zhao hu",
        "/d/kaifeng/yushi"         : "seng ren",
        "/d/kaifeng/tianwang"      : "seng ren",
        "/d/kaifeng/xianguosi"     : "seng ren",
        "/d/kaifeng/chufang2"      : "shaohuo seng",
        "/d/kaifeng/chufang2"      : "suzhai shifu",
        "/d/kaifeng/jiaomen"       : "zhang san",
        "/d/kaifeng/kongdi"        : "lu zhisheng",
        "/d/kaifeng/tangjian"      : "lao seng",

        "/d/changan/yamen-datang"  : "liang xinglu",
        "/d/changan/fangzhangshi"  : "huitong chanshi",
        "/d/changan/huozhan"       : "liang xilu",
        "/d/changan/huiwenge"      : "shu chi",
        "/d/changan/miao"          : "miao zhu",
        "/d/changan/mianguan"      : "lao zhang",
        "/d/changan/zahuopu"       : "liu laoshi",
        "/d/changan/xiaojiuguan"   : "ru hua",
        "/d/changan/xiaojiadt"     : "xiao yuanwai",
        "/d/changan/xiyuan"        : "xi zi",
        "/d/changan/yaopu"         : "shi jiugong",
        "/d/changan/weapon-shop"   : "murong hao",
        "/d/changan/shoushi-dian"  : "chen laoban",
        "/d/changan/bank"          : "tie gongji",
        "/d/changan/qunyulou1"     : "ling feixue",
        "/d/changan/duchang"       : "zhuang jia",
        "/d/changan/dangpu"        : "xiao wanxi",
        "/d/changan/jiulou2"       : "yang laoban",
        "/d/changan/zhubaohang"    : "jin fuhuan",
        "/d/changan/bridge1"       : "zhang heng",
        "/d/changan/bridge2"       : "xiao qun",
        "/d/changan/xunbufang"     : "bu tou",
        "/d/changan/yamen-datang"  : "chen jisheng",

        "/d/quanzhen/fu-woshi"     : "hou yuanwai",
        "/d/quanzhen/fu-zhangfang" : "guan jia",
        "/d/quanzhen/jiulou2"      : "zhang gui",
        "/d/quanzhen/dongmen"      : "wu jiang",
        "/d/quanzhen/ximen"        : "wu jiang",

        "/d/dali/qiandian"         : "duan zhengming",
        "/d/dali/wangfugate"       : "chu wanli",
        "/d/dali/tusifu"           : "da tusi",
        "/d/dali/tusiyishi"        : "da tusi",
        "/d/dali/stoneshop"        : "shi jiang",
        "/d/dali/garments"         : "xue laoban",
        "/d/dali/qingchi"          : "yideng dashi",
        "/d/dali/paifang"          : "hu yizhi",
        "/d/dali/wangfulu"         : "fu sigui",
        "d/dali/louti"             : "gao shengtai",
        "/d/dali/guibingshi2"      : "daizu shouling",
        "/d/dali/baiyiminju"       : "old man",

        "/d/zhongzhou/miaojia_men" : "zhong zhaowen",
        "/d/zhongzhou/congwu"      : "du dajin",
        "/d/zhongzhou/yaopuboss"   : "wu panbing",
]);

void startup();

// ������󴴽�
void create()
{
        seteuid(getuid());
        if (! clonep() && find_object(QUEST_D)) startup();
}

void start_quest()
{
        object qob;
        string qob_name;
        string room;
        object env;
        object npc;
        string *ob_names;
        string *env_rooms;
        object *obs;
        string zone, *files;

        // ѡ��һ���µĵص�(Ŀǰû��EXPLORE�����)
        env_rooms = keys(rcv_npcs);
        obs = children("/clone/quest/explore");
        if (arrayp(obs) && sizeof(obs) > 0)
                env_rooms -= obs->query("quest_position");

        if (sizeof(env_rooms) < 1)
                // �޷��ҵ������ĵص�
                return;

        room = env_rooms[random(sizeof(env_rooms))];
        env = get_object(room);

        // rcwiz add
        if (!objectp(env))return;

        // ѡ��õص��е���
        if (! objectp(npc = present(rcv_npcs[room], env)) ||
            npc->query("startroom") != base_name(env))
                // �޷��ҵ��õص��к��ʵ�NPC������
                return;

        // ����������������󣺱����п�����Ʒ����ǰ���� < 5
        ob_names = filter_array(lost_objs, (: ! find_object($1) || ! $1->query_temp("quest_ob") :));
        if (sizeof(ob_names) < 1)
                return;

        if (sizeof(children("/clone/quest/explore")) > 10)
                // ϵͳ�����15��Ѱ����Ʒ������
                return;

        // Ѱ��һ�����ñ���ĵص�
        if (sscanf(file_name(environment(npc)), "/d/%s/%*s", zone) == 2)
                zone = "/d/" + zone + "/";
        else
        {
                // ������һ����/d����ĵص�
                return;
        }
        files = get_dir(zone + "*.c");

        // ��ʼ�������һЩ��Ϣ�������ص㣩
        qob_name = ob_names[random(sizeof(ob_names))];
        qob = new("/clone/quest/explore");
        qob->set("quest_position", room);

        // ���������Լ����г�ʼ��
        qob->init_quest(npc, qob_name, zone, files);
        CHANNEL_D->do_channel(find_object(QUEST_D),
                              "sys", "����(EXPLORE)"
                              HIR "����" + qob_name->name() +
                              HIR "��" + npc->name() +
                              HIR "������һ������");
}

private void heart_beat()
{
        if (! find_object(QUEST_D))
                return;

        // ������ԣ�ÿ������(4����)����һ��QUEST
        start_quest();
}

// �����ػ����̻����������
void startup()
{
        // ����
        if (! find_object(QUEST_D))
                return;

        if (! query_heart_beat())
                CHANNEL_D->do_channel(find_object(QUEST_D),
                                      "sys", "����(EXPLORE)�����ˡ�");

        // ƽ��ÿ�ķ��Ӳ���һ������
        set_heart_beat(110 + random(20));
}

// ֹͣ����������
void stop()
{
        set_heart_beat(0);
}
