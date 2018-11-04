// zhu.c ����

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

string ask_buy();
string ask_job();
int  do_copy(string arg);
int  working(object me);
int  halt_working(object me);

void create()
{
        set_name("����", ({ "zhu xi", "zhu", "xi" }));
        set("long", "����������Ϊ������һ����ѧ�ң�����"
                    "���īˮ�Ⱥ���Ҫ�\n");
        set("title", HIR "��ѧ����ʦ" NOR);
        set("gender", "����");
        set("age", 65);
        set("no_get", 1);
        set_skill("literate", 600);

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        set("inquiry", ([
            "����" : (: ask_buy :),
            "����" : (: ask_job :),
            "����" : (: ask_job :),
            "job"  : (: ask_job :),
            "��"   : "�����鵽��ʱ�����١�",
            "����" : "�裿�㲻���ҵ��������㣿�ߣ�",
        ]));
        set("vendor_goods", ({
                "/clone/book/lbook0",
                "/clone/book/lbook1",
                "/clone/book/lbook2",
                "/clone/book/lbook3"
        }));
        setup();

        set("chat_chance", 1);
        set("chat_msg", ({
                CYN "����˵��������֮�£�Ī������������֮����Ī��������\n" NOR,
                CYN "����˵���������ˣ�С�������ɣ����������δ������֮��\n" NOR,
                CYN "����˵������ѧ֮�����������¡���������ֹ�����ơ� \n" NOR,
                CYN "����˵����������֪���������ģ�������ң��ι�ƽ���¡�\n" NOR,
        }) );
}

void init()
{
        add_action("do_copy", "copy");
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int recognize_apprentice(object ob)
{
        if (! (int)ob->query_temp("mark/��"))
                return 0;
        ob->add_temp("mark/��", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        object me = this_player();

        if (!(int)who->query_temp("mark/��"))
                who->set_temp("mark/��", 0);

        if (ob->query("money_id") && ob->value() >= 2000)
        {
                message_vision("����ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
                who->add_temp("mark/��", ob->value() / 50);
                destruct(ob);
                return 1;
        }

        command("say �����ѧ�棬����Ҫ��ʮ��������");
        return 0;
}

string ask_buy()
{
        return "������в��ٶ����˱ض�����Ӵ!\n";
}

string ask_job()
{
        object me;
        object *obs;

        me = this_player();
        if (me->query_temp("job/copy"))
                return "���㳭�����㳭���ˣ�";

        if (me->query("combat_exp") < 1200)
                return "��Ȼ������ֻ�ǳ����飬������ս��������ô�Ҫ"
                       "����С��å��������ô�죿";

        if (me->query("combat_exp") > 8000)
                return "������Ҳ�����飿�����������ˣ����߰���";

        if (me->query("qi") < 20)
                return "�ҿ�����ɫ���а�����Ъ����ɣ��ҿɲ��볭�鳭����������";

        if (me->query("jing") < 10)
                return "�ҿ��㾫���а����ܳ�������ô��";

        if (me->query_int() < 25 && me->query_skill("literate", 1) < 20)
                return "��˵��������ô����Ҳ�����飿";

        if (! interactive(me))
                return "...";

        obs = filter_array(all_inventory(environment()),
                           (: interactive($1) &&
                              $1 != $(me) &&
                              $1->query_temp("job/copy") &&
                              query_ip_number($1) == query_ip_number($(me)) :));
        if (sizeof(obs) > 0)
                return "�����Ѿ���" + obs[0]->name() + "�ڸɻ��ˣ���ȵȰɡ�";

        me->set_temp("job/copy", 1);
        return "�ã���Ͱ��ҳ���(copy)�ɣ���īֽ���������";
}

int do_copy(string arg)
{
        object me;

        me = this_player();
        if (me->is_busy())
                return notify_fail("����æ���أ����ż���\n");

        if (! me->query_temp("job/copy"))
        {
                message_vision("$N����ë�ʣ�����պī��������$n��ȵ���"
                               "���ҷ��£����Ҷ��ķ��ı���\n",
                               me, this_object());
                return 1;
        }

        me->set_temp("job/step", 1);
        me->start_busy(bind((: call_other, __FILE__, "working" :), me),
                       bind((: call_other, __FILE__, "halt_working" :), me));
        tell_object(me, "�㿪ʼ������\n");
        return 1;
}

int working(object me)
{
        string msg;
        int finish;
        int b;

        if (! me->query_temp("job/step"))
                me->set_temp("job/step", 1);

        if (! living(me))
        {
                me->delete_temp("job/copy");
                me->delete_temp("job/step");
                return 0;
        }

        finish = 0;
        me->receive_damage("jing", 1);
        me->receive_damage("qi", 2);
        switch (me->query_temp("job/step"))
        {
        case 1:
                msg = "$N�ù���̨����������ī��";
                break;
        case 2:
                msg = "$N����īĥ�ò���ˣ�����ë�ʣ����������������";
                break;
        case 3:
                msg = "$N��պī֭���������飬̯��ֽ�ţ���ʼ��д��";
                break;
        case 4:
        case 6:
                msg = "$N�۾�����ĳ�д�鼮��";
                break;
        case 5:
                msg = "$Nպ��պī��������ϸ�س�д��";
        case 7:
                msg = "$N���Ϸ������鼮��ֽ��Խ��Խ��";
                break;
        default:
                msg = "$N���鼮���ã���ֽ��ī���ɣ�װ���ɲᣬ�ݸ�$n��";
                finish = 1;
                break;
        }
        msg += "\n";

        if (finish)
        {
                object ob;
                msg += "$n����$N��д���飬����������У����ӿɽ̣�"
                       "���Ǹ���ı��꣡�������������ѧ���Ļ���\n";
                me->delete_temp("job/copy");
                me->delete_temp("job/step");

                b = 5 + random(4);
                me->add_temp("mark/��", 20);
                me->add("combat_exp", b);
                me->improve_potential((b + 2) / 3);

                if (me->query_skill("literate", 1) < 100)
                        me->improve_skill("literate", (b + 1) / 2);

                ob = new("/clone/money/coin");
                ob->set_amount(50);
                ob->move(me, 1);
        }

        msg = replace_string(msg, "$N", "��");
        msg = replace_string(msg, "$n", name());
        tell_object(me, msg);

        if (finish)
        {
                if (b > 0)
                {
                        tell_object(me, HIC "\n������" +
                                    chinese_number(b) +
                                    "�㾭���" +
                                    chinese_number((b + 2) / 3) +
                                    "��Ǳ�ܡ�\n\n" NOR);
                }
                return 0;
        }

        me->add_temp("job/step", 1);
        return 1;
}

int halt_working(object me)
{
        message_vision("$N�����еı�īֽ�ⶪ��һ�ԣ���ɧ����"
                       "ʲôѽ�������Ͳ����˸ɵĻ\n", me);
        me->delete_temp("job/copy");
        me->delete_temp("job/step");
        return 1;
}
