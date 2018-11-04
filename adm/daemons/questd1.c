// questd.c ����������ػ�����
// ����ʦ�������������ϵͳע������(SYSREG_QUEST)
// Updated by Vin for heros.cn 

#include <ansi.h>
#include <quest.h>

#pragma optimize
#pragma save_binary

inherit F_DBASE;

// �����ṩ���ⲿ���õĽӿں���
public mixed  accept_ask(object me, object who, string topic);
public void   set_information(object qob, string key, mixed info);
public mixed  query_information(object qob, string key);
public void   remove_information(object qob, string key);
public void   remove_all_information(object qob);
public string generate_information(object knower, object who, string topic);
public void   start_all_quest();

void create()
{
        seteuid(getuid());
        set("channel_id", "������");
        set_heart_beat(900);
        call_out("collect_all_quest_information", 1);
}

#define ONE_DAY                 (86400 / 365)
#define MAX_QUEST_LEVEL         3

private void special_bonus(object me, object who, mixed arg)
{
        int gongxian;

        // �������
        string *ob1_list = ({
                "/clone/fam/pill/puti1",
                "/clone/fam/pill/sheli1",
                "/clone/fam/pill/linghui1",
                "/clone/fam/pill/full1",
                "/clone/fam/pill/neili1",
                "/clone/fam/etc/va1",
                "/clone/fam/etc/va2",
                "/clone/fam/etc/va3",
                "/clone/fam/etc/va4",
                "/clone/fam/etc/va5",
                "/clone/fam/etc/va6",
        });

        // �����ʮ������
        string *ob2_list = ({
                "/clone/fam/pill/puti2",
                "/clone/fam/pill/sheli2",
                "/clone/fam/pill/linghui2",
                "/clone/fam/pill/food1",
                "/clone/fam/pill/neili2",
        });

        // �����ʮ������
        string *ob3_list = ({
                "/clone/fam/pill/puti3",
                "/clone/fam/pill/sheli3",
                            "/clone/gift/cdiamond",
                            "/clone/gift/cagate",
                            "/clone/gift/ccrystal",
                            "/clone/gift/cjade",
        });

        // ���һ�ٸ�����
        string *ob4_list = ({
                "/clone/fam/pill/puti4",
                "/clone/fam/pill/sheli4",
                "/clone/fam/gift/str1",
                "/clone/fam/gift/int1",
                "/clone/fam/gift/con1",
                "/clone/fam/gift/dex1",
                "/clone/fam/item/handan",
                "/clone/fam/item/bixue",
                "/clone/fam/item/zijin",
                "/clone/fam/item/wujin",
                "/clone/fam/item/taijin",
                "/clone/fam/pill/renshen1",
                "/clone/fam/pill/lingzhi1",
                "/clone/fam/pill/xuelian1",
        });

        // ������ٸ�����
        string *ob5_list = ({
                "/clone/fam/etc/lv5a",
                "/clone/fam/etc/lv5b",
                "/clone/fam/etc/lv5c",
                "/clone/fam/etc/lv5d",
                "/clone/fam/etc/lv5e",
                "/clone/fam/pill/renshen2",
                "/clone/fam/pill/lingzhi2",
                "/clone/fam/pill/xuelian2",
        });

        // ������ٸ�����
        string *ob6_list = ({
                "/clone/fam/gift/str2",
                "/clone/fam/gift/int2",
                "/clone/fam/gift/con2",
                "/clone/fam/gift/dex2",
                "/clone/fam/pill/renshen3",
                "/clone/fam/pill/lingzhi3",
                "/clone/fam/pill/xuelian3",
                "/clone/fam/item/zhenlong",
                "/clone/fam/item/jiulei",
                "/clone/fam/item/panlong",
        });

        // ����İٸ�����
        string *ob7_list = ({
                "/clone/tattoo/buttock1",
                "/clone/tattoo/buttock2",
                "/clone/tattoo/buttock3",
                "/clone/tattoo/buttock4",
                "/clone/tattoo/buttock5",
                "/clone/tattoo/buttock6",
                "/clone/tattoo/buttock7",
                "/clone/tattoo/buttock8",
        });

        // �����ٸ�����
        string *ob8_list = ({
                "/clone/fam/gift/str2",
                "/clone/fam/gift/int2",
                "/clone/fam/gift/con2",
                "/clone/fam/gift/dex2",
                "/clone/fam/pill/renshen3",
                "/clone/fam/pill/lingzhi3",
                "/clone/fam/pill/xuelian3",
                "/clone/fam/etc/lv7a",
                "/clone/fam/etc/lv7b",
                "/clone/fam/etc/lv7c",
                "/clone/fam/etc/lv7d",
        });

        // ������ٸ�����
        string *ob9_list = ({
                "/clone/tattoo/body1",
                "/clone/tattoo/body2",
                "/clone/tattoo/body3",
                "/clone/tattoo/body4",
                "/clone/tattoo/body5",
                "/clone/tattoo/body6",
                "/clone/tattoo/body7",
                "/clone/tattoo/body8",
                "/clone/tattoo/body9",
                "/clone/tattoo/body10",
        });

        // ����߰ٸ�����
        string *ob10_list = ({
                "/clone/fam/pill/yulu",
                "/clone/fam/pill/dimai",
                "/clone/fam/pill/renshen4",
                "/clone/fam/pill/lingzhi4",
                "/clone/fam/pill/xuelian4",
                "/clone/fam/item/baxian",
                "/clone/fam/item/kunlun",
                "/clone/fam/item/haoyue",
                "/clone/fam/item/leihuo",
                "/clone/fam/item/yinzhu",
        });

        // ��ɰ˰ٸ�����
        string *ob11_list = ({
                "/clone/tattoo/spcs1",
                "/clone/tattoo/spcs2",
                "/clone/tattoo/spcs3",
                "/clone/tattoo/spcs4",
                "/clone/tattoo/spcs5",
                "/clone/tattoo/spcs6",
                "/clone/tattoo/spcs7",
                "/clone/tattoo/spcs8",
                "/clone/tattoo/spcs9",
                "/clone/tattoo/spcs10",
        });

        // ��ɾŰٸ�����
        string *ob12_list = ({
                "/clone/fam/skpaper/blade1",
                "/clone/fam/skpaper/claw1",
                "/clone/fam/skpaper/club1",
                "/clone/fam/skpaper/cuff1",
                "/clone/fam/skpaper/dagger1",
                "/clone/fam/skpaper/finger1",
                "/clone/fam/skpaper/hammer1",
                "/clone/fam/skpaper/hand1",
                "/clone/fam/skpaper/parry1",
                "/clone/fam/skpaper/staff1",
                "/clone/fam/skpaper/strike1",
                "/clone/fam/skpaper/sword1",
                "/clone/fam/skpaper/throwing1",
                "/clone/fam/skpaper/unarmed1",
                "/clone/fam/skpaper/whip1",
        });

        // ���һǧ������
        string *ob13_list = ({
                "/clone/fam/gift/str3",
                "/clone/fam/gift/int3",
                "/clone/fam/gift/con3",
                "/clone/fam/gift/dex3",
                "/clone/fam/item/yanluo",
                "/clone/fam/item/lihuo",
        });

        string un, gift;
        object ob;

        if (stringp(arg))
                gift = arg;
        else

        if (who->query("quest_count") == 1000)
        {
                gift = ob13_list[random(sizeof(ob13_list))];
                gongxian = 500;
        } else

        if (who->query("quest_count") == 900)
        {
                gift = ob12_list[random(sizeof(ob12_list))];
                gongxian = 300;
        } else

        if (who->query("quest_count") == 800)
        {
                gift = ob11_list[random(sizeof(ob11_list))];
                gongxian = 400;
        } else

        if (who->query("quest_count") == 700)
        {
                gift = ob10_list[random(sizeof(ob10_list))];
                gongxian = 400;
        } else

        if (who->query("quest_count") == 600)
        {
                gift = ob9_list[random(sizeof(ob9_list))];
                gongxian = 500;
        } else

        if (who->query("quest_count") == 500)
        {
                gift = ob8_list[random(sizeof(ob8_list))];
                gongxian = 300;
        } else

        if (who->query("quest_count") == 400)
        {
                gift = ob7_list[random(sizeof(ob7_list))];
                gongxian = 300;
        } else

        if (who->query("quest_count") == 300)
        {
                gift = ob6_list[random(sizeof(ob6_list))];
                gongxian = 200;
        } else

        if (who->query("quest_count") == 200)
        {
                gift = ob5_list[random(sizeof(ob5_list))];
                gongxian = 150;
        } else

        if (who->query("quest_count") == 100)
        {
                gift = ob4_list[random(sizeof(ob4_list))];
                gongxian = 80;
        } else

        if (who->query("quest_count") == 50)
        {
                gift = ob3_list[random(sizeof(ob3_list))];
                gongxian = 30;
        } else

        if (who->query("quest_count") == 30)
        {
                gift = ob2_list[random(sizeof(ob2_list))];
                gongxian = 10;
        } else
        {
                gift = ob1_list[random(sizeof(ob1_list))];
                gongxian = 1;
        }
        ob = new(gift);

        if (ob->query("base_unit"))
                un = ob->query("base_unit");
        else
                un = ob->query("unit");

        if (who->query("gongxian") >= gongxian)
        {
                message_vision(CYN "$n" CYN "��$N" CYN "΢Ц������������һ"
                               + un + ob->name() + CYN "��������õ��ž���"
                               "ȥ�ɡ�\n" NOR, who, me);

                tell_object(who, HIW "\n���" + ob->name() + HIW "��Ҫ����"
                                 "��" + chinese_number(gongxian) + "������"
                                 "���ף����Ƿ�Ը��(" HIY "answer Y|N" HIW
                                 ")���ܣ�\n\n" NOR);

                // ��¼������ȡ��������NPC
                who->set_temp("quest_gift/npc", me->query("id"));

                // ��¼��������Ʒ��·��
                who->set_temp("quest_gift/obj", gift);

                // ��¼��ȡ����Ʒ��������ƹ���
                who->set_temp("quest_gift/gongxian", gongxian);
        } else
                message_vision(CYN "$n" CYN "��$N" CYN "������������"
                               "���С��š��������ˣ�������Ҳ�ò�����"
                               "\n" NOR, who, me);
}

