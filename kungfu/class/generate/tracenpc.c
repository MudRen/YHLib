// tracenpc.c

#include <ansi.h>
#include <quest.h>

inherit CLASS_D("generate") + "/chinese";

void create()
{
        mapping my;
        int lvl;

        ::create();
        set("gender", "����" );
        set("age", 50 + random(40));
        set("attitude", "friendly");
        set("scale", 150);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 50);
        set_temp("born_time", time());

        lvl = 6 + random(6);
        NPC_D->init_npc_skill(this_object(), lvl);

        // ��ʼ��NPC������
        my = query_entire_dbase();
        my["max_qi"] = 1000 + lvl * 300 + random(500);
        my["max_jing"] = my["max_qi"] / 2;
        my["max_neili"] = 1000 + lvl * 500 + random(500);
        my["eff_jing"] = my["max_jing"];
        my["jing"] = my["max_jing"];
        my["eff_qi"] = my["max_qi"];
        my["qi"] = my["max_qi"];
        my["neili"] = my["max_neili"] * 2;
}

varargs int move(mixed dest, int raw)
{
        int r;

        // ִ��ԭ����MOVE����
        r = ::move(dest, raw);

        if (query_temp("trace"))
        {
                remove_call_out("give_intercession");
                call_out("give_intercession", 2);
        }
        return r;
}

// �ж��Ƿ�������Ҫ����
void give_intercession()
{
        object ob;
        object me;
        string msg;

        if (! query_temp("trace"))
                return;

        ob = query_temp("trace");
        ob = present(ob, environment(this_object()));

        if (! objectp(ob))
                return;

        if (environment(ob) != environment(this_object()))
                return;

        if (! living(ob))
                return;

        me = query_leader();
        message("vision", HIC + sort_msg(name() + "����" + ob->name() +
                          HIC "����س���ǰȥ����е��������쿪�۰����ֵܽ�"
                          "������Ѱ�����ˣ���˵��ֻ������ӵ��һ�������ݺ�"
                          "������ɷ�Ǹ��ˡ�\n" NOR), environment());
        if (objectp(me))
        {
                tell_object(me, HIY "\n������˴˷�״̬����Ϊ�п������ɵð�"
                                "����ο��\n\n" NOR);

                GIFT_D->bonus(me, ([ "exp" : 200 + random(100),
                                     "pot" : 200 + random(100),
                                     "score"   : 20 + random(20),
                                     "weiwang" : 10 + random(10),
                                     "prompt"  : "ͨ���������Ѱ��" ]));

                CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + me->name(1) +
                                                     "(" + me->query("id") + ")��" +
                                                     name() + HIM "�ҵ���ʧɢ���ֵ�"
                                                     + ob->name() + HIM "��" NOR);

                // ����Ϊ�����жϵ���������
                if (me->query("quest/freequest") > 0)
                        GIFT_D->delay_freequest_bonus(me);
        }
        delete_temp("trace");
        set_leader(0);
        destruct(ob);
        destruct(this_object());
}

void unconcious()
{
        die();
}
