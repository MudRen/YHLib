// jiangong �๤

#include <ansi.h>

inherit NPC;

mixed ask_mine();
mixed ask_transit();
int  do_move(string arg);
int  working(object me);
int  halt_working(object me);

void create()
{
        set_name("�๤", ({ "jian gong", "jian", "gong", "jiangong" }));
        set("long", "����һ���๤���ֳֳ��ޣ��۹�һգ��գ��"
                    "�������ˣ�����ߺ�ȸ���ͣ��\n");
        set("gender", "����");
        set("age", 32);
        set_skill("unarmed", 100);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);

        set("combat_exp", 500000);
        set("shen_type", 1);
        set("inquiry", ([
            "job"  : "������ɿ�(mine)���������˻�(transit)��",
            "����" : "������ɿ�(mine)���������˻�(transit)��",
            "�ɿ�" : (: ask_mine :),
            "mine" : (: ask_mine :),
            "�˻�" : (: ask_transit :),
            "transit" : (: ask_transit :),
        ]));
        setup();

        set("chat_chance", 1);
        set("chat_msg", ({
                CYN "�๤�ȵ����죡����Ҹɣ�\n" NOR,
                CYN "�๤һ����ӣ�����������̵ģ�����ҷ���ʵ�㡣\n" NOR,
                CYN "�๤���������ܣ���֪���ڴ�ʲô���⡣\n" NOR,
                CYN "�๤�ݺݵĳ���һ���˼��£��������ô�ѿ�ʯ���������ˣ����Ɀ����\n" NOR,
        }));

        carry_object("clone/weapon/changbian")->wield();
}

void init()
{
        add_action("do_mine", "mine");
}

mixed ask_mine()
{
        object me;
        object *obs;

        me = this_player();
        if (me->query_temp("job/mine"))
                return "��������ȥ��ô��������ˣ���������ǰ�滨����";

        if (me->query("combat_exp") < 10000)
                return "������������㱾�£��¾�����������֪����";

        if (me->query("combat_exp") > 200000)
                return "�٣������Ǹ��ҿ���Ц�ɣ������̫ί�����ˡ�";

        if (me->query("qi") < 120)
                return "�ҿ����Ѿ������ˣ����ǿ���ɣ�";

        if (me->query_str() < 28)
                return "��˵���ж��������Ҳ�������֣�";

        if (! interactive(me))
                return "...";

        obs = filter_array(all_inventory(environment()),
                           (: interactive($1) &&
                              $1 != $(me) &&
                              $1->query_temp("job/mine") &&
                              query_ip_number($1) == query_ip_number($(me)) :));
/*
        if (sizeof(obs) > 0)
                return "�����Ѿ���" + obs[0]->name() + "�ɻ��أ���Ъ�Űɡ�";
*/

        me->set_temp("job/mine", 1);
        return "�ã����¾�ȥ��(mine)Щ��ʯ�������ŵ��Ǳߵĳ��ϣ����˻�ٸ���Ȼ���Ǯ��";
}

int do_mine(string arg)
{
        object me;
        object *obs;

        me = this_player();
        if (me->is_busy())
                return notify_fail("����æ���أ����ż���\n");

        if (! me->query_temp("job/mine"))
                return notify_fail("����û��Ϲæ��ɶ��\n");

        // �鿴��ʱ�ɿ���ж�����
        obs = filter_array(all_inventory(environment(me)),
                           (: userp($1) && $1->query_temp("job/step") :));

        if (sizeof(obs) >= 15)
                return notify_fail("���ڲɿ���˺ö࣬��"
                                   "�ӵ����¾�����ֻ���ȵȻ����\n");

        me->set_temp("job/step", 1);
        me->start_busy(bind((: call_other, __FILE__, "working" :), me),
                       bind((: call_other, __FILE__, "halt_working" :), me));
        tell_object(me, HIC "�㿪ʼ������\n" NOR);
        return 1;
}