public mixed accept_ask(object me, object who, string topic)
{
        string my_fam;

        my_fam = me->query("family/family_name");

        if (topic == "����" || topic == "����" ||
            topic == "����")
        {
                if (my_fam != who->query("family/family_name"))
                        return "����˭��������ʲô����ô��";

                if (who->query("out_family"))
                        return "ȥ�ɣ�" + who->name(1) + "������Ϊ֮��";

                if (who->query("combat_exp") < 50000)
                {
                        message_vision(CYN "$N" CYN "̾��һ���������˿�$n"
                                       CYN "��������书��������̫�ã�����"
                                       "�ٺúö����ɡ�\n" NOR, me, who);
                        return 1;
                }

                if (who->query("score") < 100)
                {
                        message_vision(CYN "$N" CYN "�ڰ��ֵ�����Ľ�����"
                                       "��̫�٣����ڲ�������������߽�����"
                                       "\n" NOR, me, who);
                        return 1;
                }

                who->set("out_family", 1);
                if (me->is_good())
                {
                        message_sort(HIY "$N" HIY "��$n" HIY "��ο�ĵ���"
                                     "��ͷ��������������" + my_fam + "��"
                                     "����һλ�˲Ű������ס�ˣ��ұ�����"
                                     "���мɲ��ɺ���������Ҫ������������"
                                     "֮�£�\n" NOR, me, who);
                } else
                if (me->is_bad())
                {
                        message_sort(HIR "$N" HIR "��$n" HIR "������Ц��"
                                     "���ã��ã��ã�����Գ�ȥ���߿�����"
                                     "������Щ������ν����֮���ɲ�Ҫ����"
                                     "��ȥ�ɣ�\n" NOR, me, who);
                } else
                {
                        message_sort(HIY "$N" HIY "��$n" HIY "����������"
                                     "�������߽��������ǹ���һ�ˣ��ǵ�Ҫ"
                                     "����ǰ�������ɿ����Դ��м��ˣ�ȥ"
                                     "�ɣ�\n" NOR, me, who);
                }

                message_sort(HIC "$N" HIC "����һ��С���ӣ���$n" HIC "��"
                             "����������߽��������ɽ���������������"
                             "�����Լ�¼���Ȿ��ͼ���ϣ����ɲο��������"
                             "��Ҳ����Щ������\n" NOR, me, who);

                tell_object(who, HIC "\n������ʦ��������ĵ�ͼ�ᡣ\n" NOR +
                                 WHT "��μ�����(" HIW "help quest" NOR +
                                 WHT ")�Ի�ø���ϸ����Ϣ��\n" NOR);

                CHANNEL_D->do_channel(this_object(), "rumor", "��˵" +
                                      who->name(1) + "�Ѿ���ʼ����������");
                return 1;
        }
}

