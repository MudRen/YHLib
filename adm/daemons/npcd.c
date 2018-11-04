// npcd.c

#pragma optimize
#pragma save_binary

#include <command.h>
#include <npc/name.h>
#include <npc/chinese.c>
#include <npc/japanese.c>
#include <npc/european.c>
#include <npc/masia.c>
#include <npc/indian.c>

#define HUANG_SHANG             "/kungfu/class/ultra/huang"
#define DUGU_QIUBAI             "/kungfu/class/ultra/dugu"
#define KUIHUA_TAIJIAN          "/kungfu/class/ultra/kuihua"
#define HUO_SHAN                "/kungfu/class/ultra/huoshan"

mapping place = ([
        "������"   : ({ "/d/luoyang/xidoor", "/d/luoyang/beidoor",
                        "/d/luoyang/dongdoor", "/d/luoyang/nandoor",
                        "/d/luoyang/juyi", "/d/luoyang/nantou",
                        "/d/luoyang/suanming", "/d/luoyang/laofang",
                        "/d/luoyang/center", "/d/luoyang/nantou2", }),
        "������"   : ({ "/d/beijing/tiananmen", "/d/beijing/dianmen",
                        "/d/beijing/huangling", "/d/beijing/wenmiao",
                        "/d/beijing/xingchang", "/d/beijing/minju_y",
                        "/d/beijing/mianguan", "/d/beijing/yong_3",
                        "/d/beijing/tiantan", "/d/beijing/caishi", }),
        "������"   : ({ "/d/changan/dong-chengmen", "/d/changan/nan-chengmen",
                        "/d/changan/xi-chengmen", "/d/changan/bei-chengmen",
                        "/d/changan/qinglong2", "/d/changan/baihu2", }),
        "�����"   : ({ "/d/kaifeng/road4", "/d/kaifeng/zhuque",
                        "/d/kaifeng/yanqing", "/d/kaifeng/huiguan",
                        "/d/kaifeng/nanying", "/d/kaifeng/fangsheng", }),
        "���ݳ�"   : ({ "/d/zhongzhou/shizhongxin", "/d/zhongzhou/nanmeng",
                        "/d/zhongzhou/beimen", "/d/zhongzhou/chenglou",
                        "/d/zhongzhou/yanlingdong1", "/d/zhongzhou/inpomiao", }),
        "���ݳ�"   : ({ "/d/suzhou/xidajie2", "/d/suzhou/dongdajie2",
                        "/d/suzhou/road5", "/d/suzhou/road1",
                        "/d/suzhou/gumujiaohe", "/d/suzhou/zhenquting", }),
        "���ݳ�"   : ({ "/d/hangzhou/suti2", "/d/hangzhou/jujingyuan",
                        "/d/hangzhou/liuzhuang", "/d/hangzhou/road19",
                        "/d/hangzhou/huangniling", "/d/hangzhou/qinglindong", }),
        "������"   : ({ "/d/xiangyang/westjie2", "/d/xiangyang/southjie2",
                        "/d/xiangyang/xiaorong1", "/d/xiangyang/zhonglie",
                        "/d/xiangyang/guangchang", "/d/xiangyang/dingzi", }),
        "���ݳ�"   : ({ "/d/city/beimen", "/d/city/nanmen",
                        "/d/city/ximen", "/d/city/dongmen", }),
        "������"   : ({ "/d/kunming/nandajie2", "/d/kunming/yunnan1",
                        "/d/kunming/xiaoximen", "/d/kunming/xiaolu", }),
        "���ݳ�"   : ({ "/d/jingzhou/guangchang", "/d/jingzhou/jznanmen",
                        "/d/jingzhou/wenquan", "/d/jingzhou/zizhulin", }),
        "���ݳ�"   : ({ "/d/lanzhou/guangchang", "/d/lanzhou/nroad1",
                        "/d/lanzhou/nanmen", "/d/lanzhou/ximen", }),
        "�ɶ���"   : ({ "/d/city3/southroad1", "/d/city3/qingyanggong",
                        "/d/city3/northroad2", "/d/city3/fuheqiaoe", }),
        "���ݳ�"   : ({ "/d/fuzhou/ximendajie", "/d/fuzhou/dongxiaojie",
                        "/d/fuzhou/nanmen", "/d/fuzhou/pingshan", }),
        "���ݳ�"   : ({ "/d/lingzhou/xidajie", "/d/lingzhou/nanmen",
                        "/d/lingzhou/dongdajie", }),
        "�书��"   : ({ "/d/quanzhen/xijie", "/d/quanzhen/nanjie", }),
        "Ȫ�ݳ�"   : ({ "/d/quanzhou/zhongxin", }),
        "��ɽ����" : ({ "/d/huashan/pingxinshi", "/d/village/square",
                        "/d/village/wexit", }),
        "�����Ǹ���" : ({ "/d/lingxiao/sroad5", "/d/lingxiao/bar", }),
        "�嶾�̸���" : ({ "/d/wudu/cun3", "/d/wudu/jiang2",
                          "/d/wudu/bianzhai1", "/d/wudu/milin4", }),
        "��ɽһ��" : ({ "/d/foshan/street1", "/d/foshan/southgate", }),
        "�Ϻ�һ��" : ({ "/d/xiakedao/xkroad4" }),
        "����һ��" : ({ "/d/shaolin/ruzhou" }),
        "��ɽһ��" : ({ "/d/songshan/tianzhongge", "/d/shaolin/shijie1",
                        "/d/shaolin/shijie8", }),
        "����ɽ"   : ({ "/d/quanzhen/shanlu1", "/d/quanzhen/shijie1",
                        "/d/quanzhen/shijie9", "/d/quanzhen/cuipinggu",
                        "/d/quanzhen/baishulin3", "/d/gumu/taiyi1",
                        "/d/gumu/shenheyuan", "/d/quanzhen/banshanting", }),
        "���޺�"   : ({ "/d/xingxiu/tianroad2", }),
        "��ɽ"     : ({ "/d/lingjiu/yan", }),
        "����"     : ({ "/d/guanwai/baihe", "/d/guanwai/road8",
                        "/d/guanwai/xuedi1", "/d/guanwai/beicheng",
                        "/d/guanwai/shanshenmiao" }),
        "����"     : ({ "/d/xingxiu/shamo5", "/d/baituo/gebi",
                        "/d/xueshan/shenghu", "/d/xueshan/hubian4",
                        "/d/xuedao/sroad3", "/d/xuedao/nroad6",
                        "/d/mingjiao/gebitan5", "/d/xingxiu/nanjiang2" }),
        "����һ��" : ({ "/d/dali/northgate", "/d/dali/southgate",
                        "/d/dali/shanlu2", "/d/dali/buxiongbu",
                        "/d/dali/jinzhihe", "/d/dali/xiaodao1",
                        "/d/dali/tianweijing", "/d/dali/wuding",
                        "/d/dali/luwang", "/d/dali/gudao",
                        "/d/dali/biluoxueshan", "/d/dali/zhenxiong",
                        "/d/dali/yixibu", "/d/dali/cangshanzhong",
                        "/d/dali/wumeng", "/d/dali/hongsheng", }),
]);

