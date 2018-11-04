// qingyangzi.c  �����
// Written by Vin  2002/4/28

#include <ansi.h>
inherit NPC;

int ask_me();
int tattoo(object me);

mapping body_type = ([ "����" : ({ "face" }),
                       "�ؿ�" : ({ "chest" }),
                       "��" : ({ "back" }),
                       "�β�" : ({ "buttock" }),
                       "���" : ({ "leftarm" }),
                       "�ұ�" : ({ "rightarm" }), ]);

void create()
{
        set_name("�����", ({ "qingyang zi", "qingyang", "zi" }));
        set("long", "���������µ�һ����ʦ����ӡ�\n" );

        set("nickname", HIB "����ʦ" NOR);
        set("gender", "����");
        set("attitude", "friendly");
        set("age", 325);
        set("shen_type", 0);
        set("str", 500);

        set("inquiry", ([
                "����" : (: ask_me :),
                "����" : (: ask_me :),
        ]));

        setup();

        if (! clonep(this_object()))
        {
                move("/d/luoyang/suanming");
                message_vision(CYN "\n$N" CYN "���˹������������ܣ���"
                               "��һ����̾��\n" NOR, this_object());
                set("startroom", "/d/luoyang/suanming");
        }

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/tattoo/npc_item2")->wield();
        set_temp("handing", carry_object("/clone/tattoo/npc_item1"));
}

void init()
{
        add_action("do_show", "show");
        add_action("do_answer", "answer");
        // ��������н�ֹ�鿴����״̬��ΪʲôҪ�����أ���Ϊ
        // ʵ�������Ѿ��ڽ�������������Ĵ������ǰ�������ˡ�
        add_action("do_check", "hp");
        add_action("do_check", "score");
        add_action("do_check", "special");
}

int do_check()
{
        object me = this_player();

        if (me->query_temp("item/status") == "waiting")
        {
                message_vision(CYN "$N" CYN "��$n" CYN "�ȵ�������"
                               "������û���꣬��Ｑʲô��\n" NOR,
                               this_object(), me);
                return 1;
        }
}

int do_show(string arg)
{
        string status, msg, mat;
        object me, ob;
        int value, n;

        me = this_player();
        if (! arg)
                return notify_fail("����Ҫ����ʲô������\n");

        mat = arg;

        if (! objectp(ob = present(mat, me)))
                return notify_fail("�������ƺ�û�����ֶ�����\n");

        status = query_temp("item/status");

        if (status == "look_working")
        {
                message_vision(CYN "$N" CYN "ͷҲ��̧����$n" CYN "˵����"
                               "������æ������µȻ���˵��\n" NOR,
                               this_object(), me);
                return 1;
        }

        if (! ob->query("can_tattoo"))
        {
                message_vision(CYN "$N" CYN "üͷһ�壬��$n" CYN "˵����"
                               "��ֻ��ͼ�ڸ���Ȥ��û�±������ҡ�\n" NOR,
                               this_object(), me);
                return 1;
        }

        if (ob->query("value") >= 12000)
                msg = sprintf(CYN "$N" CYN "�ӹ�$n" CYN "�ó���ͼ������������"
                              "֮������һ����̾��\n" NOR);
        else
        if (ob->query("value") >= 5000)
                msg = sprintf(CYN "$N" CYN "�ӹ�$n" CYN "�ó���ͼ��������һ��"
                              "������¶���������ɫ��\n" NOR);
        else
        if (ob->query("value") >= 2000)
                msg = sprintf(CYN "$N" CYN "�ӹ�$n" CYN "�ó���ͼ����������ü"
                              "���ƺ���˵Щʲô��\n" NOR);
        else
                msg = sprintf(CYN "$N" CYN "����$n" CYN "������ͼ������Цһ��"
                              "������¶����м����ɫ��\n" NOR);

        value = ob->query("value") / 50 + 20;
        msg += sprintf(CYN "$N" CYN "���˵�ͷ���������Ĵ�����Ҫ�ƽ�%s��������"
                       "�����ðɡ�\n" NOR, chinese_number(value));
        message_vision(msg, this_object(), me);

        return 1;
}

// ������ʾ��Ϣ
int ask_me()
{
        message_sort(CYN "$N" CYN "̧ͷ���˿�$n" CYN "����ͷ�����Ȱ��������"
                     "�̵�ͼ���ø��ҿ�(" HIY "show" NOR + CYN ")�������ҹ���"
                     "һ�¼�Ǯ��������ú��ʾͽ�Ǯ��\n" NOR, this_object(),
                     this_player());
        return 1;
}