// ��ȡ����
// ���Ŀǰ����Э�����ˣ�������ȡ����
int ask_quest(object me, object who)
{
        string fam;             // ME��������Ϣ
        object ob;              // �����ص�ĳЩ���������
        mapping q;              // WHO������
        object aob;             // WHOĿǰ����Э���Ķ���
        int exp;                // WHO�ľ���
        int t;                  // ��������ʱ��ı���
        int level;              // QUEST�ĵȼ�
        string place;

        message_vision("$n��$N�����й�����������\n", me, who);

        fam = me->query("family/family_name");
        if (who->query("family/family_name") != fam)
        {
                message_vision(CYN "$N" CYN "�ɴ��۾�����$n" CYN "����"
                               "�����ֲ�������" + fam + "�ģ�����ʲô��"
                               "��\n" NOR, me, who);
                return 1;
        }

        if (who->query_temp("quest_gift"))
        {
                message_vision(CYN "$N" CYN "��$n" CYN "��ü����������"
                               "���أ��Ƕ����㵽��Ҫ(" HIY "answer Y|N"
                               NOR + CYN ")���ǲ�Ҫ��\n" NOR, me, who);
                return 1;
        }

        q = who->query("quest");
        if (mapp(q))
        {
        	if (q["freequest"] > 0)
                {
                        message_vision(CYN "$N" CYN "��$n" CYN "˵������������"
                                       "ʱҲûʲô���飬�㻹���Լ�����һ��ʱ��"
                                       "�ɡ�\n" NOR, me, who);
                        tell_object(who, HIY "��ͻȻ�뵽�����ڽ�����ֵ���ң���"
                                         "���Ĵ��߷ã�Ҳ�������Լ��ľ�������"
                                         "��\n" NOR);
                        return 1;
                }

                if (q["master_id"] && q["master_id"] != me->query("id"))
                {
                        message_vision(CYN "$N" CYN "���˿�$n" CYN "��"
                                       "����һ����û�����$n" CYN "��\n"
                                       NOR, me, who);
                        return 1;
                }

                switch (q["type"])
                {
                case "kill":
                        message_vision(CYN "$N" CYN "һ��ŭ�ݶ�$n" CYN "�����Ҳ�����"
                                       "��" + CHINESE_D->chinese_monthday(q["limit"]) +
                                       "֮ǰɱ��" NOR + HIR + q["name"] + NOR + CYN
                                       "����������" + CHINESE_D->chinese_monthday(time()) +
                                       "��������ͷ�أ�\n" NOR, me, who);
                        break;
                case "letter":
                        message_vision(CYN "$N" CYN "һ��ŭ�ݶ�$n" CYN "�����Ҳ�����"
                                       "��" + CHINESE_D->chinese_monthday(q["limit"]) +
                                       "֮ǰ�����͵�" NOR + HIC + q["name"] + NOR + CYN
                                       "�������������" + CHINESE_D->chinese_monthday(time()) +
                                       "�����Ļ�ִ�أ�\n" NOR, me, who);
                        break;
                }
                return 1;
        }

        if (me->query("eff_qi") * 2 < me->query("max_qi") ||
            me->query("qi") * 2 < me->query("max_qi"))
        {
                message_vision(HIC "$N" HIC "�����ؿڣ�һ���ǳ�ʹ������ӣ������"
                               "����Ȼû������ȥ��\n" NOR, me);
                return 1;
        }

        exp = who->query("combat_exp");
        if (exp < 10000)
        {
                message_vision(CYN "$N" CYN "̾��һ��������$n" CYN "���������ǵ�ˮƽ��"
                               "��ʵ��û������������\n" NOR, me, who);
                return 1;
        }

        if (objectp(aob = who->query_temp("quest/assist")))
        {
                message_vision(CYN "$N" CYN "���˿�$n" CYN "����������˵�㲻�ǰ�" NOR +
                               HIY + aob->name(1) + NOR + CYN "ȥ��ô���Ȱ�����"
                               "��˵�ɣ�\n" NOR, me, who);
                return 1;
        }

        if (exp < 50000)
        {
                object letter;

                if (who->query("score") < 20)
                {
                        message_vision(CYN "$N" CYN "ҡҡͷ����$n" CYN "������ϧ��"
                                       "�Ľ�������̫���Ȼ�һ�������������ͷ���"
                                       "��\n" NOR, me, who);
                        return 1;
                }

                ob = new(CLASS_D("generate") + "/receiver.c");
                NPC_D->place_npc(ob, ({ "����һ��", "����", "���޺�", "��ɽ", "����ɽ",
                                        "����", "�����Ǹ���", "�嶾�̸���" }));
                NPC_D->set_from_me(ob, me, 100);
                NPC_D->random_move(ob);
                NPC_D->random_move(ob);
                NPC_D->random_move(ob);
                place = ob->query("place");

                letter = new("/clone/misc/letter");
                letter->set("long", "����һ��" + me->name() + "д��" + ob->name() +
                                    "���ױ��ź���\n");
                letter->set("send_from", me->query("id"));
                letter->set("send_to", ob->query("id"));
                letter->set("send_from_name", me->name());
                letter->move(me);

                message_vision(CYN "$N" CYN "��$n" CYN "�������������ҽ���" NOR +
                               HIC + ob->name() + NOR + CYN "���У�������Ӧ����" +
                               place + "��Ȼ��ѻ�ִ���������ң�\n" NOR, me, who);

                me->force_me("give letter to " + who->query("id"));
                who->set("quest/info", letter->query("id"));
                who->set("quest/type", "letter");
        } else
        {

                if (! who->query("out_family"))
                {
                        message_vision(CYN "$N" CYN "�ڰ��֣���$n" CYN "����������"
                                       "���ﵹ����һЩ���飬�����������������ʱ��"
                                       "����˵�ɣ�\n" NOR, me, who);
                        return 1;
                }

                if (who->query("score") < 100)
                {
                        message_vision(CYN "$N" CYN "̾��һ��������$n" CYN "������"
                                       "�����ڽ����϶���������������Щ������˵�ɣ�"
                                       "\n" NOR, me, who);
                        tell_object(who, HIY "���������ȼ�ǿ�Լ��Ľ����������С�\n" NOR);
                        return 1;
                }

                if (who->query("weiwang") < 20)
                {
                        message_vision(CYN "$N" CYN "���˿�$n" CYN "��̾����������"
                                       "������һ����ͷ��û�У���û�����İ����񽻸�"
                                       "�㡣\n" NOR, me, who);
                        tell_object(who, HIY "�������ǵļ�ǿ�Լ��Ľ����������С�\n" NOR);
                        return 1;
                }
        
                if (who->is_bad() && me->is_good())
                {
                        message_vision(CYN "$N" CYN "��ŭ�������д������Ȼ�Ѿ���"
                                       "����;�����������ң�\n" NOR, me, who);
                        return 1;
                }
        
                if (who->is_good() && me->is_bad())
                {
                        message_vision(CYN "$N" CYN "��ŭ�������д����ż��첻����"
                                       "���ȻҲѧ����ʼ������ˣ�����ҹ���\n"
                                       NOR, me, who);
                        return 1;
                }

                level = who->query_temp("quest/next_level");
                if (level < 0 || level > MAX_QUEST_LEVEL)
                        level = 0;

                ob = new(CLASS_D("generate") + "/killed.c");
                NPC_D->place_npc(ob, who->query("combat_exp") < 500000  ? ({ "����һ��", "����ɽ", "����", "����" }) :
                                     who->query("combat_exp") < 800000 ? ({ "����һ��", "����ɽ", "����" }) : 0);
                NPC_D->set_from_me(ob, who, 100);
                ob->add_temp("apply/attack", ob->query_skill("force") *
					     (level - 1) / 15);
                ob->add_temp("apply/dodge", ob->query_skill("force") *
					    (level - 1) / 15);
                ob->add_temp("apply/parry", ob->query_skill("force") *
					    (level - 1) / 15);
                ob->add_temp("apply/damage", 5 + level * 7);
                ob->add_temp("apply/unarmed_damage", 5 + level * 7);
                ob->add_temp("apply/armor", 10 + level * 15);
                ob->set_temp("quester", who->query("id"));
                NPC_D->random_move(ob);
                NPC_D->random_move(ob);
                NPC_D->random_move(ob);
                place = ob->query("place");

                message("vision", WHT + me->name() + WHT "С���Ķ�" + who->name() +
                                  WHT "�Ը���ʲô��" + who->name() +
                                  WHT "һ������һ�߲�ס�ĵ�ͷ��\n" NOR,
                                  environment(who), ({ who }));
                if (me->is_good())
                {
                        ob->set("shen", -ob->query("combat_exp") / 2000);
			if (me->query("family/family_name") == "������")
				tell_object(who, CYN + me->name() + CYN "���������"
                                                 "Ȼ���ǳ������Դȱ�Ϊ�������Ƕ��ڴ�"
                                                 "�״��֮ͽҲ���ܷŹ���\n���" NOR +
                                                 HIR + ob->name() + NOR + CYN "��" +
                                                 place + "�����ˣ���ȥ�������ˣ���"
                                                 "ͷ������\n" NOR);
			else
                        	tell_object(who, CYN + me->name() + CYN"�������" NOR
                                                 + HIR + ob->name() + NOR + CYN "���"
                                                 "�����ҽ��ᣬ�޶�������˵�����"
                                                 "��" + place +	"����ȥ����������ͷ��"
                                                 "���ң�\n" NOR);
                } else
                if (me->is_bad())
                {
                        ob->set("shen", ob->query("combat_exp") / 2000);
                        tell_object(who, CYN + me->name() + CYN "�������" NOR + HIR
                                         + ob->name() + NOR + CYN "�����ν�����Ŵ�"
                                         "���������ԣ���˵�������" + place + "����"
                                         "ȥ����������ͷ������\n" NOR);
                } else
                {
                        ob->set("shen_type", 0);
                        ob->set("shen", 0);
                        tell_object(who, CYN + me->name() + CYN "����˵��������Ϳ�"
                                         NOR + HIR + ob->name() + NOR + CYN "��˳��"
                                         "����˵�������" + place + "����ȥ��������"
                                         "��������ͷ�����\n" NOR);
                }
                who->set("quest/type", "kill");
                switch (level)
                {
                case 0:
                        message_vision(CYN "$N" CYN "���˶٣��ֶ�$n" CYN "�������"
                                       "�������װ�úܣ���Ҫ�ǻ��첻���ǿɲ��󻰡�"
                                       "\n" NOR, me, who);
                        break;
                case 1:
                        break;
                case 2:
                        message_vision(CYN "$N" CYN "���˿�$n" CYN "�ֵ����������"
                                       "������Щ�Ѱ죬��Ҫ�ǲ����Ҿ������˰ɡ�\n"
                                       NOR, me, who);
                        break;
                case 3:
                        message_vision(CYN "$N" CYN "̾�˿�����֣�صĶ�$n" CYN "��"
                                       "������������յý����㲻Ҫ��ǿ�Լ������о�"
                                       "���ˡ�\n" NOR, me, who);
                        break;
                }

                if (level > 0 && random(10) == 1)
                {
                        string flee_msg;

                        // ������·���NPC��λ��
                        message_sort(HIC "\n$N" HIC "�������䣬ͻȻһ�˴�æ���˹�"
                                     "���������������ˣ������ˡ���˵�Ǹ���" HIW +
                                     ob->name() + HIC "�ļһ���" + place + HIC "ʧ"
                                     "���ˣ�����Ҳ��֪��ȥ�����\n\n" NOR, me, who);

                        message_vision(CYN "$N" CYN "���˰��Σ���Ŷ�$n" CYN "̾��"
                                       "�������鷳�ˣ�����ֻ�п����Լ�Ŭ���ˡ�\n"
                                       NOR, me, who);

                        switch (random(3))
                        {
                        case 0:
                                flee_msg = "��˵$N�����˽�����׷ɱ���ķ������Ѿ���"
                                           "��PLACEȥ�ˡ�";
                                break;
                        case 1:
                                flee_msg = "����˵$N����������ؽ��أ�����Ҳ����˵"
                                           "����PLACE����֪�������Ǽ١�";
                                break;
                        default:
                                flee_msg = "��֪������Ŷ����������˵������PLACE��";
                                break;
                        }
                        ob->random_place(flee_msg);
                }
        }

        who->set("quest/family", fam);
        who->set("quest/master_name", me->name());
        who->set("quest/master_id", me->query("id"));
        who->set("quest/name", ob->name());
        who->set("quest/id", ob->query("id"));
        who->set("quest/level", level);
        who->set("quest/place", place);
        t = time();
        who->set("quest/time", t);
        t = time() / ONE_DAY;
        if (ob->query("place") == "����")
                t += 8;
        else
                t += 4;
        t = t * ONE_DAY - 1;
        who->set("quest/limit", t);
        message("vision", WHT + me->name() + WHT "�����������˵���������Ҫ��"
                          NOR + HIY + CHINESE_D->chinese_monthday(t) + NOR + WHT
                          "֮ǰ��ɣ�\n" NOR, who);
        who->start_busy(1);
        return 1;
}

