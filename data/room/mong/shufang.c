

#include <ansi.h>

inherit PRIVATE_ROOM;

void create()
{
	set("short", "�鷿");
	set ("long", @LONG
������Ǭ���ӵ�������������д�ֵĵط����ɾ��������ķ��ı�
��������İ����������档��ʱ����Ҳ������ǩ��(sign)һЩ�����
�˵���� 
LONG );

	set("exits", ([
		"east" : __DIR__"jusuo",
	]));

        set("sleep_room", 1);
        setup();

        set("room_owner", "����");
        set("room_name", "Ǭ����");
        set("room_id", "qiankun");
        set("room_owner_id", "mong");
        set("room_position", "��ʯ���");
}

void init()
{
        add_action("do_sign", "sign");
}

int do_sign()
{
        object ob;
        object me;

        me = this_player();

            if (! is_room_owner(me))
                    return notify_fail("���ֲ�����������ˣ��Ҹ�"
                                       "ʲô��\n");

        if (me->is_busy())
                return notify_fail("�����ڻ�æ���ء�\n");

        message_vision("$N���һ��ֽ����������������滭����"
                       "��д��Щ������\n", me);
        tell_object(me, "��д��һ�����͡�\n");

        ob = new("/d/room/roomobj/pass");
        ob->set_name(HIW + me->query("name") + "����" NOR,
                     ({ "pass", query("room_owner_id") + " pass" }));
        ob->set("long", "һ����" + me->query("name") + "�ױ�ǩ����" +
                     "���ͣ�ƾ��������Խ���" + query("room_name") +
                     "��\n");
        ob->move(me);
        me->start_busy(4 + random(4));
        return 1;
}