// ���ܶ���
int accept_object(object me, object ob)
{
        string status;
        int val;

        status = query_temp("item/status");
        if (status == "look_working")
        {
                message_vision(CYN "$N" CYN "ͷҲ��̧����$n" CYN "˵����"
                               "������æ������µȻ���˵��\n" NOR,
                               this_object(), me);
                return 0;
        }

        if (status == "waiting")
        {
                if (query_temp("item/player_id") == me->query("id"))
                {
                        command("say ������ɺã����Ҷ���");
                        return 0;
                }

                message_vision(CYN "$N" CYN "ͷҲ��̧����$n" CYN "˵����"
                               "������æ������µȻ���˵��\n" NOR,
                               this_object(), me);
                return 0;
        }

        if (status == "accept")
        {
                if (query_temp("item/player_id") != me->query("id"))
                {
                        command("say û������æô��������ʲô�ң�");
                        return 0;
                }

                if (! ob->query("money_id"))
                {
                        command("say �����㽻Ǯ�������������");
                        return 0;
                }
        }

        if (ob->query("can_tattoo") && ob->query("tattoo_type"))
        {
                mixed p;
                string *types;

                types = keys(body_type);

                p = me->query("tattoo/tattoo");
                if (arrayp(p))
                        types -= p;
                else
                if (stringp(p))
                        types -= ({ p });

                if (! sizeof(types))
                {
               	        message_vision(CYN "$N" CYN "��$n" CYN "��Ц������ȫ"
               	                       "���Ѿ��Ƶø���һ���ˣ����Ӳ���ô��\n"
               	                       NOR, this_object(), me);
                        return 0;
                }

                if ((p = ob->query("can_tattoo")) == "all")
                {
                        types = keys(body_type);
                } else
                if (arrayp(p))
                        types = p;
                else
                if (stringp(p))
                        types = ({ p });

                // ȷ�ϸ�ID�Ƿ��еط��Ѿ�������
                p = me->query("tattoo/tattoo");
                if (arrayp(p))
                        types -= p;
                else
                if (stringp(p))
                        types -= ({ p });

                if (! sizeof(types))
                {
                        message_vision(CYN "$N" CYN "ҡ��ҡͷ�������ͼ"
                                       "�ڲ����ʺ��Ƶ���ʣ�µĲ�λ�ϡ�\n"
                                       NOR, this_object(), me);
                        return 0;
                }

                // ������������ѵļ�ֵ
                val = ob->query("value") / 50 + 20;
                message_vision(CYN "$N" CYN "���˵�ͷ���������Ĵ�����Ҫ�ƽ�" +
                               chinese_number(val) + "���������ھ͸�Ǯ�ɡ�\n"
                               NOR, this_object(), me);
                val *= 10000;
                ob->set("item/value", val);
                me->set_temp("item/status", "item_gived");
                me->set_temp("item/value", val);
                set_temp("item/status", "accept");
                set_temp("item/player_id", me->query("id"));
                set_temp("item/accept", ob);

                remove_call_out("time_out");
                call_out("time_out", 30, me, ob);
                return 1;
        }

        if (ob->query("money_id"))
        {
                object origin;
                mixed p;
                string *types;

                if (me->query_temp("item/status") == "answer_type")
                {
                        message_vision(CYN "$N" CYN "ҡҡͷ����$n" CYN "������"
                                       "�Ÿ�Ǯ����˵˵��Ҫ��ʲô��\n" NOR,
                                       this_object(), me);
                        return 0;
                }

                if (me->query_temp("item/status") != "item_gived")
                {
                        message_vision(CYN "$N" CYN "��$n" CYN "�ݹ�ȥ��" + ob->name() +
                                       CYN "���˻�����ҡͷ�����޹�����»��\n" NOR,
                                       this_object(), me);
                        return 0;
                }

                if (ob->value() < me->query_temp("item/value"))
                {
                        message_vision(CYN "$N" CYN "��Ц����������˭��֪������"
                                       "���˵һ�������ѵ���Ϊ��������\n" NOR,
                                       this_object(), me);
                        return 0;
                }

                origin = query_temp("item/accept");
                if ((p = origin->query("can_tattoo")) == "all")
                {
                        types = keys(body_type);
                } else
                if (arrayp(p))
                        types = p;
                else
                if (stringp(p))
                        types = ({ p });

                // ȷ�ϸ�ID�Ƿ��еط��Ѿ�������
                p = me->query("tattoo/tattoo");
                if (arrayp(p))
                        types -= p;
                else
                if (stringp(p))
                        types -= ({ p });

                if (! sizeof(types))
                {
                        message_vision(CYN "$N" CYN "ҡ��ҡͷ���������"
                                       "�಻�ʺ��Ƶ���ʣ�µĲ�λ��\n" NOR,
                                       this_object(), me);
                        return 0;
                }

                set_temp("item/types", types);
                set_temp("item/money", ob);

                ob->move(this_object());

                message_vision(CYN "$N" CYN "��$n" CYN "˵�����������ʲ"
                               "ô�ط����ࣿ�����(" HIY "answer" NOR +
                               CYN ")�Ҿ��岿λ��\n" NOR, this_object(), me);
                tell_object(me, HIC "�㻹������" HIY + implode(types, "��" )
                                + HIC "�ϴ��ࡣ\n" NOR);

                me->set_temp("item/status", "answer_type");
                return -1;
        }

        message_vision(CYN "����Ӷ�$N" CYN "��ü���������е����⣬������"
                       "ʦ�����㿴����\n" NOR, me);
        return 0;
}