int accept_object(object me, object who, object ob)
{
        mapping q;              // WHO������
        string msg;             // ����˵����Ϣ
        object dob;             // ���ε��˵���
        int bonus;              // ����(��������1������)
        int t;                  // ��������ʱ��ı���
        int exp;                // ��õľ���
        int pot;                // ��õ�Ǳ��
        int mar;                // ��õ�ʵս���
        int weiwang;            // ��õ�����
        int score;              // ��õĽ�������
        int gongxian;           // ��õ����ɹ���
        int lvl;                // ����ĵȼ�
        int quest_level;        // QUEST�ĵȼ�
        int quest_count;        // ����QUEST����Ŀ
        int timeover;           // ��־����ʱ�ˣ�
        int added;              // �������ʱ�������ֵĵ��˻��������
        mixed special = 0;      // �Ƿ������⽱��

        if (me->query("family/family_name") != who->query("family/family_name"))
                return 0;

        q = who->query("quest");
        if (ob->is_letter())
        {
                if (ob->query("send_from") != me->query("id"))
                {
                        message_vision(CYN "$N" CYN "������Ҫ��ʲô��\n" NOR, me);
                        return -1;
                }

                if (! q || q["type"] != "letter" || ob->query("send_to") != q["id"])
                {
                        message_vision(CYN "$N" CYN "�����̾��һ������û˵ʲô��\n" NOR, me);
                        destruct(ob);
                        return 1;
                }

                message_vision(CYN "$N" CYN "����$n" CYN "������ʲô��������"
                               "�Ļ��㲻������ˣ�\n" NOR, me, who);        
                return -1;
        }

        if (ob->is_receipt())
        {
                if (ob->query("reply_to") != me->query("id"))
                {
                        me->force_me("say ���������ո�ʲô��");
                        return 0;
                }

                if (! q || q["type"] != "letter" || q["id"] != ob->query("reply_by"))
                {
                        me->force_me("nod");
                        me->force_me("say ��л�ˡ�");
                        destruct(ob);
                        return 1;
                }

                msg = CYN "$N" CYN "�ӹ�" + ob->name() + NOR + CYN"����ϸ����"
                      "���������˵���ܺá�\n" NOR;
                t = time();
                if (t > q["limit"])
                {
                        msg += CYN "$N" CYN "̾�˿������ֵ�����ϧ����������" +
                               CHINESE_D->chinese_monthday(t) + "ǰ��������"
                               "�ˣ������������������°ɡ�\n" NOR;
                        timeover = 1;
                } else
                {
                        if (t - q["time"] < ONE_DAY)
                        {
                                msg += CYN "$N" CYN "���ͷ������ܲ�����ô"
                                       "�������ˣ��úøɣ�\n" NOR;
                        } else
                                msg += CYN "$N" CYN "���ͷ������β�������"
                                       "�ˡ�\n" NOR;

                        timeover = 0;
                }
                bonus = (ob->query("receive_from") == who->query("id"));
                exp = 15 + random(10);
                pot = 5 + random(8);
                mar = 1;
                score = 6 + random(5);
                weiwang = 1;
                gongxian = 1;
                destruct(ob);
        } else
        {
                if (! mapp(q) || ! ob->is_corpse() && ! ob->is_head())
                        return 0;
        
                if (! stringp(ob->query("owner_id")))
                {
                        message_vision(CYN "$N" CYN "���ű��ӿ��˿�" + ob->name()
                                       + NOR + CYN "������ʲô�����ģ������"
                                       "���ߡ�\n" NOR, me);
                        return 0;
                }
        
                if (ob->query("owner_id") != q["id"])
                        return 0;

                msg = CYN "$N" CYN "�ӹ�" + ob->name() + NOR + CYN "���ǺǴ�Ц"
                      "����$n" CYN "����";

                if (me->is_good())
                        msg += CYN "�ֳ���һ�����ܺã�";
                else
                if (me->is_bad())
                        msg += CYN "�ü��ˣ�ʲô����������һ����";
                else
                        msg += CYN "�ɵúã�Ư����";

                msg += "\n" NOR;
                t = time();
                if (who->query_temp("quest/escape_times"))
                {
                        msg += CYN "$N" CYN "����������û�뵽������ôǿ����ʵ"
                               "��δ���ϵ������࣬���࣡\n" NOR;
                        timeover = 0;
                } else
                if (t > q["limit"])
                {
                        msg += CYN "$N" CYN "ҡҡͷ���ֵ�����ϧ����������" +
                               CHINESE_D->chinese_monthday(t) + "ǰ��������"
                               "�ˣ������������������°ɡ�\n" NOR;
                        timeover = 1;
                } else
                {
                        if (t - q["time"] < ONE_DAY)
                        {
                                msg += CYN "$N" CYN "���ͷ�����ɵò�����ô"
                                       "�������ˣ��úøɣ�\n" NOR ;
                        } else
                                msg += CYN "$N" CYN "���ͷ������β�������"
                                       "�ˡ�\n" NOR;

                        timeover = 0;
                }

                // bonusΪ1��ʾ����������Ϊ2��ʾ�۳�һ�롣
                bonus = (ob->query("killed_by") == who->query("id")) &&
                        (ob->query("defeated_by") == who ||
                         ! ob->query("defeated_by") &&
                           ob->query("defeated_by_who") == who->name(1));
                if (ob->query("assist") == who)
                {
                        dob = ob->query("defeated_by");
                        msg += CYN "$N" CYN "��ο�Ķ�$n" CYN "����������ܹ�"
                               "�õ�" + (dob ? dob->name(1) : "ͬ��ʦ�ֵ�") +
                               NOR + CYN "�İ�æ��Ҳ�����ף��Ժ�˴�Ҫ�����"
                               "Ӧ��\n" NOR;
                        bonus = 2;
                } else
                if (bonus)
                        bonus = 1;

                destruct(ob);
                lvl = NPC_D->check_level(who);
                exp = 10 + random(5) + lvl;
                pot = 5 + random(3) + lvl;
                mar = 1 + random(2);
                weiwang = 2 + random(3) + lvl / 2;
                score = 2 + random(3) + lvl / 2;
                gongxian = 1;
                quest_count = who->query("quest_count") + 1;

                // add temped for keep compactible with old version
                if (who->query_temp("quest/total_count"))
                {
                        quest_count = who->query_temp("quest/total_count") + 1;
                        who->delete_temp("quest/total_count");
                }

                // ����������ɵĴ�����������
                if (quest_count >= 500)
                {
                        // ��������˳���500�ε�����
                        exp += 80 + random(quest_count / 20 + 1);
                        pot += 45 + random(quest_count / 25 + 1);
                        mar = 50 + random(20);
                        weiwang += 8 + random(20);
                        score += 4 + random(15);
                        gongxian += random(2);
                } else
                if (quest_count >= 200)
                {
                        // ��������˳���200�ε�����
                        exp += 70 + random(quest_count / 20 + 1);
                        pot += 40 + random(quest_count / 25 + 1);
                        mar = 20 + random(10);
                        weiwang += 5 + random(15);
                        score += 3 + random(10);
                } else
                if (quest_count >= 100)
                {
                        // ��������˳���100�ε�����
                        exp += 50 + random(quest_count / 20 + 1);
                        pot += 30 + random(quest_count / 25 + 1);
                        weiwang += 3 + random(10);
                        score += 2 + random(10);
                } else
                if (quest_count >= 10)
                {
                        // ��������˳���10�ε�����
                        exp += 45 + random(quest_count / 20 + 1);
                        pot += 25 + random(quest_count / 25 + 1);
                        weiwang += 1 + random(5);
                        score += 1 + random(5);
                }

                switch (quest_level = q["level"])
                {
                case 0:
                        exp = exp / 2 + 1;
                        pot = pot / 2 + 1;
                        gongxian = gongxian / 2 + 1;
                        weiwang = weiwang / 3 + 1;
                        score = score / 4 + 1;
                        msg += CYN "$N" CYN "����$n" CYN "����˵�������аɣ���"
                               "���Ҹ�����ѵ������\n" NOR;
                        break;
                case 1:
                        msg += CYN "$N" CYN "��$n" CYN "�ֵ������������ҿ���"
                               "�и�Щ���θ����ˡ�\n" NOR;
                        break;
                case 2:
                        exp += exp / 4;
                        pot += pot / 4;
                        weiwang += weiwang / 4;
                        score += score / 4;
                        msg += CYN "$N" CYN "��$n" CYN "Ц�������ǲ���������"
                               "����" + who->query("family/family_name") + "��"
                               "�ý��ߡ�\n" NOR;
                        break;
                case 3:
                        exp += exp / 2;
                        pot += pot / 2;
                        weiwang += weiwang / 2;
                        score += score / 2;
                        msg += CYN "$N" CYN "��������ǳ�������οɸ�����" +
                               who->query("family/family_name") + "�����ˡ�\n"
                               NOR;
                        break;
                }

                if (quest_count == 30)
                {
                        msg += CYN "$N" CYN "������Ц��������������ģ�������"
                               "ʮ��������ɵ�ƯƯ�������ܺã��ܺá�\n" NOR;
                        special = 1;
                } else
                if (quest_count == 50)
                {
                        msg += CYN "$N" CYN "������Ц��������������ģ�������"
                               "ʮ��������ɵ�ƯƯ�������ܺã��ܺá�\n" NOR;
                        special = 1;
                } else
                if (quest_count == 100)
                {
                        msg += CYN "$N" CYN "������Ц��������������ģ�������"
                               "�ٴ�������ɵ�ƯƯ�������ܺã��ܺá�\n" NOR;
                        special = 1;
                } else
                if (quest_count == 200)
                {
                        msg += CYN "$N" CYN "��ϲ�������������ǲ�������"
                               "������ɵúܺá�\n" NOR;
                        special = 1;
                } else
                if (quest_count == 300)
                {
                        msg += CYN "$N" CYN "��ϲ�����������������ٸ�����"
                               "��˿�������������Ư����\n" NOR;
                        special = 1;
                } else
                if (quest_count == 400)
                {
                        msg += CYN "$N" CYN "��ϲ�������ǲ�����Ȼ�����İٸ�"
                               "����˿����������ɵúá�\n" NOR;
                        special = 1;
                } else
                if (quest_count == 500)
                {
                        msg += CYN "$N" CYN "̾�������ǳ���������ǰ�ˣ��벻��"
                               "�������ٴ�������һ��©�����ǲ���\n" NOR;
                        special = 1;
                } else
                if (quest_count == 600)
                {
                        msg += CYN "$N" CYN "̾�������ǳ���������ǰ�ˣ��벻��"
                               "��������ٴ�������һ��©��Ư��֮����\n" NOR;
                        special = 1;
                } else
                if (quest_count == 700)
                {
                        msg += CYN "$N" CYN "̾�������ǳ���������ǰ�ˣ��벻��"
                               "���߰ٴ�������һ��©�����ף����ף�\n" NOR;
                        special = 1;
                } else
                if (quest_count == 800)
                {
                        msg += CYN "$N" CYN "̾�������ǳ���������ǰ�ˣ��벻��"
                               "������˰ٴ�������һ��©������֮����\n" NOR;
                        special = 1;
                } else
                if (quest_count == 900)
                {
                        msg += CYN "$N" CYN "�����̾�����벻��������Űٴ���"
                               "����һ��©������֮��������֮����\n" NOR;
                        special = 1;
                } else
                if (quest_count == 1000)
                {
                        msg += CYN "$N" CYN "����̾�˿����������벻��������һ"
                               "ǧ��������һʧ�֣���������" +
                               me->query("family/family_name") +
                               "���Ǻ�����˰���\n" NOR;
                        special = 1;
                } else
                if (quest_count > 1000)
                {
                        quest_count = 0;
                } else
                if ((quest_count % 10) == 0)
                {
                        msg += CYN "$N" CYN "ϲ�������ǲ�������Ȼ����" +
                               chinese_number(quest_count) +
                               "�ζ�û��ʧ�֣��ɵĺã�\n" NOR;
                }

                quest_level = q["level"];
                quest_level++;
                if (quest_level > MAX_QUEST_LEVEL)
                        quest_level = 1;

                who->set("quest_count", quest_count);
                who->set_temp("quest/next_level", quest_level);
        }

        if ((added = (int)who->query_temp("quest/help_count")) > 0)
        {
                msg += HIY "$N" HIY "�ֵ�����ε��˷��°��֣����������Ӧ�䣬"
                       "������񣬿�ϲ���ɺأ�\n" NOR;
                who->delete_temp("quest/help_count");
        }
        added += (int)who->query_temp("quest/escape_times") * 2;
        who->delete_temp("quest/escape_times");
        // ����NPC�İ��ֺ����ߵĴ�����������
        if (added)
        {
                exp += exp * added / 2;
                pot += pot * added / 2;
        }

        message_vision(msg, me, who);
        who->delete("quest");
        if (! bonus) return 1;

        exp /= bonus;
        pot /= bonus;
        mar /= bonus;
        weiwang /= bonus;
        score /= bonus;
        gongxian /= bonus;

        // bouns
        if (timeover)
        {
                exp /= 2;
                pot /= 3;
                mar /= 2;
                weiwang /= 4;
                score /= 4;
                gongxian /= 2;
        } else
        {
                // �ٷ�֮һ�ļ���ֱ��������Ʒ����
                if ((quest_count >= 100 && random(200) == 1) || special)
			special_bonus(me, who, special);
        }

        if (who->query("potential") >= who->query_potential_limit())
                pot = 1;

        if (who->query("experience") >= who->query_experience_limit())
                mar = 1;

        // ���������������ɹ���ֵ
        if (who->query("special_skill/cunning") && random(2) < 1)
                gongxian = gongxian + random(2);

        message("vision", sprintf(HIC "ͨ����ζ���������%s�㾭�飬"
                                  "%s��Ǳ�ܼ�%s��ʵս��ᡣ\nͬʱ����"
                                  "����%s�㽭��������%s��������%s����"
                                  "�ɹ��׶ȡ�\n" NOR,
                                  chinese_number(exp),
                                  chinese_number(pot),
                                  chinese_number(mar),
                                  chinese_number(score),
                                  chinese_number(weiwang),
                                  chinese_number(gongxian)), who);
        who->add("combat_exp", exp);
        who->add("potential", pot);
        who->add("experience", mar);
        who->add("weiwang", weiwang);
        who->add("score", score);
        who->add("gongxian", gongxian);

        // ���ֹͣ�������񣬱�������һ��������freequest���ܼ�����
        if (random(40) == 1 && quest_count >= 30 && ! who->query_temp("wiz_test"))
                who->add("quest/freequest", 1 + random(3));

        return 1;
}

