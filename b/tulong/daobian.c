#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����ɽ����");
        set("long", @LONG
����ɽ��Ǯ�����ڵĶ���֮�У��Ǹ�����С����ɽʯ���
�����˾ӡ��������˸��ٴ��죬����ʾ�⣬ֻ����������Ͼ�
����һͷ��ӥ��˫����չ���������䡣�������֮��վ��һ��
���ߡ�����ɽ�Ǹ�С����ɽʯ��ľ�޿ɹ�֮����
LONG);
        set("exits",([
                "southdown":__DIR__"boat2",
                "east":__DIR__"gukou",
        ]));

        set("objects",([
                 __DIR__"npc/jiaozhong1": 2,
                 __DIR__"npc/jiaozhong2": 2,
                 __DIR__"npc/bai": 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object ob = present("bai guishou");

        if (! me->query_temp("dao") && dir == "east")
                return notify_fail(HIR "\n��ͻȻ�뵽���˰�һ���᳡��������֮"
                                   "����ǰ;δ����������\n��ȥ�������ǵĴ�("
                                   HIY "break boat" HIR ")�Է����⡣\n" NOR);

        if (me->query_temp("dao")
           && dir == "east"
           && objectp(ob)
           && living(ob))
        {
                ob->ccommand("tnnd" + me->query("id"));
                ob->ccommand("slap3" + me->query("id"));
                message_vision(CYN "$N" CYN "�ȵ��������һ����ǵĴ�ֻ��"
                               "����ȥ���ɣ�\n" NOR, ob, me);
                ob->kill_ob(me);

                ob = present("jiao zhong");
                if (objectp(ob)) ob->kill_ob(me);

                ob = present("jiao zhong 2");
                if (objectp(ob)) ob->kill_ob(me);

                ob = present("jiao zhong 3");
                if (objectp(ob)) ob->kill_ob(me);

                ob = present("jiao zhong 4");
                if (objectp(ob)) ob->kill_ob(me);
                        return notify_fail(HIY "�򶫵�·���׹�����ס�ˡ�\n" NOR);
        }
        return 1;
}
