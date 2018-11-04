#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��ţɽ");
        set("long",@long
����ɽ�����긲�ǰ�ѩ������״Զ����һͷ���ڳԲݵ�ţ
�����������ﺮ���Х�������̹ǣ��㲻�����˸�������ɽ��
��һ��ƽ�أ�����һ����ɫ�ľ�ʯ(stone)��
long);
        set("exits",([
                "southwest" : __DIR__"fufengshan",
        ]));

        set("item_desc", ([
                "stone" : WHT "����ʯ�ܴ󣬿�����(wo)��"
                          "һ���ˡ���ʯ�ı���ʮ��ƽ����\n"
                          "�����ƺ�������Ħ��һ�㡣\n" NOR,
        ]));

        set("outdoors", "kunlun");
        setup();
}

void init()
{
        add_action("do_wo", "wo");
        add_action("do_breathe", "breathe");
}

int do_wo(string arg)
{
        if (! arg || (arg != "stone") )
                return notify_fail("��Ҫ����ʲô���棿\n");

        if (this_player()->is_busy())
                return notify_fail("����æ���ء�\n");

        if (this_player()->query_temp("marks/wo"))
                return notify_fail("���Ѿ�������ʯ���ˡ�\n");

        this_player()->set_temp("marks/wo", 1);
                return notify_fail(HIC "�����������ʯ�ϣ����ص��������գ�˫����"
                                   "Ȼ΢����ȫ����ɡ�\n" NOR);
}

int do_breathe()
{
        object me = this_player();

        if (! me->query_temp("marks/wo") )
                return notify_fail(HIR "���������˼�������ֻ���ú������������������"
                                   "�ڵ����������᲻������\n" NOR);

        if (me->is_busy())
                return notify_fail("����æ���ء�\n");

        if (me->query_temp("marks/done") )
                return notify_fail(HIC "��������������˹�����������ʮ���������Ⱥú�"
                                   "��Ϣһ�°ɡ�\n" NOR);

        if (me->query_skill("liangyi-shengong", 1) < 120 )
                return notify_fail("���ڹ�����̫�������������������Ϣ��\n");

        if (me->query_skill("liangyi-shengong", 1) > 199 )
                return notify_fail("����������Ѿ���ǿ�ˣ��޷���ͨ����������ǿ������\n");

        if (! me->can_improve_skill("liangyi-shengong"))
                return notify_fail("���ʵս���鲻�㣬�޷���������������\n");

        if (me->query("qi") < 40 || me->query("jing") < 40)
                return notify_fail("�������Ѿ���ƣ���ˣ���Ϣһ��������Ϣ��\n");

        message_vision(HIW "\n$N" HIW "�������ڵ����������������������������ֻ����Ľ�"
                       "�����\n���⡣$N" HIW "ֻ����ȫ��͸�������Ķ���ˮ���·�������"
                       "��Ȼһ�塣\n\n" NOR, me);

        me->receive_damage("jing", random(30));
        me->receive_damage("qi",   random(30));
        if (me->can_improve_skill("liangyi-shengong"))
                me->improve_skill("liangyi-shengong", 5 + me->query("con") / 3 +
                                  me->query_skill("force") / 6);

        me->set_temp("marks/done", 1);
        call_out("delete_done", 5, me);

        return 1;
}

void delete_done(object me)
{
        if (objectp(me)) me->delete_temp("marks/done");
}

int valid_leave(object me, string dir)
{
        me->delete_temp("marks/wo");
                return ::valid_leave(me, dir);
}