int cancel_quest(object me, object who)
{
        mapping dbase;
        mapping q;
        object ob;
        string msg;
        int n;
        int g;

        dbase = who->query_entire_dbase();
              
        if (! mapp(q = dbase["quest"]) ||
            q["master_id"] != me->query("id"))
                return notify_fail("��û����ʲô���񰡣�\n");

        switch (q["type"])
        {
        case "kill":
                if (q["notice"] == "die")
                {
                        message_vision(CYN "$N" CYN "���ͷ����$n" CYN "�������ˣ���˵����"
                                       "�Ѿ���ɱ�ˣ��㲻���������ˡ�\n" NOR, me, who);
                } else
                {
                        message_vision(CYN "$N" CYN "�ڰ��֣���$n" CYN "������ɲ��˾�����"
                                       "���ñ������ɣ�\n" NOR, me, who);
                        who->delete("quest_count");
                }

	            who->delete_temp("quest/next_level");
                n = (40 + random(40) + NPC_D->check_level(who) * 5);
                g = (10 + random(10) + NPC_D->check_level(who));

                switch (q["level"])
                {
                case 0:
                        n *= 2;
                        break;
                case 1:
                        break;
                case 2:
                        n = 0;
                        break;
                case 3:
                        n = 0;
                        break;
                }
                if (! n) break;

                // adjust weiwang
                dbase["weiwang"] -= n;
                if (dbase["weiwang"] < 0)
                        dbase["weiwang"] = 0;
                msg = HIR "��Ľ��������ܵ�����ʧ";

                // adjust gongxian
                dbase["gongxian"] -= g;
                if (dbase["gongxian"] < 0)
                        dbase["gongxian"] = 0;
                msg += HIR "��ʦ�Ŷ�������ν�����";

                // adjust experience
                if (dbase["experience"] > dbase["learned_experience"])
                {
                        dbase["experience"] += (dbase["learned_experience"] - dbase["experience"]) * 2 / 3;
                        msg += "������ƣ�ڱ��������ʵս������Լ�ʱ��������";
                }

                // notice place
                message("vision", msg + "��\n" NOR, who);
                break;

        case "letter":
                message_vision(CYN "$N" CYN "̾���������˿�$n" CYN "���������С�¶��ɲ��ˣ����˰ɡ�\n" NOR,
                               me, who);

                who->add("score", -(15 + random(10)));
                if (who->query("score") < 0)
                        who->set("score", 0);
                message("vision", HIR "��Ľ��������ܵ�����ʧ��\n" NOR, who);
                break;
        }
        who->start_busy(2);

        ob = find_living(q["id"]);
        map_delete(dbase, "quest");
        if (! ob || ob->query_temp("quester") != who->query("id"))
                return 1;

        if (environment(ob))
                message_vision(HIC "$N" HIC "���˿����ܣ�����ææ���ߵ��ˡ�\n" NOR, ob);

        destruct(ob);
        return 1;
}