int working(object me)
{
        string msg;
        int finish;
        int b;
        object bonus;

        if (! me->query_temp("job/step"))
                me->set_temp("job/step", 1);

        if (! living(me))
        {
                me->delete_temp("job/mine");
                me->delete_temp("job/step");
                return 0;
        }

        finish = 0;
        switch (me->query_temp("job/step"))
        {
        case 1:
                me->receive_damage("qi", 1);
                msg = "$N�첽�ĳ�������ȥ��";
                break;
        case 2:
                me->receive_damage("qi", 1);
                msg = "$N�ߵ����ڣ������������ɿ�ʯ�ġ�";
                break;
        case 3:
                me->receive_damage("qi", 1);
                msg = "���ڼ����˿��˿�$N��һ���˰��˰��֣��������������";
                break;
        case 4:
                me->receive_damage("qi", 1);
                msg = "$N�������У����ڵ��˿�ʼ������ֻ��֨֨�¸µģ�������������׹ȥ��";
                break;
        case 5:
                me->receive_damage("qi", 1);
                msg = "$N��ǰԽ��Խ�ڣ��������ӻ��ǷŸ���ͣ��";
                break;
        case 6:
                me->receive_damage("qi", 1);
                msg = "��Ȼ$N����ǰһ����ԭ����һյ�͵ƣ��谵�Ļ��治�ϵ�������";
                break;
        case 7:
                me->receive_damage("qi", 1);
                msg = "���ӻ��ǲ��ϵ����·ţ������ƺ�û�о�ͷ��";
                break;
        case 8:
                me->receive_damage("qi", 1);
                msg = "���Ӻ�Ȼͣס�ˣ������ǵ��˵ط���$N��������һ������";
                break;
        case 9:
                me->receive_damage("qi", 3);
                msg = "$N������һЩ������Ŭ���ĸɻ$N��æ����ȥ��Ҳ������ӡ�";
                break;
        case 10:
                me->receive_damage("qi", 6);
                msg = "$N�������ռ���ɫ�Ŀ�ʯ�������Ƿŵ����С�";
                break;
        case 11:
                me->receive_damage("qi", 8);
                msg = "$N���÷�������ˣ�������У����������ӡ�";
                break;
        case 12:
                me->receive_damage("qi", 1);
                msg = "����Ƭ�̣����Ӻ�Ȼ���˻Σ�$N����������������ȥ��";
                break;
        case 13:
                me->receive_damage("qi", 1);
                msg = "����Խ��Խ�������ڵ��˶��ڣ�ֻ�����ڼ�����æ����ͷ�󺹡�";
                break;
        case 14:
                me->receive_damage("qi", 7);
                msg = "$N������л����æ�������ӣ�����ȥ�ˡ�";
                break;
        case 15:
                me->receive_damage("qi", 6);
                msg = "$N�ϵ����Աߣ���������������ʯ�������С�";
                break;
        default:
                me->receive_damage("qi", 4);
                msg = "$N�������˺������������ӣ������Ǹ���һ���ˡ�";
                finish = 1;
                break;
        }
        msg += "\n";

        if (finish)
        {
                if (me->query_str() >= 35)
                        msg += "$n����$N�������Ŀ�ʯ�����ͷ�����ܺ�"
                               "����һ��Ū�˲��ٰ���\n";
                else
                        msg += "$n����$N���ʯ�ϣ��������У�������"
                               "�ɡ��ߣ��Ǳ��칤Ǯȥ��\n";

                // ���ؿ�ʯ����
                environment(me)->improve_product_amount("cuprum_ore",
                                                        10 + (me->query_str() - 28));

                me->delete_temp("job/mine");
                me->delete_temp("job/step");

                if (me->query("combat_exp") < 200000)
                {
                        b = 10 + random(17);
                        me->add("combat_exp", b);
                        me->improve_potential((b + 2) / 3);
                        me->improve_skill("unarmed", (b + 1) / 2);
                }

                bonus = new("/clone/money/coin");
                bonus->set_amount(30 + (me->query_str() - 28) * 3);
        }

        msg = replace_string(msg, "$N", "��");
        msg = replace_string(msg, "$n", name());
        message("vision", msg, me);
        if (finish)
        {
                tell_object(me, "��ȥ���µ������쵽�˹�Ǯ��\n");
                bonus->move(me, 1);
                if (b > 0)
                {
                        tell_object(me, HIC "\n������ζ����������ѧҲ����һЩ��ᣬ�����" +
                                    chinese_number(b) + "�㾭���һЩǱ�ܡ�\n\n" NOR);
                }
                return 0;
        }

        me->add_temp("job/step", 1);
        return 1;
}

int halt_working(object me)
{
        message_vision(HIR "$N" HIR "ҡҡͷ��û˵����������ʹ��ˤ��"
                       "���ϣ������ˡ�\n" NOR, me);
        me->delete_temp("job/mine");
        me->delete_temp("job/step");
        return 1;
}

