// ��������ػ����̣�supply.c

#include <ansi.h>

// ��Ӧ����Ʒ�����ڽ��ܵ�ʱ��NPCֻ����˶��������֣���������
// MUD�еĴ���һ���Բ��õ�Ե�ʣ�������ÿ���ṩ����Ʒ���Ҫ��
// ���������Ҫ��MUD�е�������Ʒ������
string *supply_objs = ({
        "/clone/weapon/changjian",
        "/clone/weapon/jili",
        "/clone/weapon/tiegun",
        "/clone/weapon/zhubang",
        "/clone/weapon/zhujian",
        "/clone/weapon/changbian",
        "/clone/weapon/dagger",
        "/clone/weapon/duanjian",
        "/clone/weapon/dadao",
        "/clone/weapon/gangzhang",
        "/clone/weapon/tiejia",
        "/clone/weapon/hammer",
        "/clone/weapon/gangdao",
        "/clone/weapon/gangjian",
        "/clone/weapon/jiedao",
        "/clone/weapon/qimeigun",
        "/clone/weapon/mudao",
        "/clone/weapon/lianzi",
        "/clone/weapon/feihuangshi",
        "/clone/cloth/tiejia",
});

// ���ܹ�Ӧ��NPC��Ҫ����Щ�˱�����ָ���ĳ�������������ָ����
// �ǳ�����NPC��ID��
mapping rcv_npcs = ([

        "/d/city/duchang"          : "pang tongtuo",
        "/d/city/ymzhengting"      : "cheng yaofa",
        "/d/city/qianzhuang"       : "qian yankai",
        "/d/city/zahuopu"          : "yang yongfu",
        "/d/city/nanmen"           : "shi song",
        "/d/city/wuguan"           : "chen youde",

        "/d/fuzhou/fzroad9"        : "jia renda",
        "/d/fuzhou/ximendajie"     : "cui biaotou",
        "/d/fuzhou/biaoju"         : "bai er",
        "/d/fuzhou/biaoju"         : "chen qi",
        "/d/fuzhou/biaojudy"       : "shi biaotou",
        "/d/fuzhou/biaojuzt"       : "lin zhennan",
        "/d/fuzhou/biaojuhy"       : "zheng biaotou",
        "/d/fuzhou/yamen"          : "ge shiha",
        "/d/fuzhou/shiqiao"        : "sha tianjiang",
        "/d/fuzhou/fzroad10"       : "yu renyan",

        "/d/xiangyang/jiangjuntang": "wang jian",
        "/d/xiangyang/dangpu"      : "qiu hang",
        "/d/xiangyang/qianzhuang"  : "huang zhen",

        "/d/beijing/qingmu_dayuan" : "xuan zhen",
        "/d/beijing/gate"          : "tong zhaohe",
        "/d/beijing/yihongyuan"    : "laobao po",
        "/d/beijing/xingchang"     : "guizi shou",
        "/d/beijing/zahuo"         : "hu zhanggui",
        "/d/beijing/mianguan"      : "shuaijiao touling",
        "/d/beijing/hai_dating"    : "duo long",
        "/d/beijing/hai_dating"    : "zheng keshuang",
        "/d/beijing/hai_dating"    : "feng xifan",
        "/d/beijing/weifu_men"     : "li lishi",
        "/d/beijing/weifu_dating"  : "gui erniang",
        "/d/beijing/weifu_dating"  : "liu dahong",
        "/d/beijing/xichang"       : "tai jian",
        "/d/beijing/xichengmen"    : "du cha",

        "/d/jingzhou/qianzhuang"   : "qian defa",
        "/d/jingzhou/ymzhengting"  : "ling situi",

        "/d/suzhou/yamen"          : "feng zhengdong",
        "/d/suzhou/jubaozhai"      : "sun baopi",
        "/d/suzhou/yamen"          : "zhen youqing",
        "/d/suzhou/shuchang"       : "gongzi ge",
        "/d/suzhou/bingying"       : "wu jiang",
        "/d/suzhou/toumenshan"     : "jian ke",

        "/d/hangzhou/yaodian"      : "hu qingyu",
        "/d/hangzhou/road17"       : "chu yuan",
        "/d/hangzhou/suti4"        : "li yuanzhi",
        "/d/hangzhou/road16"       : "bai zhen",
        "/d/hangzhou/road19"       : "long jun",
        "/d/hangzhou/liuzhuang"    : "guan jia",

        "/d/kunming/kedian"        : "yuan cai",
        "/d/kunming/dangpu"        : "liu tong",
        "/d/kunming/jinrilou"      : "fujia dizi",

        "/d/luoyang/tangsancai"    : "qin zhanggui",
        "/d/luoyang/xinluofang"    : "gaoli shang",
        "/d/luoyang/huqing"        : "hu xueyuan",
        "/d/luoyang/shudian"       : "shudian laoban",
        "/d/luoyang/dangpu"        : "qi laoer",
        "/d/luoyang/zahuopu"       : "xiao nanzhong",
        "/d/luoyang/jiyuan"        : "laobao po",
        "/d/luoyang/jiyuan2"       : "piao ke",
        "/d/luoyang/shoushi"       : "zhou yifeng",

        "/d/lingzhou/neizai"       : "haolian tieshu",
        "/d/lingzhou/yipindayuan"  : "yun zhonghe",
        "/d/lingzhou/yipinjieyin"  : "nu erhai",
        "/d/lingzhou/yipinzhang"   : "zhang fang",
        "/d/lingzhou/xiaoxiaochang": "xixia bing",
        "/d/lingzhou/jiangjungate" : "xiao wei",

        "/d/lanzhou/qianzhuang"    : "qian mixin",
        "/d/lanzhou/nandajie1"     : "fujia dizi",

        "/d/city3/tidufu"          : "wu tiande",
        "/d/city3/wuguan"          : "ma wude",
        "/d/city3/wuguan"          : "lao zhangfang",
        "/d/city3/wuguanliu"       : "liu hongying",
        "/d/city3/wuguanchen"      : "chen hu",
        "/d/city3/wuguanxiao"      : "xiao fei",
        "/d/city3/wuguanlong"      : "long quan",

        "/d/foshan/yingxionglou"   : "feng qi",
        "/d/foshan/dangpu"         : "lao chaofeng",
        "/d/foshan/pm_restroom"    : "feng yiming",
        "/d/foshan/street3"        : "liumang tou",

        "/d/kaifeng/road4"         : "lu feiqing",
        "/d/kaifeng/hh_damen"      : "yang chengxie",
        "/d/kaifeng/hh_damen"      : "jiang sigen",
        "/d/kaifeng/kaifeng"       : "zhang long",
        "/d/kaifeng/kaifeng"       : "zhao hu",
        "/d/kaifeng/jiaomen"       : "zhang san",

        "/d/changan/yamen-datang"  : "liang xinglu",
        "/d/changan/huozhan"       : "liang xilu",
        "/d/changan/mianguan"      : "lao zhang",
        "/d/changan/zahuopu"       : "liu laoshi",
        "/d/changan/xiaojiadt"     : "xiao yuanwai",
        "/d/changan/shoushi-dian"  : "chen laoban",
        "/d/changan/duchang"       : "zhuang jia",
        "/d/changan/bridge1"       : "zhang heng",
        "/d/changan/bridge2"       : "xiao qun",
        "/d/changan/xunbufang"     : "bu tou",
        "/d/changan/yamen-datang"  : "chen jisheng",
        "/d/changan/biaoju-damen"  : "biaoshi",
        "/d/changan/qunyulou"      : "da shou",

        "/d/quanzhen/fu-woshi"     : "hou yuanwai",
        "/d/quanzhen/fu-zhangfang" : "guan jia",

        "/d/dali/wangfugate"       : "chu wanli",
        "/d/dali/tusifu"           : "da tusi",
        "/d/dali/tusiyishi"        : "da tusi",
        "/d/dali/garments"         : "xue laoban",
        "/d/dali/paifang"          : "hu yizhi",
        "/d/dali/wangfulu"         : "fu sigui",
        "/d/dali/louti"            : "gao shengtai",
        "/d/dali/guibingshi2"      : "daizu shouling",
        "/d/dali/bingying"         : "wei shi",

        "/d/zhongzhou/miaojia_men" : "zhong zhaowen",
        "/d/zhongzhou/congwu"      : "du dajin",

        "/d/shaolin/ruzhou"        : "wu jiang",
        "/d/shaolin/shanmen"       : "xu ming",
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
        object env;             // ������Ʒ��NPC���ڵĻ���
        object npc;             // ������Ʒ��NPC����
        object *obs;            // Ŀǰ���е�SUPPLY����
        string *env_room;       // �������ܹ��ڵĵص�
        string room;            // NPC���ڵĻ����ļ�����
        string sob_file;        // ���յ���Ʒ��Ӧ���ļ�

        object qob;             // �������

        // ѡ��һ���µĵص�(Ŀǰû��SUPPLY�����)
        env_room = keys(rcv_npcs);
        obs = children("/clone/quest/supply");
        if (arrayp(obs) && sizeof(obs) > 0)
                env_room -= obs->query("quest_position");

        if (sizeof(env_room) < 1)
                // �޷��ҵ������ĵص�
                return;

        room = env_room[random(sizeof(env_room))];
        env = get_object(room);

        // ѡ��ĵص��е���
        if (! objectp(npc = present(rcv_npcs[room], env)) ||
            npc->query("startroom") != base_name(env))
                // �޷��ҵ��õص��к��ʵ�NPC������
                return;


        // ѡ��һ�ֱ���
        sob_file = supply_objs[random(sizeof(supply_objs))];

        // ��ʼ�������һЩ��Ϣ�������ص㣩
        qob = new("/clone/quest/supply");
        qob->set("quest_position", room);

        CHANNEL_D->do_channel(find_object(QUEST_D),
                              "sys", "����(SUPPLY)��" + env->short(1) +
                              HIR "�ص�����" + npc->name() +
                              HIR "������һ������");

        // ���������Լ����г�ʼ��
        qob->init_quest(npc, sob_file);
}

private void heart_beat()
{
        if (! find_object(QUEST_D))
                return;

        // ������ԣ�ÿ����������һ��QUEST
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
                                      "sys", "����(SUPPLY)�����ˡ�");

        // ƽ��ÿ�ķ��Ӳ���һ������
        set_heart_beat(110 + random(20));
}

// ֹͣ����������
void stop()
{
        set_heart_beat(0);
}