/***********************************************************
  ϵͳע���������

    HELL������������������ڶ��ʽ���������񣬶������ػ�����
�������ǵĹ����ߡ�Ϊʲô��Ҫ�������������Ϊ�󲿷����񶼾�
�����ƵĴ�����̣��ռ��鱨�������������ĳЩҪ��ʵ��������
�񣬻�ý�����Ϊ���ܹ����ٵı�д��ʵ�ֶ������񣬹����ظ���ʵ
�ִ��룬ϵͳ�涨���������ĸ�ʽ��ֻҪ��ѭ�������ĸ�ʽ����
���Կ��ٵ������������

    ���������ȿ�һ������Ľṹ��һ������ʵ���Ͼ���һ���Զ�����
Ȼ������Ҳ��ϵĴ�������Զ������ﵽһ���ȶ�״̬��һ����˵
��������ɹ�������ֹ��ϵͳ����Ϊ��������ƶ�һЩ��׼�¼���Ȼ
���������������Լ��ƶ�һЩ�¼��������ϳ���һ�����������
�¼���Ȼ��ϵͳΪ����ά��һ��״̬�������͹�����һ���������Զ�
����

    ��һ���򵥵ġ�ɱ�ˡ�����

    ɱһ������Ҫ��Ҫ����Ҫ�أ�ʱ�䡢�ص㡢�����ĳһ��ʱ�䣬
ĳ���ص����һ�����ɱ����������ɣ����Ի�ý�������ô����
��Ƶ�����Ԥ���������ģ�һ���˴�������������񣬾�ȥ��Ӧ�ĵ�
�㣬ɱ�ˣ�ɱ���Ժ��ý�����

    ���������Զ�������

                                      ��Ϣ�ռ���ȫ
            <ԭ��̬> -> ��������̬ -----------+ 
                           /                  |
                 <Timeout>/    <Timeout>      |
                   -------<---------------\   |
                 /                         \  v
            <����̬>   <--------------- �������̬
                            ɱ������             

<ԭ��̬>��<����̬>��ϵͳ�涨��״̬��<Timeout> ��ϵͳԭ�ȱ���
���¼�������������̬���������̬�Ǹ��������е�״̬��������Ϣ
�ռ���ȫ��ɱ���������Ǹ�����������е��¼���

<ԭ��̬>�׶�ϵͳ��ʼ������������һЩ��Ҫ�Ĳ�������������
Ȩ���ݸ���������Խ��к����Ĳ�������ʱ��������Զ�����һ����
��ƶ����ĵȼ�����а��Ԥ�ڳ��ֵĵص㣬�������Ѷȵȵȡ�Ȼ��
�ͽ��뵽��������̬��ͬʱ�����Լ���Ҫ���ܳ�ʱ�¼���

��ʱ��������������Ϣ���п��ܴ�����������񣬲���������������
����˸��˳��ֵĵص���Ϣ��������������Ϊ��Ϣ�ռ���ȫ������
���������������Ⱥ���ҽ�������

��������ﱻ������֪ͨ��������������ת�Ƶ�<����̬>����
��һ���������̬�Ŀ����ǳ�ʱ�ˡ�

����<����̬>��ϵͳ�Զ�������������

������������������Ϸ�еĻ��ز��������²�������ϵͳ�������
�ȵȡ�ֻҪ����һ�����󣬾Ϳ��Բ�������

������Ϣ������ͨ������Ϣ����һ����Ϣ��ͨ�����Կ��Ƶ����������
������С��������Ĵ�����Ϣ�������Щ��Ϣ���Է�ӳ����ǰ����
��һЩ��Ϣ����Щ�����Ѿ���ϵͳ��װ����������Ժ�ϵͳ���ý�
�ں�����register_information()���ǼǺ�������ص���Ϣ -- Ϊʲ
ô�������������ͬʱ�������Լ��Ǽǣ�������Ϊ�����ػ������п�
�����������´�������������ʧ���еǼǵ����ݣ���ʱ�����ػ�����
�ͻ����ϵͳ�����е����񣬵���register_information()�ӿ�����
����֯��Щ��Ϣ��

��Ϣ���ݽṹ��

---+-- scheme(1) -*
   |
   +-- scheme(2) -*
   |
   +-- scheme(3) --+-- �ؼ��֣���Ϣ1
                   |
                   +-- �ؼ��֣���Ϣ2
                   |
                   .........

������Ҫһ���Ľ�����������random(��������) > ��Ϣ��ʱ�� ��
�п��ܴ����������Ϣ����Ϣ������һ������������������Ļ�����
������Ϣ��ʱ��ϵͳ�Ѵ����Ķ���ʹ�����Ϣ���ˣ��ؼ��ִ��ݸ���
������ȡ���ķ��ؽ����

QUEST_D�ṩ����ϢAPI��

QUEST_D->add_quest(QUEST_OBJECT);
QUEST_D->set_information(QUEST_OBJECT, key, information);
QUEST_D->query_information(QUEST_OBJECT, key);
QUEST_D->remove_information(QUEST_OBJECT, key);
QUEST_D->remove_all_information(QUEST_OBJECT);

QUEST_OB�����ṩ����Ϣ�ӿڣ�

QUEST_OB->register_information();
QUEST_OB->name();
QUEST_OB->can_know_by(object knower);
QUEST_OB->can_rumor_by(object knower);
QUEST_OB->query_introduce(object knower, object who);

***********************************************************/

