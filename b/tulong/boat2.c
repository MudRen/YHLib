#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ߵ����ߣ���ʱ���ֺ�����ͣ�����˴󴬡���Щ����
�Ǿ޾����ɳ�ɡ���ȭ��һ���˵�������
LONG);
        set("exits",([
                "northup":__DIR__"daobian",
        ]));

        set("objects",([
                __DIR__"obj/stone": 1,
        ]));
        setup();
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        object me = this_player(), inv;

        if (arg != "boat" && arg != "��")
                return notify_fail("��Ҫ����ʲô��\n");

        inv = present("stone", me);

        if (query("dao"))
		return notify_fail("���ϵ�Φ����͵��ˣ�����ʲô��\n");

        if (! objectp(inv))
		return notify_fail("��׼����ʲô�Ҵ�ѽ��\n");

        message_vision(HIY "$N" HIY "�������е�" + inv->query("name") +
                       HIY "�����ϵ�Φ����ȥ��\n", me);

        message_vision(WHT "\n��ʱֻ���ÿ���������֮�������������Ĵ�Φһ��"
                       "������������\n����֮�����������֮�䣬��Φ�˻򵹻�"
                       "б����һ���⡣\n\n" NOR, me);
        set("dao", 1);
        set("long", @LONG
���ߵ����ߣ���ʱ���ֺ�����ͣ�����˴󴬡���Щ����
�Ǿ޾����ɳ�ɡ���ȭ��һ���˵�������ֻ����Щ����Φ��
�����Ҷϵ��ˡ�
LONG);
        me->set_temp("dao", 1);
        return 1;
}