mapping levels = ([
//      combat_exp   skill_level
//      ��֤��ʮ����ǰ����������ɣ���ʮ��֮ǰ����ɡ�
        50000      : 20,                // level 1
        100000     : 30,                // level 2
        200000     : 40,                // level 3
        400000     : 50,                // level 4
        500000     : 120,               // level 5
        800000     : 150,               // level 6
        1200000    : 175,               // level 7
        1600000    : 200,               // level 8
        2000000    : 225,               // level 9
        2500000    : 250,               // level 10
        3000000    : 275,               // level 11
        4000000    : 300,               // level 12
        5500000    : 350,               // level 13
        7500000    : 400,               // level 14
        9000000    : 450,               // level 15
        15000000   : 500,               // level 16
]);

// return the character(ob) 's level, 0 is lowest
int check_level(object ob)
{
        int *exp;
        int i;

        exp = sort_array(keys(levels), 1);
        for (i = 0; i < sizeof(exp); i++)
                if (ob->query("combat_exp") < exp[i]) break;

        return i;
}

// set the the level of the npc's skill
void init_npc_skill(object ob, int lvl)
{
        int sk_lvl;
        string *ks;
        int i;
        int exp;

        if (lvl < 1) lvl = 1;
        if (lvl >= sizeof(levels)) lvl = sizeof(levels) - 1;

        exp = sort_array(keys(levels), 1)[lvl - 1];
        ob->set("combat_exp", exp);
        sk_lvl = levels[exp];
        if (! ob->query_skills())
                return;
        ks = keys(ob->query_skills());
        for (i = 0; i < sizeof(ks); i++)
                ob->set_skill(ks[i], sk_lvl);

        return;
}

string *nations = ({ "�й�", "�ձ�", "���", "����", "����", "�ɹ�",
                     "����˹", "Ӣ����", "������", "������", "������",
                     "����ʱ", "������˹̹", "��ɳ��˹̹", "���ȱ��˹̹" });

// generate a npc with nation & skill level
object create_npc(string nation, int lvl)
{
        object ob;

        switch (nation)
        {
        case "�й�":
                ob = new(CLASS_D("generate") + "/chinese");
                NPC_D->generate_cn_name(ob);
                break;
        case "�ձ�":
                ob = new(CLASS_D("generate") + "/japanese");
                NPC_D->generate_jp_name(ob);
                break;
        case "Ӣ����":
                ob = new(CLASS_D("generate") + "/english");
                NPC_D->generate_e_name(ob);
                break;
        case "������":
        case "������":
        case "������":
        case "����ʱ":
        case "����":
                ob = new(CLASS_D("generate") + "/european");
                NPC_D->generate_e_name(ob);
                break;
        case "����":
                ob = new(CLASS_D("generate") + "/indian");
                NPC_D->generate_in_name(ob);
                break;
        case "������ģ":
        case "���":
        case "����˹":
        case "������˹̹":
        case "��ɳ��˹̹":
        case "���ȱ��˹̹":
        case "�ɹ�":
                return 0;
        }