// ϵͳ����һ������
public void add_quest(object qob)
{
        mapping total;

        if (! mapp(total = query("information")))
        {
                // ԭ��û���κ�����
                total = ([ qob : 1 ]);
                set("information", total);
        } else
        {
                // �鿴��������Ƿ��Ѿ��ж���
                if (undefinedp(total[qob]))
                        // ����һ��������Ϊ��ʱ��ոս���
                        // ����룬��û���κ���صľ�����Ϣ��
                        // ���������Ŀ��Ӧ�ľ�ֻ��һ����
                        // ������ʶ��
                        total[qob] = 1;
        }
}

// ������Ϣ
public void set_information(object qob, string key, mixed info)
{
        mapping total;
        mapping all_info;

        if (! stringp(key) || (! stringp(info) && ! functionp(info)))
        {
                log_file("static/quest",
                         sprintf("%s Quest:%O(%s) set illegal info:%s:%O.\n",
                                 log_time(), qob, qob->name(), key, info));
                return;
        }

        if (! mapp(total = query("information")))
                total = ([ ]);

        if (! mapp(all_info = total[qob]))
        {
                // ԭ��û�и�����������Ϣ��Ϣ
                all_info = ([ ]);
                total += ([ qob : all_info ]);
        }

        all_info[key] = info;
        set("information", total);
}

// ��ѯ��Ϣ
public mixed query_information(object qob, string key)
{
        mapping total;
        mapping all_info;

        if (! mapp(total = query("information")))
                return 0;

        if (! mapp(all_info = total[qob]))
                return 0;

        return all_info[key];
}

// ɾ����Ϣ
public void remove_information(object qob, string key)
{
        mapping total;
        mapping all_info;

        if (! mapp(total = query("information")))
                return;

        if (! mapp(all_info = total[qob]))
                return;

        map_delete(all_info, key);
        if (! sizeof(all_info))
        {
                // ����������Ѿ�û����Ϣ��
                map_delete(total, qob);
                return;
        }
}

// ɾ��ĳһ�������������Ϣ
public void remove_all_information(object qob)
{
        mapping total;

        if (! mapp(total = query("information")))
                return;

        // ��ɾ��������Ϣ��ͬʱ��������Ҳȥ���� -- Ϊʲô
        // ��������������Ϊ�����һ��û���κ���Ϣ�����񣨽�
        // ����������ṩ��Ϣ��������������ĺ�����������
        // ������һ���ṩ��Ϣ���������������ϢҲ������
        // ͬ�ĺ��塣
        map_delete(total, qob);
}

// QUESTϵͳ����������ʱ���ռ���������������Ϣ
private void collect_all_quest_information()
{
        mapping total;
        object qob;
        object *obs;

        CHANNEL_D->do_channel(this_object(), "sys",
                              "�����鿪ʼ�ռ����е�������Ϣ��");

        if (! mapp(total = query("information")))
        {
                total = ([ ]);
                set("information", total);
        }

        obs = filter_array(objects(), (: $1->is_quest() :));

        // ɨ�����е�QUEST���󣬵Ǽ���Ϣ
        foreach (qob in obs)
        {
                reset_eval_cost();
                total[qob] = 0;
                catch(qob->register_information());
        }

        // ���Ѽ����������ػ�����
        start_all_quest();
}