int do_answer(string arg)
{
        string *tattooed, *types;
        string tlong, special;
        object ob, me;
        object money;

        me = this_player();
        if (me->query_temp("item/status") != "answer_type")
                return 0;

        if (! arg)
                return notify_fail("��Ҫ�ش�ʲô��\n");

        message_vision(CYN "$n" CYN "����ͷ����һ�ᣬ��$N" CYN "������"
                       "���ͼ���Ѵ��������ҵ�" + arg + "�ϰɣ�\n" NOR,
                       this_object(), me);

        if (member_array(arg, query_temp("item/types")) == -1 ||
            undefinedp(body_type[arg]))
        {
                message_vision(CYN "$N" CYN "���˿�$n" CYN "�����ĵ���"
                               "Ц��һ����\n" NOR, this_object(), me);
                return 1;
        }

        if (objectp(money = query_temp("item/money")))
                destruct(money);

        set_temp("item/status", "look_working");
        me->set_temp("item/status", "waiting");

        ob = query_temp("item/accept");

        message_sort(HIC "\n$N" CYN "���˵�ͷ����$n" CYN "˵��������"
                     "��Ϳ�ʼ�ɣ����ɵ��ǱߵĴ���ȥ�����Ҷ���$N"
                     HIC "˵���ת����ȥ�����ֽ�" + ob->name() + HIC
                     "��������ˮ�裬��" + ob->name() + HIC "��ȫʪ"
                     "͸����С������ش�ˮ��ȡ������������$n" HIC
                     "��" + arg + "֮�ϡ�\n\n" NOR, this_object(), me);

        // Ϊ�Ѿ�������Ĳ�λ�Ǻ�
        tattooed = me->query("tattoo/tattoo");

        if (! arrayp(tattooed))
                tattooed = ({ });

        tattooed -= ({ arg });
        tattooed += ({ arg });
        me->set("tattoo/tattoo", tattooed);

        // ���Ӳ�ͬ��λ�Ĵ�������
        tlong = ob->query("tattoo_long");

        switch (arg)
        {
        case "����":
                me->set("tattoo/face_long", tlong);
                break;
        case "�ؿ�":
                me->set("tattoo/chest_long", tlong);
                break;
        case "��":
                me->set("tattoo/back_long", tlong);
                break;
        case "���":
                me->set("tattoo/leftarm_long", tlong);
                break;
        case "�ұ�":
                me->set("tattoo/rightarm_long", tlong);
                break;
        default:
                me->set("tattoo/buttock_long", tlong);
                break;
        }

        // ����ͼ���ṩ�ĺ������ԼǺ�
        if (ob->query("tattoo_str"))
                me->add("tattoo/tattoo_str", ob->query("tattoo_str"));

        if (ob->query("tattoo_int"))
                me->add("tattoo/tattoo_int", ob->query("tattoo_int"));

        if (ob->query("tattoo_con"))
                me->add("tattoo/tattoo_con", ob->query("tattoo_con"));

        if (ob->query("tattoo_dex"))
                me->add("tattoo/tattoo_dex", ob->query("tattoo_dex"));

        if (ob->query("tattoo_per"))
                me->add("tattoo/tattoo_per", ob->query("tattoo_per"));

        // ����ͼ���ṩ�����⼼��
        special = ob->query("tattoo_special");
        if (special)
        {
                me->set("special_skill/" + special, 1);
                me->set("tattoo/special/" + special, 1);
        }

        // ִ�д���Ĺ�������
        me->start_busy(bind((: call_other, __FILE__, "tattoo" :), me));

        remove_call_out("time_out");
        destruct(ob);
        return 1;
}