mixed ask_transit()
{
        string startroom;
        int c;
        object ob;
        object me;
        int amount;

        if (! stringp(startroom = query("startroom")) ||
            find_object(startroom) != environment())
                // not in start room
                return "�ҡ����е�ͷ�Ρ��ȡ��Ȼ������";

        me = this_player();

        if (me->query("score") < 1000)
                return "�ҿ�����������̫ǳ�����ɲ��������˻���";

        if (me->query("combat_exp") < 50000)
                return "���в��У������˱���̫�·�ϱ�ѻ������ˣ�";

        if (me->query("combat_exp") > 300000)
                return "�٣������Ǹ��ҿ���Ц�ɣ������̫ί�����ˡ�";

        if (objectp(me->query_temp("job/hz_cart")))
                return "�ϴ������͵���������ô����ȥ���ٺ������£�";

        if ((amount = me->query("job/hz_cuprum_ore")) > 0)
        {
                amount = (amount + 99) / 100;
                // ����(MUDʱ��)��������ﻹû���ʹ������
                message_sort("$N��Цһ������$n������" + me->name(1) +
                             "���ϴ����͵Ļ�...�ߣ������㱾��"
                             "��΢�ķ��ϣ��Ҳ����׷���ˣ���"
                             "���ǳ�ͭ��ʯ���ܾ������װ׵Ķ�"
                             "�ˣ���������" + chinese_number(amount) +
                             "���ƽ𣬳��ͭ����˵����\n",
                             this_object(), me);
                return 1;
        }

        c = environment(me)->query_product_amount("cuprum_ore");
        if (c < 300)
                return "���ڻ�û�ж��ٿ�ʯ�أ���æ���ߣ���ȵȰɡ�";
        else
        if (c < 800)
                message_vision("$N���˿�$n��������Ҳ�ã���Ȼ"
                               "���ڻ����࣬����Ҳ����ˡ���\n",
                               this_object(), me);
        else
        if (c < 1000)
                message_vision("$N���ͷ����$n�������ðɣ���"
                               "����һ���ˣ��ͷ��˰ɡ���\n",
                               this_object(), me);
        if (c < 3000)
                message_vision("$N����$n���к����������ã���"
                               "���㷢���أ��������ɣ���\n",
                               this_object(), me);
        else
        if (c < 8000)
                message_vision("$N��æ��������׼���ɣ�������"
                               "���кü����ˣ���\n",
                               this_object(), me);
        else
                message_vision("$N����$n����ϲ���������ã���"
                               "��������Ҫ���ˣ����������ã���\n",
                               this_object(), me);

        if (c > 1000) c = 1000;
        environment(me)->improve_product_amount("cuprum_ore", -c);

        // ���ɽ�ͨ����
        ob = new("/clone/misc/cart");
        ob->set_temp("goods/name", "ͭ��ʯ");
        ob->set_temp("goods/id",   "cuprum_ore");
        ob->set_temp("goods/unit", "��");
        ob->set_temp("goods/amount", c);
        message_sort("$Nһ�������������ƹ�һ" + ob->query("unit") +
                     ob->name() + "������Ŷ�" + me->name() +
                     "����������⳵�����͵���������ͭ��ȥ��"
                     "����������ˣ�����ǳ�͢�Ķ�����������"
                     "Ҫ����Դ���ȥ�ɣ��˵��������͸񣡡�\n",
                     this_object(), me);
        tell_object(me, YEL + name() + "������һ" + ob->query("unit") +
                        ob->name() + "��\n" NOR);
        ob->move(environment(me));
        ob->set_owner(me);

        // ��¼����������Ϣ
        me->set("job/hz_cuprum_ore", c);
        me->set_temp("job/hz_cart", ob);
        ob->set_temp("job/info", "hz_cuprum_ore");
        ob->set_temp("job/owner", me);

        return 1;
}

int accept_object(object who, object ob)
{
        int amount;

        if (! ob->query("money_id"))
                return 0;

        if ((amount = who->query("job/hz_cuprum_ore")) > 0)
        {
                amount = (amount + 99) / 100;
                if (ob->value() < amount * 10000)
                {
                        message_vision(CYN "$N" CYN "���˿�$n"
                                       CYN "�ݹ�����Ǯ�����"
                                       "����������㣿һ�߶�ȥ"
                                       "����\n" NOR,
                                       this_object(), who);
                        return 0;
                }

                message_vision(CYN "$N" CYN "���Ӻ���һ�����ӹ�"
                               + ob->name() + NOR + CYN "������"
                               "�����ˣ��Ͳ�׷�����ˡ���\n" NOR,
                               this_object(), who);
                who->delete("job/hz_cuprum_ore");
        } else
        {
                message_vision(CYN "$N" CYN "ü����Ц����"
                               + ob->name() + NOR +
                               CYN "���˹�����������ң�ȴ�����$n"
                               CYN "��\n" NOR, this_object(), who);
        }

        destruct(ob);
        return -1;
}