public void start_all_quest()
{
        string quest;
        string *qlist;
        string name;
        int pos;
/*
        if (! VERSION_D->is_version_ok())
                // ����ͬ���汾����ô�����������ػ�����
                return;
*/
        quest = read_file(CONFIG_DIR "quest");
        if (! stringp(quest))
                // �����ļ���û������
                return;

        qlist = explode(quest, "\n");
        foreach (name in qlist)
        {
                // ��ֹ���г�ʱ
                reset_eval_cost();

                if (strlen(name) < 1 || name[0] == '#')
                        // ���л�����ע����
                        continue;

                // ȥ����β��ע�ͺͿո�
                pos = strsrch(name, '#');
                if (pos > 1) name = name[0..pos - 1];
                name = replace_string(name, " ", "");

                // �����ļ�����
                name = QUEST_DIR + name + ".c";
                if (file_size(name) < 0)
                {
                        // û���������
                        log_file("static/quest",
                                 sprintf("%s invalid quest: %s\n",
                                         log_time(), name));
                        continue;
                }

                // �����������
                catch(call_other(name, "startup"));
        }
}

// �������е�����
private void heart_beat()
{
        mapping total;
        mixed key;
        int live_time;
        int t;

        // �����������е�������̣������Ϊĳ�ֹ���ֹͣ���У�
        // ��ʱ���Խ����������������������ԭ��û�г����ϣ�
        // ��ô��ʱ�����������޸����ǵ�����ʱ�䡣
        start_all_quest();

        if (! mapp(total = query("information")))
                return;

        // ���㵱ǰʱ��
        t = time();

        // ɨ�����е�����ֻ������Ч������
        foreach (key in keys(total))
        {
                reset_eval_cost();
                if (! objectp(key))
                        map_delete(total, key);
                else
                switch (key->query_status())
                {
                case QUEST_CREATE:
                        if (t - key->query("start_time") > QUEST_CREATE_PERIOD)
                        {
                                // �������񳬹���Чʱ���ˣ�����֮
                                log_file("static/quest", sprintf("%s quest: %s create timeout\n%O",
                                                                 log_time(), base_name(key),
                                                                 key->query_entire_dbase()));
                                catch(key->change_status(QUEST_FINISH));
                                map_delete(total, key);
                        }
                        break;

                case QUEST_FINISH:
                        if (t->query("finish_time") > QUEST_FINISH_PERIOD)
                                // �������񳬹���Чʱ����
                                key->change_status(QUEST_ERROR);
                        break;

                case QUEST_ERROR:
                        // ���������д���״̬��
                        break;

                default:
                        // ������ͨ������״̬��
                        if ((live_time = key->query("live_time")) > 0 &&
                            live_time < t - key->query("start_time"))
                        {
                                // ���泬����ʱ��
                                catch(key->change_status(QUEST_FINISH));
                                map_delete(total, key);
                        }
                        break;
                }
        }
}

// ����Ϣ��ͨ��ʿ����ʹ��
public string generate_information(object knower, object who, string topic)
{
        mapping total;
        object *obs;
        object *dest;
        string name, title;
        object last_ob;
        mixed answer;

        total = query("information");

        switch (random(30))
        {
        case 0:
                return "���磡�е��ð��������˼��";
        case 1:
                return "�ȡ��ȵȣ���˵ʲô��û�������";
        case 2:
                return "�ţ��ԵȰ����ͺá����ˣ���ղ�˵ɶ��";
        case 3:
                return "����������Ŷ�����ˣ������������أ�";
        case 4:
                return "���ϣ�������˼����������ô��";
        case 5:
                return "�ͺá��ͺá����ˣ���˵ɶ��";
        case 7:
                return "�ţ����Ե�һ�£������ﻹûæ�ꡣ";
        }

        if (topic == "rumor" || topic == "��Ϣ")
        {
                // ���ɴ���
                if (! mapp(total) ||
                    ! sizeof(obs = filter_array(keys(total), (: objectp($1) :))))
                {
                        // Ŀǰû���κ�����
                        switch (random(3))
                        {
                        case 0:
                                return "���ûɶ��Ϣ��";
                        case 1:
                                return "�������̫ͦƽ�ġ�";
                        default:
                                return "��֪��...��ȥ���ʱ��˰ɡ�";
                        }
                }

                // ���˸�С������ɢ������Ϣ
                obs = filter_array(obs, (: objectp($1) && $1->can_rumor_by($(knower)) :));
                if (! sizeof(obs))
                {
                        // ����ʿ����ɢ����Ϣ
                        switch (random(3))
                        {
                        case 0:
                                return "�ҵ�����˵��������ϳ��˲����¶���";
                        case 1:
                                return "��ѽѽ����Ҳ֪����һЩ���ܣ������˵˵��";
                        default:
                                return "����ͷ����Խ��Խ���ˡ�";
                        }
                }

                // ���ѡ��һ������ɢ����������Ϣ
                last_ob = obs[random(sizeof(obs))];
                knower->set_temp("last_asked_quest", last_ob);
                if (answer = last_ob->query_prompt(knower, who))
                        return answer;

                switch (random(3))
                {
                case 0:
                        return "�������������йء�" HIY +
                               last_ob->name() + NOR CYN "���Ĵ��ţ�";
                case 1:
                        return "�������ʢ����" HIY +
                               last_ob->name() + NOR CYN "����������أ�";
                default:
                        return "��û��������Ҷ������ۡ�" HIY +
                               last_ob->name() + NOR CYN "����";
                }
        }

        if (! mapp(total))
                return 0;

        // ��ø���֪��������������Ϣ
        obs = filter_array(keys(total), (: objectp($1) :));
        obs = filter_array(obs, (: $1->can_know_by($(knower)) :));

        // �鿴�Ƿ���ĳһ�������ĳһ����Ŀ
        if (sscanf(topic, "%s.%s", name, title) == 2)
        {
                dest = filter_array(obs, (: $1->name() == $(name) :));
                if (! sizeof(dest))
                        return 0;

                last_ob = dest[0];
        } else
        {
                // �鿴�Ƿ���ĳһ������
                dest = filter_array(obs, (: $1->name() == $(topic) :));
                if (sizeof(dest) > 0)
                {
                        last_ob = dest[0];
                        knower->set_temp("last_asked_quest", last_ob);
                        answer = last_ob->query_introduce(knower, who);
                        if (stringp(answer))
                                return answer;
                        return "��˵����" HIY + knower->name() +
                               HIY "�Ǽ������������������ʶ����ˡ�" NOR;
                } else
                // �鿴���һ�α�ѯ�ʵ�������Ϣ���Ƿ��и���Ŀ
                {
                        last_ob = knower->query_temp("last_asked_quest");
                        if (! objectp(last_ob) || ! mapp(total[last_ob]))
                                return 0;

                        title = topic;
                }
        }

        // �����й�ĳ�������ĳ����Ŀ����Ϣ
        knower->set_temp("last_asked_quest", last_ob);
        answer = total[last_ob];

        if (! mapp(answer))
                return 0;

        // �������Ǽ��˾������Ϣ
        answer = answer[title];
        if (functionp(answer))
                return evaluate(answer, knower, who, topic);

        if (stringp(answer))
                return answer;

        return 0;
}