int tattoo(object me)
{
        object ob;
        string msg;
        int finish;

        if (! me->query_temp("tattoo/step"))
                me->set_temp("tattoo/step", 1);

        finish = 0;
        switch (me->query_temp("tattoo/step"))
        {
        case 1:
                msg = "������߽����ã��˳�һ��̴ľ����У��������һ�����롣";
                break;
        case 2:
                msg = "��������ӽ�$N������ڷŶ�����������ͼ���е�����ʩ�롣";
                break;
        case 3:
                msg = "ֻ��������Ƴ���磬ÿһ�����һմ��������ȥ��ΪѸ�ݡ�";
                break;
        case 4:
                msg = "����ʱ�������������ѱ�����ӹ��ճ�������ͼ�ڷֺ����";
                break;
        case 5:
                msg = "��һ�ᣬ$N�����ϵ����������������������뼡����Ϊһ�塣";
                break;
        case 6:
                msg = "�㲻����̾����ӵ��뷨���棬����ǧ���뾹������Ѫӿ����";
                break;
        case 7:
                msg = "����ӽ��ŴӺ�����ȡ��ʮ��ɫ��ƿ����ȡ��ĩ����ɫ���С�";
                break;
        case 8:
                msg = "�������ָ�׼�����������ɫ��ĩ���ٷֱ���$N����֮�ϡ�";
                break;
        case 9:
                msg = "�������ã����ڴ����ϵĸ�ɫ��ĩ�Ѿ�����������$N�ļ�����";
                break;
        case 10:
                msg = "�����ϵ���ɫ������¶�˳�����ɫ�����ޣ���ͼ�ڸ��޶��¡�";
                break;
        case 11:
                msg = "ֻ�������ϵ���������ϸ����������������Ҫ�������һ�㡣";
                break;
        case 12:
                msg = "�����������ã����˵�ͷ�������ȥ�˴�����ʣ��ķ�ĩ��";
                break;
        default:
                msg = "����Ӷ�$N˵����ͼ���ϵ������Ѿ�������̺��ˣ�����ɡ�";
                finish = 1;
                break;
        }
        msg += "\n";

        msg = replace_string(msg, "$N", "��");
        msg = replace_string(msg, "$n", name());
        message("vision", HIG + msg + NOR, me);

        if (finish)
        {
                if (objectp(ob = present("qingyang zi", environment(me))))
                {
                        ob->delete_temp("item");
                        message_vision(HIC "\n$N" HIC "��$n" HIC "˵����"
                                       "Ǯ�����ˣ�������������ˣ��Ӵ���"
                                       "��������Ƿ��\n" NOR, ob, me);
                }

                me->delete_temp("item");
                me->delete_temp("tattoo/step");
                tell_object(me, HIY "\n�����������е������ƺ�����ĳ"
                                "�����صı仯��\n" NOR);
                return 0;
        }
        me->add_temp("tattoo/step", 1);
        return 1;
}

void time_out(object me, object ob)
{
        object money;
        int at_present;

        money = query_temp("item/money");

        if (! objectp(me))
                me = find_player(query_temp("item/player_id"));

        if (! objectp(me) || environment(me) != environment())
        {
                command("say ��֣��ղ���λ�����أ���ô������ˣ�\n");
                at_present = 0;
        } else
        {
                command("say ��������ԥ�ɣ��ҿɲ��ܸ�����ţ���������ɣ�");
                at_present = 1;
        }

        delete_temp("item");
        if (objectp(me))
                me->delete_temp("item");

        if (money)
        {
                if (at_present)
                        command("give " + money->query("id") +
                                " to " + me->query("id"));

                if (environment(money) == this_object())
                        command("drop " + money->query("id"));
        }

        if (ob)
        {
                if (at_present)
                        command("give " + ob->query("id") +
                                " to " + me->query("id"));

                if (environment(ob) == this_object())
                        command("drop " + ob->query("id"));
        }
}