        ob->set("nation", nation);
        init_npc_skill(ob, lvl);

        return ob;
}

// generate challenger
object create_challenger()
{
        string *n;
        object *ob;
        int max_level;
        int i;
        int lvl;

        ob = all_interactive();
        max_level = 0;
        for (i = 0; i < sizeof(ob); i++)
                if (! wizardp(ob[i]) && max_level < check_level(ob[i]))
                        max_level = check_level(ob[i]);

        max_level++;
        lvl = 1 + random(max_level);
        if (lvl < 3) lvl = max_level;

        n = ({ "�ձ�", "�ձ�", "�ձ�",
               "����",
               "Ӣ����", "������", "������", "������", "����ʱ", "����", });
        return create_npc(n[random(sizeof(n))], lvl);
}

// set the basic parameter from me
void set_from_me(object tob, object fob, int scale)
{
        mapping my, hp_status;

        hp_status = fob->query_entire_dbase();
        my = tob->query_entire_dbase();

        if (! scale)
        {
                if (undefinedp(my["scale"]))
                        my["scale"] = 100;
                scale = my["scale"];
        }

        my["str"] = hp_status["str"] * scale / 100;
        my["int"] = hp_status["int"] * scale / 100;
        my["con"] = hp_status["con"] * scale / 100;
        my["dex"] = hp_status["dex"] * scale / 100;

        my["max_qi"]     = hp_status["max_qi"]   * scale / 100;
        my["eff_qi"]     = my["max_qi"];
        my["qi"]         = my["max_qi"];
        my["max_jing"]   = hp_status["max_jing"] * scale / 100;
        my["eff_jing"]   = my["max_jing"];
        my["jing"]       = my["max_jing"];
        my["max_neili"]  = hp_status["max_neili"]* scale / 100;
        my["jiali"]      = tob->query_skill("force") / 3;
        if (my["max_neili"] > 9000)
                // max_neili not more then 9k
                my["max_neili"] = 9000;
        my["neili"]      = my["max_neili"] * 2;

        tob->set_from_me(fob, scale);
}

// select a random 

string random_place(string *not_place)
{
        string *kp;

        kp = keys(place);

        // exclude some place
        if (arrayp(not_place))
                kp -= not_place;

        // select a random place
        return kp[random(sizeof(kp))];
}

// place npc
void place_npc(object ob, string *not_place, string *in_place)
{
        string *kp;
        string p;
        string startroom;
        object pos;

        // select the place
        if (! arrayp(in_place))
                kp = keys(place);
        else
                kp = in_place;

        // exclude some place
        if (arrayp(not_place))
                kp -= not_place;

        // select the exact position
/*
        for (;;)
        {
                p = kp[random(sizeof(kp))];
                startroom = place[p][random(sizeof(place[p]))];
                pos = get_object(startroom);


                if (! objectp(pos = get_object(startroom)))
                {
                        log_file("log", sprintf("error to place npc to %s:%s\n",
                                                p, startroom));
                        continue;
                }
                break;

        }
*/

        p = kp[random(sizeof(kp))];
        startroom = place[p][random(sizeof(place[p]))];

        // move to the position
        //ob->move(pos);

        ob->move(startroom);
        ob->set("place", p);
        ob->set("startroom", startroom);
        ob->set_temp("moved", ({ }));
        message_vision("$N���˹�����\n", ob);

        return;
}

#define MAX_MOVED       5

// random move
void random_move(object ob)
{
        mapping exits;
        string *moved;
        string dir;
        string *dirs;
        int i;

        moved = ob->query_temp("moved");
        if (! moved) moved = ({ });
        if (sizeof(moved) >= MAX_MOVED)
        {
                // out of range, move back
                dir = GO_CMD->query_reverse(moved[sizeof(moved) - 1]);
        } else
        {
                exits = environment(ob)->query("exits");
                dirs = keys(exits);
                for (i = 0; i < 12; i++)
                {
                        if (! sizeof(dirs))
                                return;
                        dir = dirs[random(sizeof(dirs))];
                        if (stringp(GO_CMD->query_reverse(dir)) &&
                            ! exits[dir]->query("no_fight"))
                                break;
                        dirs -= ({ dir });
                }
        }

        if (sizeof(moved) &&
            GO_CMD->query_reverse(dir) == moved[sizeof(moved) - 1])
        {
                // move back
                moved = moved[0..<2];
        } else
                moved += ({ dir });
        ob->set_temp("moved", moved);

        GO_CMD->main(ob, dir);
}

// get all ultra master
object *query_ultra_master()
{
        return ({ get_object(HUANG_SHANG),
                  get_object(DUGU_QIUBAI),
                  get_object(KUIHUA_TAIJIAN),
                  get_object(HUO_SHAN) });
}


