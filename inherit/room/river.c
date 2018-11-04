// river.c
// by vin

#include <room.h>
#include <ansi.h>

inherit ROOM;

void setup()
{
        set("item_desc/river", HIC "\nֻ����������һҶС�ۣ�Ҳ�������("
                               HIY "yell" HIC ")һ������(" HIY "boat" HIC
                               ")��\n���������������Ը��Ṧ����,Ҳ��ֱ��"
                               "��ˮ(" HIY "cross" HIC ")̤��������\n" NOR);
        ::setup();
}

void init()
{
        add_action("do_yell", "yell");
        add_action("do_cross", "cross");
}

int do_yell(string arg)
{
        object *obs;
        object me, arrive, boat;
        string msg;

        me = this_player();
        arrive = find_object(query("arrive_room"));

        if (! arrive)
                arrive = load_object(query("arrive_room"));

        if (! arg || arg == "" )
                return 0;

        if (strlen(arg) > 15)
                return notify_fail("��������ɤ�ӣ������Լ��ƺ��޷�"
                                   "�����ô��һ�λ���\n");

        if (arg == "boat")
                arg = "����";

        msg = WHT "\n$N" NOR + WHT "�����������ߺ�һ������" +
              arg + "������ԶԶ���˳�ȥ��\n" NOR;

        if (arg != "����" || ! arrive)
        {
                msg += HIY "ͻȻ������ԶԶ����һ���������" +
                       arg + "��������\n" NOR;
                message_vision(msg, me);
        } else
        {
                msg += HIY "\nֻ��һҶ���ۻ�����ʻ�˹�������������"
                       "��һ��̤�Ű���ϵ̰����Ա�˿����¡�$N" HIY
                       "�����æ�첽̤�ϡ�������$P�ϴ����漴�㽫̤"
                       "�Ű������������һ������ʻȥ��\n\n" NOR;
                message_sort(msg, me);

                boat = new("/clone/misc/river_boat");

                obs = filter_array(all_inventory(), (: $1 == $(me)
                                   || $1->query_leader() == $(me)
                                   && ! playerp($1)
                                   && ! $1->is_killing($(me)->query("id")) :));
                obs->move(boat);

                me->start_call_out((: call_other, __FILE__, "arrival",
                                      me, boat, arrive :), 10);
        }
        return 1;
}

void arrival(object me, object boat, object arrive)
{
        object *obs;

        if (! objectp(me) || ! objectp(boat))
                return;

        if (environment(me) != boat)
                return;

        obs = filter_array(all_inventory(boat), (: $1 == $(me) 
                           || $1->query_leader() == $(me)
                           && ! playerp($1)
                           && ! $1->is_killing($(me)->query("id")) :));

        tell_object(me, CYN "\n����˵�������������ϰ��ɡ����漴��"
                        "һ��̤�Ű���ϵ̰���\n\n" NOR);

        obs->move(arrive);
        message("vision", HIY "\nֻ��һ��С�������򰶱߿�������δ"
                          "���ȣ������˼�������������\n\n" NOR,
                          environment(me), ({ me }));

        if (sizeof(obs = all_inventory(boat)) > 0)
        {
                message("vision", WHT "ֻ����ͨ��ͨ�������Ӷɴ���"
                                  "����һ�Ѷ�������\n" NOR, me);
                obs->move(arrive);
        }

        if (objectp(boat))
                destruct(boat);
}

int do_cross()
{
        object me, arrive;
        string msg;

        me = this_player();
        arrive = find_object(query("arrive_room"));

        if (! arrive)
                arrive = load_object(query("arrive_room"));

        if (! arrive)
        {
                tell_object(me, "���Ŀ��ȥ������ˮ��������Ũ��ʲ"
                                "ô�������塣\n");
                return 1;
        }

        if (! me->query_skill("dodge", 1))
        {
                tell_object(me, "�����һ�ɣ���ʲô��������ɱô��\n");
                return 1;
        }

        if (me->query_skill("dodge") < 270)
        {
                tell_object(me, "�������һ�£������Լ����Ṧ�ƺ�"
                                "��û�����ҡ�\n");
                return 1;
        }

        if (me->query("neili") < 300)
        {
                tell_object(me, "���������������������Ϣһ�°ɡ�\n");
                return 1;
        }

        me->add("neili", -200);

        msg = HIW "\nֻ��$N" HIW "����΢΢һ�Σ���ȻƮ��������"
              "������ˮ����԰�̤����ȥ��������΢������������"
              "���������ʵ����������ң���������˾�̾�Ṧ�����"
              "������û����Ӱ��\n\n" NOR;
        message_sort(msg, me);

        me->move(arrive);
        message("vision", HIW "\n����ˮ��������ɢ����һ��̤��"
                          "���ˣ�����̤���ӹ�������\n\n" NOR,
                          environment(me), ({ me }));
        return 1;
}
